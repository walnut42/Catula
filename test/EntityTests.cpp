//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "../Entity.h"

#include <gtest/gtest.h>

class TestEntity : public Entity {
public:
    TestEntity(ModelGame &modelGame, Image image, float x = 0, float y = 0) : Entity(modelGame, image, x, y) {};

    virtual void update() {}

    const sf::Vector2f &getSize() const {
        return size;
    }

    void setPos(float x, float y) {
        pos.x = x;
        pos.y = y;
    }

    void setAngle(float ang) {
        angle = ang;
    }
};

TEST(Entity, Collision) {
    ModelGame model;
    TestEntity a(model, Image::Laser, 30, 50);
    sf::Vector2f size = a.getSize();
    ASSERT_FLOAT_EQ(a.getPos().x, 30);
    ASSERT_FLOAT_EQ(a.getPos().y, 50);

    TestEntity b(model, Image::Laser, 30, 50 + size.y);
    ASSERT_TRUE(Entity::collide(&a, &b));
    b.setPos(30, 50 + size.y + 10);
    ASSERT_FALSE(Entity::collide(&a, &b));
    b.setAngle(20);
    ASSERT_FALSE(Entity::collide(&a, &b));
    a.setAngle(20);
    ASSERT_FALSE(Entity::collide(&a, &b));
    a.setAngle(80);
    ASSERT_TRUE(Entity::collide(&a, &b));

}