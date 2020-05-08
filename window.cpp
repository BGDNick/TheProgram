#include "window.hpp"
#include "ui_window.h"
#include <iostream>
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
    connect(ui->actionRails_2, &QAction::triggered, this, &Window::rails);

    //дополнительные действия
    on_comboBoxLightType_activated("Single"); // выключение некоторых полей


}

Window::~Window()
{
    delete ui;
}

//Функции вкладки File
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

    //вставка линз
    QJsonArray jArrLens;

    foreach(Lens ls, lens)
    {
        jArrLens.append(ls.toJsonObject());
    }

    jObj.insert("lens", jArrLens);

    //вставка источников света

    QJsonArray jArrLight;

    foreach(Light l, lights)
    {
        jArrLight.append(l.toJsonObject());
    }

    jObj.insert("light", jArrLight);

    QTextStream out(&file);
    QJsonDocument jDoc(jObj);

    QString text;
    text = jDoc.toJson(QJsonDocument::Indented);
    out << text;
    file.close();
    is_saved = true;




}

// добавить проверку на сохранение
void Window::load()
{
    if(!is_saved) // предложение сохранить файл если он не сохранен
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Wrning", "Would you like to save?", QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            save();
        }
    }

    QString fileName = QFileDialog::getOpenFileName(this, "Load the file");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file");
        return;
    }
    setWindowTitle(fileName);

    //очистка всех объектов
    lines.clear();
    rects.clear();
    lens.clear();
    lights.clear();
    items.clear();

    //считвание файла
    QTextStream in(&file);
    QString text = in.readAll();
    QJsonDocument jDoc = QJsonDocument::fromJson(text.toUtf8());
    QJsonObject jObj = jDoc.object();

    QJsonArray jArr_lines = jObj.value("line").toArray();
    QJsonArray jArr_rects = jObj.value("rectangle").toArray();
    QJsonArray jArr_lens = jObj.value("lens").toArray();
    QJsonArray jArr_lights = jObj.value("light").toArray();

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

        //добваление в список объектов
        QListWidgetItem* item = new QListWidgetItem(temp.name, ui->listWidget);
        item->setWhatsThis("Rectangle");
        ui->listWidget->addItem(item);
        items.append(*item);
    }

    // добавление линз
    foreach(QJsonValue jValue, jArr_lens)
    {
        QJsonObject jLens = jValue.toObject();
        Lens temp;
        temp.fromJsonObject(jLens);
        lens.append(temp);

        QListWidgetItem* item = new QListWidgetItem(temp.name, ui->listWidget);
        item->setWhatsThis("Lens");
        ui->listWidget->addItem(item);
        items.append(*item);
    }

    // добавление источников света
    foreach(QJsonValue jValue, jArr_lights)
    {
        QJsonObject jLight = jValue.toObject();
        Light temp;
        temp.fromJsonObject(jLight);
        lights.append(temp);

        QListWidgetItem* item = new QListWidgetItem(temp.name, ui->listWidget);
        item->setWhatsThis("Light");
        ui->listWidget->addItem(item);
        items.append(*item);
    }

    currentFile = fileName;
    is_saved = true;
    ui->plainTextEdit->setPlainText(text);

}

void Window::newDocument()
{
    if(!is_saved) // предложение сохранить файл если он не сохранен
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Wrning", "Would you like to save?", QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            save();
        }

    }

    setWindowTitle("TheProgramm");
    currentFile.clear();
    is_saved = false;
    //работа с объектами
    lines.clear();
    rects.clear();
    lens.clear();
    lights.clear();

    on_pushButtonClearScreen_clicked();
    items.clear();
    ui->listWidget->clear();
    ui->plainTextEdit->clear();
}

void Window::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    currentFile = fileName;
    save();
}

//Функции вкладки View

void Window::rails()
{
    Line Ox(std::pair<double, double>(-1000.137, 0), std::pair<double, double> (1000.785, 0));
    Line Oy(std::pair<double, double>(0, -1000.456), std::pair<double, double> (0, 1000.913));

    if(ui->actionRails_2->isEnabled())
    {
        if((lines.indexOf(Ox) == -1) && (lines.indexOf(Oy) == -1))
        {
            lines.append(Ox);
            lines.append(Oy);
        }

        on_pushButtonCalculate_clicked();
    }
    else
    {

        lines.removeOne(Ox);
        lines.removeOne(Oy);

        on_pushButtonCalculate_clicked();
    }

}


