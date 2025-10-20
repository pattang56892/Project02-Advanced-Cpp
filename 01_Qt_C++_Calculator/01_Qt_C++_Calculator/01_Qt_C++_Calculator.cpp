// 01_Qt_C++_Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ============================================================================
// FILE: CarCalculator.h
// Qt Car Payment Calculator - Header File
// ============================================================================

#ifndef CARCALCULATOR_H
#define CARCALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDate>
#include <cmath>

class CarCalculator : public QMainWindow {
    Q_OBJECT

public:
    explicit CarCalculator(QWidget* parent = nullptr);
    ~CarCalculator();

private slots:
    void calculatePayment();
    void exportToCSV();

private:
    void setupUI();
    QGroupBox* createInputSection();
    QGroupBox* createResultsSection();
    QGroupBox* createComparisonSection();
    void updateResults();

    // Input widgets
    QDoubleSpinBox* vehiclePriceInput;
    QDoubleSpinBox* tradeInInput;
    QDoubleSpinBox* downPaymentInput;
    QDoubleSpinBox* hstRateInput;
    QDoubleSpinBox* licenceFeeInput;
    QDoubleSpinBox* registrationFeeInput;
    QDoubleSpinBox* annualRateInput;
    QSpinBox* monthsInput;

    // Result labels
    QLabel* netPriceLabel;
    QLabel* hstAmountLabel;
    QLabel* totalPurchaseLabel;
    QLabel* amountFinancedLabel;
    QLabel* totalLoanLabel;
    QLabel* monthlyPaymentLabel;
    QLabel* totalPaidLabel;
    QLabel* totalInterestLabel;

    // Comparison labels
    QLabel* biweeklyPaymentLabel;
    QLabel* biweeklyInterestLabel;
    QLabel* savingsLabel;

    // Opportunity cost labels
    QLabel* opportunityCostLabel;
    QLabel* netSavingsLabel;

    // Tables
    QTableWidget* detailsTable;
    QTableWidget* comparisonTable;

    // Buttons
    QPushButton* calculateBtn;
    QPushButton* exportBtn;

    // Calculation results (stored for export)
    struct Results {
        double netPrice = 0;
        double hstAmount = 0;
        double totalPurchase = 0;
        double amountFinanced = 0;
        double totalLoan = 0;
        double monthlyPayment = 0;
        double totalPaid = 0;
        double totalInterest = 0;
        double biweeklyPayment = 0;
        double biweeklyTotalInterest = 0;
        double opportunityCost = 0;
        double netSavings = 0;
    } results;
};

#endif // CARCALCULATOR_H


// ============================================================================
// FILE: CarCalculator.cpp
// Qt Car Payment Calculator - Implementation
// ============================================================================

//#include "CarCalculator.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QHeaderView>
#include <QFont>

CarCalculator::CarCalculator(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("Nissan Kick - Car Payment Calculator");
    resize(1000, 800);
    setupUI();
}

CarCalculator::~CarCalculator() {}

void CarCalculator::setupUI() {
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    // Title
    QLabel* title = new QLabel("Nissan Kick - Monthly Payment Calculator", this);
    QFont titleFont;
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    title->setFont(titleFont);
    title->setStyleSheet("color: #16a34a; padding: 10px;");
    mainLayout->addWidget(title);

    // Input section
    mainLayout->addWidget(createInputSection());

    // Calculate button
    calculateBtn = new QPushButton("Calculate Payment", this);
    calculateBtn->setStyleSheet(
        "QPushButton {"
        "  background-color: #16a34a;"
        "  color: white;"
        "  font-weight: bold;"
        "  padding: 10px;"
        "  border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #15803d;"
        "}"
    );
    connect(calculateBtn, &QPushButton::clicked, this, &CarCalculator::calculatePayment);
    mainLayout->addWidget(calculateBtn);

    // Results section
    mainLayout->addWidget(createResultsSection());

    // Comparison section
    mainLayout->addWidget(createComparisonSection());

    // Export button
    exportBtn = new QPushButton("Export to CSV", this);
    exportBtn->setStyleSheet(
        "QPushButton {"
        "  background-color: #2563eb;"
        "  color: white;"
        "  padding: 8px;"
        "  border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #1d4ed8;"
        "}"
    );
    connect(exportBtn, &QPushButton::clicked, this, &CarCalculator::exportToCSV);
    mainLayout->addWidget(exportBtn);
}

