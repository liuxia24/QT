#ifndef GUESSMAIN_H
#define GUESSMAIN_H  //宏定义头文件
#pragma execution_character_set("utf-8")  //防止中文乱码
#include<QMenu>
#include<QAction>
#include<QMenuBar>
#include <QMainWindow>
#include<QMessageBox>
#include"mybutton.h"
#include"guessplay.h"
#include<QPainter>
#include<QPaintEvent>
namespace Ui {
class GuessMain;
}

class GuessMain : public QMainWindow
{
    Q_OBJECT   //QT特有的宏  信号与

public:
    explicit GuessMain(QWidget *parent = 0);
    ~GuessMain();

    //进入游戏一个槽函数
    void playgame();
protected:
    void paintEvent(QPaintEvent *e);
private:
    Ui::GuessMain *ui;//ui界面设计

     QMenu *m_start;//一个开始菜单
     QAction *startgame;//开始游戏
     QAction *exitgame;//退出游戏

     QMenu *m_help;//菜单
     QAction *aboutgame;//关于游戏菜单项
     QAction *helpgame;//游戏帮助

     guessplay *pl_game;//定义一个指针   这个窗口用来做游戏


};

#endif // GUESSMAIN_H
