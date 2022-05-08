#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <element.h>

#include <UML/umlclassifier.h>


// konstruktor
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // propojení dané komponentry při určitém signálu a zadaném příjmeci s danou akcí
    connect(ui->createClassBtn, SIGNAL(clicked()), this, SLOT(clickedCreateClassBtn()));
    connect(ui->createInterfaceBtn, SIGNAL(clicked()), this, SLOT(clickedCreateInterfaceBtn()));

    // menu akce
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveToFile()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFromFile()));
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(undo()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(quit()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));

    this->help = Help();
    this->classDiagram = new ClassDiagram("Diagram");
    this->idCounter = 1;

}

void MainWindow::clickedCreateClassBtn () {
    this->createClass(false);
}

void MainWindow::clickedCreateInterfaceBtn () {
    this->createClass(true);
}

void MainWindow::createClass(bool isInterface) {
    // pomocné proměnné
    QString name = ui->className->text();
    QString error;

    // vytvoření třídy v diagramu
    bool obj = classDiagram->createClass(name, idCounter, isInterface, ui->centerContent);

    // testování jestli objekt již existuje
    if (!obj) {
        error.append("Error: Class instance of name ");
        error.append(name);
        error.append(" is actually exists.");
        ui->errorText->setText(error.toUtf8().data());
    // pokud objekt ještě neexistuje, vytvořím pro něj ui
    } else {
        // jen výpis
        ui->errorText->setText("ACTION: create Interface");

        // vytvoření skupiny s údaji třídy a nastavení jména objektu kvůli referenci
        QWidget *w = new QWidget(ui->centerContent);
        w->setObjectName(name);
        QGroupBox *gpbox = new QGroupBox(tr(name.toUtf8().data()), w);
        // zvýšení počítadla
        this->idCounter++;
    }
};



void MainWindow::newFile() {
    printf("ACTION: %s\n", "newFile");
}

void MainWindow::saveToFile() {
    printf("ACTION: %s\n", "saveToFile");
}

void MainWindow::openFromFile() {
    printf("ACTION: %s\n", "openFromFile");
}

void MainWindow::undo() {
    printf("ACTION: %s\n", "undo");
}

void MainWindow::quit() {
    printf("ACTION: %s\n", "quit");
    exit(EXIT_SUCCESS);
}

void MainWindow::about() {
    printf("ACTION: %s\n", "about");
    help.show();
}


// destruktor
MainWindow::~MainWindow()
{
    delete ui;
    //delete(this->classDiagram);
}






