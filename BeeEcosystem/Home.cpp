#include "Home.h"
#include "qpainter.h"
#include "QGraphicsScene.h"
#include "Human.h"

float Home::sSize{180};

Home::Home()
    :LivingHome(QRectF(-sSize / 2.0f, -sSize / 2.0f, sSize, sSize), QColor(255, 228, 181))
{
}

void Home::birth()
{
    Human* newHuman = new Human(this);
    scene()->addItem(newHuman);
    mLivingBeings.push_back(newHuman);
    newHuman->initPos();
}


QRectF Home::boundingRect() const
{
    return QRectF();
}

void Home::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setBrush(Qt::NoBrush);
    painter->setPen(mColor);
    painter->drawRect(mForm);
    painter->setPen(QColor(0, 0, 0));
    QFontMetrics fontMetrics(painter->font());
    painter->drawText(QPointF(-fontMetrics.width("HOME") / 2.0f, fontMetrics.height() / 2.0f), "HOME");
}

void Home::initPos()
{
    if (scene()) {
        setPos(scene()->width()/4.0f, -scene()->height()/6.0f);
    }
}

float Home::size()
{
    return sSize;
}
