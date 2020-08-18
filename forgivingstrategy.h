#ifndef FORGIVINGSTRATEGY_H
#define FORGIVINGSTRATEGY_H

#include <QVector>

#include "agentstrategy.h"
#include "gameagent.h"
#include "strategies.h"

template <int N = 3>
class ForgivingStrategy : public AgentStrategy {
  // AgentStrategy interface
 public:
  ForgivingStrategy(GameAgent* a) : AgentStrategy{a}, m_forgiveness{N} {}
  virtual StrategyAction* nextAction(AbstractGame* game) override {
    QVector<GameAction> actions = game->opponentActions(this->agent());
    if (actions.length() == 0) return new StrategyAction{Cheat, this};
    if (forgiveness() == 0)
      return new StrategyAction{Cheat, new CheaterStrategy{agent()}};
    switch (actions.last()) {
      case Cheat:
        m_forgiveness--;
      default:
        return new StrategyAction{Cooperate, this};
    }
  }

  int forgiveness() const { return m_forgiveness; }
  void setForgiveness(int forgiveness) { m_forgiveness = forgiveness; }
  virtual ~ForgivingStrategy() {}

 private:
  int m_forgiveness;
};

#endif  // FORGIVINGSTRATEGY_H
