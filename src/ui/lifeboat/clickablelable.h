#ifndef CLICKABLELABLE_H
#define CLICKABLELABLE_H

#include <QMouseEvent>
#include <QLabel>
#include <iostream>
#include "../../logic/game.h"


class ClickableLabel : public QLabel
{
Q_OBJECT
public:
    explicit ClickableLabel( const QString& text="", QWidget* parent=0 );
    ~ClickableLabel();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event) override;
};

#endif // CLICKABLELABLE_H
