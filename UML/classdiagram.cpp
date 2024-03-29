#include "classdiagram.h"

#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>

ClassDiagram::ClassDiagram(QString name): Element{name}
{
    this->classes = QList<UMLClass *>();
    this->classifiers = QList<UMLClassifier *>();
}

bool ClassDiagram::createClass(QString name, int id, bool isInterface, QWidget *parent) {
    // vytvoření classy s testem
    UMLClass *obj;
    for (int i = 0; i < this->classes.size(); i++) {
        obj = this->classes[i];
        if (obj->getName().compare(name) == 0) {
            return false;
        }
    }
    obj = new UMLClass(name, id, isInterface, parent);

    // přidání classifieru s kontrolou na existenci
    UMLClassifier *classifier;
    bool exists = false;
    for (int i = 0; i < this->classifiers.size(); i++) {
        classifier = this->classifiers[i];
        if (classifier->getName().compare(name) == 0) {
            exists = true;
        }
    }
    this->classes.append(obj);

    // pokud neexistuje classifier tak ho vytvořím
    if (exists == false) {
        classifier = new UMLClassifier(name);
        this->classifiers.append(classifier);
    }

    // vložení gui pro UMLClass
    QVBoxLayout *layout = new QVBoxLayout();
    obj->setLayout(layout);

    // pokud je interface -> nelze přídávat atributy -> ani nebudu vykreslovat
    if (isInterface == false) {
        // řádky attributů
        QVBoxLayout *attributes = new QVBoxLayout();
        attributes->setObjectName("attributes");
        layout->addLayout(attributes);

        // rozdělovač
        QFrame *divider = new QFrame();
        divider->setFrameShape(QFrame::HLine);
        layout->addWidget(divider);
    }

    // řádky metod
    QVBoxLayout *methods = new QVBoxLayout();
    methods->setObjectName("methods");
    layout->addLayout(methods);

    // posun
    obj->setGeometry(id*10, id*10, 100, 30);

    // nastavení jména pro referenci
    obj->setObjectName(name);

    // zobrazení
    obj->show();

    return true;
}

bool ClassDiagram::deleteClass(UMLClass obj) {
    return false;
}

bool ClassDiagram::changeClassName(QString oldName, QString newName) {
    return false;
}

UMLClass *ClassDiagram:: getObject(QString name) {
    return NULL;
}

UMLClassifier *ClassDiagram::classifierForName(QString name) {
    UMLClassifier *obj;
    for (int i = 0; i < this->classifiers.size(); i++) {
        obj = this->classifiers[i];
        if (obj->getName().compare(name) == 0) {
            return obj;
        }
    }
    obj = new UMLClassifier(name);
    return obj;
}

UMLClassifier *ClassDiagram::findClassifier(QString name) {
    return NULL;
}

UMLClass *ClassDiagram::findClass(QString name) {
    UMLClass *obj;
    for (int i = 0; i < this->classes.size(); i++) {
        obj = this->classes[i];
        if (obj->getName().compare(name) == 0) {
            return obj;
        }
    }
    return NULL;
}

UMLRelation *ClassDiagram::createRelation(QString name, QString type, QString class1, QString class2, QString class3) {
    return NULL;
}

UMLRelation *ClassDiagram::findRelation(QString class1, QString class2) {
    return NULL;
}

QList<UMLRelation> *ClassDiagram::findAllRelationsOfClass(QString class1) {
    return NULL;
}

SequenceDiagram *ClassDiagram::createSeqDiagram(QString name) {
    return NULL;
}

bool  ClassDiagram::deleteSeqDiagram(QString name) {
    return false;
}

SequenceDiagram *ClassDiagram::findSeqDiagram(QString name) {
    return NULL;
}

