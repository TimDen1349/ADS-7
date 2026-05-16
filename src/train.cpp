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
  if (first == nullptr) {
    return 0;
  }
  countOp = 0;
  bool originalLight = first->light;
  int length = 0;

  while (true) {
    int steps = 0;
    Car* cur = first;
    do {
      cur = cur->next;
      steps++;
      countOp++;
    } while (cur->light != first->light && cur != first);

    cur->light = !cur->light;

    for (int i = 0; i < steps; ++i) {
      cur = cur->prev;
      countOp++;
    }

    if (first->light != originalLight) {
      length = steps;
      break;
    }
  }
  return length;
}

int Train::getOpCount() {
  return countOp;
}
