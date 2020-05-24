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
    QString getString();
    ~Window();

public slots:
    void newDocument();

    void load();

    void save();

    void saveAs();

    void on_pushButtonTextEnter_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonCalculate_clicked();

    void on_pushButtonClearScreen_clicked();

    void on_toolButtonScaleInc_clicked();

    void on_toolButtonDec_clicked();

    void on_pushButtonLensAdd_clicked();

    //void on_pushButtonRectAdd_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_comboBoxLightType_activated(const QString &arg1);

    void on_pushButtonLightAdd_clicked();

    void on_spinBoxLightAmount_valueChanged(int arg1);


public:
    std::pair<double, double> mainFrame = std::make_pair(500, 500);
    Ui::Window *ui;
    bool is_saved = true; 
    //QList<Rect> rects;
    QList<Lens> lens;
    QList<Light> lights;
    QList<QListWidgetItem> items;   
    QGraphicsView view;
    QGraphicsScene *scene;
    QList<Line> lines;
    QString currentFile;
    double current_scale = 0;
private slots:
    void on_doubleSpinBox_valueChanged(double arg1);
    void on_pushButtonCalculate_2_clicked();
    void on_doubleSpinBox_2_valueChanged(double arg1);
};
#endif // WINDOW_HPP

#ifndef SERVER_HPP
#define SERVER_HPP

#include <QTcpSocket>
#include <QTcpServer>
#include <QObject>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(Window* i_w, QObject *parent = nullptr);

signals:

public slots:
    void connected();

public:
    Window* w;
    QTcpSocket* socket;
    QTcpServer* server;
};
#endif // SERVER_HPP
