#include "agentstrategy.h"

AgentStrategy::AgentStrategy(GameAgent *a, QObject *parent)
    : QObject{parent}, m_agent{a} {}

AgentStrategy::~AgentStrategy() {}

GameAgent *AgentStrategy::agent() const { return m_agent; }

void AgentStrategy::setAgent(GameAgent *agent) { m_agent = agent; }

StrategyAction::StrategyAction(GameAction a, AgentStrategy *s)
    : nextAction{a}, nextStrategy{s} {}
