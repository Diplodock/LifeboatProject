#include "board.h"
#include "ui_board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board),
    gs(6) {
    ui->setupUi(this);
    std::ifstream jsonreader("cards.json");
    jsonreader >> j;
    initializeCards();
    initializeMarks();
    initializePos();
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
    std::function<void()> func = [&]() {
        addSeagull();
    };
    std::function<void(int)> func2 = [&](int id) {
        moveCard(id);
    };
    std::function<void(int)> func3 = [&](int id) {
        removeCard(id);
    };
    std::function<void(std::vector<int> ids)> func4 = [&](const std::vector<int>& ids) {
        for (int x : ids) removeCard(x);
    };
    auto *seag = new SeagullsListener(func);
    auto *cardsonboard = new AddCardsOnBoardListener(func2);
    auto *remusedcard = new RemoveUsedCardListener(func3);
    auto *remnotusedcard = new RemoveNotUsedCardsListener(func4);
    gs.AddSListener(std::make_shared<SeagullsListener>(*seag));
    gs.AddAddListener(std::make_shared<AddCardsOnBoardListener>(*cardsonboard));
    gs.AddRemUsedListener(std::make_shared<RemoveUsedCardListener>(*remusedcard));
    gs.AddRemNotUsedListener(std::make_shared<RemoveNotUsedCardsListener>(*remnotusedcard));
}

Board::~Board() {
    delete ui;
}

