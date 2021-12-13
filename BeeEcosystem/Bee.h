//Fichier : Bee.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef BEE_H
#define BEE_H

#include "ForagingInsect.h"
#include "FloweringPlant.h"

//Bee représente des abeilles qui vont poléniser une floweringPlant aléatoirement, lorsqu'elle la polénise, une nouvelle floweringPlant est créé.
//Au fil du temps, de nouvelles abeilles naissent et décèdent.

class Bee : public ForagingInsect
{
private :
	int mNbrOfloweringPlantToCreate;

public:
	//fonction de base
	Bee(Swarm* swarm);
	~Bee() override = default;
	Bee(Bee const&) = default;
	Bee& operator=(Bee const&) = default;

	//fonction utilitaire
	bool isColliding(const FloweringPlant* floweringPlant) const;
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