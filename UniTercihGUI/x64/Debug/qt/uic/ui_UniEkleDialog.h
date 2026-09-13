/********************************************************************************
** Form generated from reading UI file 'UniEkleDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNIEKLEDIALOG_H
#define UI_UNIEKLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UniEkleDialogClass
{
public:
    QLineEdit *txtUniAd;
    QLineEdit *txtBolum;
    QLineEdit *txtSehir;
    QLineEdit *txtPuan;
    QLineEdit *txtSira;
    QLineEdit *txtOncekiSira;
    QPushButton *btnKaydet;
    QListWidget *lstTumUniversiteler;
    QPushButton *btnUniSil;
    QLineEdit *txtkontenjan;
    QLineEdit *txtID;

    void setupUi(QDialog *UniEkleDialogClass)
    {
        if (UniEkleDialogClass->objectName().isEmpty())
            UniEkleDialogClass->setObjectName("UniEkleDialogClass");
        UniEkleDialogClass->resize(817, 626);
        UniEkleDialogClass->setStyleSheet(QString::fromUtf8("/* --- GENEL PENCERE --- */\n"
"QDialog {\n"
"    /* Di\304\237er ekranlarla ayn\304\261 pastel ge\303\247i\305\237 */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 #E0F7FA, \n"
"                                stop:0.5 #F3E5F5, \n"
"                                stop:1 #FFF3E0);\n"
"}\n"
"\n"
"/* --- YAZI KUTULARI (6 Adet Veri Giri\305\237i) --- */\n"
"QLineEdit {\n"
"    background-color: rgba(255, 255, 255, 180); \n"
"    border: 1px solid rgba(255, 255, 255, 0); \n"
"    border-radius: 15px; \n"
"    padding: 8px 15px;\n"
"    font-size: 13px; /* \303\207ok kutu oldu\304\237u i\303\247in yaz\304\261y\304\261 bir t\304\261k k\303\274\303\247\303\274ltt\303\274k */\n"
"    color: #555555;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    background-color: rgba(255, 255, 255, 230);\n"
"    border: 1px solid #b39ddb; \n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: rgba(80, 80, 80, 150);\n"
"    font-style: italic;\n"
"}\n"
"\n"
"/* --- BUTONLAR (Kaydet"
                        " ve Sil) --- */\n"
"QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, \n"
"                                      stop:0 #f8bbd0, stop:1 #f48fb1);\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 15px;\n"
"    padding: 10px 20px;\n"
"    font-size: 14px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, \n"
"                                      stop:0 #f48fb1, stop:1 #ec407a);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    padding-top: 12px;\n"
"    padding-left: 21px;\n"
"}\n"
"\n"
"/* --- SA\304\236DAK\304\260 L\304\260STE (QListWidget veya QTableWidget) --- */\n"
"/* Bu k\304\261s\304\261m o b\303\274y\303\274k beyaz alan\304\261 s\303\274sler */\n"
"QListWidget, QTableWidget {\n"
"    background-color: rgba(255, 255, 255, 150); /* Yar\304\261 \305\237effaf arka plan */\n"
"    border: 1px solid rgba(255, 255, 255, 200);\n"
"    border-radius: 15px;\n"
"    color: #444;\n"
"    padding"
                        ": 10px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* Listede bir \305\237eye t\304\261klay\304\261nca (Se\303\247ili \303\226\304\237e) */\n"
