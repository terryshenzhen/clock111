#include "widget.h"
#include "ui_widget.h"
#include <QDateTime>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //窗体标题
    this->setWindowTitle(tr("电子钟"));
    m_timer=new QTimer(this);
    //设置定时器循环触发
    m_timer->setSingleShot(false);//非单次触发
    //设置定时器触发时间
    m_timer->setInterval(1*1000);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(RecvTimer()));
    //启动定时器
    m_timer->start();
    //调用一次“回到今天”槽函数,初始化日历
    on_pushButton_clicked();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::RecvTimer()
{
    //获取当前时间
    QDateTime dt=QDateTime::currentDateTime();
    //构造时间字符串
    QString str=dt.time().toString("HH:mm:ss");
    //设置LCD时钟
    ui->lcdNumber->display(str);
    //时钟进度条的显示:秒数%10
    ui->progressBar->setValue(dt.time().second()%10);
    qDebug()<<dt.time().second()%10;
}

void Widget::on_pushButton_clicked()
{
    QDateTime dt=QDateTime::currentDateTime();
    //设置日历为今天
    ui->calendarWidget->setSelectedDate(dt.date());
    ui->calendarWidget->setFocus();
}
