// 02_CA_P134-152_ENHANCED.cpp
// Enhanced Interactive Teaching Tool for Problems 134-153
// Now with LIVE execution, step-by-step visualization, and custom input!

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <tuple>
#include <cmath>
#include <numeric>
#include <stack>
#include <climits>
#include <sstream>
#include <functional>

using namespace std;

// ============================================================================
// UTILITY FUNCTIONS FOR INTERACTIVE FEATURES
// ============================================================================

// Clear input buffer
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Print section divider
void printDivider() {
    cout << "================================================================================\n";
}

// Print success message
void printSuccess(const string& msg) {
    cout << "\n[PASS] " << msg << "\n";
}

// Print error message
void printError(const string& msg) {
    cout << "\n[FAIL] " << msg << "\n";
}

// Print info message
void printInfo(const string& msg) {
    cout << "\n[i] " << msg << "\n";
}

// Parse comma-separated integers from string
vector<int> parseIntArray(const string& input) {
    vector<int> result;
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        // Remove whitespace
        token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end());
        if (!token.empty()) {
            try {
                result.push_back(stoi(token));
            } catch (...) {
                printError("Invalid number: " + token);
                return {};
            }
        }
    }
    return result;
}

// Print vector
template<typename T>
void printVector(const vector<T>& vec, const string& name = "Array") {
    cout << name << ": [";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

// Print map
template<typename K, typename V>
void printMap(const unordered_map<K, V>& m, const string& name = "Map") {
    cout << name << ": {";
    size_t count = 0;
    for (const auto& [key, val] : m) {
        cout << key << ": " << val;
        if (++count < m.size()) cout << ", ";
    }
    cout << "}\n";
}

// Wait for Enter key
void waitForEnter(const string& message = "Press Enter to continue...") {
    cout << "\n" << message;
    cin.get();
}

// Display interactive submenu
int displaySubmenu(const string& problemName) {
    printDivider();
    cout << "               " << problemName << " - INTERACTIVE MODE\n";
    printDivider();
    cout << "1. View Tutorial & Code Solutions (C++/Python/JavaScript)\n";
    cout << "2. Run Predefined Test Cases\n";
    cout << "3. Enter Custom Input\n";
    cout << "4. Step-by-Step Visualization\n";
    cout << "5. Back to Main Menu\n";
    printDivider();
    cout << "Enter your choice (1-5): ";

    int choice;
    if (!(cin >> choice) || choice < 1 || choice > 5) {
        clearInput();
        return -1;
    }
    clearInput();
    return choice;
}

// Forward declarations
void problem134(); void problem135(); void problem136(); void problem137(); void problem138();
void problem139(); void problem140(); void problem141(); void problem142(); void problem143();
void problem144(); void problem145(); void problem146(); void problem147(); void problem148();
void problem149(); void problem150(); void problem151(); void problem152(); void problem153();

// ============================================================================
// PROBLEM 134: LONGEST HARMONIOUS SUBSEQUENCE
// ============================================================================

// Actual working implementation
class Solution134 {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int maxLen = 0;
        for (const auto& [num, cnt] : count) {
            if (count.find(num + 1) != count.end()) {
                maxLen = max(maxLen, cnt + count[num + 1]);
            }
        }

        return maxLen;
    }

    // Step-by-step visualization
    int findLHS_Visualized(vector<int>& nums) {
        unordered_map<int, int> count;

        cout << "\nStep 1: Building frequency map...\n";
        for (int num : nums) {
            count[num]++;
            cout << "  Added " << num << " -> frequency now: " << count[num] << "\n";
        }

        cout << "\nStep 2: Final frequency map:\n";
        printMap(count, "  Frequencies");

        int maxLen = 0;
        cout << "\nStep 3: Finding harmonious subsequences (diff = 1)...\n";
        for (const auto& [num, cnt] : count) {
            if (count.find(num + 1) != count.end()) {
                int len = cnt + count[num + 1];
                cout << "  Found pair (" << num << ", " << num + 1 << "): ";
                cout << count[num] << " + " << count[num + 1] << " = " << len << "\n";
                if (len > maxLen) {
                    maxLen = len;
                    cout << "    -> New maximum!\n";
                }
            }
        }

        cout << "\nFinal result: " << maxLen << "\n";
        return maxLen;
    }
};