QGroupBox* CarCalculator::createInputSection() {
    QGroupBox* inputGroup = new QGroupBox("Vehicle & Financing Details", this);
    QGridLayout* layout = new QGridLayout(inputGroup);

    // Initialize input widgets with default values
    vehiclePriceInput = new QDoubleSpinBox(this);
    vehiclePriceInput->setRange(0, 999999);
    vehiclePriceInput->setValue(19138.00);
    vehiclePriceInput->setPrefix("$");

    tradeInInput = new QDoubleSpinBox(this);
    tradeInInput->setRange(0, 999999);
    tradeInInput->setValue(1000.00);
    tradeInInput->setPrefix("$");

    downPaymentInput = new QDoubleSpinBox(this);
    downPaymentInput->setRange(0, 999999);
    downPaymentInput->setValue(10000.00);
    downPaymentInput->setPrefix("$");

    hstRateInput = new QDoubleSpinBox(this);
    hstRateInput->setRange(0, 100);
    hstRateInput->setValue(13.0);
    hstRateInput->setSuffix("%");

    licenceFeeInput = new QDoubleSpinBox(this);
    licenceFeeInput->setRange(0, 9999);
    licenceFeeInput->setValue(42.00);
    licenceFeeInput->setPrefix("$");

    registrationFeeInput = new QDoubleSpinBox(this);
    registrationFeeInput->setRange(0, 9999);
    registrationFeeInput->setValue(169.00);
    registrationFeeInput->setPrefix("$");

    annualRateInput = new QDoubleSpinBox(this);
    annualRateInput->setRange(0, 100);
    annualRateInput->setValue(7.99);
    annualRateInput->setSuffix("%");
    annualRateInput->setDecimals(2);

    monthsInput = new QSpinBox(this);
    monthsInput->setRange(12, 120);
    monthsInput->setValue(60);
    monthsInput->setSuffix(" months");

    // Add to layout
    int row = 0;
    layout->addWidget(new QLabel("Vehicle Price:"), row, 0);
    layout->addWidget(vehiclePriceInput, row++, 1);

    layout->addWidget(new QLabel("Trade-in Allowance:"), row, 0);
    layout->addWidget(tradeInInput, row++, 1);

    layout->addWidget(new QLabel("Down Payment:"), row, 0);
    layout->addWidget(downPaymentInput, row++, 1);

    layout->addWidget(new QLabel("HST Rate:"), row, 0);
    layout->addWidget(hstRateInput, row++, 1);

    layout->addWidget(new QLabel("Licence Fee:"), row, 0);
    layout->addWidget(licenceFeeInput, row++, 1);

    layout->addWidget(new QLabel("Registration Fee:"), row, 0);
    layout->addWidget(registrationFeeInput, row++, 1);

    layout->addWidget(new QLabel("Annual Interest Rate:"), row, 0);
    layout->addWidget(annualRateInput, row++, 1);

    layout->addWidget(new QLabel("Loan Term:"), row, 0);
    layout->addWidget(monthsInput, row++, 1);

    return inputGroup;
}

QGroupBox* CarCalculator::createResultsSection() {
    QGroupBox* resultsGroup = new QGroupBox("Your Monthly Payment Plan", this);
    resultsGroup->setStyleSheet("QGroupBox { font-weight: bold; color: #16a34a; }");
    QGridLayout* layout = new QGridLayout(resultsGroup);

    // Create labels for results
    netPriceLabel = new QLabel("$0.00", this);
    hstAmountLabel = new QLabel("$0.00", this);
    totalPurchaseLabel = new QLabel("$0.00", this);
    amountFinancedLabel = new QLabel("$0.00", this);
    totalLoanLabel = new QLabel("$0.00", this);
    monthlyPaymentLabel = new QLabel("$0.00", this);
    totalPaidLabel = new QLabel("$0.00", this);
    totalInterestLabel = new QLabel("$0.00", this);

    // Style the monthly payment label
    QFont paymentFont;
    paymentFont.setPointSize(14);
    paymentFont.setBold(true);
    monthlyPaymentLabel->setFont(paymentFont);
    monthlyPaymentLabel->setStyleSheet("color: #16a34a;");

    int row = 0;
    layout->addWidget(new QLabel("Net Vehicle Price:"), row, 0);
    layout->addWidget(netPriceLabel, row++, 1);

    layout->addWidget(new QLabel("HST Amount:"), row, 0);
    layout->addWidget(hstAmountLabel, row++, 1);

    layout->addWidget(new QLabel("Total Purchase Price:"), row, 0);
    layout->addWidget(totalPurchaseLabel, row++, 1);

    layout->addWidget(new QLabel("Amount Financed:"), row, 0);
    layout->addWidget(amountFinancedLabel, row++, 1);

    layout->addWidget(new QLabel("Total Loan Amount:"), row, 0);
    layout->addWidget(totalLoanLabel, row++, 1);

    // Separator
    QFrame* line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line, row++, 0, 1, 2);

    layout->addWidget(new QLabel("MONTHLY PAYMENT:"), row, 0);
    layout->addWidget(monthlyPaymentLabel, row++, 1);

    layout->addWidget(new QLabel("Total Amount Paid:"), row, 0);
    layout->addWidget(totalPaidLabel, row++, 1);

    layout->addWidget(new QLabel("Total Interest Paid:"), row, 0);
    layout->addWidget(totalInterestLabel, row++, 1);

    return resultsGroup;
}

