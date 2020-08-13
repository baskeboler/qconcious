#include "agentstrategy.h"



GameAgent *AgentStrategy::agent() const
{
    return m_agent;
}

void AgentStrategy::setAgent(GameAgent *agent)
{
    m_agent = agent;
}
