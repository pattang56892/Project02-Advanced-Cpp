#include "CodeHighlighter.h"

CodeHighlighter::CodeHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    // Keyword format
    keywordFormat.setForeground(QColor(86, 156, 214)); // VS Code blue
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bclass\\b" << "\\bpublic\\b" << "\\bprivate\\b" << "\\bprotected\\b"
                    << "\\bif\\b" << "\\belse\\b" << "\\bfor\\b" << "\\bwhile\\b" << "\\bdo\\b"
                    << "\\breturn\\b" << "\\bint\\b" << "\\bvoid\\b" << "\\bbool\\b" << "\\bchar\\b"
                    << "\\bstring\\b" << "\\bconst\\b" << "\\bstatic\\b" << "\\bvirtual\\b"
                    << "\\bnamespace\\b" << "\\busing\\b" << "\\binclude\\b" << "\\bdefine\\b"
                    << "\\btypedef\\b" << "\\bstruct\\b" << "\\benum\\b" << "\\bunion\\b"
                    << "\\btemplate\\b" << "\\btypename\\b" << "\\boperator\\b" << "\\binline\\b"
                    << "\\bexplicit\\b" << "\\boverride\\b" << "\\bfinal\\b" << "\\bconstexpr\\b"
                    << "\\bauto\\b" << "\\bdecltype\\b" << "\\bnoexcept\\b";

    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    // Class format
    classFormat.setForeground(QColor(78, 201, 176)); // Teal
    classFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("\\b[A-Z][a-zA-Z0-9_]*\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    // Single line comment format
    singleLineCommentFormat.setForeground(QColor(106, 153, 85)); // Green
    rule.pattern = QRegularExpression("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    // Multi line comment format
    multiLineCommentFormat.setForeground(QColor(106, 153, 85)); // Green

    // Quotation format
    quotationFormat.setForeground(QColor(206, 145, 120)); // Orange
    rule.pattern = QRegularExpression("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    // Function format
    functionFormat.setForeground(QColor(220, 220, 170)); // Yellow
    functionFormat.setFontItalic(true);
    rule.pattern = QRegularExpression("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    // Number format
    numberFormat.setForeground(QColor(181, 206, 168)); // Light green
    rule.pattern = QRegularExpression("\\b[0-9]+\\b");
    rule.format = numberFormat;
    highlightingRules.append(rule);

    // Preprocessor format
    preprocessorFormat.setForeground(QColor(155, 155, 155)); // Gray
    preprocessorFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("#[a-zA-Z0-9_]+");
    rule.format = preprocessorFormat;
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

    // Multi-line comments
    setCurrentBlockState(0);

    QRegularExpression startExpression("/\\*");
    QRegularExpression endExpression("\\*/");

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(startExpression);

    while (startIndex >= 0) {
        QRegularExpressionMatch endMatch = endExpression.match(text, startIndex);
        int endIndex = endMatch.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex + endMatch.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(startExpression, startIndex + commentLength);
    }
}