QGroupBox* CarCalculator::createComparisonSection() {
    QGroupBox* compGroup = new QGroupBox("Savings Analysis", this);
    compGroup->setStyleSheet("QGroupBox { font-weight: bold; color: #dc2626; }");
    QVBoxLayout* layout = new QVBoxLayout(compGroup);

    QLabel* dealershipTitle = new QLabel("Dealership Offer (Bi-weekly @ 7.99%):", this);
    dealershipTitle->setStyleSheet("font-weight: bold; color: #dc2626;");
    layout->addWidget(dealershipTitle);

    biweeklyPaymentLabel = new QLabel("Bi-weekly Payment: $165.04", this);
    biweeklyInterestLabel = new QLabel("Total Interest: $3,789.66", this);
    layout->addWidget(biweeklyPaymentLabel);
    layout->addWidget(biweeklyInterestLabel);

    QFrame* line1 = new QFrame(this);
    line1->setFrameShape(QFrame::HLine);
    line1->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line1);

    savingsLabel = new QLabel("Interest Saved: $0.00", this);
    QFont savingsFont;
    savingsFont.setPointSize(12);
    savingsFont.setBold(true);
    savingsLabel->setFont(savingsFont);
    savingsLabel->setStyleSheet("color: #16a34a; padding: 10px;");
    layout->addWidget(savingsLabel);

    QFrame* line2 = new QFrame(this);
    line2->setFrameShape(QFrame::HLine);
    line2->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line2);

    opportunityCostLabel = new QLabel("Opportunity Cost (2.5% for 5 years): $0.00", this);
    opportunityCostLabel->setStyleSheet("color: #ea580c;");
    layout->addWidget(opportunityCostLabel);

    netSavingsLabel = new QLabel("NET SAVINGS (after opportunity cost): $0.00", this);
    netSavingsLabel->setFont(savingsFont);
    netSavingsLabel->setStyleSheet("color: #2563eb; padding: 10px;");
    layout->addWidget(netSavingsLabel);

    return compGroup;
}

void CarCalculator::calculatePayment() {
    // Get input values
    double vehiclePrice = vehiclePriceInput->value();
    double tradeIn = tradeInInput->value();
    double downPayment = downPaymentInput->value();
    double hstRate = hstRateInput->value() / 100.0;
    double licenceFee = licenceFeeInput->value();
    double registrationFee = registrationFeeInput->value();
    double annualRate = annualRateInput->value() / 100.0;
    int months = monthsInput->value();

    // Calculate step by step
    results.netPrice = vehiclePrice - tradeIn;
    results.hstAmount = results.netPrice * hstRate;
    results.totalPurchase = results.netPrice + results.hstAmount + licenceFee;
    results.amountFinanced = results.totalPurchase - downPayment;
    results.totalLoan = results.amountFinanced + registrationFee;

    // Monthly payment calculation
    double monthlyRate = annualRate / 12.0;
    if (monthlyRate > 0) {
        results.monthlyPayment = results.totalLoan *
            (monthlyRate * std::pow(1 + monthlyRate, months)) /
            (std::pow(1 + monthlyRate, months) - 1);
    }
    else {
        results.monthlyPayment = results.totalLoan / months;
    }

    results.totalPaid = results.monthlyPayment * months;
    results.totalInterest = results.totalPaid - results.totalLoan;

    // Bi-weekly comparison (dealership offer)
    double biweeklyRate = annualRate / 26.0;
    int biweeklyPayments = 130;
    if (biweeklyRate > 0) {
        results.biweeklyPayment = results.totalLoan *
            (biweeklyRate * std::pow(1 + biweeklyRate, biweeklyPayments)) /
            (std::pow(1 + biweeklyRate, biweeklyPayments) - 1);
    }
    double biweeklyTotalPaid = results.biweeklyPayment * biweeklyPayments;
    results.biweeklyTotalInterest = biweeklyTotalPaid - results.totalLoan;

    // Opportunity cost
    double extraDownPayment = downPayment - 3042.00;
    double opportunityRate = 0.025;
    double years = months / 12.0;
    double futureValue = extraDownPayment * std::pow(1 + opportunityRate, years);
    results.opportunityCost = futureValue - extraDownPayment;

    double grossSavings = 3789.66 - results.totalInterest;
    results.netSavings = grossSavings - results.opportunityCost;

    updateResults();
}

