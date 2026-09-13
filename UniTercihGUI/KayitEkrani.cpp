#include "KayitEkrani.h"
#include "ui_KayitEkrani.h"
#include <QMessageBox>

KayitEkrani::KayitEkrani(OgrenciSistemi* sistemAdresi, QWidget* parent) :
    QDialog(parent),
    ui(new Ui::KayitEkrani)
{
    ui->setupUi(this);
    this->setWindowTitle("Kayit Paneli");

    veritabani = sistemAdresi;

}

KayitEkrani::~KayitEkrani()
{
    delete ui;
}

void KayitEkrani::on_btnTamamla_clicked()
{
    QString tc = ui->txtYeniTC->text();
    QString ad = ui->txtYeniAd->text();
    QString sifre = ui->txtYeniSifre->text();

    if (tc.isEmpty() || ad.isEmpty() || sifre.isEmpty()) {
        QMessageBox::warning(this, "Hata", "Bos alan birakmayiniz!");
        return;
    }

    veritabani->KayitEkle(tc.toStdString(), ad.toStdString(), sifre.toStdString());

    QMessageBox::information(this, "Basarili", "Kayit yapildi! Giris yapabilirsiniz.");
    this->accept();
}