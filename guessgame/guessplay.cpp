#include "guessplay.h"
guessplay::guessplay(QWidget *parent) : QWidget(parent),temp(0),com_temp(0)
{

            this->setWindowTitle(QString("GUESSGAME"));
            this->setMaximumSize(580,450);
            this->setMinimumSize(580,450);
             this->setWindowIcon(QIcon(QString(":/new/prefix1/猜拳icon.jpg")));
//        stop=new mybutton(this);  //停止按钮
//        stop->setpath(":/new/prefix1/yes.png");

//        unstop=new mybutton(this);//退出游戏按钮吧
//        unstop->setpath(":/new/prefix1/no.png");

//        stop->move(70,350);
//        unstop->move(420,350);
        this->peoplegif=new QMovie;
        peoplegif->setFileName(QString(":/new/prefix1/剪刀石头布人类.gif"));

        this->compgif=new QMovie;
        compgif->setFileName(QString(":/new/prefix1/剪刀石头布电脑.gif"));


        people=new QLabel(this);
        this->people->setMovie(peoplegif);
        this->people->move(50,150);

        computer=new QLabel(this);
        this->computer->setMovie(compgif);
        this->computer->move(400,150);

        compgif->start();
        peoplegif->start();


        shear=new QPushButton(QString("剪刀"),this);
        shear->resize(50,50);
        shear->move(50,370);

        rock=new QPushButton(QString("石头"),this);
        rock->resize(50,50);
        rock->move(250,370);

        paper=new QPushButton(QString("布"),this);
        paper->resize(50,50);
       paper->move(440,370);

       mark_left=new QLabel(this);
       mark_left->move(50,150);
       mark_left->hide();

       mark_right=new QLabel(this);
       mark_right->move(400,150);
       mark_right->hide();

       connect(shear,&QPushButton::clicked,   //剪刀按钮
               [=]()
       {
               peoplegif->stop();
               compgif->stop();  //停止GIF
               people->hide();
               computer->hide();

               mark_left->setPixmap(QPixmap(":/new/prefix1/左剪刀.png"));
               mark_left->show();

               temp=1;  //1代表剪刀
              qDebug()<<temp;

              this->randmark(); //电脑产生随机的一个剪刀石头布
               this->whowin();//判断who win
       });

       connect(rock,&QPushButton::clicked,  //石头按钮
               [=]()
       {
               peoplegif->stop();
               compgif->stop();  //停止GIF
               people->hide();
               computer->hide();

               mark_left->setPixmap(QPixmap(":/new/prefix1/左拳头.png"));
               mark_left->show();

               temp=2;  //2代表石头

              this->randmark();
                  this->whowin();//判断who win
       });

       connect(paper,&QPushButton::clicked,  //布的按钮
               [=]()
       {
               peoplegif->stop();
               compgif->stop();  //停止GIF
               people->hide();
               computer->hide();

               mark_left->setPixmap(QPixmap(":/new/prefix1/左布.png"));
               mark_left->show();

               temp=3;  //3代表布

              this->randmark();
                  this->whowin();//判断who win

       });
       update();
}

void guessplay::randmark()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    com_temp = qrand()%(3-1+1)+1;
    qDebug()<<com_temp;
       switch(com_temp)
       {
                    case 1:
                             mark_right->setPixmap(QPixmap(":/new/prefix1/右剪刀.png"));
                             mark_right->show();
                            break;
                    case 2:
                             mark_right->setPixmap(QPixmap(":/new/prefix1/右拳头.png"));
                             mark_right->show();
                            break;
                    case 3:
                            mark_right->setPixmap(QPixmap(":/new/prefix1/右布.png"));
                            mark_right->show();
                            break;
       }

}

void guessplay::whowin()
{
    if(temp==com_temp)
    {
        if(QMessageBox::Yes==QMessageBox::question(this,"打平手","请选择是否继续游戏",QMessageBox::Yes,QMessageBox::No))
        {
                peoplegif->start();
                compgif->start();  //停止GIF
                people->show();
                computer->show();
                mark_left->hide();
                mark_right->hide();
        }
        else
        {
            this->close();
        }
    }
    else if(temp==1&&com_temp==3||temp==2&&com_temp==1||temp==3&&com_temp==2)
    {
        if(QMessageBox::Yes==QMessageBox::question(this,"恭喜您，YOUR WIN","请选择是否继续游戏",QMessageBox::Yes,QMessageBox::No))
        {
                peoplegif->start();
                compgif->start();  //停止GIF
                people->show();
                computer->show();
                mark_left->hide();
                mark_right->hide();
        }
        else
        {
            this->close();
        }
    }
   else
        {
        if(QMessageBox::Yes==QMessageBox::question(this,"很遗憾,you loser ","请选择是否继续游戏",QMessageBox::Yes,QMessageBox::No))
        {
                peoplegif->start();
                compgif->start();  //停止GIF
                people->show();
                computer->show();
                mark_left->hide();
                mark_right->hide();
        }
        else
        {
            this->close();
        }

    }

}

guessplay::~guessplay()
{
        delete peoplegif; //释放QMOVIE的内存
    delete compgif;
}

void guessplay::paintEvent(QPaintEvent *e)
{
    QPainter p_play(this);
    p_play.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/VS.jpg"));
}



