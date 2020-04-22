#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QHBoxLayout>

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

private:
    Ui::Board *ui;
};

void addCard(QLayout*);
#endif // BOARD_H
