#pragma once
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDate>
#include <QMessageBox>
#include "core/factory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LargeShow_clicked() //输出大型设备
{
    this->setVisible(false);
    TableShow *table = new TableShow(this);
    table->setWindowTitle("生产设备输出");
    table->LorS = true;
    table->table_init_Large();
    table->show();
}
void MainWindow::on_SmallShow_clicked() //输出其他设备
{
    this->setVisible(false);
    TableShow *table = new TableShow(this);
    table->setWindowTitle("其他设备输出");
    table->LorS = false;
    table->table_init_Small();
    table->show();
}

void MainWindow::on_RTbutton_clicked()  //实时输出功能按键
{
    //弹出窗口提示
    QMessageBox::information(this,"提示","开始实时显示\n实时显示需要一定的运算量\n",QMessageBox::Ok);
    this->setVisible(false);    //使当前页面不可见
    TableShow *table = new TableShow(this);
    table->setWindowTitle("生产设备实时显示");
    table->LorS = true;
    table->table_init_Large();
    table->RT_show_all();
    table->show();
}

void MainWindow::on_close_clicked() //关闭窗口
{
    this->close();
    Factory::GetInstance()->deleteInstance();
}

void MainWindow::on_user_clicked()  //软件说明
{
    QMessageBox::about(this,"软件说明",
                             "软件使用说明：\n"
                             "1.排序功能：点击横向表头即可排序\n"
                             "2.编辑功能：右上角编辑按键选择是，然后双击表格中的某一项即可编辑\t\n"
                             "   注意：编辑时使用空格键进行多项设备的输入,不可使用英文逗号键\n"
                             "3.搜索功能：输入需要搜索的设备名，OID，OEM，用户名均可实现搜索\n"
                             "4.注意编辑、删除、添加操作完后需要按键保存\n"
                             "5.其他事项：进入详细信息可以查看单独某一设备的详细信息及实时输出\t\n"
                             "6.由于设备损坏概率较高，开启损坏弹窗会在每次损坏时弹窗可能导致难以关闭\t\n"
                             "7.对于未使用的设备，我们将不开启实时刷新\t\n"
                             "\n软件简介：\n"
                             "1.使用QT与VS开发,VS用于开发后端逻辑部分，QT用于开发图像化界面\t\n"
                             "   两者共同使用可以实现更快的Debug,利于程序开发与测试\n"
                             "2.逻辑部分与GUI两者通过逻辑部分单例类的接口进行交互,\n"
                             "   实现了逻辑部分与GUI的分离，更为高效，且利于两部分的升级与迭代\t\n"
                             "3.软件的实时输出部分采用读取设备实时信息文件的方式进行，该方式更加\n"
                             "   符合实际（采用外界信息传入的方式，例如串口传入的方式会更好）\n"
                             "4.本软件数据更多出于演示目的，与实际情况可能不符合\t\n"
                             "5.实时输出中，我们为了展示每一个设备的信息相对应其实时数据，将设备\n"
                             "   的损坏概率设置为与设备OID的最后两位相同"
                             );
}