void problem134_viewTutorial() {
    printDivider();
    cout << "                 Problem 134: Longest Harmonious Subsequence\n";
    printDivider();
    cout << "Description: Find the length of the longest subsequence in an array where the difference\n";
    cout << "between the largest and smallest element is exactly 1. The subsequence doesn't need to be contiguous.\n\n";

    cout << "Tutorial:\n";
    cout << "1. A harmonious subsequence can only contain two numbers: x and x+1\n";
    cout << "2. We need to count the frequency of each number in the array\n";
    cout << "3. For each number x, check if x+1 exists in the array\n";
    cout << "4. The length of the harmonious subsequence is count(x) + count(x+1)\n";
    cout << "5. Track the maximum length found\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <unordered_map>\n#include <algorithm>\nusing namespace std;\n\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int findLHS(vector<int>& nums) {\n";
    cout << "        unordered_map<int, int> count;\n";
    cout << "        for (int num : nums) {\n";
    cout << "            count[num]++;\n";
    cout << "        }\n\n";
    cout << "        int maxLen = 0;\n";
    cout << "        for (const auto& [num, cnt] : count) {\n";
    cout << "            if (count.find(num + 1) != count.end()) {\n";
    cout << "                maxLen = max(maxLen, cnt + count[num + 1]);\n";
    cout << "            }\n";
    cout << "        }\n\n";
    cout << "        return maxLen;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "from collections import Counter\n\n";
    cout << "class Solution:\n";
    cout << "    def findLHS(self, nums):\n";
    cout << "        count = Counter(nums)\n";
    cout << "        max_len = 0\n";
    cout << "        for num in count:\n";
    cout << "            if num + 1 in count:\n";
    cout << "                max_len = max(max_len, count[num] + count[num + 1])\n";
    cout << "        return max_len\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var findLHS = function(nums) {\n";
    cout << "    const count = {};\n";
    cout << "    for (const num of nums) {\n";
    cout << "        count[num] = (count[num] || 0) + 1;\n";
    cout << "    }\n\n";
    cout << "    let maxLen = 0;\n";
    cout << "    for (const numStr in count) {\n";
    cout << "        const num = parseInt(numStr);\n";
    cout << "        if (count[num + 1]) {\n";
    cout << "            maxLen = Math.max(maxLen, count[num] + count[num + 1]);\n";
    cout << "        }\n";
    cout << "    }\n\n";
    cout << "    return maxLen;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: [1,3,2,2,5,2,3,7]\n";
    cout << "Output: 5 (subsequence [3,2,2,2,3])\n";
    cout << "Explanation: The longest subsequence with max-min=1 is [3,2,2,2,3]\n\n";
}

void problem134_runTests() {
    Solution134 sol;
    int passed = 0, total = 0;

    printInfo("Running predefined test cases...");

    // Test 1
    total++;
    vector<int> test1 = {1,3,2,2,5,2,3,7};
    int expected1 = 5;
    int result1 = sol.findLHS(test1);
    printVector(test1, "\nTest 1 Input");
    cout << "Expected: " << expected1 << ", Got: " << result1;
    if (result1 == expected1) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    // Test 2
    total++;
    vector<int> test2 = {1,2,3,4};
    int expected2 = 2;
    int result2 = sol.findLHS(test2);
    printVector(test2, "\nTest 2 Input");
    cout << "Expected: " << expected2 << ", Got: " << result2;
    if (result2 == expected2) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    // Test 3
    total++;
    vector<int> test3 = {1,1,1,1};
    int expected3 = 0;
    int result3 = sol.findLHS(test3);
    printVector(test3, "\nTest 3 Input");
    cout << "Expected: " << expected3 << ", Got: " << result3;
    if (result3 == expected3) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    cout << "\n";
    printDivider();
    cout << "Test Results: " << passed << "/" << total << " passed\n";
    printDivider();
}

void problem134_customInput() {
    Solution134 sol;

    cout << "\nEnter array elements (comma-separated, e.g., 1,3,2,2,5,2,3,7): ";
    string input;
    getline(cin, input);

    vector<int> nums = parseIntArray(input);
    if (nums.empty()) {
        printError("Invalid input!");
        return;
    }

    printVector(nums, "\nYour Input");
    int result = sol.findLHS(nums);
    cout << "\nResult: " << result << "\n";
}

void problem134_stepByStep() {
    Solution134 sol;

    vector<int> example = {1,3,2,2,5,2,3,7};
    printVector(example, "\nExample Input");
    cout << "\nExecuting with step-by-step visualization:\n";
    printDivider();

    sol.findLHS_Visualized(example);
}

void problem134() {
    while (true) {
        int choice = displaySubmenu("Problem 134: Longest Harmonious Subsequence");

        if (choice == -1) {
            printError("Invalid choice!");
            continue;
        }

        switch (choice) {
            case 1:
                problem134_viewTutorial();
                waitForEnter();
                break;
            case 2:
                problem134_runTests();
                waitForEnter();
                break;
            case 3:
                problem134_customInput();
                waitForEnter();
                break;
            case 4:
                problem134_stepByStep();
                waitForEnter();
                break;
            case 5:
                return;
        }
    }
}

// ============================================================================
// PROBLEM 135: REMOVE ELEMENT
// ============================================================================

class Solution135 {
public:
    int removeElement(vector<int>& nums, int val) {
        int writeIndex = 0;
        for (int readIndex = 0; readIndex < nums.size(); ++readIndex) {
            if (nums[readIndex] != val) {
                nums[writeIndex++] = nums[readIndex];
            }
        }
        return writeIndex;
    }

    int removeElement_Visualized(vector<int>& nums, int val) {
        cout << "\nInitial array: ";
        printVector(nums, "");
        cout << "Value to remove: " << val << "\n\n";

        cout << "Using two-pointer approach:\n";
        cout << "- readIndex: iterates through entire array\n";
        cout << "- writeIndex: tracks position for next valid element\n\n";

        int writeIndex = 0;
        cout << "Step-by-step execution:\n";
        printDivider();

        for (int readIndex = 0; readIndex < nums.size(); ++readIndex) {
            cout << "Read[" << readIndex << "] = " << nums[readIndex];
            if (nums[readIndex] != val) {
                nums[writeIndex] = nums[readIndex];
                cout << " -> Keep it! Write to position [" << writeIndex << "]\n";
                writeIndex++;
            } else {
                cout << " -> Skip (equals " << val << ")\n";
            }

            // Show current array state
            cout << "  Current: [";
            for (int i = 0; i < nums.size(); i++) {
                if (i == writeIndex && i <= readIndex) cout << "| ";
                cout << nums[i];
                if (i < nums.size() - 1) cout << ", ";
            }
            cout << "] (writeIndex=" << writeIndex << ")\n\n";
        }

        cout << "Final result: new length = " << writeIndex << "\n";
        cout << "Modified array (first " << writeIndex << " elements): [";
        for (int i = 0; i < writeIndex; i++) {
            cout << nums[i];
            if (i < writeIndex - 1) cout << ", ";
        }
        cout << "]\n";

        return writeIndex;
    }
};

