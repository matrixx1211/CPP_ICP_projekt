#include "umlclass.h"

#include <qpushbutton.h>


UMLClass::UMLClass(QString name, int id, bool isInterface, QWidget *parent): UMLClassifier{name}, QGroupBox{name, parent}
{
    this->name = name;
    this->id = id;
    this->isInterface = isInterface;
}

bool UMLClass::getIsAbstract() {
    return this->isAbstract;
}

bool UMLClass::getIsInterface() {
    return this->isInterface;
}

void UMLClass::setAbstract(bool isAbstract) {
    this->isAbstract = isAbstract;
}

bool UMLClass::addAttribute(UMLAttribute *attr) {
    for (int i = 0; i < this->attributes.size(); i++) {
        if (this->attributes[i].getName().compare((*attr).getName()) == 0) {
            return false;
        }
    }
    this->attributes.append(*attr);
    return true;
}

int UMLClass::getAttrPosition(UMLAttribute *attr) {
    for (int i = 0; i < this->attributes.size(); i++) {
        if (this->attributes[i].getName().compare((*attr).getName()) == 0)
            return i;
    }
    return -1;
}

int UMLClass::moveAttrAtPosition(UMLAttribute *attr, int pos) {

    for (int i = 0; i < this->attributes.size(); i++) {
        if (this->attributes[i].getName().compare((*attr).getName()) == 0) {
            this->attributes.removeAt(i);
            this->attributes.insert(pos, *attr);
            return pos;
        }
    }
    return -1;
}

int UMLClass::getId() {
    return this->id;
}

bool UMLClass::removeAttr(UMLAttribute *attr) {
    for (int i = 0; i < this->attributes.size(); i++) {
        if (this->attributes[i].getName().compare((*attr).getName()) == 0) {
            this->attributes.removeAt(i);
            return true;
        }
    }
    return false;
}

bool UMLClass::addOperation(UMLOperation *op) {
    for (int i = 0; i < this->operations.size(); i++) {
        if (this->operations[i].getName().compare((*op).getName()) == 0) {
            return false;
        }
    }
    this->operations.append(*op);
    return true;
}

bool UMLClass::removeOperation(UMLOperation *op) {
    for (int i = 0; i < this->operations.size(); i++) {
        if (this->operations[i].getName().compare((*op).getName()) == 0) {
            this->operations.removeAt(i);
            return true;
        }
    }
    return false;
}

void UMLClass::setPosition(double x, double y){
    this->x = x;
    this->y = y;
}

double UMLClass::getPositionX(){
    return this->x;
}

double UMLClass::getPositionY(){
    return this->y;
}

QList<UMLAttribute> UMLClass::getAttributes() {
    return this->attributes;
}

UMLClass::~UMLClass() {

}
