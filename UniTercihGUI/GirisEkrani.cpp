#include "GirisEkrani.h"
#include "KayitEkrani.h" 
#include <QMessageBox>

GirisEkrani::GirisEkrani(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("Giris Ekrani");

    sistem = new OgrenciSistemi(1000);

}

GirisEkrani::~GirisEkrani()
{
  
    delete sistem;
}

void GirisEkrani::on_btnGiris_clicked()
{
    QString kadi = ui.txtKullanici->text();
    QString sifre = ui.txtSifre->text();

    if (sistem->GirisYap(kadi.toStdString(), sifre.toStdString())) {
       
        accept();
    }
  
    else {
        QMessageBox::warning(this, "Hata", "Kullanici adi veya sifre yanlis!");
    }
}


void GirisEkrani::on_btnKayitOl_clicked()
{
   
    KayitEkrani* yeniEkran = new KayitEkrani(sistem, this);

    yeniEkran->exec();
    this->show();

    delete yeniEkran;
}