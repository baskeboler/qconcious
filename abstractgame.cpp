#include "abstractgame.h"

AbstractGame::AbstractGame(GameAgent *a, GameAgent *b, int rounds, QObject *parent)
    : QObject{parent}, m_rounds{rounds}, m_currentRound{0}, m_agent1{a}, m_agent2{b} {
  scores[m_agent1->id()] = 0;
  scores[m_agent2->id()] = 0;
}

void AbstractGame::playRound() {

  auto action1 = getAgent1()->nextAction(this);
  auto action2 = getAgent2()->nextAction(this);

  Round r{m_currentRound++, action1, action2};
  scoreRound(r);
  history.push_back(r);
}

void AbstractGame::playGame() {
  while (!isGameOver())
    playRound();
}

bool AbstractGame::isGameOver() { return m_currentRound == m_rounds; }

int AbstractGame::getRounds() const { return m_rounds; }

void AbstractGame::setRounds(int rounds) { m_rounds = rounds; }

GameAgent *AbstractGame::getAgent1() const { return m_agent1; }

void AbstractGame::setAgent1(GameAgent *agent1) { m_agent1 = agent1; }

GameAgent *AbstractGame::getAgent2() const { return m_agent2; }

void AbstractGame::setAgent2(GameAgent *agent2) { m_agent2 = agent2; }

QVector<GameAction> AbstractGame::agentActions(GameAgent *a) {

  QVector<GameAction> res;
  for (auto round : history) {
    if (a->id() == getAgent1()->id()) {
      res.push_back(round.action1);
    } else {
      res.push_back(round.action2);
    }
  }
  return res;
}

QVector<GameAction> AbstractGame::opponentActions(GameAgent *a) {
  if (a->id() == getAgent1()->id()) {
    return agentActions(getAgent2());
  } else {
    return agentActions(getAgent1());
  }
}
