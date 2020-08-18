#include "gameagent.h"

int GameAgent::s_nextId = 0;

GameAgent::GameAgent() { m_id = s_nextId++; }

int GameAgent::id() const { return m_id; }
