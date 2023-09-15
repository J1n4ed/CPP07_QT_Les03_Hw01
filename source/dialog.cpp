#include "../headers/dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{    
    delete ui;
}

QString Dialog::makeString(QString db_host, QString db_name, QString db_login, QString db_pwd, uint db_port)
{
    QString connection_string;

    // build postgreSQL connection string

    // "user=<user> password=<pwd> host=<host> port=<port> dbname=<db name>"

    connection_string = "user=" + db_login + " password=" + db_pwd + " host=" + db_host + " port =" + QString::number(db_port) + " dbname=" + db_name;

    return connection_string;
}

void Dialog::on_buttonBox_accepted()
{
    con_str = makeString(ui->txt_host_name->text(), ui->txt_bd_name->text(), ui->txt_login->text(), ui->txt_pwd->text(), ui->sb_port->value());
}

QString Dialog::get_string()
{
    return con_str;
}
