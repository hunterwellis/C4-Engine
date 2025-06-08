#ifndef CONNECT4_UI_BOARD_HPP_
#define CONNECT4_UI_BOARD_HPP_

#include <QWidget>
#include <QGraphicsScene>
#include <QVector>

#include "engine/qtengine.hpp"

#define BOARD_HEIGHT 512
#define BOARD_WIDTH 440

class Board : public QWidget {
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

public slots:
    // void engineMove(int col);
    void updateState(int move);
    
signals:
    void engineCall(QVector<bool> *currState);

private:
    QtEngine *engine;

    bool turn = true;

    void placeChecker(int x);

    QVector<bool> state[7];
};

#endif

