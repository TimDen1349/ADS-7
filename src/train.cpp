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
  bool startLight = first->light;
  int step = 0;

  while (true) {
    ++step;
    // идём на step вагонов вперёд
    Car* cur = first;
    for (int i = 0; i < step; ++i) {
      cur = cur->next;
      ++countOp;
    }
    // если свет совпадает с начальным
    if (cur->light == startLight) {
      cur->light = !cur->light;         // переключаем
      if (cur != first) {               // возвращаемся назад, если не первый
        for (int i = 0; i < step; ++i) {
          cur = cur->prev;
          ++countOp;
        }
      }
      // если свет в первом вагоне изменился – длина найдена
      if (first->light != startLight) {
        return step;
      }
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
