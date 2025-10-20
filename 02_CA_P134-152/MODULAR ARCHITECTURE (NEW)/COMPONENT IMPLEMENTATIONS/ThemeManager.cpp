#include "ThemeManager.h"

ThemeManager::ThemeManager(QObject *parent)
    : QObject(parent)
    , m_currentTheme(Light)
{
}

void ThemeManager::setTheme(Theme theme)
{
    if (m_currentTheme != theme) {
        m_currentTheme = theme;
        emit themeChanged(theme);
    }
}

void ThemeManager::toggleTheme()
{
    setTheme(m_currentTheme == Light ? Dark : Light);
}

QString ThemeManager::getMainWindowStyle() const
{
    return m_currentTheme == Light ? getLightMainWindowStyle() : getDarkMainWindowStyle();
}

QString ThemeManager::getSidebarStyle() const
{
    return m_currentTheme == Light ? getLightSidebarStyle() : getDarkSidebarStyle();
}

QString ThemeManager::getHeaderStyle() const
{
    return m_currentTheme == Light ? getLightHeaderStyle() : getDarkHeaderStyle();
}

QString ThemeManager::getContentStyle() const
{
    return m_currentTheme == Light ? getLightContentStyle() : getDarkContentStyle();
}

QString ThemeManager::getButtonStyle() const
{
    return m_currentTheme == Light ? getLightButtonStyle() : getDarkButtonStyle();
}

QString ThemeManager::getInputStyle() const
{
    return m_currentTheme == Light ? getLightInputStyle() : getDarkInputStyle();
}

QString ThemeManager::getCodeEditorStyle() const
{
    return m_currentTheme == Light ? getLightCodeEditorStyle() : getDarkCodeEditorStyle();
}

// Light Theme Styles
QString ThemeManager::getLightMainWindowStyle() const
{
    return R"(
        QMainWindow {
            background-color: #ffffff;
            color: #2c3e50;
        }
        QSplitter::handle {
            background-color: #dee2e6;
        }
        QSplitter::handle:hover {
            background-color: #adb5bd;
        }
    )";
}

QString ThemeManager::getLightSidebarStyle() const
{
    return R"(
        SidebarWidget {
            background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,
                stop: 0 #f8f9fa, stop: 1 #e9ecef);
            border-right: 2px solid #dee2e6;
        }
        QLabel {
            color: #2c3e50;
            background-color: transparent;
        }
        QLineEdit {
            background-color: white;
            color: #2c3e50;
            border: 2px solid #bdc3c7;
        }
        QListWidget {
            background-color: white;
            color: #2c3e50;
            border: 1px solid #dee2e6;
        }
    )";
}

QString ThemeManager::getLightHeaderStyle() const
{
    return R"(
        HeaderWidget {
            background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                stop: 0 #f8f9fa, stop: 1 #e9ecef);
            border-bottom: 2px solid #dee2e6;
        }
        QLabel {
            color: #2c3e50;
            background-color: rgba(255, 255, 255, 0.8);
            border: 1px solid #dee2e6;
        }
    )";
}

QString ThemeManager::getLightContentStyle() const
{
    return R"(
        QTabWidget::pane {
            border: 1px solid #dee2e6;
            background-color: white;
        }
        QTabBar::tab {
            background-color: #f8f9fa;
            color: #495057;
            border: 1px solid #dee2e6;
        }
        QTabBar::tab:selected {
            background-color: white;
            color: #2c3e50;
        }
        QTextEdit {
            background-color: white;
            color: #2c3e50;
            border: 1px solid #dee2e6;
        }
    )";
}

QString ThemeManager::getLightButtonStyle() const
{
    return R"(
        QPushButton {
            background-color: #007bff;
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 4px;
        }
        QPushButton:hover {
            background-color: #0056b3;
        }
    )";
}

QString ThemeManager::getLightInputStyle() const
{
    return R"(
        QLineEdit, QTextEdit {
            background-color: white;
            color: #2c3e50;
            border: 2px solid #bdc3c7;
            border-radius: 4px;
            padding: 8px;
        }
        QLineEdit:focus, QTextEdit:focus {
            border-color: #007bff;
        }
    )";
}

QString ThemeManager::getLightCodeEditorStyle() const
{
    return R"(
        QTextEdit {
            background-color: #f8f9fa;
            color: #2c3e50;
            font-family: 'Consolas', 'Courier New', monospace;
            border: 1px solid #dee2e6;
        }
    )";
}

// Dark Theme Styles
QString ThemeManager::getDarkMainWindowStyle() const
{
    return R"(
        QMainWindow {
            background-color: #2b2b2b;
            color: #ffffff;
        }
        QSplitter::handle {
            background-color: #404040;
        }
        QSplitter::handle:hover {
            background-color: #555555;
        }
    )";
}

QString ThemeManager::getDarkSidebarStyle() const
{
    return R"(
        SidebarWidget {
            background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,
                stop: 0 #3c3c3c, stop: 1 #2b2b2b);
            border-right: 2px solid #404040;
        }
        QLabel {
            color: #ffffff;
            background-color: transparent;
        }
        QLineEdit {
            background-color: #404040;
            color: #ffffff;
            border: 2px solid #555555;
        }
        QLineEdit:focus {
            border-color: #007bff;
        }
        QListWidget {
            background-color: #404040;
            color: #ffffff;
            border: 1px solid #555555;
        }
        QListWidget::item:selected {
            background-color: #007bff;
            color: white;
        }
        QListWidget::item:hover {
            background-color: #555555;
        }
    )";
}

QString ThemeManager::getDarkHeaderStyle() const
{
    return R"(
        HeaderWidget {
            background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                stop: 0 #3c3c3c, stop: 1 #2b2b2b);
            border-bottom: 2px solid #404040;
        }
        QLabel {
            color: #ffffff;
            background-color: rgba(64, 64, 64, 0.8);
            border: 1px solid #555555;
        }
    )";
}

QString ThemeManager::getDarkContentStyle() const
{
    return R"(
        QTabWidget::pane {
            border: 1px solid #555555;
            background-color: #404040;
        }
        QTabBar::tab {
            background-color: #3c3c3c;
            color: #cccccc;
            border: 1px solid #555555;
        }
        QTabBar::tab:selected {
            background-color: #404040;
            color: #ffffff;
        }
        QTabBar::tab:hover {
            background-color: #4a4a4a;
        }
        QTextEdit {
            background-color: #2b2b2b;
            color: #ffffff;
            border: 1px solid #555555;
        }
    )";
}

QString ThemeManager::getDarkButtonStyle() const
{
    return R"(
        QPushButton {
            background-color: #007bff;
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 4px;
        }
        QPushButton:hover {
            background-color: #0056b3;
        }
        QPushButton:pressed {
            background-color: #004085;
        }
    )";
}

QString ThemeManager::getDarkInputStyle() const
{
    return R"(
        QLineEdit, QTextEdit {
            background-color: #404040;
            color: #ffffff;
            border: 2px solid #555555;
            border-radius: 4px;
            padding: 8px;
        }
        QLineEdit:focus, QTextEdit:focus {
            border-color: #007bff;
        }
    )";
}

QString ThemeManager::getDarkCodeEditorStyle() const
{
    return R"(
        QTextEdit {
            background-color: #1e1e1e;
            color: #d4d4d4;
            font-family: 'Consolas', 'Courier New', monospace;
            border: 1px solid #404040;
        }
    )";
}