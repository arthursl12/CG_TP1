#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject {
    public:
        virtual void draw() = 0;
        virtual bool collides(GameObject& obj);
    protected:
        float x, y;
        float height, width;
};

#endif /* GAME_OBJECT_H */