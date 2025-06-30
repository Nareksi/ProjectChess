#include "mainwindow.h"
#include<QLayout>
#include<QWidget>
#include<QPushButton>
#include <QApplication>
#include<QRect>
#include<QGridLayout>
#include"chess_table.h"
#include<QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    chess_table table;

    //f.show();

    return a.exec();
}
