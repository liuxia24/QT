#ifndef GUESSPLAY_H
#define GUESSPLAY_H
#pragma execution_character_set("utf-8")  //防止中文乱码
#include"mybutton.h"
#include <QWidget>
#include<QLabel>
#include<QMovie>
#include<QPushButton>
#include<QtGlobal>
#include<QTime>
#include<QMessageBox>
#include<QPainter>
#include<QPaintEvent>
//左边一个容器   右边一个容器
//图片循环切换
//当点击暂停时  执行两个容器获取的  值
//有一个开始 和暂停的按钮
//点击开始  图片开始循环切换  停止就是获取了 人和电脑的 那个值
class guessplay : public QWidget
{
    Q_OBJECT
public:
    explicit guessplay(QWidget *parent = 0);
    void randmark();  //随机产生一个 数  1 剪刀 2石头 3是布
    void whowin();
    ~guessplay();
protected:
    void paintEvent(QPaintEvent *e);
private:
    //mybutton *stop;//停止
    //mybutton *unstop;//不停止

    QMovie *peoplegif;
    QMovie *compgif;

     QLabel *people;
     QLabel *computer;

     QPushButton *shear;  //剪刀
     QPushButton *rock;//石头
     QPushButton *paper;//布

     QLabel *mark_left;
     QLabel *mark_right;

     int temp;//存放人类的变量
     int com_temp;//存放电脑的变量
};


#endif // GUESSPLAY_H
