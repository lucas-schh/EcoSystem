//Fichier : LivingBeing.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef LIVINGBEING_H
#define LIVINGBEING_H

#include <QGraphicsItem>

//Cette classe abstraite représente un être vivant. Elle est ainsi composé des attributs et fonctions de base nécessaire pour un être vivant.


class LivingBeing : public QGraphicsItem
{
protected :
	   float mLifeTime;
	   float mAge;
	   QColor mColor;
	   bool mAlive;

public :
	//fonction de base
	LivingBeing(float lifeTime, QColor color);
	virtual ~LivingBeing() = default;
	LivingBeing(LivingBeing const&) = default;
	LivingBeing& operator=(LivingBeing const&) = default;

	//fonction utilitaire
	bool isAlive() const;
	void setAlive(bool alive);
	
	//fonction virtuel pure
	virtual void initPos() = 0;
};

#endif