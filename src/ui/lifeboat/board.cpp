#include "board.h"
#include "ui_board.h"
#include "clickablelable.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board),
    gs(6) {
    ui->setupUi(this);
    addBoat();
    std::function<ActionPtr(int, int, int)> constructor1 = [](int a, int b, int c) {
        TakeItemsAction action(a, b, c);
        return std::make_unique<TakeItemsAction>(action);
    };
    af.RegisterAction("TakeItemsAction", constructor1);
    std::function<ActionPtr(int, int, int)> constructor2 = [](int a, int b, int c) {
        Example action(a, b, c);
        return std::make_unique<Example>(action);
    };
    af.RegisterAction("Example", constructor2);
    std::function<ActionPtr(int, int, int)> constructor3 = [](int a, int b, int c) {
        TakeNavigationCard action(a, b, c);
        return std::make_unique<TakeNavigationCard>(action);
    };
    af.RegisterAction("TakeNavigationCard", constructor3);
    std::function<ActionPtr(int, int, int)> constructor4 = [](int a, int b, int c) {
        ChooseItem action(a, b, c);
        return std::make_unique<ChooseItem>(action);
    };
    af.RegisterAction("ChooseItem", constructor4);
    std::function<ActionPtr(int, int, int)> constructor5 = [](int a, int b, int c) {
        ChooseNavigationCard action(a, b, c);
        return std::make_unique<ChooseNavigationCard>(action);
    };
    af.RegisterAction("ChooseNavigationCard", constructor5);
    std::function<ActionPtr(int, int, int)> constructor6 = [](int a, int b, int c) {
        Row action(a, b, c);
        return std::make_unique<Row>(action);
    };
    af.RegisterAction("Row", constructor6);
}

Board::~Board() {
    delete ui;
}

void Board::addCard(ClickableLabel* label, QLayout* lo, const char* path) {
    label->setPixmap(QPixmap(path));
    label->setScaledContents(true);
    label->setMaximumHeight(135);
    label->setMaximumWidth(95);
    lo->addWidget(label);
}

void Board::addSeagull() {
    auto* seagull = new QLabel(this);
    seagull->setPixmap(QPixmap(":/resources/seagull.png"));
    seagull->setScaledContents(true);
    seagull->setMaximumHeight(35);
    seagull->setMaximumWidth(35);
    ui->gull_layout->addWidget(seagull);
}

void Board::addBoat() {
    auto *lady = new ClickableLabel("", this, 5);
    auto *captain = new ClickableLabel("", this, 1);
    auto *frenchy = new ClickableLabel("", this, 2);
    auto boatswain = new ClickableLabel("", this, 0);
    auto *snob = new ClickableLabel("", this, 6);
    auto *kid = new ClickableLabel("", this, 4);
    connect(lady, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(captain, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(frenchy, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(boatswain, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(snob, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(kid, &ClickableLabel::clicked, this, &Board::handleClick);
    addCard(lady, ui->boat_layout,":/resources/cards/characters/lady.jpg");
    addCard(captain, ui->boat_layout,":/resources/cards/characters/captain.jpg");
    addCard(frenchy, ui->boat_layout,":/resources/cards/characters/frenchy.jpg");
    addCard(boatswain, ui->boat_layout,":/resources/cards/characters/boatswain.jpg");
    addCard(snob, ui->boat_layout,":/resources/cards/characters/snob.jpg");
    addCard(kid, ui->boat_layout,":/resources/cards/characters/kid.jpg");
}

void Board::handleClick() {
    auto* menu = new QMenu( this);
    auto* card = reinterpret_cast<ClickableLabel*>(sender());
    std::vector<std::string> cur = gs.GetAvailableActions(card->id_, player_);
    for (const std::string& it : cur) {
        auto* act = new QAction(QString::fromStdString(it), this);
        connect(act, &QAction::triggered, this,
                [=] {getAction(it, card->id_);});
        menu->addAction(act);
    }
    menu->exec(QCursor::pos());
}

void Board::getAction(const std::string& str, int card_id_) {
    ActionPtr p1 = af.CreateAction(str, player_, card_id_, 0);
    p1->exec(gs);
}

void Board::sChange(int counter) {

}

void Board::addCard(int id) {

}

void Board::remUsed(int id) {

}

void Board::remNotUsed(std::vector<int> ids) {

}

void Board::hpChange(int id, int hp) {

}

void Board::exChange(int id, bool is) {

}

void Board::dChange(int id, bool is) {

}

void Board::thirstChange(int id, bool is) {

}

void Board::addOutboard(int id) {

}

void Board::turnChange(int id) {

}

