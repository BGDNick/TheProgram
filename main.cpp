#include "window.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.setFixedSize(1280, 720);
    w.show();
    return a.exec();
}
