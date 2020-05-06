#include "clickablelable.h"
#include <iostream>

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent)
    : QLabel(parent) {
    setText(text);
}

ClickableLabel::~ClickableLabel() {
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
