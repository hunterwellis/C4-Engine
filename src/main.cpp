#include <QApplication>
#include <QTimer>
#include "board.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Board game;

    game.resize(BOARD_HEIGHT, BOARD_WIDTH);
    game.setFixedSize(game.size());

    game.show();

    return app.exec();
}
