//Fichier : Swarm.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef SWARM_H
#define SWARM_H

#include "LivingHome.h"

//Cette classe représente un essaim. Un essaim est une entité statique dans lequel les insectes butineurs vivent en groupe.

class Swarm : public LivingHome
{
public:
	//fonction de base
	Swarm();
	virtual ~Swarm() = default;
	Swarm(Swarm const&) = default;
	Swarm& operator=(Swarm const&) = default;

	//fonction override
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
	
	//fonction statique
	static float size();

	//variable statique
private:
	static float sSize;
};

#endif