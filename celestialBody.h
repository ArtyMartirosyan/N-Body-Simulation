#pragma once
#define WINSIZE 512
//#define G {6.67e-11}

#include <iostream>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

using namespace std;


class  CelestialBody : public sf::Drawable
{
public:
    CelestialBody();
    CelestialBody(double&, double&, double&, double&, double&, string);
    ~CelestialBody();

    void setRadius(double);
    
    double getXpos();
    void setXpos(double);
    double getYpos();
    void setYpos(double);
    double getXvel();
    void setXvel(double);
    double getYvel();
    void setYvel(double);
    double getMass();
    void setMass(double);

    sf::Sprite sprite;
    sf::Texture texture;
    friend istream &operator>>(istream &input, shared_ptr<CelestialBody> arg);
    friend ostream &operator<<(ostream &output, shared_ptr<CelestialBody> arg);
private:
    double xpos, ypos;
    double xvel, yvel;
    double mass;
    double universeRadius;
    string fileName;
    void draw(sf::RenderTarget&, sf::RenderStates) const;
};
