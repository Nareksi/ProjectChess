#ifndef FIGURES_H
#define FIGURES_H
#include<QPixmap>
#include<QWidget>
#include<QLabel>
#pragma once
class chess_table;
class Figures: public QLabel
{
    Q_OBJECT
protected:
    QPixmap*fig;
public:
    Figures();
};

#endif // FIGURES_H
