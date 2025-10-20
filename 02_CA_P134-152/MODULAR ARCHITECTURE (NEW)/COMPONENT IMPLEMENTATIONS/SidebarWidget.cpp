#include "SidebarWidget.h"
#include <QPropertyAnimation>
#include <QEasingCurve>

SidebarWidget::SidebarWidget(QWidget *parent)
    : QWidget(parent)
    , mainLayout(nullptr)
    , titleLabel(nullptr)
    , searchBox(nullptr)
    , problemList(nullptr)
    , resetButton(nullptr)
    , slideAnimation(nullptr)
{
    setupUI();

    // Setup slide animation
    slideAnimation = new QPropertyAnimation(this, "maximumWidth");
    slideAnimation->setDuration(300);
    slideAnimation->setEasingCurve(QEasingCurve::InOutCubic);
}

void SidebarWidget::setupUI()
{
    setMinimumWidth(250);
    setMaximumWidth(350);

    applyTheme();

    // Main layout
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(15, 20, 15, 15);
    mainLayout->setSpacing(15);

    // Title
    titleLabel = new QLabel("🔍 Algorithm Problems", this);
    titleLabel->setStyleSheet(
        "QLabel {"
        "  color: #2c3e50;"
        "  font-size: 14pt;"
        "  font-weight: bold;"
        "  padding: 8px 0px;"
        "  border-bottom: 2px solid #3498db;"
        "  margin-bottom: 5px;"
        "}"
    );
    mainLayout->addWidget(titleLabel);

    // Search box
    searchBox = new QLineEdit(this);
    searchBox->setPlaceholderText("🔎 Search problems...");
    searchBox->setStyleSheet(
        "QLineEdit {"
        "  padding: 10px 15px;"
        "  border: 2px solid #bdc3c7;"
        "  border-radius: 8px;"
        "  font-size: 12pt;"
        "  background-color: white;"
        "}"
        "QLineEdit:focus {"
        "  border-color: #3498db;"
        "  background-color: #f8f9fa;"
        "}"
    );
    mainLayout->addWidget(searchBox);

    // Problem list
    problemList = new QListWidget(this);
    problemList->setStyleSheet(
        "QListWidget {"
        "  border: 1px solid #dee2e6;"
        "  border-radius: 8px;"
        "  background-color: white;"
        "  selection-background-color: #e3f2fd;"
        "  font-size: 11pt;"
        "  padding: 5px;"
        "}"
        "QListWidget::item {"
        "  padding: 12px 15px;"
        "  border-bottom: 1px solid #f1f3f4;"
        "  border-radius: 4px;"
        "  margin: 2px 0px;"
        "}"
        "QListWidget::item:hover {"
        "  background-color: #f8f9fa;"
        "  border-left: 4px solid #3498db;"
        "}"
        "QListWidget::item:selected {"
        "  background-color: #e3f2fd;"
        "  border-left: 4px solid #2196f3;"
        "  color: #1565c0;"
        "  font-weight: bold;"
        "}"
    );
    mainLayout->addWidget(problemList);

    // Reset button
    resetButton = new QPushButton("🔄 Reset View", this);
    resetButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #28a745;"
        "  color: white;"
        "  border: none;"
        "  padding: 10px 15px;"
        "  border-radius: 6px;"
        "  font-weight: bold;"
        "  font-size: 11pt;"
        "}"
        "QPushButton:hover {"
        "  background-color: #218838;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #1e7e34;"
        "}"
    );
    mainLayout->addWidget(resetButton);

    // Connect signals
    connect(searchBox, &QLineEdit::textChanged, this, &SidebarWidget::onSearchTextChanged);
    connect(problemList, &QListWidget::currentRowChanged, this, &SidebarWidget::onProblemItemClicked);
    connect(resetButton, &QPushButton::clicked, this, &SidebarWidget::onResetClicked);
}

void SidebarWidget::applyTheme()
{
    setStyleSheet(
        "SidebarWidget {"
        "  background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, "
        "    stop: 0 #f8f9fa, stop: 1 #e9ecef);"
        "  border-right: 2px solid #dee2e6;"
        "}"
    );
}

void SidebarWidget::setProblems(const QVector<ProblemData> &problems)
{
    allProblems = problems;
    filteredProblems = problems;

    problemList->clear();
    for (const ProblemData &problem : problems) {
        QString itemText = QString("Problem %1: %2").arg(problem.number).arg(problem.title);
        problemList->addItem(itemText);
    }
}

void SidebarWidget::filterProblems(const QString &searchText)
{
    problemList->clear();
    filteredProblems.clear();

    QString lowerSearch = searchText.toLower();

    for (const ProblemData &problem : allProblems) {
        QString problemText = QString("Problem %1: %2").arg(problem.number).arg(problem.title).toLower();

        if (problemText.contains(lowerSearch) || QString::number(problem.number).contains(lowerSearch)) {
            filteredProblems.append(problem);
            QString itemText = QString("Problem %1: %2").arg(problem.number).arg(problem.title);
            problemList->addItem(itemText);
        }
    }
}

void SidebarWidget::resetSelection()
{
    problemList->setCurrentRow(-1);
    searchBox->clear();
}

void SidebarWidget::slideIn()
{
    if (slideAnimation->state() == QPropertyAnimation::Running) {
        slideAnimation->stop();
    }

    slideAnimation->setStartValue(0);
    slideAnimation->setEndValue(350);
    slideAnimation->start();

    QWidget::show();
}

