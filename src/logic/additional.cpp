#include "additional.h"

using AddPtr = std::shared_ptr<Additional>;

AddPtr create(Additional obj) {
    return std::make_shared<Additional>(obj);
}

std::string Additional::GetKind() const {
    return kind_;
}

void Additional::SetKind(std::string kind) {
    kind_ = kind;
}

static Additional painting1;
static Additional painting2;
static Additional painting3;

static Additional money1;
static Additional money2;
static Additional money3;
static Additional money4;
static Additional money5;
static Additional money6;

static Additional jewelry1;
static Additional jewelry2;
static Additional jewelry3;

std::vector<AddPtr> listAdditional =
    {create(painting1), create(painting2), create(painting3),
    create(money1), create(money2), create(money3),
    create(money4), create(money5), create(money6),
    create(jewelry1), create(jewelry2), create(jewelry3)
    };