// ADS101 Algoritmer og Datastrukturer for spill 2020
// Dag Nylund, Høgskolen i Innlandet
#ifndef PLAINRECTANGLE_H
#define PLAINRECTANGLE_H

#include <vector>

struct Vector2d {
    double x;
    double y;
    Vector2d operator + (const Vector2d& v) const
    {
            Vector2d u;
            u.x = x + v.x;
            u.y = y + v.y;
            return u;
    }
    Vector2d operator / (int d)
    {
        Vector2d u;
        u.x = x/2;
        u.y = y/2;
        return u;
    }
};

class PlainRectangle
{
private:
    Vector2d m_v1;
    Vector2d m_v2;
    Vector2d m_v3;
    Vector2d m_v4;
    static std::vector<PlainRectangle> m_rectangles;
public:
    PlainRectangle();
    PlainRectangle(const Vector2d &v1, const Vector2d &v2, const Vector2d &v3, const Vector2d & v4);
    void subDivide(const Vector2d &a, const Vector2d &b, const Vector2d &c, const Vector2d& d, int n);
    void makeRectangle(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, const Vector2d& v4);
    void print() const;

};
#endif // PLAINRECTANGLE_H
