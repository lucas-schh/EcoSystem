//Fichier : Tomato.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef TOMATO_H
#define TOMATO_H

#include "FloweringPlant.h"

//Cette classe hérite de la classe FloweringPlant, elle n'a qu'une seule fonction qui permet de generer un nombre aleatoire
//selon le parametre life et son attribut membre mLifeRecovery,
//c'est également  dans cette classe qu'on définit la couleur de la plante à fleur et l'attribut mLifeRecovery

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