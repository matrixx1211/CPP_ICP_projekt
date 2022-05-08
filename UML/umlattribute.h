#ifndef UMLATTRIBUTE_H
#define UMLATTRIBUTE_H

#include "umlclassifier.h"

#include <element.h>

class UMLAttribute : public Element
{
public:
    // konstruktor
    UMLAttribute(QString name, UMLClassifier *type, QString accessibility);
    // destruktor
    ~UMLAttribute();

    // modifikátor přístupu
    QString accessibility;
    // typ atributu
    UMLClassifier *type;

    // vrátí modifikátor přístupu
    QString getAccessibility();
    // vrátí typ atributu
    UMLClassifier *getType();
    // vrací formátovaný řetězec
    QString toString();
};

#endif // UMLATTRIBUTE_H
