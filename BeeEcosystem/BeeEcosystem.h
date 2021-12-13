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
	// Lit�raux et variables symboliques utilis�s
	static QSize	const sSceneSize;				// Taille de la sc�ne
	static size_t	const sMaxNbrOfItems;			// Nombre maximum de fl�che
	static QString	const sAboutButtonText;			// Text du bouton "� propos"
	static QString	const sAboutText;				// Text pour la bo�te � propos
	static QString	const sControlStartText;		// Textes pour les contr�les
	static QString	const sControlStopText;			//    "
	static QString	const sControlPauseText;		//    "
	static QString	const sControlResumeText;		//    "
	static QString	const sControlStepText;			//    "
	static QColor	const sSceneBackgroundColor;	// Couleurs utilis�es
	static QColor	const sControlRunningColor;		//    "
	static QColor	const sControlPauseColor;		//    "
	static QColor	const sControlStoppedColor;		//    "
	static QColor	const sControlNotReadyColor;	//    "
};

#endif