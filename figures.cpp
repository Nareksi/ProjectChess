#include "figures.h"


figures::figures() {
     ALL_FIGURES = {
        {":/images/images/blackPawn.png"},
        {":/images/images/whitePawn.png"},
        {":/images/images/blackRook.png"},
        {":/images/images/whiteRook.png"},
        {":/images/images/blackHorse.png"},
        {":/images/images/whiteHorse.png"},
        {":/images/images/blackElephant.png"},
        {":/images/images/whiteElephant.png"},
        {":/images/images/blackQueen.png"},
        {":/images/images/whiteQueen.png"},
        {":/images/images/blackKing.png"},
        {":/images/images/whiteKing.png"}
    };

    for (int i = 0; i<ALL_FIGURES.size(); i++) {
        ALL_FIGURES[i] = ALL_FIGURES[i].scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    }

}


vector<QGraphicsPixmapItem*> figures::setImages(){
    vector<QGraphicsPixmapItem*> allFigures;
    for (int i = 0; i < ALL_FIGURES.size(); ++i) {
        QGraphicsPixmapItem* f = new QGraphicsPixmapItem(ALL_FIGURES[i]);
        allFigures.push_back(f);

    }
    return allFigures;
}
