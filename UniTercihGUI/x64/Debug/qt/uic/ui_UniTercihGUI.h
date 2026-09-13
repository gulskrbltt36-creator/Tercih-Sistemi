/********************************************************************************
** Form generated from reading UI file 'UniTercihGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNITERCIHGUI_H
#define UI_UNITERCIHGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UniTercihGUIClass
{
public:
    QWidget *centralWidget;
    QListWidget *lstTercihler;
    QLineEdit *txtArama;
    QListWidget *IstSonuclar;
    QPushButton *btnAsagi;
    QPushButton *btnYukari;
    QLineEdit *txtChat;
    QSlider *sliderSimulasyon;
    QLabel *lblSimulasyon;
    QProgressBar *progressBarRisk;
    QPushButton *btnRapor;
    QPushButton *btnEkle;
    QPushButton *btnKiyasla;
    QPushButton *btnAI;
    QLabel *label_2;
    QLineEdit *txtSiralama;
    QPushButton *btnSil;
    QPushButton *btnGeriAl;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UniTercihGUIClass)
    {
        if (UniTercihGUIClass->objectName().isEmpty())
            UniTercihGUIClass->setObjectName("UniTercihGUIClass");
        UniTercihGUIClass->resize(1260, 700);
        UniTercihGUIClass->setStyleSheet(QString::fromUtf8("/* === 1. ARKA PLAN RESM\304\260 === */\n"
"QWidget#centralWidget {\n"
"    /* Senin ayarlad\304\261\304\237\304\261n yol buras\304\261 */\n"
"    border-image: url(:/UniTercihGUI/images/background.jpg) 0 0 0 0 stretch stretch;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"}\n"
"\n"
"/* === 2. BUZLU CAM PANELLER (SOL VE SA\304\236 KUTULAR) === */\n"
"QFrame#solPanel, QFrame#sagPanel {\n"
"    /* Yar\304\261 saydam beyaz renk */\n"
"    background-color: rgba(255, 255, 255, 170); \n"
"    border-radius: 20px; /* K\303\266\305\237eleri yuvarlat */\n"
"    border: 1px solid rgba(255, 255, 255, 120); /* Hafif beyaz \303\247izgi */\n"
"}\n"
"\n"
"/* === 3. SOLDAK\304\260 L\304\260STE G\303\226R\303\234N\303\234M\303\234 === */\n"
"QListWidget {\n"
"    background-color: transparent; /* Listenin kendi arkas\304\261 \305\237effaf olsun */\n"
"    border: none;\n"
"    outline: none;\n"
"}\n"
"QListWidget::item {\n"
"    color: #444;\n"
"    padding: 10px;\n"
"    margin: 4px;\n"
"    border-radius: 10px;\n"
"}\n"
""
                        "QListWidget::item:hover {\n"
"    background-color: rgba(255, 255, 255, 200); /* \303\234zerine gelince parlas\304\261n */\n"
"}\n"
"QListWidget::item:selected {\n"
"    /* Se\303\247ilince Mavi-Turkuaz olsun */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #a1c4fd, stop:1 #c2e9fb);\n"
"    color: white;\n"
"}\n"
"\n"
"/* === 4. NORMAL BUTONLAR (Temizle, Ekle vb.) === */\n"
"\n"
"QPushButton {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* Yar\304\261 saydam beyaz */\n"
"    color: #333333; /* Yaz\304\261 rengi koyu gri (okunabilirlik i\303\247in) */\n"
"    border: 2px solid #ffffff; /* Kal\304\261n beyaz \303\247er\303\247eve */\n"
"    border-radius: 15px; /* Yuvarlak k\303\266\305\237eler */\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.5); /* \303\234zerine gelince biraz daha beyazla\305\237\304\261r */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.1); /* T\304\261klan\304\261nca "
                        "\305\237effafla\305\237\304\261r */\n"
