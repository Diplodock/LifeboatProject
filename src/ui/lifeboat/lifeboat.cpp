#include "lifeboat.h"
#include "./ui_lifeboat.h"
#include "board.h"

Lifeboat::Lifeboat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lifeboat) {
    ui->setupUi(this);
    QMainWindow::showFullScreen();
}

Lifeboat::~Lifeboat() {
    delete ui;
}

void Lifeboat::on__exit_clicked() {
    close();
}

void Lifeboat::on__find_game_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void Lifeboat::on__new_game_clicked() {
    auto* board = new Board(this);
    board->show();
}

void Lifeboat::on__back_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

void Lifeboat::on__back_2_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}
