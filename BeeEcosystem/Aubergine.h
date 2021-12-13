//Fichier : Aubergine.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021

#pragma once
#ifndef AUBERGINE_H
#define AUBERGINE_H

#include "FloweringPlant.h"
#include "Random.h"

//Représente une aubergine, qui redonne de la vie à un humain lorsqu'il la mange.
//Pour plus d'info : regarder la doc de FloweringPlant

class Aubergine : public FloweringPlant
{
public:
	//fonction de base
	Aubergine();
	~Aubergine() override = default;
	Aubergine(Aubergine const&) = default;
	Aubergine& operator=(Aubergine const&) = default;

	//fonction override
	int lifeRecovery(int life) const override;
};

#endif