#include "benfordslaw.h"
#include <QDebug>
#include <algorithm>

BenfordsLaw::BenfordsLaw() {}

int
BenfordsLaw::firstDigit(long n)
{
  while (n > 9) {
    n /= 10;
  }
  return n;
}

int
BenfordsLaw::firstDigit(double n)
{
  if (n <= 0)
    return 0;
  while (n < 1)
    n *= 10;
  return firstDigit((long)n);
}

void
BenfordsLaw::compute(QVector<long>& input, QVector<int>& out)
{
  for (int i = 1; i < 10; i++) {
    int c = std::count_if(
      input.cbegin(), input.cend(), [=](long n) { return firstDigit(n) == i; });
    qDebug() << i << " --- " << c;
    out[i] = c;
  }
}
