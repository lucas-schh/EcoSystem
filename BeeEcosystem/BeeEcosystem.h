#pragma once
#ifndef BEE_ECOSYSTEM_H
#define BEE_ECOSYSTEM_H

#include <QtWidgets/QMainWindow>
#include "ui_BeeEcosystem.h"

#include "EcoSystem.h"
#include <QTimer>
#include "Tomato.h"
#include "Courgette.h"
#include "Aubergine.h"
#include "SwarmBees.h"
#include "SwarmAsianHornet.h"
#include "Bee.h"

class QGraphicsView;
class QControlBar;
class QParameters;
class QPushButton;



class BeeEcosystem : public QMainWindow
{
    Q_OBJECT

public:
    BeeEcosystem(QWidget *parent = Q_NULLPTR);
	~BeeEcosystem() = default;
	BeeEcosystem(BeeEcosystem const&) = delete;
	BeeEcosystem& operator=(BeeEcosystem const&) = delete;

private:
    Ui::BeeEcosystemClass ui;

	EcoSystem mGraphicsScene;
	QGraphicsView* mSimulationView;
	QParameters* mParameters;
	QControlBar* mControlBar;
	QPushButton* mAboutButton;

	QTimer mTimer;

private slots:
	void startSimulation();
	void stepSimulation();
	void pauseSimulation();
	void resumeSimulation();
	void stopSimulation();

	void advance();

	void about();

private:
	// Litéraux et variables symboliques utilisés
	static QSize	const sSceneSize;				// Taille de la scène
	static size_t	const sMaxNbrOfItems;			// Nombre maximum de flèche
	static QString	const sAboutButtonText;			// Text du bouton "À propos"
	static QString	const sAboutText;				// Text pour la boîte à propos
	static QString	const sControlStartText;		// Textes pour les contrôles
	static QString	const sControlStopText;			//    "
	static QString	const sControlPauseText;		//    "
	static QString	const sControlResumeText;		//    "
	static QString	const sControlStepText;			//    "
	static QColor	const sSceneBackgroundColor;	// Couleurs utilisées
	static QColor	const sControlRunningColor;		//    "
	static QColor	const sControlPauseColor;		//    "
	static QColor	const sControlStoppedColor;		//    "
	static QColor	const sControlNotReadyColor;	//    "
};

#endif