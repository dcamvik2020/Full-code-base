#include "field.h"

Field::Field() {
    for (int i = 0; i < 4; i++)
        sides[i] = 0;
}

void Field::left() {
    sides[0] = 1;
}

void Field::up() {
    sides[1] = 1;
}

void Field::right() {
    sides[2] = 1;
}

void Field::down() {
    sides[3] = 1;
}
