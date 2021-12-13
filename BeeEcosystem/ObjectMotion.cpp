#include "ObjectMotion.h"
#include "Random.h"
#include "BeeEcosystem.h"

ObjectMotion::ObjectMotion(float lifeTime, QColor color, QPoint speed, float amplitudeSpeed)
	:LivingBeing(lifeTime, color),
	mSpeed{speed},
	mDestination{QPointF()},
	mIsOutside{},
	mNewPosition{},
	mAmplitudeSpeed{ amplitudeSpeed }
{
}

void ObjectMotion::setIsOutside(bool isOutside)
{
	mIsOutside = isOutside;
}

void ObjectMotion::moovingTo(QPointF& position)
{
	if (mDestination==QPointF()) { //permet d'envoyer l'objet qu'une seule fois
		const float pi{ 3.1415926535897932384626433832795f };
		mDestination = position;
		QPointF direction = position - pos();
		mSpeed = mAmplitudeSpeed * QPointF(cos(atan2(direction.y(),direction.x())), sin(atan2(direction.y(),direction.x())));
	}
}

bool ObjectMotion::isCollidingScene() const
{
	if (pos().x() > scene()->width() / 2 || pos().x() < -scene()->width() / 2)  return true;
	else if (pos().y() > scene()->height() / 2 || pos().y() < -scene()->height() / 2) return true;
	else {
		return false;
	}
}
