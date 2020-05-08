#include "lens.hpp"

Lens::Lens()
{
    std::pair<double, double> coord = std::pair<double, double> (0,0);
    std::pair<double, double> radius = std::pair<double, double> (0,0);
    double length = 0;
    double r_index = 0;
}

Lens::Lens(std::pair<double, double> i_coord, std::pair<double,double> i_radius, double i_length, double i_r_index, QString i_type, double angle_i)
{
    coord = i_coord;
    radius = i_radius;
    length = i_length;
    r_index = i_r_index;
    type = i_type;
    angle = angle_i;

}




QJsonObject Lens::toJsonObject()
{

    QJsonObject jObj;

    jObj.insert("x", QJsonValue::fromVariant(coord.first));
    jObj.insert("y", QJsonValue::fromVariant(coord.second));
    jObj.insert("R1", QJsonValue::fromVariant(radius.first));
    jObj.insert("R2", QJsonValue::fromVariant(radius.second));
    jObj.insert("l", QJsonValue::fromVariant(length));
    jObj.insert("n", QJsonValue::fromVariant(r_index));
    jObj.insert("type", QJsonValue::fromVariant(type));
    jObj.insert("name", QJsonValue::fromVariant(name));
    jObj.insert("angle", QJsonValue::fromVariant(angle));

    return jObj;

}

Lens Lens::fromJsonObject(QJsonObject jObj)
{
    this->coord.first = jObj.value("x").toDouble();
    this->coord.second = jObj.value("y").toDouble();
    this->radius.first = jObj.value("R1").toDouble();
    this->radius.second = jObj.value("R2").toDouble();
    this->length = jObj.value("l").toDouble();
    this->r_index = jObj.value("n").toDouble();
    this->type = jObj.value("type").toDouble();
    this->name = jObj.value("name").toDouble();
    this->angle = jObj.value("angle").toDouble();

    return *this;
}

void Lens::draw(QGraphicsScene* scene)
{
    if(type == type_flat)
    {
        //std::cout << "Drawing" << std::endl;
        //std::cout << coord.first << "  " << coord.second << "  " << radius.first << "  " << radius.second << "  " << length << "  " << r_index << std::endl;

        //расстояние от центра левой окружности до центра линзы
        double a = (radius.first * radius.first + radius.first * radius.second - length * radius.first - length * radius.second + length * length)/
                (radius.first + radius.second - length);

        //расстояние от центра правой окружности до центра линзы
        double b = (radius.second * radius.second + radius.first * radius.second - length * radius.first - length * radius.second) /
                (radius.first + radius.second - length);

        //половина высоты линзы
        double h = sqrt(radius.first * radius.first - a * a);

        //координаты левого и правого центров окружностей
        std::pair<double, double> coord_left = std::pair <double, double> (coord.first - a, coord.second);

        std::pair<double, double> coord_right = std::pair<double, double> (coord.first + b, coord.second);

        //углы необходимые для посроения дуг
        double pi = 3.1415926535;
        double angle_left = asin(h / radius.first) ;
        double angle_right = asin(h / radius.second);
        //начинаем создавать дугу

        //переводим перо в центр левой окружности
        //path.moveTo(coord_left.first, coord_left.second);
        //начинаем прорисовывать левую дугу
        //path.arcTo(coord_left.first - radius.first, coord_left.second + radius.first, radius.first, radius.first, angle_left, 180);
        //добавление дуги на экран

        // создаем пути т.к. нет элемента "дуга"
        QPainterPath path_left;
        QPainterPath path_right;

        // первая дуга

        path_left.moveTo(coord_left.first + radius.first * cos(angle_left) , (coord_left.second - radius.first * sin(angle_left)));

        path_left.arcTo(coord_left.first - radius.first, coord_left.second - radius.first, 2 * radius.first, 2 * radius.first, 180 * angle_left / pi + angle, -2 * 180 * angle_left / pi);
        scene->addPath(path_left);
        //вторая дуга

        path_right.moveTo(coord_right.first - radius.second * cos(angle_right), (coord_right.second - radius.second * sin(angle_right)));

        path_right.arcTo(coord_right.first - radius.second, coord_right.second - radius.second, 2 * radius.second, 2 * radius.second, 180 - 180 * angle_right / pi + angle, 2 * 180 * angle_right / pi);
        scene->addPath(path_right);

        return;
    }

    if(type == type_convex)
    {
        //pass
    }

}

