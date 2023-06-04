#include <QApplication>
#include <Game.h>
#include <QSplashScreen>
#include <QTimer>

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Con ayuda de la libreria QSplashScreen se puede mostrar una pantalla de carga con un logo png diseñado para el juego
    QSplashScreen splash;
    splash.setPixmap(QPixmap(":/imagenes/sprites/BackGrounds/intro juego.png").scaled(800,600));
    splash.show();\
    QTimer::singleShot(3000,&splash,SLOT(close()));

    game = new Game();
    game->show();

    return a.exec();
}