void Window::on_pushButtonTextEnter_clicked()
{
    if(!is_saved) // предложение сохранить файл если он не сохранен
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Wrning", "Would you like to save?", QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            save();
        }
    }

    QString text;
    text = ui->plainTextEdit->toPlainText();
    lines.clear();
    rects.clear();
    lens.clear();
    lights.clear();
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

        QListWidgetItem* item = new QListWidgetItem(temp.name, ui->listWidget);
        item->setWhatsThis("Rectangle");
        ui->listWidget->addItem(item);
        items.append(*item);
    }

    //добавление линз
    QJsonArray jArr_lens = jObj.value("lens").toArray();

    foreach (QJsonValue jValue, jArr_lens)
    {
        QJsonObject jLens = jValue.toObject();
        Lens temp;
        temp.fromJsonObject(jLens);
        lens.append(temp);

        QListWidgetItem* item = new QListWidgetItem(temp.name, ui->listWidget);
        item->setWhatsThis("Lens");
        ui->listWidget->addItem(item);
        items.append(*item);
    }
    //добавление источников света

    QJsonArray jArr_light = jObj.value("light").toArray();

    foreach (QJsonValue jValue, jArr_light)
    {
        QJsonObject jLight = jValue.toObject();
        Light temp;
        temp.fromJsonObject(jLight);
        lights.append(temp);

        QListWidgetItem* item = new QListWidgetItem(temp.name, ui->listWidget);
        item->setWhatsThis("Light");
        ui->listWidget->addItem(item);
        items.append(*item);
    }

    is_saved = false;



}

void Window::on_pushButtonClear_clicked()
{
    ui->plainTextEdit->clear();
    is_saved = false;
}

void Window::on_pushButtonCalculate_clicked()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    //потом будет удаленно, крест для тестировки
    scene->addLine(-100,0,100,0);
    scene->addLine(0,100,0,-100);

    //отрисовка линий
    foreach (Line l, lines) {
        scene->addLine(l.coord1.first, l.coord1.second, l.coord2.first, l.coord2.second);
    }

    //отрисовка прямоугольников
    foreach (Rect r, rects)
    {
        scene->addRect(r.coord1.first, r.coord1.second, r.coord2.first, r.coord2.second, r.defineQPen(), r.defineQBrush());
    }

    //отрисовка линз
    foreach( Lens l, lens)
    {
        l.draw(scene);

    }

    //отрисовка источников света
    foreach(Light l, lights)
    {
        l.draw(scene);
    }
}

void Window::on_pushButtonClearScreen_clicked() // кнопка очистки экрана
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

void Window::on_toolButtonR_clicked() // устаревшая кнопка, потом будет удалена
{
    ui->plainTextEdit->insertPlainText("\"rectangle\":[{\"x1\": * ,\"y1\": * ,\"x2\": * ,\"y2\": * }]");
    is_saved = false;

}

void Window::on_toolButtonL_clicked() // устаревшая кнопка, потом будет удалена
{
    ui->plainTextEdit->insertPlainText("\"line\":[{\"x1\": * ,\"y1\": * ,\"x2\": * ,\"y2\": * ,\"r\": * ,\"g\": * ,\"b\": * }]");
    is_saved = false;
}

void Window::on_toolButtonScaleInc_clicked() // кнопка увеличения масштаба картинки
{
    ui->graphicsView->scale(1.5,1.5);
}

void Window::on_toolButtonDec_clicked() // кнопка уменьшения масштаба картинки
{
    ui->graphicsView->scale(0.75, 0.75);
}

void Window::on_pushButtonLensAdd_clicked() //кнопка добавления линзы
{
    // добавление линзы
    Lens added_lens;
    added_lens.coord = std::pair<double, double>(ui->lineEditLensCoordX->text().toDouble(), ui->lineEditLensCoordY->text().toDouble());
    added_lens.radius = std::pair<double, double>(ui->lineEditLensRadiusLeft->text().toDouble(), ui->lineEditLensRadiusRight->text().toDouble());
    added_lens.length = ui->lineEditLensLength->text().toDouble();
    added_lens.r_index = ui->lineEditLensR_Index->text().toDouble();
    added_lens.name = ui->lineEditLensName->text();
    added_lens.type = ui->comboBoxLensType->currentText();
    added_lens.angle = ui->lineEditLensAngle->text().toDouble();

    // проверка на то занято ли имя
    int counter = 0;
    int count = ui->listWidget->count();
    while(counter < count)
    {

        if((items[counter].text().toStdString() == added_lens.name.toStdString()))
        {
            QMessageBox::information(this, "Warning", "Names must be different");
            return;
        }
        counter++;
    }

    //проверка на коректность введенных данных
    if((added_lens.radius.first<=0)||(added_lens.radius.second<=0)||(added_lens.length < 0) || ((added_lens.radius.first+added_lens.radius.second) <= added_lens.length))
    {
        QMessageBox::information(this, "Warning", "Incorrect lens' data");
        return;
    }
    //Добавление в линзы
    lens.append(added_lens);

    //добавление  объект в список объектов

    QListWidgetItem* item = new QListWidgetItem(added_lens.name, ui->listWidget);
    item->setWhatsThis("Lens");
    ui->listWidget->addItem(item);
    items.append(*item);
    // восстановление виджета
    ui->lineEditLensName->setText("Lens");
    ui->lineEditLensCoordX->clear();
    ui->lineEditLensCoordY->clear();
    ui->lineEditLensLength->clear();
    ui->lineEditLensRadiusLeft->clear();
    ui->lineEditLensRadiusRight->clear();
    ui->lineEditLensR_Index->clear();
    ui->lineEditLensAngle->clear();

    is_saved = false;

    //отрисовка с новой линзой
    on_pushButtonCalculate_clicked();

}

