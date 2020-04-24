#include "board.h"
#include "ui_board.h"
#include "clickablelable.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board) {
    ui->setupUi(this);
    auto *label = new ClickableLabel("", this);
    label->setPixmap(QPixmap(":/resources/cards/shirts/navigation.jpg"));
    label->setScaledContents(true);
    label->setMaximumHeight(135);
    label->setMaximumWidth(95);
    ui->navLayout->addWidget(label);
}

Board::~Board() {
    delete ui;
}

void addCard(QLayout* lo) {
    ClickableLabel *label = new ClickableLabel();
    label->setPixmap(QPixmap(":/resources/cards/shirts/navigation.jpg"));
    label->setScaledContents(true);
    label->setMaximumHeight(135);
    label->setMaximumWidth(95);
    lo->addWidget(label);
}

void Board::on_pushButton_clicked() {
    seagulls++;
    if (seagulls == 4) exit(0);
    auto *label = new ClickableLabel("", this);
    label->setPixmap(QPixmap(":/resources/seagull.png"));
    label->setScaledContents(true);
    label->setMaximumHeight(30);
    label->setMaximumWidth(30);
    ui->gullLayout->addWidget(label);
}
