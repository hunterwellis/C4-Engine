#include "qtengine.hpp"

// TODO DELETE DEBUGGING FUNCTION
inline void debug(QVector<bool> *state){
    // debug
    qDebug() << "==================================";

    // to 2D vector
    char board[49] = {'.'};
    for (int col = 0; col < 7; ++col){
        for (int row = 0; row < state[col].size(); ++row){
            board[(col * 7) + row] = state[col][row] ? 'x' : 'o';
        }
    }

    // print board
    for (int row = 6; row >= 0; --row){
        QString line = "";
        for (int col = 0; col < 7; ++col){
            int idx = ((col * 7) + row);
            line += QString::number(idx);
            line += " ";
            // std::cout << board[(col * 7) + row];
        }
        qDebug() << line;
    }





    for (int col = 0; col < 7; ++col){
        QString piece = "";
        for (int row = 0; row < state[col].size(); ++row){
            int idx = ((5 - row) * 7) + col;
            piece += QString::number(idx);
            piece.push_back(state[col][row] ? "X" : "O");
            piece += " ";
        }
        qDebug() << col << ": " << piece;
    }


}

QtEngine::QtEngine(QWidget *parent) : QWidget(parent) {
}


uint64_t QtEngine::toBitmap(QVector<bool> *state){
    return 0;
}

/* Main engine call - Qt slot.
 *
 * This slot is evoked by the qt ui to find the next engine move.
 * The engine move is given by the signal solution(int move) 
 * with an int 0-6 representing the column number.
 *
*/
void QtEngine::solve(QVector<bool> *currState){
    debug(currState);
    uint64_t bitmap = toBitmap(currState);
    emit solution(engine.solve(bitmap));
}
