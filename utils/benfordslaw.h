#ifndef BENFORDSLAW_H
#define BENFORDSLAW_H

#include <QtCore/qglobal.h>

#include <QVector>
class BenfordsLaw {
 public:
  BenfordsLaw();

  /**
   * @brief firstDigit
   * @param n
   * @return
   */
  static int firstDigit(long n);

  /**
   * @brief firstDigit
   * @param n
   * @return
   */
  static int firstDigit(double n);

  /**
   * @brief compute
   * @param input
   * @param out
   */
  static void compute(QVector<long>& input, QVector<int>& out);
};

#endif  // BENFORDSLAW_H