"}\n"
"\n"
"/* === 5. S\304\260H\304\260RL\304\260 B\303\234Y\303\234K BUTON === */\n"
"QPushButton#sihirliButon {\n"
"    /* Mavi-Ye\305\237ilimsi \303\266zel renk */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #8fd3f4, stop:1 #84fab0);\n"
"    border-radius: 30px; /* Tam yuvarlak */\n"
"    font-size: 16px;\n"
"    padding: 15px 40px;\n"
"    border: 2px solid rgba(255,255,255, 0.7);\n"
"}\n"
"QPushButton#sihirliButon:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #a0e0ff, stop:1 #9dfbc0);\n"
"    margin-top: -2px; /* Hafif yukar\304\261 z\304\261plama efekti */\n"
"}\n"
"\n"
"/* === 6. YAZI KUTULARI (Inputlar) === */\n"
"QLineEdit, QComboBox {\n"
"    background-color: rgba(255, 255, 255, 200);\n"
"    border: 1px solid white;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    color: #444;\n"
"}"));
        centralWidget = new QWidget(UniTercihGUIClass);
        centralWidget->setObjectName("centralWidget");
        lstTercihler = new QListWidget(centralWidget);
        lstTercihler->setObjectName("lstTercihler");
        lstTercihler->setGeometry(QRect(0, 0, 256, 661));
        txtArama = new QLineEdit(centralWidget);
        txtArama->setObjectName("txtArama");
        txtArama->setGeometry(QRect(860, 20, 341, 31));
        IstSonuclar = new QListWidget(centralWidget);
        IstSonuclar->setObjectName("IstSonuclar");
        IstSonuclar->setGeometry(QRect(890, 50, 301, 192));
        btnAsagi = new QPushButton(centralWidget);
        btnAsagi->setObjectName("btnAsagi");
        btnAsagi->setGeometry(QRect(270, 280, 75, 31));
        btnYukari = new QPushButton(centralWidget);
        btnYukari->setObjectName("btnYukari");
        btnYukari->setGeometry(QRect(270, 240, 75, 31));
        txtChat = new QLineEdit(centralWidget);
        txtChat->setObjectName("txtChat");
        txtChat->setGeometry(QRect(310, 600, 541, 31));
        sliderSimulasyon = new QSlider(centralWidget);
        sliderSimulasyon->setObjectName("sliderSimulasyon");
        sliderSimulasyon->setGeometry(QRect(320, 340, 211, 18));
        sliderSimulasyon->setOrientation(Qt::Horizontal);
        lblSimulasyon = new QLabel(centralWidget);
        lblSimulasyon->setObjectName("lblSimulasyon");
        lblSimulasyon->setGeometry(QRect(550, 350, 49, 16));
        progressBarRisk = new QProgressBar(centralWidget);
        progressBarRisk->setObjectName("progressBarRisk");
        progressBarRisk->setGeometry(QRect(270, 10, 191, 23));
        progressBarRisk->setValue(24);
        btnRapor = new QPushButton(centralWidget);
        btnRapor->setObjectName("btnRapor");
        btnRapor->setGeometry(QRect(990, 260, 91, 31));
        btnEkle = new QPushButton(centralWidget);
        btnEkle->setObjectName("btnEkle");
        btnEkle->setGeometry(QRect(1100, 260, 91, 31));
        btnKiyasla = new QPushButton(centralWidget);
        btnKiyasla->setObjectName("btnKiyasla");
        btnKiyasla->setGeometry(QRect(1020, 460, 191, 41));
        btnAI = new QPushButton(centralWidget);
        btnAI->setObjectName("btnAI");
        btnAI->setGeometry(QRect(1050, 540, 141, 51));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(570, 10, 71, 20));
        txtSiralama = new QLineEdit(centralWidget);
        txtSiralama->setObjectName("txtSiralama");
        txtSiralama->setGeometry(QRect(640, 10, 113, 31));
        btnSil = new QPushButton(centralWidget);
        btnSil->setObjectName("btnSil");
        btnSil->setGeometry(QRect(270, 173, 75, 31));
        btnGeriAl = new QPushButton(centralWidget);
        btnGeriAl->setObjectName("btnGeriAl");
        btnGeriAl->setGeometry(QRect(270, 130, 81, 31));
        UniTercihGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UniTercihGUIClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1260, 22));
        UniTercihGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UniTercihGUIClass);
        mainToolBar->setObjectName("mainToolBar");
        UniTercihGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UniTercihGUIClass);
        statusBar->setObjectName("statusBar");
        UniTercihGUIClass->setStatusBar(statusBar);

        retranslateUi(UniTercihGUIClass);

        QMetaObject::connectSlotsByName(UniTercihGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *UniTercihGUIClass)
    {
        UniTercihGUIClass->setWindowTitle(QCoreApplication::translate("UniTercihGUIClass", "UniTercihGUI", nullptr));
        btnAsagi->setText(QCoreApplication::translate("UniTercihGUIClass", "v", nullptr));
        btnYukari->setText(QCoreApplication::translate("UniTercihGUIClass", "^", nullptr));
        txtChat->setPlaceholderText(QCoreApplication::translate("UniTercihGUIClass", "Sirala ,temizle, yaz....", nullptr));
        lblSimulasyon->setText(QCoreApplication::translate("UniTercihGUIClass", "TextLabel", nullptr));
        btnRapor->setText(QCoreApplication::translate("UniTercihGUIClass", "Rapor", nullptr));
        btnEkle->setText(QCoreApplication::translate("UniTercihGUIClass", "ekle", nullptr));
        btnKiyasla->setText(QCoreApplication::translate("UniTercihGUIClass", "\304\260K\304\260 B\303\226L\303\234M\303\234 KIYASLA", nullptr));
        btnAI->setText(QCoreApplication::translate("UniTercihGUIClass", "AI", nullptr));
        label_2->setText(QCoreApplication::translate("UniTercihGUIClass", "S\304\261ralaman\304\261z", nullptr));
        txtSiralama->setText(QCoreApplication::translate("UniTercihGUIClass", "50000", nullptr));
        btnSil->setText(QCoreApplication::translate("UniTercihGUIClass", "S\304\260L", nullptr));
        btnGeriAl->setText(QCoreApplication::translate("UniTercihGUIClass", "GER\304\260 AL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UniTercihGUIClass: public Ui_UniTercihGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITERCIHGUI_H
