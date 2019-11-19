#ifndef NUMBERBUTTON_H
#define NUMBERBUTTON_H
#include <QPushButton>
#include<QMouseEvent>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include <QDebug>
extern QLineEdit *Screen;
extern int countnum;
class numberbutton:public QPushButton
{
    Q_OBJECT
private:
    int number;

public:
    numberbutton(QWidget *parent):QPushButton(parent)
    {
        connect(this,SIGNAL(clicked()),this,SLOT(Write()));
    }
    void setnumber(int number)
    {
        this->number=number;
    }
    ~numberbutton()
    {

    }
public slots:
    void Write()
    {
        if (countnum==0)
            Screen->setText(QString::number(number));
        else
            Screen->insert(QString::number(number));
        countnum++;
    }
};

#endif // NUMBERBUTTON_H
