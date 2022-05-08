#ifndef HELP_H
#define HELP_H

#include <qwidget.h>

namespace Ui { class Help; }

class Help
{
public:
    // konstruktor
    Help();
    // destruktor
    ~Help();

    // rozhraní nápovědy
    Ui::Help *ui;
    // okno pro nápovědu
    QWidget *help;

    // rozbrazení okna nápovědy
    void show();
};

#endif // HELP_H
