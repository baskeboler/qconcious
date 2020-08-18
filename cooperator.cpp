#include "cooperator.h"

Cooperator::Cooperator() : GameAgent{} {}

Cooperator::~Cooperator() {}

GameAction Cooperator::nextAction(AbstractGame *game) {
  return GameAction::Cooperate;
}
