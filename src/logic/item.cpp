#include "item.h"

bool Item::GetPosition() const {
    return position_;
}

int Item::GetPoints() const {
    return points_;
}

void Item::SetPosition(bool position) {
    position_ = position;
}

void Item::SetPoints(int points) {
    points_ = points;
}