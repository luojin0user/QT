#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include "tableshow.h"
#include "addinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LargeShow_clicked();

    void on_SmallShow_clicked();

    void on_RTbutton_clicked();

    void on_close_clicked();


    void on_user_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
