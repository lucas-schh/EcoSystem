//Fichier : ForagingInsect.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef FOREGINGINSECT_H
#define FOREGINGINSECT_H

#include "ObjectMotion.h"
#include "Swarm.h"
#include "Random.h"

//Représente un insecte butineur, elle permet de regrouper les attributs en commun des insectes butineurs afin de faciliter la réutilisation
//du code orienté objet, comme l'ajout d'autre type d'insecte butineur.

class ForagingInsect : public ObjectMotion
{
protected:
	Swarm* mSwarm;
	int mNbrOfBirth;
public:
	//fonction de base
	ForagingInsect(QColor color, Swarm *swarm);
	virtual ~ForagingInsect() = default;
	ForagingInsect(ForagingInsect const&) = default;
	ForagingInsect& operator=(ForagingInsect const&) = default;

	//accesseur
	Swarm* swarm() const;

};

#endif