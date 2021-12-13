#include "BeeEcosystem.h"


#include <QRandomGenerator>
#include <QGraphicsView>
#include "QControlBar.h"
#include "QParameters.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>


size_t	const BeeEcosystem::sMaxNbrOfItems{ 1000 };
QSize	const BeeEcosystem::sSceneSize(500, 400);
QColor	const BeeEcosystem::sSceneBackgroundColor(QColor::fromHsl(215, 80, 222));
QString	const BeeEcosystem::sControlStartText("Démarrer la simulation");
QString	const BeeEcosystem::sControlStopText("Terminer la simulation");
QString	const BeeEcosystem::sControlPauseText("Mettre la simulation sur pause");
QString	const BeeEcosystem::sControlResumeText("Reprendre la simulation");
QString	const BeeEcosystem::sControlStepText("Faire un pas de simulation");
QColor	const BeeEcosystem::sControlRunningColor(0, 255, 0);
QColor	const BeeEcosystem::sControlPauseColor(255, 196, 0);
QColor	const BeeEcosystem::sControlStoppedColor(255, 0, 0);
QColor	const BeeEcosystem::sControlNotReadyColor(230, 230, 230);

const QString BeeEcosystem::sAboutButtonText("À propos...");
const QString BeeEcosystem::sAboutText(
    R"..(GPA434 
Ingénierie des systèmes orientés objets

Laboratoire  3
Simulation d'un écosystème 

Ce projet consiste à ...

Réalisé par :
   - Étudiant 1
   - Étudiant 2
   - ...
)..");


BeeEcosystem::BeeEcosystem(QWidget *parent)
    : QMainWindow(parent)
    , mSimulationView{ new QGraphicsView(&mGraphicsScene) }
    , mParameters{ new QParameters(sMaxNbrOfItems) }
    , mControlBar{ new QControlBar(Qt::Vertical) }
    , mAboutButton{ new QPushButton(sAboutButtonText) }
{
	setWindowTitle("Startup project demo");
	setWindowIcon(QIcon(":/StartUpProjectDemo/icon"));

	ui.setupUi(this);

	mControlBar->setReady();
	mControlBar->setActionText(QControlBar::Action::Start, sControlStartText);
	mControlBar->setActionText(QControlBar::Action::Stop, sControlStopText);
	mControlBar->setActionText(QControlBar::Action::Pause, sControlPauseText);
	mControlBar->setActionText(QControlBar::Action::Resume, sControlResumeText);
	mControlBar->setActionText(QControlBar::Action::Step, sControlStepText);
	mControlBar->setStateColor(QControlBar::State::NotReady, sControlNotReadyColor);
	mControlBar->setStateColor(QControlBar::State::Paused, sControlPauseColor);
	mControlBar->setStateColor(QControlBar::State::Running, sControlRunningColor);
	mControlBar->setStateColor(QControlBar::State::Stopped, sControlStoppedColor);

	mGraphicsScene.setSceneRect(-sSceneSize.width() / 2, -sSceneSize.height() / 2, sSceneSize.width(), sSceneSize.height());

	QWidget* controlWidget{ new QWidget };
	QVBoxLayout* controlLayout{ new QVBoxLayout };
	controlWidget->setLayout(controlLayout);
	controlLayout->addWidget(mParameters);
	controlLayout->addStretch();
	controlLayout->addWidget(mControlBar);
	controlLayout->addWidget(mAboutButton);

	QWidget* centralWidget{ new QWidget };
	QHBoxLayout* centralLayout{ new QHBoxLayout };
	centralWidget->setLayout(centralLayout);

	centralLayout->addWidget(mSimulationView);
	centralLayout->addWidget(controlWidget);

	setCentralWidget(centralWidget);

	connect(mControlBar, &QControlBar::started, this, &BeeEcosystem::startSimulation);
	connect(mControlBar, &QControlBar::stopped, this, &BeeEcosystem::stopSimulation);
	connect(mControlBar, &QControlBar::paused, this, &BeeEcosystem::pauseSimulation);
	connect(mControlBar, &QControlBar::resumed, this, &BeeEcosystem::resumeSimulation);
	connect(mControlBar, &QControlBar::stepped, this, &BeeEcosystem::stepSimulation);

	connect(&mTimer, &QTimer::timeout, this, &BeeEcosystem::advance);

	connect(mAboutButton, &QPushButton::clicked, this, &BeeEcosystem::about);
}

void BeeEcosystem::advance()
{
	mGraphicsScene.advance();

	for (auto& item : mGraphicsScene.items()) {
		LivingBeing* myLB{ dynamic_cast<LivingBeing*>(item) };
		if (myLB && !myLB->isAlive()) {
			mGraphicsScene.removeItem(myLB);
			delete myLB;
		}


	}
}

void BeeEcosystem::startSimulation()
{
	// Vide la scène pour démarrer une nouvelle démo
	mGraphicsScene.clear();

	// Met un item rectangulaire pour bien voir les limites de la scène
	QGraphicsRectItem* background{ new QGraphicsRectItem(mGraphicsScene.sceneRect()) };
	background->setPen(Qt::NoPen);
	background->setBrush(sSceneBackgroundColor);
	mGraphicsScene.addItem(background);


	// Ajoute les éléments
	SwarmBees* swarmBees = new SwarmBees();
	SwarmAsianHornet* swarmAsianHornet = new SwarmAsianHornet();
	Home* home = new Home();
	mGraphicsScene.addItem(swarmBees);
	mGraphicsScene.addItem(swarmAsianHornet);
	mGraphicsScene.addItem(home);
	for (int i{ 0 }; i < mParameters->nbrOfBee(); ++i) {
		swarmBees->birth();
	}

	for (int i{ 0 }; i < mParameters->nbrOfAsianHornet(); ++i) {
		swarmAsianHornet->birth();
	}

	for (int i{ 0 }; i < mParameters->nbrOfFloweringPlant(); ++i) {
		int aux = FloweringPlant::chooseTypeOfFloweringPlant();
		
		if(aux ==1) mGraphicsScene.addItem(new Tomato());
		else if(aux ==2) mGraphicsScene.addItem(new Courgette());
		else if(aux ==3) mGraphicsScene.addItem(new Aubergine());
	}
	
	for (int i{ 0 }; i < mParameters->nbrOfHuman(); ++i) {
		home->birth();
	}


	//Place les éléments à leur position initiale
	//place en premier les LivingHome, car la position initiale des LivingBeings depend de la position de leur livingHome
	for (auto& item : mGraphicsScene.items()) {
		LivingHome* livinghome{ dynamic_cast<LivingHome*>(item) };
		if (livinghome) livinghome->initPos();
	}
	
	for (auto& item : mGraphicsScene.items()) {
		
		LivingBeing* livingBeing{ dynamic_cast<LivingBeing*>(item) };
		if (livingBeing) livingBeing->initPos();
	}

	EcoSystem::setElapsedTime(mParameters->elapsedTime());

	// Démarre la simulation
	mTimer.start(EcoSystem::elapsedTime()*1000); //En milliseconde

	mParameters->setEnabled(false);
}

void BeeEcosystem::stepSimulation()
{
	mGraphicsScene.advance();
}

void BeeEcosystem::pauseSimulation()
{
	mTimer.stop();
}

void BeeEcosystem::resumeSimulation()
{
	mTimer.start(EcoSystem::elapsedTime() * 1000);
}

void BeeEcosystem::stopSimulation()
{
	mTimer.stop();
	mParameters->setEnabled(true);
}

void BeeEcosystem::about()
{
	QMessageBox::about(this, "À propos...", sAboutText);
}