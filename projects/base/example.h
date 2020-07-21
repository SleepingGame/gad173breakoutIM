#pragma once

#include "app.h"

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	sf::Sprite *m_backgroundSprite;
	sf::Sprite *m_catmyaw;
	sf::Sprite catsprite;
	sf::RectangleShape line[21];
	sf::RectangleShape line2[6];
};
