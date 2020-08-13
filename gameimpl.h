#ifndef GAMEIMPL_H
#define GAMEIMPL_H

#include "abstractgame.h"

class GameImpl : public AbstractGame {
 public:
  GameImpl(GameAgent *a, GameAgent *b, int rounds)
      : AbstractGame{a, b, rounds} {}

  virtual ~GameImpl() {}
  // AbstractGame interface
 public:
  virtual int getScore(GameAgent &agent) override;
  virtual const RoundResult *scoreRound(const Round &round) override;
};

#endif  // GAMEIMPL_H
