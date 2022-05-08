#ifndef UMLCLASS_H
#define UMLCLASS_H

#include "umlattribute.h"
#include "umlclassifier.h"
#include "umloperation.h"

#include <qevent.h>
#include <qwidget.h>
#include "qgroupbox.h"


QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class UMLClass : public UMLClassifier, public QGroupBox
{
public:
    // konstruktor
    UMLClass(QString name, int id, bool isInterface, QWidget *parent);
    // destruktor
    ~UMLClass();

    // zda je abstraktní
    bool isAbstract;
    // zda je rozhraní
    bool isInterface;
    // list atributů
    QList<UMLAttribute> attributes;
    // list operací
    QList<UMLOperation> operations;
    // identifikátor
    int id;
    // widget pro třídu/rozhraní
    QWidget *obj;
    // x souřadnice
    double x;
    // y souřadnice
    double y;


    // vrátí true jestli je abstraktní
    bool getIsAbstract();
    // vrátí true jestli je rozhraní
    bool getIsInterface();
    // nastavování abstrakce
    void setAbstract(bool isAbstract);
    // přída atribut
    bool addAttribute(UMLAttribute *attr);
    // získá pozici zadaného atributu
    int getAttrPosition(UMLAttribute *attr);
    // přesune atribut na novou pozici
    int moveAttrAtPosition(UMLAttribute *attr, int pos);
    // vrátí id
    int getId();
    // smaže atribut
    bool removeAttr(UMLAttribute *attr);
    // přidá operaci
    bool addOperation(UMLOperation *op);
    // smaže operaci
    bool removeOperation(UMLOperation *op);
    // nastaví pozici
    void setPosition(double x, double y);
    // vrátí pozici na x
    double getPositionX();
    // vrátí pozici na y
    double getPositionY();
    // vrátí list atributů
    QList<UMLAttribute>getAttributes();

protected:
    void mousePressEvent(QMouseEvent *event) {
        dragStart = event->pos();
    }

    void mouseMoveEvent(QMouseEvent *event) {
        setGeometry(QRect(geometry().topLeft() + event->pos() - dragStart, rect().size()));
    }

private:
    QPoint dragStart;

};

#endif // UMLCLASS_H
