#include <QApplication>

#include "cheater.h"
#include "cooperator.h"
#include "gameagent.h"
#include "gameimpl.h"
#include "mainwindow.h"
#include "randomagent.h"
#include "strategies.h"
#include "strategygameagent.h"
#include "titsfortatsagent.h"
//#include <cstddef>
#include <algorithm>
#include <iostream>
#include <locale>
#include <string>

#include "utils.h"

// using namespace std;
using namespace std::literals;

typedef ForgivingStrategy<5> MyCustomStrategy;

int main(int argc, char* argv[]) {
  //  pruebas();

  int samplesize = 6000000;
  QRandomGenerator* rand = QRandomGenerator::system();

  QVector<long> nums(samplesize);
  QVector<int> out(10);
  QVector<double> out2(10);
  rand->generate(nums.begin(), nums.end());
  BenfordsLaw::compute(nums, out);
  std::transform(out.begin(), out.end(), out2.begin(),
                 [=](long n) { return (double)n / samplesize; });
  qInfo() << "benfordness: " << out;
  qInfo() << "aggregate sum: " << std::accumulate(out.begin(), out.end(), 0);
  qInfo() << "benfordness %: " << out2;
  auto* a1 = StrategyGameAgent::buildAgent<MyCustomStrategy>();
  auto a2 = StrategyGameAgent::buildAgent<RandomStrategy>();
  // new StrategyGameAgent;
  //    a2->setStrategy(new RandomStrategy{a2});
  AbstractGame* g = new GameImpl(a1, a2, 10);

  g->playGame();

  std::cout << "agent 1: " << g->getScore(*a1) << std::endl
            << "agent 2: " << g->getScore(*a2) << std::endl;
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
