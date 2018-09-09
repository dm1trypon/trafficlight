#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>

#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void signalFromColor(QBrush color);

private:
    Ui::Widget *ui;
    QGraphicsScene* scene;
    QTimer* redTimer;
    QTimer* yellowTimer;
    QTimer* greenTimer;
    QGraphicsEllipseItem* ellipse_red = new QGraphicsEllipseItem;
    QGraphicsEllipseItem* ellipse_yellow = new QGraphicsEllipseItem;
    QGraphicsEllipseItem* ellipse_green = new QGraphicsEllipseItem;
private slots:
    void slotChangeRed();
    void slotChangeYellow();
    void slotChangeGreen();

    void slotShowColor(QBrush color);

};

class TrafficLight : QGraphicsEllipseItem
{
private:
    int time_red = 10000;
    int time_yellow = 2000;
    int time_green = 10000;
public:
    TrafficLight(int count);
    void changeColor();

};


#endif // WIDGET_H
