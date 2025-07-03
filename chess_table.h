#ifndef CHESS_TABLE_H
#define CHESS_TABLE_H

#include<QGraphicsItem>
#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsView>
#include"figures.h"

class game_logic;

class Figures;

using namespace std;
class chess_table:public QWidget
{
    Q_OBJECT
private:
    int cellSize;
    int size;
    static const QColor BROWN;
    static const QColor WHITE;
    vector<vector<QPoint>> rect;
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
