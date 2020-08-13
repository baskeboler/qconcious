#include "cheater.h"
#include "cooperator.h"
#include "gameagent.h"
#include "gameimpl.h"
#include "mainwindow.h"
#include "randomagent.h"
#include "strategies.h"
#include "strategygameagent.h"
#include "titsfortatsagent.h"
#include <QApplication>
//#include <cstddef>
#include <iostream>
#include <locale>
#include <string>
// using namespace std;
using namespace std::literals;

int
main(int argc, char* argv[])
{
  //  pruebas();
  auto* a1 = StrategyGameAgent::buildAgent<ForgivingStrategy<3>>();
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
