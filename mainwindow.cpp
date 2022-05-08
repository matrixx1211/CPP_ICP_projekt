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

    // propojení akcí s pravou částí
    connect(ui->addAttribute, SIGNAL(clicked()), this, SLOT(addAttribute()));
    connect(ui->addOperation, SIGNAL(clicked()), this, SLOT(addOperation()));

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
        if (isInterface)
            ui->errorText->setText("ACTION: create Interface");
        else
            ui->errorText->setText("ACTION: create Class");

        ui->classSelector->addItem(name);
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


// změní jméno
void MainWindow::changeClassName() {

}

// přidá atribut
void MainWindow::addAttribute() {
    // test jestli náhodu není interface
    QString className = ui->classSelector->currentText();
    UMLClass *obj = classDiagram->findClass(className);
    if (obj->getIsInterface()) {
        ui->errorText->setText("Cannot add attribute to Interface.");
        return;
    }

    // pomocné proměnné
    QString accesibility = ui->attributeAccessibility->currentText();
    QString name = ui->attributeName->text();
    QString type = ui->attributeType->text();
    // test jestli bylo zadáno vše
    if (className != "" && accesibility != "" && name != "" && type != "") {
        // kam budu vkládat
        QGroupBox *parent = ui->centerContent->findChild<QGroupBox *>(className);
        QVBoxLayout *attributes = parent->findChild<QVBoxLayout *>("attributes");

        // vytvoření a test atributu
        UMLAttribute *attr = new UMLAttribute(name, classDiagram->classifierForName(type), accesibility);
        if (!obj->addAttribute(attr)) {
            ui->errorText->setText("Attribute already exists.");
            return;
        }

        // nový záznam s nastavením
        QLabel *label = new QLabel();
        label->setText(accesibility.append(name.append(":").append(type)));
        attributes->addWidget(label);
        QRect r = parent->geometry();
        parent->setGeometry(r.x(), r.y(), r.width(), r.height()+20);

        // výpis
        ui->errorText->setText("ACTION: add atribute\n");
    } else {
        ui->errorText->setText("Class, accesibility, name or type not selected.");
    }
}

// přidá operaci
void MainWindow::addOperation() {

}

// destruktor
MainWindow::~MainWindow()
{
    delete ui;
    //delete(this->classDiagram);
}






