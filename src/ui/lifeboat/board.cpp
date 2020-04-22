#include "board.h"
#include "ui_board.h"
#include "clickablelable.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board) {
    ui->setupUi(this);
    addCard(ui->boat_layout);
    addCard(ui->boat_layout);
}

Board::~Board() {
    delete ui;
}

void addCard(QLayout* lo) {
    ClickableLabel *label = new ClickableLabel();
    label->setPixmap(QPixmap(":/resources/cards/characters/boatswain.jpg"));
    label->setScaledContents(true);
    label->setMaximumHeight(165);
    label->setMaximumWidth(119);
    lo->addWidget(label);
}
