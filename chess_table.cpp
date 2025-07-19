#include "chess_table.h"
const QColor chess_table::BROWN(139, 69, 19);
const QColor chess_table::WHITE(Qt::white);
const QColor chess_table::BLACK(Qt::black);

chess_table::chess_table() {
    //mainTable = new QGraphicsRectItem();

    letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    numbers = {'1', '2', '3', '4', '5', '6', '7', '8'};
    Info.resize(32);
    scene = new QGraphicsScene();
    scene->installEventFilter(this);
    lastCol = -1, lastRow = -1;
    selectionRect = new QGraphicsRectItem();

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
    toChess();
    AddInView();
    printChessCoordinates();
    scene->addItem(selectionRect);

    size = 8;

}

void chess_table::CreateTable(){

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            QGraphicsRectItem* pieceTable = new QGraphicsRectItem();

            pieceTable->setRect(j*cellSize,i*cellSize, cellSize, cellSize);
            if((i+j)%2 == 1){
                pieceTable->setBrush(BROWN);
                pieceTable->setPen(QPen(BLACK, 2));
            }
            else{
                pieceTable->setBrush(WHITE);
                pieceTable->setPen(QPen(BLACK, 2));
            }
            pieceTable->setZValue(0);
            rect[j].push_back(pieceTable);

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
}

void chess_table::AddFigure(){
    int figureIndex = 0;


    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            QGraphicsPixmapItem *figure;
            QPointF *coordinate;
            QString name;
            bool isBlack;
            if ((i == 0 && j == 0)|| (i == 0 && j == 7)){
                figure = new QGraphicsPixmapItem(blackRook->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "blackRook";
                isBlack = true;

            }
            else if ((i == 0 && j == 1)|| (i == 0 && j == 6)){
                figure = new QGraphicsPixmapItem(blackHorse->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "blackHorse";
                isBlack = true;

            }
            else if ((i == 0 && j == 2)|| (i == 0 && j == 5)){
                figure = new QGraphicsPixmapItem(blackElephant->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "blackElephant";
                isBlack = true;

            }
            else if (i == 0 && j == 3){
                figure = new QGraphicsPixmapItem(blackQueen->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "blackQueen";
                isBlack = true;

            }
            else if (i == 0 && j == 4){
                figure = new QGraphicsPixmapItem(blackKing->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "blackKing";
                isBlack = true;

            }
            else if (i == 1){
                figure = new QGraphicsPixmapItem(blackPawn->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "blackPawn";
            }

            else if ((i == 7 && j == 0)|| (i == 7 && j == 7)){
                figure = new QGraphicsPixmapItem(whiteRook->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "whiteRook";
                isBlack = true;

            }
            else if ((i == 7 && j == 1)|| (i == 7 && j == 6)){
                figure = new QGraphicsPixmapItem(whiteHorse->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "whiteHorse";
                isBlack = false;

            }
            else if ((i == 7 && j == 2)|| (i == 7 && j == 5)){
                figure = new QGraphicsPixmapItem(whiteElephant->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "whiteElephant";
                isBlack = false;


            }
            else if (i == 7 && j == 3){
                figure = new QGraphicsPixmapItem(whiteQueen->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "whiteQueen";
                isBlack = false;


            }
            else if (i == 7 && j == 4){
                figure = new QGraphicsPixmapItem(whiteKing->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "whiteKing";
                isBlack = false;


            }
            else if (i == 6){
                figure = new QGraphicsPixmapItem(whitePawn->pixmap());
                coordinate = new QPointF(j * cellSize, i * cellSize);
                name = "whitePawn";
                isBlack = false;

            }
            else{
                continue;
            }

            figure->setPos(j * cellSize + (cellSize - figure->boundingRect().width()) / 2,
                         i * cellSize + (cellSize - figure->boundingRect().height()) / 2);

            saveFiguresData(figure, coordinate, figureIndex, name, isBlack);

            scene->addItem(figure);
            figureIndex++;
        }
    }

}

QGraphicsScene chess_table::getScene(){
    return scene;
}



void chess_table::saveFiguresData(QGraphicsPixmapItem *figureType, QPointF *figureCoordinate, int &i, QString &figureName, bool &isBlack){
    Info[i].figureType = figureType;
    Info[i].figuresCoordinate = figureCoordinate;
    Info[i].figureName = figureName;
    Info[i].isBlack = isBlack;
}



void chess_table::toChess() {
    for (int i = 0; i < Info.size(); ++i) {
        if (Info[i].figuresCoordinate && Info[i].figureType) {
            int row = static_cast<int>(Info[i].figuresCoordinate->y()) / cellSize;
            int col = static_cast<int>(Info[i].figuresCoordinate->x()) / cellSize;


            char file = 'A' + col;
            char rank = '1' + (7 - row);
            Info[i].chessCoordinate = QString(file) + QString(rank);
        }
    }
}

bool chess_table::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::GraphicsSceneMousePress) {
        QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            QPointF clickPos = mouseEvent->scenePos();
            handleChessClick(clickPos);
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}

void chess_table::handleChessClick(const QPointF &clickPos) {
    int col = static_cast<int>(clickPos.x()) / cellSize;
    int row = static_cast<int>(clickPos.y()) / cellSize;

    // Всегда обновляем выделение, даже для пустых клеток
    setColor(col, row);

    // Логика определения фигуры
    char file = 'A' + col;
    char rank = '1' + (7 - row);
    QString chessCoord = QString(file) + QString(rank);

    for (const auto &figure : Info) {
        if (figure.chessCoordinate == chessCoord && figure.figureType) {
            qDebug() << "Clicked on" << chessCoord << "->" << figure.figureName;
            return;
        }
    }
    qDebug() << "Clicked on empty cell:" << chessCoord;
}
QGraphicsRectItem* chess_table::setColor(int& col, int& row) {
    if (col < 0 || col >= 8 || row < 0 || row >= 8) {
        selectionRect->setRect(0, 0, 0, 0);
        lastCol = -1;
        lastRow = -1;
        return nullptr;
    }

    // Проверяем, был ли это клик на уже выделенной клетке
    if (col == lastCol && row == lastRow) {
        // Снимаем выделение
        selectionRect->setRect(0, 0, 0, 0);
        lastCol = -1;
        lastRow = -1;
    } else {
        // Устанавливаем новое выделение
        selectionRect->setRect(col*cellSize, row*cellSize, cellSize, cellSize);
        selectionRect->setPen(QPen(QColor(255, 215, 0), 4));
        lastCol = col;
        lastRow = row;
    }

    return selectionRect;
}

void chess_table::printChessCoordinates()  {
    qDebug() << "Chess coordinates:";
    for (size_t i = 0; i < Info.size(); ++i) {
        qDebug() << "Raw coordinates:" << *Info[i].figuresCoordinate
                 << "-> row:" << Info[i].figuresCoordinate->y() / cellSize<< "col:" << Info[i].figuresCoordinate->x()/ cellSize;
        qDebug() << "Figure:" << Info[i].figureName;
        qDebug() << "Chess coordinate:" << Info[i].chessCoordinate;
    }
}
//ИДИ НАХУЙ
//НАРЕК ЧМО