void Window::on_pushButtonRectAdd_clicked() //кнопка добавления прямоугольника
{
    //добавление прямоугольника
    Rect added_rect;
    added_rect.coord1 = std::pair<double, double>(ui->lineEditRectX->text().toDouble(), ui->lineEditRectY->text().toDouble());
    added_rect.coord2 = std::pair<double, double>(ui->lineEditRectWidth->text().toDouble(), ui->lineEditRectHeight->text().toDouble());
    added_rect.name = ui->lineEditRectName->text();
    added_rect.reflection = ui->lineEditRectReflection->text().toDouble();


    //проверка на то занято ли имя
    int counter = 0;
    int count = ui->listWidget->count();
    while(counter < count)
    {

        if((items[counter].text().toStdString() == added_rect.name.toStdString()))
        {
            std::cout << "w" << std::endl;
            QMessageBox::information(this, "Warning", "Names must be different");
            std::cout << "wa" << std::endl;
            return;
        }
        counter++;
    }

    rects.append(added_rect);


    //добавление объекта в список объектов
    QListWidgetItem* item = new QListWidgetItem(added_rect.name, ui->listWidget);
    item->setWhatsThis("Rectangle");
    items.append(*item);
    ui->listWidget->addItem(item);
    std::cout << "whats this " << ui->listWidget->item(0)->whatsThis().toStdString() << std::endl;
    //восставновление виджета
    ui->lineEditRectName->setText("Rectangle");
    ui->lineEditRectX->clear();
    ui->lineEditRectY->clear();
    ui->lineEditRectWidth->clear();
    ui->lineEditRectHeight->clear();
    ui->lineEditRectReflection->clear();
    //отрисовка с новым прямоугольником
    on_pushButtonCalculate_clicked();
}

void Window::on_listWidget_itemDoubleClicked(QListWidgetItem *item) // если по одному из элементов в списке элементов нажали два раза
{
    ui->listWidget->takeItem(ui->listWidget->row(item));
    //удаление объекта из items
    QList<QListWidgetItem> temp;
    foreach(QListWidgetItem it, items)
    {
        if(it.text() == item->text())
        {
            //pass
        }
        else
        {
            temp.append(it);
        }
    }
    items = temp;
    //если объект - прямоугольник
    if(item->whatsThis() == "Rectangle")
    {
        QList<Rect> temp;
        foreach(Rect r, rects )
        {
            if(r.name == item->text())
            {
                //pass
            }
            else
            {
                temp.append(r);
            }

        }
        rects = temp;
    }
    else
    if(item->whatsThis() == "Lens")
    {
        QList<Lens> temp;
        foreach(Lens l, lens )
        {
            if(l.name == item->text())
            {
                //pass
            }
            else
            {
                temp.append(l);
            }

        }
        lens = temp;
    }
    if(item->whatsThis() == "Light")
    {
        QList<Light> temp;
        foreach (Light l, lights)
        {
            if(l.name == item->text())
            {
                //pass
            }
            else
            {
                temp.append(l);
            }
        }
        lights = temp;
    }

    //отрисовка без удаленного предмета
    on_pushButtonCalculate_clicked();

}


