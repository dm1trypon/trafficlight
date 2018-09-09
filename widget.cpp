#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QPen pen;
    pen.setColor(Qt::black);
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 200, 300, this);
    scene->setStickyFocus(true);
    ui->graphicsView->setScene(scene);

    ellipse_red = scene->addEllipse(50, 0, 100, 100, pen, QBrush(Qt::black));
    ellipse_yellow = scene->addEllipse(50, 100, 100, 100, pen, QBrush(Qt::black));
    ellipse_green = scene->addEllipse(50, 200, 100, 100, pen, QBrush(Qt::black));

    redTimer = new QTimer(this);
    yellowTimer = new QTimer(this);
    greenTimer = new QTimer(this);
    redTimer->start(1000);
    connect(redTimer, SIGNAL(timeout()),
               this, SLOT(slotChangeYellow()));
    connect(yellowTimer, SIGNAL(timeout()),
                   this, SLOT(slotChangeGreen()));
    connect(greenTimer, SIGNAL(timeout()),
                   this, SLOT(slotChangeRed()));

    connect(this, &Widget::signalFromColor, this, &Widget::slotShowColor);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotChangeRed()
{
    greenTimer->stop();
    redTimer->start(10000);
    emit signalFromColor(Qt::red);
    Widget::ellipse_red->setBrush(Qt::red);
    Widget::ellipse_yellow->setBrush(Qt::black);
    Widget::ellipse_green->setBrush(Qt::black);
}

void Widget::slotChangeYellow()
{
    redTimer->stop();
    yellowTimer->start(2000);
    emit signalFromColor(Qt::yellow);
    Widget::ellipse_yellow->setBrush(Qt::yellow);
    Widget::ellipse_red->setBrush(Qt::black);
    Widget::ellipse_green->setBrush(Qt::black);
}

void Widget::slotChangeGreen()
{
    yellowTimer->stop();
    greenTimer->start(10000);
    emit signalFromColor(Qt::green);
    Widget::ellipse_green->setBrush(Qt::green);
    Widget::ellipse_red->setBrush(Qt::black);
    Widget::ellipse_yellow->setBrush(Qt::black);
}

void Widget::slotShowColor(QBrush color)
{
    qDebug() << color;
    //Widget::ellipse->setBrush(color);

}

TrafficLight::TrafficLight(int count)
{

}

void TrafficLight::changeColor()
{

}
