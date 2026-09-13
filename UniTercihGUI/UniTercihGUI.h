#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_UniTercihGUI.h"
#include "DynamicArray.h"
#include "Trie.h"
#include "DataLoader.h"
#include "AI.h"
#include "IDList.h"
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QFileDialog>
#include "Stack.h"
#include "PRIORITYQUEUE_H.h"
#include "LinkedList.h"

class UniTercihGUI : public QMainWindow
{
    Q_OBJECT

public:
    UniTercihGUI(QWidget* parent = nullptr);
    ~UniTercihGUI();


private:
    Ui::UniTercihGUIClass* ui;

    DynamicArray uniListesi;
    Trie aramaMotoru;
    Stack undoStack;
    LinkedList linkedList;
    University* getUniById(int id);

    void kutulariHazirla();
    void listeyiGuncelle(int simuleSiralama);
    void arayaEkle(int index, int uniID);


};  