#include <cmath>
#include <sstream>
#include <SFML/Audio.hpp>

#include "universe.h"



int main(int argc, char* argv[])
{
    double G = 6.67e-11;
   
    Universe obj;
    sf::RenderWindow window(sf::VideoMode (WINSIZE, WINSIZE), "Universe");
    
    //background
    sf::Texture texture;
    if(!texture.loadFromFile("starfield.jpg"))
        return -1;

    sf::Sprite sprite;
    sprite.setTexture(texture);

    //music
    sf::SoundBuffer Buffer;
    if (!Buffer.loadFromFile("Jörmungandr-HQ.wav"))
        return -1;

    sf::Sound Sound;
    Sound.setBuffer(Buffer);
    Sound.setVolume(50.f);

    //set font to display time
    sf::Font bebas;
    bebas.loadFromFile("BebasNeue-Regular.ttf");
    sf::Text timeDisplay("0.0", bebas);

    double totalTime = atof(argv[1]);
    double timeRate = atof(argv[2]);
    double time = 0.0;

    Sound.play();
    while(window.isOpen())
    {
        window.draw(sprite);
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
	        window.close();
        }

        
        
        vector<double> fX;
        vector<double> fY;

        for(unsigned i = 0; i < obj.solarSystem.size(); i++) {
            fX.push_back(0.0);
            fY.push_back(0.0);
        }

        for(unsigned i = 0; i < obj.solarSystem.size(); i++){
            for(unsigned a = 0; a < obj.solarSystem.size(); a++){
                if(i == a){
                    fX[i] += 0;
                    fY[i] += 0;
                }
                else{
                    double deltaX = obj.solarSystem[i]->getXpos() - obj.solarSystem[a]->getXpos();
                    double deltaY = obj.solarSystem[i]->getYpos() - obj.solarSystem[a]->getYpos();

                    double r = sqrt(deltaX*deltaX + deltaY*deltaY);

                    double F = (G * obj.solarSystem[a]->getMass() * obj.solarSystem[i]->getMass())/(r*r);
                    double Fx = F*(deltaX/r);
                    double Fy = F*(deltaY/r);

                    fX[i] += Fx;
                    fY[i] += Fy;
                }
               
            }
            
        }
        
        for(unsigned i = 0; i < obj.solarSystem.size(); i++)
        {
            double Ax = fX[i]/obj.solarSystem[i]->getMass();
            double Ay = fY[i]/obj.solarSystem[i]->getMass();

            obj.solarSystem[i]->setXvel(timeRate * Ax);
            obj.solarSystem[i]->setYvel(timeRate * Ay);

            obj.step(timeRate, obj.solarSystem[i]);
        }

        window.clear();
        window.draw(sprite);

        for(int i = 0; i < obj.getNumPlanets(); i++)
        {
            window.draw(*obj.solarSystem[i]);            
        }

        time += timeRate;
        if(time > totalTime)
        {
            window.close();
        }

        //draw time on window
        stringstream stream;
        stream << time;
        timeDisplay.setString(stream.str());
        window.draw(timeDisplay);

        window.display();
    }
    Sound.stop();

    for(unsigned i = 0; i < obj.solarSystem.size(); i++)
    {
        cout << obj.solarSystem[i];
        cout << endl;
    }
    return 0;
}