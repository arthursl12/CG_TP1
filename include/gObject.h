#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject {
    public:
        virtual void draw() = 0;
    protected:
        float x, y;
};

#endif /* GAME_OBJECT_H */