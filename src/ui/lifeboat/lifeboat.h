#ifndef LIFEBOAT_H
#define LIFEBOAT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Lifeboat; }
QT_END_NAMESPACE

class Lifeboat : public QMainWindow
{
    Q_OBJECT

public:
    Lifeboat(QWidget *parent = nullptr);
    ~Lifeboat();

private:
    Ui::Lifeboat *ui;
};
#endif // LIFEBOAT_H
