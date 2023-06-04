#include "Game.h"
#include "Enemy.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include <QMediaPlayer>
#include <QImage>

Game::Game(QWidget* parent)
{
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    //setBackgroundBrush(QBrush(":/imagenes/sprites/BackGrounds/ciudad2.png"));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    
    player = new Player();
    player->setPos(-150,200);
    
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x()+140,health->y());
    scene->addItem(health);

    //spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);
}

