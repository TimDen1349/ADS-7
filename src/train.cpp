// Copyright 2025 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (first == nullptr) {
    first = newCar;
    first->next = first;
    first->prev = first;
    return;
  }
  Car* last = first->prev;
  last->next = newCar;
  newCar->prev = last;
  newCar->next = first;
  first->prev = newCar;
}

int Train::getLength() {
  if (first == nullptr) return 0;
  countOp = 0;
  bool original = first->light;
  first->light = !original;
  int steps = 0;
  Car* cur = first;
  do {
    cur = cur->next;
    ++countOp;
    ++steps;
  } while (cur->light != first->light);
  for (int i = 0; i < steps; ++i) {
    cur = cur->prev;
    ++countOp;
  }
  return steps;
}

int Train::getOpCount() {
  return countOp;
}
