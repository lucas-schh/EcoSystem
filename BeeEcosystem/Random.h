//Fichier : Random.h
//GPA434 - Laboratoire 3
//Cr�ation :
//	-Lucas Schwing - SCHL88030007
//	-Axel Coulon - COUA73100008
//	-09/12/2021
#pragma once
#ifndef RANDOM_H
#define RANDOM_H

#include "qpoint.h"
#include "FloweringPlant.h"

//Cette classe utilitaire poss�de toutes les fonctions n�cessaire pour g�n�rer de l'al�atoire.

class Random
{
public:
	Random() = delete;
	Random(Random const&) = delete;
	Random& operator=(Random const&) = delete;
	~Random() = delete;

	static float generate(); // entre 0.0 et 1.0
	static int generate(int min, int max);
	static float generate(float min, float max);
	static double generate(double min, double max);
	static QPoint randomPointOnCircle(float radius);
	static QColor randomHumanSkinColor();
	static QString randomHumanName();
};

#endif