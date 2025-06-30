#include "figures.h"


figures::figures() {
    const QVector<QString> ALL_FIGURES = {
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
        QPixmap pixmap(ALL_FIGURES[i]);
        pixmap = pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        figureImages.push_back(pixmap);
        //figuresInfo.push_back({figure.isBlack, figure.info});
    }

}


vector<QGraphicsPixmapItem*> figures::setImages(){
    vector<QGraphicsPixmapItem*> allFigures;
    for (int i = 0; i < figureImages.size(); ++i) {
        QGraphicsPixmapItem* f = new QGraphicsPixmapItem(figureImages[i]);
        allFigures.push_back(f);
    }
    return allFigures;
}
