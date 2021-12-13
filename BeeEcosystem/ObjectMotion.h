//Fichier : ObjectMotion.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef OBJECTMOTION_H
#define OBJECTMOTION_H

#include "LivingBeing.h"

//Cette classe représente un objet dynamique. Elle est ainsi composé des attributs et fonctions de base nécessaire pour un objet dynamique, tel que
//la vitesse, la nouvelle position, la destination, un boolean pour savoir si il est en dehors de sa livingHome, et l'amplitude de son speed.

class ObjectMotion: public LivingBeing
{
protected:
	QPointF mSpeed;
	QPointF mDestination;
	QPointF mNewPosition;
	bool mIsOutside;
	float mAmplitudeSpeed;

public:
	//fonction de base
	ObjectMotion(float lifeTime, QColor color, QPoint mSpeed, float amplitudeSpeed);
	virtual ~ObjectMotion() = default;
	ObjectMotion(ObjectMotion const&) = default;
	ObjectMotion& operator=(ObjectMotion const&) = default;

	//setter
	void setIsOutside(bool isOutside);

	//fonction utilitaire
	bool isCollidingScene() const;
	void moovingTo(QPointF & position);
};

#endif