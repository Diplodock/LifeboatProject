#include "lifeboat.h"
#include "./ui_lifeboat.h"

Lifeboat::Lifeboat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lifeboat)
{
    ui->setupUi(this);
}

Lifeboat::~Lifeboat()
{
    delete ui;
}
