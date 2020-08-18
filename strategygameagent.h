#ifndef STRATEGYGAMEAGENT_H
#define STRATEGYGAMEAGENT_H

#include "gameagent.h"
#include "strategies.h"

class StrategyGameAgent : public GameAgent {
 public:
  StrategyGameAgent(AgentStrategy* s = nullptr);

 public:
  virtual GameAction nextAction(AbstractGame* game) override;

  AgentStrategy* getStrategy() const;
  void setStrategy(AgentStrategy* value);

  template <typename T>
  static StrategyGameAgent* buildAgent() {
    auto agent = new StrategyGameAgent;
    agent->setStrategy(new T{agent});
    return agent;
  }

 private:
  AgentStrategy* strategy;
};

#endif  // STRATEGYGAMEAGENT_H
