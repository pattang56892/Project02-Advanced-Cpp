#include "ContentWidget.h"

ContentWidget::ContentWidget(QWidget *parent)
    : QWidget(parent)
    , mainLayout(nullptr)
    , topControlsWidget(nullptr)
    , topControlsLayout(nullptr)
    , zoomInButton(nullptr)
    , zoomOutButton(nullptr)
    , resetZoomButton(nullptr)
    , contentTabs(nullptr)
    , descriptionTab(nullptr)
    , cppTab(nullptr)
    , pythonTab(nullptr)
    , jsTab(nullptr)
    , testTab(nullptr)
    , testInput(nullptr)
    , testOutput(nullptr)
    , runTestButton(nullptr)
    , clearTestButton(nullptr)
    , cppHighlighter(nullptr)
    , pythonHighlighter(nullptr)
    , jsHighlighter(nullptr)
    , baseFontSize(12)
    , currentZoomLevel(0)
{
    setupUI();
}

void ContentWidget::setupUI()
{
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(5);

    createZoomControls();
    createDescriptionTab();
    createCodeTabs();
    createTestTab();

    mainLayout->addWidget(topControlsWidget);
    mainLayout->addWidget(contentTabs);

    // Initialize font sizes and button states
    updateFontSizes();
}

void ContentWidget::createZoomControls()
{
    topControlsWidget = new QWidget(this);
    topControlsWidget->setFixedHeight(40);

    topControlsLayout = new QHBoxLayout(topControlsWidget);
    topControlsLayout->setContentsMargins(10, 5, 10, 5);
    topControlsLayout->setSpacing(8);

    // Add label
    QLabel *zoomLabel = new QLabel("Font Size:", topControlsWidget);
    zoomLabel->setStyleSheet("font-weight: bold; color: #495057;");
    topControlsLayout->addWidget(zoomLabel);

    // Zoom In button
    zoomInButton = new QPushButton("🔍+", topControlsWidget);
    zoomInButton->setFixedSize(35, 30);
    zoomInButton->setToolTip("Increase font size");
    zoomInButton->setStyleSheet(R"(
        QPushButton {
            background-color: #28a745;
            color: white;
            border: none;
            border-radius: 4px;
            font-weight: bold;
            font-size: 10pt;
        }
        QPushButton:hover {
            background-color: #34ce57;
        }
        QPushButton:pressed {
            background-color: #1e7e34;
        }
        QPushButton:disabled {
            background-color: #6c757d;
        }
    )");
    topControlsLayout->addWidget(zoomInButton);

    // Zoom Out button
    zoomOutButton = new QPushButton("🔍-", topControlsWidget);
    zoomOutButton->setFixedSize(35, 30);
    zoomOutButton->setToolTip("Decrease font size");
    zoomOutButton->setStyleSheet(R"(
        QPushButton {
            background-color: #dc3545;
            color: white;
            border: none;
            border-radius: 4px;
            font-weight: bold;
            font-size: 10pt;
        }
        QPushButton:hover {
            background-color: #e85d6a;
        }
        QPushButton:pressed {
            background-color: #bd2130;
        }
        QPushButton:disabled {
            background-color: #6c757d;
        }
    )");
    topControlsLayout->addWidget(zoomOutButton);

    // Reset Zoom button
    resetZoomButton = new QPushButton("100%", topControlsWidget);
    resetZoomButton->setFixedSize(40, 30);
    resetZoomButton->setToolTip("Reset to default font size");
    resetZoomButton->setStyleSheet(R"(
        QPushButton {
            background-color: #6c757d;
            color: white;
            border: none;
            border-radius: 4px;
            font-weight: bold;
            font-size: 9pt;
        }
        QPushButton:hover {
            background-color: #7c8388;
        }
        QPushButton:pressed {
            background-color: #545b62;
        }
    )");
    topControlsLayout->addWidget(resetZoomButton);

    // Add spacer to push controls to the left
    topControlsLayout->addStretch();

    // Connect signals
    connect(zoomInButton, &QPushButton::clicked, this, &ContentWidget::zoomIn);
    connect(zoomOutButton, &QPushButton::clicked, this, &ContentWidget::zoomOut);
    connect(resetZoomButton, &QPushButton::clicked, this, &ContentWidget::resetZoom);
}

