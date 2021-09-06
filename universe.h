#pragma once

#include <iostream>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "celestialBody.h"

using namespace std;



class Universe
{
public:    
    Universe();
    
    int getNumPlanets();
    void step(double, shared_ptr<CelestialBody>);
    vector<shared_ptr<CelestialBody>> solarSystem;
private:
    
    int numPlanets;
};


