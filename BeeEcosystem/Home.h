//Fichier : ForagingInsect.h
//GPA434 - Laboratoire 3
//Cr�ation :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef HOME_H
#define HOME_H

#include "LivingHome.h"

//Repr�sente une maison, dans laquelle des humains vivent. Elle agit principalement comme un conteneur dans lequel les humains restent lorsqu'ils
//n'ont pas de tache � faire.
//Elle permet de cr�er des nouveaux humains � la simulation.

class Home : public LivingHome
{
public:
	//fonction de base
	Home();
	~Home() override = default;
	Home(Home const&) = default;
	Home& operator=(Home const&) = default;
	
	//fonction override
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
	void initPos() override;
	void birth() override;

	//fonction statique
	static float size();

	//variable statique
private:
	static float sSize;
};

#endif