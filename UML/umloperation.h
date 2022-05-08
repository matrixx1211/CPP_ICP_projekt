#ifndef UMLOPERATION_H
#define UMLOPERATION_H

#include "umlattribute.h"

class UMLOperation : public UMLAttribute
{
public:
    UMLOperation(QString name, UMLClassifier *type, QString accessibility);

    // list atributů
    QList<UMLAttribute> args;

    // vytváří operaci
    UMLOperation create(QString name, UMLClassifier *type, QString accessibility, UMLAttribute...);
    // přída argument vrátí true
    bool addArgument(UMLAttribute arg);
    // vrací list atributu
    QList<UMLAttribute> getArguments();
};

#endif // UMLOPERATION_H
