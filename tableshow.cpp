#pragma once
#include "tableshow.h"
#include <QDate>
#include <QCloseEvent>
#include <QMessageBox>
#include "core/factory.h"


TableShow::TableShow(QWidget *mainshow, QWidget *parent) :
    QWidget(parent),ui(new Ui::TableShow),   //初始化
    search(false)
{
    pFactory = Factory::GetInstance();
    setAttribute(Qt::WA_DeleteOnClose);
    mainwindows = mainshow;
    back = false;
    dateTimer.start(1000);
    connect(&dateTimer,SIGNAL(timeout()),this,SLOT(show_time()));
    ui->setupUi(this);
}

TableShow::~TableShow()
{
    vector<int>().swap(location);
    dateTimer.stop();
    delete ui;
}

/*返回主菜单*/
void TableShow::on_back_clicked()
{
    timer.stop();
    refreshCol = 0;
    back = true;
    this->close();
}

//表格初始化
void TableShow::table_init_Large()
{
    show_str("生产设备列表输出");
    search = false;
    badMessage = false;
    LorS = true;
    back = false;

    ui->startRT->setEnabled(true);
    ui->stopRT->setEnabled(true);
    ui->startBadMessage->setEnabled(true);
    ui->stopBadMessage->setEnabled(true);
    //输出表格内容
    //返回时需要调用clear来释放内存

    sort_init();
    set_header_large();
    table_write_large();

}
void TableShow::table_init_Small()
{
    show_str("工具设备列表输出");
    search = false;
    badMessage = false;
    LorS = false;
    back = false;

    ui->startRT->setEnabled(false);
    ui->stopRT->setEnabled(false);
    ui->startBadMessage->setEnabled(false);
    ui->stopBadMessage->setEnabled(false);
    //输出表格内容
    //返回时需要调用clear来释放内存
    //调用Small的Vector
    sort_init();
    set_header_small();
    table_write_small();
}
//设置表头
void TableShow::set_header_large()
{
    QTableWidgetItem *headerItem;
    QStringList headerText;

    headerText<<"设备类型"<<"OID"<<"OEM"<<"是否使用"<<"是否损坏"<<"损坏概率"<<"输入接口"<<"输出接口"<<"效率"<<"温度"<<"详细信息";  //表头标题用QStringList来表示

    ui->table_output->setColumnCount(headerText.count());//列数设置为与 headerText的行数相等

    for (int i=0;i<ui->table_output->columnCount();i++)//列编号从0开始
    {
        headerItem=new QTableWidgetItem(headerText.at(i)); //新建一个QTableWidgetItem， headerText.at(i)获取headerText的i行字符串
        ui->table_output->setHorizontalHeaderItem(i,headerItem); //设置表头单元格的Item
    }

    ui->table_output->clearContents();//只清除工作区，不清除表头
    ui->table_output->setEditTriggers(QAbstractItemView::NoEditTriggers);   //不可被编辑，使用QAbstractItemView::EditTriggers即可编辑
}
void TableShow::set_header_small()
{
    QTableWidgetItem *headerItem;
    QStringList headerText;

    headerText<<"设备类型"<<"OID"<<"OEM"<<"是否使用"<<"是否损坏"<<"是否归还"<<"使用人"<<"借用日期"<<"归还日期";  //表头标题用QStringList来表示

    ui->table_output->setColumnCount(headerText.count());//列数设置为与 headerText的行数相等

    for (int i=0;i<ui->table_output->columnCount();i++)//列编号从0开始
    {
        headerItem=new QTableWidgetItem(headerText.at(i)); //新建一个QTableWidgetItem， headerText.at(i)获取headerText的i行字符串
        ui->table_output->setHorizontalHeaderItem(i,headerItem); //设置表头单元格的Item
    }

    ui->table_output->clearContents();//只清除工作区，不清除表头
    ui->table_output->setEditTriggers(QAbstractItemView::NoEditTriggers);   //不可被编辑，使用QAbstractItemView::EditTriggers即可编辑

}
//写表格内容
void TableShow::table_write_large()
{
    //调用Vector中的Large
    DeviceLargeInfo DL;
    ui->table_output->setRowCount(0);
    int nRow = 0;
    int num = 0;
    while(pFactory->factory_ui_show_iter(DL,num) == 1)
    {
        ui->table_output->insertRow(nRow);
        createItemsARow(nRow,DL); //为某一行创建items
        nRow++;
    }
}
void TableShow::table_write_small()
{
    DeviceSmallInfo DS;
    ui->table_output->setRowCount(0);
    int nRow = 0;
    int num = 0;
    while(pFactory->factory_ui_show_iter(DS,num) == 1)
    {
        ui->table_output->insertRow(nRow);
        createItemsARow(nRow,DS); //为某一行创建items
        nRow++;
    }
}
//表格写入一行
void TableShow::createItemsARow(int nRow, DeviceLargeInfo &info)
{
    //所有数据，没有设置初始值的，自动赋值为-1
    //设备类型
    //新建一个Item,并将其写入表格中，该处有3个重载
    bool red = info.condition;
    QStrItem(red,nRow,0,info.type);
    QStrItem(red,nRow,1,info.OID);
    QStrItem(red,nRow,2,info.OEM);
    QStrItem(red,nRow,3,info.work);
    QStrItem(red,nRow,4,info.condition);
    //前五个是基类的
    //这五个是Large类私有的
    QStrItem(red,nRow,5,info.PFail);
    QStrItem(red,nRow,6,info.port_in);
    QStrItem(red,nRow,7,info.port_out);
    QStrItem(red,nRow,8,info.efficiency);
    QStrItem(red,nRow,9,info.temperture);
    //进入详细信息
    QStrItem(red,nRow,10,(string)"详细信息");
}
void TableShow::createItemsARow(int nRow,DeviceSmallInfo &info)
{
    bool red = info.condition;
    QStrItem(red,nRow,0,info.type);
    QStrItem(red,nRow,1,info.OID);
    QStrItem(red,nRow,2,info.OEM);
    QStrItem(red,nRow,3,info.work);
    QStrItem(red,nRow,4,info.condition);
    //前五个是基类的
    QStrItem(red,nRow,5,info.revert);
    QStrItem(red,nRow,6,info.user);
    QStrItem(red,nRow,7,info.start_date);
    QStrItem(red,nRow,8,info.end_date);
    //QStrItem(item,nRow,9,info.);
    //这4个是Small类私有的
}
//将每一个项目写成QString
void TableShow::QStrItem(bool red,int nRow,int nCol,string strIn)
{
    QTableWidgetItem *item = nullptr;
    QString str;
    str = QString::fromStdString(strIn);
    item=new  QTableWidgetItem(str);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //文本对齐格式
    if(red) //颜色
        item->setForeground(Qt::red);
    ui->table_output->setItem(nRow,nCol,item); //为单元格设置Item
}
void TableShow::QStrItem(bool red,int nRow,int nCol,bool bIn)
{
    QTableWidgetItem *item = nullptr;
    QString str = bIn?"是":"否";
    item=new  QTableWidgetItem(str);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //文本对齐格式
    if(red) //颜色
        item->setForeground(Qt::red);
    ui->table_output->setItem(nRow,nCol,item); //为单元格设置Item
}
void TableShow::QStrItem(bool red,int nRow,int nCol,float fIn)
{
    QTableWidgetItem *item = nullptr;
    QString str;

    if(fIn == -1)
        str = "-";    //无输出
    else
        str = QString::asprintf("%.2f",fIn);

    item=new  QTableWidgetItem(str);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //文本对齐格式
    if(red) //颜色
        item->setForeground(Qt::red);
    ui->table_output->setItem(nRow,nCol,item); //为单元格设置Item
}


