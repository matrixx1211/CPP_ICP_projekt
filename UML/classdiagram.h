#ifndef CLASSDIAGRAM_H
#define CLASSDIAGRAM_H

#include "communicationdiagram.h"
#include "sequencediagram.h"
#include "umlclass.h"
#include "umlclassifier.h"
#include "umlrelation.h"

#include <element.h>
#include <qlist.h>

class ClassDiagram : public Element
{
public:
    // konstruktor
    explicit ClassDiagram(QString name);
    // destruktor
    ~ClassDiagram();

    // list tříd
    QList<UMLClass *> classes;
    // list tříd
    QList<UMLClassifier *> classifiers;
    // list relaci
    QList<UMLRelation *> relations;
    // list sekvenčních diagramů
    QList<SequenceDiagram *> sequenceDiagrams;
    // list diagramů komunikace
    QList<CommunicationDiagram *> communicationDiagrams;

    // vytvoří novou instanci třídy
    bool createClass(QString name, int id, bool isInterface, QWidget *parent);
    // smaže instanci třídy
    bool deleteClass(UMLClass obj);
    // změní jméno instance třídy
    bool changeClassName(QString oldName, QString newName);
    // najde třídu podle názvu
    UMLClass *getObject(QString name);
    // vytvoří nový classifier pokud neexistuje
    UMLClassifier *classifierForName(QString name);
    // najde classifier pokud existuje vrací classifier jinak vrací null
    UMLClassifier *findClassifier(QString name);
    // vytvoří relaci
    UMLRelation *createRelation(QString name, QString type, QString class1, QString class2, QString class3);
    // najde relaci
    UMLRelation *findRelation(QString class1, QString class2);
    // najde všechny relace dané třídy
    QList<UMLRelation> *findAllRelationsOfClass(QString class1);
    // vytvoření sekvenčního diagramu
    SequenceDiagram *createSeqDiagram(QString name);
    // smazání sekvenčního diagramu
    bool deleteSeqDiagram(QString name);
    // nalezení sekvenčního diagramu
    SequenceDiagram *findSeqDiagram(QString name);
};

#endif // CLASSDIAGRAM_H