void SidebarWidget::slideOut()
{
    if (slideAnimation->state() == QPropertyAnimation::Running) {
        slideAnimation->stop();
    }

    slideAnimation->setStartValue(350);
    slideAnimation->setEndValue(0);

    connect(slideAnimation, &QPropertyAnimation::finished, this, [this]() {
        QWidget::hide();
        disconnect(slideAnimation, &QPropertyAnimation::finished, this, nullptr);
    });

    slideAnimation->start();
}


void SidebarWidget::onProblemItemClicked(int row)
{
    if (row >= 0 && row < filteredProblems.size()) {
        emit problemSelected(filteredProblems[row].number);
    }
}

void SidebarWidget::onSearchTextChanged()
{
    filterProblems(searchBox->text());
}

void SidebarWidget::onResetClicked()
{
    emit resetRequested();
}

void SidebarWidget::applyTheme(ThemeManager::Theme theme)
{
    if (theme == ThemeManager::Dark) {
        // Apply dark theme with dimmed problem headers (25% opacity reduction)
        setStyleSheet(R"(
            SidebarWidget {
                background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,
                    stop: 0 #3c3c3c, stop: 1 #2b2b2b);
                border-right: 2px solid #404040;
            }
        )");

        titleLabel->setStyleSheet(R"(
            QLabel {
                color: #ffffff;
                font-size: 14pt;
                font-weight: bold;
                padding: 8px 0px;
                border-bottom: 2px solid #3498db;
                margin-bottom: 5px;
                background-color: transparent;
            }
        )");

        searchBox->setStyleSheet(R"(
            QLineEdit {
                padding: 10px 15px;
                border: 2px solid #555555;
                border-radius: 8px;
                font-size: 12pt;
                background-color: #404040;
                color: #ffffff;
            }
            QLineEdit:focus {
                border-color: #3498db;
                background-color: #4a4a4a;
            }
        )");

        // Dimmed problem list items (75% opacity = 25% dimmed)
        problemList->setStyleSheet(R"(
            QListWidget {
                border: 1px solid #555555;
                border-radius: 8px;
                background-color: #404040;
                selection-background-color: #007bff;
                font-size: 11pt;
                padding: 5px;
                color: rgba(204, 204, 204, 192); /* 75% opacity = 25% dimmed */
            }
            QListWidget::item {
                padding: 12px 15px;
                border-bottom: 1px solid #505050;
                border-radius: 4px;
                margin: 2px 0px;
                color: rgba(204, 204, 204, 192); /* 75% opacity for problem headers */
            }
            QListWidget::item:hover {
                background-color: #4a4a4a;
                border-left: 4px solid #3498db;
                color: rgba(255, 255, 255, 230); /* Slightly brighter on hover */
            }
            QListWidget::item:selected {
                background-color: #007bff;
                border-left: 4px solid #0056b3;
                color: #ffffff; /* Full brightness when selected */
                font-weight: bold;
            }
        )");

        resetButton->setStyleSheet(R"(
            QPushButton {
                background-color: #28a745;
                color: white;
                border: none;
                padding: 10px 15px;
                border-radius: 6px;
                font-weight: bold;
                font-size: 11pt;
            }
            QPushButton:hover {
                background-color: #34ce57;
            }
            QPushButton:pressed {
                background-color: #1e7e34;
            }
        )");

    } else {
        // Apply light theme (original styling)
        setStyleSheet(R"(
            SidebarWidget {
                background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,
                    stop: 0 #f8f9fa, stop: 1 #e9ecef);
                border-right: 2px solid #dee2e6;
            }
        )");

        titleLabel->setStyleSheet(R"(
            QLabel {
                color: #2c3e50;
                font-size: 14pt;
                font-weight: bold;
                padding: 8px 0px;
                border-bottom: 2px solid #3498db;
                margin-bottom: 5px;
                background-color: transparent;
            }
        )");

        searchBox->setStyleSheet(R"(
            QLineEdit {
                padding: 10px 15px;
                border: 2px solid #bdc3c7;
                border-radius: 8px;
                font-size: 12pt;
                background-color: white;
                color: #2c3e50;
            }
            QLineEdit:focus {
                border-color: #3498db;
                background-color: #f8f9fa;
            }
        )");

        problemList->setStyleSheet(R"(
            QListWidget {
                border: 1px solid #dee2e6;
                border-radius: 8px;
                background-color: white;
                selection-background-color: #e3f2fd;
                font-size: 11pt;
                padding: 5px;
                color: #2c3e50;
            }
            QListWidget::item {
                padding: 12px 15px;
                border-bottom: 1px solid #f1f3f4;
                border-radius: 4px;
                margin: 2px 0px;
            }
            QListWidget::item:hover {
                background-color: #f8f9fa;
                border-left: 4px solid #3498db;
            }
            QListWidget::item:selected {
                background-color: #e3f2fd;
                border-left: 4px solid #2196f3;
                color: #1565c0;
                font-weight: bold;
            }
        )");

        resetButton->setStyleSheet(R"(
            QPushButton {
                background-color: #28a745;
                color: white;
                border: none;
                padding: 10px 15px;
                border-radius: 6px;
                font-weight: bold;
                font-size: 11pt;
            }
            QPushButton:hover {
                background-color: #218838;
            }
            QPushButton:pressed {
                background-color: #1e7e34;
            }
        )");
    }
}