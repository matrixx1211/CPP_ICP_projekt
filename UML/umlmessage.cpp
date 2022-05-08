#include "umlmessage.h"

UMLMessage::UMLMessage(QString name, QString class1, QString class2, QString type, QString operation): Element{name}
{
    this->class1 = class1;
    this->class2 = class2;
    this->type = type;
    this->operation = operation;
    this->height = 100;
}

QString UMLMessage::getClass1(){
    return this->class1;
}

QString UMLMessage::getClass2(){
    return this->class2;
}

QString UMLMessage::getType(){
    return this->type;
}

QString UMLMessage::getOperation(){
    return this->operation;
}

double UMLMessage::getHeight(){
    return this->height;
}

void UMLMessage::setHeight(double height){
    this->height = height;
}

UMLMessage::~UMLMessage() {

}
