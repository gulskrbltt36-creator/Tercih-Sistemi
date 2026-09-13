#pragma once
#ifndef OGRENCIYONETIM_H
#define OGRENCIYONETIM_H

#include <string>
#include <iostream>
#include <fstream> 

using namespace std;

struct OgrenciNode {
    string tcNo;        
    string adSoyad;     
    string sifre;      
    OgrenciNode* sonraki; 

    OgrenciNode(string tc, string ad, string pass) : tcNo(tc), adSoyad(ad), sifre(pass), sonraki(nullptr) {}
};

class OgrenciSistemi {
private:
    OgrenciNode** tablo;
    int kapasite;
    int elemanSayisi;

    int HashCode(string key) {
        unsigned long hash = 5381;
        for (char c : key) {
            hash = ((hash << 5) + hash) + c;
        }
        return hash % kapasite;
    }

    void YenidenBoyutlandir() {
        int eskiKapasite = kapasite;
        OgrenciNode** eskiTablo = tablo;
        kapasite *= 2;
        tablo = new OgrenciNode * [kapasite];
        for (int i = 0; i < kapasite; i++) tablo[i] = nullptr;

        elemanSayisi = 0;

        for (int i = 0; i < eskiKapasite; ++i) {
            OgrenciNode* gecici = eskiTablo[i];
            while (gecici != nullptr) {
                OgrenciNode* sonraki = gecici->sonraki;
                KayitEkle(gecici->tcNo, gecici->adSoyad, gecici->sifre);
                delete gecici; 
                gecici = sonraki;
            }
        }
        delete[] eskiTablo;
    }

public:
    
    OgrenciSistemi(int baslangicKapasite = 100) {
        kapasite = baslangicKapasite;
        elemanSayisi = 0;
        tablo = new OgrenciNode * [kapasite];
        for (int i = 0; i < kapasite; i++) tablo[i] = nullptr;

        DosyadanOku();
    }

 
    ~OgrenciSistemi() {
    
        DosyayaYaz();

       
        for (int i = 0; i < kapasite; i++) {
            OgrenciNode* gecici = tablo[i];
            while (gecici != nullptr) {
                OgrenciNode* sil = gecici;
                gecici = gecici->sonraki;
                delete sil;
            }
        }
        delete[] tablo;
    }

 
    void KayitEkle(string tc, string ad, string pass) {
        if ((double)elemanSayisi / kapasite >= 0.75) {
            YenidenBoyutlandir();
        }

        int index = HashCode(tc);
        OgrenciNode* yeni = new OgrenciNode(tc, ad, pass);

        if (tablo[index] == nullptr) {
            tablo[index] = yeni;
        }
        else {
     
            OgrenciNode* gecici = tablo[index];
            while (gecici->sonraki != nullptr) {
                gecici = gecici->sonraki;
            }
            gecici->sonraki = yeni;
        }
        elemanSayisi++;
    }

  
    bool GirisYap(string tc, string girilenSifre) {
        int index = HashCode(tc);
        OgrenciNode* gecici = tablo[index];

        while (gecici != nullptr) {
            if (gecici->tcNo == tc) {
                return (gecici->sifre == girilenSifre);
            }
            gecici = gecici->sonraki;
        }
        return false;


    }
    void DosyayaYaz() {
        ofstream dosya("ogrenci_veritabani.txt"); 
        if (!dosya.is_open()) return;

        for (int i = 0; i < kapasite; i++) {
            OgrenciNode* gecici = tablo[i];
            while (gecici != nullptr) {
                dosya << gecici->tcNo << "|"
                    << gecici->adSoyad << "|"
                    << gecici->sifre << "\n";
                gecici = gecici->sonraki;
            }
        }
        dosya.close();
    }

    void DosyadanOku() {
        ifstream dosya("ogrenci_veritabani.txt");
        if (!dosya.is_open()) return; 

        string satir;
        while (getline(dosya, satir)) {
            size_t p1 = satir.find('|');
            size_t p2 = satir.find('|', p1 + 1);

            if (p1 != string::npos && p2 != string::npos) {
                string tc = satir.substr(0, p1);
                string ad = satir.substr(p1 + 1, p2 - (p1 + 1));
                string sifre = satir.substr(p2 + 1);

               
                KayitEkle(tc, ad, sifre);
            }
        }
        dosya.close();
    }
};

#endif