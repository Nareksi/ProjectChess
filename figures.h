#ifndef FIGURES_H
#define FIGURES_H
#include<QPixmap>
#include<QWidget>
#include<QLabel>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include<vector>
#pragma once
class chess_table;

using namespace std;

struct FigureData{
    QString path;
    bool isBlack;
    QString info;
};

class figures {
private:

    vector<QPixmap> figureImages;
    QVector<FigureData> figuresInfo;
public:
    figures();
vector<QGraphicsPixmapItem*>setImages();
    QVector<QPixmap> getFigureImages();
    QVector<FigureData> getFigureInfo();
};

#endif // FIGURES_H
