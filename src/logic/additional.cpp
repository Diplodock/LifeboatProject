#include "additional.h"

std::string Additional::GetKind() const {
    return kind_;
}

void Additional::SetKind(std::string kind) {
    kind_ = kind;
}