//Fichier : EcoSystem.h
//GPA434 - Laboratoire 3
//Cr�ation :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef ECO_SYSTEM_H
#define ECO_SYSTEM_H

#include "QGraphicsScene.h"
#include "Human.h"

//Repr�sente notre sc�ne � laquelle on a ajout� certaine fonction utilitaire.
//Ces fonctions sont celle qui ont besoin d'acc�der aux les �l�ments de la sc�ne ou d'agir sur les �l�ments de la sc�ne.

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
	void toSting(Human& human, const SwarmAsianHornet& swarmAsianHornet) const; //inflige des d�g�ts � l'humain en fonction du nombre de AsianHornet
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