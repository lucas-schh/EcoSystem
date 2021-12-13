//Fichier : FloweringPlant.h
//GPA434 - Laboratoire 3
//Cr�ation :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef FLOWERINGPLANT_H
#define FLOWERINGPLANT_H

#include "LivingBeing.h"
#include <QPolygonF>

//Cette classe abstraite repr�sente une plante � fleur, une plante � fleur redonne de la vie � un humain lorsqu'elle est mang�.
//Elles pourissent au bout d'un certain temps al�atoire.
//De nouvelle plante � fleur sont cr�� lorsqu'une abeille en pol�nise une (plus d'info sur la doc de Bee.h)

class FloweringPlant : public LivingBeing
{
protected:
	float mLifeRecovery;

public:
	//fonction de base
	FloweringPlant( QColor color, float lifeRecovery);
	virtual ~FloweringPlant() = default;
	FloweringPlant(FloweringPlant const&) = default;
	FloweringPlant& operator=(FloweringPlant const&) = default;

	//fonction virtuel pure
	virtual int lifeRecovery(int life) const= 0;

	//fonction override
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
	void advance(int  phase) override;
	void initPos() override;

	static QPolygonF shape();
	static float radius();
	static void setRadius(float radius);
	static int chooseTypeOfFloweringPlant();
	
private: 
	static float sRadius;
	static QPolygonF sShape;
};

#endif