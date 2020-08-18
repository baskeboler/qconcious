#include "randomagent.h"

#include <QRandomGenerator>

RandomAgent::RandomAgent() {}

RandomAgent::~RandomAgent() {}

GameAction RandomAgent::nextAction(AbstractGame *game) {
  double randVal = QRandomGenerator::system()->generateDouble();
  if (randVal >= 0.5) {
    return Cooperate;
  }
  return Cheat;
}
