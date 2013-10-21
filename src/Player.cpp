#include "Player.hpp"

Player::Player()
{
	right = false;
	left = false;

	speed = 0.5f;
	xs = 0.0f;
	fric = 1.1f;

	pos = sf::Vector2f(180, 410);	
	self.setPosition(pos);
}

void Player::setAnimationProfile(int profile, sf::Texture &txtr)
{
	self.setTexture(txtr);
	//handle animation init here
	self.setOrigin(self.getTextureRect().width / 2, self.getTextureRect().height);
}

void Player::input(sf::Event &event)
{
	switch (event.type)
	{
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
				case sf::Keyboard::Right:
					right = true;
				break;
				case sf::Keyboard::Left:
					left = true;
				break;
			}
		break;
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
				case sf::Keyboard::Right:
					right = false;
				break;
				case sf::Keyboard::Left:
					left = false;
				break;
			}
		break;
	}
}

float Player::clamp(float x, float a, float b)
{
	return x < a ? a : (x > b ? b : x);
}

void Player::draw(sf::RenderWindow &rwin, float interp)
{
	rwin.draw(self);

	sf::Vector2f posInterp = pos;
	if (pos.x != lastPos.x)
		posInterp.x += interp;
	if (pos.y != lastPos.y)
		posInterp.y += interp;
	self.setPosition(posInterp);	
	lastPos = pos;	
}

void Player::update(float dt)
{	
	if (right == true && left == false)
	{
		xs += speed;
	}
	
	if (right == false && left == true)
	{
		xs -= speed;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		right = false;
		left = false;
	}
	
	pos.x += clamp(xs, -6, 6);
	xs /= fric;
}