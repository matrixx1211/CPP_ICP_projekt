#include "help.h"
#include "ui_help.h"

Help::Help(): ui(new Ui::Help) {
    this->help = new QWidget();
    ui->setupUi(help);
    help->setWindowTitle("Help");
}

void Help::show() {
    help->show();
}

Help::~Help() {

}
