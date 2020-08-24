#ifndef BENFORDTEST_H
#define BENFORDTEST_H

#include <QtCore/qglobal.h>

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "utils.h"

#if BOOST_VERSION > 106700
#define BOOST_ENABLED true
#endif

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

#ifdef BOOST_ENABLED
  void fibtest();

  void mandeltest();
#endif
};

#endif  // BENFORDTEST_H
