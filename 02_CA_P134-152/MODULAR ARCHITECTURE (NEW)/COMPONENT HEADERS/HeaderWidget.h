#ifndef HEADER_WIDGET_H
#define HEADER_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>

class HeaderWidget : public QWidget {
    Q_OBJECT

public:
    explicit HeaderWidget(QWidget *parent = nullptr);

    void setProblemTitle(const QString &title);
    void setCurrentProblem(int number, const QString &title);

signals:
    void sidebarToggleRequested();
    void themeToggleRequested();
    void aboutRequested();

private slots:
    void onSidebarToggleClicked();
    void onThemeToggleClicked();
    void onAboutClicked();

private:
    void setupUI();
    void updateThemeButtonIcon(bool isDark);

    // UI Components - Problem Title Section (Left Half)
    QHBoxLayout *mainLayout;
    QHBoxLayout *titleSection;
    QPushButton *sidebarToggleButton;
    QLabel *problemTitleLabel;

    // UI Components - Button Bar Section (Right Half)
    QHBoxLayout *buttonSection;
    QPushButton *themeToggleButton;
    QPushButton *aboutButton;

    // State
    bool sidebarVisible;
    bool isDarkTheme;
};

#endif // HEADER_WIDGET_H