#pragma once

class BoxColider
{
public:
    BoxColider() : x1(0), y1(0), x2(0), y2(0) {}

    void Update();

    bool CheckOverlap(const BoxColider& other) const
    {
        // Return true when rectangles overlap
        if (x2 < other.x1) return false;
        if (x1 > other.x2) return false;
        if (y2 < other.y1) return false;
        if (y1 > other.y2) return false;
        return true;
    }

    int x1;
    int y1;
    int x2;
    int y2;
};
