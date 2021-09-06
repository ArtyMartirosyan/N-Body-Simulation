#include "celestialBody.h"

CelestialBody::CelestialBody()
{
    xpos = 0;
    ypos = 0;
    xvel = 0;
    yvel = 0;
    mass = 0;

}
CelestialBody::CelestialBody(double& newXpos, double& newYpos, double& newXvel, double& newYvel, double& newMass, string image)
{
    xpos = newXpos;
    ypos = newYpos;
    xvel = newXvel;
    yvel = newYvel;
    mass = newMass;

    texture.loadFromFile(image);
    sprite.setTexture(texture);
}


CelestialBody::~CelestialBody()
{
    
}

void CelestialBody::setRadius(double r)
{
    universeRadius = r;
}

double CelestialBody::getXpos()
{
    return xpos;
}
void CelestialBody::setXpos(double x)
{
    xpos = x;
}
double CelestialBody::getYpos()
{
    return ypos;
}
void CelestialBody::setYpos(double y)
{
    ypos = y;
}
double CelestialBody::getXvel()
{
    return xvel;
}
void CelestialBody::setXvel(double xAcc)
{
    xvel += xAcc;
}
double CelestialBody::getYvel()
{
    return yvel;
}
void CelestialBody::setYvel(double yAcc)
{
    yvel += yAcc;
}
double CelestialBody::getMass()
{
    return mass;
}
void CelestialBody::setMass(double m)
{
    mass = m;
}
void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Sprite drawSprite = sprite;  
    double r = (WINSIZE / 2) / universeRadius;
    double rx = xpos * r + (WINSIZE / 2);
    double ry = ypos * r + (WINSIZE / 2);

    //cout << r << ", " << rx << ", " << ry << endl;
  
    drawSprite.setPosition(rx, ry);
  
    target.draw(drawSprite);
}

istream &operator>>(istream &input, shared_ptr<CelestialBody> arg)
{
    string fname;
    double v;
    input >> v;
    arg->setXpos(v);
    
    input >> v;
    arg->setYpos(v);

    input >> v;
    arg->setXvel(v);

    input >> v;
    arg->setYvel(v);

    input >> v;
    arg->setMass(v);

    input >> fname;
    arg->fileName = fname;

    arg->texture.loadFromFile(fname);
    arg->sprite.setTexture(arg->texture);

    return input;
}

ostream &operator<<(ostream &out, shared_ptr<CelestialBody> arg)
{
    out << arg->fileName << " ";
    out << arg->getXpos() << " ";
    out << arg->getYpos() << " ";
    out << arg->getXvel() << " ";
    out << arg->getYvel() << " ";
    out << arg->getMass();

    return out;
}