//排序部分，初始化,排序调用函数
void TableShow::sort_init()
{
    connect(ui->table_output->horizontalHeader(), SIGNAL(sectionClicked(int)),this, SLOT(column_sort(int)));
}
void TableShow::column_sort(int choose)
{
    switch(choose)
    {
    case 0:
        pFactory->factory_ui_sort(1);
        show_str("按设备类型排序");
        break;
    case 1:
        pFactory->factory_ui_sort(2);
        show_str("按OID排序");
        break;
    case 2:
        pFactory->factory_ui_sort(3);
        show_str("按OEM排序");
        break;
    case 3:
        pFactory->factory_ui_sort(4);
        show_str("按是否使用排序");
        break;
    case 4:
        pFactory->factory_ui_sort(5);
        show_str("按是否损坏排序");
        break;
    case 5:
        LorS ?
        pFactory->factory_ui_sort(11):
        pFactory->factory_ui_sort(21);
        LorS ? show_str("按损坏概率排序") : show_str("按是否归还排序");
        break;
    case 6:
        LorS ?
        pFactory->factory_ui_sort(12):
        pFactory->factory_ui_sort(22);
        LorS ? show_str("按输入接口排序") : show_str("按使用者排序");
        break;
    case 7:
        LorS ?
        pFactory->factory_ui_sort(13):
        pFactory->factory_ui_sort(23);
        LorS ?  show_str("按输出接口排序") : show_str("按借用日期排序");
        break;
    case 8:
        LorS ?
        pFactory->factory_ui_sort(14):
        pFactory->factory_ui_sort(24);
        LorS ? show_str("按效率排序") : show_str("按归还时间排序");
        break;
    case 9:
        pFactory->factory_ui_sort(15);
        show_str("按温度排序");
        break;
    default:
        break;
    }

    LorS ?
    table_write_large() : table_write_small();
}

