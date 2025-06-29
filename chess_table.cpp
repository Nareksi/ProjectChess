#include "chess_table.h"
const QColor chess_table::BROWN(139, 69, 19);
const QColor chess_table::WHITE(Qt::white);

chess_table::chess_table() {
    //mainTable = new QGraphicsRectItem();
    letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    numbers = {'1', '2', '3', '4', '5', '6', '7', '8'};
    scene = new QGraphicsScene();
    cellSize= 100;
    SetRectSize();
    CreateTable();
    AddInView();
    size = 8;
}

void chess_table::CreateTable(){

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            QGraphicsRectItem* pieceTable = new QGraphicsRectItem();

            pieceTable->setRect(j*cellSize,i*cellSize, cellSize, cellSize);
            if((i+j)%2 == 1){
                pieceTable->setBrush(BROWN);
            }
            else{
                pieceTable->setBrush(WHITE);
            }
            rect[i][j].setX(pieceTable->x());
            rect[i][j].setY(pieceTable->y());
            scene->addItem(pieceTable);

        }
    }
    AddLettersAndNumbers();
}
void chess_table::AddLettersAndNumbers() {
    QFont font("Arial", 16, QFont::Bold);

    // Добавляем буквы (A-H) внизу и вверху
    for (int i = 0; i < 8; ++i) {
        // Буквы внизу (под доской)
        QGraphicsTextItem* letterBottom = new QGraphicsTextItem(QString(letters[i]));
        letterBottom->setFont(font);
        letterBottom->setPos(i * cellSize + cellSize / 2 - 10, 8 * cellSize + 5);
        scene->addItem(letterBottom);

        // Буквы вверху (над доской)
        QGraphicsTextItem* letterTop = new QGraphicsTextItem(QString(letters[i]));
        letterTop->setFont(font);
        letterTop->setPos(i * cellSize + cellSize / 2 - 10, -30);
        scene->addItem(letterTop);
    }

    // Добавляем цифры (1-8) слева и справа
    for (int i = 0; i < 8; ++i) {
        // Цифры слева (рядом с доской)
        QGraphicsTextItem* numberLeft = new QGraphicsTextItem(QString(numbers[7 - i])); // 7-i чтобы шло от 8 сверху
        numberLeft->setFont(font);
        numberLeft->setPos(-30, i * cellSize + cellSize / 2 - 10);
        scene->addItem(numberLeft);

        // Цифры справа (рядом с доской)
        QGraphicsTextItem* numberRight = new QGraphicsTextItem(QString(numbers[7 - i]));
        numberRight->setFont(font);
        numberRight->setPos(8 * cellSize + 5, i * cellSize + cellSize / 2 - 10);
        scene->addItem(numberRight);
    }
}

void chess_table::AddInView(){
    view = new QGraphicsView(scene);
    view->show();
}

void chess_table::SetRectSize(){
    rect.resize(8);
    for (int i = 0; i < 8; ++i) {
        rect[i].resize(8);
    }
}



