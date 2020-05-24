#ifndef LIGHT_HPP
#define LIGHT_HPP
#include "IncludeAll.hpp"

class Light
{
public:
    Light();

    Light(QString name_i, double power_i, double x1_i, double y1_i, double x2_i = 0, double y2_i = 0);

    QJsonObject toJsonObject();

    Light fromJsonObject(QJsonObject jObj);

    void draw(QGraphicsScene* scene);

    QBrush defineQBrush();

    QPen defineQPen();

public:
    double x1;
    double y1;

    double x2;
    double y2;

    double power;
    QString name;

    bool type = false; // для определения типа источника света
    size_t amount = 0;
};

#endif // LIGHT_HPP
