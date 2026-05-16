// Copyright 2025 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (first == nullptr) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;
  countOp = 0;
  bool startLight = first->light;
  Car* cur = first;
  int steps = 0;
  do {
    cur = cur->next;
    countOp++;
    if (cur->light == startLight) {
      cur->light = !cur->light;
    }
    steps++;
  } while (cur != first);
  return steps;
}

int Train::getOpCount() {
  return countOp;
}
