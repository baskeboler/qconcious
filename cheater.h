#ifndef CHEATER_H
#define CHEATER_H

#include "gameagent.h"



class Cheater: public GameAgent
{
public:
    Cheater();
    virtual GameAction nextAction(AbstractGame *game) override;
    virtual ~Cheater();
};

#endif // CHEATER_H
