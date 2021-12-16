#include <Collision.h>

//using AABB collision detection

Collision::Collision(sf::RectangleShape& body): body(body)
{
}

Collision::~Collision()
{
}

bool Collision::CheckCollision(Collision & other, float push)
{
    //get position of body and other
    sf::Vector2f otherPosition= other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition= GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    //intersection calculation
    float intersectX = abs(deltaX) - (otherHalfSize.x - thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y - thisHalfSize.y);

    if (intersectX < 0.f && intersectY < 0.0f) //are we colliding with something?
    {
        push = std:: min(std::max(push, 0.0f), 1.0f); //clamping the push position between 0 and 1

        if (intersectX > intersectY) //takes the smallest intersection (between x and y)
        {
            if (deltaX > 0.0f)
            {
                Move(intersectX * (1.0f - push), 0.0f);
                other.Move(-intersectX*push, 0.0f);
            }
            else
            {
                Move(-intersectX * (1.0f - push), 0.0f);
                other.Move(intersectX*push, 0.0f);
            }
        }
        else
        {
            if (deltaY > 0.0f)
            {
                Move(0.0f, intersectY * (1.0f - push));
                other.Move(0.0f,-intersectY*push);
            }
            else
            {
                Move(0.0f, -intersectY * (1.0f - push));
                other.Move(0.0f, intersectY*push);
            }
        }
        return true;
    }
    return false;
}
