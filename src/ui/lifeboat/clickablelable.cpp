#include "clickablelable.h"

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent, int id)
    : QLabel(parent), id_(id) {
    setText(text);
}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