void ContentWidget::createDescriptionTab()
{
    contentTabs = new QTabWidget(this);
    contentTabs->setStyleSheet(
        "QTabWidget::pane {"
        "  border: 1px solid #dee2e6;"
        "  background-color: white;"
        "}"
        "QTabBar::tab {"
        "  background-color: #f8f9fa;"
        "  color: #495057;"
        "  border: 1px solid #dee2e6;"
        "  padding: 8px 16px;"
        "  margin-right: 2px;"
        "}"
        "QTabBar::tab:selected {"
        "  background-color: white;"
        "  color: #2c3e50;"
        "  border-bottom: 1px solid white;"
        "}"
        "QTabBar::tab:hover {"
        "  background-color: #e9ecef;"
        "}"
    );

    // Description tab
    descriptionTab = new QTextEdit(this);
    descriptionTab->setReadOnly(true);
    descriptionTab->setStyleSheet(
        "QTextEdit {"
        "  font-family: 'Segoe UI', Arial, sans-serif;"
        "  font-size: 12pt;"
        "  padding: 15px;"
        "  line-height: 1.6;"
        "  background-color: white;"
        "  color: #2c3e50;"
        "  border: none;"
        "}"
    );
    contentTabs->addTab(descriptionTab, "📖 Description & Tutorial");
}

void ContentWidget::createCodeTabs()
{
    // C++ tab
    cppTab = new QTextEdit(this);
    cppTab->setReadOnly(true);
    cppTab->setStyleSheet(
        "QTextEdit {"
        "  font-family: 'Consolas', 'Courier New', monospace;"
        "  font-size: 11pt;"
        "  padding: 15px;"
        "  background-color: #f8f9fa;"
        "  color: #2c3e50;"
        "  line-height: 1.4;"
        "  border: none;"
        "}"
    );
    contentTabs->addTab(cppTab, "⚡ C++ Solution");

    // Python tab
    pythonTab = new QTextEdit(this);
    pythonTab->setReadOnly(true);
    pythonTab->setStyleSheet(
        "QTextEdit {"
        "  font-family: 'Consolas', 'Courier New', monospace;"
        "  font-size: 11pt;"
        "  padding: 15px;"
        "  background-color: #f8f9fa;"
        "  color: #2c3e50;"
        "  line-height: 1.4;"
        "  border: none;"
        "}"
    );
    contentTabs->addTab(pythonTab, "🐍 Python Solution");

    // JavaScript tab
    jsTab = new QTextEdit(this);
    jsTab->setReadOnly(true);
    jsTab->setStyleSheet(
        "QTextEdit {"
        "  font-family: 'Consolas', 'Courier New', monospace;"
        "  font-size: 11pt;"
        "  padding: 15px;"
        "  background-color: #f8f9fa;"
        "  color: #2c3e50;"
        "  line-height: 1.4;"
        "  border: none;"
        "}"
    );
    contentTabs->addTab(jsTab, "🌐 JavaScript Solution");
}

