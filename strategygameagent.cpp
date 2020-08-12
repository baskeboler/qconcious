#include "strategygameagent.h"



AgentStrategy *StrategyGameAgent::getStrategy() const
{
    return strategy;
}

void StrategyGameAgent::setStrategy(AgentStrategy *value)
{
    strategy = value;
}