void Board::addCard(ClickableLabel* label, QLayout* lo, const std::string& path) {
    label->setPixmap(QPixmap(path.c_str()));
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

void Board::moveCard(int card_id) {
    addCard(map[card_id], ui->game_layout, j["cards"][card_id]["path"]);
}

void Board::hpChange(int id, int hp) {
    int player_pos = pos[id];
    switch (player_pos) {
        case 0:
            ui->hp_0->display(hp);
        case 1:
            ui->hp_1->display(hp);
        case 2:
            ui->hp_2->display(hp);
        case 3:
            ui->hp_3->display(hp);
        case 4:
            ui->hp_4->display(hp);
        case 5:
            ui->hp_5->display(hp);
    }
}

void Board::removeCard(int card_id) {
    map[card_id]->close();
}

void Board::addBoat() {
    addCard(map[5], ui->player_0,j["cards"][5]["path"]);
    addCard(map[1], ui->player_1,j["cards"][1]["path"]);
    addCard(map[2], ui->player_2,j["cards"][2]["path"]);
    addCard(map[0], ui->player_3,j["cards"][0]["path"]);
    addCard(map[6], ui->player_4,j["cards"][6]["path"]);
    addCard(map[4], ui->player_5,j["cards"][4]["path"]);
    addCard(map[98], ui->supplies, j["cards"][98]["path"]);
    addCard(map[99], ui->nav_layout, j["cards"][99]["path"]);
}

void Board::markDead(int id, bool b) {
    (void) b;
    int player_pos = pos[id];
    switch (player_pos) {
        case 0:
            ui->dead_0->show();
        case 1:
            ui->dead_1->show();
        case 2:
            ui->dead_2->show();
        case 3:
            ui->dead_3->show();
        case 4:
            ui->dead_4->show();
        case 5:
            ui->dead_5->show();
        default:
            return;
    }
}

void Board::markThirsty(int id, bool b) {
    int player_pos = pos[id];
    switch (player_pos) {
        case 0:
            if (b) ui->thirsty_0->show();
            if (!b) ui->thirsty_0->hide();
        case 1:
            if (b) ui->thirsty_1->show();
            if (!b) ui->thirsty_1->hide();
        case 2:
            if (b) ui->thirsty_2->show();
            if (!b) ui->thirsty_2->hide();
        case 3:
            if (b) ui->thirsty_3->show();
            if (!b) ui->thirsty_3->hide();
        case 4:
            if (b) ui->thirsty_4->show();
            if (!b) ui->thirsty_4->hide();
        case 5:
            if (b) ui->thirsty_5->show();
            if (!b) ui->thirsty_5->hide();
        default:
            return;
    }
}

void Board::markExhaust(int id, bool b) {
    int player_pos = pos[id];
    switch (player_pos) {
        case 0:
            if (b) ui->exhaust_0->show();
            if (!b) ui->exhaust_0->hide();
        case 1:
            if (b) ui->exhaust_1->show();
            if (!b) ui->exhaust_1->hide();
        case 2:
            if (b) ui->exhaust_2->show();
            if (!b) ui->exhaust_2->hide();
        case 3:
            if (b) ui->exhaust_3->show();
            if (!b) ui->exhaust_3->hide();
        case 4:
            if (b) ui->exhaust_4->show();
            if (!b) ui->exhaust_4->hide();
        case 5:
            if (b) ui->exhaust_5->show();
            if (!b) ui->exhaust_5->hide();
        default:
            return;
    }
}

void Board::markCurPlayer(int id) {
//    int player_pos = pos[id];
//    switch (player_pos) {
//        case 0:
//            if (b) ui->exhaust_0->show();
//            if (!b) ui->exhaust_0->hide();
//        case 1:
//            if (b) ui->exhaust_1->show();
//            if (!b) ui->exhaust_1->hide();
//        case 2:
//            if (b) ui->exhaust_2->show();
//            if (!b) ui->exhaust_2->hide();
//        case 3:
//            if (b) ui->exhaust_3->show();
//            if (!b) ui->exhaust_3->hide();
//        case 4:
//            if (b) ui->exhaust_4->show();
//            if (!b) ui->exhaust_4->hide();
//        case 5:
//            if (b) ui->exhaust_5->show();
//            if (!b) ui->exhaust_5->hide();
//        default:
//            return;
//    }
}

void Board::initializeCards() {
    auto *lady = new ClickableLabel("", this, 5);
    auto *captain = new ClickableLabel("", this, 1);
    auto *frenchy = new ClickableLabel("", this, 2);
    auto *boatswain = new ClickableLabel("", this, 0);
    auto *snob = new ClickableLabel("", this, 6);
    auto *kid = new ClickableLabel("", this, 4);
    auto *supplies = new ClickableLabel("", this, 98);
    auto *navigation = new ClickableLabel("", this, 99);
    auto *painting1 = new ClickableLabel("", this, 24);
    auto *painting2 = new ClickableLabel("", this, 25);
    auto *painting3 = new ClickableLabel("", this, 26);
    auto *money1 = new ClickableLabel("", this, 27);
    auto *money2 = new ClickableLabel("", this, 28);
    auto *money3 = new ClickableLabel("", this, 29);
    auto *money4 = new ClickableLabel("", this, 30);
    auto *money5 = new ClickableLabel("", this, 31);
    auto *money6 = new ClickableLabel("", this, 32);
    auto *jewelry1 = new ClickableLabel("", this, 33);
    auto *jewelry2 = new ClickableLabel("", this, 34);
    auto *jewelry3 = new ClickableLabel("", this, 35);
    auto *water1 = new ClickableLabel("", this, 36);
    auto *water2 = new ClickableLabel("", this, 37);
    auto *water3 = new ClickableLabel("", this, 38);
    auto *water4 = new ClickableLabel("", this, 39);
    auto *water5 = new ClickableLabel("", this, 40);
    auto *water6 = new ClickableLabel("", this, 41);
    auto *water7 = new ClickableLabel("", this, 42);
    auto *water8 = new ClickableLabel("", this, 43);
    auto *water9 = new ClickableLabel("", this, 44);
    auto *water10 = new ClickableLabel("", this, 45);
    auto *water11 = new ClickableLabel("", this, 46);
    auto *water12 = new ClickableLabel("", this, 47);
    auto *water13 = new ClickableLabel("", this, 48);
    auto *water14 = new ClickableLabel("", this, 49);
    auto *water15 = new ClickableLabel("", this, 50);
    auto *water16 = new ClickableLabel("", this, 51);
    auto *water17 = new ClickableLabel("", this, 52);
    auto *umbrella = new ClickableLabel("", this, 53);
    auto *trap1 = new ClickableLabel("", this, 54);
    auto *trap2 = new ClickableLabel("", this, 55);
    auto *medkit1 = new ClickableLabel("", this, 56);
    auto *medkit2 = new ClickableLabel("", this, 57);
    auto *medkit3 = new ClickableLabel("", this, 58);
    auto *lifebouy = new ClickableLabel("", this, 59);
    auto *compass = new ClickableLabel("", this, 60);
    auto *cannibalism = new ClickableLabel("", this, 61);
    auto *vodka = new ClickableLabel("", this, 62);
    auto *paddle1 = new ClickableLabel("", this, 63);
    auto *paddle2 = new ClickableLabel("", this, 64);
    auto *flaregun = new ClickableLabel("", this, 65);
    auto *harpoon = new ClickableLabel("", this, 66);
    auto *knife = new ClickableLabel("", this, 67);
    auto *club = new ClickableLabel("", this, 68);
    auto *nav1 = new ClickableLabel("", this, 69);
    auto *nav2 = new ClickableLabel("", this, 70);
    auto *nav3 = new ClickableLabel("", this, 71);
    auto *nav4 = new ClickableLabel("", this, 72);
    auto *nav5 = new ClickableLabel("", this, 73);
    auto *nav6 = new ClickableLabel("", this, 74);
    auto *nav7 = new ClickableLabel("", this, 75);
    auto *nav8 = new ClickableLabel("", this, 76);
    auto *nav9 = new ClickableLabel("", this, 77);
    auto *nav10 = new ClickableLabel("", this, 78);
    auto *nav11 = new ClickableLabel("", this, 79);
    auto *nav12 = new ClickableLabel("", this, 80);
    auto *nav13 = new ClickableLabel("", this, 81);
    auto *nav14 = new ClickableLabel("", this, 82);
    auto *nav15 = new ClickableLabel("", this, 83);
    auto *nav16 = new ClickableLabel("", this, 84);
    auto *nav17 = new ClickableLabel("", this, 85);
    auto *nav18 = new ClickableLabel("", this, 86);
    auto *nav19 = new ClickableLabel("", this, 87);
    auto *nav20 = new ClickableLabel("", this, 88);
    auto *nav21 = new ClickableLabel("", this, 89);
    auto *nav22 = new ClickableLabel("", this, 90);
    auto *nav23 = new ClickableLabel("", this, 91);
    auto *nav24 = new ClickableLabel("", this, 92);
    auto *nav25 = new ClickableLabel("", this, 93);
    auto *nav26 = new ClickableLabel("", this, 94);
    auto *nav27 = new ClickableLabel("", this, 95);
    auto *nav28 = new ClickableLabel("", this, 96);
    auto *nav29 = new ClickableLabel("", this, 97);
    map[5] = lady;
    map[1] = captain;
    map[2] = frenchy;
    map[0] = boatswain;
    map[6] = snob;
    map[4] = kid;
    map[98] = supplies;
    map[99] = navigation;
    map[24] = painting1;
    map[25] = painting2;
    map[26] = painting3;
    map[27] = money1;
    map[28] = money2;
    map[29] = money3;
    map[30] = money4;
    map[31] = money5;
    map[32] = money6;
    map[33] = jewelry1;
    map[34] = jewelry2;
    map[35] = jewelry3;
    map[36] = water1;
    map[37] = water2;
    map[38] = water3;
    map[39] = water4;
    map[40] = water5;
    map[41] = water6;
    map[42] = water7;
    map[43] = water8;
    map[44] = water9;
    map[45] = water10;
    map[46] = water11;
    map[47] = water12;
    map[48] = water13;
    map[49] = water14;
    map[50] = water15;
    map[51] = water16;
    map[52] = water17;
    map[53] = umbrella;
    map[54] = trap1;
    map[55] = trap2;
    map[56] = medkit1;
    map[57] = medkit2;
    map[58] = medkit3;
    map[59] = lifebouy;
    map[60] = compass;
    map[61] = cannibalism;
    map[62] = vodka;
    map[63] = paddle1;
    map[64] = paddle2;
    map[65] = flaregun;
    map[66] = harpoon;
    map[67] = knife;
    map[68] = club;
    map[69] = nav1;
    map[70] = nav2;
    map[71] = nav3;
    map[72] = nav4;
    map[73] = nav5;
    map[74] = nav6;
    map[75] = nav7;
    map[76] = nav8;
    map[77] = nav9;
    map[78] = nav10;
    map[79] = nav11;
    map[80] = nav12;
    map[81] = nav13;
    map[82] = nav14;
    map[83] = nav15;
    map[84] = nav16;
    map[85] = nav17;
    map[86] = nav18;
    map[87] = nav19;
    map[88] = nav20;
    map[89] = nav21;
    map[90] = nav22;
    map[91] = nav23;
    map[92] = nav24;
    map[93] = nav25;
    map[94] = nav26;
    map[95] = nav27;
    map[96] = nav28;
    map[97] = nav29;
    connect(lady, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(captain, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(frenchy, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(boatswain, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(snob, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(kid, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(supplies, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(navigation, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(compass, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(cannibalism, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(vodka, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(paddle1, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(paddle2, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(flaregun, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(harpoon, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(knife, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(club, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(painting1, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(painting2, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(painting3, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(money1, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(money2, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(money3, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(money4, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(money5, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(money6, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(jewelry1, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(jewelry2, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(jewelry3, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water1, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water2, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water3, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water4, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water5, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water6, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water7, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water8, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water9, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water10, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water11, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water12, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water13, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water14, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water15, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water16, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(water17, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(umbrella, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(trap1, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(trap2, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(medkit1, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(medkit2, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(medkit3, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(lifebouy, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav1, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav2, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav3, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav4, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav5, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav6, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav7, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav8, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav9, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav10, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav11, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav12, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav13, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav14, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav15, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav16, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav17, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav18, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav19, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav20, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav21, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav22, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav23, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav24, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav25, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav26, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav27, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav28, &ClickableLabel::clicked, this, &Board::handleClick);
    connect(nav29, &ClickableLabel::clicked, this, &Board::handleClick);
}

void Board::initializeMarks() {
    ui->dead_0->hide();
    ui->dead_1->hide();
    ui->dead_2->hide();
    ui->dead_3->hide();
    ui->dead_4->hide();
    ui->dead_5->hide();
    ui->thirsty_0->hide();
    ui->thirsty_1->hide();
    ui->thirsty_2->hide();
    ui->thirsty_3->hide();
    ui->thirsty_4->hide();
    ui->thirsty_5->hide();
    ui->exhaust_0->hide();
    ui->exhaust_1->hide();
    ui->exhaust_2->hide();
    ui->exhaust_3->hide();
    ui->exhaust_4->hide();
    ui->exhaust_5->hide();
    ui->cur_player_0->hide();
    ui->cur_player_1->hide();
    ui->cur_player_2->hide();
    ui->cur_player_3->hide();
    ui->cur_player_4->hide();
    ui->cur_player_5->hide();
}

void Board::initializePos() {
    pos[5] = 0;
    pos[1] = 1;
    pos[2] = 2;
    pos[0] = 3;
    pos[6] = 4;
    pos[4] = 5;
}


void Board::handleClick() {
    auto* menu = new QMenu( this);
    auto* card = reinterpret_cast<ClickableLabel*>(sender());
    std::vector<std::string> cur = gs.GetAvailableActions(card->id_, player_);
    for (const std::string& it : cur) {
        auto* act = new QAction(QString::fromStdString(it), this);
        connect(act, &QAction::triggered, this,
                [&] {getAction(it, card->id_);});
        menu->addAction(act);
    }
    menu->exec(QCursor::pos());
}

void Board::getAction(const std::string& str, int card_id_) {
    ActionPtr p1 = af.CreateAction(str, player_, card_id_, 0);
    p1->exec(gs);
}

