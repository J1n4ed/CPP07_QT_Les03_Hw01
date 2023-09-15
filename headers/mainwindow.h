#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "about.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setConnection(QString con_str);

private slots:
    void on_action_triggered();

    void on_pb_generate_clicked();

    void on_actionAbout_triggered();

    void on_pb_update_clicked();

    void on_pb_exit_clicked();

    void on_action_2_triggered();

    void on_action_3_triggered();

private:
    Ui::MainWindow *ui;
    Dialog* dialog;
    About* about;
    QString connection;
};
#endif // MAINWINDOW_H
