#include <iostream>
#include <SFML/Graphics.hpp>

#define SPEED 10
int main()
{
  sf::RenderWindow window(sf::VideoMode(), "SFML Works!", sf::Style::Fullscreen);
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  int x_inc = SPEED;
  int y_inc = -SPEED;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:
        if ((event.key.control) &&
            (event.key.code == sf::Keyboard::Q)) {
          window.close();
        }
        break;
      }
    }
          // update the position
    auto shape_pos = shape.getPosition();
    auto window_size = window.getSize();


    if (shape_pos.x > window_size.x) {
      x_inc = -SPEED;
    } else if (shape_pos.x < 0) {
      x_inc = SPEED;
    }

    if (shape_pos.y > window_size.y) {
      y_inc = -SPEED;
    } else if (shape_pos.y < 0) {
      y_inc = SPEED;
    }

    
    shape.setPosition(shape_pos.x + x_inc, shape_pos.y + y_inc);

    window.clear();
    window.draw(shape);
    window.display();

  }
  return 0;
}
