#include "Human.h"
#include "Random.h"
#include <QPainter>
#include "EcoSystem.h"
#include "Aubergine.h"
#include "Courgette.h"
#include "Tomato.h"


QRectF Human::sShape{ QRectF(-sSize, -sSize, 2 * sSize, 2 * sSize) };
float Human::sSize{ 20.0f };


Human::Human(Home* home)
	:ObjectMotion(Random::generate(100,200), Random::randomHumanSkinColor(), Random::randomPointOnCircle(20), 20),
	mHome{home},
	mLife{Random::generate(80,120)},
	mName{ Random::randomHumanName() },
	mNbrOfloweringPlantToEat{1},
	mGoKillAsianHornet{},
	mNbrOfBirth{1}
{
}

int Human::life() const
{
	return mLife;
}

void Human::setLife(int life)
{
	mLife = life;
}

void Human::setGoKillAsianHornet(int goKillAsianHornet)
{
	mGoKillAsianHornet = goKillAsianHornet;
}

void Human::eat(FloweringPlant* floweringPlant)
{
	if (floweringPlant->lifeRecovery(mLife) > 120) mLife = 120;
	else mLife = floweringPlant->lifeRecovery(mLife);
	floweringPlant->setAlive(false);
}

bool Human::isColliding(const FloweringPlant* floweringPlant) const
{
	if (floweringPlant->collidesWithItem(this)) {
		return true;
	}
	else {
		return false;
	}
}

bool Human::isColliding(const SwarmAsianHornet* swarmAsianHornet) const
{
	if (swarmAsianHornet->collidesWithItem(this)) {
		return true;
	}
	else {
		return false;
	}
}

void Human::stayInHome()
{
	if (mHome) {
		if (pos().x() - sSize <= (mHome->pos().x() - Home::size() / 2.0f)) {
			setPos(QPointF(pos().x()+1,pos().y())); //On décale un peu l'objet car il peut y avoir des problèmes de collision avec la bordure
			mSpeed = QPoint(-mSpeed.x(), mSpeed.y());
		}
		if (pos().x() + sSize > mHome->pos().x() + Home::size() / 2.0f) {
			mSpeed = QPoint(-mSpeed.x(), mSpeed.y());
		}
		if (pos().y() + sSize > (mHome->pos().y() + Home::size() / 2.0f)) {
			mSpeed = QPoint(mSpeed.x(), -mSpeed.y());
		}
		if (pos().y() - sSize <= (mHome->pos().y() - Home::size() / 2.0f)) {
			setPos(QPointF(pos().x(), pos().y()+1));
			mSpeed = QPoint(mSpeed.x(), -mSpeed.y());
		}
	}
}

QRectF Human::boundingRect() const
{
	return sShape;
}

void Human::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(Qt::NoPen);
	painter->setBrush(mColor);
	painter->drawRect(sShape);
	painter->setPen(QColor(0,0,0));
	QFontMetrics fontMetrics(painter->font());
	painter->drawText(QPointF(-fontMetrics.width(mName)/2.0f, fontMetrics.height()/2.0f), mName);
	painter->setPen(Qt::NoPen);
	painter->setBrush(QColor(255,0,0));
	painter->drawRect(-sSize / 2.0f, sSize / 2.0f, std::clamp(mLife * sSize/120, 0.0f, sSize), sSize/8.0f); //barre de vie
}

