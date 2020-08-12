#ifndef RANDOMSTRATEGY_H
#define RANDOMSTRATEGY_H

#include <QRandomGenerator>
#include "agentstrategy.h"


class RandomStrategy : public AgentStrategy {

  // AgentStrategy interface
public:
  RandomStrategy(GameAgent *a);
  virtual StrategyAction *nextAction(AbstractGame *game) override;
};

#endif // RANDOMSTRATEGY_H
