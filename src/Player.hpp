#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Event.hpp>
class Player
{
private:
	sf::Vector2f pos, lastPos;
	float xs, fric, interp, speed;
	bool right, left;
	sf::Sprite self;

	sf::Vector2f posInterp;
	float clamp(float x, float a, float b);
public:
	Player();
	~Player() {}
	void input(sf::Event &event);
	void draw(sf::RenderWindow &rwin, float interp);
	void update(float dt);

	void setPosition(float x, float y) { pos.x = x; pos.y = y; }
	void setAnimationProfile(int profile, sf::Texture &txtr);

	const sf::Vector2f &getPosition() { return self.getPosition(); }
};
#endif