void Human::advance(int phase)
{
	// Détermine le comportement
	if (phase == 0) {
		EcoSystem* myScene = static_cast<EcoSystem*>(scene());
		if (!mIsOutside) {
			if ((Random::generate(1, 700) == 1) && myScene->randomFloweringPlant()) mIsOutside = true; //randomFloweringPlant() est ici utilisé pour savoir si il reste des floweringPlant
			if (!(myScene->isEnoughFood()) && !(myScene->allAsianHornetDead()) && mGoKillAsianHornet == 0 && mAge>EcoSystem::elapsedTime()*1000) { //mAge>EcoSystem::elapsedTime()*1000 empêche que les nouveaux nés aille tué les AsianHornet
				mIsOutside = true;
				myScene->sendHumanKillAsianHornet(this); //permet d'envoyer qu'un seul humain aller tuer les AsianHornet
			}
			stayInHome();
			mDestination = QPointF();
			if (mNbrOfloweringPlantToEat == 0) mNbrOfloweringPlantToEat = 1;
		}
		else if (mIsOutside) {
			if (myScene->randomFloweringPlant() && mGoKillAsianHornet != 2) { //gère le cas où il va manger une floweringPlant, la logique est similaire à celle des abeilles
				moovingTo((myScene->randomFloweringPlant())->pos());
				if (isCollidingScene()) {
					mDestination = QPointF();
					moovingTo(mHome->pos());
				}
				if (mNbrOfloweringPlantToEat == 1) {
					for (auto& item : scene()->items()) {
						FloweringPlant* myFloweringPlant{ dynamic_cast<FloweringPlant*>(item) };
						if (this && myFloweringPlant && isColliding(myFloweringPlant)) {
							eat(myFloweringPlant);
							mNbrOfloweringPlantToEat = 0;
							mDestination = QPointF();
							moovingTo(mHome->pos());
						}
					}
				}
				else if (mDestination==mHome->pos()) {
					if (pos().y() < mDestination.y()) mIsOutside = 0;
				}
			}
			else if (!(myScene->randomFloweringPlant()) && mGoKillAsianHornet != 2) { //gère le cas où il n'y a plus de floweringPlant
				if (mDestination != mHome->pos()) mDestination = QPointF(); //permet de faire qu'une fois le moovingto(mHome->pos())
				moovingTo(mHome->pos());
				if (pos().y() < mDestination.y()) mIsOutside = 0;
			}
			else if (mGoKillAsianHornet == 2) { //gère le cas de l'humain qui va tuer les AsianHornet
				SwarmAsianHornet* mySwarmAsianHornet{};
				for (auto item : scene()->items()) {
					SwarmAsianHornet* swarmAsianHornet = dynamic_cast<SwarmAsianHornet*>(item);
					if (swarmAsianHornet) mySwarmAsianHornet = swarmAsianHornet;
				}
				if (mySwarmAsianHornet) {
					moovingTo(mySwarmAsianHornet->pos());
					if (isColliding(mySwarmAsianHornet)) {
						myScene->toSting(*this, *mySwarmAsianHornet);
						myScene->killAsianHornet(mySwarmAsianHornet);
						mDestination = QPointF();
						moovingTo(mHome->pos());
					}
					if (pos().x() > mDestination.x() && mDestination == mHome->pos()) {
						mIsOutside = 0;
						myScene->setAllGoKillAsianHornetToNull(); //une fois qu'il est renté met l'attribut à 0 à tous les autres humains pour qu'un autre puisse aller tuer les AsianHornet
					}
				}
			}
		}
		mNewPosition = pos() + mSpeed * EcoSystem::elapsedTime();
		if (mLife <= 0) {
			mHome->die(this);
			mAlive = false;
		}
		if (mAge >= mLifeTime) {
			mHome->die(this);
			mAlive = false; 
			if (mGoKillAsianHornet == 2) myScene->setAllGoKillAsianHornetToNull(); //gère le cas où l'humain qui devait aller tuer les AsianHornets meurt de vieillesse sur le chemin
		}
		if (!(myScene->randomFloweringPlant())) mLifeTime = mLifeTime-0.03f; //Si y'a plus de nourriture, alors leur esperance de vie diminue
	}
	else if (phase == 1) {
		// Applique la nouvelle position
		setPos(mNewPosition);


		// Plus vieux
		mAge += EcoSystem::elapsedTime();

		//donne naissance
		if (mAge > Random::generate(75, 140) && mNbrOfBirth > 0 && mHome->livingBeing().size() >= 2) {
			mHome->birth();
			mNbrOfBirth--;
		}
	}
}

void Human::initPos()
{
	if (mHome) {
		setPos(Random::generate((float)(mHome->pos().x() - Home::size() / 2.0f + sSize), (float)(mHome->pos().x() + Home::size() / 2.0f - sSize)), Random::generate((float)(mHome->pos().y() - Home::size() / 2.0f + sSize), (float)(mHome->pos().y() + Home::size() / 2.0f - sSize)));
	}
}
