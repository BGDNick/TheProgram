/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QAction *actionNew;
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionImport_image;
    QAction *actionTurn_On;
    QAction *actionTurn_on;
    QAction *actionRails_2;
    QAction *actionRails_Off;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButtonTextEnter;
    QPushButton *pushButtonClear;
    QFrame *frame;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_2;
    QGraphicsView *graphicsView;
    QPushButton *pushButtonCalculate;
    QPushButton *pushButtonClearScreen;
    QToolButton *toolButtonScaleInc;
    QToolButton *toolButtonDec;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QToolBox *toolBox;
    QWidget *page_5;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditLensCoordX;
    QLineEdit *lineEditLensCoordY;
    QLineEdit *lineEditLensLength;
    QLabel *label_2;
    QLabel *label_7;
    QLineEdit *lineEditLensR_Index;
    QLabel *label_6;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEditLensRadiusLeft;
    QLineEdit *lineEditLensRadiusRight;
    QPushButton *pushButtonLensAdd;
    QLineEdit *lineEditLensName;
    QWidget *Lens;
    QLineEdit *lineEditRectName;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEditRectX;
    QLineEdit *lineEditRectY;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditRectLength;
    QPushButton *pushButtonRectAdd;
    QWidget *light;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEditLightName;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditLightX;
    QLineEdit *lineEditLightY;
    QDoubleSpinBox *doubleSpinBoxLightPower;
    QPushButton *pushButtonLightAdd;
    QComboBox *comboBoxLightType;
    QLabel *label_11;
    QLabel *label_12;
    QSpinBox *spinBoxLightAmount;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEditLightX_2;
    QLineEdit *lineEditLightY_2;
    QPushButton *pushButtonCalculate_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuView;
    QMenu *menuFile;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->setEnabled(true);
        Window->resize(1280, 716);
        actionNew = new QAction(Window);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionLoad = new QAction(Window);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(Window);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(Window);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionImport_image = new QAction(Window);
        actionImport_image->setObjectName(QString::fromUtf8("actionImport_image"));
        actionTurn_On = new QAction(Window);
        actionTurn_On->setObjectName(QString::fromUtf8("actionTurn_On"));
        actionTurn_on = new QAction(Window);
        actionTurn_on->setObjectName(QString::fromUtf8("actionTurn_on"));
        actionRails_2 = new QAction(Window);
        actionRails_2->setObjectName(QString::fromUtf8("actionRails_2"));
        actionRails_Off = new QAction(Window);
        actionRails_Off->setObjectName(QString::fromUtf8("actionRails_Off"));
        centralwidget = new QWidget(Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(970, 460, 311, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(verticalLayoutWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        pushButtonTextEnter = new QPushButton(centralwidget);
        pushButtonTextEnter->setObjectName(QString::fromUtf8("pushButtonTextEnter"));
        pushButtonTextEnter->setEnabled(true);
        pushButtonTextEnter->setGeometry(QRect(1050, 640, 75, 31));
        pushButtonTextEnter->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonTextEnter->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));
        pushButtonClear = new QPushButton(centralwidget);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(970, 640, 75, 31));
        pushButtonClear->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonClear->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 1281, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        doubleSpinBox = new QDoubleSpinBox(frame);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(110, 10, 61, 16));
        doubleSpinBox->setMinimum(100.000000000000000);
        doubleSpinBox->setMaximum(100000.000000000000000);
        doubleSpinBox->setSingleStep(10.000000000000000);
        doubleSpinBox->setValue(500.000000000000000);
        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(30, 10, 71, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Arial\";"));
        doubleSpinBox_2 = new QDoubleSpinBox(frame);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(180, 10, 61, 16));
        doubleSpinBox_2->setMinimum(100.000000000000000);
        doubleSpinBox_2->setMaximum(100000.000000000000000);
        doubleSpinBox_2->setSingleStep(10.000000000000000);
        doubleSpinBox_2->setValue(500.000000000000000);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 30, 971, 611));
        pushButtonCalculate = new QPushButton(centralwidget);
        pushButtonCalculate->setObjectName(QString::fromUtf8("pushButtonCalculate"));
        pushButtonCalculate->setGeometry(QRect(80, 640, 101, 31));
        pushButtonCalculate->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));
        pushButtonClearScreen = new QPushButton(centralwidget);
        pushButtonClearScreen->setObjectName(QString::fromUtf8("pushButtonClearScreen"));
        pushButtonClearScreen->setGeometry(QRect(0, 640, 71, 31));
        pushButtonClearScreen->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));
        toolButtonScaleInc = new QToolButton(centralwidget);
        toolButtonScaleInc->setObjectName(QString::fromUtf8("toolButtonScaleInc"));
        toolButtonScaleInc->setGeometry(QRect(930, 560, 31, 31));
        toolButtonScaleInc->setStyleSheet(QString::fromUtf8("font: 12pt \"MS Shell Dlg 2\";\n"
"font: 75 14pt \"MS Shell Dlg 2\";"));
        toolButtonDec = new QToolButton(centralwidget);
        toolButtonDec->setObjectName(QString::fromUtf8("toolButtonDec"));
        toolButtonDec->setGeometry(QRect(930, 600, 31, 31));
        toolButtonDec->setStyleSheet(QString::fromUtf8("font: 75 14pt \"MS Shell Dlg 2\";"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(969, 29, 311, 131));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(verticalLayoutWidget_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(970, 160, 311, 301));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 311, 220));
        label = new QLabel(page_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 71, 21));
        label->setStyleSheet(QString::fromUtf8("font: italic 10pt \"Arial\";"));
        horizontalLayoutWidget = new QWidget(page_5);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(90, 40, 121, 24));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditLensCoordX = new QLineEdit(horizontalLayoutWidget);
        lineEditLensCoordX->setObjectName(QString::fromUtf8("lineEditLensCoordX"));

        horizontalLayout->addWidget(lineEditLensCoordX);

        lineEditLensCoordY = new QLineEdit(horizontalLayoutWidget);
        lineEditLensCoordY->setObjectName(QString::fromUtf8("lineEditLensCoordY"));

        horizontalLayout->addWidget(lineEditLensCoordY);

        lineEditLensLength = new QLineEdit(page_5);
        lineEditLensLength->setObjectName(QString::fromUtf8("lineEditLensLength"));
        lineEditLensLength->setGeometry(QRect(89, 69, 71, 20));
        label_2 = new QLabel(page_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 69, 71, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: italic 10pt \"Arial\";"));
        label_7 = new QLabel(page_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 100, 81, 21));
        label_7->setStyleSheet(QString::fromUtf8("font: italic 10pt \"Arial\";"));
        lineEditLensR_Index = new QLineEdit(page_5);
        lineEditLensR_Index->setObjectName(QString::fromUtf8("lineEditLensR_Index"));
        lineEditLensR_Index->setGeometry(QRect(90, 100, 71, 20));
        label_6 = new QLabel(page_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 130, 71, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: italic 10pt \"Arial\";"));
        horizontalLayoutWidget_2 = new QWidget(page_5);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(90, 130, 126, 24));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEditLensRadiusLeft = new QLineEdit(horizontalLayoutWidget_2);
        lineEditLensRadiusLeft->setObjectName(QString::fromUtf8("lineEditLensRadiusLeft"));

        horizontalLayout_3->addWidget(lineEditLensRadiusLeft);

        lineEditLensRadiusRight = new QLineEdit(horizontalLayoutWidget_2);
        lineEditLensRadiusRight->setObjectName(QString::fromUtf8("lineEditLensRadiusRight"));

        horizontalLayout_3->addWidget(lineEditLensRadiusRight);

        pushButtonLensAdd = new QPushButton(page_5);
        pushButtonLensAdd->setObjectName(QString::fromUtf8("pushButtonLensAdd"));
        pushButtonLensAdd->setGeometry(QRect(220, 160, 75, 23));
        lineEditLensName = new QLineEdit(page_5);
        lineEditLensName->setObjectName(QString::fromUtf8("lineEditLensName"));
        lineEditLensName->setGeometry(QRect(10, 0, 113, 31));
        lineEditLensName->setStyleSheet(QString::fromUtf8("font: 75 italic 14pt \"Arial\";"));
        toolBox->addItem(page_5, QString::fromUtf8("Lens"));
        Lens = new QWidget();
        Lens->setObjectName(QString::fromUtf8("Lens"));
        Lens->setGeometry(QRect(0, 0, 311, 220));
        lineEditRectName = new QLineEdit(Lens);
        lineEditRectName->setObjectName(QString::fromUtf8("lineEditRectName"));
        lineEditRectName->setGeometry(QRect(10, 0, 113, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(9);
        lineEditRectName->setFont(font1);
        lineEditRectName->setStyleSheet(QString::fromUtf8("font: 75 italic 14pt \"Arial\";"));
        horizontalLayoutWidget_3 = new QWidget(Lens);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(100, 50, 121, 24));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEditRectX = new QLineEdit(horizontalLayoutWidget_3);
        lineEditRectX->setObjectName(QString::fromUtf8("lineEditRectX"));

        horizontalLayout_4->addWidget(lineEditRectX);

        lineEditRectY = new QLineEdit(horizontalLayoutWidget_3);
        lineEditRectY->setObjectName(QString::fromUtf8("lineEditRectY"));

        horizontalLayout_4->addWidget(lineEditRectY);

        label_3 = new QLabel(Lens);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 71, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: italic 10pt \"Arial\";"));
        label_4 = new QLabel(Lens);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 80, 71, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: italic 10pt \"Arial\";"));
        lineEditRectLength = new QLineEdit(Lens);
        lineEditRectLength->setObjectName(QString::fromUtf8("lineEditRectLength"));
        lineEditRectLength->setGeometry(QRect(100, 80, 71, 20));
        pushButtonRectAdd = new QPushButton(Lens);
        pushButtonRectAdd->setObjectName(QString::fromUtf8("pushButtonRectAdd"));
        pushButtonRectAdd->setGeometry(QRect(220, 170, 75, 23));
        toolBox->addItem(Lens, QString::fromUtf8("Screen"));
        light = new QWidget();
        light->setObjectName(QString::fromUtf8("light"));
        light->setGeometry(QRect(0, 0, 311, 220));
        label_9 = new QLabel(light);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 40, 71, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        label_9->setFont(font2);
        label_10 = new QLabel(light);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 70, 47, 21));
        label_10->setFont(font2);
        lineEditLightName = new QLineEdit(light);
        lineEditLightName->setObjectName(QString::fromUtf8("lineEditLightName"));
        lineEditLightName->setGeometry(QRect(10, 0, 113, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(14);
        font3.setItalic(true);
        lineEditLightName->setFont(font3);
        horizontalLayoutWidget_4 = new QWidget(light);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(110, 40, 121, 24));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEditLightX = new QLineEdit(horizontalLayoutWidget_4);
        lineEditLightX->setObjectName(QString::fromUtf8("lineEditLightX"));

        horizontalLayout_2->addWidget(lineEditLightX);

        lineEditLightY = new QLineEdit(horizontalLayoutWidget_4);
        lineEditLightY->setObjectName(QString::fromUtf8("lineEditLightY"));

        horizontalLayout_2->addWidget(lineEditLightY);

        doubleSpinBoxLightPower = new QDoubleSpinBox(light);
        doubleSpinBoxLightPower->setObjectName(QString::fromUtf8("doubleSpinBoxLightPower"));
        doubleSpinBoxLightPower->setGeometry(QRect(110, 70, 62, 22));
        doubleSpinBoxLightPower->setMaximum(100.000000000000000);
        pushButtonLightAdd = new QPushButton(light);
        pushButtonLightAdd->setObjectName(QString::fromUtf8("pushButtonLightAdd"));
        pushButtonLightAdd->setGeometry(QRect(220, 140, 75, 23));
        comboBoxLightType = new QComboBox(light);
        comboBoxLightType->addItem(QString());
        comboBoxLightType->addItem(QString());
        comboBoxLightType->setObjectName(QString::fromUtf8("comboBoxLightType"));
        comboBoxLightType->setGeometry(QRect(170, 0, 91, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        comboBoxLightType->setFont(font4);
        label_11 = new QLabel(light);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 130, 51, 21));
        label_11->setFont(font2);
        label_12 = new QLabel(light);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 100, 91, 21));
        label_12->setFont(font2);
        spinBoxLightAmount = new QSpinBox(light);
        spinBoxLightAmount->setObjectName(QString::fromUtf8("spinBoxLightAmount"));
        spinBoxLightAmount->setGeometry(QRect(110, 130, 61, 22));
        spinBoxLightAmount->setMinimum(2);
        spinBoxLightAmount->setMaximum(100);
        horizontalLayoutWidget_5 = new QWidget(light);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(110, 100, 121, 24));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        lineEditLightX_2 = new QLineEdit(horizontalLayoutWidget_5);
        lineEditLightX_2->setObjectName(QString::fromUtf8("lineEditLightX_2"));

        horizontalLayout_5->addWidget(lineEditLightX_2);

        lineEditLightY_2 = new QLineEdit(horizontalLayoutWidget_5);
        lineEditLightY_2->setObjectName(QString::fromUtf8("lineEditLightY_2"));

        horizontalLayout_5->addWidget(lineEditLightY_2);

        toolBox->addItem(light, QString::fromUtf8("Light"));
        pushButtonCalculate_2 = new QPushButton(centralwidget);
        pushButtonCalculate_2->setObjectName(QString::fromUtf8("pushButtonCalculate_2"));
        pushButtonCalculate_2->setGeometry(QRect(1190, 640, 91, 31));
        pushButtonCalculate_2->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));
        Window->setCentralWidget(centralwidget);
        verticalLayoutWidget->raise();
        pushButtonTextEnter->raise();
        pushButtonClear->raise();
        frame->raise();
        graphicsView->raise();
        pushButtonCalculate->raise();
        pushButtonClearScreen->raise();
        verticalLayoutWidget_2->raise();
        toolButtonScaleInc->raise();
        toolButtonDec->raise();
        toolBox->raise();
        pushButtonCalculate_2->raise();
        statusbar = new QStatusBar(Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Window->setStatusBar(statusbar);
        menubar = new QMenuBar(Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 21));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        Window->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionImport_image);

        retranslateUi(Window);

        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Window", nullptr));
        actionNew->setText(QCoreApplication::translate("Window", "New", nullptr));
        actionLoad->setText(QCoreApplication::translate("Window", "Load", nullptr));
        actionSave->setText(QCoreApplication::translate("Window", "Save", nullptr));
        actionSave_as->setText(QCoreApplication::translate("Window", "Save as", nullptr));
        actionImport_image->setText(QCoreApplication::translate("Window", "Import image", nullptr));
        actionTurn_On->setText(QCoreApplication::translate("Window", "Turn On", nullptr));
        actionTurn_on->setText(QCoreApplication::translate("Window", "Turn on", nullptr));
        actionRails_2->setText(QCoreApplication::translate("Window", "Rails On", nullptr));
        actionRails_Off->setText(QCoreApplication::translate("Window", "Rails Off", nullptr));
        pushButtonTextEnter->setText(QCoreApplication::translate("Window", "Enter", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("Window", "Clear", nullptr));
        label_15->setText(QCoreApplication::translate("Window", "Frame", nullptr));
        pushButtonCalculate->setText(QCoreApplication::translate("Window", "Draw", nullptr));
        pushButtonClearScreen->setText(QCoreApplication::translate("Window", "Clear", nullptr));
        toolButtonScaleInc->setText(QCoreApplication::translate("Window", "+", nullptr));
        toolButtonDec->setText(QCoreApplication::translate("Window", "-", nullptr));
        label->setText(QCoreApplication::translate("Window", "Coordinate", nullptr));
        label_2->setText(QCoreApplication::translate("Window", "Length", nullptr));
        label_7->setText(QCoreApplication::translate("Window", "Refl. Index", nullptr));
        label_6->setText(QCoreApplication::translate("Window", "Radiuses", nullptr));
        pushButtonLensAdd->setText(QCoreApplication::translate("Window", "Add", nullptr));
#if QT_CONFIG(tooltip)
        lineEditLensName->setToolTip(QCoreApplication::translate("Window", "<html><head/><body><p>Lens</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEditLensName->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEditLensName->setText(QCoreApplication::translate("Window", "Lens", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QCoreApplication::translate("Window", "Lens", nullptr));
#if QT_CONFIG(tooltip)
        lineEditRectName->setToolTip(QCoreApplication::translate("Window", "<html><head/><body><p>Lens</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEditRectName->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEditRectName->setText(QCoreApplication::translate("Window", "Screen", nullptr));
        label_3->setText(QCoreApplication::translate("Window", "Coordinate", nullptr));
        label_4->setText(QCoreApplication::translate("Window", "Length", nullptr));
        pushButtonRectAdd->setText(QCoreApplication::translate("Window", "Add", nullptr));
        toolBox->setItemText(toolBox->indexOf(Lens), QCoreApplication::translate("Window", "Screen", nullptr));
        label_9->setText(QCoreApplication::translate("Window", "Coordinatte", nullptr));
        label_10->setText(QCoreApplication::translate("Window", "Power", nullptr));
        lineEditLightName->setText(QCoreApplication::translate("Window", "Light", nullptr));
        pushButtonLightAdd->setText(QCoreApplication::translate("Window", "Add", nullptr));
        comboBoxLightType->setItemText(0, QCoreApplication::translate("Window", "Single", nullptr));
        comboBoxLightType->setItemText(1, QCoreApplication::translate("Window", "Line", nullptr));

        label_11->setText(QCoreApplication::translate("Window", "Amount", nullptr));
        label_12->setText(QCoreApplication::translate("Window", "End Coordinate", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxLightAmount->setToolTip(QCoreApplication::translate("Window", "<html><head/><body><p>2</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBox->setItemText(toolBox->indexOf(light), QCoreApplication::translate("Window", "Light", nullptr));
        pushButtonCalculate_2->setText(QCoreApplication::translate("Window", "Calculate", nullptr));
        menuView->setTitle(QCoreApplication::translate("Window", "View", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Window", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
