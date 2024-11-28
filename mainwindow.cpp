#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "movimiento.h"

#include <iostream>

using namespace std;

int times = 0;
ofstream fout;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    cin >> opcion;
    ui->setupUi(this);
    scene=new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-635, -315, 1270, 630); // (posx, posy, ancho, alto)
    scene->setBackgroundBrush(QBrush(QImage(":/imagen/imagenes/espacio_mejor.jpg").scaled(1270,500)));
    timer = new QTimer();

    //Planetas = new QList<Movimiento*>();
    connect(timer, SIGNAL(timeout()), this,SLOT(ActualizarPosicion()));
    temporizador = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}
