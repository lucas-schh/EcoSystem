#include "QParameters.h"


#include <QSpinBox>
#include <QFormLayout>
#include <QtMath>


QParameters::QParameters(size_t maxItems, QWidget* parent)
	: QWidget(parent),
	mNbrOfBee{ new QSpinBox },
	mNbrOfAsianHornet { new QSpinBox },
	mNbrOfHuman {new QSpinBox},
	mNbrOfFloweringPlant {new QSpinBox},
	mElapsedTime{new QDoubleSpinBox}
{
	const size_t minMaxNbrBees{ 50 };

	mNbrOfBee->setRange(1, qMax(static_cast<size_t>(minMaxNbrBees), maxItems));
	mNbrOfBee->setValue(minMaxNbrBees);

	QFormLayout* beeLayout{ new QFormLayout };
	beeLayout->addRow("Nombre de Bee ", mNbrOfBee);

	const size_t minMaxNbrAsianHornets{ 15 };

	mNbrOfAsianHornet->setRange(1, qMax(static_cast<size_t>(minMaxNbrAsianHornets), maxItems));
	mNbrOfAsianHornet->setValue(minMaxNbrAsianHornets);

	QFormLayout* asianHornetLayout{ new QFormLayout };
	asianHornetLayout->addRow("Nombre de AsianHornet ", mNbrOfAsianHornet);

	const size_t minMaxNbrHuman{ 4 };

	mNbrOfHuman->setRange(1, qMax(static_cast<size_t>(minMaxNbrHuman), maxItems));
	mNbrOfHuman->setValue(minMaxNbrHuman);

	QFormLayout* humanLayout{ new QFormLayout };
	humanLayout->addRow("Nombre de Human ", mNbrOfHuman);

	const size_t minMaxNbrFloweringPlant{ 15 };

	mNbrOfFloweringPlant->setRange(1, qMax(static_cast<size_t>(minMaxNbrFloweringPlant), maxItems));
	mNbrOfFloweringPlant->setValue(minMaxNbrFloweringPlant);

	QFormLayout* floweringPlantLayout{ new QFormLayout };
	floweringPlantLayout->addRow("Nombre de FloweringPlant ", mNbrOfFloweringPlant);

	const float minMaxElapsedTime{ 0.03 };

	mElapsedTime->setRange(0.0f, qMax(static_cast<float>(minMaxElapsedTime), 5.0f));
	mElapsedTime->setDecimals(2);
	mElapsedTime->setSingleStep(0.01);
	mElapsedTime->setValue(minMaxElapsedTime);

	QFormLayout* elapsedTimeLayout{ new QFormLayout };
	elapsedTimeLayout->addRow("Temps écoulé entre chaque pas de la simulation en seconde ", mElapsedTime);

	QVBoxLayout* layout{ new QVBoxLayout };
	layout->addLayout(beeLayout);
	layout->addLayout(asianHornetLayout);
	layout->addLayout(humanLayout);
	layout->addLayout(floweringPlantLayout);
	layout->addLayout(elapsedTimeLayout);
	setLayout(layout);
}

size_t QParameters::nbrOfBee() const
{
	return static_cast<size_t>(mNbrOfBee->value());
}

size_t QParameters::nbrOfAsianHornet() const
{
	return static_cast<size_t>(mNbrOfAsianHornet->value());
}

size_t QParameters::nbrOfHuman() const
{
	return static_cast<size_t>(mNbrOfHuman->value());
}

size_t QParameters::nbrOfFloweringPlant() const
{
	return static_cast<size_t>(mNbrOfFloweringPlant->value());
}

float QParameters::elapsedTime() const
{
	return static_cast<float>(mElapsedTime->value());
}
