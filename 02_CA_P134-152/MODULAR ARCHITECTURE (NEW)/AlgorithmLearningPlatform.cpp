#include "AlgorithmLearningPlatform.h"

AlgorithmLearningPlatform::AlgorithmLearningPlatform(QWidget *parent)
    : QMainWindow(parent)
    , centralWidget(nullptr)
    , mainSplitter(nullptr)
    , sidebar(nullptr)
    , header(nullptr)
    , contentArea(nullptr)
    , themeManager(nullptr)
    , simulator(nullptr)
    , sidebarVisible(true)
    , autoHideSidebar(false)
{
    setWindowTitle("🚀 Algorithm Learning Platform - Problems 134-153");
    setMinimumSize(600, 400);
    resize(1400, 900);

    // Initialize managers
    themeManager = new ThemeManager(this);
    simulator = new AlgorithmSimulator(this);

    setupUI();
    loadProblemData();
    connectSignals();

    // Load first problem by default
    if (!problems.empty()) {
        sidebar->getProblemList()->setCurrentRow(0);
        onProblemSelected(problems[0].number);
    }

    // Apply initial theme
    themeManager->setTheme(ThemeManager::Light);
}

AlgorithmLearningPlatform::~AlgorithmLearningPlatform()
{
}

void AlgorithmLearningPlatform::setupUI()
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Create header
    header = new HeaderWidget(this);
    mainLayout->addWidget(header);

    // Create splitter for sidebar and content
    mainSplitter = new QSplitter(Qt::Horizontal, this);
    mainSplitter->setChildrenCollapsible(false);

    // Create sidebar
    sidebar = new SidebarWidget(this);
    sidebar->setMaximumWidth(350);
    sidebar->setMinimumWidth(250);

    // Create content area
    contentArea = new ContentWidget(this);

    // Add to splitter
    mainSplitter->addWidget(sidebar);
    mainSplitter->addWidget(contentArea);

    // Set splitter proportions (sidebar:content = 1:3)
    mainSplitter->setSizes({300, 900});

    mainLayout->addWidget(mainSplitter);
}

void AlgorithmLearningPlatform::loadProblemData()
{
    problems = ProblemDataManager::loadAllProblems();
    sidebar->setProblems(problems);
}

void AlgorithmLearningPlatform::connectSignals()
{
    // Header signals
    connect(header, &HeaderWidget::sidebarToggleRequested, this, &AlgorithmLearningPlatform::toggleSidebar);
    connect(header, &HeaderWidget::themeToggleRequested, this, &AlgorithmLearningPlatform::toggleTheme);
    connect(header, &HeaderWidget::aboutRequested, this, &AlgorithmLearningPlatform::showAbout);

    // Sidebar signals
    connect(sidebar, &SidebarWidget::problemSelected, this, &AlgorithmLearningPlatform::onProblemSelected);
    connect(sidebar, &SidebarWidget::resetRequested, this, &AlgorithmLearningPlatform::resetView);
    connect(sidebar->getSearchBox(), &QLineEdit::textChanged, this, &AlgorithmLearningPlatform::onSearchTextChanged);

    // Content area signals
    connect(contentArea, &ContentWidget::runTestRequested, this, &AlgorithmLearningPlatform::runTest);
    connect(contentArea, &ContentWidget::clearTestRequested, this, &AlgorithmLearningPlatform::clearTest);

    // Theme manager signals
    connect(themeManager, &ThemeManager::themeChanged, this, [this](ThemeManager::Theme theme) {
        // Apply theme to all components
        setStyleSheet(themeManager->getMainWindowStyle());
        // Apply theme to content area
        contentArea->applyTheme(theme);
        // Apply theme to sidebar
        sidebar->applyTheme(theme);
    });
}

void AlgorithmLearningPlatform::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    checkViewportWidth();
}

void AlgorithmLearningPlatform::checkViewportWidth()
{
    int currentWidth = width();

    if (currentWidth < SIDEBAR_AUTO_HIDE_WIDTH && sidebarVisible && !autoHideSidebar) {
        autoHideSidebar = true;
        sidebar->slideOut();
        sidebarVisible = false;
    } else if (currentWidth >= SIDEBAR_AUTO_HIDE_WIDTH && !sidebarVisible && autoHideSidebar) {
        autoHideSidebar = false;
        sidebar->slideIn();
        sidebarVisible = true;
    }
}

