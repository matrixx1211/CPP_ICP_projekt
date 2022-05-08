#include "umlclassifier.h"

UMLClassifier::UMLClassifier(QString name): Element{name}
{
    this->isUserDefined = false;
}

UMLClassifier::UMLClassifier(QString name, bool isUserDefined): Element{name}
{
    this->isUserDefined = isUserDefined;
}

bool UMLClassifier::getIsUserDefined() {
    return this->isUserDefined;
}

QString UMLClassifier::toString() {
    return QString("%1(%2)").arg(this->name).arg(this->isUserDefined ? "true" : "false");
}

UMLClassifier::~UMLClassifier() {

}


