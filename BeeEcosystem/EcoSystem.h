//Fichier : EcoSystem.h
//GPA434 - Laboratoire 3
//Création :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef ECO_SYSTEM_H
#define ECO_SYSTEM_H

#include "QGraphicsScene.h"
#include "Human.h"

//Représente notre scène à laquelle on a ajouté certaine fonction utilitaire.
//Ces fonctions sont celle qui ont besoin d'accéder aux les éléments de la scène ou d'agir sur les éléments de la scène.

class EcoSystem : public QGraphicsScene
{
public:
	//fonction de base
	EcoSystem()=default;
	~EcoSystem() = default;
	EcoSystem(EcoSystem const&) = default;
	EcoSystem& operator=(EcoSystem const&) = default;

	//fonction utilitaire
	void killAsianHornet(SwarmAsianHornet* swarmAsianHornet) const;
	bool isEnoughFood() const;
	FloweringPlant* randomFloweringPlant() const;
	void toSting(Human& human, const SwarmAsianHornet& swarmAsianHornet) const; //inflige des dégâts à l'humain en fonction du nombre de AsianHornet
	void sendHumanKillAsianHornet(Human* human) const;
	void setAllGoKillAsianHornetToNull() const;
	bool allAsianHornetDead() const;

	//fonction statique
	static float elapsedTime();
	static float setElapsedTime(float elapsedTime);

	//variable statique
private:
	static float sElapsedTime;
};

#endif