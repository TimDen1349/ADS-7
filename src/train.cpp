// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train():countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* car = new Car;
    car->light = light;

    if (first == nullptr) {
        first = car;
        car->next = car;
        car->prev = car;
    } else {
        Car* last = first->prev;

        car->next = first;
        car->prev = last;

        last->next = car;
        first->prev = car;
    }
}

int Train::getLength() {
    countOp = 0;
    if (first == nullptr) {
        return 0;
    }
    first->light = true;

    while (1) {
        Car* cur = first;
        int len = 0;
        do {
            cur = cur->next;
            ++countOp;
            ++len;
        } while (!cur->light);
        cur->light = false;

        for (int i = 0; i < len; ++i) {
            cur = cur->prev;
            ++countOp;
        }
        if (!cur->light) {
            return len;
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
