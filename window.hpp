#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include "IncludeAll.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "lens.hpp"

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

    void rails();

    void on_pushButtonTextEnter_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonCalculate_clicked();

    void on_pushButtonClearScreen_clicked();

    void on_toolButtonR_clicked();

    void on_toolButtonL_clicked();

    void on_toolButtonScaleInc_clicked();

    void on_toolButtonDec_clicked();

    void on_pushButtonLensAdd_clicked();

    void on_pushButtonRectAdd_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_comboBoxLightType_activated(const QString &arg1);

    void on_pushButtonLightAdd_clicked();

    void on_spinBoxLightAmount_valueChanged(int arg1);

private:
    Ui::Window *ui;
    QString currentFile;
    bool is_saved = true;
    QList<Line> lines;
    QList<Rect> rects;
    QList<Lens> lens;
    QList<Light> lights;
    QList<QListWidgetItem> items;
    QGraphicsScene *scene;
    QGraphicsView view;

};
#endif // WINDOW_HPP
