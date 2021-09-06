#include "universe.h"
#include <iostream>

Universe::Universe()
{
    string input;

    getline(cin, input);
    numPlanets = atoi(input.c_str());

    getline(cin, input);
    double universeRad = atof(input.c_str());
    
    for(int i=0; i < numPlanets; i++)
    {
        shared_ptr<CelestialBody> cbody(new CelestialBody());
        cbody->setRadius(universeRad);
        cin >> cbody;
        solarSystem.push_back(cbody);
    }
}


int Universe::getNumPlanets()
{
    return numPlanets;
}

void Universe::step(double time, shared_ptr<CelestialBody> obj)
{
    obj->setXpos(obj->getXpos() - time * obj->getXvel());
    obj->setYpos(obj->getYpos() - time * obj->getYvel());
}



