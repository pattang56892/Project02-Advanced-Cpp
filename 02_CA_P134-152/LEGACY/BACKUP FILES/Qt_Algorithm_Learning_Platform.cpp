// Qt_Algorithm_Learning_Platform.cpp
// GUI version of the Algorithm Learning Platform for Problems 134-153
// Converts console-based learning tool to modern Qt interface

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
#include <QMessageBox>
#include <vector>
#include <string>
#include <unordered_map>

class CodeHighlighter : public QSyntaxHighlighter {
    Q_OBJECT

public:
    explicit CodeHighlighter(QTextDocument *parent = nullptr);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QTextCharFormat keywordFormat;
    QTextCharFormat stringFormat;
    QTextCharFormat commentFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat functionFormat;
};

struct ProblemData {
    int number;
    QString title;
    QString description;
    QString tutorial;
    QString cppSolution;
    QString pythonSolution;
    QString jsSolution;
    QString example;
};

class AlgorithmLearningPlatform : public QMainWindow {
    Q_OBJECT

public:
    explicit AlgorithmLearningPlatform(QWidget *parent = nullptr);
    ~AlgorithmLearningPlatform();

private slots:
    void onProblemSelected(int row);
    void onSearchTextChanged(const QString &text);
    void resetView();
    void showAbout();

private:
    void setupUI();
    void loadProblemData();
    void updateProblemDisplay(const ProblemData &problem);
    void setupSyntaxHighlighting();

    // UI Components
    QWidget *centralWidget;
    QSplitter *mainSplitter;

    // Left Panel
    QWidget *leftPanel;
    QLineEdit *searchBox;
    QListWidget *problemList;
    QPushButton *resetButton;

    // Right Panel
    QWidget *rightPanel;
    QLabel *problemTitle;
    QTabWidget *contentTabs;
    QTextEdit *descriptionTab;
    QTextEdit *cppTab;
    QTextEdit *pythonTab;
    QTextEdit *jsTab;

    // Header/Footer
    QLabel *headerLabel;
    QPushButton *aboutButton;

    // Data
    std::vector<ProblemData> problems;
    CodeHighlighter *cppHighlighter;
    CodeHighlighter *pythonHighlighter;
    CodeHighlighter *jsHighlighter;
};

#endif // ALGORITHM_LEARNING_PLATFORM_H

// Implementation

CodeHighlighter::CodeHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    // Keyword format
    keywordFormat.setColor(QColor(86, 156, 214)); // VS Code blue
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bclass\\b" << "\\bpublic\\b" << "\\bprivate\\b"
                    << "\\bprotected\\b" << "\\bint\\b" << "\\bvoid\\b"
                    << "\\bbool\\b" << "\\breturn\\b" << "\\bif\\b"
                    << "\\belse\\b" << "\\bfor\\b" << "\\bwhile\\b"
                    << "\\bvector\\b" << "\\bstring\\b" << "\\bauto\\b"
                    << "\\bconst\\b" << "\\bstatic\\b" << "\\binline\\b"
                    << "\\bnamespace\\b" << "\\busing\\b" << "\\binclude\\b";

    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    // String format
    stringFormat.setColor(QColor(206, 145, 120)); // VS Code orange
    rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
    rule.format = stringFormat;
    highlightingRules.append(rule);

    // Comment format
    commentFormat.setColor(QColor(106, 153, 85)); // VS Code green
    commentFormat.setFontItalic(true);
    rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
    rule.format = commentFormat;
    highlightingRules.append(rule);

    // Number format
    numberFormat.setColor(QColor(181, 206, 168)); // VS Code light green
    rule.pattern = QRegularExpression(QStringLiteral("\\b\\d+\\b"));
    rule.format = numberFormat;
    highlightingRules.append(rule);

    // Function format
    functionFormat.setColor(QColor(220, 220, 170)); // VS Code yellow
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z]+(?=\\()"));
    rule.format = functionFormat;
    highlightingRules.append(rule);
}

void CodeHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}

AlgorithmLearningPlatform::AlgorithmLearningPlatform(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Algorithm Learning Platform - Problems 134-153");
    setMinimumSize(1200, 800);
    resize(1400, 900);

    loadProblemData();
    setupUI();
    setupSyntaxHighlighting();

    // Load first problem by default
    if (!problems.empty()) {
        problemList->setCurrentRow(0);
        onProblemSelected(0);
    }
}

