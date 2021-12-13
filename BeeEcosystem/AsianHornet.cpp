#include "AsianHornet.h"
#include <QPainter>
#include "EcoSystem.h"
#include "Random.h"

QRectF AsianHornet::sShape{ QRectF(-sRadius, -sRadius, 2 * sRadius, 2 * sRadius) };
float AsianHornet::sRadius{ 3.5f };

AsianHornet::AsianHornet(Swarm* swarm)
	:ForagingInsect(QColor(128, 0, 0), swarm),
	mNumberOfBeeKilled{ 0 },
	mLimitOfKills{2}
{
}

bool AsianHornet::isColliding(const SwarmBees* swarmbees) const
{
	if (collidesWithItem(swarmbees) == true) {
		return true;
	}
	return false;
}

bool AsianHornet::isColliding(const Bee* bee) const
{
	if (collidesWithItem(bee) == true) {
		return true;
	}
	return false;
}

void AsianHornet::killBee(Bee* bee) const
{
	bee->swarm()->die(bee);
	bee->setAlive(false);
}

void AsianHornet::stayInSwarm()
{
	if (mSwarm) {
		if (pos().x() - sRadius <= (mSwarm->pos().x() - Swarm::size() / 2.0f)) {
			setPos(QPointF(pos().x() + 1, pos().y())); //On d�cale un peu l'objet car il peut y avoir des probl�mes de collision avec la bordure
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

void AsianHornet::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setBrush(mColor);
	painter->setPen(Qt::NoPen);
	painter->drawEllipse(sShape);
}

QRectF AsianHornet::boundingRect() const
{
    return sShape;
}

void AsianHornet::advance(int phase)
{
	EcoSystem* myScene = static_cast<EcoSystem*>(scene());
// D�termine le comportement
	if (phase == 0) {
		if (!mIsOutside) {     
			stayInSwarm();
			mNumberOfBeeKilled == 0;
			if ((Random::generate(1,1000) == 1)) mIsOutside = true;
			mDestination = QPointF();
		}
		else if (mIsOutside) {
			// on envoie le frelon dans le coin inférieur bas de la scene
			moovingTo(QPointF(Random::generate(-(scene()->width()) / 2.0f, (scene()->width()) / 2.0f), Random::generate((scene()->height()) / 4.0f, (scene()->height()) / 2.0f)));
			if (isCollidingScene()) {
				mDestination = QPointF();  // on reset la Destination pour pouvoir rentrer dans la boucle dans la fonction moovingTo
				moovingTo(mSwarm->pos());  // on le renvoie à son essaim
			}
			//definit une zone � l'int�rieur de la swarm
			if ((pos().x() > (mSwarm->pos().x() - Swarm::size() / 3.0f) && pos().x() < (mSwarm->pos().x() + Swarm::size() / 3.0f)) && (pos().y() > (mSwarm->pos().y() - Swarm::size() / 3.0f) && pos().y() < (mSwarm->pos().y() + Swarm::size() / 3.0f))&& mDestination==mSwarm->pos())
			{
				mIsOutside = 0;	
			}
			SwarmBees* collidingSwarmBees{};
			int nbrOfBee{};
			for (auto& item : scene()->items()) {
				SwarmBees* mySwarmBees{ dynamic_cast<SwarmBees*>(item) };
				Bee* myBee{ dynamic_cast<Bee*>(item) };
		     	if (mySwarmBees && isColliding(mySwarmBees) ) {
						mDestination = QPointF();
						moovingTo(mySwarmBees->pos()); // le frelon se rend au centre de l'essaim
						collidingSwarmBees = mySwarmBees;
				}
				if (this && myBee && mNumberOfBeeKilled != mLimitOfKills) {  // le frelon ne peut tuer que deux abeilles à la fois
					if (isColliding(myBee)) {
						killBee(myBee);
						mNumberOfBeeKilled++;
					}
				}
				if(myBee) nbrOfBee++;
			}
			if ((mNumberOfBeeKilled == mLimitOfKills && mDestination != mSwarm->pos()) || nbrOfBee==0) { // cas ou le frelon retourne a son nid 
				mDestination = QPointF();
				moovingTo(mSwarm->pos());
			}
			if (collidingSwarmBees && pos().y() > collidingSwarmBees->pos().y() && mNumberOfBeeKilled < mLimitOfKills && nbrOfBee!=0) { // si le frelon ne touche aucune abeille et arrive au centre du nid alors il attend
				mSpeed = QPointF();
			}
		}
		mNewPosition = pos() + mSpeed * EcoSystem::elapsedTime();
		if (mAge >= mLifeTime) {
			mSwarm->die(this);
			mAlive = false;
		}
	}
	else if (phase == 1) {
		// Applique la nouvelle position
		setPos(mNewPosition);

		// Plus vieux
		mAge += EcoSystem::elapsedTime();

		//Donne naissance
		if (mAge > Random::generate(15, 29) && mNbrOfBirth > 0) {
			mSwarm->birth();
			mNbrOfBirth--;
		}
	}
}

// place le frelon sur la scene dans son mSwarm
void AsianHornet::initPos()
{
	if (mSwarm) {
		setPos(Random::generate((float)(mSwarm->pos().x() - Swarm::size() / 2.0f + sRadius), (float)(mSwarm->pos().x() + Swarm::size() / 2.0f - sRadius)), Random::generate((float)(mSwarm->pos().y() - Swarm::size() / 2.0f + sRadius), (float)(mSwarm->pos().y() + Swarm::size() / 2.0f - sRadius)));
	}
}
