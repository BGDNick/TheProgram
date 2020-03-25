#ifndef LINE_HPP
#define LINE_HPP
#include <IncludeAll.hpp>
#include <objects.hpp>

// линии
class Line: public Object
{
public:
    Line();

    Line(std::pair<double, double> p1, std::pair<double, double> p2, int c[3]);

    QJsonObject toJsonObject();
    Line fromJsonObject(QJsonObject jObj);

public:
    std::pair<double, double> coord2;
    int colour[3] = {0,0,0};
};

#endif // LINE_HPP
