#include "./benfordtest.h"

BenfordTest::BenfordTest(QObject *parent) : QObject(parent) {}

bool BenfordTest::myCondition() { return true; }

int BenfordTest::fib(int n) {
  if (n < 0) return 0;
  if (n <= 1) return 1;
  return fib(n - 1) + fib(n - 2);
}

QVector<qint64> BenfordTest::fibSequence(int c) {
  QVector<qint64> res(c);
  for (int i = 0; i < c; i++) res[i] = fib(i);
  return res;
}

void BenfordTest::initTestCase() { qDebug("Called before everything else."); }

void BenfordTest::myFirstTest() {
  QVERIFY(true);   // check that a condition is satisfied
  QCOMPARE(1, 1);  // compare two values
}

void BenfordTest::mySecondTest() {
  QVERIFY(myCondition());
  QVERIFY(1 != 2);
}

void BenfordTest::cleanupTestCase() {
  qDebug("Called after myFirstTest and mySecondTest.");
}

void BenfordTest::benfords1() {
  int f = BenfordsLaw::firstDigit(3141L);
  QCOMPARE(f, 3);
}

#ifdef BOOST_ENABLED
void BenfordTest::fibtest() {
  QVector<qint64> fibs = fibSequence(20);
  QCOMPARE(fibs.size(), 20);
  QCOMPARE(fibs[10], fib(10));
}

void BenfordTest::mandeltest() { mandel(5000); }
#endif

QTEST_MAIN(BenfordTest)
//#include "benfordtest.moc"
