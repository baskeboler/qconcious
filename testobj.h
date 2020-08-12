#ifndef TESTOBJ_H
#define TESTOBJ_H

#include <QObject>

class testobj : public QObject
{
    Q_OBJECT
public:
    explicit testobj(QObject *parent = nullptr);

signals:

};

#endif // TESTOBJ_H
