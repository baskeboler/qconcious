#include "titsfortatsagent.h"

TitsForTatsAgent::TitsForTatsAgent() {}

TitsForTatsAgent::~TitsForTatsAgent() {}

GameAction TitsForTatsAgent::nextAction(AbstractGame *game) {
  auto actions = game->opponentActions(this);
  if (actions.size() > 0) {
    return actions.last();
  }
  return Cooperate;
}
