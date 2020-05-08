#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "objects.hpp"

// прямоугольник
class Rect: public Object
{
public:
    Rect();
    Rect(std::pair<double, double> p1, std::pair<double, double> p2);

    QJsonObject toJsonObject();
    Rect fromJsonObject(QJsonObject jObj);
    QBrush defineQBrush();
    QPen defineQPen();

public:
    std::pair<double, double> coord2;
    double reflection = 0; // коэффициент отражения
    QString name = "Rectangle";
};

#endif // RECTANGLE_HPP
