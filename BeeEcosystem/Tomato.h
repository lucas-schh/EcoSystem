//Fichier : Tomato.h
//GPA434 - Laboratoire 3
//Cr�ation :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef TOMATO_H
#define TOMATO_H

#include "FloweringPlant.h"

//Cette classe h�rite de la classe FloweringPlant, elle n'a qu'une seule fonction qui permet de generer un nombre aleatoire
//selon le parametre life et son attribut membre mLifeRecovery,
//c'est �galement  dans cette classe qu'on d�finit la couleur de la plante � fleur et l'attribut mLifeRecovery

class Tomato : public FloweringPlant
{

public:
	//fonction de base
	Tomato();
	~Tomato() override = default;
	Tomato(Tomato const&) = default;
	Tomato& operator=(Tomato const&) = default;

	//fonction override
	int lifeRecovery(int life) const override;
};

#endif