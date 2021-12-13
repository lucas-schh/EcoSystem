#include "Random.h"

#include <random>
#include "EcoSystem.h"

float Random::generate()
{
    return (float)rand() / RAND_MAX;
}

int Random::generate(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

float Random::generate(float min, float max)
{
    return generate() * (max - min) + min;
}

double Random::generate(double min, double max)
{
    return generate() * (max - min) + min;
}

QPoint Random::randomPointOnCircle(float radius)
{
    return QPoint(cos(generate(-1.0f,1.0f))*radius, sin(generate(-1.0f, 1.0f))*radius);
}

QColor Random::randomHumanSkinColor()
{
    int aux = generate(1, 6);
    if (aux == 1) return QColor(197, 140, 133);
    else if (aux == 2) return QColor(236, 188, 180);
    else if (aux == 3) return QColor(209, 163, 164);
    else if (aux == 4) return QColor(161, 102, 94);
    else if (aux == 5) return QColor(80, 51, 53);
    else if (aux == 6) return QColor(89, 47, 42);
}

QString Random::randomHumanName()
{
    int aux = generate(1, 10);
    if (aux == 1) return QString("Ali");
    else if (aux == 2) return QString("Luc");
    else if (aux == 3) return QString("Chris");
    else if (aux == 4) return QString("Tanguy");
    else if (aux == 5) return QString("Rose");
    else if (aux == 6) return QString("Charly");
    else if (aux == 7) return QString("Jean");
    else if (aux == 8) return QString("Marie");
    else if (aux == 9) return QString("Léa");
    else if (aux == 10) return QString("Lou");
}