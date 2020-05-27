#ifndef CLICKABLELABLE_H
#define CLICKABLELABLE_H

#include <QMouseEvent>
#include <QLabel>
#include <vector>
#include <string>

class ClickableLabel : public QLabel {

Q_OBJECT

public:
    explicit ClickableLabel(const QString& text = "", QWidget* parent = nullptr, int id = -1);
    int id_;
private:
    ~ClickableLabel();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABLE_H
