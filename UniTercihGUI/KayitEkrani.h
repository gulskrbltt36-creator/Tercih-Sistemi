#pragma once
#ifndef KAYITEKRANI_H      
#define KAYITEKRANI_H      

#include <QDialog>
#include "OgrenciYonetim.h" 

namespace Ui {
    class KayitEkrani; 
}

class KayitEkrani : public QDialog
{
    Q_OBJECT

public:
    
    explicit KayitEkrani(OgrenciSistemi* sistemAdresi, QWidget* parent = nullptr);
    ~KayitEkrani();

private slots:
    void on_btnTamamla_clicked();

private:
    Ui::KayitEkrani* ui;
    OgrenciSistemi* veritabani; 
};

#endif 