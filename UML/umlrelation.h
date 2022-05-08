#ifndef UMLRELATION_H
#define UMLRELATION_H

#include <element.h>

class UMLRelation : public Element
{
public:
    // konstruktor
    UMLRelation(QString name, QString type, QString class1, QString class2, QString class3);
    // destruktor
    ~UMLRelation();

    // typ relace
    QString type;
    // první člen relace
    QString class1;
    // druhý člen relace
    QString class2;
    // třetí člen relace (pouze u asociace - mezitabulka)
    QString class3;

    // vrátí typ
    QString getType();
    QString getClass1();
    QString getClass2();
    QString getClass3();

};

#endif // UMLRELATION_H
