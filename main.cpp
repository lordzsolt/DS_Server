#include <QCoreApplication>

#include "Controllers/ApplicationController.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ApplicationController& application = ApplicationController::currentApplication();
//    application.networking().functionMessage(FunctionType::Add,
//                                             "alma",
//                                             nullptr);

    return a.exec();
}
