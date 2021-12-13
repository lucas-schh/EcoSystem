//Fichier : Bee.h
//GPA434 - Laboratoire 3
//Cr�ation :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef BEE_H
#define BEE_H

#include "ForagingInsect.h"
#include "FloweringPlant.h"

//Bee repr�sente des abeilles qui vont pol�niser une floweringPlant al�atoirement, lorsqu'elle la pol�nise, une nouvelle floweringPlant est cr��.
//Au fil du temps, de nouvelles abeilles naissent et d�c�dent.

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