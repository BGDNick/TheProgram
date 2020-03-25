#include "window.hpp"
#include "ui_window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    setWindowTitle("TheProgramm");
    setWindowIcon(QIcon(":/resources/data/Logo.png"));
    connect(ui->actionNew, &QAction::triggered, this, &Window::newDocument);
    connect(ui->actionLoad, &QAction::triggered, this, &Window::load);
    connect(ui->actionSave, &QAction::triggered, this, &Window::save);
    connect(ui->actionSave_as, &QAction::triggered, this, &Window::save);
    connect(ui->actionSave, &QAction::triggered, this, &Window::save);
}

Window::~Window()
{
    delete ui;
}

void Window::save()
{
    QString fileName;
    if(currentFile.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFile = fileName;
    }

    else
    {
        fileName = currentFile;
    }

    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, "Warning", "Cannot save file" + file.errorString());
        return;
    }

    setWindowTitle(fileName);

    QJsonObject jObj;
    //вставка отрезков
    QJsonArray jArrLines;
    foreach(Line l, lines)
    {
        jArrLines.append(l.toJsonObject());
    }
    jObj.insert("line",jArrLines);

    //вставка прямоугольников
    QJsonArray jArrRect;
    foreach(Rect r, rects)
    {
        jArrRect.append(r.toJsonObject());
    }
    jObj.insert("rectangle", jArrRect);

    QTextStream out(&file);
    QJsonDocument jDoc(jObj);
    QString text;
    text = jDoc.toJson(QJsonDocument::Compact);
    out << text;
    file.close();

    is_saved = true;

}

// добавить проверку на сохранение
void Window::load()
{
    /*if(!is_saved)
    {
        QMessageBox::warning(this, "Warning", "Save first");
        save();
    }*/

    QString fileName = QFileDialog::getOpenFileName(this, "Load the file");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file");
        return;
    }
    setWindowTitle(fileName);

    lines.clear();

    QTextStream in(&file);
    QString text = in.readAll();
    QJsonDocument jDoc = QJsonDocument::fromJson(text.toUtf8());
    QJsonObject jObj = jDoc.object();

    QJsonArray jArr_lines = jObj.value("line").toArray();
    QJsonArray jArr_rects = jObj.value("rectangle").toArray();

    // добавление линий
    foreach(QJsonValue jValue, jArr_lines)
    {
        QJsonObject jLine = jValue.toObject();
        Line temp;
        temp.fromJsonObject(jLine);
        lines.append(temp);
    }

    // добавление прямоугольников
    foreach(QJsonValue jValue, jArr_rects)
    {
        QJsonObject jRect = jValue.toObject();
        Rect temp;
        temp.fromJsonObject(jRect);
        rects.append(temp);
    }
    currentFile = fileName;
    is_saved = true;
    ui->plainTextEdit->setPlainText(text);

}

void Window::newDocument()
{
    /*if(!is_saved)
    {
        QMessageBox::warning(this, "Warning", "Save first");
        save();
    }*/
    setWindowTitle("TheProgramm");
    currentFile.clear();
    is_saved = false;
    lines.clear();
    rects.clear();
    ui->plainTextEdit->clear();
}

void Window::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    currentFile = fileName;
    save();
}


void Window::on_pushButtonTextEnter_clicked()
{
    QString text;
    text = ui->plainTextEdit->toPlainText();
    lines.clear();
    rects.clear();
    QJsonDocument jDoc = QJsonDocument::fromJson(text.toUtf8());
    QJsonObject jObj = jDoc.object();

    // добавление линий
    QJsonArray jArr_lines = jObj.value("line").toArray();

    foreach(QJsonValue jValue, jArr_lines)
    {
        QJsonObject jLine = jValue.toObject();
        Line temp;
        temp.fromJsonObject(jLine);
        lines.append(temp);
    }

    // добавление прямоугольников
    QJsonArray jArr_rects = jObj.value("rectangle").toArray();

    foreach (QJsonValue jValue, jArr_rects)
    {
        QJsonObject jRect = jValue.toObject();
        Rect temp;
        temp.fromJsonObject(jRect);
        rects.append(temp);
    }

    is_saved = true;
}

void Window::on_pushButtonClear_clicked()
{
    ui->plainTextEdit->clear();
}

void Window::on_pushButtonCalculate_clicked()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    scene->addLine(1,1,100,100,QPen(QColor(Qt::red)));
    foreach (Line l, lines) {
        QPen pen(QColor(l.colour[0], l.colour[1], l.colour[2], 255));
        scene->addLine(l.coord1.first, l.coord1.second, l.coord2.first, l.coord2.second, pen);
    }

    foreach (Rect r, rects)
    {
        scene->addRect(r.coord1.first, r.coord1.second, r.coord2.first, r.coord2.second);
    }
}

void Window::on_pushButtonClearScreen_clicked()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

void Window::on_toolButtonR_clicked()
{
    ui->plainTextEdit->insertPlainText("\"rectangle\":[{\"x1\": * ,\"y1\": * ,\"x2\": * ,\"y2\": * }]");

}

void Window::on_toolButtonL_clicked()
{
    ui->plainTextEdit->insertPlainText("\"line\":[{\"x1\": * ,\"y1\": * ,\"x2\": * ,\"y2\": * ,\"r\": * ,\"g\": * ,\"b\": * }]");
}
