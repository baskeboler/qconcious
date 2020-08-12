#ifndef STRATEGYGAMEAGENT_H
#define STRATEGYGAMEAGENT_H

#include "strategies.h"
#include "gameagent.h"

class StrategyGameAgent : public GameAgent {
public:
    StrategyGameAgent( AgentStrategy* s = nullptr);

    // GameAgent interface
public:
    virtual GameAction nextAction(AbstractGame *game) override;

    AgentStrategy *getStrategy() const;
    void setStrategy(AgentStrategy *value);

private:
    AgentStrategy *strategy;
};

#endif // STRATEGYGAMEAGENT_H
