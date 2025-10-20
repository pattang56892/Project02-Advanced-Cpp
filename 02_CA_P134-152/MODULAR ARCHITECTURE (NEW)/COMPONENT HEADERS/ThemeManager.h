#ifndef THEME_MANAGER_H
#define THEME_MANAGER_H

#include <QObject>
#include <QString>
#include <QWidget>

class ThemeManager : public QObject {
    Q_OBJECT

public:
    enum Theme {
        Light,
        Dark
    };

    explicit ThemeManager(QObject *parent = nullptr);

    Theme currentTheme() const { return m_currentTheme; }
    void setTheme(Theme theme);
    void toggleTheme();

    // Theme-specific styles
    QString getMainWindowStyle() const;
    QString getSidebarStyle() const;
    QString getHeaderStyle() const;
    QString getContentStyle() const;
    QString getButtonStyle() const;
    QString getInputStyle() const;
    QString getCodeEditorStyle() const;

signals:
    void themeChanged(Theme newTheme);

private:
    Theme m_currentTheme;

    QString getLightMainWindowStyle() const;
    QString getDarkMainWindowStyle() const;
    QString getLightSidebarStyle() const;
    QString getDarkSidebarStyle() const;
    QString getLightHeaderStyle() const;
    QString getDarkHeaderStyle() const;
    QString getLightContentStyle() const;
    QString getDarkContentStyle() const;
    QString getLightButtonStyle() const;
    QString getDarkButtonStyle() const;
    QString getLightInputStyle() const;
    QString getDarkInputStyle() const;
    QString getLightCodeEditorStyle() const;
    QString getDarkCodeEditorStyle() const;
};

#endif // THEME_MANAGER_H