#ifndef QT_ENGINE_HPP_
#define QT_ENGINE_HPP_

#include <stdint.h>
#include <iostream>
#include <QWidget>
#include <QGraphicsScene>
#include <QVector>

#include "solver.hpp"

class QtEngine: public QWidget {
    Q_OBJECT

public:
    QtEngine(QWidget *parent = nullptr);

signals:
    void solution(int col);

public slots:
    void solve(QVector<bool> *currState);

private:
    uint64_t toBitmap(QVector<bool> *state);
    ConnectEngine engine;

};

#endif
