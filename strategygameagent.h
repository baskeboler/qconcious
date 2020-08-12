#ifndef STRATEGYGAMEAGENT_H
#define STRATEGYGAMEAGENT_H

#include "agentstrategy.h"
#include "gameagent.h"

class StrategyGameAgent : public GameAgent {
public:
  StrategyGameAgent()
      : GameAgent{}, strategy{new RandomStrategy{this}}

  {}

  // GameAgent interface
public:
  virtual GameAction nextAction(AbstractGame *game) override {
    auto sa =  strategy->nextAction(game);
    strategy = sa->nextStrategy;
    return sa->nextAction;
  }

private:
  AgentStrategy *strategy;
};

#endif // STRATEGYGAMEAGENT_H
