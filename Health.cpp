#include "Health.h"
#include <QFont>
#include <QGraphicsItem>
#include <QGraphicsTextItem>

Health::Health(QGraphicsItem* parent): QGraphicsTextItem(parent)
{
    health=3;

    //draw the text
    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ")+QString::number(health));

}

int Health::getHealth()
{
    return health;
}