//查找部分，开始查找
void TableShow::on_startSearch_clicked()
{
    search = true;
    string find = ui->searchInput->text().toStdString();

    ui->table_output->clearContents();
    ui->table_output->setRowCount(0);

    location.clear();
    pFactory->factory_ui_find(find,location);   //找到所有的设备
    int nRow = 0;

    if(LorS)
    {
        nRow = 0;
        for(int i = 0; i < location.size(); i++)
        {
            DeviceLargeInfo DL;
            if(pFactory->factory_ui_show_line(DL,location[i]))  //返回值是1代表正常，否则返回0
            {
                ui->table_output->insertRow(nRow);
                createItemsARow(nRow++,DL); //为某一行创建items
            }
        }
    }

    else
    {
        nRow = 0;
        for(int i = 0; i < location.size(); i++)
        {
            DeviceSmallInfo DS;
            if(pFactory->factory_ui_show_line(DS,location[i]))  //返回值是1代表正常，否则返回0
            {
                ui->table_output->insertRow(nRow);
                createItemsARow(nRow++,DS); //为某一行创建items
            }
        }
    }
}
/*查找后回到主页面*/
void TableShow::on_searchReset_clicked()
{
    if(LorS)
        table_init_Large();
    else
        table_init_Small();
    search = false;
    ui->searchInput->clear();
    //ui->saveAll->setEnabled(true); //设置可保存
}

//添加新设备
/*插入新行，按钮add*/
void TableShow::on_ButtonAddNew_clicked()
{
    //此处新建一个页面来编辑
    AddInfo *add = new AddInfo(LorS,nullptr);   //true,添加大设备
    add->setWindowTitle("添加新设备");
    add->setAddInfo();
    add->show();
}

/*删除某一行内容*/
void TableShow::on_DeleteRow_clicked()
{
    //添加一个对话框指示删除
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"删除询问","是否删除？",QMessageBox::Yes | QMessageBox::Cancel);

    if(reply == QMessageBox::Yes)
    {
        pFactory->factory_ui_delete(ui->table_output->item(selRow,1)->text().toStdString());    //右侧指的是当前列的oid
        ui->table_output->removeRow(selRow);
    }
}

