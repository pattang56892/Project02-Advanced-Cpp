#ifndef CONTENT_WIDGET_H
#define CONTENT_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include "ProblemData.h"
#include "CodeHighlighter.h"
#include "ThemeManager.h"

class ContentWidget : public QWidget {
    Q_OBJECT

public:
    explicit ContentWidget(QWidget *parent = nullptr);

    void setProblem(const ProblemData &problem);
    void setupSyntaxHighlighting();
    void applyTheme(ThemeManager::Theme theme);

    // Font size controls
    void zoomIn();
    void zoomOut();
    void resetZoom();

    // Test interface
    QString getTestInput() const;
    void setTestOutput(const QString &output);
    void clearTestArea();

signals:
    void runTestRequested();
    void clearTestRequested();

private slots:
    void onRunTestClicked();
    void onClearTestClicked();

private:
    void setupUI();
    void createZoomControls();
    void createDescriptionTab();
    void createCodeTabs();
    void createTestTab();
    void updateFontSizes();

    // UI Components
    QVBoxLayout *mainLayout;
    QWidget *topControlsWidget;
    QHBoxLayout *topControlsLayout;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QPushButton *resetZoomButton;
    QTabWidget *contentTabs;

    // Content tabs
    QTextEdit *descriptionTab;
    QTextEdit *cppTab;
    QTextEdit *pythonTab;
    QTextEdit *jsTab;

    // Interactive testing tab
    QWidget *testTab;
    QTextEdit *testInput;
    QTextEdit *testOutput;
    QPushButton *runTestButton;
    QPushButton *clearTestButton;

    // Syntax highlighting
    CodeHighlighter *cppHighlighter;
    CodeHighlighter *pythonHighlighter;
    CodeHighlighter *jsHighlighter;

    // Font size management
    int baseFontSize;
    int currentZoomLevel; // -2 to +3 (smaller to larger)
};

#endif // CONTENT_WIDGET_H