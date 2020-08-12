#include "strategygameagent.h"



StrategyGameAgent::StrategyGameAgent(AgentStrategy *s)
    : GameAgent{}

{
    if (s != nullptr) {
        strategy=s;
    } else {
        strategy = new RandomStrategy{this};
    }
}

GameAction StrategyGameAgent::nextAction(AbstractGame *game) {
    auto sa =  strategy->nextAction(game);
    strategy = sa->nextStrategy;
    return sa->nextAction;
}

AgentStrategy *StrategyGameAgent::getStrategy() const
{
    return strategy;
}

void StrategyGameAgent::setStrategy(AgentStrategy *value)
{
    strategy = value;
}

