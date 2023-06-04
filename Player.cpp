#include <QGraphicsScene>
#include "Player.h"
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem* parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imagenes/sprites/MC/inicial.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A){
        if(pos().x()>-170)  setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_D){
        if (pos().x()<570) setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_W){
        if (pos().y()>100) setPos(x(),y()-10);

    }
    else if (event->key() == Qt::Key_S){
        if (pos().y()<320) setPos(x(),y()+10);
    }
    else if (event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        bullet->setPos(x(),y()); //se volvió loco despues de añadir los graficos, tocó restarle a cada posicion en ensayo y error
        scene()->addItem(bullet);

    }
}
void Player::spawn()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}

