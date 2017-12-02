#ifndef MYBUTTON_H
#define MYBUTTON_H
#include<QPaintEvent>//绘画事件 update();//刷新事件
#include<QPainter>//画家
#include <QWidget>
#include<QMouseEvent>
#include<QDebug>
//我要给这个 QWIDGET设置一张PIXMAP像素图
//然后点击可以发出信号
//表面  是  图标可以绘画出来   通过提升  给choos调用setimage函数后可以设置图片的
//按钮有什么作用？这不是pushbutton并不能点击 所以通过设置信号
//鼠标按下抬起时间将其设置 可以发生信号处理槽函数
//鼠标抬起的时候有点变大的感觉
class mybutton : public QWidget
{
    Q_OBJECT
public:
    explicit mybutton(QWidget *parent = 0);//显示构造函数
    void setpath(QString path="");//传入图片路径

protected:
       void paintEvent(QPaintEvent *e);//绘画事件

       void mousePressEvent(QMouseEvent *e);//鼠标按下事件
       void mouseReleaseEvent(QMouseEvent *e);//鼠标抬起事件
signals:
       void pressd();//信号 只需发出emit  无需定义
       void release();//抬起信号

 private:
      QString   imgpath;
      int normalX,normalY;
};

#endif // MYBUTTON_H