void CarCalculator::updateResults() {
    // Update result labels
    netPriceLabel->setText(QString("$%1").arg(results.netPrice, 0, 'f', 2));
    hstAmountLabel->setText(QString("$%1").arg(results.hstAmount, 0, 'f', 2));
    totalPurchaseLabel->setText(QString("$%1").arg(results.totalPurchase, 0, 'f', 2));
    amountFinancedLabel->setText(QString("$%1").arg(results.amountFinanced, 0, 'f', 2));
    totalLoanLabel->setText(QString("$%1").arg(results.totalLoan, 0, 'f', 2));
    monthlyPaymentLabel->setText(QString("$%1").arg(results.monthlyPayment, 0, 'f', 2));
    totalPaidLabel->setText(QString("$%1").arg(results.totalPaid, 0, 'f', 2));
    totalInterestLabel->setText(QString("$%1").arg(results.totalInterest, 0, 'f', 2));

    // Update comparison
    double interestSaved = 3789.66 - results.totalInterest;
    savingsLabel->setText(QString("Interest Saved: $%1\n($3,789.66 - $%2)")
        .arg(interestSaved, 0, 'f', 2)
        .arg(results.totalInterest, 0, 'f', 2));

    opportunityCostLabel->setText(QString("Opportunity Cost (2.5% for 5 years): -$%1")
        .arg(results.opportunityCost, 0, 'f', 2));

    netSavingsLabel->setText(QString("NET SAVINGS: $%1")
        .arg(results.netSavings, 0, 'f', 2));
}

void CarCalculator::exportToCSV() {
    QString fileName = QFileDialog::getSaveFileName(this,
        "Export to CSV", "car_calculator.csv", "CSV Files (*.csv)");

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not save file!");
        return;
    }

    QTextStream out(&file);

    // Write CSV content
    out << "Nissan Kick Payment Calculator Report\n";
    out << "Generated on," << QDate::currentDate().toString("yyyy-MM-dd") << "\n\n";

    out << "VEHICLE DETAILS\n";
    out << "Sales Price," << vehiclePriceInput->value() << "\n";
    out << "Trade-in," << tradeInInput->value() << "\n";
    out << "Net Price," << results.netPrice << "\n";
    out << "HST," << results.hstAmount << "\n";
    out << "Licence Fee," << licenceFeeInput->value() << "\n";
    out << "Total Purchase," << results.totalPurchase << "\n\n";

    out << "FINANCING - YOUR PLAN\n";
    out << "Down Payment," << downPaymentInput->value() << "\n";
    out << "Amount Financed," << results.amountFinanced << "\n";
    out << "Registration Fee," << registrationFeeInput->value() << "\n";
    out << "Total Loan," << results.totalLoan << "\n";
    out << "Annual Rate," << annualRateInput->value() << "%\n";
    out << "Loan Term," << monthsInput->value() << " months\n";
    out << "Monthly Payment," << results.monthlyPayment << "\n";
    out << "Total Paid," << results.totalPaid << "\n";
    out << "Total Interest," << results.totalInterest << "\n\n";

    out << "DEALERSHIP OFFER\n";
    out << "Bi-weekly Payment,165.04\n";
    out << "Total Interest,3789.66\n\n";

    out << "SAVINGS\n";
    out << "Interest Saved," << (3789.66 - results.totalInterest) << "\n";
    out << "Opportunity Cost," << results.opportunityCost << "\n";
    out << "Net Savings," << results.netSavings << "\n";

    file.close();
    QMessageBox::information(this, "Success", "File exported successfully!");
}


// ============================================================================
// FILE: main.cpp
// Qt Car Payment Calculator - Entry Point
// ============================================================================

//#include "CarCalculator.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    CarCalculator calculator;
    calculator.show();

    return app.exec();
}

#include "01_Qt_C++_Calculator.moc"


// ============================================================================
// FILE: CarCalculator.pro
// Qt Project File
// ============================================================================
/*
QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CarCalculator
TEMPLATE = app

SOURCES += main.cpp \
           CarCalculator.cpp

HEADERS += CarCalculator.h

# C++11 support
CONFIG += c++11

# Output directory
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
UI_DIR = build
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
