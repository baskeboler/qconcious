#ifndef AGENTSTRATEGY_H
#define AGENTSTRATEGY_H

#include "gameagent.h"

#include <QRandomGenerator>

class AgentStrategy;

struct StrategyAction {
        GameAction nextAction;
        AgentStrategy *nextStrategy;
        StrategyAction(GameAction a, AgentStrategy *s): nextAction{a}, nextStrategy{s} {}
};

class AgentStrategy
{
public:
    AgentStrategy(GameAgent* a): m_agent{a}{}

    virtual StrategyAction *nextAction(AbstractGame *game)=0;
    virtual ~AgentStrategy(){}
private:
    GameAgent *m_agent;
};

class CheaterStrategy: public AgentStrategy {

    // AgentStrategy interface
public:
    CheaterStrategy(GameAgent* a): AgentStrategy{a}{}
    virtual StrategyAction * nextAction(AbstractGame *game) override {
        return new StrategyAction{Cheat, this};
    }
};

class CooperatorStrategy: public AgentStrategy {


    // AgentStrategy interface
public:
    CooperatorStrategy(GameAgent* a): AgentStrategy{a}{}
    virtual StrategyAction * nextAction(AbstractGame *game) override {
        return new StrategyAction{Cooperate, this};
    }
};

class RandomStrategy: public AgentStrategy {


    // AgentStrategy interface
public:
    RandomStrategy(GameAgent* a): AgentStrategy{a}{}
    virtual StrategyAction *nextAction(AbstractGame *game) override {
        double n = QRandomGenerator::system()->generateDouble();
        if  (n >= 0.5) {
            return new StrategyAction{Cooperate, this};
        } else {
            return new StrategyAction{Cheat, this};
        }
    }
};

#endif // AGENTSTRATEGY_H
