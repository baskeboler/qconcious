#ifndef AGENTSTRATEGY_H
#define AGENTSTRATEGY_H
#include <QObject>

#include "gameagent.h"

class AgentStrategy;

struct StrategyAction {
  GameAction nextAction;
  AgentStrategy* nextStrategy;
  StrategyAction(GameAction a, AgentStrategy* s);
};

class AgentStrategy : public QObject {
  Q_OBJECT
 public:
  AgentStrategy(GameAgent* a, QObject* parent = nullptr);

  virtual StrategyAction* nextAction(AbstractGame* game) = 0;
  virtual ~AgentStrategy();

  GameAgent* agent() const;
  void setAgent(GameAgent* agent);

 private:
  GameAgent* m_agent;
};

#endif  // AGENTSTRATEGY_H
