#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "numberbutton.h"
#include "signbutton.h"
#include <string>
#include <QLabel>
#include <iostream>
#include "QLineEdit"
using namespace std;

double result;
char lastsign;
int countnum;
numberbutton **NumberButton;
signbutton **SymbolButton;
QLineEdit *Screen;
QLabel *background;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

void MainWindow::createUI()
{
    background=new QLabel(this);
    background->setGeometry(0,0,400,300);
    background->setStyleSheet("background-image: url(:/new/prefix1/1.jpg)");
    background->show();
    Screen=new QLineEdit(this);
    Screen->setGeometry(25,10,350,40);
    Screen->setReadOnly(true);
    Screen->setAlignment(Qt::AlignRight);
    Screen->setStyleSheet("background-color:rgba(0,0,0,0);border:none;color:rgb(255,255,0);");
    Screen->setText("0");
    Screen->setFont(QFont("Titillium Web",23));
    Screen->show();
    NumberButton=new numberbutton*[10];
    for (int i=0;i<10;i++)
    {
        NumberButton[i]=new numberbutton(this);
        NumberButton[i]->setnumber(i);
        NumberButton[i]->setGeometry(40*i+2,100,35,40);
        NumberButton[i]->setText(QString::number(i));
        NumberButton[i]->setFont(QFont("Titillium Web",20));
        NumberButton[i]->setStyleSheet("color:rgb(200,16,200)");
        NumberButton[i]->setFlat(true);
        NumberButton[i]->show();
    }
    SymbolButton=new signbutton*[5];
    string symbol[]={"+","-","x","/","="};
    for (int i=0;i<5;i++)
    {
        SymbolButton[i]=new signbutton(this);
        SymbolButton[i]->setsign(symbol[i]);
        SymbolButton[i]->setGeometry(60*i+50,200,60,60);
        SymbolButton[i]->setText(QString::fromStdString(symbol[i]));
        SymbolButton[i]->setFont(QFont("Titillium Web",25));
        SymbolButton[i]->setStyleSheet("color:rgb(0,0,0)");
        SymbolButton[i]->setFlat(true);
        SymbolButton[i]->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addnumber(int a)
{
    Screen->insert(QString::number(a));
}
