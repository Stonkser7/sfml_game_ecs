
#include <SFML/Graphics.hpp>



int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "ECS TEST");

	sf::RectangleShape shape(sf::Vector2f(500, 300));
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y / 2.f);
	shape.setFillColor(sf::Color::Cyan);
	shape.setOutlineColor(sf::Color::Magenta);
	shape.setOutlineThickness(-1);
	shape.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();

		window.draw(shape);

		window.display();
	}
}