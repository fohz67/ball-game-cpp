#pragma once

class FloatRect2
{
   public:
    FloatRect2() : left(0), top(0), width(0), height(0)
    {
    }
    FloatRect2(float l, float t, float w, float h) : left(l), top(t), width(w), height(h)
    {
    }

    bool contains(float x, float y) const
    {
        return (x >= left && x <= left + width && y >= top && y <= top + height);
    }

    float left;
    float top;
    float width;
    float height;
};
