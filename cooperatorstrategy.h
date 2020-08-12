#ifndef COOPERATORSTRATEGY_H
#define COOPERATORSTRATEGY_H

#include "agentstrategy.h"



class CooperatorStrategy : public AgentStrategy {

  // AgentStrategy interface
public:
  CooperatorStrategy(GameAgent *a);
  virtual StrategyAction *nextAction(AbstractGame *game) override;
};
#endif // COOPERATORSTRATEGY_H
