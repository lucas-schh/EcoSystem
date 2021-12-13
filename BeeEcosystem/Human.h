//Fichier : Human.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef HUMAIN_H
#define HUMAIN_H

#include "ObjectMotion.h"
#include "Home.h"
#include "FloweringPlant.h"
#include "SwarmAsianHornet.h"

//Représente un humain, les humains possèdent une maison dans laquelle ils vivent.
//Il peut récupérer de la vie en allant manger une FloweringPlant.
//Lorsqu'il n'y a plus assez de floweringPlant, les humains vont aller dans l'essaim de frelons (SwarmAsianHornet) pour en tuer une partie
//afin que les abeilles proliférent et polénise plus de floweringPlant.

class Human : public ObjectMotion
{
private:
	int mLife;
	QString mName;
	Home* mHome;
	int mNbrOfloweringPlantToEat;
	int mGoKillAsianHornet; //si = 0 ne va pas tuer, = 1 attend que quelqu'un aille les tuer, = 2 va aller les tuer
	int mNbrOfBirth;

public:
	//fonction de base
	Human(Home* home);
	~Human() override= default;
	Human(Human const&) = default;
	Human& operator=(Human const&) = default;

	//accesseur et setter
	int life() const;
	void setLife(int life);
	void setGoKillAsianHornet(int goKillAsianHornet);

	//fonction utilitaire
	void eat(FloweringPlant* floweringPlant);
	bool isColliding(const FloweringPlant* floweringPlant) const;
	bool isColliding(const SwarmAsianHornet* swarmAsianHornet) const;
	void stayInHome();

	//fonction override
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
	void advance(int phase) override;
	void initPos() override;

	//variable statique
private:
	static QRectF sShape;
	static float sSize;
};

#endif