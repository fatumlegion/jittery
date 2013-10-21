#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/Clock.hpp>
#include "GameWorld.hpp"
#include <stack>
class Application
{
private:
	float dt, timeNow, timeFrame, timeActual, accumulator;
	bool parseArguments(int argc, char **argv);
	bool doForceFPS, enableVSync;
	
	std::stack<GameWorld*> cont_worlds;
	
	static Application *m_App;
	
	sf::VideoMode videoMode;
	sf::RenderWindow rwin;
	sf::Clock gameClock;
	int forceFPS;
public:	
	sf::RenderWindow &getRenderWindow() { return this->rwin; }
	sf::VideoMode &getVideoMode() { return this->videoMode; }
	
	static Application *getSingleton();
	
	void pushWorld(GameWorld *world);
	void popAllWorlds();
	void popWorld();
	
	int run(int argc, char **argv);
	void initialize();
	void release();
};
#endif