#ifndef LIFEBOAT_H
#define LIFEBOAT_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QLineEdit>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class Lifeboat; }
QT_END_NAMESPACE

class Lifeboat : public QMainWindow
{
    Q_OBJECT

public:
    Lifeboat(QWidget *parent = nullptr);
    ~Lifeboat();

private slots:
    void on__exit_clicked();
    void on__find_game_clicked();
    void on__new_game_clicked();
    void on__back_clicked();

    void on__back_2_clicked();

private:
    Ui::Lifeboat *ui;
};
#endif // LIFEBOAT_H
