#ifndef RANDOMAGENT_H
#define RANDOMAGENT_H

#include "gameagent.h"
class RandomAgent : public GameAgent {
 public:
  RandomAgent();
  virtual ~RandomAgent();
  // GameAgent interface
 public:
  virtual GameAction nextAction(AbstractGame *game) override;
};

#endif  // RANDOMAGENT_H
