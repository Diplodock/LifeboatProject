#include "logindialog.h"
#include "lifeboat_autogen/include/ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::LoginDialog) {
    ui->setupUi(this);
}

LoginDialog::~LoginDialog() {
    delete ui;
}

std::string LoginDialog::on_pushButton_clicked() {
    std::cout << ui->lineEdit->text().toStdString();
    return ui->lineEdit->text().toStdString();
}
