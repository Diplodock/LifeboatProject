#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QHBoxLayout>
#include <QMenu>
#include "../../logic/game_state.h"
#include "../../multiplayer/lifeboat/action_factory.h"
#include "../../logic/listener.h"
#include "clickablelable.h"


namespace Ui {
class Board;
}

class Board : public QWidget {
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    Ui::Board* getUi();
    GameState gs;
    ActionFactory af;

private:
    Ui::Board *ui;
    void addCard(ClickableLabel*, QLayout*, const char*);
    void addBoat();
    void addSeagull();
    void sChange(int counter);
    void addCard(int id);
    void remUsed(int id);
    void remNotUsed(std::vector<int> ids);
    void hpChange(int id, int hp);
    void exChange(int id, bool is);
    void dChange(int id, bool is);
    void thirstChange(int id, bool is);
    void addOutboard(int id);
    void turnChange(int id);

    int player_ = 0;

public slots:
    void handleClick();
    void getAction(const std::string& str, int card_id_);
};
#endif // BOARD_H
