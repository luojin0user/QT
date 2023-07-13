#pragma once
#include "addinfo.h"
#include "ui_addinfo.h"
#include "mainwindow.h"
#include "tableshow.h"

AddInfo::AddInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddInfo)
{
    pFactory = Factory::GetInstance();
    QWidget::setAttribute (Qt::WA_DeleteOnClose);
    ui->setupUi(this);
}
AddInfo::AddInfo(bool input, QWidget *parent) :
    QWidget(parent),LorS(input),
ui(new Ui::AddInfo)
{
    pFactory = Factory::GetInstance();
    QWidget::setAttribute (Qt::WA_DeleteOnClose);
    ui->setupUi(this);
}

AddInfo::~AddInfo()
{
    delete ui;
}
/*设置初始文本输出*/
void AddInfo::setAddInfo()
{
    clear_all();

    ui->label_1->setText("设备类型:");
    ui->label_2->setText("OID:");
    ui->label_3->setText("OEM:");
    ui->label_4->setText("是否使用:");
    ui->label_5->setText("是否损坏:");
    if(LorS)
    {
        ui->label_6->setText("损坏概率:");
        ui->label_7->setText("效率:");
        ui->label_8->setText("温度:");
        ui->label_9->setText("输入接口:");
        ui->label_10->setText("输出接口:");

        ui->comboBox_6->setEditText("No Input");
        ui->dateEdit_7->text().clear();
        ui->dateEdit_8->text().clear();
        ui->comboBox_6->setEnabled(false);
        ui->dateEdit_7->setEnabled(false);
        ui->dateEdit_8->setEnabled(false);
    }
    else
    {
        ui->label_6->setText("是否归还:");
        ui->label_7->setText("借用日期:");
        ui->label_8->setText("归还日期:");
        ui->label_9->setText("使用人:");
        ui->label_10->setText("");

        ui->dateEdit_7->setCalendarPopup(true);
        ui->dateEdit_8->setCalendarPopup(true);

        ui->label_10->setEnabled(false);
        ui->lineEdit_10->setEnabled(false);
        //工具设备专属
    }
}
//读取输入信息,并写入vector，写入文件
void AddInfo::on_WriteOk_clicked()
{
    saveInfo();
    this->close();
}
//写入vector，写入文件
void AddInfo::saveInfo()
{
    if(LorS)
    {
        DeviceLargeInfo add;    //临时储存变量

        add.type = ui->lineEdit_1->text().toStdString();
        add.OID = ui->lineEdit_2->text().toStdString();
        add.OEM = ui->lineEdit_3->text().toStdString();
        add.work = ui->comboBox_4->currentIndex() == 0 ? true : false;  //0是，1否，2未知
        add.condition = ui->comboBox_5->currentIndex() == 0 ? true : false;

        add.PFail = -1;
        add.port_in = ui->lineEdit_9->text().toStdString();
        add.port_out = ui->lineEdit_10->text().toStdString();

        add.efficiency = -1;
        add.temperture = -1;

        pFactory->factory_ui_add(add);
    }

    else
    {
        DeviceSmallInfo add;

        add.type = ui->lineEdit_1->text().toStdString();
        add.OID = ui->lineEdit_2->text().toStdString();
        add.OEM = ui->lineEdit_3->text().toStdString();
        add.work = ui->comboBox_4->currentIndex() == 0 ? true : false;  //0是，1否，2未知
        add.condition = ui->comboBox_5->currentIndex() == 0 ? true : false;

        add.revert = ui->comboBox_6->currentIndex() == 0 ? true : false;
        add.start_date = ui->dateEdit_7->date().toString(Qt::ISODate).toStdString();
        add.end_date = ui->dateEdit_8->date().toString(Qt::ISODate).toStdString();
        add.user = ui->lineEdit_9->text().toStdString();

        pFactory->factory_ui_add(add);
    }
    pFactory->write_to_file();;
}
//重置所有输入
void AddInfo::on_Reset_clicked()
{
    clear_all();

    if(LorS)
    {
        ui->comboBox_6->setEditText("No Input");
        ui->dateEdit_7->clear();
        ui->dateEdit_8->clear();
        ui->comboBox_6->setEnabled(false);
        ui->dateEdit_7->setEnabled(false);
        ui->dateEdit_8->setEnabled(false);
    }
    else
    {
        ui->label_10->setEnabled(false);
        ui->lineEdit_10->setEnabled(false);
        //工具设备专属
    }
}

void AddInfo::clear_all()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();

    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
}

void AddInfo::on_AddNew_clicked()
{
    saveInfo();
    clear_all();
}
void AddInfo::closeEvent(QCloseEvent * event)
{
    this->close();
}

