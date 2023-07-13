#include "rtshow.h"
#include "ui_rtshow.h"
#include "tableshow.h"
#include <QDebug>

RTshow::RTshow(int getRow,QWidget *parent) :
    QWidget(parent),nRTrow(getRow),
    ui(new Ui::RTshow)
{
    pFactory = Factory::GetInstance();
    setAttribute(Qt::WA_DeleteOnClose);
    refreshCol = 0;
    ui->setupUi(this);
}

RTshow::~RTshow()
{
    delete ui;
}
//返回按键
void RTshow::on_back_clicked()
{
    this->close();
}
//初始化函数
void RTshow::init(std::string str)
{
    charts_init();
    timer.start(500);   //刷新时间
    //设置不可操作
    ui->label_11->setFocusPolicy(Qt::NoFocus);
    ui->label_12->setFocusPolicy(Qt::NoFocus);
    ui->label_13->setFocusPolicy(Qt::NoFocus);
    ui->label_14->setFocusPolicy(Qt::NoFocus);
    ui->label_15->setFocusPolicy(Qt::NoFocus);
    ui->label_16->setFocusPolicy(Qt::NoFocus);
    ui->label_17->setFocusPolicy(Qt::NoFocus);
    ui->label_18->setFocusPolicy(Qt::NoFocus);
    ui->label_19->setFocusPolicy(Qt::NoFocus);
    ui->label_10->setFocusPolicy(Qt::NoFocus);

    vector<int>nInfoRow;    //此处只用到了ninfoRow[0]
    nInfoRow.clear();
    DeviceLargeInfo DL;
    pFactory->factory_ui_find(str,nInfoRow);
    pFactory->factory_ui_show_line(DL,nInfoRow[0]);

    ui->label_11->setText(QString::fromStdString(DL.type));
    ui->label_12->setText(QString::fromStdString(DL.OID));
    ui->label_13->setText(QString::fromStdString(DL.OEM));
    ui->label_14->setText(QString::fromStdString(DL.work == true ? "是" : "否"));

    ui->label_18->setText(QString::fromStdString(DL.port_in));
    ui->label_19->setText(QString::fromStdString(DL.port_out));

    connect(&timer,SIGNAL(timeout()),this,SLOT(refresh())); //timer时钟触发refresh事件
}
//更新函数
void RTshow::refresh()
{
    if(refreshCol == 120)
        refreshCol = 0;

    RTinfoString RTtemp;
    flag = pFactory->factory_ui_RTinfo_to_ui_line(RTtemp,nRTrow,refreshCol);
    refreshCol++;

    //有数据
    if(flag)
    {
        //表格刷新
        QList<QPointF> point;
        point.clear();
        for(int i = 0; i < NaxisX - 1; i++) //将所有点的数据向左平移
            temp_charts[i] = temp_charts[i+1];
        temp_charts[NaxisX - 1] = stof(RTtemp.temperture);

        for(int i = 1; i <= NaxisX; i++)    //将平移后的点写入QList以供输出
        {
            QPointF temp;
            temp.setX(i);
            temp.setY(temp_charts[i-1]);
            point.push_back(temp);
        }

        tempurture->replace(point); //用新的点代替原来的点

        ui->label_15->setText(QString::fromStdString(RTtemp.condition));
        ui->label_16->setText(QString::fromStdString(RTtemp.efficiency));
        ui->label_17->setText(QString::fromStdString(RTtemp.temperture));
        ui->label_110 ->setText(QString::fromStdString(RTtemp.PFail));
    }
    else
    {
        ui->label_15->setText("No data");
        ui->label_16->setText("No data");
        ui->label_17->setText("No data");
        ui->label_110->setText("No data");
    }
}
//点击关闭事件
void RTshow::closeEvent(QCloseEvent *event)
{
    timer.stop();
}
//折线图输出初始化函数
void RTshow::charts_init()
{
    chartView = new QChartView(this);   //在本页面建立新的表格
    chart = new QChart();   //表格v
    tempurture = new QSplineSeries();   //折线，此处为光滑曲线

    chart->setTitle("实时输出");    //设置标题
    chartView->setChart(chart); //在view中设置chart图标

    tempurture->setName("温度");  //线条名字

    chart->addSeries(tempurture);   //图表添加线条

    //设置坐标轴
    chart->createDefaultAxes();
    chart->axisX()->setRange(1,NaxisX);
    chart->axisY()->setRange(200,400);

    ui->verticalLayout->addWidget(chartView);   //在该页面的vertical区域显示图表

    QList<QPointF> point;
    for(int i = 0; i < NaxisX; i++)
    {
        QPointF temp;
        temp.setX(0);
        temp.setY(0);
        point.push_back(temp);
    }
    tempurture->replace(point);
}

