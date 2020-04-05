#include "lifeboat.h"
#include "./ui_lifeboat.h"

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

}

void Lifeboat::on__new_game_clicked() {

}
