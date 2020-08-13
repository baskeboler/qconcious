#ifndef GAMEAGENT_H
#define GAMEAGENT_H

enum GameAction { Cooperate, Cheat };

class AbstractGame;

class GameAgent {
 public:
  GameAgent();

  virtual GameAction nextAction(AbstractGame *game) = 0;

  int id() const;

  virtual ~GameAgent() {}

 private:
  int m_id;
  static int s_nextId;
};

#include "abstractgame.h"
#endif  // GAMEAGENT_H
