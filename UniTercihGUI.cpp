#include "UniTercihGUI.h"
#include "University.h"
#include "LinkedList.h"
#include <QListWidgetItem>
#include <QMessageBox>
#include <QPushButton>
#include "AI.h"
#include <QFile>
#include <QTextStream>

UniTercihGUI::UniTercihGUI(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::UniTercihGUIClass)
{
    ui->setupUi(this);

    DataLoader::loadData("universiteler.txt", uniListesi, aramaMotoru);

    kutulariHazirla();
    ui->lstTercihler->setSelectionMode(QAbstractItemView::ExtendedSelection);

    ui->sliderSimulasyon->setRange(1, 2000000);
    ui->sliderSimulasyon->setValue(50000);

    connect(ui->txtSiralama, &QLineEdit::textChanged, this, [=]() {
        int girilenSira = ui->txtSiralama->text().toInt();
        if (girilenSira > 0) {
            ui->sliderSimulasyon->setValue(girilenSira);
            listeyiGuncelle(girilenSira);
        }
        });

    connect(ui->sliderSimulasyon, &QSlider::valueChanged, this, [=](int val) {

        ui->txtSiralama->setText(QString::number(val));
        listeyiGuncelle(val);

        });


    connect(ui->txtChat, &QLineEdit::returnPressed, this, [=]() {
        QString komut = ui->txtChat->text().toLower();

        if (komut.isEmpty()) return;

        if (komut.contains("sirala") || komut.contains("duzenle") || komut.contains("optimize")) {
            ui->btnAI->click();
            QMessageBox::information(this, "AI Asistan", "Emredersiniz! Listeniz kazanma ihtimaline gore optimize edildi.");
        }
        else if (komut.contains("temizle") || komut.contains("sil")) {
            kutulariHazirla();
            QMessageBox::information(this, "AI Asistan", "Tercih listeniz tamamen temizlendi.");
        }

        else {
            QMessageBox::information(this, "AI Asistan", "Komut anlaşılamadı. 'Sirala', 'Temizle', 'Rapor' diyebilirsin.");
        }
        ui->txtChat->clear();
        });


    connect(ui->btnYukari, &QPushButton::clicked, this, [=]() {
        int satir = ui->lstTercihler->currentRow();
        if (satir <= 0) return;

        University uni = linkedList.get(satir + 1);

        linkedList.removeAt(satir + 1);
        linkedList.insertAt(satir, uni);

        listeyiGuncelle(ui->txtSiralama->text().toInt());
        ui->lstTercihler->setCurrentRow(satir - 1);
        });

    connect(ui->btnAsagi, &QPushButton::clicked, this, [=]() {
        int satir = ui->lstTercihler->currentRow();
        if (satir < 0 || satir >= linkedList.getCount() - 1) return;

        University uni = linkedList.get(satir + 1);

        linkedList.removeAt(satir + 1);
        linkedList.insertAt(satir + 2, uni);

        listeyiGuncelle(ui->txtSiralama->text().toInt());
        ui->lstTercihler->setCurrentRow(satir + 1);
        });


    connect(ui->btnSil, &QPushButton::clicked, this, [=]() {
        int seciliSatir = ui->lstTercihler->currentRow();

        if (seciliSatir >= 0) {
            QListWidgetItem* item = ui->lstTercihler->currentItem();
            int id = item->data(Qt::UserRole).toInt();

            if (id > 0) {

                undoStack.push(seciliSatir + 1, id);
                linkedList.removeAt(seciliSatir + 1);

                listeyiGuncelle(ui->txtSiralama->text().toInt());
            }
        }
        });


    connect(ui->btnGeriAl, &QPushButton::clicked, this, [=]() {
        if (undoStack.isEmpty()) {
            QMessageBox::information(this, "Bilgi", "Geri alinacak silme islemi bulunamadi.");
            return;
        }

        DeletedItem sonSilinen = undoStack.pop();

        int idx = uniListesi.binarySearchByID(sonSilinen.uniID);
        if (idx != -1) {
            University uni = uniListesi.get(idx);

            linkedList.insertAt(sonSilinen.index, uni);


            listeyiGuncelle(ui->txtSiralama->text().toInt());

            ui->lstTercihler->setCurrentRow(sonSilinen.index - 1);
        }
        });

    connect(ui->btnRapor, &QPushButton::clicked, this, [=]() {
        QString dosyaYolu = QFileDialog::getSaveFileName(this, "Raporu Kaydet", "", "Text Files (*.txt)");
        if (dosyaYolu.isEmpty()) return;

        QFile file(dosyaYolu);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "=== TERCİH VE RİSK RAPORU ===\n";
            out << "Tarih: " << QDate::currentDate().toString() << "\n";
            out << "Ogrenci Siralamasi: " << ui->txtSiralama->text() << "\n\n";

            for (int i = 0; i < 24; i++) {
                if (ui->lstTercihler->item(i)->data(Qt::UserRole).toInt() != 0) {
                    out << ui->lstTercihler->item(i)->text() << "\n";
                }
            }
            out << "\n--- AI Tarafindan Analiz Edilmistir ---";
            file.close();
            QMessageBox::information(this, "Basarili", "Rapor  kaydedildi!");
        }
        });

    connect(ui->btnKiyasla, &QPushButton::clicked, this, [=]() {

        QList<QListWidgetItem*> secilenler = ui->lstTercihler->selectedItems();

        if (secilenler.size() != 2) {
            QMessageBox::warning(this, "Eksik Secim",
                "Lutfen listenizden kiyaslamak istediginiz 2 universiteyi secin.\n"
                "(Klavyedeki CTRL tusuna basili tutarak secim yapabilirsiniz)");
            return;
        }

        int id1 = secilenler[0]->data(Qt::UserRole).toInt();
        int id2 = secilenler[1]->data(Qt::UserRole).toInt();

        if (id1 == 0 || id2 == 0) {
            QMessageBox::warning(this, "Hatali Secim", "Bos kutulari kiyaslayamazsiniz!");
            return;
        }

        University& u1 = uniListesi.get(uniListesi.binarySearchByID(id1));
        University& u2 = uniListesi.get(uniListesi.binarySearchByID(id2));

        QString rapor = "=== DETAYLI KARŞILAŞTIRMA ===\n\n";

        rapor += "1. ADAY: " + QString::fromStdString(u1.name) + "  " + QString::fromStdString(u1.department) + "\n";
        rapor += "2. ADAY: " + QString::fromStdString(u2.name) + "  " + QString::fromStdString(u2.department) + "\n";
        rapor += "--------------------------------------\n";


        rapor += QString("Sıralama:\t%1 vs %2\n").arg(u1.rank).arg(u2.rank);
        if (u1.rank > u2.rank)
            rapor += "🏆 Sıralamam Avantajı: 1. Aday (Daha prestijli olabilir)\n";
        else rapor += "🏆 Sıralama Avantajı: 2. Aday (Daha prestijli olabilir)\n";

        rapor += "\n";


        rapor += QString("Kontenjan:\t%1 vs %2\n").arg(u1.quota).arg(u2.quota);
        if (u1.quota > u2.quota)
            rapor += "🟢 Yerleşme Kolaylığı: 1. Adayda kontenjan daha bol.\n";
        else rapor += "🟢 Yerleşme Kolaylığı: 2. Adayda kontenjan daha bol.\n";

        rapor += "\n--------------------------------------\n";
        rapor += "--- AI YAŞAM VE YURT ANALİZİ ---\n";



        auto yurtYorumu = [](int tier) -> QString {
            if (tier == 1) return "Büyükşehir. Kiralar yüksek, KYK çıkma ihtimali zor olabilir. Özel yurt bakılmalı.";
            if (tier == 2) return "Orta ölçekli şehir. Yurt imkanları dengeli, ulaşım nispeten kolay.";
            return "Öğrenci dostu şehir. KYK yurdu çıkma ihtimali çok yüksek, yaşam ucuz.";
            };

        rapor += "1. ADAY (" + QString::fromStdString(u1.name) + "):\n";
        rapor += "-> " + yurtYorumu(u1.cityTier) + "\n\n";

        rapor += "2. ADAY (" + QString::fromStdString(u2.name) + "):\n";
        rapor += "-> " + yurtYorumu(u2.cityTier) + "\n";


        QMessageBox::information(this, "Kiyaslama Sonucu", rapor);
        });

    connect(ui->txtArama, &QLineEdit::textChanged, this, [=](const QString& text) {
        ui->IstSonuclar->clear();
        if (text.length() < 2) return;
        IDList sonuclar = aramaMotoru.getSuggestions(text.toStdString());
        for (int i = 0; i < sonuclar.size(); i++) {
            int id = sonuclar.get(i);
            int index = uniListesi.binarySearchByID(id);
            if (index != -1) {
                University& u = uniListesi.get(index);


                QListWidgetItem* item = new QListWidgetItem(
                    QString::fromStdString(u.name + " - " + u.department)
                );
                item->setData(Qt::UserRole, id);
                ui->IstSonuclar->addItem(item);
            }
        }});


        connect(ui->IstSonuclar, &QListWidget::itemClicked, this, [=](QListWidgetItem* item) {


            int id = item->data(Qt::UserRole).toInt();
            int index = uniListesi.binarySearchByID(id);

            if (index == -1) return;

            University& u = uniListesi.get(index);

            int mevcutSiralama = ui->txtSiralama->text().toInt();
            if (mevcutSiralama == 0) mevcutSiralama = 1;

            AI::Prediction rapor = AI::analyze(mevcutSiralama, u);

            int ihtimal = (int)rapor.percent;

            ui->progressBarRisk->setValue(ihtimal);

            QString stil;
            if (ihtimal >= 80) {
                stil = "QProgressBar::chunk { background-color: #2ecc71; }";
            }
            else if (ihtimal >= 40) {
                stil = "QProgressBar::chunk { background-color: #f1c40f; }";
            }
            else {
                stil = "QProgressBar::chunk { background-color: #e74c3c; }";
            }
            ui->progressBarRisk->setStyleSheet(stil + "QProgressBar { text-align: center; font-weight: bold; }");
            ui->progressBarRisk->setToolTip(QString::fromStdString(rapor.message));
            });


        connect(ui->lstTercihler, &QListWidget::itemClicked, this, [=](QListWidgetItem* item) {
            int id = item->data(Qt::UserRole).toInt();
            if (id == 0) {
                ui->progressBarRisk->setValue(0);
                return;
            }

            });

        connect(ui->btnEkle, &QPushButton::clicked, this, [=]() {

            if (ui->IstSonuclar->selectedItems().isEmpty()) {
                QMessageBox::warning(this, "Uyarı", "Lütfen listeden bir bölüm seçin!");
                return;
            }

            QListWidgetItem* seciliItem = ui->IstSonuclar->selectedItems().first();
            int eklenecekID = seciliItem->data(Qt::UserRole).toInt();

            if (linkedList.contains(eklenecekID)) {
                QMessageBox::critical(this, "Hata", "Bu bölümü zaten listenize eklediniz!");
                return;
            }

         
            University* gercekUni = getUniById(eklenecekID);

            if (gercekUni == nullptr) {
                QMessageBox::critical(this, "Hata", "Veritabanında veri bulunamadı!");
                return;
            }
            University kopyalanacakUni = *gercekUni;

            int hedefSatir = ui->lstTercihler->currentRow();

            if (hedefSatir >= 0) {
         
                linkedList.insertAt(hedefSatir + 1, kopyalanacakUni);
            }
            else {
              
                linkedList.add(kopyalanacakUni);
            }
            int kullaniciSiralamasi = ui->txtSiralama->text().toInt();
            if (kullaniciSiralamasi == 0) kullaniciSiralamasi = 100000; 

            listeyiGuncelle(kullaniciSiralamasi);

        
            ui->IstSonuclar->clearSelection();
            ui->lstTercihler->clearSelection();
            });


    connect(ui->btnAI, &QPushButton::clicked, this, [=]() {
        PriorityQueue pq;
        int mevcutSira = ui->txtSiralama->text().toInt();

        Node* current = linkedList.getHead();
        while (current != nullptr) {
            int id = current->data.id;
            int idx = uniListesi.binarySearchByID(id);

            if (idx != -1) {
                University& u = uniListesi.get(idx);
                AI::Prediction rapor = AI::analyze(mevcutSira, u);
                pq.push(u, rapor.percent);
            }
            current = current->next;
        }

        linkedList.clear();
        while (!pq.isEmpty()) {
            linkedList.add(pq.pop());
        }

        listeyiGuncelle(mevcutSira);
        });
}

