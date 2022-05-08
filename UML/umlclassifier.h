#ifndef UMLCLASSIFIER_H
#define UMLCLASSIFIER_H

#include <element.h>

class UMLClassifier : public Element
{
public:
    // konstruktor
    UMLClassifier(QString name);
    UMLClassifier(QString name, bool isUserDefined);
    // destruktor
    ~UMLClassifier();

    // značí, jestli se jedná o uživatelsky definovaný classifier
    bool isUserDefined;

    // vrátí true jestli je uživatelsky definovaný clasifier
    bool getIsUserDefined();
    // vrátí formátovaný řetězec
    QString toString();
};

#endif // UMLCLASSIFIER_H
