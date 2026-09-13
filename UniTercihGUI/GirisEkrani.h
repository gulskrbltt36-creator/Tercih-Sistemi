#pragma once
#include "OgrenciYonetim.h"
#include <QDialog>
#include "ui_GirisEkrani.h"


class GirisEkrani : public QDialog
{
	Q_OBJECT

public:
	GirisEkrani(QWidget *parent = nullptr);
	~GirisEkrani();
	

private:
	Ui::GirisEkraniClass ui;
	OgrenciSistemi* sistem;
private slots:

	void on_btnGiris_clicked();
	void on_btnKayitOl_clicked();
};

