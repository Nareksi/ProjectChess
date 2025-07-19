#ifndef CHESS_TABLE_H
#define CHESS_TABLE_H

#include<QGraphicsItem>
#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsSceneMouseEvent>
#include<QDebug>
#include"figures.h"

class game_logic;

class Figures;
struct FiguresInfo{
    QPointF *figuresCoordinate;
    QGraphicsPixmapItem *figureType;
    QString chessCoordinate;
    QString figureName;
    bool isBlack;
};

using namespace std;
class chess_table:public QWidget, public QGraphicsRectItem
{
    Q_OBJECT
private:
    int cellSize;
    int size;
    static const QColor BROWN;
    static const QColor WHITE;
    static const QColor BLACK;
    vector<vector<QGraphicsRectItem*>> rect;
    QGraphicsRectItem *mainTable;
    QGraphicsScene *scene;
    QGraphicsView *view;
    vector<char> letters;
    vector<char> numbers;
    QString ArrayToString(int i, int j);
    QPoint StringToArray();
    void AddLettersAndNumbers();
    void AddInView();
    void SetRectSize();
    void CreateTable();
    void SetFigure();
    void AddFigure();
    figures figures;
    vector<QGraphicsPixmapItem*> allFig;
    void toChess();
    vector<FiguresInfo> Info;
    void saveFiguresData(QGraphicsPixmapItem *figureType, QPointF *figureCoordinate, int &i, QString &figureName, bool &isBlack);
    void printChessCoordinates();
    bool eventFilter(QObject *obj, QEvent *event) override;
    void handleChessClick(const QPointF &clickPos);
    QGraphicsRectItem* lastSelectedCell;
    QGraphicsRectItem* setColor( int&col, int&row);
    QGraphicsRectItem* selectionRect;
    int lastCol = -1;
    int lastRow = -1;





public:
    chess_table();
    QGraphicsPixmapItem *blackPawn;
    QGraphicsPixmapItem *whitePawn;
    QGraphicsPixmapItem *blackRook;
    QGraphicsPixmapItem *whiteRook;
    QGraphicsPixmapItem *blackHorse;
    QGraphicsPixmapItem *whiteHorse;
    QGraphicsPixmapItem *blackElephant;
    QGraphicsPixmapItem *whiteElephant;
    QGraphicsPixmapItem *blackQueen;
    QGraphicsPixmapItem *whiteQueen;
    QGraphicsPixmapItem *blackKing;
    QGraphicsPixmapItem *whiteKing;

    QGraphicsScene getScene();
    vector<vector<QPoint>> getRect();
};

#endif // CHESS_TABLE_H
