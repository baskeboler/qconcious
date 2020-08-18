#include "gameimpl.h"

int GameImpl::getScore(GameAgent &agent) { return scores[agent.id()]; }

const RoundResult *GameImpl::scoreRound(const Round &round) {
  int score1 = 0;
  int score2 = 0;
  if (round.action1 == round.action2) {
    switch (round.action1) {
      case Cheat:

        break;

      case Cooperate:
        score1 = 2;
        score2 = 2;
        break;

      default:
        break;
    }
  } else {
    switch (round.action1) {
      case Cheat:
        score1 = 3;
        score2 = -1;
        break;
      default:
        score1 = -1;
        score2 = 3;
    }
  }
  scores[getAgent1()->id()] += score1;
  scores[getAgent2()->id()] += score2;
  auto result = new RoundResult{round.round, score1, score2};
  emit roundPlayed(*result);
  return result;
}
