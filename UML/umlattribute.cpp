#include "umlattribute.h"

UMLAttribute::UMLAttribute(QString name, UMLClassifier *type, QString accessibility): Element{name}
{
    this->type = type;
    this->accessibility = accessibility;
}

QString UMLAttribute::getAccessibility() {
    return this->accessibility;
}

UMLClassifier *UMLAttribute::getType() {
    return this->getType();
}

QString UMLAttribute::toString() {
    return QString("%1(%2)").arg(this->name).arg(this->type->getName());
}

UMLAttribute::~UMLAttribute() {
    // destruktor
}
