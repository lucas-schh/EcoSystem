#ifndef Q_PARAMETERS_H
#define Q_PARAMETERS_H


#include <QWidget>
#include <QDoubleSpinBox>

class QSpinBox;


class QParameters : public QWidget
{
	Q_OBJECT

public:
	QParameters(size_t maxItems = 250, QWidget* parent = nullptr);

	size_t nbrOfBee() const;
	size_t nbrOfAsianHornet() const;
	size_t nbrOfHuman() const;
	size_t nbrOfFloweringPlant() const;
	float elapsedTime() const;

protected:
	QSpinBox* mNbrOfBee;
	QSpinBox* mNbrOfAsianHornet;
	QSpinBox* mNbrOfHuman;
	QSpinBox* mNbrOfFloweringPlant;
	QDoubleSpinBox* mElapsedTime;
};


#endif // Q_PARAMETERS_H