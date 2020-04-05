#include "lifeboat.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lifeboat w;
    w.show();
    return a.exec();
}
