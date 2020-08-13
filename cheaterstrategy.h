#ifndef CHEATERSTRATEGY_H
#define CHEATERSTRATEGY_H

#include "agentstrategy.h"

class CheaterStrategy : public AgentStrategy {
  // AgentStrategy interface
 public:
  CheaterStrategy(GameAgent *a);
  virtual StrategyAction *nextAction(AbstractGame *game) override;
};

#endif  // CHEATERSTRATEGY_H