University* UniTercihGUI::getUniById(int id)
{
    for (int i = 0; i < uniListesi.getSize(); i++) {
        University* u = &uniListesi.get(i);

        if (u->id == id) {
            return u;
        }
    }
    return nullptr; 
}
UniTercihGUI::~UniTercihGUI() { delete ui; }


void UniTercihGUI::kutulariHazirla() {
    ui->lstTercihler->clear();
    for (int i = 1; i <= 24; i++) {
        QListWidgetItem* item = new QListWidgetItem(QString::number(i) + ". --- BOS ---");
        item->setData(Qt::UserRole, 0);
        item->setForeground(QColor(150, 150, 150));
        ui->lstTercihler->addItem(item);
    }
}
void UniTercihGUI::listeyiGuncelle(int simuleSiralama) {
    if (simuleSiralama <= 0) simuleSiralama = 1;

    ui->lstTercihler->clear();

    Node* current = linkedList.getHead();
    int siraNo = 1;
    while (current != nullptr) {
        University& u = current->data;

        QListWidgetItem* item = new QListWidgetItem();
        item->setData(Qt::UserRole, u.id); 

        AI::Prediction rapor = AI::analyze(simuleSiralama, u);
        QString durumEtiketi;
        

        if (rapor.percent >= 80.0) {
            durumEtiketi = " [BANKO - GELIR]";
          
        }
        else if (rapor.percent >= 40.0) {
            durumEtiketi = " [PLASE - SURPRIZ]";
          
        }
        else {
            durumEtiketi = " [RISKLI - GELMEZ]";
       
        }

        QString tamMetin = QString::number(siraNo) + ". " +
            QString::fromStdString(u.name) + " - " +
            QString::fromStdString(u.department) +
            durumEtiketi + " %" + QString::number((int)rapor.percent);

        item->setText(tamMetin);
        item->setForeground(Qt::black);
        ui->lstTercihler->addItem(item);
        current = current->next;
        siraNo++;
    }

    for (int i = siraNo; i <= 24; i++) {
        QListWidgetItem* bosItem = new QListWidgetItem(QString::number(i) + ". --- BOS ---");
        bosItem->setData(Qt::UserRole, 0);
        bosItem->setBackground(QColor(45, 45, 45));
        bosItem->setForeground(Qt::gray);
        ui->lstTercihler->addItem(bosItem);
    }
}