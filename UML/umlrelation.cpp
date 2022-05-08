#include "umlrelation.h"

UMLRelation::UMLRelation(QString name, QString type, QString class1, QString class2, QString class3): Element{name}
{

}

QString UMLRelation::getType() {
    return this->type;
}

QString UMLRelation::getClass1() {
    return this->class1;
}

QString UMLRelation::getClass2() {
    return this->class2;
}

QString UMLRelation::getClass3() {
    return this->class3;
}
