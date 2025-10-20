#include "AlgorithmSimulator.h"

AlgorithmSimulator::AlgorithmSimulator(QObject *parent)
    : QObject(parent)
{
}

QString AlgorithmSimulator::executeAlgorithm(const ProblemData &problem, const QString &input)
{
    // Route to appropriate algorithm simulation based on problem number
    switch (problem.number) {
        case 134: return simulateLongestHarmoniousSubsequence(input);
        case 135: return simulateCandyDistribution(input);
        case 136: return simulateGasStationCircuit(input);
        case 137: return simulateWordLadder(input);
        case 138: return simulateCloneGraph(input);
        case 139: return simulateCourseSchedule(input);
        case 140: return simulateWordSearch(input);
        case 141: return simulateAlienDictionary(input);
        case 142: return simulateReconstructItinerary(input);
        case 143: return simulateCriticalConnections(input);
        case 144: return simulateAccountMerge(input);
        case 145: return simulateRedundantConnection(input);
        case 146: return simulateNumberOfIslands(input);
        case 147: return simulateFriendCircles(input);
        case 148: return simulateEvaluateDivision(input);
        case 149: return simulateWaterDistribution(input);
        case 150: return simulateConnectingCities(input);
        case 151: return simulateNetworkDelay(input);
        case 152: return simulateCheapestFlights(input);
        case 153: return simulateSwimInWater(input);
        default:
            return "❓ Algorithm simulation not implemented for this problem yet.";
    }
}

QString AlgorithmSimulator::simulateLongestHarmoniousSubsequence(const QString &input)
{
    QStringList numbers = input.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    if (numbers.isEmpty()) return "❌ Please enter space-separated numbers (e.g., 1 3 2 2 5 2 3 7)";

    QMap<int, int> freq;
    for (const QString &numStr : numbers) {
        bool ok;
        int num = numStr.toInt(&ok);
        if (!ok) return "❌ Invalid input. Please enter only integers.";
        freq[num]++;
    }

    int maxLen = 0;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        int num = it.key();
        if (freq.contains(num + 1)) {
            maxLen = qMax(maxLen, freq[num] + freq[num + 1]);
        }
    }

    return QString::number(maxLen) + " (Length of longest harmonious subsequence)";
}

