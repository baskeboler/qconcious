#ifndef AGENTSTRATEGY_H
#define AGENTSTRATEGY_H

#include "gameagent.h"


class AgentStrategy;

struct StrategyAction {
  GameAction nextAction;
  AgentStrategy *nextStrategy;
  StrategyAction(GameAction a, AgentStrategy *s)
      : nextAction{a}, nextStrategy{s} {}
};

class AgentStrategy {
public:
  AgentStrategy(GameAgent *a) : m_agent{a} {}

  virtual StrategyAction *nextAction(AbstractGame *game) = 0;
  virtual ~AgentStrategy() {}

private:
  GameAgent *m_agent;
};




#endif // AGENTSTRATEGY_H
