#include "HeaderWidget.h"

HeaderWidget::HeaderWidget(QWidget *parent)
    : QWidget(parent)
    , mainLayout(nullptr)
    , titleSection(nullptr)
    , buttonSection(nullptr)
    , sidebarToggleButton(nullptr)
    , problemTitleLabel(nullptr)
    , themeToggleButton(nullptr)
    , aboutButton(nullptr)
    , sidebarVisible(true)
    , isDarkTheme(false)
{
    setupUI();
}

void HeaderWidget::setupUI()
{
    setFixedHeight(60);
    setStyleSheet(
        "HeaderWidget {"
        "  background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
        "    stop: 0 #f8f9fa, stop: 1 #e9ecef);"
        "  border-bottom: 2px solid #dee2e6;"
        "}"
    );

    // Main horizontal layout
    mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(15, 8, 15, 8);
    mainLayout->setSpacing(20);

    // Left half - Problem title section
    titleSection = new QHBoxLayout();
    titleSection->setSpacing(12);

    // Sidebar toggle button
    sidebarToggleButton = new QPushButton("☰", this);
    sidebarToggleButton->setFixedSize(40, 40);
    sidebarToggleButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #007bff;"
        "  color: white;"
        "  border: none;"
        "  border-radius: 20px;"
        "  font-size: 16pt;"
        "  font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "  background-color: #0056b3;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #004085;"
        "}"
    );
    sidebarToggleButton->setToolTip("Toggle Sidebar (Ctrl+B)");

    // Problem title label (reduced to half width)
    problemTitleLabel = new QLabel("Select a Problem", this);
    problemTitleLabel->setStyleSheet(
        "QLabel {"
        "  color: #2c3e50;"
        "  font-size: 16pt;"
        "  font-weight: bold;"
        "  padding: 8px 12px;"
        "  background-color: rgba(255, 255, 255, 0.8);"
        "  border-radius: 8px;"
        "  border: 1px solid #dee2e6;"
        "}"
    );
    problemTitleLabel->setMaximumWidth(400); // Limit to half the typical width

    titleSection->addWidget(sidebarToggleButton);
    titleSection->addWidget(problemTitleLabel);
    titleSection->addStretch(); // Push everything to the left

    // Right half - Button bar section
    buttonSection = new QHBoxLayout();
    buttonSection->setSpacing(10);

    // Theme toggle button
    themeToggleButton = new QPushButton("🌙", this);
    themeToggleButton->setFixedSize(40, 40);
    themeToggleButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #ffc107;"
        "  color: #212529;"
        "  border: none;"
        "  border-radius: 20px;"
        "  font-size: 16pt;"
        "}"
        "QPushButton:hover {"
        "  background-color: #e0a800;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #d39e00;"
        "}"
    );
    themeToggleButton->setToolTip("Toggle Dark/Light Theme (Ctrl+T)");

    // About button
    aboutButton = new QPushButton("ℹ️", this);
    aboutButton->setFixedSize(40, 40);
    aboutButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #17a2b8;"
        "  color: white;"
        "  border: none;"
        "  border-radius: 20px;"
        "  font-size: 16pt;"
        "}"
        "QPushButton:hover {"
        "  background-color: #138496;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #117a8b;"
        "}"
    );
    aboutButton->setToolTip("About Algorithm Learning Platform");

    buttonSection->addStretch(); // Push buttons to the right
    buttonSection->addWidget(themeToggleButton);
    buttonSection->addWidget(aboutButton);

    // Add both sections to main layout with equal stretch
    mainLayout->addLayout(titleSection, 1);  // Takes 50% of width
    mainLayout->addLayout(buttonSection, 1); // Takes 50% of width

    // Connect signals
    connect(sidebarToggleButton, &QPushButton::clicked, this, &HeaderWidget::onSidebarToggleClicked);
    connect(themeToggleButton, &QPushButton::clicked, this, &HeaderWidget::onThemeToggleClicked);
    connect(aboutButton, &QPushButton::clicked, this, &HeaderWidget::onAboutClicked);
}

void HeaderWidget::setProblemTitle(const QString &title)
{
    problemTitleLabel->setText(title);
}

void HeaderWidget::setCurrentProblem(int number, const QString &title)
{
    QString fullTitle = QString("Problem %1: %2").arg(number).arg(title);
    QString shortTitle = fullTitle;

    // Truncate if too long (keeping it to roughly half the original length)
    if (shortTitle.length() > 25) {
        shortTitle = shortTitle.left(22) + "...";
        // Set tooltip to show full title when truncated
        problemTitleLabel->setToolTip(fullTitle);
    } else {
        // Clear tooltip if not truncated
        problemTitleLabel->setToolTip("");
    }

    setProblemTitle(shortTitle);
}

void HeaderWidget::onSidebarToggleClicked()
{
    sidebarVisible = !sidebarVisible;

    // Update button appearance
    sidebarToggleButton->setText(sidebarVisible ? "☰" : "▶");
    sidebarToggleButton->setToolTip(sidebarVisible ? "Hide Sidebar" : "Show Sidebar");

    emit sidebarToggleRequested();
}

void HeaderWidget::onThemeToggleClicked()
{
    isDarkTheme = !isDarkTheme;
    updateThemeButtonIcon(isDarkTheme);
    emit themeToggleRequested();
}

void HeaderWidget::updateThemeButtonIcon(bool isDark)
{
    if (isDark) {
        themeToggleButton->setText("☀️");
        themeToggleButton->setToolTip("Switch to Light Theme");
        themeToggleButton->setStyleSheet(
            "QPushButton {"
            "  background-color: #fd7e14;"
            "  color: white;"
            "  border: none;"
            "  border-radius: 20px;"
            "  font-size: 16pt;"
            "}"
            "QPushButton:hover {"
            "  background-color: #e8590c;"
                "}"
            "QPushButton:pressed {"
            "  background-color: #d5480b;"
            "}"
        );
    } else {
        themeToggleButton->setText("🌙");
        themeToggleButton->setToolTip("Switch to Dark Theme");
        themeToggleButton->setStyleSheet(
            "QPushButton {"
            "  background-color: #6f42c1;"
            "  color: white;"
            "  border: none;"
            "  border-radius: 20px;"
            "  font-size: 16pt;"
            "}"
            "QPushButton:hover {"
            "  background-color: #5a32a3;"
                "}"
            "QPushButton:pressed {"
            "  background-color: #4e2a8e;"
            "}"
        );
    }
}

void HeaderWidget::onAboutClicked()
{
    emit aboutRequested();
}