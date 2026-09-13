#include "UniTercihGUI.h"   
#include <QtWidgets/QApplication>
#include "GirisEkrani.h"       
#include <fstream> 
#include "University.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    GirisEkrani giris;

    if (giris.exec() == QDialog::Accepted) {

            UniTercihGUI ogrenciEkrani;

            ogrenciEkrani.show();

            return a.exec();
        }
  
    return 0;
}