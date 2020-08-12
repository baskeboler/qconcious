#include "cheaterstrategy.h"


CheaterStrategy::CheaterStrategy(GameAgent *a) : AgentStrategy{a} {}

StrategyAction *CheaterStrategy::nextAction(AbstractGame *game) {
    return new StrategyAction{Cheat, this};
}
