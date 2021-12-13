//Fichier : Courgette.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef COURGETTE_H
#define COURGETTE_H

#include "FloweringPlant.h"
#include "Random.h"

//Représente une courgette, qui redonne de la vie à un humain lorsqu'il la mange.
//Pour plus d'info : regarder la doc de FloweringPlant

class Courgette : public FloweringPlant
{
public:
	//fonction de base
	Courgette();
	~Courgette() override = default;
	Courgette(Courgette const&) = default;
	Courgette& operator=(Courgette const&) = default;

	//fonction override
	int lifeRecovery(int life) const override;
};

#endif