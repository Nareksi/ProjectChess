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



class figures {
private:
    vector<QPixmap> ALL_FIGURES;
public:
    figures();
vector<QGraphicsPixmapItem*>setImages();
};

#endif // FIGURES_H
