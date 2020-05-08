#ifndef LENS_HPP
#define LENS_HPP

#include "IncludeAll.hpp"

class Lens
{
public:
    Lens();

    explicit Lens(std::pair<double, double> i_coord, std::pair<double,double> i_radius,
         double i_lenght, double i_r_index, QString i_type, double angle);

    QJsonObject toJsonObject();

    Lens fromJsonObject(QJsonObject jObj);

    void draw(QGraphicsScene* scene);

public:
    std::pair<double, double> coord;
    std::pair<double, double> radius;
    double length;
    double r_index;
    double angle;
    QString name = "Lens";
    QString type = "Flat";

    QString type_flat = "Flat";
    QString type_convex = "Convex";

};
#endif // LENS_HPP