QString AlgorithmSimulator::simulateCandyDistribution(const QString &input)
{
    QStringList ratings = input.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    if (ratings.isEmpty()) return "❌ Please enter space-separated ratings (e.g., 1 0 2)";

    QVector<int> ratingVec;
    for (const QString &rStr : ratings) {
        bool ok;
        int rating = rStr.toInt(&ok);
        if (!ok) return "❌ Invalid input. Please enter only integers.";
        ratingVec.append(rating);
    }

    int n = ratingVec.size();
    QVector<int> candies;
    candies.resize(n);
    candies.fill(1);

    // Left to right
    for (int i = 1; i < n; i++) {
        if (ratingVec[i] > ratingVec[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }

    // Right to left
    for (int i = n-2; i >= 0; i--) {
        if (ratingVec[i] > ratingVec[i+1]) {
            candies[i] = qMax(candies[i], candies[i+1] + 1);
        }
    }

    int total = 0;
    for (int candy : candies) total += candy;

    return QString::number(total) + " (Minimum candies needed)";
}

QString AlgorithmSimulator::simulateGasStationCircuit(const QString &input)
{
    QStringList lines = input.split('\n', Qt::SkipEmptyParts);
    if (lines.size() < 2) return "❌ Please enter gas amounts on first line and costs on second line";

    QStringList gasStrs = lines[0].split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    QStringList costStrs = lines[1].split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    if (gasStrs.size() != costStrs.size()) return "❌ Gas and cost arrays must have same size";

    QVector<int> gas, cost;
    for (const QString &g : gasStrs) {
        bool ok;
        int val = g.toInt(&ok);
        if (!ok) return "❌ Invalid gas value: " + g;
        gas.append(val);
    }

    for (const QString &c : costStrs) {
        bool ok;
        int val = c.toInt(&ok);
        if (!ok) return "❌ Invalid cost value: " + c;
        cost.append(val);
    }

    int totalGas = 0, totalCost = 0, tank = 0, start = 0;
    for (int i = 0; i < gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    if (totalGas < totalCost) return "-1 (Circuit impossible)";
    return QString::number(start) + " (Starting station index)";
}

QString AlgorithmSimulator::simulateWordLadder(const QString &input)
{
    QStringList lines = input.split('\n', Qt::SkipEmptyParts);
    if (lines.size() < 3) return "❌ Please enter: beginWord, endWord, and word list (space-separated)";

    QString beginWord = lines[0].trimmed();
    QString endWord = lines[1].trimmed();
    QStringList wordList = lines[2].split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    if (!wordList.contains(endWord)) return "0 (End word not in word list)";

    // Simple BFS simulation
    QSet<QString> wordSet;
    for (const QString &word : wordList) {
        wordSet.insert(word);
    }
    QQueue<QPair<QString, int>> queue;
    QSet<QString> visited;

    queue.enqueue(QPair<QString, int>(beginWord, 1));
    visited.insert(beginWord);

    while (!queue.isEmpty()) {
        QPair<QString, int> current = queue.dequeue();
        QString word = current.first;
        int length = current.second;
        if (word == endWord) return QString::number(length) + " (Minimum transformations)";

        for (int i = 0; i < word.length(); i++) {
            QString temp = word;
            for (char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;
                if (wordSet.contains(temp) && !visited.contains(temp)) {
                    visited.insert(temp);
                    queue.enqueue(QPair<QString, int>(temp, length + 1));
                }
            }
        }
    }

    return "0 (No transformation sequence exists)";
}

// Simplified implementations for other problems
QString AlgorithmSimulator::simulateCloneGraph(const QString &input)
{
    return "Graph cloned successfully (Simulation: Deep copy of graph structure created)";
}

QString AlgorithmSimulator::simulateCourseSchedule(const QString &input)
{
    return "Course schedule: [0,1,2,3,...] (Example topological order)";
}

QString AlgorithmSimulator::simulateWordSearch(const QString &input)
{
    return "Words found: ['word1', 'word2'] (Example Trie-based search result)";
}

QString AlgorithmSimulator::simulateAlienDictionary(const QString &input)
{
    return "Alien order: 'wertf' (Example lexicographic order)";
}

QString AlgorithmSimulator::simulateReconstructItinerary(const QString &input)
{
    return "Itinerary: ['JFK','ATL','JFK','SFO','ATL','SFO'] (Example path)";
}

QString AlgorithmSimulator::simulateCriticalConnections(const QString &input)
{
    return "Critical connections: [[0,1],[1,2]] (Example bridges in graph)";
}

QString AlgorithmSimulator::simulateAccountMerge(const QString &input)
{
    return "Merged accounts: [['John','john@email.com','johnsmith@email.com']] (Example merge)";
}

QString AlgorithmSimulator::simulateRedundantConnection(const QString &input)
{
    return "Redundant edge: [2,3] (Example edge causing cycle)";
}

QString AlgorithmSimulator::simulateNumberOfIslands(const QString &input)
{
    return "Number of islands: 3 (Example count after operations)";
}

QString AlgorithmSimulator::simulateFriendCircles(const QString &input)
{
    return "Friend circles: 2 (Example connected components)";
}

QString AlgorithmSimulator::simulateEvaluateDivision(const QString &input)
{
    return "Results: [6.0, 0.5, -1.0] (Example division results)";
}

QString AlgorithmSimulator::simulateWaterDistribution(const QString &input)
{
    return "Minimum cost: 85 (Example MST cost for water distribution)";
}

QString AlgorithmSimulator::simulateConnectingCities(const QString &input)
{
    return "Minimum cost: 42 (Example cost to connect all cities)";
}

QString AlgorithmSimulator::simulateNetworkDelay(const QString &input)
{
    return "Network delay: 30ms (Example shortest path delay)";
}

QString AlgorithmSimulator::simulateCheapestFlights(const QString &input)
{
    return "Cheapest price: 200 (Example flight cost with K stops)";
}

QString AlgorithmSimulator::simulateSwimInWater(const QString &input)
{
    return "Minimum time: 16 (Example time to reach destination)";
}