#include "FloweringPlant.h"
#include <algorithm>
#include <QPainter>

#include "BeeEcosystem.h"
#include "Random.h"


QPolygonF createTriangle(float radius) {

	QPolygonF triangle(3);   //3 points polygone
	triangle[0] = QPointF(radius, 0);
	triangle[1] = QPointF(-radius / 2, sqrt(3) * radius / 2);
	triangle[2] = QPointF(-radius / 2, -sqrt(3) * radius / 2);

	return triangle;
}

float FloweringPlant::sRadius{ 15.0f };
QPolygonF FloweringPlant::sShape(createTriangle(FloweringPlant::radius()));


FloweringPlant::FloweringPlant(QColor color,  float lifeRecovery)
	: LivingBeing(Random::generate(20, 40),  color),
	mLifeRecovery{ lifeRecovery }
{
}

QRectF FloweringPlant::boundingRect() const {

	return sShape.boundingRect();
}

float FloweringPlant::radius()
{
	return sRadius;
}

void FloweringPlant::setRadius(float radius)
{
	sRadius = std::clamp(radius, 0.1f, 1000.0f);
	sShape = createTriangle(FloweringPlant::radius());
}

void FloweringPlant::initPos()
{
	if (scene()) {
		setPos(Random::generate(((scene()->width()) / 4.0f) - scene()->width() / 10.0f, ((scene()->width()) / 4.0f) + scene()->width() / 10.0f), Random::generate(((scene()->height()) / 4.0f) - scene()->width() / 10.0f, ((scene()->height()) / 4.0f) + scene()->width() / 10.0f));
	}
}

int FloweringPlant::chooseTypeOfFloweringPlant()
{
	return Random::generate(1, 3);
}

QPolygonF FloweringPlant::shape()
{
	return sShape;
}

void FloweringPlant::advance(int phase)
{
	if (phase == 0) {
		if (mAge >= mLifeTime) mAlive = false;
	}
	else if (phase == 1) {
		mAge += EcoSystem::elapsedTime();
	}
}

void FloweringPlant::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
	painter->setPen(mColor);
	painter->setBrush(mColor);
	painter->drawPolygon(sShape);
}