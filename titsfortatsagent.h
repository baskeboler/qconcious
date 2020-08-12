#ifndef TITSFORTATSAGENT_H
#define TITSFORTATSAGENT_H

#include "gameagent.h"
class TitsForTatsAgent: public GameAgent
{
public:
    TitsForTatsAgent();
    virtual ~TitsForTatsAgent();
    // GameAgent interface
public:
    virtual GameAction nextAction(AbstractGame *game) override;
};

#endif // TITSFORTATSAGENT_H