"QListWidget::item:selected, QTableWidget::item:selected {\n"
"    background-color: #ba68c8; /* Mor/Lila se\303\247im rengi */\n"
"    color: white;\n"
"    border-radius: 10px; /* Se\303\247ili sat\304\261r\304\261n kenarlar\304\261 yuvarlans\304\261n */\n"
"}\n"
"\n"
"/* Listenin Kayd\304\261rma \303\207ubu\304\237u (Scrollbar) - \303\207ok \305\237\304\261k dursun */\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: rgba(0,0,0,0.05);\n"
"    width: 8px;\n"
"    margin: 0px 0px 0px 0px;\n"
"    border-radius: 4px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: #ce93d8;\n"
"    min-height: 20px;\n"
"    border-radius: 4px;\n"
"}"));
        txtUniAd = new QLineEdit(UniEkleDialogClass);
        txtUniAd->setObjectName("txtUniAd");
        txtUniAd->setGeometry(QRect(50, 180, 141, 41));
        txtBolum = new QLineEdit(UniEkleDialogClass);
        txtBolum->setObjectName("txtBolum");
        txtBolum->setGeometry(QRect(50, 250, 141, 41));
        txtSehir = new QLineEdit(UniEkleDialogClass);
        txtSehir->setObjectName("txtSehir");
        txtSehir->setGeometry(QRect(280, 330, 141, 41));
        txtPuan = new QLineEdit(UniEkleDialogClass);
        txtPuan->setObjectName("txtPuan");
        txtPuan->setGeometry(QRect(50, 330, 141, 41));
        txtSira = new QLineEdit(UniEkleDialogClass);
        txtSira->setObjectName("txtSira");
        txtSira->setGeometry(QRect(280, 100, 141, 41));
        txtOncekiSira = new QLineEdit(UniEkleDialogClass);
        txtOncekiSira->setObjectName("txtOncekiSira");
        txtOncekiSira->setGeometry(QRect(280, 250, 141, 41));
        btnKaydet = new QPushButton(UniEkleDialogClass);
        btnKaydet->setObjectName("btnKaydet");
        btnKaydet->setGeometry(QRect(190, 420, 111, 41));
        lstTumUniversiteler = new QListWidget(UniEkleDialogClass);
        lstTumUniversiteler->setObjectName("lstTumUniversiteler");
        lstTumUniversiteler->setGeometry(QRect(500, 20, 311, 391));
        btnUniSil = new QPushButton(UniEkleDialogClass);
        btnUniSil->setObjectName("btnUniSil");
        btnUniSil->setGeometry(QRect(584, 430, 201, 41));
        txtkontenjan = new QLineEdit(UniEkleDialogClass);
        txtkontenjan->setObjectName("txtkontenjan");
        txtkontenjan->setGeometry(QRect(280, 180, 151, 41));
        txtID = new QLineEdit(UniEkleDialogClass);
        txtID->setObjectName("txtID");
        txtID->setGeometry(QRect(50, 100, 141, 41));

        retranslateUi(UniEkleDialogClass);

        QMetaObject::connectSlotsByName(UniEkleDialogClass);
    } // setupUi

    void retranslateUi(QDialog *UniEkleDialogClass)
    {
        UniEkleDialogClass->setWindowTitle(QCoreApplication::translate("UniEkleDialogClass", "UniEkleDialog", nullptr));
        txtUniAd->setPlaceholderText(QCoreApplication::translate("UniEkleDialogClass", "\303\234niversite Ad\304\261", nullptr));
        txtBolum->setPlaceholderText(QCoreApplication::translate("UniEkleDialogClass", "B\303\266l\303\274m", nullptr));
        txtSehir->setPlaceholderText(QCoreApplication::translate("UniEkleDialogClass", "\305\236ehir Puan\304\261", nullptr));
        txtPuan->setPlaceholderText(QCoreApplication::translate("UniEkleDialogClass", "Puan", nullptr));
        txtSira->setPlaceholderText(QCoreApplication::translate("UniEkleDialogClass", "S\304\261ralama", nullptr));
        txtOncekiSira->setPlaceholderText(QCoreApplication::translate("UniEkleDialogClass", "\303\226nceki S\304\261ralama", nullptr));
        btnKaydet->setText(QCoreApplication::translate("UniEkleDialogClass", "KAYDET", nullptr));
        btnUniSil->setText(QCoreApplication::translate("UniEkleDialogClass", "Se\303\247ili \303\234niversiteyi Sil", nullptr));
        txtkontenjan->setText(QString());
        txtkontenjan->setPlaceholderText(QCoreApplication::translate("UniEkleDialogClass", " Kontenjan", nullptr));
        txtID->setPlaceholderText(QCoreApplication::translate("UniEkleDialogClass", "         ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UniEkleDialogClass: public Ui_UniEkleDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNIEKLEDIALOG_H
