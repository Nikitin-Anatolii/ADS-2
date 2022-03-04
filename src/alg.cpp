// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 1)
    return value;
  else if (n == 0)
    return 1;
  else
    return value * pown(value, n - 1);
}

uint64_t fact(uint16_t n) {
  if ((n == 0) || (n == 1))
    return 1;
  else
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) * 1. / fact(n);
}

double expn(double x, uint16_t count) {
  if (count == 0)
    return calcItem(x, count);
  else
    return calcItem(x, count) + expn(x, count - 1);
}

double sinn(double x, uint16_t count) {
  if (count == 0)
    return 0;
  else
    return (pown(-1, count - 1) * calcItem(x, 2 * count - 1)) + sinn(x, count - 1);
}

double cosn(double x, uint16_t count) {
  if (count == 0)
    return 0;
  else
    return pown(-1, count - 1) * calcItem(x, 2 * (count - 1)) + cosn(x, count - 1);
}
