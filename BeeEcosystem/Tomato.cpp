#include "Tomato.h"
#include "Random.h"


Tomato::Tomato()
    :
    FloweringPlant(QColor(255, 0, 0), 2)
{
}

int Tomato::lifeRecovery(int life) const
{
    return Random::generate(life + mLifeRecovery, life * mLifeRecovery);
}