void problem135_viewTutorial() {
    printDivider();
    cout << "                       Problem 135: Remove Element\n";
    printDivider();
    cout << "Description: Given an array of integers and a value, remove all occurrences of that value\n";
    cout << "in-place and return the new length of the array.\n\n";

    cout << "Tutorial:\n";
    cout << "1. Use two pointers: one to iterate through the array (read pointer)\n";
    cout << "2. Another to track the position where next valid element should be placed (write pointer)\n";
    cout << "3. When encountering the value to remove, skip it\n";
    cout << "4. When encountering a valid element, place it at the write pointer position\n";
    cout << "5. The write pointer's final position is the new length\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\nusing namespace std;\n\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int removeElement(vector<int>& nums, int val) {\n";
    cout << "        int writeIndex = 0;\n";
    cout << "        for (int readIndex = 0; readIndex < nums.size(); ++readIndex) {\n";
    cout << "            if (nums[readIndex] != val) {\n";
    cout << "                nums[writeIndex++] = nums[readIndex];\n";
    cout << "            }\n";
    cout << "        }\n";
    cout << "        return writeIndex;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "class Solution:\n";
    cout << "    def removeElement(self, nums, val):\n";
    cout << "        write_index = 0\n";
    cout << "        for read_index in range(len(nums)):\n";
    cout << "            if nums[read_index] != val:\n";
    cout << "                nums[write_index] = nums[read_index]\n";
    cout << "                write_index += 1\n";
    cout << "        return write_index\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var removeElement = function(nums, val) {\n";
    cout << "    let writeIndex = 0;\n";
    cout << "    for (let readIndex = 0; readIndex < nums.length; readIndex++) {\n";
    cout << "        if (nums[readIndex] !== val) {\n";
    cout << "            nums[writeIndex] = nums[readIndex];\n";
    cout << "            writeIndex++;\n";
    cout << "        }\n";
    cout << "    }\n";
    cout << "    return writeIndex;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: nums = [3,2,2,3], val = 3\n";
    cout << "Output: 2, nums = [2,2]\n";
    cout << "Explanation: Your function should return length = 2, with the first two elements of nums being 2.\n\n";
}

void problem135_runTests() {
    Solution135 sol;
    int passed = 0, total = 0;

    printInfo("Running predefined test cases...");

    // Test 1
    total++;
    vector<int> test1 = {3,2,2,3};
    vector<int> test1_copy = test1;
    int val1 = 3;
    int expected1 = 2;
    int result1 = sol.removeElement(test1, val1);
    printVector(test1_copy, "\nTest 1 Input");
    cout << "Value to remove: " << val1 << "\n";
    cout << "Expected length: " << expected1 << ", Got: " << result1;
    if (result1 == expected1) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    // Test 2
    total++;
    vector<int> test2 = {0,1,2,2,3,0,4,2};
    vector<int> test2_copy = test2;
    int val2 = 2;
    int expected2 = 5;
    int result2 = sol.removeElement(test2, val2);
    printVector(test2_copy, "\nTest 2 Input");
    cout << "Value to remove: " << val2 << "\n";
    cout << "Expected length: " << expected2 << ", Got: " << result2;
    if (result2 == expected2) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    // Test 3
    total++;
    vector<int> test3 = {1};
    vector<int> test3_copy = test3;
    int val3 = 1;
    int expected3 = 0;
    int result3 = sol.removeElement(test3, val3);
    printVector(test3_copy, "\nTest 3 Input");
    cout << "Value to remove: " << val3 << "\n";
    cout << "Expected length: " << expected3 << ", Got: " << result3;
    if (result3 == expected3) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    cout << "\n";
    printDivider();
    cout << "Test Results: " << passed << "/" << total << " passed\n";
    printDivider();
}

void problem135_customInput() {
    Solution135 sol;

    cout << "\nEnter array elements (comma-separated, e.g., 3,2,2,3): ";
    string input;
    getline(cin, input);

    vector<int> nums = parseIntArray(input);
    if (nums.empty()) {
        printError("Invalid input!");
        return;
    }

    cout << "Enter value to remove: ";
    int val;
    if (!(cin >> val)) {
        clearInput();
        printError("Invalid value!");
        return;
    }
    clearInput();

    printVector(nums, "\nYour Input");
    cout << "Value to remove: " << val << "\n";

    int result = sol.removeElement(nums, val);
    cout << "\nNew length: " << result << "\n";
    cout << "Modified array (first " << result << " elements): [";
    for (int i = 0; i < result; i++) {
        cout << nums[i];
        if (i < result - 1) cout << ", ";
    }
    cout << "]\n";
}

void problem135_stepByStep() {
    Solution135 sol;

    vector<int> example = {3,2,2,3};
    int val = 3;

    cout << "\nExecuting with step-by-step visualization:\n";
    printDivider();

    sol.removeElement_Visualized(example, val);
}

