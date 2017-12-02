#include "mybutton.h"

mybutton::mybutton(QWidget *parent) : QWidget(parent)
{
        this->normalX=8;
        this->normalY=8;
}

void mybutton::setpath(QString path)
{
         this->imgpath=path;
        update();//间接刷新绘画事件
}
  void mybutton::paintEvent(QPaintEvent *e)
  {
        //定义一个画家
      QPainter painbutton(this);

      painbutton.drawPixmap(0,0,width(),height(),QPixmap(imgpath));
  }
  void mybutton::mousePressEvent(QMouseEvent *e)//鼠标按下事件
  {
        this->resize(width()-normalX,height()-normalY);
        emit pressd(); //QWIDGET发出信号

  }
  void mybutton::mouseReleaseEvent(QMouseEvent  *e)//鼠标抬起事件
  {
       this->resize(width()+normalX,height()+normalY);
       emit release();  //QWIDGET发出信号

  }
