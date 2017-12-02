#include "guessmain.h"
#include "ui_guessmain.h"

GuessMain::GuessMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuessMain)  //在堆区申请内存给ui设计界面
{
    ui->setupUi(this);
   update();
    this->setWindowIcon(QIcon(QString(":/new/prefix1/猜拳icon.jpg")));
   this->setMaximumSize(580,450);
   this->setMinimumSize(580,450);
   this->m_start=new QMenu(this);
    m_start=this->menuBar()->addMenu(QString("start"));//建立菜单

    startgame=this->m_start->addAction(QString("开始"));
    this->m_start->addSeparator();//添加分割线 在m_start中
    exitgame=this->m_start->addAction(QString("退出"));
    //以上是start开始 的菜单 add

    this->m_help=this->menuBar()->addMenu(QString("help"));//帮助菜单
    this->aboutgame=this->m_help->addAction(QString("关于游戏"));
    this->m_help->addSeparator();//建立分割线
    this->helpgame=this->m_help->addAction(QString("帮助文档"));
    //以上是help 菜单 add

    //connect(this->exitgame,&QAction::triggered,this,&GuessMain::close);
    connect(this->exitgame,&QAction::triggered,
            [=]()
    {
                   this->close();
    });  //连接exitgame action  关闭游戏

    connect(this->aboutgame,&QAction::triggered,
            [=]()
    {
                   QMessageBox::about(this,QString("关于猜拳游戏"),QString(" 游戏版权:刘伟森版权所有"));
    });  //aboutgame connect signals and slots

    connect(this->helpgame,&QAction::triggered,
            [=]()
    {
                   QMessageBox::information(this,QString("游戏帮助"),QString("1.石头赢剪刀"
                                                                         "2.剪刀赢布 3.布赢石头"),QMessageBox::Ok);
    });//helpgame connect signals and slots

    connect(this->ui->exitbutton,&mybutton::release,  //退出 游戏
            [=]()
    {
                   if(QMessageBox::Close==QMessageBox::question(this,"退出游戏","请问您是退出游戏吗",QMessageBox::No,QMessageBox::Close))\
                   {
                       this->close();
                   }
    });

   connect(this->ui->startbutton,&mybutton::release,this,&GuessMain::playgame);

    ui->startbutton->setpath(":/new/prefix1/pvm.png");
    ui->exitbutton->setpath(":/new/prefix1/exitchoose.png");

}

GuessMain::~GuessMain()
{
    delete ui;
    delete pl_game;
}

void GuessMain::playgame()
{
     //点击进入游戏  当前窗口隐藏   将游戏窗口show出来
    this->hide();
     pl_game=new guessplay;
    pl_game->show();
}

void GuessMain::paintEvent(QPaintEvent *e)
{
    QPainter bg(this);

    bg.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/猜拳背景.jpg"));
}
