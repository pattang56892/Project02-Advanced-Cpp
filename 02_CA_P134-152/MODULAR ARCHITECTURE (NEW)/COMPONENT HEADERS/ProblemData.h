#ifndef PROBLEM_DATA_H
#define PROBLEM_DATA_H

#include <QString>
#include <QVector>

struct ProblemData {
    int number;
    QString title;
    QString description;
    QString tutorial;
    QString cppSolution;
    QString pythonSolution;
    QString jsSolution;
    QString example;

    ProblemData() : number(0) {}

    ProblemData(int num, const QString &t, const QString &desc, const QString &tut,
                const QString &cpp, const QString &py, const QString &js, const QString &ex)
        : number(num), title(t), description(desc), tutorial(tut),
          cppSolution(cpp), pythonSolution(py), jsSolution(js), example(ex) {}
};

class ProblemDataManager {
public:
    static QVector<ProblemData> loadAllProblems();
    static ProblemData createProblem134();
    static ProblemData createProblem135();
    static ProblemData createProblem136();
    static ProblemData createProblem137();
    static ProblemData createProblem138();
    static ProblemData createProblem139();
    static ProblemData createProblem140();
    static ProblemData createProblem141();
    static ProblemData createProblem142();
    static ProblemData createProblem143();
    static ProblemData createProblem144();
    static ProblemData createProblem145();
    static ProblemData createProblem146();
    static ProblemData createProblem147();
    static ProblemData createProblem148();
    static ProblemData createProblem149();
    static ProblemData createProblem150();
    static ProblemData createProblem151();
    static ProblemData createProblem152();
    static ProblemData createProblem153();
};

#endif // PROBLEM_DATA_H