#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
extern QLineEdit *Screen;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void createUI();
     ~MainWindow();
public slots:
    void addnumber(int);
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
