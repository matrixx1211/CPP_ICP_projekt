#include "umloperation.h"

UMLOperation::UMLOperation(QString name, UMLClassifier *type, QString accessibility): UMLAttribute{name, type, accessibility}
{

}

UMLOperation UMLOperation::create(QString name, UMLClassifier *type, QString accessibility, UMLAttribute...) {
    UMLOperation obj(name, type, accessibility);
    UMLAttribute arg(name, type, accessibility);
    foreach (arg, args) {
        obj.addArgument(arg);
    };

    return obj;
}
bool UMLOperation::addArgument(UMLAttribute arg) {
    for (int i = 0; i < this->args.size(); i++) {
        if (this->args[i].getName().compare(arg.getName()) == 0) {
            return false;
        }
    }
    this->args.append(arg);
    return true;
}
QList<UMLAttribute> UMLOperation::getArguments() {
    return this->args;
}
