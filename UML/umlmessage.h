#ifndef UMLMESSAGE_H
#define UMLMESSAGE_H

#include "umlclass.h"

#include <element.h>

class UMLMessage : public Element
{
public:
    // konstruktor
    UMLMessage(QString name, QString class1, QString class2, QString type, QString operation);
    // destruktor
    ~UMLMessage();

    // typ zprávy
    QString type;
    // jméno třídy odkud
    QString class1;
    // jméno třídy kam
    QString class2;
    // jméno operace
    QString operation;
    // výška
    double height;

    // vrací jméno třídy odkud
    QString getClass1();
    // vrací jméno třídy kam
    QString getClass2();
    // vrací typ zprávy
    QString getType();
    // vrací jméno operace
    QString getOperation();
    // vrací výšku
    double getHeight();
    // nastavuje novou výšku
    void setHeight(double height);
};

#endif // UMLMESSAGE_H
