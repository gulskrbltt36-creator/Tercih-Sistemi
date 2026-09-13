/********************************************************************************
** Form generated from reading UI file 'KayitEkrani.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KAYITEKRANI_H
#define UI_KAYITEKRANI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_KayitEkrani
{
public:
    QLineEdit *txtYeniTC;
    QLineEdit *txtYeniAd;
    QLineEdit *txtYeniSifre;
    QPushButton *btnTamamla;
    QLabel *lblBaslik;

    void setupUi(QDialog *KayitEkrani)
    {
        if (KayitEkrani->objectName().isEmpty())
            KayitEkrani->setObjectName("KayitEkrani");
        KayitEkrani->resize(595, 400);
        KayitEkrani->setStyleSheet(QString::fromUtf8("/* --- GENEL PENCERE AYARLARI --- */\n"
"/* Buradaki QDialog yerine pencerenin objectName'i varsa onu da yazabilirsin */\n"
"QDialog {\n"
"    /* E\304\236ER EL\304\260NDE ARKA PLAN RESM\304\260 VARSA A\305\236A\304\236IDAK\304\260 SATIRI KULLAN: */\n"
"    /* background-image: url(:/resimler/arkaplan.png); */\n"
"    /* background-position: center; */\n"
"    \n"
"    /* RES\304\260M YOKSA BENZER B\304\260R PASTEL GE\303\207\304\260\305\236 \304\260\303\207\304\260N BUNU KULLAN: */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 #E0F7FA,  /* A\303\247\304\261k mavi */\n"
"                                stop:0.5 #F3E5F5, /* A\303\247\304\261k lila */\n"
"                                stop:1 #FFF3E0); /* A\303\247\304\261k turuncu */\n"
"}\n"
"\n"
"/* --- YAZI KUTULARI (QLineEdit) --- */\n"
"QLineEdit {\n"
"    /* Hafif \305\237effaf beyaz arka plan (Glassmorphism etkisi) */\n"
"    background-color: rgba(255, 255, 255, 180); \n"
"    border: 1px solid "
                        "rgba(255, 255, 255, 0); /* Kenarl\304\261\304\237\304\261 gizle ya da \303\247ok silik yap */\n"
"    border-radius: 15px; /* Kenarlar\304\261 yuvarlat */\n"
"    padding: 8px 15px;   /* \304\260\303\247eriden bo\305\237luk b\304\261rak, yaz\304\261 yap\304\261\305\237mas\304\261n */\n"
"    font-size: 14px;\n"
"    color: #555555;      /* Yaz\304\261 rengi koyu gri */\n"
"    selection-background-color: #a6d4fa;\n"
"}\n"
"\n"
"/* Kutuya t\304\261klay\304\261nca (Focus) */\n"
"QLineEdit:focus {\n"
"    background-color: rgba(255, 255, 255, 230);\n"
"    border: 1px solid #b39ddb; /* T\304\261klan\304\261nca hafif mor bir kenarl\304\261k */\n"
"}\n"
"\n"
"/* --- BUTONLAR (QPushButton) --- */\n"
"QPushButton {\n"
"    /* 2. resimdeki 'ekle' butonu gibi pembe/lila tonu */\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, \n"
"                                      stop:0 #f8bbd0, stop:1 #f48fb1);\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 15px; /* Butonlar\304\261 da yu"
                        "varlat */\n"
"    padding: 10px 20px;\n"
"    font-size: 14px;\n"
"    border: none;\n"
"}\n"
"\n"
"/* Butonun \303\274zerine gelince */\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, \n"
"                                      stop:0 #f48fb1, stop:1 #ec407a);\n"
"}\n"
"\n"
"/* Butona bas\304\261nca */\n"
"QPushButton:pressed {\n"
"    padding-top: 12px; /* Bas\304\261lma hissi i\303\247in yaz\304\261y\304\261 az a\305\237a\304\237\304\261 kayd\304\261r */\n"
"    padding-left: 21px;\n"
"}\n"
"\n"
"/* --- ET\304\260KETLER (QLabel - E\304\237er varsa) --- */\n"
"QLabel {\n"
"    color: #4a4a4a;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 13px;\n"
"    font-weight: 600;\n"
"    background: transparent; /* Arka plan\304\261 \305\237effaf olsun ki resim g\303\266r\303\274ns\303\274n */\n"
"}\n"
"\n"
"QLabel#lblBaslik {\n"
"    color: #6a1b9a; /* Di\304\237er butonlarla uyumlu koyu bir mor/lila tonu */\n"
"    font-family: \"Segoe UI\", sans-serif; /* "
                        "Modern yaz\304\261 tipi */\n"
