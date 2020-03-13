#ifndef LIFEBOAT_H
#define LIFEBOAT_H

#include <QMainWindow>
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
    void on_pushButton_clicked();

private:
    Ui::Lifeboat *ui;
};
#endif // LIFEBOAT_H
