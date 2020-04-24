#include "lifeboat.h"
#include "json.hpp"

#include <QApplication>
using json = nlohmann::json;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Lifeboat w;
    w.show();
    return a.exec();
}