//действия при нажатии на объект в списке
void Window::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(item->whatsThis() == "Lens")
    {
        ui->toolBox->setCurrentIndex(0);
        foreach(Lens l, lens)
        {
            if(l.name == item->text())
            {
                ui->lineEditLensCoordX->setText(QString::number(l.coord.first));
                ui->lineEditLensCoordY->setText(QString::number(l.coord.second));
                ui->lineEditLensLength->setText(QString::number(l.length));
                ui->lineEditLensName->setText(l.name);
                ui->lineEditLensRadiusLeft->setText(QString::number(l.radius.first));
                ui->lineEditLensRadiusRight->setText(QString::number(l.radius.second));
                ui->lineEditLensR_Index->setText(QString::number(l.r_index));
                ui->lineEditLensAngle->setText(QString::number(l.angle));
                int index;
                if(l.type == "Flat")
                {
                    index = 0;
                }
                else
                {
                    index = 1;
                }
                ui->comboBoxLensType->setCurrentIndex(index);
                return;
            }
        }
    }
    else
    if(item->whatsThis() == "Rectangle")
    {
        ui->toolBox->setCurrentIndex(1);
        foreach(Rect r, rects)
        {
            if(r.name == item->text())
            {
                ui->lineEditRectName->setText((r.name)) ;
                ui->lineEditRectHeight->setText(QString::number(r.coord2.second));
                ui->lineEditRectWidth->setText(QString::number(r.coord2.first));
                ui->lineEditRectX->setText(QString::number(r.coord1.first));
                ui->lineEditRectY->setText(QString::number(r.coord2.second));
                ui->lineEditRectReflection->setText(QString::number(r.reflection));
                return;
            }
        }
    }
    else
    if(item->whatsThis() == "Light")
    {
        ui->toolBox->setCurrentIndex(2);
        foreach(Light l, lights)
        {
            if(l.name == item->text())
            {

                ui->lineEditLightName->setText(l.name);
                ui->lineEditLightX->setText(QString::number(l.x1));
                ui->lineEditLightY->setText(QString::number(l.y1));
                ui->doubleSpinBoxLightPower->setValue(l.power);
                if(l.type)
                {
                    ui->lineEditLightX_2->setText(QString::number(l.x2));
                    ui->lineEditLightY_2->setText(QString::number(l.y2));
                    ui->spinBoxLightAmount->setValue(l.amount);
                    ui->comboBoxLightType->setCurrentIndex(1);
                    on_comboBoxLightType_activated("Line"); // включение некоторых полей
                }
                else
                {
                    ui->comboBoxLightType->setCurrentIndex(0);
                    on_comboBoxLightType_activated("Single"); // выключение некоторых полей

                }
                return;
            }
        }
    }

}




void Window::on_comboBoxLightType_activated(const QString &arg1) //при изменении типа источника света
{
    if(arg1 == "Single")
    {
        //выключаем поля, которые не соответсвуют выбраному типу объекта
        ui->lineEditLightX_2->setEnabled(false);
        ui->lineEditLightY_2->setEnabled(false);
        ui->spinBoxLightAmount->setEnabled(false);

        return;
    }

    if(arg1 == "Line")
    {
        //включаем поля которые соответсвуют выбраному объекту
        ui->lineEditLightX_2->setEnabled(true);
        ui->lineEditLightY_2->setEnabled(true);
        ui->spinBoxLightAmount->setEnabled(true);
    }

}

void Window::on_pushButtonLightAdd_clicked() //при нжатии на кнопку добавления линзы
{
    // создание временного объекта
    Light added_light;
    added_light.x1 = ui->lineEditLightX->text().toDouble();
    added_light.y1 = ui->lineEditLightY->text().toDouble();

    added_light.name = ui->lineEditLightName->text();
    added_light.power = ui->doubleSpinBoxLightPower->text().toDouble();

    added_light.x2 = ui->lineEditLightX_2->text().toDouble();
    added_light.y2 = ui->lineEditLightY_2->text().toDouble();
    added_light.amount = ui->spinBoxLightAmount->text().toDouble();
    if((ui->comboBoxLightType->currentText() == "Single"))
    {
        added_light.type = false;
    }
    else
    {
        added_light.type = true;
    }

    // проверка на то занято ли имя
    int counter = 0;
    int count = ui->listWidget->count();
    while(counter < count)
    {

        if((items[counter].text().toStdString() == added_light.name.toStdString()))
        {
            QMessageBox::information(this, "Warning", "Names must be different");
            return;
        }
        counter++;
    }

    // в начале проверяем какой тип объекта выбран


    //добавление в общий список источников света
    lights.append(added_light);

    //добавление объекта в список объектов
    QListWidgetItem* item = new QListWidgetItem(added_light.name, ui->listWidget);
    item->setWhatsThis("Light");
    ui->listWidget->addItem(item);
    items.append(*item);



    //отрисовка с новым источником света
    on_pushButtonCalculate_clicked();
}



void Window::on_spinBoxLightAmount_valueChanged(int arg1) //будет удалено
{
    //idle
}
