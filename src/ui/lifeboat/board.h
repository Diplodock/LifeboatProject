#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QHBoxLayout>
#include <QMenu>
#include <unordered_map>
#include <fstream>
#include "../../logic/game_state.h"
#include "../../multiplayer/lifeboat/action_factory.h"
#include "../../logic/listener.h"
#include "../../logic/universal.h"
#include "../../logic/goods.h"
#include "clickablelable.h"
#include <json.hpp>

using json = nlohmann::json;


namespace Ui {
class Board;
}

class Board : public QWidget {
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    GameState gs;
    ActionFactory af;
    json j;

private:
    Ui::Board *ui;
    void initializeMarks();
    void initializeCards();
    void initializePos();
    static void addCard(ClickableLabel*, QLayout*, const std::string&);
    void addBoat();
    void addSeagull();
    void moveCard(int card_id);
    void removeCard(int card_id);
    void markDead(int id, bool b);
    void markThirsty(int id, bool b);
    void markExhaust(int id, bool b);
    void markCurPlayer(int prev_id, int cur_id);
    void changeRound(const std::string& name);
    void hpChange(int id, int hp);

    std::unordered_map<int, ClickableLabel*> map;
    std::unordered_map<int, int> pos;

    int player_ = 0;

public slots:
    void handleActionClick();
    void handleInvClick();
    void getAction(const std::string& str, int card_id_);
};
#endif // BOARD_H
