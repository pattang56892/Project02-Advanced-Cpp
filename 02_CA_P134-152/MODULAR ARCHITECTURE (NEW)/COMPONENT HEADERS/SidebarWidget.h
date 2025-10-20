#ifndef SIDEBAR_WIDGET_H
#define SIDEBAR_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QPropertyAnimation>
#include "ProblemData.h"
#include "ThemeManager.h"

class SidebarWidget : public QWidget {
    Q_OBJECT

public:
    explicit SidebarWidget(QWidget *parent = nullptr);

    void setProblems(const QVector<ProblemData> &problems);
    void filterProblems(const QString &searchText);
    void resetSelection();
    void applyTheme(ThemeManager::Theme theme);

    // Animation methods
    void slideIn();
    void slideOut();

    // Getters
    QLineEdit* getSearchBox() const { return searchBox; }
    QListWidget* getProblemList() const { return problemList; }

signals:
    void problemSelected(int problemId);
    void resetRequested();

private slots:
    void onProblemItemClicked(int row);
    void onSearchTextChanged();
    void onResetClicked();

private:
    void setupUI();
    void applyTheme();

    // UI Components
    QVBoxLayout *mainLayout;
    QLabel *titleLabel;
    QLineEdit *searchBox;
    QListWidget *problemList;
    QPushButton *resetButton;

    // Animation
    QPropertyAnimation *slideAnimation;

    // Data
    QVector<ProblemData> allProblems;
    QVector<ProblemData> filteredProblems;
};

#endif // SIDEBAR_WIDGET_H