/*保存按钮*/
void TableShow::on_saveAll_clicked()
{
    if(LorS && !search)
        pFactory->factory_ui_delete_large();
    else if(!LorS && !search)
        pFactory->factory_ui_delete_small();
    //全部保存
    for(int i = 0; i < ui->table_output->rowCount(); i++)
    {
        if(LorS)
        {
            DeviceLargeInfo DL;

            DL.type = ui->table_output->item(i,0)->text().toStdString();
            DL.OID = ui->table_output->item(i,1)->text().toStdString();
            DL.OEM = ui->table_output->item(i,2)->text().toStdString();
            DL.work = ui->table_output->item(i,3)->text().toStdString() == "否" ? false:true;
            DL.condition = ui->table_output->item(i,4)->text().toStdString() == "否" ? false:true;

            if(ui->table_output->item(i,5)->text() == "-" || ui->table_output->item(i,5)->text() == "")
                DL.PFail = -1;
            else
                DL.PFail = ui->table_output->item(i,5)->text().toFloat();

            DL.port_in = ui->table_output->item(i,6)->text().toStdString();
            DL.port_out = ui->table_output->item(i,7)->text().toStdString();

            if(ui->table_output->item(i,8)->text() == "-" || ui->table_output->item(i,8)->text() == "")
                DL.efficiency = -1;
            else
                DL.efficiency = ui->table_output->item(i,8)->text().toFloat();

            if(ui->table_output->item(i,9)->text() == "-" || ui->table_output->item(i,9)->text() == "")
                DL.temperture = -1;
            else
                DL.temperture = ui->table_output->item(i,9)->text().toFloat();

            if(search)//search后，有一个vector location储存了对应下标
                pFactory->factory_ui_amend(location[i],DL);
            else
                pFactory->factory_ui_add(DL);
        }
        else
        {
            DeviceSmallInfo DS;

            DS.type = ui->table_output->item(i,0)->text().toStdString();
            DS.OID = ui->table_output->item(i,1)->text().toStdString();
            DS.OEM = ui->table_output->item(i,2)->text().toStdString();
            DS.work = ui->table_output->item(i,3)->text().toStdString() == "否" ? false:true;
            DS.condition = ui->table_output->item(i,4)->text().toStdString() == "否" ? false:true;
            DS.revert = ui->table_output->item(i,5)->text().toStdString() == "否" ? false:true;
            DS.user = ui->table_output->item(i,6)->text().toStdString();
            DS.start_date = ui->table_output->item(i,7)->text().toStdString();
            DS.end_date = ui->table_output->item(i,8)->text().toStdString();

            if(search)
                pFactory->factory_ui_amend(location[i],DS);
            else
                pFactory->factory_ui_add(DS);

        }
    }
    pFactory->write_to_file();;
    show_str("已保存");
}


