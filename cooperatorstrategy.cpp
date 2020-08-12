#include "cooperatorstrategy.h"


CooperatorStrategy::CooperatorStrategy(GameAgent *a) : AgentStrategy{a} {}

StrategyAction *CooperatorStrategy::nextAction(AbstractGame *game) {
    return new StrategyAction{Cooperate, this};
}