void problem135() {
    while (true) {
        int choice = displaySubmenu("Problem 135: Remove Element");

        if (choice == -1) {
            printError("Invalid choice!");
            continue;
        }

        switch (choice) {
            case 1:
                problem135_viewTutorial();
                waitForEnter();
                break;
            case 2:
                problem135_runTests();
                waitForEnter();
                break;
            case 3:
                problem135_customInput();
                waitForEnter();
                break;
            case 4:
                problem135_stepByStep();
                waitForEnter();
                break;
            case 5:
                return;
        }
    }
}

// ============================================================================
// PROBLEM 136: MINIMUM WEIGHTED SUBGRAPH WITH THE REQUIRED PATHS
// ============================================================================

class Solution136 {
public:
    typedef pair<long long, int> plli;

    vector<long long> dijkstra(vector<vector<plli>>& graph, int start, int n) {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<plli, vector<plli>, greater<plli>> pq;
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [w, v] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<plli>> adj(n), rev_adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({(long long)w, v});
            rev_adj[v].push_back({(long long)w, u});
        }

        vector<long long> d1 = dijkstra(adj, src1, n);
        vector<long long> d2 = dijkstra(adj, src2, n);
        vector<long long> d3 = dijkstra(rev_adj, dest, n);

        long long ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            if (d1[i] != LLONG_MAX && d2[i] != LLONG_MAX && d3[i] != LLONG_MAX) {
                ans = min(ans, d1[i] + d2[i] + d3[i]);
            }
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};

void problem136_viewTutorial() {
    printDivider();
    cout << "          Problem 136: Minimum Weighted Subgraph With the Required Paths\n";
    printDivider();
    cout << "Description: Find the minimum weight of a subgraph in a weighted directed graph that contains\n";
    cout << "paths from a source node to two required destination nodes.\n\n";

    cout << "Tutorial:\n";
    cout << "1. The minimal path consists of: src1 -> intermediate_node, src2 -> intermediate_node, and intermediate_node -> dest\n";
    cout << "2. We need to run Dijkstra's algorithm three times:\n";
    cout << "   a. From src1 on the original graph (d1)\n";
    cout << "   b. From src2 on the original graph (d2)\n";
    cout << "   c. From dest on the reversed graph (d3 - simulates all nodes -> dest)\n";
    cout << "3. The answer is min(d1[i] + d2[i] + d3[i]) for all intermediate nodes i.\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <queue>\n#include <climits>\n#include <algorithm>\nusing namespace std;\n\n";
    cout << "typedef pair<long long, int> plli;\n\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {\n";
    cout << "        vector<vector<plli>> adj(n), rev_adj(n);\n";
    cout << "        for (auto& e : edges) {\n";
    cout << "            int u = e[0], v = e[1], w = e[2];\n";
    cout << "            adj[u].push_back({(long long)w, v});\n";
    cout << "            rev_adj[v].push_back({(long long)w, u});\n";
    cout << "        }\n\n";
    cout << "        auto dijkstra = [&](vector<vector<plli>>& graph, int start) -> vector<long long> {\n";
    cout << "            vector<long long> dist(n, LLONG_MAX);\n";
    cout << "            priority_queue<plli, vector<plli>, greater<plli>> pq;\n";
    cout << "            dist[start] = 0;\n";
    cout << "            pq.push({0, start});\n\n";
    cout << "            while (!pq.empty()) {\n";
    cout << "                auto [d, u] = pq.top(); pq.pop();\n";
    cout << "                if (d > dist[u]) continue;\n";
    cout << "                for (auto [w, v] : graph[u]) {\n";
    cout << "                    if (dist[u] + w < dist[v]) {\n";
    cout << "                        dist[v] = dist[u] + w;\n";
    cout << "                        pq.push({dist[v], v});\n";
    cout << "                    }\n";
    cout << "                }\n";
    cout << "            }\n";
    cout << "            return dist;\n";
    cout << "        };\n\n";
    cout << "        vector<long long> d1 = dijkstra(adj, src1);\n";
    cout << "        vector<long long> d2 = dijkstra(adj, src2);\n";
    cout << "        vector<long long> d3 = dijkstra(rev_adj, dest);\n\n";
    cout << "        long long ans = LLONG_MAX;\n";
    cout << "        for (int i = 0; i < n; ++i) {\n";
    cout << "            if (d1[i] != LLONG_MAX && d2[i] != LLONG_MAX && d3[i] != LLONG_MAX) {\n";
    cout << "                ans = min(ans, d1[i] + d2[i] + d3[i]);\n";
    cout << "            }\n";
    cout << "        }\n\n";
    cout << "        return ans == LLONG_MAX ? -1 : ans;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5\n";
    cout << "Output: 9\n\n";
}

void problem136_runTests() {
    Solution136 sol;
    int passed = 0, total = 0;

    printInfo("Running predefined test cases...");

    // Test 1
    total++;
    int n1 = 6;
    vector<vector<int>> edges1 = {{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}};
    int src1_1 = 0, src2_1 = 1, dest1 = 5;
    long long expected1 = 9;
    long long result1 = sol.minimumWeight(n1, edges1, src1_1, src2_1, dest1);

    cout << "\nTest 1: n=" << n1 << ", edges count=" << edges1.size();
    cout << ", src1=" << src1_1 << ", src2=" << src2_1 << ", dest=" << dest1 << "\n";
    cout << "Expected: " << expected1 << ", Got: " << result1;
    if (result1 == expected1) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    // Test 2
    total++;
    int n2 = 3;
    vector<vector<int>> edges2 = {{0,1,1},{2,1,1}};
    int src1_2 = 0, src2_2 = 1, dest2 = 2;
    long long expected2 = -1;
    long long result2 = sol.minimumWeight(n2, edges2, src1_2, src2_2, dest2);

    cout << "\nTest 2: n=" << n2 << ", edges count=" << edges2.size();
    cout << ", src1=" << src1_2 << ", src2=" << src2_2 << ", dest=" << dest2 << "\n";
    cout << "Expected: " << expected2 << ", Got: " << result2;
    if (result2 == expected2) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    cout << "\n";
    printDivider();
    cout << "Test Results: " << passed << "/" << total << " passed\n";
    printDivider();
}

