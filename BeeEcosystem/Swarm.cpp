#include "Swarm.h"
#include "qpainter.h"

float Swarm::sSize{75.0f};

Swarm::Swarm()
    :LivingHome(QRectF(-sSize/2.0f, -sSize / 2.0f, sSize, sSize), QColor(0,0,0))
{
}

QRectF Swarm::boundingRect() const
{
    return mForm;
}

void Swarm::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setBrush(Qt::NoBrush);
    painter->setPen(mColor);
    painter->drawRect(mForm);
    QFontMetrics fontMetrics(painter->font());
    painter->drawText(QPointF(-fontMetrics.width("SWARM") / 2.0f, fontMetrics.height() / 2.0f), "SWARM");
}

float Swarm::size()
{
    return sSize;
}
