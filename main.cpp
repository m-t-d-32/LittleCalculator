#include <QApplication>
#include <QMediaPlayer>
#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include "QLineEdit"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Little Calculator");
    w.show();
    w.createUI();
    QMediaPlayer *player=new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("back.mp3"));
    QObject::connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),player,SLOT(play()));
    player->setVolume(10);
    player->play();
    return a.exec();
}
