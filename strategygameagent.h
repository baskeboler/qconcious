#ifndef STRATEGYGAMEAGENT_H
#define STRATEGYGAMEAGENT_H

#include "agentstrategy.h"
#include "gameagent.h"

class StrategyGameAgent : public GameAgent {
public:
    StrategyGameAgent( AgentStrategy* s = nullptr)
        : GameAgent{}

    {
        if (s != nullptr) {
            strategy=s;
        } else {
            strategy = new RandomStrategy{this};
        }
    }

    // GameAgent interface
public:
    virtual GameAction nextAction(AbstractGame *game) override {
        auto sa =  strategy->nextAction(game);
        strategy = sa->nextStrategy;
        return sa->nextAction;
    }

    AgentStrategy *getStrategy() const;
    void setStrategy(AgentStrategy *value);

private:
    AgentStrategy *strategy;
};

#endif // STRATEGYGAMEAGENT_H
