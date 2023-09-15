#include "../headers/about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    QPixmap pix("./resource/duck.gif");
    mo.setFileName("./resource/duck.gif");
    ui->lable_image->setMovie(&mo);
    mo.start();
}

About::~About()
{
    delete ui;
}

void About::on_pb_close_about_clicked()
{
    this->close();
}

