#ifndef COOPERATOR_H
#define COOPERATOR_H

#include "gameagent.h"

class Cooperator : public GameAgent {
 public:
  Cooperator();
  virtual ~Cooperator();
  virtual GameAction nextAction(AbstractGame *game) override;
};

#endif  // COOPERATOR_H