void AlgorithmLearningPlatform::onProblemSelected(int problemId)
{
    // Find problem by ID
    for (const ProblemData &problem : problems) {
        if (problem.number == problemId) {
            updateProblemDisplay(problem);
            header->setCurrentProblem(problem.number, problem.title);
            break;
        }
    }
}

void AlgorithmLearningPlatform::updateProblemDisplay(const ProblemData &problem)
{
    contentArea->setProblem(problem);
}

void AlgorithmLearningPlatform::onSearchTextChanged(const QString &text)
{
    sidebar->filterProblems(text);
}

void AlgorithmLearningPlatform::resetView()
{
    sidebar->resetSelection();
}

void AlgorithmLearningPlatform::toggleSidebar()
{
    if (sidebarVisible) {
        sidebar->slideOut();
        sidebarVisible = false;
    } else {
        sidebar->slideIn();
        sidebarVisible = true;
    }
    autoHideSidebar = false; // Manual toggle disables auto-hide
}

void AlgorithmLearningPlatform::toggleTheme()
{
    themeManager->toggleTheme();
}

void AlgorithmLearningPlatform::runTest()
{
    QString input = contentArea->getTestInput().trimmed();
    if (input.isEmpty()) {
        contentArea->setTestOutput("❌ Error: Please enter some input to test!");
        return;
    }

    // Get current selected problem
    int currentRow = sidebar->getProblemList()->currentRow();
    if (currentRow < 0 || currentRow >= problems.size()) {
        contentArea->setTestOutput("❌ Error: Please select a problem first!");
        return;
    }

    const ProblemData &currentProblem = problems[currentRow];

    QString output = "🔄 Running test for Problem " + QString::number(currentProblem.number) + ": " + currentProblem.title + "\n";
    output += "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    output += "📥 Input: " + input + "\n\n";

    // Execute algorithm simulation
    QString result = simulator->executeAlgorithm(currentProblem, input);

    output += "📤 Output: " + result + "\n\n";
    output += "✅ Test completed! Check if the output matches your expected result.";

    contentArea->setTestOutput(output);
}

void AlgorithmLearningPlatform::clearTest()
{
    contentArea->clearTestArea();
}

void AlgorithmLearningPlatform::showAbout()
{
    QMessageBox::about(this, "About Algorithm Learning Platform",
        "<h2>🚀 Algorithm Learning Platform</h2>"
        "<p><b>Problems 134-153: Advanced Algorithms & Data Structures</b></p>"
        "<hr>"
        "<p>This educational platform provides comprehensive tutorials and "
        "multi-language solutions for competitive programming and algorithm learning.</p>"
        "<h3>✨ Key Features:</h3>"
        "<ul style='margin-left: 20px;'>"
        "<li>🔍 <b>Smart Search:</b> Quickly find problems by name or number</li>"
        "<li>📖 <b>Detailed Tutorials:</b> Step-by-step algorithm explanations</li>"
        "<li>⚡ <b>C++ Solutions:</b> Optimized code with syntax highlighting</li>"
        "<li>🐍 <b>Python Implementations:</b> Pythonic approaches and alternatives</li>"
        "<li>🌐 <b>JavaScript Versions:</b> Modern ES6+ implementations</li>"
        "<li>💡 <b>Rich Examples:</b> Multiple test cases with explanations</li>"
        "<li>🎨 <b>Modern UI:</b> Professional interface for enhanced learning</li>"
        "<li>🌓 <b>Dark/Light Theme:</b> Comfortable viewing in any environment</li>"
        "<li>📱 <b>Responsive Design:</b> Adaptive layout for different screen sizes</li>"
        "<li>🧪 <b>Interactive Testing:</b> Test algorithms with custom input</li>"
        "</ul>"
        "<hr>"
        "<p><i>\"The program successfully balances mathematical rigor with accessibility, making complex "
        "algorithms approachable to learners of all levels.\"</i></p>"
        "<hr>"
        "<p style='text-align: center; color: #666666; font-size: 11pt;'>🎓 Enhanced Learning Experience | "
        "Interactive Testing | Multi-Language Support</p>");
}

