#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <QGraphicsItem>
#include "Game.h"

extern Game* game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem()
{
    //set random position
    int randomPos =rand() % 750 + (-200); // + (-200)
    setPos(randomPos,-190);
    setPixmap(QPixmap(":/imagenes/sprites/explocion/albondiga.png"));

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    int randomVel = rand() % 10 + 3;
    setPos(x(),y()+randomVel);
    if (pos().y() > 360){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
