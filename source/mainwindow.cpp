#include "../headers/mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog = new Dialog(this);
    about = new About(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    MainWindow::close();
}


void MainWindow::on_pb_generate_clicked()
{
    dialog->exec();
    this->setConnection(dialog->get_string());
    ui->txt_results->setText(connection);
}


void MainWindow::on_actionAbout_triggered()
{
    about->show();
}

void MainWindow::setConnection(QString con_str)
{
    connection = con_str;
}


void MainWindow::on_pb_update_clicked()
{
    ui->txt_results->setText(connection);
}


void MainWindow::on_pb_exit_clicked()
{
    this->close();
}

