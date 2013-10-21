#ifndef TESTWORLD_HPP
#define TESTWORLD_HPP
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include "AssetContainer.hpp"
#include "GameWorld.hpp"
#include "Player.hpp"
class TestWorld : public GameWorld
{
private:
	Player *player;
	AssetContainer *ac;
public:
	TestWorld();
	~TestWorld();
	void input(sf::Event &event);
	void draw(sf::RenderWindow &rwin, float interp);
	void update(float dt);
};
#endif