void ContentWidget::createTestTab()
{
    testTab = new QWidget(this);
    QVBoxLayout *testLayout = new QVBoxLayout(testTab);
    testLayout->setContentsMargins(15, 15, 15, 15);
    testLayout->setSpacing(15);

    // Test instructions
    QLabel *testInstructions = new QLabel("🧪 Interactive Testing - Try the algorithm with your own input!", testTab);
    testInstructions->setStyleSheet(
        "QLabel {"
        "  font-weight: bold;"
        "  font-size: 13pt;"
        "  color: #2c3e50;"
        "  margin-bottom: 10px;"
        "}"
    );
    testLayout->addWidget(testInstructions);

    // Input section
    QLabel *inputLabel = new QLabel("Input:", testTab);
    inputLabel->setStyleSheet("font-weight: bold; font-size: 11pt; color: #34495e;");
    testLayout->addWidget(inputLabel);

    testInput = new QTextEdit(testTab);
    testInput->setMaximumHeight(100);
    testInput->setPlaceholderText("Enter your test input here...");
    testInput->setStyleSheet(
        "QTextEdit {"
        "  font-family: 'Consolas', 'Courier New', monospace;"
        "  font-size: 11pt;"
        "  padding: 10px;"
        "  border: 2px solid #bdc3c7;"
        "  border-radius: 5px;"
        "  background-color: #f8f9fa;"
        "}"
    );
    testLayout->addWidget(testInput);

    // Buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    runTestButton = new QPushButton("▶️ Run Test", testTab);
    runTestButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #27ae60;"
        "  color: white;"
        "  border: none;"
        "  padding: 10px 20px;"
        "  border-radius: 5px;"
        "  font-weight: bold;"
        "  font-size: 11pt;"
        "}"
        "QPushButton:hover {"
        "  background-color: #219a52;"
        "}"
    );

    clearTestButton = new QPushButton("🗑️ Clear", testTab);
    clearTestButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #e74c3c;"
        "  color: white;"
        "  border: none;"
        "  padding: 10px 20px;"
        "  border-radius: 5px;"
        "  font-weight: bold;"
        "  font-size: 11pt;"
        "}"
        "QPushButton:hover {"
        "  background-color: #c0392b;"
        "}"
    );

    buttonLayout->addWidget(runTestButton);
    buttonLayout->addWidget(clearTestButton);
    buttonLayout->addStretch();
    testLayout->addLayout(buttonLayout);

    // Output section
    QLabel *outputLabel = new QLabel("Output:", testTab);
    outputLabel->setStyleSheet("font-weight: bold; font-size: 11pt; color: #34495e; margin-top: 10px;");
    testLayout->addWidget(outputLabel);

    testOutput = new QTextEdit(testTab);
    testOutput->setReadOnly(true);
    testOutput->setPlaceholderText("Test results will appear here...");
    testOutput->setStyleSheet(
        "QTextEdit {"
        "  font-family: 'Consolas', 'Courier New', monospace;"
        "  font-size: 11pt;"
        "  padding: 10px;"
        "  border: 2px solid #bdc3c7;"
        "  border-radius: 5px;"
        "  background-color: #ecf0f1;"
        "}"
    );
    testLayout->addWidget(testOutput);

    contentTabs->addTab(testTab, "🧪 Interactive Test");

    // Connect signals
    connect(runTestButton, &QPushButton::clicked, this, &ContentWidget::onRunTestClicked);
    connect(clearTestButton, &QPushButton::clicked, this, &ContentWidget::onClearTestClicked);
}

void ContentWidget::setProblem(const ProblemData &problem)
{
    // Set description
    QString description = QString("<h2>Problem %1: %2</h2>").arg(problem.number).arg(problem.title);
    description += QString("<p><strong>Description:</strong></p><p>%1</p>").arg(problem.description);
    description += QString("<hr><p><strong>Tutorial:</strong></p><pre>%1</pre>").arg(problem.tutorial);
    description += QString("<hr><p><strong>Example:</strong></p><pre>%1</pre>").arg(problem.example);
    descriptionTab->setHtml(description);

    // Set code solutions
    cppTab->setPlainText(problem.cppSolution);
    pythonTab->setPlainText(problem.pythonSolution);
    jsTab->setPlainText(problem.jsSolution);
}

void ContentWidget::setupSyntaxHighlighting()
{
    cppHighlighter = new CodeHighlighter(cppTab->document());
    pythonHighlighter = new CodeHighlighter(pythonTab->document());
    jsHighlighter = new CodeHighlighter(jsTab->document());
}

QString ContentWidget::getTestInput() const
{
    return testInput->toPlainText();
}

void ContentWidget::setTestOutput(const QString &output)
{
    testOutput->setPlainText(output);

    // Scroll to bottom
    QTextCursor cursor = testOutput->textCursor();
    cursor.movePosition(QTextCursor::End);
    testOutput->setTextCursor(cursor);
}

void ContentWidget::clearTestArea()
{
    testInput->clear();
    testOutput->clear();
    testOutput->setPlainText("🧹 Test area cleared. Ready for new input!");
}

void ContentWidget::onRunTestClicked()
{
    emit runTestRequested();
}

void ContentWidget::onClearTestClicked()
{
    emit clearTestRequested();
}

