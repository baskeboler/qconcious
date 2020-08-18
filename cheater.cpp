#include "cheater.h"

Cheater::Cheater() : GameAgent{} {}

GameAction Cheater::nextAction(AbstractGame *game) { return GameAction::Cheat; }

Cheater::~Cheater() {}
