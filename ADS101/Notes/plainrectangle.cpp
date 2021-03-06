// ADS101 Algoritmer og Datastrukturer for spill 2020
// Dag Nylund, Høgskolen i Innlandet

#include <iostream>
#include "plainrectangle.h"

std::vector<PlainRectangle> PlainRectangle::m_rectangles;

PlainRectangle::PlainRectangle() //: PlainTriangle ()
{

}

PlainRectangle::PlainRectangle(const Vector2d &v1, const Vector2d &v2, const Vector2d &v3, const Vector2d &v4)
    : m_v1{v1}, m_v2{v2}, m_v3{v3}, m_v4{v4}
{

}

void PlainRectangle::subDivide(const Vector2d &a, const Vector2d &b, const Vector2d &c, const Vector2d &d, int n)
{
    if (n>0) {
        Vector2d v1 = (a+b)/2;
        Vector2d v2 = (b+c)/2;
        Vector2d v3 = (c+d)/2;
        Vector2d v4 = (d+a)/2;
        Vector2d m = (a+c)/2;
        subDivide(a, v1, m, v4, n-1);
        subDivide(v1, b, v2, m, n-1);
        subDivide(m, v2, c, v3, n-1);
        subDivide(v4, m, v3, d, n-1);
    } else {
        makeRectangle(a, b, c, d);
    }
}

void PlainRectangle::makeRectangle(const Vector2d &v1, const Vector2d &v2, const Vector2d &v3, const Vector2d &v4)
{
    m_rectangles.push_back(PlainRectangle(v1, v2, v3, v4));

}

void PlainRectangle::print() const
{
    std::cout << "n = " << m_rectangles.size() << std::endl;
    for (auto it=m_rectangles.begin(); it!=m_rectangles.end(); it++)
    {
        auto t = *it;
        std::cout << "(" << t.m_v1.x << ", " << t.m_v1.y << "), ";
        std::cout << "(" << t.m_v2.x << ", " << t.m_v2.y << "), ";
        std::cout << "(" << t.m_v3.x << ", " << t.m_v3.y << ") ";
        std::cout << "(" << t.m_v4.x << ", " << t.m_v4.y << ") ";
        std::cout << std::endl;
    }
}
