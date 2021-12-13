#include "Courgette.h"

Courgette::Courgette()
    :FloweringPlant(QColor(0, 255, 0), 20)
{
}

int Courgette::lifeRecovery(int life) const
{
    return life + mLifeRecovery;
}