void problem136_customInput() {
    printInfo("This problem requires complex graph input.");
    printInfo("Using simplified input mode...\n");

    Solution136 sol;

    cout << "Enter number of nodes: ";
    int n;
    if (!(cin >> n) || n < 1) {
        clearInput();
        printError("Invalid input!");
        return;
    }

    cout << "Enter src1: ";
    int src1;
    if (!(cin >> src1) || src1 < 0 || src1 >= n) {
        clearInput();
        printError("Invalid src1!");
        return;
    }

    cout << "Enter src2: ";
    int src2;
    if (!(cin >> src2) || src2 < 0 || src2 >= n) {
        clearInput();
        printError("Invalid src2!");
        return;
    }

    cout << "Enter dest: ";
    int dest;
    if (!(cin >> dest) || dest < 0 || dest >= n) {
        clearInput();
        printError("Invalid dest!");
        return;
    }

    cout << "Enter number of edges: ";
    int m;
    if (!(cin >> m) || m < 0) {
        clearInput();
        printError("Invalid edge count!");
        return;
    }

    clearInput();

    vector<vector<int>> edges;
    cout << "Enter edges as 'u v weight' (one per line):\n";
    for (int i = 0; i < m; i++) {
        cout << "Edge " << i + 1 << ": ";
        int u, v, w;
        if (!(cin >> u >> v >> w)) {
            clearInput();
            printError("Invalid edge!");
            return;
        }
        edges.push_back({u, v, w});
    }
    clearInput();

    long long result = sol.minimumWeight(n, edges, src1, src2, dest);
    cout << "\nResult: " << result << "\n";
    if (result == -1) {
        cout << "No valid path exists!\n";
    }
}

void problem136_stepByStep() {
    printInfo("Step-by-step visualization for graph algorithms is complex.");
    printInfo("Showing execution trace for a simple example...\n");

    Solution136 sol;

    int n = 4;
    vector<vector<int>> edges = {{0,1,1},{1,2,1},{2,3,1},{0,3,4}};
    int src1 = 0, src2 = 1, dest = 3;

    cout << "Graph: " << n << " nodes\n";
    cout << "Edges: ";
    for (auto& e : edges) {
        cout << "(" << e[0] << "->" << e[1] << ", w=" << e[2] << ") ";
    }
    cout << "\nSrc1: " << src1 << ", Src2: " << src2 << ", Dest: " << dest << "\n\n";

    cout << "Algorithm will:\n";
    cout << "1. Run Dijkstra from src1=" << src1 << " (find shortest paths to all nodes)\n";
    cout << "2. Run Dijkstra from src2=" << src2 << " (find shortest paths to all nodes)\n";
    cout << "3. Run Dijkstra from dest=" << dest << " on reversed graph\n";
    cout << "4. Find minimum: d1[i] + d2[i] + d3[i] for all nodes i\n\n";

    long long result = sol.minimumWeight(n, edges, src1, src2, dest);
    cout << "Final Result: " << result << "\n";
}

void problem136() {
    while (true) {
        int choice = displaySubmenu("Problem 136: Minimum Weighted Subgraph");

        if (choice == -1) {
            printError("Invalid choice!");
            continue;
        }

        switch (choice) {
            case 1:
                problem136_viewTutorial();
                waitForEnter();
                break;
            case 2:
                problem136_runTests();
                waitForEnter();
                break;
            case 3:
                problem136_customInput();
                waitForEnter();
                break;
            case 4:
                problem136_stepByStep();
                waitForEnter();
                break;
            case 5:
                return;
        }
    }
}

// ============================================================================
// PROBLEM 137: PARTITION ARRAY INTO TWO ARRAYS TO MINIMIZE SUM DIFFERENCE
// ============================================================================

class Solution137 {
public:
    int minimumDifference(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        for (int i = target; i >= 0; --i) {
            if (dp[i]) {
                return total - 2 * i;
            }
        }

        return total;
    }

    int minimumDifference_Visualized(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total / 2;

        cout << "\nInput array: ";
        printVector(nums, "");
        cout << "Total sum: " << total << "\n";
        cout << "Target (half): " << target << "\n\n";

        cout << "Using Dynamic Programming to find achievable sums:\n";
        printDivider();

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        cout << "Initial: dp[0] = true (can achieve sum 0 with empty set)\n\n";

        for (int num : nums) {
            cout << "Processing number: " << num << "\n";
            int count = 0;
            for (int j = target; j >= num; --j) {
                if (!dp[j] && dp[j - num]) {
                    dp[j] = true;
                    count++;
                }
            }
            cout << "  -> " << count << " new sums became achievable\n";

            // Show first few achievable sums
            cout << "  Current achievable sums (sample): ";
            int shown = 0;
            for (int i = 0; i <= target && shown < 10; i++) {
                if (dp[i]) {
                    cout << i << " ";
                    shown++;
                }
            }
            if (shown == 10) cout << "...";
            cout << "\n\n";
        }

        cout << "Finding largest achievable sum <= " << target << ":\n";
        for (int i = target; i >= 0; --i) {
            if (dp[i]) {
                int other = total - i;
                cout << "Found: subset1_sum = " << i << ", subset2_sum = " << other << "\n";
                cout << "Difference: |" << i << " - " << other << "| = " << (total - 2 * i) << "\n";
                return total - 2 * i;
            }
        }

        return total;
    }
};

