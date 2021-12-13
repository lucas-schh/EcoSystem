//Fichier : AsianHornet.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021

#pragma once
#ifndef ASIANHORNET_H
#define ASIANHORNET_H

#include "ForagingInsect.h"
#include "SwarmBees.h"
#include "Bee.h"

//AsianHornet représente des frelons asiatiques, qui est une espèce invasive qui s'attaque aux abeilles.
//Ses fonctions lui permettent de rester dans sa Swarm (essaim) et de partir à une position aléatoire vers le bas de la scène.
//Si elle croise une abeille elle la tue, et dès qu'elle croise un essaim d'abeille, elle y reste jusqu'à en tuer 2.
//Au fil du temps, de nouveaux frelons naissent et décèdent.


class AsianHornet : public ForagingInsect
{
private:
	int mNumberOfBeeKilled;
	int mLimitOfKills;

public:
	//fonction de base
	AsianHornet(Swarm* swarm);
	~AsianHornet() override = default;
	AsianHornet(AsianHornet const&) = default;
	AsianHornet& operator=(AsianHornet const&) = default;

	//fonction utilitaire
	bool isColliding(const SwarmBees* swarmbees) const;
	bool isColliding(const Bee* bee) const;
	void killBee(Bee* bee) const;
	void stayInSwarm();

	//fonction override
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
	QRectF boundingRect() const override;
	void advance(int phase) override;
	void initPos() override;

	//variable statique
private:
	static QRectF sShape;
	static float sRadius;	
};

#endif