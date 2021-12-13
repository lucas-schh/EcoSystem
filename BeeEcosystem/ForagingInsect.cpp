#include "ForagingInsect.h"


ForagingInsect::ForagingInsect(QColor color, Swarm* swarm)
    : ObjectMotion(Random::generate(20, 40), color, Random::randomPointOnCircle(50), 50),
    mSwarm{swarm},
    mNbrOfBirth{ Random::generate(0,2) }
{
}

Swarm* ForagingInsect::swarm() const
{
    return mSwarm;
}
