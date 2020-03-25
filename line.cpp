#include "line.hpp"

// описание Line
Line::Line()
{
    coord1.first = 0;
    coord2.first = 0;
    coord1.second = 0;
    coord2.second = 0;
    for(int i = 0; i < 3; ++i)
    {
        colour[i] = 0;
    }
}

Line::Line(std::pair<double, double> p1, std::pair<double, double> p2, int* c)
{
    coord1 = p1;
    coord2 = p2;
    for(int i = 0; i < 3; ++i)
    {
        colour[i] = c[i];
    }
}


QJsonObject Line::toJsonObject()
{
    QJsonObject jObj;
    jObj.insert("x1", QJsonValue::fromVariant(coord1.first));
    jObj.insert("y1", QJsonValue::fromVariant(coord1.second));
    jObj.insert("x2", QJsonValue::fromVariant(coord2.first));
    jObj.insert("y2", QJsonValue::fromVariant(coord2.second));

    jObj.insert("r", QJsonValue::fromVariant(colour[0]));
    jObj.insert("g", QJsonValue::fromVariant(colour[1]));
    jObj.insert("b", QJsonValue::fromVariant(colour[2]));

    return jObj;

}

Line Line::fromJsonObject(QJsonObject jObj)
{
    this->coord1.first = jObj.value("x1").toDouble();
    this->coord1.second = jObj.value("y1").toDouble();
    this->coord2.first = jObj.value("x2").toDouble();
    this->coord2.second = jObj.value("y2").toDouble();

    this->colour[0] = jObj.value("r").toInt();
    this->colour[1] = jObj.value("g").toInt();
    this->colour[2] = jObj.value("b").toInt();

    return *this;
}