AlgorithmLearningPlatform::~AlgorithmLearningPlatform() {}

void AlgorithmLearningPlatform::setupUI()
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Header
    headerLabel = new QLabel("Algorithm Learning Platform - Problems 134-153", this);
    QFont headerFont;
    headerFont.setPointSize(18);
    headerFont.setBold(true);
    headerLabel->setFont(headerFont);
    headerLabel->setStyleSheet("color: #2e86ab; padding: 15px; background-color: #f8f9fa; border-radius: 8px; margin-bottom: 10px;");
    headerLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(headerLabel);

    // Main splitter
    mainSplitter = new QSplitter(Qt::Horizontal, this);
    mainLayout->addWidget(mainSplitter);

    // Left Panel
    leftPanel = new QWidget(this);
    leftPanel->setMaximumWidth(350);
    leftPanel->setMinimumWidth(250);
    QVBoxLayout *leftLayout = new QVBoxLayout(leftPanel);

    // Search box
    QLabel *searchLabel = new QLabel("Search Problems:", this);
    searchLabel->setStyleSheet("font-weight: bold; color: #333;");
    leftLayout->addWidget(searchLabel);

    searchBox = new QLineEdit(this);
    searchBox->setPlaceholderText("Type to filter problems...");
    searchBox->setStyleSheet("padding: 8px; border: 2px solid #ddd; border-radius: 4px;");
    connect(searchBox, &QLineEdit::textChanged, this, &AlgorithmLearningPlatform::onSearchTextChanged);
    leftLayout->addWidget(searchBox);

    // Problem list
    QLabel *listLabel = new QLabel("Algorithm Problems:", this);
    listLabel->setStyleSheet("font-weight: bold; color: #333; margin-top: 10px;");
    leftLayout->addWidget(listLabel);

    problemList = new QListWidget(this);
    problemList->setStyleSheet(
        "QListWidget {"
        "  border: 2px solid #ddd;"
        "  border-radius: 4px;"
        "  background-color: white;"
        "}"
        "QListWidget::item {"
        "  padding: 8px;"
        "  border-bottom: 1px solid #eee;"
        "}"
        "QListWidget::item:selected {"
        "  background-color: #2e86ab;"
        "  color: white;"
        "}"
        "QListWidget::item:hover {"
        "  background-color: #e3f2fd;"
        "}"
    );
    connect(problemList, &QListWidget::currentRowChanged, this, &AlgorithmLearningPlatform::onProblemSelected);
    leftLayout->addWidget(problemList);

    // Reset button
    resetButton = new QPushButton("Clear Search", this);
    resetButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #6c757d;"
        "  color: white;"
        "  border: none;"
        "  padding: 8px;"
        "  border-radius: 4px;"
        "  font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "  background-color: #545b62;"
        "}"
    );
    connect(resetButton, &QPushButton::clicked, this, &AlgorithmLearningPlatform::resetView);
    leftLayout->addWidget(resetButton);

    mainSplitter->addWidget(leftPanel);

    // Right Panel
    rightPanel = new QWidget(this);
    QVBoxLayout *rightLayout = new QVBoxLayout(rightPanel);

    // Problem title
    problemTitle = new QLabel("Select a problem to view details", this);
    QFont titleFont;
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    problemTitle->setFont(titleFont);
    problemTitle->setStyleSheet("color: #2e86ab; padding: 10px; background-color: #f8f9fa; border-radius: 4px;");
    problemTitle->setAlignment(Qt::AlignCenter);
    rightLayout->addWidget(problemTitle);

    // Content tabs
    contentTabs = new QTabWidget(this);
    contentTabs->setStyleSheet(
        "QTabWidget::pane {"
        "  border: 2px solid #ddd;"
        "  background-color: white;"
        "}"
        "QTabBar::tab {"
        "  background-color: #f8f9fa;"
        "  padding: 8px 16px;"
        "  margin-right: 2px;"
        "  border: 1px solid #ddd;"
        "  border-bottom: none;"
        "}"
        "QTabBar::tab:selected {"
        "  background-color: white;"
        "  border-bottom: 2px solid #2e86ab;"
        "}"
    );

    // Description tab
    descriptionTab = new QTextEdit(this);
    descriptionTab->setReadOnly(true);
    descriptionTab->setStyleSheet("font-family: 'Segoe UI', Arial, sans-serif; font-size: 11pt; padding: 10px;");
    contentTabs->addTab(descriptionTab, "📖 Description & Tutorial");

    // C++ tab
    cppTab = new QTextEdit(this);
    cppTab->setReadOnly(true);
    cppTab->setStyleSheet("font-family: 'Consolas', 'Courier New', monospace; font-size: 10pt; padding: 10px; background-color: #1e1e1e; color: #d4d4d4;");
    contentTabs->addTab(cppTab, "⚡ C++ Solution");

    // Python tab
    pythonTab = new QTextEdit(this);
    pythonTab->setReadOnly(true);
    pythonTab->setStyleSheet("font-family: 'Consolas', 'Courier New', monospace; font-size: 10pt; padding: 10px; background-color: #1e1e1e; color: #d4d4d4;");
    contentTabs->addTab(pythonTab, "🐍 Python Solution");

    // JavaScript tab
    jsTab = new QTextEdit(this);
    jsTab->setReadOnly(true);
    jsTab->setStyleSheet("font-family: 'Consolas', 'Courier New', monospace; font-size: 10pt; padding: 10px; background-color: #1e1e1e; color: #d4d4d4;");
    contentTabs->addTab(jsTab, "🌐 JavaScript Solution");

    rightLayout->addWidget(contentTabs);

    mainSplitter->addWidget(rightPanel);

    // Set splitter proportions
    mainSplitter->setSizes({300, 900});

    // Footer with about button
    QHBoxLayout *footerLayout = new QHBoxLayout();
    footerLayout->addStretch();

    aboutButton = new QPushButton("About Platform", this);
    aboutButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #17a2b8;"
        "  color: white;"
        "  border: none;"
        "  padding: 8px 16px;"
        "  border-radius: 4px;"
        "  font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "  background-color: #138496;"
        "}"
    );
    connect(aboutButton, &QPushButton::clicked, this, &AlgorithmLearningPlatform::showAbout);
    footerLayout->addWidget(aboutButton);

    mainLayout->addLayout(footerLayout);
}

