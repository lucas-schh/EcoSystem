#include "SwarmAsianHornet.h"
#include "qgraphicsscene.h"
#include "AsianHornet.h"

SwarmAsianHornet::SwarmAsianHornet()
	:Swarm()
{
}

void SwarmAsianHornet::birth()
{
	AsianHornet* newAsianHornet = new AsianHornet(this);
	mLivingBeings.push_back(newAsianHornet);
	scene()->addItem(newAsianHornet);
	newAsianHornet->initPos();
}


void SwarmAsianHornet::initPos()
{
	if (scene()) {
		setPos(-scene()->width() / 3.5f, -scene()->height()/8.0f);
	}
}
