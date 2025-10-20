#ifndef ALGORITHM_LEARNING_PLATFORM_H
#define ALGORITHM_LEARNING_PLATFORM_H

#include <QMainWindow>
#include <QSplitter>
#include <QListWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QScrollArea>
#include <QFont>
#include <QFontMetrics>
#include <QSyntaxHighlighter>
#include <QTextDocument>
#include <QRegularExpression>
#include <QApplication>
#include <QQueue>
#include <QPair>
#include <QSet>
#include <QMap>
#include <QVector>
#include <QTextCursor>
#include <QMessageBox>
#include <QStringList>
#include <QTimer>
#include <QResizeEvent>

#include "ProblemData.h"
#include "CodeHighlighter.h"
#include "ThemeManager.h"
#include "SidebarWidget.h"
#include "HeaderWidget.h"
#include "ContentWidget.h"
#include "AlgorithmSimulator.h"

class AlgorithmLearningPlatform : public QMainWindow {
    Q_OBJECT

public:
    explicit AlgorithmLearningPlatform(QWidget *parent = nullptr);
    ~AlgorithmLearningPlatform();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onProblemSelected(int problemId);
    void onSearchTextChanged(const QString &text);
    void resetView();
    void showAbout();
    void runTest();
    void clearTest();
    void toggleSidebar();
    void toggleTheme();

private:
    void setupUI();
    void loadProblemData();
    void connectSignals();
    void checkViewportWidth();
    void updateProblemDisplay(const ProblemData &problem);

    // Core Components
    QWidget *centralWidget;
    QSplitter *mainSplitter;
    SidebarWidget *sidebar;
    HeaderWidget *header;
    ContentWidget *contentArea;

    // Managers
    ThemeManager *themeManager;
    AlgorithmSimulator *simulator;

    // Data
    QVector<ProblemData> problems;

    // UI State
    bool sidebarVisible;
    bool autoHideSidebar;
    static const int SIDEBAR_AUTO_HIDE_WIDTH = 800;
};

#endif // ALGORITHM_LEARNING_PLATFORM_H