void AlgorithmLearningPlatform::setupSyntaxHighlighting()
{
    cppHighlighter = new CodeHighlighter(cppTab->document());
    pythonHighlighter = new CodeHighlighter(pythonTab->document());
    jsHighlighter = new CodeHighlighter(jsTab->document());
}

void AlgorithmLearningPlatform::loadProblemData()
{
    // Sample problems - in real implementation, load from the original file
    problems = {
        {134, "Longest Harmonious Subsequence",
         "Find the length of the longest subsequence in an array where the difference between the largest and smallest element is exactly 1.",
         "Tutorial:\n1. A harmonious subsequence can only contain two numbers: x and x+1\n2. Count frequency of each number\n3. For each number x, check if x+1 exists\n4. Length = count(x) + count(x+1)\n5. Track maximum length",
         "#include <vector>\n#include <unordered_map>\nusing namespace std;\n\nclass Solution {\npublic:\n    int findLHS(vector<int>& nums) {\n        unordered_map<int, int> count;\n        for (int num : nums) {\n            count[num]++;\n        }\n        \n        int maxLen = 0;\n        for (const auto& [num, cnt] : count) {\n            if (count.find(num + 1) != count.end()) {\n                maxLen = max(maxLen, cnt + count[num + 1]);\n            }\n        }\n        \n        return maxLen;\n    }\n};",
         "from collections import Counter\n\nclass Solution:\n    def findLHS(self, nums):\n        count = Counter(nums)\n        max_len = 0\n        for num in count:\n            if num + 1 in count:\n                max_len = max(max_len, count[num] + count[num + 1])\n        return max_len",
         "var findLHS = function(nums) {\n    const count = {};\n    for (const num of nums) {\n        count[num] = (count[num] || 0) + 1;\n    }\n    \n    let maxLen = 0;\n    for (const numStr in count) {\n        const num = parseInt(numStr);\n        if (count[num + 1]) {\n            maxLen = Math.max(maxLen, count[num] + count[num + 1]);\n        }\n    }\n    \n    return maxLen;\n};",
         "Example:\nInput: [1,3,2,2,5,2,3,7]\nOutput: 5\nExplanation: Longest subsequence is [3,2,2,2,3]"
        },
        {135, "Remove Element",
         "Remove all instances of a given value from an array in-place and return the new length.",
         "Tutorial:\n1. Use two pointers approach\n2. Keep one pointer for current position\n3. Move elements that are not equal to target\n4. Return final position as new length",
         "#include <vector>\nusing namespace std;\n\nclass Solution {\npublic:\n    int removeElement(vector<int>& nums, int val) {\n        int k = 0;\n        for (int i = 0; i < nums.size(); i++) {\n            if (nums[i] != val) {\n                nums[k] = nums[i];\n                k++;\n            }\n        }\n        return k;\n    }\n};",
         "class Solution:\n    def removeElement(self, nums, val):\n        k = 0\n        for i in range(len(nums)):\n            if nums[i] != val:\n                nums[k] = nums[i]\n                k += 1\n        return k",
         "var removeElement = function(nums, val) {\n    let k = 0;\n    for (let i = 0; i < nums.length; i++) {\n        if (nums[i] !== val) {\n            nums[k] = nums[i];\n            k++;\n        }\n    }\n    return k;\n};",
         "Example:\nInput: nums = [3,2,2,3], val = 3\nOutput: 2\nExplanation: nums becomes [2,2,_,_]"
        }
        // Add more problems as needed...
    };

    // Populate the list widget
    for (const auto &problem : problems) {
        QString itemText = QString("%1. %2").arg(problem.number).arg(problem.title);
        problemList->addItem(itemText);
    }
}

