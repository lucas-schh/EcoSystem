#include "Bee.h"
#include <QPainter>
#include "EcoSystem.h"
#include "Random.h"

#include "Tomato.h"
#include "Courgette.h"
#include "Aubergine.h"




QRectF Bee::sShape{ QRectF(-sRadius, -sRadius, 2*sRadius, 2*sRadius) };
float Bee::sRadius{ 2.5f };

Bee::Bee(Swarm* swarm)
	:ForagingInsect(QColor(244, 158, 18), swarm),
	mNbrOfloweringPlantToCreate{1}
{
}

bool Bee::isColliding(const FloweringPlant* floweringPlant) const
{
	if (floweringPlant->collidesWithItem(this)){
			return true;
	}
	else {
		return false;
	}
}

void Bee::stayInSwarm()
{
	if (mSwarm) {
		if (pos().x() - sRadius <= (mSwarm->pos().x() - Swarm::size() / 2.0f)) {
			setPos(QPointF(pos().x() + 1, pos().y())); //On décale un peu l'objet car il peut y avoir des problèmes de collision avec la bordure
			mSpeed = QPoint(-mSpeed.x(), mSpeed.y());
		}
		if (pos().x() + sRadius > mSwarm->pos().x() + Swarm::size() / 2.0f) {
			mSpeed = QPoint(-mSpeed.x(), mSpeed.y());
		}
		if (pos().y() + sRadius > (mSwarm->pos().y() + Swarm::size() / 2.0f)) {
			mSpeed = QPoint(mSpeed.x(), -mSpeed.y());
		}
		if (pos().y() - sRadius <= (mSwarm->pos().y() - Swarm::size() / 2.0f)) {
			setPos(QPointF(pos().x(), pos().y() + 1));
			mSpeed = QPoint(mSpeed.x(), -mSpeed.y());
		}
	}
}

void Bee::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setBrush(mColor);
	painter->setPen(Qt::NoPen);
	painter->drawEllipse(sShape);
}

QRectF Bee::boundingRect() const
{
	return sShape;
}

void Bee::advance(int phase)
{
// Détermine le comportement
	if (phase == 0) {
		EcoSystem* myScene = static_cast<EcoSystem*>(scene());
		if (!mIsOutside) {
			if ((Random::generate(1, 8000) == 1) && myScene->randomFloweringPlant()) mIsOutside = true; //randomFloweringPlant() est utilisé pour savoir si il existe des floweringPlant dans la scène (elle renvoie nullptr si non)
			stayInSwarm();
			mDestination = QPointF();
			if (mNbrOfloweringPlantToCreate == 0) mNbrOfloweringPlantToCreate = 1;
		}
		if (mIsOutside) {
			if (myScene->randomFloweringPlant()) { //Si il y a des floweringPlant dans la scène
				moovingTo((myScene->randomFloweringPlant())->pos());
				if (isCollidingScene()) { //gère le cas où l'abeille se dirige vers une floweringPlant qui existe plus (elle continue alors jusqu'au bord de la scene)
					mDestination = QPointF();
					moovingTo(mSwarm->pos());
				}
			}
			else if (!(myScene->randomFloweringPlant())) { //gère le cas où il n'y a plus de floweringPlant
				if (mDestination != mSwarm->pos()) mDestination = QPointF(); //permet de faire qu'une fois le moovingto(mSwarm->pos())
				moovingTo(mSwarm->pos());
				if (pos().x() < mDestination.x()) mIsOutside = 0;
			}
			if (mNbrOfloweringPlantToCreate == 1) {
				for (auto& item : scene()->items()) {
					FloweringPlant* myFloweringPlant{ dynamic_cast<FloweringPlant*>(item) };
					if (this && myFloweringPlant) {
						Courgette* myCourgette{ dynamic_cast<Courgette*>(myFloweringPlant) };
						Aubergine* myAubergine{ dynamic_cast<Aubergine*>(myFloweringPlant) };
						Tomato* myTomato{ dynamic_cast<Tomato*>(myFloweringPlant) };
						//dès que la bee croise une floweringplant elle la polénise et repart
						if (myTomato && isColliding(myTomato)) {
							Tomato* myT = new Tomato();
							scene()->addItem(myT);
							myT->initPos();
							mNbrOfloweringPlantToCreate = 0;
							mDestination = QPointF();
							moovingTo(mSwarm->pos());
						}
						if (myCourgette && isColliding(myCourgette)) {
							Courgette* myC = new Courgette();
							scene()->addItem(myC);
							myC->initPos();
							mNbrOfloweringPlantToCreate = 0;
							mDestination = QPointF();
							moovingTo(mSwarm->pos());
						}
						if (myAubergine && isColliding(myAubergine)) {
							Aubergine* myA = new Aubergine();
							scene()->addItem(myA);
							myA->initPos();
							mNbrOfloweringPlantToCreate = 0;
							mDestination = QPointF();
							moovingTo(mSwarm->pos());
						}
					}
				}
			}
			else if (mDestination==mSwarm->pos()) { //gère le cas quand mNbrOfloweringPlantToCreate=0
				if (pos().x() < mDestination.x()) mIsOutside = 0;
			}
		}
		mNewPosition = pos() + mSpeed * EcoSystem::elapsedTime();
		if (mAge >= mLifeTime) {
			mSwarm->die(this);
			mAlive = false;
		}
		// Applique le comportement
	}
	else if (phase == 1) {
		// Applique la nouvelle position
		setPos(mNewPosition);
	
		// Plus vieux
		mAge += EcoSystem::elapsedTime();

		//donne naissance
		if (mAge > Random::generate(15, 29) && mNbrOfBirth > 0) {
			mSwarm->birth();
			mNbrOfBirth--;
		}
	}
}

void Bee::initPos()
{
    if (mSwarm) {
        setPos(Random::generate((float)(mSwarm->pos().x()-Swarm::size()/2.0f+sRadius), (float)(mSwarm->pos().x() + Swarm::size() / 2.0f - sRadius)), Random::generate((float)(mSwarm->pos().y() - Swarm::size() / 2.0f + sRadius), (float)(mSwarm->pos().y() + Swarm::size() / 2.0f - sRadius)));
    }
}