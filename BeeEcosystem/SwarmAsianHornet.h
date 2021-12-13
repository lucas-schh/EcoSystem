//Fichier : SwarmAsianHornet.h
//GPA434 - Laboratoire 3
//Cr�ation :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef SWARMASIANHORNET_H
#define SWARMASIANHORNET_H

#include "Swarm.h"

//Cette classe repr�sente un essaim de frelons asiatique. Elle h�rite de Swarm, et int�gre les fonctions virtual de LivingHome, puisque birth dans un 
//essaim de frelons doit uniquement cr�er des frelons.

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