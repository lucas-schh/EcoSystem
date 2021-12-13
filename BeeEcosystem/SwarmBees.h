//Fichier : SwarmBees.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef SWARMBEES_H
#define SWARMBEES_H

#include "Swarm.h"

//Cette classe hérite de la classe Swarm et possède deux fonctions : birth() et initPos().Birth permet de creer une nouvelle Bee,
//de l'ajouter à la scène() et au vecteur mLivingBeings. InitPos permet de placer le SwarmBees

class SwarmBees : public Swarm
{
public:
	//fonction de base
	SwarmBees();
	~SwarmBees() override = default;
	SwarmBees(SwarmBees const&) = default;
	SwarmBees& operator=(SwarmBees const&) = default;

	//fonction override
	void birth() override;
	void initPos() override;
};

#endif