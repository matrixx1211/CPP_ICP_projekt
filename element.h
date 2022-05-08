#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>

class Element
{
public:
    // konstruktor
    explicit Element(QString name);
    // destruktor
    ~Element();

    // název elementu
    QString name;

    // vrací jméno elementu
    QString getName();
    // změní jméno elementu
    void rename(QString newName);
private:

signals:

};

#endif // ELEMENT_H
