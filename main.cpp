#include "cheater.h"
#include "cooperator.h"
#include "gameagent.h"
#include "gameimpl.h"
#include "mainwindow.h"
#include "randomagent.h"
#include "strategygameagent.h"
#include "titsfortatsagent.h"
#include "strategies.h"

#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    GameAgent *a1 = new TitsForTatsAgent;
    auto a2 = new StrategyGameAgent;
    a2->setStrategy(new RandomStrategy{a2});
    AbstractGame *g = new GameImpl(a1, a2, 10);

    g->playGame();

    cout << "agent 1: " << g->getScore(*a1) << endl
         << "agent 2: " << g->getScore(*a2) << endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
