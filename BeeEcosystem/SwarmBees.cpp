#include "SwarmBees.h"
#include "QGraphicsScene.h"
#include "Bee.h"

SwarmBees::SwarmBees()
	:Swarm()
{
}

void SwarmBees::birth()
{
	Bee* newBee = new Bee(this);
	scene()->addItem(newBee);
	mLivingBeings.push_back(newBee);
	newBee->initPos();
}

void SwarmBees::initPos()
{
	if (scene()) {
		setPos(-scene()->width()/4.0f, scene()->height() / 4.0f);
	}
}
