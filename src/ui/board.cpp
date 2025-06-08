#include "board.hpp"
#include <cctype>
#include <QPainter>
#include <QResizeEvent>
#include <cwchar>
#include <QPixmap>
#include <QDebug>
#include <qcolor.h>
#include <qpoint.h>

Board::Board(QWidget *parent) : QWidget(parent) {
    engine = new QtEngine;

    QObject::connect(this, &Board::engineCall, engine, &QtEngine::solve);
    QObject::connect(engine, &QtEngine::solution, this, &Board::updateState);

    setMinimumSize(BOARD_HEIGHT, BOARD_WIDTH);
}

void Board::paintEvent(QPaintEvent *event){

    QPainter painter(this);

    painter.setPen(Qt::NoPen);

    int squareWidth = width() / 7;
    int squareHeight = height() / 6;

    // draw board
    painter.fillRect(rect(), Qt::darkGray);  // background
    painter.setBrush(Qt::lightGray); // empty holes
    int offset = squareWidth / 8;
    for (int i = 0; i < 42; ++i){
        painter.drawEllipse((i % 7) * squareWidth + offset, (i / 7) * squareHeight + offset, 0.75 * squareWidth, 0.75 * squareHeight);
    }

    // draw game state
    for (int col = 0; col < 7; ++col){
        for (int row = 0; row < state[col].size(); ++row){
            int idx = ((5 - row) * 7) + col;
            painter.setBrush(state[col][row] ? Qt::red : Qt::yellow);
            painter.drawEllipse((idx % 7) * squareWidth + offset, (idx / 7) * squareHeight + offset, 0.75 * squareWidth, 0.75 * squareHeight);
        }
    }

    // // debug
    // qDebug() << "=================";
    // for (int col = 0; col < 7; ++col){
    //     QString piece = "";
    //     for (int row = 0; row < state[col].size(); ++row){
    //         int idx = ((5 - row) * 7) + col;
    //         piece += QString::number(idx);
    //         piece.push_back(state[col][row] ? "X" : "O");
    //         piece += " ";
    //     }
    //     qDebug() << col << ": " << piece;
    // }
    //
}

void Board::placeChecker(int x){
    state[x / static_cast<int>(width() / 7)].push_back(turn);
    turn = !turn;
    // qInfo() << x / static_cast<int>(width() / 7);
    update();
}

// Qt Event Handling
void Board::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){

    }

    QWidget::mousePressEvent(event);
}

void Board::mouseReleaseEvent(QMouseEvent* event){
    placeChecker(event->pos().x());
    QWidget::mouseReleaseEvent(event);

    emit engineCall(state);
}

// Qt slots
void Board::updateState(int col){
    // state[col].push_back(turn);
    // turn = !turn;
    update();
}