void ContentWidget::applyTheme(ThemeManager::Theme theme)
{
    if (theme == ThemeManager::Dark) {
        // Apply dark theme to zoom controls
        if (topControlsWidget) {
            topControlsWidget->setStyleSheet("QWidget { background-color: #404040; }");
        }

        // Update zoom label for dark mode
        if (topControlsLayout && topControlsLayout->itemAt(0)) {
            QLabel *zoomLabel = qobject_cast<QLabel*>(topControlsLayout->itemAt(0)->widget());
            if (zoomLabel) {
                zoomLabel->setStyleSheet("font-weight: bold; color: #cccccc;");
            }
        }
        // Apply dark theme styles
        contentTabs->setStyleSheet(R"(
            QTabWidget::pane {
                border: 1px solid #555555;
                background-color: #404040;
            }
            QTabBar::tab {
                background-color: #3c3c3c;
                color: #cccccc;
                border: 1px solid #555555;
                padding: 8px 16px;
                margin-right: 2px;
            }
            QTabBar::tab:selected {
                background-color: #404040;
                color: #ffffff;
            }
            QTabBar::tab:hover {
                background-color: #4a4a4a;
            }
        )");

        // Apply dark theme to text edits
        QString darkTextEditStyle = R"(
            QTextEdit {
                background-color: #2b2b2b;
                color: #ffffff;
                border: 1px solid #555555;
            }
        )";

        descriptionTab->setStyleSheet(darkTextEditStyle);
        cppTab->setStyleSheet(darkTextEditStyle);
        pythonTab->setStyleSheet(darkTextEditStyle);
        jsTab->setStyleSheet(darkTextEditStyle);
        testInput->setStyleSheet(darkTextEditStyle);
        testOutput->setStyleSheet(darkTextEditStyle);

    } else {
        // Apply light theme to zoom controls
        if (topControlsWidget) {
            topControlsWidget->setStyleSheet("QWidget { background-color: white; }");
        }

        // Update zoom label for light mode
        if (topControlsLayout && topControlsLayout->itemAt(0)) {
            QLabel *zoomLabel = qobject_cast<QLabel*>(topControlsLayout->itemAt(0)->widget());
            if (zoomLabel) {
                zoomLabel->setStyleSheet("font-weight: bold; color: #495057;");
            }
        }

        // Apply light theme styles (original)
        contentTabs->setStyleSheet(R"(
            QTabWidget::pane {
                border: 1px solid #dee2e6;
                background-color: white;
            }
            QTabBar::tab {
                background-color: #f8f9fa;
                color: #495057;
                border: 1px solid #dee2e6;
                padding: 8px 16px;
                margin-right: 2px;
            }
            QTabBar::tab:selected {
                background-color: white;
                color: #2c3e50;
                border-bottom-color: white;
            }
            QTabBar::tab:hover {
                background-color: #e9ecef;
            }
        )");

        // Apply light theme to text edits
        QString lightTextEditStyle = R"(
            QTextEdit {
                background-color: white;
                color: #2c3e50;
                border: 1px solid #dee2e6;
            }
        )";

        descriptionTab->setStyleSheet(lightTextEditStyle);
        cppTab->setStyleSheet(lightTextEditStyle);
        pythonTab->setStyleSheet(lightTextEditStyle);
        jsTab->setStyleSheet(lightTextEditStyle);
        testInput->setStyleSheet(lightTextEditStyle);
        testOutput->setStyleSheet(lightTextEditStyle);
    }
}

void ContentWidget::zoomIn()
{
    if (currentZoomLevel < 3) {
        currentZoomLevel++;
        updateFontSizes();
    }
}

void ContentWidget::zoomOut()
{
    if (currentZoomLevel > -2) {
        currentZoomLevel--;
        updateFontSizes();
    }
}

void ContentWidget::resetZoom()
{
    currentZoomLevel = 0;
    updateFontSizes();
}

void ContentWidget::updateFontSizes()
{
    // Calculate new font size based on zoom level
    int newFontSize = baseFontSize + (currentZoomLevel * 2); // 2pt increments

    // Update font for all text content areas
    QFont font;
    font.setPointSize(newFontSize);

    if (descriptionTab) descriptionTab->setFont(font);
    if (cppTab) cppTab->setFont(font);
    if (pythonTab) pythonTab->setFont(font);
    if (jsTab) jsTab->setFont(font);
    if (testInput) testInput->setFont(font);
    if (testOutput) testOutput->setFont(font);

    // Update button states
    zoomInButton->setEnabled(currentZoomLevel < 3);
    zoomOutButton->setEnabled(currentZoomLevel > -2);

    // Update reset button text to show current zoom level
    int zoomPercentage = 100 + (currentZoomLevel * 17); // Approximately 17% per level
    resetZoomButton->setText(QString("%1%").arg(zoomPercentage));
}