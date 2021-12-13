#include "EcoSystem.h"
#include <vector>
#include "Random.h"
#include "AsianHornet.h"

float EcoSystem::sElapsedTime{ 0.03 };

float EcoSystem::elapsedTime()
{
    return sElapsedTime;
}

float EcoSystem::setElapsedTime(float elapsedTime)
{
    return sElapsedTime = elapsedTime;
}

FloweringPlant* EcoSystem::randomFloweringPlant() const
{
    std::vector<FloweringPlant*> allFloweringPlant;
    for (auto item : items()) {
        FloweringPlant* floweringPlant = dynamic_cast<FloweringPlant*>(item);
        if (floweringPlant) allFloweringPlant.push_back(floweringPlant);
    }
    if (allFloweringPlant.size() != 0) {
        int randomFloweringPlant = Random::generate(0, allFloweringPlant.size() - 1);
        FloweringPlant* floweringPlantSelected = allFloweringPlant[randomFloweringPlant];
        return floweringPlantSelected;
    }
    else return nullptr;
}

void EcoSystem::toSting(Human& human, const SwarmAsianHornet& swarmAsianHornet) const
{
    int damage = swarmAsianHornet.livingBeing().size() * 2;
    if ((human.life() - damage) <= 0) setAllGoKillAsianHornetToNull(); //gère le cas où les AsianHornet tue l'humain avant qu'il rentre à la Home
    human.setLife(human.life() - damage);
}

void EcoSystem::sendHumanKillAsianHornet(Human* myHuman) const
{
    for (auto item : items()) {
        Human* human = dynamic_cast<Human*>(item);
        if (human) {
            human->setGoKillAsianHornet(1);
        }
    }
    myHuman->setIsOutside(true);
    myHuman->setGoKillAsianHornet(2);
}

void EcoSystem::setAllGoKillAsianHornetToNull() const
{
    for (auto item : items()) {
        Human* human = dynamic_cast<Human*>(item);
        if (human) {
            human->setGoKillAsianHornet(0);
        }
    }
}

bool EcoSystem::allAsianHornetDead() const
{
    int nbrOfAsianHornet{};
    for (auto item : items()) {
        AsianHornet* asianHornet = dynamic_cast<AsianHornet*>(item);
        if (asianHornet) nbrOfAsianHornet++;
    }
    if (nbrOfAsianHornet == 0) {
        return true;
    }
    else return false;
}


void EcoSystem::killAsianHornet(SwarmAsianHornet* swarmAsianHornet) const
{
    int killAsianHornet{};
    if (swarmAsianHornet->livingBeing().size() <= 5) killAsianHornet = swarmAsianHornet->livingBeing().size();
    else killAsianHornet = swarmAsianHornet->livingBeing().size() * 0.3;
    for (auto asianHornet : swarmAsianHornet->livingBeing()) {
        AsianHornet* hornet = static_cast<AsianHornet*>(asianHornet);
        if (killAsianHornet > 0) {
            swarmAsianHornet->die(hornet);
            hornet->setAlive(false);
            killAsianHornet--;
        }
    }
}

bool EcoSystem::isEnoughFood() const
{
    int nbrOfFloweringPlant{};
    int nbrOfhuman{};
    for (auto item : items()) {
        FloweringPlant* floweringPlant = dynamic_cast<FloweringPlant*>(item);
        Human* human = dynamic_cast<Human*>(item);
        if (floweringPlant) nbrOfFloweringPlant++;
        if (human) nbrOfhuman++;
    }
    if (nbrOfFloweringPlant < nbrOfhuman * 2) return false;
    else return true;
}