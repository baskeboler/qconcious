#ifndef BENFORDTEST_H
#define BENFORDTEST_H

#include <QtCore/qglobal.h>

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "utils/benfordslaw.h"

class BenfordTest : public QObject {
  Q_OBJECT
 public:
  explicit BenfordTest(QObject *parent = nullptr);

 private:
  bool myCondition();

  int fib(int n);

  QVector<qint64> fibSequence(int c);

 private slots:
  void initTestCase();

  void myFirstTest();

  void mySecondTest();

  void cleanupTestCase();

  void benfords1();

  void fibtest();
};

#endif  // BENFORDTEST_H
