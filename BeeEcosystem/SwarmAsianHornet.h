//Fichier : SwarmAsianHornet.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef SWARMASIANHORNET_H
#define SWARMASIANHORNET_H

#include "Swarm.h"

//Cette classe représente un essaim de frelons asiatique. Elle hérite de Swarm, et intégre les fonctions virtual de LivingHome, puisque birth dans un 
//essaim de frelons doit uniquement créer des frelons.

class SwarmAsianHornet : public Swarm
{
public:
	//fonction de base
	SwarmAsianHornet();
	~SwarmAsianHornet() override = default;
	SwarmAsianHornet(SwarmAsianHornet const&) = default;
	SwarmAsianHornet& operator=(SwarmAsianHornet const&) = default;

	//fonction override
	void birth() override;
	void initPos() override;
};

#endif