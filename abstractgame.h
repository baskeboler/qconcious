#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#include <QMap>
#include <QObject>
#include <QVector>

#include "gameagent.h"

/**
 * @brief The Round struct
 */
struct Round {
  int round;
  GameAction action1;
  GameAction action2;
  Round(const int r, const GameAction a1, const GameAction a2);
  Round();
};

/**
 * @brief The RoundResult struct
 */
struct RoundResult {
  int round;
  int score1;
  int score2;
  RoundResult(const int r, const int s1, const int s2);
};

/**
 * @brief The AbstractGame class
 */
class AbstractGame : public QObject {
  Q_OBJECT
 public:
  Q_PROPERTY(int m_rounds READ getRounds WRITE setRounds);
  Q_PROPERTY(int m_currentRound READ getCurrentRound WRITE setCurrentRound);
  Q_PROPERTY(GameAgent *m_agent1 READ getAgent1 WRITE setAgent1);
  Q_PROPERTY(GameAgent *m_agent2 READ getAgent2 WRITE setAgent2);
  AbstractGame(GameAgent *a, GameAgent *b, int rounds,
               QObject *parent = nullptr);

  void playRound();
  void playGame();

  bool isGameOver();

  virtual int getScore(GameAgent &agent) = 0;
  virtual const RoundResult *scoreRound(const Round &round) = 0;

  virtual ~AbstractGame() {}

  int getRounds() const;
  void setRounds(int rounds);

  GameAgent *getAgent1() const;
  void setAgent1(GameAgent *agent1);

  GameAgent *getAgent2() const;
  void setAgent2(GameAgent *agent2);

  QVector<GameAction> agentActions(GameAgent *a);
  QVector<GameAction> opponentActions(GameAgent *a);
  int getCurrentRound() const;
  void setCurrentRound(int currentRound);

 signals:
  void roundPlayed(const RoundResult &result);

 protected:
  int m_rounds;
  int m_currentRound;
  GameAgent *m_agent1;
  GameAgent *m_agent2;
  QMap<int, int> scores;
  QVector<Round> history;
};

#endif  // ABSTRACTGAME_H
