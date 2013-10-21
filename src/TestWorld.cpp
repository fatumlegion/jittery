#include "TestWorld.hpp"
#include <stdio.h>

TestWorld::TestWorld()
{	
	ac = new AssetContainer();
	ac->addTexture("player", "res/images/player.png");

	player = new Player();
	player->setAnimationProfile(0, *ac->getTexture("player"));
	player->setPosition(100, 550);
}

TestWorld::~TestWorld()
{
	delete ac;
	delete player;
}

void TestWorld::input(sf::Event &event)
{
	player->input(event);
}

void TestWorld::draw(sf::RenderWindow &rwin, float interp)
{
	player->draw(rwin, interp);
}

void TestWorld::update(float dt)
{
	player->update(dt);
}