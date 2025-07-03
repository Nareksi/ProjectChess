#include "chess_table.h"
const QColor chess_table::BROWN(139, 69, 19);
const QColor chess_table::WHITE(Qt::white);

chess_table::chess_table() {
    //mainTable = new QGraphicsRectItem();

    letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    numbers = {'1', '2', '3', '4', '5', '6', '7', '8'};

    scene = new QGraphicsScene();

    allFig = figures.setImages();
    blackPawn = allFig[0];
    whitePawn = allFig[1];
    blackRook = allFig[2];
    whiteRook = allFig[3];
    blackHorse = allFig[4];
    whiteHorse = allFig[5];
    blackElephant = allFig[6];
    whiteElephant = allFig[7];
    blackQueen = allFig[8];
    whiteQueen = allFig[9];
    blackKing = allFig[10];
    whiteKing = allFig[11];

    cellSize= 100;
    SetRectSize();
    CreateTable();
    AddFigure();
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

void chess_table::AddFigure(){



    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            QGraphicsPixmapItem *pawn;
            if ((i == 0 && j == 0)|| (i == 0 && j == 7)){
                pawn = new QGraphicsPixmapItem(blackRook->pixmap());
            }
            else if ((i == 0 && j == 1)|| (i == 0 && j == 6)){
                pawn = new QGraphicsPixmapItem(blackHorse->pixmap());
            }
            else if ((i == 0 && j == 2)|| (i == 0 && j == 5)){
                pawn = new QGraphicsPixmapItem(blackElephant->pixmap());
            }
            else if (i == 0 && j == 3){
                pawn = new QGraphicsPixmapItem(blackQueen->pixmap());
            }
            else if (i == 0 && j == 4){
                pawn = new QGraphicsPixmapItem(blackKing->pixmap());
            }
            else if (i == 1){
                pawn = new QGraphicsPixmapItem(blackPawn->pixmap());
            }

            else if ((i == 7 && j == 0)|| (i == 7 && j == 7)){
                pawn = new QGraphicsPixmapItem(whiteRook->pixmap());
            }
            else if ((i == 7 && j == 1)|| (i == 7 && j == 6)){
                pawn = new QGraphicsPixmapItem(whiteHorse->pixmap());
            }
            else if ((i == 7 && j == 2)|| (i == 7 && j == 5)){
                pawn = new QGraphicsPixmapItem(whiteElephant->pixmap());
            }
            else if (i == 7 && j == 3){
                pawn = new QGraphicsPixmapItem(whiteQueen->pixmap());
            }
            else if (i == 7 && j == 4){
                pawn = new QGraphicsPixmapItem(whiteKing->pixmap());
            }
            else if (i == 6){
                pawn = new QGraphicsPixmapItem(whitePawn->pixmap());
            }
            else{
                continue;
            }

            pawn->setPos(j * cellSize + (cellSize - pawn->boundingRect().width()) / 2,
                         i * cellSize + (cellSize - pawn->boundingRect().height()) / 2);


            scene->addItem(pawn);
        }
    }

}



