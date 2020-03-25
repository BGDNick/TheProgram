#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include "IncludeAll.hpp"
#include "rectangle.hpp"
#include "line.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void newDocument();

    void load();

    void save();

    void saveAs();

    void on_pushButtonTextEnter_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonCalculate_clicked();

    void on_pushButtonClearScreen_clicked();

    void on_toolButtonR_clicked();

    void on_toolButtonL_clicked();

private:
    Ui::Window *ui;
    QString currentFile;
    bool is_saved = true;
    QList<Line> lines;
    QList<Rect> rects;
    QGraphicsScene *scene;

};
#endif // WINDOW_HPP
