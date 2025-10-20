#ifndef ALGORITHM_SIMULATOR_H
#define ALGORITHM_SIMULATOR_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include <QMap>
#include <QVector>
#include <QSet>
#include <QQueue>
#include <QPair>
#include "ProblemData.h"

class AlgorithmSimulator : public QObject {
    Q_OBJECT

public:
    explicit AlgorithmSimulator(QObject *parent = nullptr);

    QString executeAlgorithm(const ProblemData &problem, const QString &input);

private:
    // Algorithm simulation methods for each problem
    QString simulateLongestHarmoniousSubsequence(const QString &input);
    QString simulateCandyDistribution(const QString &input);
    QString simulateGasStationCircuit(const QString &input);
    QString simulateWordLadder(const QString &input);
    QString simulateCloneGraph(const QString &input);
    QString simulateCourseSchedule(const QString &input);
    QString simulateWordSearch(const QString &input);
    QString simulateAlienDictionary(const QString &input);
    QString simulateReconstructItinerary(const QString &input);
    QString simulateCriticalConnections(const QString &input);
    QString simulateAccountMerge(const QString &input);
    QString simulateRedundantConnection(const QString &input);
    QString simulateNumberOfIslands(const QString &input);
    QString simulateFriendCircles(const QString &input);
    QString simulateEvaluateDivision(const QString &input);
    QString simulateWaterDistribution(const QString &input);
    QString simulateConnectingCities(const QString &input);
    QString simulateNetworkDelay(const QString &input);
    QString simulateCheapestFlights(const QString &input);
    QString simulateSwimInWater(const QString &input);
};

#endif // ALGORITHM_SIMULATOR_H