"    font-size: 28px; /* Yaz\304\261 boyutu b\303\274y\303\274k olsun */\n"
"    font-weight: bold; /* Kal\304\261n yaz\304\261 */\n"
"    background-color: transparent; /* Arka plan \305\237effaf kals\304\261n */\n"
"    margin-bottom: 10px; /* Alttaki kutularla aras\304\261na biraz mesafe koyar */\n"
"}\n"
"\n"
"/* \304\260ste\304\237e ba\304\237l\304\261: Mouse \303\274zerine gelince hafif parlas\304\261n istersen */\n"
"QLabel#lblBaslik:hover {\n"
"    color: #8e24aa; \n"
"}\n"
""));
        txtYeniTC = new QLineEdit(KayitEkrani);
        txtYeniTC->setObjectName("txtYeniTC");
        txtYeniTC->setGeometry(QRect(210, 90, 131, 41));
        txtYeniTC->setStyleSheet(QString::fromUtf8("/* --- GENEL PENCERE AYARLARI --- */\n"
"/* Buradaki QDialog yerine pencerenin objectName'i varsa onu da yazabilirsin */\n"
"QDialog {\n"
"    /* E\304\236ER EL\304\260NDE ARKA PLAN RESM\304\260 VARSA A\305\236A\304\236IDAK\304\260 SATIRI KULLAN: */\n"
"    /* background-image: url(:/resimler/arkaplan.png); */\n"
"    /* background-position: center; */\n"
"    \n"
"    /* RES\304\260M YOKSA BENZER B\304\260R PASTEL GE\303\207\304\260\305\236 \304\260\303\207\304\260N BUNU KULLAN: */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 #E0F7FA,  /* A\303\247\304\261k mavi */\n"
"                                stop:0.5 #F3E5F5, /* A\303\247\304\261k lila */\n"
"                                stop:1 #FFF3E0); /* A\303\247\304\261k turuncu */\n"
"}\n"
"\n"
"/* --- YAZI KUTULARI (QLineEdit) --- */\n"
"QLineEdit {\n"
"    /* Hafif \305\237effaf beyaz arka plan (Glassmorphism etkisi) */\n"
"    background-color: rgba(255, 255, 255, 180); \n"
"    border: 1px solid "
                        "rgba(255, 255, 255, 0); /* Kenarl\304\261\304\237\304\261 gizle ya da \303\247ok silik yap */\n"
"    border-radius: 15px; /* Kenarlar\304\261 yuvarlat */\n"
"    padding: 8px 15px;   /* \304\260\303\247eriden bo\305\237luk b\304\261rak, yaz\304\261 yap\304\261\305\237mas\304\261n */\n"
"    font-size: 14px;\n"
"    color: #555555;      /* Yaz\304\261 rengi koyu gri */\n"
"    selection-background-color: #a6d4fa;\n"
"}\n"
"\n"
"/* Kutuya t\304\261klay\304\261nca (Focus) */\n"
"QLineEdit:focus {\n"
"    background-color: rgba(255, 255, 255, 230);\n"
"    border: 1px solid #b39ddb; /* T\304\261klan\304\261nca hafif mor bir kenarl\304\261k */\n"
"}\n"
"\n"
"/* --- BUTONLAR (QPushButton) --- */\n"
"QPushButton {\n"
"    /* 2. resimdeki 'ekle' butonu gibi pembe/lila tonu */\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, \n"
"                                      stop:0 #f8bbd0, stop:1 #f48fb1);\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 15px; /* Butonlar\304\261 da yu"
                        "varlat */\n"
"    padding: 10px 20px;\n"
"    font-size: 14px;\n"
"    border: none;\n"
"}\n"
"\n"
"/* Butonun \303\274zerine gelince */\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, \n"
"                                      stop:0 #f48fb1, stop:1 #ec407a);\n"
"}\n"
"\n"
"/* Butona bas\304\261nca */\n"
"QPushButton:pressed {\n"
"    padding-top: 12px; /* Bas\304\261lma hissi i\303\247in yaz\304\261y\304\261 az a\305\237a\304\237\304\261 kayd\304\261r */\n"
"    padding-left: 21px;\n"
"}\n"
"\n"
"/* --- ET\304\260KETLER (QLabel - E\304\237er varsa) --- */\n"
"QLabel {\n"
"    color: #4a4a4a;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 13px;\n"
"    font-weight: 600;\n"
"    background: transparent; /* Arka plan\304\261 \305\237effaf olsun ki resim g\303\266r\303\274ns\303\274n */\n"
"}"));
        txtYeniAd = new QLineEdit(KayitEkrani);
        txtYeniAd->setObjectName("txtYeniAd");
        txtYeniAd->setGeometry(QRect(210, 140, 131, 41));
        txtYeniSifre = new QLineEdit(KayitEkrani);
        txtYeniSifre->setObjectName("txtYeniSifre");
        txtYeniSifre->setGeometry(QRect(210, 190, 131, 41));
        txtYeniSifre->setEchoMode(QLineEdit::Password);
        btnTamamla = new QPushButton(KayitEkrani);
        btnTamamla->setObjectName("btnTamamla");
        btnTamamla->setGeometry(QRect(190, 270, 151, 41));
        lblBaslik = new QLabel(KayitEkrani);
        lblBaslik->setObjectName("lblBaslik");
        lblBaslik->setGeometry(QRect(80, 20, 401, 61));
        lblBaslik->setAlignment(Qt::AlignCenter);

        retranslateUi(KayitEkrani);

        QMetaObject::connectSlotsByName(KayitEkrani);
    } // setupUi

    void retranslateUi(QDialog *KayitEkrani)
    {
        KayitEkrani->setWindowTitle(QCoreApplication::translate("KayitEkrani", "KayitEkrani", nullptr));
        txtYeniTC->setPlaceholderText(QCoreApplication::translate("KayitEkrani", "TC Giriniz..", nullptr));
        txtYeniAd->setPlaceholderText(QCoreApplication::translate("KayitEkrani", "\304\260sim Giriniz...", nullptr));
        txtYeniSifre->setPlaceholderText(QCoreApplication::translate("KayitEkrani", "\305\236ifre Giriniz...", nullptr));
        btnTamamla->setText(QCoreApplication::translate("KayitEkrani", "Kayd\304\261 Tamamla", nullptr));
        lblBaslik->setText(QCoreApplication::translate("KayitEkrani", "Aram\304\261za Kat\304\261l...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KayitEkrani: public Ui_KayitEkrani {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KAYITEKRANI_H