void problem137_viewTutorial() {
    printDivider();
    cout << "        Problem 137: Partition Array Into Two Arrays to Minimize Sum Difference\n";
    printDivider();
    cout << "Description: Divide an array into two subarrays such that the absolute difference between\n";
    cout << "their sums is minimized. Find the best possible split to make the subarray sums as close as possible.\n\n";

    cout << "Tutorial:\n";
    cout << "1. This is a variation of the subset sum problem\n";
    cout << "2. We want to partition the array into two subsets with sums as close as possible\n";
    cout << "3. The optimal solution will have sum1 approx total_sum/2\n";
    cout << "4. We use dynamic programming (DP) to find all possible subset sums up to total_sum/2\n";
    cout << "5. The best solution is the largest subset sum <= total_sum/2\n";
    cout << "6. The minimum difference is |total_sum - 2 * best_sum|\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <numeric>\n#include <algorithm>\nusing namespace std;\n\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int minimumDifference(vector<int>& nums) {\n";
    cout << "        int total = accumulate(nums.begin(), nums.end(), 0);\n";
    cout << "        int target = total / 2;\n";
    cout << "        vector<bool> dp(target + 1, false);\n";
    cout << "        dp[0] = true;\n\n";
    cout << "        for (int num : nums) {\n";
    cout << "            for (int j = target; j >= num; --j) {\n";
    cout << "                dp[j] = dp[j] || dp[j - num];\n";
    cout << "            }\n";
    cout << "        }\n\n";
    cout << "        for (int i = target; i >= 0; --i) {\n";
    cout << "            if (dp[i]) {\n";
    cout << "                return total - 2 * i;\n";
    cout << "            }\n";
    cout << "        }\n\n";
    cout << "        return total;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: [3,9,7,3]\n";
    cout << "Output: 2\n";
    cout << "Explanation: One optimal partition is [3,9] and [7,3] with sums 12 and 10, difference 2.\n\n";
}

void problem137_runTests() {
    Solution137 sol;
    int passed = 0, total = 0;

    printInfo("Running predefined test cases...");

    // Test 1
    total++;
    vector<int> test1 = {3,9,7,3};
    int expected1 = 2;
    int result1 = sol.minimumDifference(test1);
    printVector(test1, "\nTest 1 Input");
    cout << "Expected: " << expected1 << ", Got: " << result1;
    if (result1 == expected1) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    // Test 2
    total++;
    vector<int> test2 = {1,2,3,4};
    int expected2 = 0;
    int result2 = sol.minimumDifference(test2);
    printVector(test2, "\nTest 2 Input");
    cout << "Expected: " << expected2 << ", Got: " << result2;
    if (result2 == expected2) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    // Test 3
    total++;
    vector<int> test3 = {1,6,11,5};
    int expected3 = 1;
    int result3 = sol.minimumDifference(test3);
    printVector(test3, "\nTest 3 Input");
    cout << "Expected: " << expected3 << ", Got: " << result3;
    if (result3 == expected3) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    cout << "\n";
    printDivider();
    cout << "Test Results: " << passed << "/" << total << " passed\n";
    printDivider();
}

void problem137_customInput() {
    Solution137 sol;

    cout << "\nEnter array elements (comma-separated, e.g., 3,9,7,3): ";
    string input;
    getline(cin, input);

    vector<int> nums = parseIntArray(input);
    if (nums.empty()) {
        printError("Invalid input!");
        return;
    }

    printVector(nums, "\nYour Input");
    int result = sol.minimumDifference(nums);
    cout << "\nMinimum difference: " << result << "\n";
}

void problem137_stepByStep() {
    Solution137 sol;

    vector<int> example = {3,9,7,3};
    printVector(example, "\nExample Input");
    cout << "\nExecuting with step-by-step visualization:\n";
    printDivider();

    sol.minimumDifference_Visualized(example);
}

void problem137() {
    while (true) {
        int choice = displaySubmenu("Problem 137: Partition Array");

        if (choice == -1) {
            printError("Invalid choice!");
            continue;
        }

        switch (choice) {
            case 1:
                problem137_viewTutorial();
                waitForEnter();
                break;
            case 2:
                problem137_runTests();
                waitForEnter();
                break;
            case 3:
                problem137_customInput();
                waitForEnter();
                break;
            case 4:
                problem137_stepByStep();
                waitForEnter();
                break;
            case 5:
                return;
        }
    }
}

// ============================================================================
// PROBLEM 138: MINIMUM COST TO CUT A STICK
// ============================================================================

class Solution138 {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> c = cuts;
        c.insert(c.begin(), 0);
        c.push_back(n);
        sort(c.begin(), c.end());

