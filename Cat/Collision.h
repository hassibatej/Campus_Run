#ifndef COLLISION
#define COLLISION
#include <SFML/Graphics.hpp>

class Collision
{
public:
    Collision(sf::RectangleShape& body);
    ~Collision();

    //this is done so that we dont need to make body a public function
    void Move(float dx, float dy) {body.move(dx, dy);}

    bool CheckCollision(Collision& other, float push); // Push decides how much the object needs to be pushed out e.g. if push = 0 (i.e. player can’t move through wall), if push = 1 (i.e. player can push crate object away)

    // get position of other inside the collision function
    sf::Vector2f GetPosition() {return body.getPosition();}

    //halfsize is the distance from centre to corner
    sf::Vector2f GetHalfSize() {return body.getSize() / 2.0f;}

private:
    //storing the body in collision to be able to modify it
    sf::RectangleShape& body;
};

#endif

