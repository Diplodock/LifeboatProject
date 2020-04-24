#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QHBoxLayout>
#include "../../logic/game_state.h"

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    GameState game;
    int seagulls = 0;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Board *ui;
};

void addCard(QLayout*);
#endif // BOARD_H
