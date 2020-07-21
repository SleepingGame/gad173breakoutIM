#include "example.h"

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{

	m_catmyaw = kage::TextureManager::getSprite("data/cat.png");
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	
	for (size_t i = 0; i < 21; i++)
	{
		line[i] = sf::RectangleShape(sf::Vector2f(5, 375));
		line[i].setPosition(sf::Vector2f(100 + i * 75, 100));
		line[i].setFillColor(sf::Color::Green);
	}
	for (size_t i = 0; i < 6; i++)
	{
		line2[i] = sf::RectangleShape(sf::Vector2f(1500, 5));
		line2[i].setPosition(sf::Vector2f(100, 100 + i * 75));
		line2[i].setFillColor(sf::Color::Green);
	}

	m_catmyaw->setPosition(sf::Vector2f(100, 100));

	return true;
}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}
	
	sf::Vector2f mousePosition = (sf::Vector2f)sf::Mouse::getPosition(m_window);
	std::cout << "Mouse Position X - " << mousePosition.x << " | " << "Mouse Position Y - " << mousePosition.y <<std::endl;
	m_catmyaw->setPosition(mousePosition.x, mousePosition.y);

	ImGui::Begin("Kittie2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::Image(*m_catmyaw);
	ImGui::End();



}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	for (size_t i = 0; i < 21; i++)
	{
		m_window.draw(line[i]);
	}	
	for (size_t i = 0; i < 6; i++)
	{
		m_window.draw(line2[i]);
	}
	m_window.draw(*m_catmyaw);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

