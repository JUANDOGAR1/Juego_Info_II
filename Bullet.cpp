#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <Enemy.h>
#include <Qlist>
#include "Game.h"

extern Game* game; //an external global  object called game

Bullet::Bullet(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imagenes/sprites/explocion/Dibujo 3.png"));

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increase score
            game->score->increase();

            //remove  them from the scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //delete  them from de heap
            delete colliding_items[i];
            delete this;
            return;
        }

    }

    setPos(x(),y()-10);
    if (pos().y()+boundingRect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