        int m = c.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; ++len) {
            for (int i = 0; i + len < m; ++i) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + c[j] - c[i]);
                }
            }
        }

        return dp[0][m - 1];
    }

    int minCost_Visualized(int n, vector<int>& cuts) {
        vector<int> c = cuts;
        c.insert(c.begin(), 0);
        c.push_back(n);
        sort(c.begin(), c.end());

        cout << "\nStick length: " << n << "\n";
        cout << "Cut positions: ";
        printVector(cuts, "");
        cout << "After adding endpoints and sorting: ";
        printVector(c, "");
        cout << "\n";

        int m = c.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        cout << "Dynamic Programming approach (Interval DP):\n";
        cout << "dp[i][j] = minimum cost to make all cuts between c[i] and c[j]\n\n";

        printDivider();

        for (int len = 2; len < m; ++len) {
            cout << "Processing intervals of length " << len << ":\n";
            for (int i = 0; i + len < m; ++i) {
                int j = i + len;
                dp[i][j] = INT_MAX;

                cout << "  Interval [" << c[i] << ", " << c[j] << "] (indices " << i << " to " << j << "):\n";
                cout << "    Stick length: " << (c[j] - c[i]) << "\n";

                for (int k = i + 1; k < j; ++k) {
                    int cost = dp[i][k] + dp[k][j] + c[j] - c[i];
                    cout << "    Cut at position " << c[k] << ": ";
                    cout << dp[i][k] << " + " << dp[k][j] << " + " << (c[j] - c[i]);
                    cout << " = " << cost;

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        cout << " <- Best!";
                    }
                    cout << "\n";
                }
                cout << "    Final dp[" << i << "][" << j << "] = " << dp[i][j] << "\n\n";
            }
        }

        cout << "Result: " << dp[0][m - 1] << "\n";
        return dp[0][m - 1];
    }
};

void problem138_viewTutorial() {
    printDivider();
    cout << "                  Problem 138: Minimum Cost to Cut a Stick\n";
    printDivider();
    cout << "Description: You're given a stick of length n and an array of cuts. Determine the minimum\n";
    cout << "cost to cut the stick into segments based on the given cut locations.\n\n";

    cout << "Tutorial:\n";
    cout << "1. This is a Dynamic Programming problem (Interval DP)\n";
    cout << "2. Add 0 and n to the cuts array to represent the stick ends, then sort.\n";
    cout << "3. dp[i][j] = minimum cost to cut the segment between cuts[i] and cuts[j].\n";
    cout << "4. The cost of a cut is the length of the segment being cut: (cuts[j] - cuts[i]).\n";
    cout << "5. Recurrence: dp[i][j] = min(dp[i][k] + dp[k][j]) + (cuts[j] - cuts[i]) for all k between i and j.\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <algorithm>\n#include <climits>\nusing namespace std;\n\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int minCost(int n, vector<int>& cuts) {\n";
    cout << "        cuts.insert(cuts.begin(), 0);\n";
    cout << "        cuts.push_back(n);\n";
    cout << "        sort(cuts.begin(), cuts.end());\n\n";
    cout << "        int m = cuts.size();\n";
    cout << "        vector<vector<int>> dp(m, vector<int>(m, 0));\n\n";
    cout << "        for (int len = 2; len < m; ++len) {\n";
    cout << "            for (int i = 0; i + len < m; ++i) {\n";
    cout << "                int j = i + len;\n";
    cout << "                dp[i][j] = INT_MAX;\n";
    cout << "                for (int k = i + 1; k < j; ++k) {\n";
    cout << "                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);\n";
    cout << "                }\n";
    cout << "            }\n";
    cout << "        }\n\n";
    cout << "        return dp[0][m - 1];\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: n = 7, cuts = [1,3,4,5]\n";
    cout << "Output: 16\n";
    cout << "Explanation: Using cuts 1,3,4,5 with costs 6+4+3+3 = 16\n\n";
}

void problem138_runTests() {
    Solution138 sol;
    int passed = 0, total = 0;

    printInfo("Running predefined test cases...");

    // Test 1
    total++;
    int n1 = 7;
    vector<int> cuts1 = {1,3,4,5};
    int expected1 = 16;
    int result1 = sol.minCost(n1, cuts1);
    cout << "\nTest 1: n=" << n1 << ", cuts=";
    printVector(cuts1, "");
    cout << "Expected: " << expected1 << ", Got: " << result1;
    if (result1 == expected1) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    // Test 2
    total++;
    int n2 = 9;
    vector<int> cuts2 = {5,6,1,4,2};
    int expected2 = 22;
    int result2 = sol.minCost(n2, cuts2);
    cout << "\nTest 2: n=" << n2 << ", cuts=";
    printVector(cuts2, "");
    cout << "Expected: " << expected2 << ", Got: " << result2;
    if (result2 == expected2) {
        printSuccess("PASSED");
        passed++;
    } else {
        printError("FAILED");
    }

    cout << "\n";
    printDivider();
    cout << "Test Results: " << passed << "/" << total << " passed\n";
    printDivider();
}

void problem138_customInput() {
    Solution138 sol;

    cout << "\nEnter stick length (n): ";
    int n;
    if (!(cin >> n) || n < 1) {
        clearInput();
        printError("Invalid length!");
        return;
    }
    clearInput();

    cout << "Enter cut positions (comma-separated, e.g., 1,3,4,5): ";
    string input;
    getline(cin, input);

    vector<int> cuts = parseIntArray(input);
    if (cuts.empty()) {
        printError("Invalid input!");
        return;
    }

    cout << "\nStick length: " << n << "\n";
    printVector(cuts, "Cuts");

    int result = sol.minCost(n, cuts);
    cout << "\nMinimum cost: " << result << "\n";
}

void problem138_stepByStep() {
    Solution138 sol;

    int n = 7;
    vector<int> cuts = {1,3,4,5};

    cout << "\nExecuting with step-by-step visualization:\n";
    printDivider();

    sol.minCost_Visualized(n, cuts);
}

