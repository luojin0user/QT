#ifndef RTSHOW_H
#define RTSHOW_H
#pragma once
#include <QWidget>
#include <QTimer>
#include <QCloseEvent>
#include <sstream>
#include "core/factory.h"

// 包含line chart需要的头文件
#include <QChartView>
#include <QSplineSeries>
#include <QScatterSeries>
#include <QValueAxis>
#include <QtMath>

#define NaxisX 20   //x轴的长度

namespace Ui {
class RTshow;
}

class RTshow : public QWidget
{
    Q_OBJECT

public:
    //explicit RTshow(QWidget *parent = nullptr);
    explicit RTshow(int getRow, QWidget *parent = nullptr);
    ~RTshow();

    void init(string str);

private slots:
    void on_back_clicked(); //返回功能
    void refresh(); //刷新函数

private:
    Factory* pFactory;   //指示单例类的指针

    int nRTrow;   //当前设备所在的行(在allRTdata中)
    int refreshCol; //当前刷新的行数
    float temp_charts[NaxisX] = {0};    //储存表格数据的数组
    Ui::RTshow *ui;

    void closeEvent(QCloseEvent *event);    
    void charts_init(); //表格初始化函数
    bool flag; //是否有这个类型
    QTimer timer;   //用于实时刷新的定时器

    QChart *chart;  //表格
    QChartView *chartView;  //显示表格
    QSplineSeries *tempurture;  //曲线（温度）
};

#endif // RTSHOW_H
