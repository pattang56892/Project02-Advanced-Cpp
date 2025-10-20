#include <QApplication>
#include "AlgorithmLearningPlatform.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Set application properties
    app.setApplicationName("Algorithm Learning Platform");
    app.setApplicationVersion("2.0");
    app.setOrganizationName("Educational Software");

    // Create and show the main window
    AlgorithmLearningPlatform window;
    window.show();

    return app.exec();
}