#include "lifeboat.h"
#include "./ui_lifeboat.h"
#include "logindialog.h"

Lifeboat::Lifeboat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lifeboat) {
    ui->setupUi(this);
}


Lifeboat::~Lifeboat() {
    delete ui;
}

void Lifeboat::on__exit_clicked() {
    close();
}

void Lifeboat::on__find_game_clicked() {
    LoginDialog loginDialog;
    loginDialog.setModal(true);
    loginDialog.exec();
}

void Lifeboat::on__new_game_clicked() {

}
