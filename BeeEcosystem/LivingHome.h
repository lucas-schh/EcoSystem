//Fichier : LivingHome.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef LIVINGHOME_H
#define LIVINGHOME_H

#include "QGraphicsItem.h"
#include "LivingBeing.h"
#include <vector>

//Cette classe abstraite représente un espace de vie. Elle est ainsi composé des attributs et fonctions de base nécessaire pour conteneur dans lequel
//les êtres vivants vivent.

class LivingHome : public QGraphicsItem
{
protected:
	std::vector<LivingBeing*> mLivingBeings;
	QRectF mForm;
	QColor mColor;

public:
	//fonction de base
	LivingHome(QRectF form, QColor color);
	virtual ~LivingHome() = default;
	LivingHome(LivingHome const&) = default;
	LivingHome& operator=(LivingHome const&) = default;

	//getter et setter
	std::vector<LivingBeing*> livingBeing() const;
	QRectF form() const;
	QColor color() const;

	//fonction utilitaire
	void die(LivingBeing* livingBeing); //enlève un element de son vector mLivingBeings

	//fonction virtuel pure
	virtual void birth() = 0;
	virtual void initPos() = 0;
};

#endif