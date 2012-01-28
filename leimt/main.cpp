#include <QtGui/QApplication>
#include "leimt.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    leimt foo;
    foo.show();
    return app.exec();
}
