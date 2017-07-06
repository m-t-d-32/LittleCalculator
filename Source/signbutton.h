#ifndef SIGNBUTTON_H
#define SIGNBUTTON_H
#include <QPushButton>
#include <iostream>
#include <QLineEdit>
using namespace std;
#include <string>
extern QLineEdit *Screen;
extern double result;
extern char lastsign;
extern int countnum;
class signbutton:public QPushButton
{
    Q_OBJECT
private:
    string sign;
public:
    signbutton(QWidget *parent):QPushButton(parent)
    {
        connect(this,SIGNAL(clicked()),this,SLOT(cal()));
    }

    void setsign(string sign)
    {
        this->sign=sign;
    }
public slots:
    void cal()
    {
        countnum=0;
        bool div0=false;
        switch (lastsign)
        {
        case '+':
             {
                 result+=(Screen->text()).toDouble();
                 break;
            }
        case '-':
             {
                 result-=(Screen->text()).toDouble();
                 break;
            }
        case 'x':
             {
                 result*=(Screen->text()).toDouble();
                 break;
            }
        case '/':
             {
            if((Screen->text()).toDouble())
                 result/=(Screen->text()).toDouble();
            else
                div0=true;
                break;
            }
        default:
            {
                result=(Screen->text()).toDouble();;
                break;
             }
        }
        if (div0)
            Screen->setText("Error");
        else
            Screen->setText(QString::number(result));
        lastsign=sign[0];
    }
};

#endif // SIGNBUTTON_H
