#include "movimiento.h"


QRectF Movimiento::boundingRect() const
{
    return QRectF(0, 0, 2 * r, 2 * r);
}

void Movimiento::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    srand(time(0));
    QColor((255, 255, 255));

    if(color == 'A')
        painter->setBrush(Qt::yellow);
    else
        painter->setBrush(QColor(255, 255, 255));

    painter->drawEllipse(boundingRect());
}
double Movimiento::getPosx() const
{
    return posx;
}

double Movimiento::getPosy() const
{
    return posy;
}

double Movimiento::getMasa() const
{
    return masa;
}

double Movimiento::getVelX() const
{
    return velX;
}

double Movimiento::getVelY() const
{
    return velY;
}



char Movimiento::getNombre() const
{
    return nombre;
}

Movimiento::Movimiento()
{

}

Movimiento::Movimiento(char nombre_, double x,  double y, double velX_, double velY_,
                       double masa_, int r_, char color_)
{
    nombre = nombre_;

    // Posiciones que cambian
    posx = x;
    posy = y;

    //color de la particula
    color = color_;

    // Velocidades en X y Y
    velX = velX_;
    velY = velY_;

    masa = masa_;

    r = r_;

    setPos(posx, -posy);
}