void AlgorithmLearningPlatform::onProblemSelected(int row)
{
    if (row >= 0 && row < problems.size()) {
        updateProblemDisplay(problems[row]);
    }
}

void AlgorithmLearningPlatform::updateProblemDisplay(const ProblemData &problem)
{
    problemTitle->setText(QString("Problem %1: %2").arg(problem.number).arg(problem.title));

    // Update description tab
    QString descContent = QString("<h2>Problem Description</h2><p>%1</p><h2>%2</h2><p style='white-space: pre-line;'>%3</p><h2>Example</h2><p style='white-space: pre-line; font-family: monospace; background-color: #f8f9fa; padding: 10px; border-radius: 4px;'>%4</p>")
                         .arg(problem.description)
                         .arg("Tutorial")
                         .arg(problem.tutorial)
                         .arg(problem.example);
    descriptionTab->setHtml(descContent);

    // Update code tabs
    cppTab->setText(problem.cppSolution);
    pythonTab->setText(problem.pythonSolution);
    jsTab->setText(problem.jsSolution);
}

void AlgorithmLearningPlatform::onSearchTextChanged(const QString &text)
{
    for (int i = 0; i < problemList->count(); ++i) {
        QListWidgetItem *item = problemList->item(i);
        bool visible = item->text().contains(text, Qt::CaseInsensitive);
        item->setHidden(!visible);
    }
}

void AlgorithmLearningPlatform::resetView()
{
    searchBox->clear();
    for (int i = 0; i < problemList->count(); ++i) {
        problemList->item(i)->setHidden(false);
    }
}

void AlgorithmLearningPlatform::showAbout()
{
    QMessageBox::about(this, "About Algorithm Learning Platform",
        "<h3>Algorithm Learning Platform</h3>"
        "<p><b>Problems 134-153: Advanced Algorithms</b></p>"
        "<p>This educational platform provides comprehensive tutorials and "
        "multi-language solutions for algorithmic problems.</p>"
        "<p>Features:</p>"
        "<ul>"
        "<li>🔍 Searchable problem database</li>"
        "<li>📖 Step-by-step tutorials</li>"
        "<li>⚡ C++ Solutions with syntax highlighting</li>"
        "<li>🐍 Python implementations</li>"
        "<li>🌐 JavaScript versions</li>"
        "<li>💡 Example test cases</li>"
        "</ul>"
        "<p><i>Built with Qt for enhanced learning experience</i></p>");
}

// Main application entry point
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    AlgorithmLearningPlatform platform;
    platform.show();

    return app.exec();
}

#include "Qt_Algorithm_Learning_Platform.moc"