#include "element.h"

// konstruktor
Element::Element(QString name)
{
    this->name = name;
}

// metoda vrátí jméno elementu
QString Element::getName() {
    return this->name;
}

// metoda přejmenuje element
void Element::rename(QString newName) {
    this->name = newName;
}

// destruktor
Element::~Element() {
    //QString this->name::~QString;
    printf("%d Destructor\n", 213);
    fflush(stdout);
}
