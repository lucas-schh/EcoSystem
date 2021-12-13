#include "Aubergine.h"


Aubergine::Aubergine()
    :FloweringPlant(QColor(55, 0, 40), 1.2)
{
}

int Aubergine::lifeRecovery(int life) const
{
    return life * mLifeRecovery;
}