#include "LivingBeing.h"

LivingBeing::LivingBeing(float lifeTime, QColor color)
	: mLifeTime{lifeTime},
	mAge{},
	mColor{color},
	mAlive{true}
{
}

bool LivingBeing::isAlive() const
{
	return mAlive;
}

void LivingBeing::setAlive(bool alive)
{
		mAlive = alive;
}
