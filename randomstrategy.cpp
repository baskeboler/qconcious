#include "randomstrategy.h"


RandomStrategy::RandomStrategy(GameAgent *a) : AgentStrategy{a} {}

StrategyAction *RandomStrategy::nextAction(AbstractGame *game) {
    double n = QRandomGenerator::system()->generateDouble();
    if (n >= 0.5) {
        return new StrategyAction{Cooperate, this};
    } else {
        return new StrategyAction{Cheat, this};
    }
}
