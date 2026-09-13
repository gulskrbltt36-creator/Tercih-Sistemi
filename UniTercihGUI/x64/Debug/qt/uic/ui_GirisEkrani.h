/********************************************************************************
** Form generated from reading UI file 'GirisEkrani.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIRISEKRANI_H
#define UI_GIRISEKRANI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GirisEkraniClass
{
public:
    QLineEdit *txtKullanici;
    QLineEdit *txtSifre;
    QPushButton *btnGiris;
    QPushButton *btnKayitOl;
    QLabel *lblBaslik;

    void setupUi(QDialog *GirisEkraniClass)
    {
        if (GirisEkraniClass->objectName().isEmpty())
            GirisEkraniClass->setObjectName("GirisEkraniClass");
        GirisEkraniClass->resize(600, 400);
        GirisEkraniClass->setStyleSheet(QString::fromUtf8("/* --- GENEL PENCERE --- */\n"
"QDialog {\n"
"    /* Kay\304\261t ekran\304\261yla ayn\304\261 pastel ge\303\247i\305\237 */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 #E0F7FA, \n"
"                                stop:0.5 #F3E5F5, \n"
"                                stop:1 #FFF3E0);\n"
"}\n"
"\n"
"/* --- YAZI KUTULARI (Kullan\304\261c\304\261 Ad\304\261 ve \305\236ifre) --- */\n"
"QLineEdit {\n"
"    background-color: rgba(255, 255, 255, 180); \n"
"    border: 1px solid rgba(255, 255, 255, 0); \n"
"    border-radius: 15px; \n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"    color: #555555;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    background-color: rgba(255, 255, 255, 230);\n"
"    border: 1px solid #b39ddb; /* Odaklan\304\261nca mor kenarl\304\261k */\n"
"}\n"
"\n"
"/* Placeholder (Silik Yaz\304\261) Rengi */\n"
"QLineEdit::placeholder {\n"
"    color: rgba(80, 80, 80, 150);\n"
"    font-style: italic;\n"
"}\n"
"\n"
"/* --- BUTONLAR (Giri\305"
                        "\237 Yap ve Kay\304\261t Ol) --- */\n"
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
"/* --- BA\305\236LIK ET\304\260KET\304\260 (Sadece lblBaslik isimliler i\303\247in) --- */\n"
"QLabel#lblBaslik {\n"
"    color: #6a1b9a; /* Di\304\237er butonlarla uyumlu koyu bir mor/lila tonu */\n"
"    font-family: \"Segoe UI\", sans-serif; /* Modern yaz\304\261 tipi */\n"
"    font-size: 28px; /* Yaz\304\261 boyutu b\303\274y\303\274k olsun */\n"
"    font-weight: bold; /* Kal\304\261"
                        "n yaz\304\261 */\n"
"    background-color: transparent; /* Arka plan \305\237effaf kals\304\261n */\n"
"    margin-bottom: 10px; /* Alttaki kutularla aras\304\261na biraz mesafe koyar */\n"
"}\n"
"\n"
"/* \304\260ste\304\237e ba\304\237l\304\261: Mouse \303\274zerine gelince hafif parlas\304\261n istersen */\n"
"QLabel#lblBaslik:hover {\n"
"    color: #8e24aa; \n"
"}"));
        txtKullanici = new QLineEdit(GirisEkraniClass);
        txtKullanici->setObjectName("txtKullanici");
        txtKullanici->setGeometry(QRect(170, 130, 191, 41));
        txtSifre = new QLineEdit(GirisEkraniClass);
        txtSifre->setObjectName("txtSifre");
        txtSifre->setGeometry(QRect(170, 180, 191, 41));
        txtSifre->setEchoMode(QLineEdit::Password);
        btnGiris = new QPushButton(GirisEkraniClass);
        btnGiris->setObjectName("btnGiris");
        btnGiris->setGeometry(QRect(180, 240, 181, 41));
        btnKayitOl = new QPushButton(GirisEkraniClass);
        btnKayitOl->setObjectName("btnKayitOl");
        btnKayitOl->setGeometry(QRect(210, 290, 121, 41));
        btnKayitOl->setStyleSheet(QString::fromUtf8(""));
        lblBaslik = new QLabel(GirisEkraniClass);
        lblBaslik->setObjectName("lblBaslik");
        lblBaslik->setGeometry(QRect(110, 50, 321, 61));
        lblBaslik->setAlignment(Qt::AlignCenter);

        retranslateUi(GirisEkraniClass);

        QMetaObject::connectSlotsByName(GirisEkraniClass);
    } // setupUi

    void retranslateUi(QDialog *GirisEkraniClass)
    {
        GirisEkraniClass->setWindowTitle(QCoreApplication::translate("GirisEkraniClass", "GirisEkrani", nullptr));
        txtKullanici->setPlaceholderText(QCoreApplication::translate("GirisEkraniClass", "Kullanc\304\261 Ad\304\261..", nullptr));
        txtSifre->setPlaceholderText(QCoreApplication::translate("GirisEkraniClass", "\305\236ifre..", nullptr));
        btnGiris->setText(QCoreApplication::translate("GirisEkraniClass", "Giri\305\237 Yap", nullptr));
        btnKayitOl->setText(QCoreApplication::translate("GirisEkraniClass", "Kay\304\261t Ol", nullptr));
        lblBaslik->setText(QCoreApplication::translate("GirisEkraniClass", "HO\305\236 GELD\304\260N\304\260Z...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GirisEkraniClass: public Ui_GirisEkraniClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIRISEKRANI_H