void problem138() {
    while (true) {
        int choice = displaySubmenu("Problem 138: Minimum Cost to Cut a Stick");

        if (choice == -1) {
            printError("Invalid choice!");
            continue;
        }

        switch (choice) {
            case 1:
                problem138_viewTutorial();
                waitForEnter();
                break;
            case 2:
                problem138_runTests();
                waitForEnter();
                break;
            case 3:
                problem138_customInput();
                waitForEnter();
                break;
            case 4:
                problem138_stepByStep();
                waitForEnter();
                break;
            case 5:
                return;
        }
    }
}

// ============================================================================
// PLACEHOLDER PROBLEMS 139-153 (Keep original non-interactive versions)
// ============================================================================

void problem139() {
    cout << "\n[PLACEHOLDER] Problem 139: Maximum Candies You Can Get from Boxes\n";
    cout << "This problem will be enhanced in the next iteration.\n";
    cout << "Press Enter to continue...";
}

void problem140() { cout << "\n[PLACEHOLDER] Problem 140\n"; }
void problem141() { cout << "\n[PLACEHOLDER] Problem 141\n"; }
void problem142() { cout << "\n[PLACEHOLDER] Problem 142\n"; }
void problem143() { cout << "\n[PLACEHOLDER] Problem 143\n"; }
void problem144() { cout << "\n[PLACEHOLDER] Problem 144\n"; }
void problem145() { cout << "\n[PLACEHOLDER] Problem 145\n"; }
void problem146() { cout << "\n[PLACEHOLDER] Problem 146\n"; }
void problem147() { cout << "\n[PLACEHOLDER] Problem 147\n"; }
void problem148() { cout << "\n[PLACEHOLDER] Problem 148\n"; }
void problem149() { cout << "\n[PLACEHOLDER] Problem 149\n"; }
void problem150() { cout << "\n[PLACEHOLDER] Problem 150\n"; }
void problem151() { cout << "\n[PLACEHOLDER] Problem 151\n"; }
void problem152() { cout << "\n[PLACEHOLDER] Problem 152\n"; }
void problem153() { cout << "\n[PLACEHOLDER] Problem 153\n"; }

// ============================================================================
// MAIN MENU AND PROGRAM STRUCTURE
// ============================================================================

void printHeader() {
    cout << "\n";
    printDivider();
    cout << "                    ENHANCED ALGORITHM LEARNING PLATFORM\n";
    cout << "                  Problems 134-153: Advanced Algorithms\n";
    cout << "                           INTERACTIVE EDITION\n";
    printDivider();
    cout << "NEW FEATURES:\n";
    cout << "  - Live code execution with predefined test cases\n";
    cout << "  - Custom input mode for testing your own data\n";
    cout << "  - Step-by-step algorithm visualization\n";
    cout << "  - Multi-language code examples (C++, Python, JavaScript)\n\n";
    cout << "Currently enhanced: Problems 134-138\n";
    cout << "Coming soon: Problems 139-153\n";
    printDivider();
}

void displayMainMenu() {
    cout << "\n";
    printDivider();
    cout << "                              MAIN MENU\n";
    printDivider();
    cout << "ENHANCED (Interactive):\n";
    cout << "1.  134. Longest Harmonious Subsequence\n";
    cout << "2.  135. Remove Element\n";
    cout << "3.  136. Minimum Weighted Subgraph With the Required Paths\n";
    cout << "4.  137. Partition Array Into Two Arrays to Minimize Sum Difference\n";
    cout << "5.  138. Minimum Cost to Cut a Stick\n\n";
    cout << "COMING SOON:\n";
    cout << "6.  139. Maximum Candies You Can Get from Boxes\n";
    cout << "7.  140. Sum of Subarray Minimums\n";
    cout << "8.  141. Longest Duplicate Substring\n";
    cout << "9.  142. Max Consecutive Ones III\n";
    cout << "10. 143. Power of Two\n";
    cout << "11. 144. Longest Palindrome by Concatenating Two Letter Words\n";
    cout << "12. 145. Snapshot Array\n";
    cout << "13. 146. Shortest Path in a Grid with Obstacles Elimination\n";
    cout << "14. 147. Sqrt(x)\n";
    cout << "15. 148. Min Stack\n";
    cout << "16. 149. Reverse Integer\n";
    cout << "17. 150. Implement Queue using Stacks\n";
    cout << "18. 151. Meeting Rooms III\n";
    cout << "19. 152. Path With Maximum Minimum Value\n";
    cout << "20. 153. Multiply Strings\n";
    cout << "0.  Exit\n";
    printDivider();
    cout << "Enter your choice (0-20): ";
}

void (*problemFunctions[])() = {
    nullptr,
    problem134, problem135, problem136, problem137, problem138,
    problem139, problem140, problem141, problem142, problem143,
    problem144, problem145, problem146, problem147, problem148,
    problem149, problem150, problem151, problem152, problem153
};

int main() {
    printHeader();

    int choice;
    do {
        displayMainMenu();

        if (!(cin >> choice) || choice < 0 || choice > 20) {
            cout << "\nInvalid input! Please enter a number between 0 and 20.\n";
            clearInput();
            continue;
        }
        clearInput();

        if (choice == 0) {
            cout << "\nThank you for using the Enhanced Algorithm Learning Platform!\n";
            cout << "Happy coding and keep learning!\n";
            printDivider();
            break;
        }

        problemFunctions[choice]();

        if (choice >= 6 && choice <= 20) {
            waitForEnter();
        }

    } while (true);

    return 0;
}