//实时输出部分
/*实时输出函数*/
void TableShow::RT_show_all()
{
    ui->table_output->setEditTriggers(QAbstractItemView::NoEditTriggers);   //使其不可编辑
    ui->startRT->setEnabled(false); //使该按钮不可点击
    ui->groupBox->setEnabled(false); //不可编辑
    ui->startSearch->setEnabled(false); //不可搜索
    ui->ButtonAddNew->setEnabled(false);    //不可添加
    ui->searchReset->setEnabled(false);
    ui->DeleteRow->setEnabled(false);
    ui->searchInput->setEnabled(false);
    ui->tablePush->setEnabled(false);
    disconnect(ui->table_output->horizontalHeader(), SIGNAL(sectionClicked(int)),this, SLOT(column_sort(int))); //使不能排序
    timer.stop();
    timer.start(2000);
    refreshCol = 0;
    connect(&timer,SIGNAL(timeout()),this,SLOT(refresh_table()));
    //开启后要使该按钮不能使用
}
/*开始实时输出*/
void TableShow::on_startRT_clicked()
{
    RT_show_all();
}
/*刷新输出数据*/
void TableShow::refresh_table()
{
    refreshCol++;

    if(refreshCol == 120)
        refreshCol = 0;

    pFactory->factory_ui_RTinfo_to_ui(refreshCol);

    for(int k = 0;k < ui->table_output->rowCount(); k++)
    {
        if(ui->table_output->item(k,4)->text() == "是")
        {
            //损坏弹窗
            if(badMessage)
                QMessageBox::question(this,"提示",ui->table_output->item(k,0)->text()+"已损坏",QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Ok);
        }
    }

    //对损坏的进行排序,可能会很卡顿,具体数字的定义看factory.cpp line136
    pFactory->factory_ui_sort(5);
    table_write_large();
}
/*停止实时输出*/
void TableShow::on_stopRT_clicked()
{
    //ui->table_output->setEditTriggers(QAbstractItemView::DoubleClicked);    //使其可编辑
    ui->startRT->setEnabled(true); //使该按钮可点击
    ui->groupBox->setEnabled(true); //不可编辑
    ui->startSearch->setEnabled(true); //不可搜索
    ui->ButtonAddNew->setEnabled(true);    //不可添加
    ui->searchReset->setEnabled(true);
    ui->DeleteRow->setEnabled(true);
    ui->searchInput->setEnabled(true);
    ui->tablePush->setEnabled(true);
    connect(ui->table_output->horizontalHeader(), SIGNAL(sectionClicked(int)),this, SLOT(column_sort(int))); //使不能排序

    timer.stop();
}
/*开启损坏弹窗*/
void TableShow::on_startBadMessage_clicked()
{
    badMessage = true;
}
/*关闭损坏弹窗*/
void TableShow::on_stopBadMessage_clicked()
{
    badMessage = false;
}


//按钮部分以及功能部分
/*左上角功能输出，private*/
void TableShow::show_str(const char *s)
{
    ui->outputLabel->setText(s);
}
/*按钮刷新表格，按钮table*/
void TableShow::on_tablePush_clicked()
{
    show_str("刷新");
    if(LorS)
        table_init_Large();
    else
        table_init_Small();

    ui->table_output->scrollToBottom();     //滚动到最后一行
}
/*使能编辑*/
void TableShow::on_edit_enable_clicked()
{
    ui->table_output->setEditTriggers(QAbstractItemView::DoubleClicked);
    //设置可编辑，双击编辑
    show_str("设置可编辑");
}
void TableShow::on_edit_disable_clicked()
{
    ui->table_output->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置不可编辑
    show_str("设置可编辑");
}
/*右上角输出当前选中的内容，同时进入详细信息*/
void TableShow::on_table_output_cellClicked(int row, int column)
{
    selRow = row;
    QTableWidgetItem *item = ui->table_output->item(row,column);
    ui->ItemLabel->setText(item->text());

    if(LorS && column == 10 && ui->table_output->editTriggers() == QAbstractItemView::NoEditTriggers)   //位于Large输出且不可编辑,则单击进入
    {
        QTableWidgetItem *item = ui->table_output->item(row,0);
        string sel = item->text().toStdString();
        //factory_ui_RTinfo_find_row(row)用于找到位于allRTdata中的位置，返回值就是其位置，row是其在vector D中的位置
        RTshow *rt = new RTshow(pFactory->factory_ui_RTinfo_find_row(row),nullptr);
        timer.stop();  //停止刷新
        rt->setWindowTitle("详细信息实时输出");
        rt->init(sel);  //RTshow初始化
        rt->show();
    }
}
/*关闭窗口后的处理*/
void TableShow::closeEvent(QCloseEvent * event)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"提示","是否关闭？\n请确定已经保存所有内容",QMessageBox::Yes | QMessageBox::Cancel);

    if(reply == QMessageBox::Cancel)
        event->ignore();    //不关闭
    else
    {
        dateTimer.stop();
        timer.stop();
        if(back)
            mainwindows->setVisible(true);
        else
            mainwindows->close();
    }
}
/*时间输出*/
void TableShow::show_time()
{
    QDateTime dateTime = QDateTime::currentDateTime();//获取系统现在的时间
    ui->data_time->setText(dateTime.toString("yyyy-MM-dd hh:mm:ss ddd"));
}
