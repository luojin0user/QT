#ifndef TABLESHOW_H
#define TABLESHOW_H

#pragma once
#include <QWidget>
#include "mainwindow.h"
#include "ui_tableshow.h"
#include "addinfo.h"
#include "rtshow.h"
#include <QTimer>
#include <QCloseEvent>
#include "core/struct_transfer.h"

namespace Ui {
class TableShow;
}

class TableShow : public QWidget
{
    Q_OBJECT

public:
    explicit TableShow(QWidget *mainshow, QWidget *parent = nullptr);
    ~TableShow();

    void table_init_Large();    //输出设备的初始化函数
    void table_init_Small();
    void table_write_large();   //将表格除表头外的部分全部重写(根据vector)
    void table_write_small();
    void closeEvent(QCloseEvent *event);    //点击关闭后触发的事件
    void RT_show_all(); //全部

    bool LorS;  //大小设备选择
    QTimer timer;   //用于实时刷新的定时器

private slots:
    void on_back_clicked(); //返回按钮

    void show_str(const char *s);   //左上角功能输出

    void on_tablePush_clicked();    //刷新功能

    void on_ButtonAddNew_clicked(); //添加新设备按钮

    void on_table_output_cellClicked(int row, int column);  //读取选中的单元格

    void on_DeleteRow_clicked();    //删除一行设备

    void on_edit_enable_clicked();  //编辑使能
    void on_edit_disable_clicked(); //使不能编辑

    void on_saveAll_clicked();  //保存按钮

    void on_startSearch_clicked();  //开始查找按钮

    void on_searchReset_clicked();  //重找重置按钮
    void column_sort(int);  //列排序，点击列排序时调用该函数
    void sort_init();   //排序初始化函数，Large与Small都需要调用该函数

    void on_startRT_clicked();  //开始实时输出按钮，调用RT_show_all函数
    void on_stopRT_clicked();   //停止实时输出按钮
    void refresh_table();   //实时输出刷新界面函数
    void on_startBadMessage_clicked();  //使能损坏弹窗
    void on_stopBadMessage_clicked();   //不使能损坏弹窗
    void show_time();   //右上角显示时间

private:
    Ui::TableShow *ui;

    Factory* pFactory;   //指示单例类的指针
    QWidget *mainwindows;   //用于指示主界面的指针
    int selRow; //当前选中的行
    int refreshCol; //当前刷新的行
    bool search;    //是否在查找模式
    bool badMessage;    //是否开启损坏弹窗
    bool back;  //指示是返回还是关闭
    QTimer dateTimer;
    vector<int> location; //所查找的设备的下标

    void set_header_large();    //大型设备表头设置
    void set_header_small();    //其他设备表头设置
    void createItemsARow(int nRow, DeviceLargeInfo &info); //为某一行创建 items
    void createItemsARow(int nRow, DeviceSmallInfo &info);
    void QStrItem(bool red,int nRow,int nCol,string strIn); //将一个数据写入一个单元格，三种不同的数据
    void QStrItem(bool red,int nRow,int nCol,bool bIn);
    void QStrItem(bool red,int nRow,int nCol,float fIn);


};

#endif // TABLESHOW_H
