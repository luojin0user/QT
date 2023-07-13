#ifndef ADDINFO_H
#define ADDINFO_H
#pragma once
#include "core/factory.h"
#include <QWidget>

namespace Ui {
class AddInfo;
}
class AddInfo : public QWidget
{
    Q_OBJECT

public:
    explicit AddInfo(QWidget *parent = nullptr);
    AddInfo(bool input, QWidget *parent = nullptr);
    ~AddInfo();

    void setAddInfo();  //设置初始文本信息
    bool LorS;  //设备或者工具添加，true为设备L;
    void saveInfo();


private slots:
    void on_WriteOk_clicked();  //读取输入信息,并写入vector

    void on_Reset_clicked();

    void on_AddNew_clicked();

    void closeEvent(QCloseEvent * event);
private:
    Ui::AddInfo *ui;

    Factory* pFactory;   //指示单例类的指针
    void clear_all();
};

#endif // ADDINFO_H
