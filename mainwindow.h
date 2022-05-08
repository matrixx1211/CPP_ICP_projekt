#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmainwindow.h"
#include "help.h"
#include <qtextbrowser.h>
#include <UML/classdiagram.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // konstruktor
    MainWindow(QWidget *parent = nullptr);
    // destruktor
    ~MainWindow();
    // ClassDiagram instance
    ClassDiagram *classDiagram;
    // počítadlo id
    int idCounter;


private:
    // interface - komponenty
    Ui::MainWindow *ui;
    // okno s nápovědou
    Help help;
    // vytvoření nové třídy
    void createClass(bool isInterface);

// akce
private slots:
    // pomocná funkce pro vytvoření Class
    void clickedCreateClassBtn();
    // pomocná funkce pro vytvoření Interface
    void clickedCreateInterfaceBtn();

    // menu akce
    // nový soubor
    void newFile();
    // uložení do souboru
    void saveToFile();
    // otevření ze souboru
    void openFromFile();
    // vrácení zpět
    void undo();
    // ukončení
    void quit();
    // nápověda
    void about();
};
#endif // MAINWINDOW_H
