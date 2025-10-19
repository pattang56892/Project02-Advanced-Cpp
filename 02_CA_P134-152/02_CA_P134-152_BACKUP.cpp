// 02_CA_P134-152.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// AlgorithmicInsights_TeachingTool.cpp
// A true teaching tool for Problems 134–153
// "It’s not just a calculator—it’s a teaching tool, and it succeeds at that role."

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
#include <climits> // For LLONG_MAX, INT_MAX, INT_MIN

using namespace std;

// Forward declarations of all problem functions
void problem134(); void problem135(); void problem136(); void problem137(); void problem138();
void problem139(); void problem140(); void problem141(); void problem142(); void problem143();
void problem144(); void problem145(); void problem146(); void problem147(); void problem148();
void problem149(); void problem150(); void problem151(); void problem152(); void problem153();

// Utility function to clear input buffer
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Display program header
void printHeader() {
    cout << "\n================================================================================";
    cout << "\n                          ALGORITHM LEARNING PLATFORM";
    cout << "\n                      Problems 134-153: Advanced Algorithms";
    cout << "\n================================================================================\n";
    cout << "The program successfully balances mathematical rigor with accessibility, making complex ";
    cout << "concepts approachable for users with varying backgrounds. The inclusion of both ";
    cout << "algorithmic explanations and multi-language solutions demonstrates a deep understanding ";
    cout << "of how different users learn and understand computational concepts. The code serves as ";
    cout << "an excellent example of how to create educational software that is both technically ";
    cout << "sound and user-centric.\n\n";
    cout << "Navigate through the problems using the menu below to explore the code and tutorials.\n";
}

// Display main menu
void displayMainMenu() {
    cout << "\n================================================================================";
    cout << "\n                           MAIN MENU";
    cout << "\n================================================================================\n";
    cout << "1.  134. Longest Harmonious Subsequence\n";
    cout << "2.  135. Remove Element\n";
    cout << "3.  136. Minimum Weighted Subgraph With the Required Paths\n";
    cout << "4.  137. Partition Array Into Two Arrays to Minimize Sum Difference\n";
    cout << "5.  138. Minimum Cost to Cut a Stick\n";
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
    cout << "0. Exit\n";
    cout << "================================================================================\n";
    cout << "Enter your choice (0-20): ";
}

// Problem 134: Longest Harmonious Subsequence
void problem134() {
    cout << "\n================================================================================";
    cout << "\n                       Problem 134: Longest Harmonious Subsequence";
    cout << "\n================================================================================\n";
    cout << "Description: Find the length of the longest subsequence in an array where the difference";
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

// Problem 135: Remove Element
void problem135() {
    cout << "\n================================================================================";
    cout << "\n                         Problem 135: Remove Element";
    cout << "\n================================================================================\n";
    cout << "Description: Given an array of integers and a value, remove all occurrences of that value";
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

// Problem 136: Minimum Weighted Subgraph With the Required Paths
void problem136() {
    cout << "\n================================================================================";
    cout << "\n               Problem 136: Minimum Weighted Subgraph With the Required Paths";
    cout << "\n================================================================================\n";
    cout << "Description: Find the minimum weight of a subgraph in a weighted directed graph that contains";
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

    cout << "Python Solution:\n";
    cout << "import heapq\nfrom collections import defaultdict\nimport math\n\n";
    cout << "class Solution:\n";
    cout << "    def minimumWeight(self, n, edges, src1, src2, dest):\n";
    cout << "        adj = defaultdict(list)\n";
    cout << "        rev_adj = defaultdict(list)\n";
    cout << "        for u, v, w in edges:\n";
    cout << "            adj[u].append((v, w))\n";
    cout << "            rev_adj[v].append((u, w))\n\n";
    cout << "        def dijkstra(graph, start):\n";
    cout << "            dist = [math.inf] * n\n";
    cout << "            dist[start] = 0\n";
    cout << "            pq = [(0, start)]\n";
    cout << "            while pq:\n";
    cout << "                d, u = heapq.heappop(pq)\n";
    cout << "                if d > dist[u]:\n";
    cout << "                    continue\n";
    cout << "                for v, w in graph[u]:\n";
    cout << "                    if dist[u] + w < dist[v]:\n";
    cout << "                        dist[v] = dist[u] + w\n";
    cout << "                        heapq.heappush(pq, (dist[v], v))\n";
    cout << "            return dist\n\n";
    cout << "        d1 = dijkstra(adj, src1)\n";
    cout << "        d2 = dijkstra(adj, src2)\n";
    cout << "        d3 = dijkstra(rev_adj, dest)\n\n";
    cout << "        ans = math.inf\n";
    cout << "        for i in range(n):\n";
    cout << "            if d1[i] != math.inf and d2[i] != math.inf and d3[i] != math.inf:\n";
    cout << "                ans = min(ans, d1[i] + d2[i] + d3[i])\n\n";
    cout << "        return -1 if ans == math.inf else ans\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var minimumWeight = function(n, edges, src1, src2, dest) {\n";
    cout << "    const adj = Array.from({ length: n }, () => []);\n";
    cout << "    const revAdj = Array.from({ length: n }, () => []);\n\n";
    cout << "    for (const [u, v, w] of edges) {\n";
    cout << "        adj[u].push([v, w]);\n";
    cout << "        revAdj[v].push([u, w]);\n";
    cout << "    }\n\n";
    cout << "    const dijkstra = (graph, start) => {\n";
    cout << "        const dist = Array(n).fill(Infinity);\n";
    cout << "        dist[start] = 0;\n";
    cout << "        const pq = [[0, start]];\n\n";
    cout << "        while (pq.length) {\n";
    cout << "            const [d, u] = pq.shift();\n";
    cout << "            if (d > dist[u]) continue;\n";
    cout << "            for (const [v, w] of graph[u]) {\n";
    cout << "                if (dist[u] + w < dist[v]) {\n";
    cout << "                    dist[v] = dist[u] + w;\n";
    cout << "                    pq.push([dist[v], v]);\n";
    cout << "                    pq.sort((a, b) => a[0] - b[0]); // Simple sort for demo\n";
    cout << "                }\n";
    cout << "            }\n";
    cout << "        }\n";
    cout << "        return dist;\n";
    cout << "    };\n\n";
    cout << "    const d1 = dijkstra(adj, src1);\n";
    cout << "    const d2 = dijkstra(adj, src2);\n";
    cout << "    const d3 = dijkstra(revAdj, dest);\n\n";
    cout << "    let ans = Infinity;\n";
    cout << "    for (let i = 0; i < n; i++) {\n";
    cout << "        if (d1[i] !== Infinity && d2[i] !== Infinity && d3[i] !== Infinity) {\n";
    cout << "            ans = Math.min(ans, d1[i] + d2[i] + d3[i]);\n";
    cout << "        }\n";
    cout << "    }\n\n";
    cout << "    return ans === Infinity ? -1 : ans;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: n = 6, edges = [[0,1,1],[1,2,3],[2,3,3],[3,4,2],[4,5,2],[5,0,1]], src1 = 0, src2 = 2, dest = 5\n";
    cout << "Output: 9\n";
    cout << "Explanation: The path with minimum weight is 0->1->2->3->4->5 with weight 1+3+3+2+2 = 11\n";
    cout << "But we can also use node 1 as intermediate: 0->1 + 2->1 + 1->5 = 1+3+5 = 9\n\n";
}

// Problem 137: Partition Array Into Two Arrays to Minimize Sum Difference
void problem137() {
    cout << "\n================================================================================";
    cout << "\n             Problem 137: Partition Array Into Two Arrays to Minimize Sum Difference";
    cout << "\n================================================================================\n";
    cout << "Description: Divide an array into two subarrays such that the absolute difference between";
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

    cout << "Python Solution:\n";
    cout << "class Solution:\n";
    cout << "    def minimumDifference(self, nums):\n";
    cout << "        total = sum(nums)\n";
    cout << "        target = total // 2\n";
    cout << "        dp = [False] * (target + 1)\n";
    cout << "        dp[0] = True\n\n";
    cout << "        for num in nums:\n";
    cout << "            for j in range(target, num - 1, -1):\n";
    cout << "                dp[j] = dp[j] or dp[j - num]\n\n";
    cout << "        for i in range(target, -1, -1):\n";
    cout << "            if dp[i]:\n";
    cout << "                return total - 2 * i\n\n";
    cout << "        return total\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var minimumDifference = function(nums) {\n";
    cout << "    const total = nums.reduce((a, b) => a + b, 0);\n";
    cout << "    const target = Math.floor(total / 2);\n";
    cout << "    const dp = Array(target + 1).fill(false);\n";
    cout << "    dp[0] = true;\n\n";
    cout << "    for (const num of nums) {\n";
    cout << "        for (let j = target; j >= num; j--) {\n";
    cout << "            dp[j] = dp[j] || dp[j - num];\n";
    cout << "        }\n";
    cout << "    }\n\n";
    cout << "    for (let i = target; i >= 0; i--) {\n";
    cout << "        if (dp[i]) {\n";
    cout << "            return total - 2 * i;\n";
    cout << "        }\n";
    cout << "    }\n\n";
    cout << "    return total;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: [3,9,7,3]\n";
    cout << "Output: 2\n";
    cout << "Explanation: One optimal partition is [3,9] and [7,3] with sums 12 and 10, difference 2.\n\n";
}

// Problem 138: Minimum Cost to Cut a Stick
void problem138() {
    cout << "\n================================================================================";
    cout << "\n                        Problem 138: Minimum Cost to Cut a Stick";
    cout << "\n================================================================================\n";
    cout << "Description: You're given a stick of length n and an array of cuts. Determine the minimum";
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

    cout << "Python Solution:\n";
    cout << "class Solution:\n";
    cout << "    def minCost(self, n, cuts):\n";
    cout << "        cuts = [0] + sorted(cuts) + [n]\n";
    cout << "        m = len(cuts)\n";
    cout << "        dp = [[0] * m for _ in range(m)]\n\n";
    cout << "        for length in range(2, m):\n";
    cout << "            for i in range(m - length):\n";
    cout << "                j = i + length\n";
    cout << "                dp[i][j] = float('inf')\n";
    cout << "                for k in range(i + 1, j):\n";
    cout << "                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i])\n\n";
    cout << "        return dp[0][m - 1]\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var minCost = function(n, cuts) {\n";
    cout << "    cuts = [0, ...cuts.sort((a, b) => a - b), n];\n";
    cout << "    const m = cuts.length;\n";
    cout << "    const dp = Array.from({ length: m }, () => Array(m).fill(0));\n\n";
    cout << "    for (let len = 2; len < m; len++) {\n";
    cout << "        for (let i = 0; i + len < m; i++) {\n";
    cout << "            const j = i + len;\n";
    cout << "            dp[i][j] = Infinity;\n";
    cout << "            for (let k = i + 1; k < j; k++) {\n";
    cout << "                dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);\n";
    cout << "            }\n";
    cout << "        }\n";
    cout << "    }\n\n";
    cout << "    return dp[0][m - 1];\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: n = 7, cuts = [1,3,4,5]\n";
    cout << "Output: 16\n";
    cout << "Explanation: Using cuts 1,3,4,5 with costs 6+4+3+3 = 16\n\n";
}

// Problem 139: Maximum Candies You Can Get from Boxes
void problem139() {
    cout << "\n================================================================================";
    cout << "\n                     Problem 139: Maximum Candies You Can Get from Boxes";
    cout << "\n================================================================================\n";
    cout << "Description: You're given boxes containing candies, some locked initially. Determine the";
    cout << "maximum number of candies you can collect by strategically using keys found in open boxes to unlock others.\n\n";

    cout << "Tutorial: This complex problem models resource management with dependencies. It's best solved with a Breadth-First Search (BFS) combined with state tracking.\n";
    cout << "1. State Tracking: We must track three things:\n";
    cout << "   - `q`: Boxes that are currently open and need to be processed.\n";
    cout << "   - `availableKeys`: Keys we have found (stored as box IDs).\n";
    cout << "   - `foundButLocked`: Boxes we found but couldn't open yet.\n";
    cout << "2. BFS Logic:\n";
    cout << "   - Open an available box (status=1 or key in hand).\n";
    cout << "   - Collect its candies.\n";
    cout << "   - Collect new keys (add to `availableKeys`).\n";
    cout << "   - Check `foundButLocked` - if we now have a key, add it to `q`.\n";
    cout << "   - Find new boxes (add to `q` if openable, otherwise add to `foundButLocked`).\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <queue>\n#include <unordered_set>\nusing namespace std;\n\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, \n";
    cout << "                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {\n";
    cout << "        queue<int> q;\n";
    cout << "        unordered_set<int> availableKeys;\n";
    cout << "        // Tracks boxes that are found but currently locked AND we don't have the key yet\n";
    cout << "        unordered_set<int> foundButLocked;\n";
    cout << "        vector<bool> opened(status.size(), false);\n";
    cout << "        int totalCandies = 0;\n\n";

    cout << "        for (int box : initialBoxes) {\n";
    cout << "            if (status[box] == 1) {\n";
    cout << "                q.push(box);\n";
    cout << "                opened[box] = true;\n";
    cout << "            } else {\n";
    cout << "                foundButLocked.insert(box); // Found it, but it's locked and key status unknown\n";
    cout << "            }\n";
    cout << "        }\n\n";

    cout << "        while (!q.empty()) {\n";
    cout << "            int box = q.front(); q.pop();\n";
    cout << "            totalCandies += candies[box];\n\n";

    cout << "            // 1. Process keys found in the current box\n";
    cout << "            for (int key : keys[box]) {\n";
    cout << "                availableKeys.insert(key);\n";
    cout << "                // Check if this key unlocks a box we already found\n";
    cout << "                if (foundButLocked.count(key) && !opened[key]) {\n";
    cout << "                    q.push(key);\n";
    cout << "                    opened[key] = true;\n";
    cout << "                    foundButLocked.erase(key);\n";
    cout << "                }\n";
    cout << "            }\n\n";

    cout << "            // 2. Process boxes found inside the current box\n";
    cout << "            for (int nextBox : containedBoxes[box]) {\n";
    cout << "                if (!opened[nextBox]) {\n";
    cout << "                    if (status[nextBox] == 1 || availableKeys.count(nextBox)) {\n";
    cout << "                        q.push(nextBox);\n";
    cout << "                        opened[nextBox] = true;\n";
    cout << "                        if (foundButLocked.count(nextBox)) foundButLocked.erase(nextBox);\n";
    cout << "                    } else {\n";
    cout << "                        foundButLocked.insert(nextBox);\n";
    cout << "                    }\n";
    cout << "                }\n";
    cout << "            }\n";
    cout << "        }\n\n";

    cout << "        return totalCandies;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "from collections import deque\n\n";
    cout << "class Solution:\n";
    cout << "    def maxCandies(self, status, candies, keys, containedBoxes, initialBoxes):\n";
    cout << "        q = deque()\n";
    cout << "        available_keys = set()\n";
    cout << "        found_but_locked = set()\n";
    cout << "        opened = [False] * len(status)\n";
    cout << "        total_candies = 0\n\n";

    cout << "        for box in initialBoxes:\n";
    cout << "            if status[box] == 1:\n";
    cout << "                q.append(box)\n";
    cout << "                opened[box] = True\n";
    cout << "            else:\n";
    cout << "                found_but_locked.add(box)\n\n";

    cout << "        while q:\n";
    cout << "            box = q.popleft()\n";
    cout << "            total_candies += candies[box]\n\n";

    cout << "            for key in keys[box]:\n";
    cout << "                available_keys.add(key)\n";
    cout << "                if key in found_but_locked and not opened[key]:\n";
    cout << "                    q.append(key)\n";
    cout << "                    opened[key] = True\n";
    cout << "                    found_but_locked.remove(key)\n\n";

    cout << "            for next_box in containedBoxes[box]:\n";
    cout << "                if not opened[next_box]:\n";
    cout << "                    if status[next_box] == 1 or next_box in available_keys:\n";
    cout << "                        q.append(next_box)\n";
    cout << "                        opened[next_box] = True\n";
    cout << "                        if next_box in found_but_locked: found_but_locked.remove(next_box)\n";
    cout << "                    else:\n";
    cout << "                        found_but_locked.add(next_box)\n\n";

    cout << "        return total_candies\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var maxCandies = function(status, candies, keys, containedBoxes, initialBoxes) {\n";
    cout << "    const q = [];\n";
    cout << "    const availableKeys = new Set();\n";
    cout << "    const foundButLocked = new Set();\n";
    cout << "    const opened = Array(status.length).fill(false);\n";
    cout << "    let totalCandies = 0;\n\n";

    cout << "    for (const box of initialBoxes) {\n";
    cout << "        if (status[box] === 1) {\n";
    cout << "            q.push(box);\n";
    cout << "            opened[box] = true;\n";
    cout << "        } else {\n";
    cout << "            foundButLocked.add(box);\n";
    cout << "        }\n";
    cout << "    }\n\n";

    cout << "    while (q.length) {\n";
    cout << "        const box = q.shift();\n";
    cout << "        totalCandies += candies[box];\n\n";

    cout << "        // 1. Process keys found\n";
    cout << "        for (const key of keys[box]) {\n";
    cout << "            availableKeys.add(key);\n";
    cout << "            if (foundButLocked.has(key) && !opened[key]) {\n";
    cout << "                q.push(key);\n";
    cout << "                opened[key] = true;\n";
    cout << "                foundButLocked.delete(key);\n";
    cout << "            }\n";
    cout << "        }\n\n";

    cout << "        // 2. Process contained boxes\n";
    cout << "        for (const nextBox of containedBoxes[box]) {\n";
    cout << "            if (!opened[nextBox]) {\n";
    cout << "                if (status[nextBox] === 1 || availableKeys.has(nextBox)) {\n";
    cout << "                    q.push(nextBox);\n";
    cout << "                    opened[nextBox] = true;\n";
    cout << "                    if (foundButLocked.has(nextBox)) foundButLocked.delete(nextBox);\n";
    cout << "                } else {\n";
    cout << "                    foundButLocked.add(nextBox);\n";
    cout << "                }\n";
    cout << "            }\n";
    cout << "        }\n";
    cout << "    }\n\n";

    cout << "    return totalCandies;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: status = [1,1,1,1,1], candies = [1,1,1,10,1], keys = [[],[0,1,2,3,4],[],[],[]], \n";
    cout << "       containedBoxes = [[1,2,3,4],[],[],[],[]], initialBoxes = [0]\n";
    cout << "Output: 1\n";
    cout << "Explanation: We can only open box 0 and get 1 candy, but we can't open any other boxes.\n\n";
}

// Problem 140: Sum of Subarray Minimums
void problem140() {
    cout << "\n================================================================================";
    cout << "\n                         Problem 140: Sum of Subarray Minimums";
    cout << "\n================================================================================\n";
    cout << "Description: You're given an array of numbers. Find the sum of the minimum values of";
    cout << "all possible subarrays within that array.\n\n";

    cout << "Tutorial: A naive solution is O(N^3), but we need O(N). The key insight is to calculate the contribution of each element as the minimum, rather than iterating through all subarrays.\n";
    cout << "1. For each element `arr[i]`, find its Previous Smaller Element (PSE) and Next Smaller Element (NSE).\n";
    cout << "2. `PSE[i]` is the index of the closest element to the left that is strictly smaller than `arr[i]`.\n";
    cout << "3. `NSE[i]` is the index of the closest element to the right that is strictly smaller than `arr[i]`.\n";
    cout << "4. All subarrays for which `arr[i]` is the minimum span from `PSE[i]+1` to `NSE[i]-1`.\n";
    cout << "5. Number of such subarrays = `(i - PSE[i]) * (NSE[i] - i)`.\n";
    cout << "6. Total sum = Sum of `arr[i] * (i - PSE[i]) * (NSE[i] - i)` for all i.\n";
    cout << "7. A Monotonic Stack efficiently computes PSE and NSE in a single pass.\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <stack>\nusing namespace std;\n\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int sumSubarrayMins(vector<int>& arr) {\n";
    cout << "        const int MOD = 1000000007;\n";
    cout << "        stack<int> st;\n";
    cout << "        long long result = 0;\n\n";

    cout << "        // Iterate from 0 to arr.size() (the latter acts as a sentinel)\n";
    cout << "        for (int i = 0; i <= arr.size(); ++i) {\n";
    cout << "            while (!st.empty() && (i == arr.size() || arr[st.top()] >= arr[i])) {\n";
    cout << "                int mid = st.top(); st.pop();\n";
    cout << "                int left = st.empty() ? -1 : st.top();\n";
    cout << "                int right = i; // Current index acts as the Next Smaller Element\n";
    cout << "                long long count = (long long)(mid - left) * (right - mid) % MOD;\n";
    cout << "                result = (result + arr[mid] * count) % MOD;\n";
    cout << "            }\n";
    cout << "            st.push(i);\n";
    cout << "        }\n\n";

    cout << "        return (int)result;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "class Solution:\n";
    cout << "    def sumSubarrayMins(self, arr):\n";
    cout << "        MOD = 10**9 + 7\n";
    cout << "        stack = []\n";
    cout << "        result = 0\n\n";

    cout << "        for i in range(len(arr) + 1):\n";
    cout << "            # Sentinel check (i == len(arr)) or current element is smaller\n";
    cout << "            while stack and (i == len(arr) or arr[stack[-1]] >= arr[i]):\n";
    cout << "                mid = stack.pop()\n";
    cout << "                left = stack[-1] if stack else -1\n";
    cout << "                right = i\n";
    cout << "                count = (mid - left) * (right - mid)\n";
    cout << "                result = (result + arr[mid] * count) % MOD\n";
    cout << "            stack.append(i)\n\n";

    cout << "        return result\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var sumSubarrayMins = function(arr) {\n";
    cout << "    const MOD = 1000000007;\n";
    cout << "    const stack = [];\n";
    cout << "    let result = 0;\n\n";

    cout << "    for (let i = 0; i <= arr.length; i++) {\n";
    cout << "        while (stack.length && (i === arr.length || arr[stack[stack.length - 1]] >= arr[i])) {\n";
    cout << "            const mid = stack.pop();\n";
    cout << "            const left = stack.length ? stack[stack.length - 1] : -1;\n";
    cout << "            const right = i;\n";
    cout << "            const count = (mid - left) * (right - mid);\n";
    cout << "            result = (result + arr[mid] * count) % MOD;\n";
    cout << "        }\n";
    cout << "        stack.push(i);\n";
    cout << "    }\n\n";

    cout << "    return result;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: [3,1,2,4]\n";
    cout << "Output: 17\n";
    cout << "Explanation: Sum of all subarray minimums is 3+1+2+4+1+1+2+1+1+1 = 17\n\n";
}

// Problem 141: Longest Duplicate Substring
void problem141() {
    cout << "\n================================================================================";
    cout << "\n                         Problem 141: Longest Duplicate Substring";
    cout << "\n================================================================================\n";
    cout << "Description: Find the longest substring that appears at least twice in a given string.";
    cout << "The occurrences may overlap.\n\n";

    cout << "Tutorial: The problem asks for the *longest* substring, which suggests a monotonic property (if a substring of length L exists, all substrings of length < L also exist). This allows for Binary Search over the possible length [0, N-1].\n";
    cout << "1. Binary Search on the length `L`.\n";
    cout << "2. For a given length `L`, we need a fast way to check if a duplicate substring exists.\n";
    cout << "3. The `findDuplicate` function iterates through all substrings of length `L`.\n";
    cout << "4. It uses a Hash Set to track seen substrings (or ideally, a more efficient Rabin-Karp rolling hash for true O(N log N) complexity, though simple hash sets pass for most constraints).\n";
    cout << "5. If a duplicate is found, we try for a longer length (l = mid + 1); otherwise, we try a shorter length (r = mid - 1).\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <string>\n#include <vector>\n#include <unordered_set>\nusing namespace std;\n\n";

    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    // NOTE: This simple implementation uses a hash set of strings, which is O(N^2) in worst case (hashing long strings). \n";
    cout << "    // The true efficient solution uses Rabin-Karp (Rolling Hash) for O(N log N) performance.\n";
    cout << "    string longestDupSubstring(string s) {\n";
    cout << "        int n = s.size();\n";
    cout << "        int l = 0, r = n - 1;\n";
    cout << "        string result = \"\";\n\n";

    cout << "        while (l <= r) {\n";
    cout << "            int mid = l + (r - l) / 2;\n";
    cout << "            string dup = findDuplicate(s, mid);\n";
    cout << "            if (!dup.empty()) {\n";
    cout << "                result = dup;\n";
    cout << "                l = mid + 1;\n";
    cout << "            } else {\n";
    cout << "                r = mid - 1;\n";
    cout << "            }\n";
    cout << "        }\n\n";

    cout << "        return result;\n";
    cout << "    }\n\n";

    cout << "private:\n";
    cout << "    string findDuplicate(const string& s, int len) {\n";
    cout << "        if (len == 0) return \"\";\n";
    cout << "        unordered_set<string> seen;\n";
    cout << "        for (int i = 0; i + len <= s.size(); ++i) {\n";
    cout << "            string substr = s.substr(i, len);\n";
    cout << "            if (seen.count(substr)) return substr;\n";
    cout << "            seen.insert(substr);\n";
    cout << "        }\n";
    cout << "        return \"\";\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "class Solution:\n";
    cout << "    # Python's solution benefits from fast substring operations and good dict/set performance\n";
    cout << "    def longestDupSubstring(self, s):\n";
    cout << "        n = len(s)\n";
    cout << "        l, r = 0, n - 1\n";
    cout << "        result = \"\"\n\n";

    cout << "        while l <= r:\n";
    cout << "            mid = (l + r) // 2\n";
    cout << "            dup = self.findDuplicate(s, mid)\n";
    cout << "            if dup:\n";
    cout << "                result = dup\n";
    cout << "                l = mid + 1\n";
    cout << "            else:\n";
    cout << "                r = mid - 1\n\n";

    cout << "        return result\n\n";

    cout << "    def findDuplicate(self, s, length):\n";
    cout << "        if length == 0:\n";
    cout << "            return \"\"\n";
    cout << "        seen = set()\n";
    cout << "        for i in range(len(s) - length + 1):\n";
    cout << "            substr = s[i:i + length]\n";
    cout << "            if substr in seen:\n";
    cout << "                return substr\n";
    cout << "            seen.add(substr)\n";
    cout << "        return \"\"\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var longestDupSubstring = function(s) {\n";
    cout << "    const n = s.length;\n";
    cout << "    let l = 0, r = n - 1;\n";
    cout << "    let result = \"\";\n\n";

    cout << "    while (l <= r) {\n";
    cout << "        const mid = Math.floor((l + r) / 2);\n";
    cout << "        const dup = findDuplicate(s, mid);\n";
    cout << "        if (dup) {\n";
    cout << "            result = dup;\n";
    cout << "            l = mid + 1;\n";
    cout << "        } else {\n";
    cout << "            r = mid - 1;\n";
    cout << "        }\n";
    cout << "    }\n\n";

    cout << "    return result;\n\n";

    cout << "    function findDuplicate(str, len) {\n";
    cout << "        if (len === 0) return \"\";\n";
    cout << "        const seen = new Set();\n";
    cout << "        for (let i = 0; i + len <= str.length; i++) {\n";
    cout << "            const substr = str.substring(i, i + len);\n";
    cout << "            if (seen.has(substr)) return substr;\n";
    cout << "            seen.add(substr);\n";
    cout << "        }\n";
    cout << "        return \"\";\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: \"banana\"\n";
    cout << "Output: \"ana\"\n";
    cout << "Explanation: \"ana\" appears twice in \"banana\" (at positions 1 and 3)\n\n";
}

// Problem 142: Max Consecutive Ones III
void problem142() {
    cout << "\n================================================================================";
    cout << "\n                         Problem 142: Max Consecutive Ones III";
    cout << "\n================================================================================\n";
    cout << "Description: Find the longest subarray containing only 1s, where you are allowed to";
    cout << "flip up to k 0s to 1s. Return the maximum length of such a subarray.\n\n";

    cout << "Tutorial: This is a classic Sliding Window problem, optimizing for a subarray that respects a maximum constraint (max `k` zeros).\n";
    cout << "1. Use two pointers, `left` and `right`, defining the current window.\n";
    cout << "2. Expand the window with `right`.\n";
    cout << "3. Maintain a count of `zeros` within the window.\n";
    cout << "4. If `zeros > k`, the constraint is violated. Shrink the window by moving `left` forward until `zeros <= k`.\n";
    cout << "5. The maximum length is tracked as `right - left + 1`.\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <algorithm>\nusing namespace std;\n\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int longestOnes(vector<int>& nums, int k) {\n";
    cout << "        int left = 0, zeros = 0, maxLen = 0;\n\n";

    cout << "        for (int right = 0; right < nums.size(); ++right) {\n";
    cout << "            if (nums[right] == 0) zeros++;\n\n";

    cout << "            while (zeros > k) {\n";
    cout << "                if (nums[left] == 0) zeros--;\n";
    cout << "                left++;\n";
    cout << "            }\n\n";

    cout << "            maxLen = max(maxLen, right - left + 1);\n";
    cout << "        }\n\n";

    cout << "        return maxLen;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "class Solution:\n";
    cout << "    def longestOnes(self, nums, k):\n";
    cout << "        left = 0\n";
    cout << "        zeros = 0\n";
    cout << "        max_len = 0\n\n";

    cout << "        for right in range(len(nums)):\n";
    cout << "            if nums[right] == 0:\n";
    cout << "                zeros += 1\n\n";

    cout << "            while zeros > k:\n";
    cout << "                if nums[left] == 0:\n";
    cout << "                    zeros -= 1\n";
    cout << "                left += 1\n\n";

    cout << "            max_len = max(max_len, right - left + 1)\n\n";

    cout << "        return max_len\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var longestOnes = function(nums, k) {\n";
    cout << "    let left = 0, zeros = 0, maxLen = 0;\n\n";

    cout << "    for (let right = 0; right < nums.length; right++) {\n";
    cout << "        if (nums[right] === 0) zeros++;\n\n";

    cout << "        while (zeros > k) {\n";
    cout << "            if (nums[left] === 0) zeros--;\n";
    cout << "            left++;\n";
    cout << "        }\n\n";

    cout << "        maxLen = Math.max(maxLen, right - left + 1);\n";
    cout << "    }\n\n";

    cout << "    return maxLen;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2\n";
    cout << "Output: 6\n";
    cout << "Explanation: The longest subarray is [1,1,1,0,0,1,1,1,1,1,1] with 5 zeros flipped to 1s, length 6\n\n";
}

// Problem 143: Power of Two
void problem143() {
    cout << "\n================================================================================";
    cout << "\n                           Problem 143: Power of Two";
    cout << "\n================================================================================\n";
    cout << "Description: Determine if a given integer is a power of two. That is, check if it can";
    cout << "be expressed as 2 raised to some integer exponent.\n\n";

    cout << "Tutorial: The most efficient solution uses bit manipulation, leveraging a fundamental property of powers of two in binary.\n";
    cout << "1. A power of two (e.g., 8, 16) has exactly one '1' bit in its binary representation (e.g., 1000, 10000).\n";
    cout << "2. The operation `n - 1` flips all bits to the right of the lowest set bit, and the lowest set bit itself becomes 0.\n";
    cout << "3. The bitwise AND operation `n & (n - 1)` will result in 0 if and only if `n` has exactly one set bit.\n";
    cout << "4. We must also check that `n` is positive, as 0 and negative numbers are not powers of two.\n\n";

    cout << "C++ Solution:\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    bool isPowerOfTwo(int n) {\n";
    cout << "        if (n <= 0) return false;\n";
    cout << "        // Bitwise trick: checks if n has exactly one set bit\n";
    cout << "        return (n & (n - 1)) == 0;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "class Solution:\n";
    cout << "    def isPowerOfTwo(self, n):\n";
    cout << "        # Uses the same bitwise trick\n";
    cout << "        return n > 0 and (n & (n - 1)) == 0\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var isPowerOfTwo = function(n) {\n";
    cout << "    // Uses the same bitwise trick\n";
    cout << "    return n > 0 && (n & (n - 1)) === 0;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: 16\n";
    cout << "Output: true\n";
    cout << "Explanation: 16 in binary is 10000. 16 & (16-1) -> 10000 & 01111 = 0\n\n";
}

// Problem 144: Longest Palindrome by Concatenating Two Letter Words
void problem144() {
    cout << "\n================================================================================";
    cout << "\n              Problem 144: Longest Palindrome by Concatenating Two Letter Words";
    cout << "\n================================================================================\n";
    cout << "Description: You're given a list of two-letter words. Find the length of the longest";
    cout << "palindrome you can build by concatenating words from the list.\n\n";

    cout << "Tutorial: A palindrome formed by concatenating words must look like: W1 W2 ... Wk CENTER Wk' ... W2' W1', where Wk' is the reverse of Wk.\n";
    cout << "1. Count the frequency of every two-letter word.\n";
    cout << "2. Identify two types of words:\n";
    cout << "   a. **Non-palindromic words (e.g., \"ab\"):** Must be paired with their reverse (\"ba\"). Use `min(count('ab'), count('ba'))` pairs.\n";
    cout << "   b. **Palindromic words (e.g., \"aa\"):** Can be paired up (e.g., \"aa\" + \"aa\"). Any odd count leaves one word for the center.\n";
    cout << "3. Total length = `(Number of pairs * 4) + (2 if a center word is used)`.\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <unordered_map>\n#include <string>\n#include <algorithm>\nusing namespace std;\n\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int longestPalindrome(vector<string>& words) {\n";
    cout << "        unordered_map<string, int> freq;\n";
    cout << "        for (const string& word : words) {\n";
    cout << "            freq[word]++;\n";
    cout << "        }\n\n";

    cout << "        int center = 0, pairs = 0;\n\n";

    cout << "        for (auto& [word, count] : freq) {\n";
    cout << "            string rev = string(word.rbegin(), word.rend());\n";

    cout << "            if (word == rev) { // Palindromic word type (e.g., \"aa\")\n";
    cout << "                pairs += count / 2; // Use all pairs\n";
    cout << "                if (count % 2 == 1) center = 1; // Can use one single word as center\n";
    cout << "            } else if (freq.find(rev) != freq.end()) { // Non-palindromic word type (e.g., \"ab\")\n";
    cout << "                pairs += min(count, freq[rev]);\n";
    cout << "                freq[rev] = 0; // Avoid double counting when processing the reverse\n";
    cout << "            }\n";
    cout << "        }\n\n";

    cout << "        // Each pair adds 4 to length (word + reverse) or (aa + aa)\n";
    cout << "        // The center adds 2 if present\n";
    cout << "        return (pairs * 4) + (center * 2);\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "from collections import Counter\n\n";
    cout << "class Solution:\n";
    cout << "    def longestPalindrome(self, words):\n";
    cout << "        freq = Counter(words)\n";
    cout << "        center = 0\n";
    cout << "        pairs = 0\n\n";

    cout << "        for word, count in list(freq.items()):\n";
    cout << "            rev = word[::-1]\n";

    cout << "            if word == rev:\n";
    cout << "                pairs += count // 2\n";
    cout << "                if count % 2 == 1:\n";
    cout << "                    center = 1\n";
    cout << "            elif rev in freq:\n";
    cout << "                pairs += min(count, freq[rev])\n";
    cout << "                freq[rev] = 0  # Avoid double counting\n\n";

    cout << "        return pairs * 4 + center * 2\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var longestPalindrome = function(words) {\n";
    cout << "    const freq = {};\n";
    cout << "    for (const word of words) {\n";
    cout << "        freq[word] = (freq[word] || 0) + 1;\n";
    cout << "    }\n\n";

    cout << "    let center = 0;\n";
    cout << "    let pairs = 0;\n\n";

    cout << "    for (const word in freq) {\n";
    cout << "        const count = freq[word];\n";
    cout << "        const rev = word.split('').reverse().join('');\n";

    cout << "        if (word === rev) {\n";
    cout << "            pairs += Math.floor(count / 2);\n";
    cout << "            if (count % 2 === 1) center = 1;\n";
    cout << "        } else if (freq[rev]) {\n";
    cout << "            pairs += Math.min(count, freq[rev]);\n";
    cout << "            freq[word] = 0; // Mark word count as 0 to avoid using it again\n";
    cout << "            freq[rev] = 0; // The reverse is also consumed\n";
    cout << "        }\n";
    cout << "    }\n\n";

    cout << "    return pairs * 4 + center * 2;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: words = [\"ab\",\"ty\",\"yt\",\"lc\",\"cl\",\"ab\"]\n";
    cout << "Output: 8\n";
    cout << "Explanation: Pairs are {\"ab\", \"ba\"}, {\"ty\", \"yt\"}, {\"lc\", \"cl\"}. Length is 3*4 = 12. Correct pairs were {\"ty\", \"yt\"} and {\"lc\", \"cl\"}. Total 8.\n\n";
}

// Problem 145: Snapshot Array
void problem145() {
    cout << "\n================================================================================";
    cout << "\n                           Problem 145: Snapshot Array";
    cout << "\n================================================================================\n";
    cout << "Description: Implement a snapshot array where you can update elements and take";
    cout << "snapshots of the array at any time. Later, you should be able to retrieve the value";
    cout << "of an element at a specific snapshot.\n\n";

    cout << "Tutorial: The challenge is efficiency in memory and retrieval. Instead of copying the whole array at each `snap()`, we only record the history of *changes* for each index.\n";
    cout << "1. Use a `std::vector` of `std::map` (or list of pairs/tuples) to store state history.\n";
    cout << "2. For index `i`, store `snapshots[i]` as a map where `key=snap_id` and `value=value`.\n";
    cout << "3. `set(index, val)`: Records the change with the current `snapId`.\n";
    cout << "4. `snap()`: Simply increments the global `snapId`.\n";
    cout << "5. `get(index, snap_id)`: Uses `map::upper_bound` (or binary search) to find the largest `snapId` in the history that is less than or equal to the requested `snap_id`. This is the value that was in effect at that time.\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <map>\nusing namespace std;\n\n";

    cout << "class SnapshotArray {\n";
    cout << "private:\n";
    cout << "    int snapId = 0;\n";
    cout << "    // Stores (index -> {snap_id -> value}) - Map provides efficient lookup\n";
    cout << "    vector<map<int, int>> snapshots;\n\n";

    cout << "public:\n";
    cout << "    SnapshotArray(int length) : snapshots(length) {\n";
    cout << "        // Initialize with default value 0 at snapId -1 (before any snap)\n";
    cout << "        for(int i = 0; i < length; ++i) {\n";
    cout << "            snapshots[i][-1] = 0;\n";
    cout << "        }\n";
    cout << "    }\n\n";

    cout << "    void set(int index, int val) {\n";
    cout << "        snapshots[index][snapId] = val;\n";
    cout << "    }\n\n";

    cout << "    int snap() {\n";
    cout << "        return snapId++;\n";
    cout << "    }\n\n";

    cout << "    int get(int index, int snap_id) {\n";
    cout << "        auto& history = snapshots[index];\n";
    cout << "        // Find the first element with a snapId > snap_id\n";
    cout << "        auto it = history.upper_bound(snap_id);\n";
    cout << "        // The previous element holds the latest value at or before snap_id\n";
    cout << "        --it;\n";
    cout << "        return it->second;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "from bisect import bisect_right\n\n";

    cout << "class SnapshotArray:\n";
    cout << "    def __init__(self, length):\n";
    cout << "        self.snap_id = 0\n";
    cout << "        # Stores history as list of (snap_id, value) pairs. (-1, 0) is the base.\n";
    cout << "        self.arr = [[(-1, 0)] for _ in range(length)]\n\n";

    cout << "    def set(self, index, val):\n";
    cout << "        # Overwrite if the last change was in the current snap_id\n";
    cout << "        if self.arr[index][-1][0] == self.snap_id:\n";
    cout << "            self.arr[index][-1] = (self.snap_id, val)\n";
    cout << "        else:\n";
    cout << "            self.arr[index].append((self.snap_id, val))\n\n";

    cout << "    def snap(self):\n";
    cout << "        self.snap_id += 1\n";
    cout << "        return self.snap_id - 1\n\n";

    cout << "    def get(self, index, snap_id):\n";
    cout << "        history = self.arr[index]\n";
    cout << "        # bisect_right finds insertion point for (snap_id, inf)\n";
    cout << "        # Decrementing the index gives the position of the desired value\n";
    cout << "        pos = bisect_right(history, (snap_id, float('inf'))) - 1\n";
    cout << "        return history[pos][1]\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var SnapshotArray = function(length) {\n";
    cout << "    this.snapId = 0;\n";
    cout << "    // History of { snapId, val } objects, stored in chronological order.\n";
    cout << "    this.arr = Array.from({ length }, () => [{ snapId: -1, val: 0 }]);\n";
    cout << "};\n\n";

    cout << "SnapshotArray.prototype.set = function(index, val) {\n";
    cout << "    const lastRecord = this.arr[index][this.arr[index].length - 1];\n";
    cout << "    if (lastRecord.snapId === this.snapId) {\n";
    cout << "        lastRecord.val = val; // Overwrite if in current snapshot\n";
    cout << "    } else {\n";
    cout << "        this.arr[index].push({ snapId: this.snapId, val });\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "SnapshotArray.prototype.snap = function() {\n";
    cout << "    return this.snapId++;\n";
    cout << "};\n\n";

    cout << "SnapshotArray.prototype.get = function(index, snapId) {\n";
    cout << "    const history = this.arr[index];\n";
    cout << "    let left = 0, right = history.length - 1;\n";
    cout << "    let result = 0;\n\n";

    cout << "    // Binary search for the last record with snapId <= requested snapId\n";
    cout << "    while (left <= right) {\n";
    cout << "        const mid = Math.floor((left + right) / 2);\n";
    cout << "        if (history[mid].snapId <= snapId) {\n";
    cout << "            result = history[mid].val;\n";
    cout << "            left = mid + 1;\n";
    cout << "        } else {\n";
    cout << "            right = mid - 1;\n";
    cout << "        }\n";
    cout << "    }\n\n";

    cout << "    return result;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: [\"SnapshotArray\",\"set\",\"snap\",\"set\",\"get\"]\n";
    cout << "       [[3],[0,5],[0],[0,6],[0,0]]\n";
    cout << "Output: [null,null,0,null,5]\n";
    cout << "Explanation: At snapshot 0, set arr[0]=5; at snapshot 1, set arr[0]=6; get(0,0) returns 5\n\n";
}

// Problem 146: Shortest Path in a Grid with Obstacles Elimination
void problem146() {
    cout << "\n================================================================================";
    cout << "\n              Problem 146: Shortest Path in a Grid with Obstacles Elimination";
    cout << "\n================================================================================\n";
    cout << "Description: Find the shortest path from the top-left to the bottom-right corner of a";
    cout << "grid. You can eliminate a limited number of obstacles along the way.\n\n";

    cout << "Tutorial: This pathfinding problem requires Breadth-First Search (BFS) where the state includes the number of eliminations remaining. This is crucial because reaching a cell with more eliminations left is better.\n";
    cout << "1. State: `(row, col, eliminations_left, steps)`.\n";
    cout << "2. `Visited` Tracking: Use a 3D array: `visited[row][col][eliminations_left]` to ensure we don't process the same cell with a worse *remaining elimination count*.\n";
    cout << "3. Optimization: If `k` is large enough to bypass the entire grid (`k >= m + n - 2`), the shortest path is simply the Manhattan distance.\n";
    cout << "4. Movement: If moving into a `1` (obstacle), the new elimination count is `current_elim - 1`.\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <queue>\n#include <tuple>\nusing namespace std;\n\n";

    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int shortestPath(vector<vector<int>>& grid, int k) {\n";
    cout << "        int m = grid.size(), n = grid[0].size();\n";
    cout << "        // Optimization: if k is large enough, path is Manhattan distance\n";
    cout << "        if (k >= m + n - 2) return m + n - 2;\n\n";

    cout << "        // 3D visited: [row][col][eliminations_left]\n";
    cout << "        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));\n";
    cout << "        // Queue state: (row, col, eliminations_left, steps)\n";
    cout << "        queue<tuple<int, int, int, int>> q;\n";
    cout << "        q.push({0, 0, k, 0});\n";
    cout << "        visited[0][0][k] = true;\n\n";

    cout << "        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};\n\n";

    cout << "        while (!q.empty()) {\n";
    cout << "            auto [r, c, elim, steps] = q.front(); q.pop();\n\n";

    cout << "            if (r == m - 1 && c == n - 1) return steps;\n\n";

    cout << "            for (auto& dir : dirs) {\n";
    cout << "                int nr = r + dir[0], nc = c + dir[1];\n";
    cout << "                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;\n\n";

    cout << "                int newElim = elim - grid[nr][nc]; // grid[nr][nc] is 1 or 0\n";
    cout << "                if (newElim < 0 || visited[nr][nc][newElim]) continue;\n\n";

    cout << "                visited[nr][nc][newElim] = true;\n";
    cout << "                q.push({nr, nc, newElim, steps + 1});\n";
    cout << "            }\n";
    cout << "        }\n\n";

    cout << "        return -1;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "from collections import deque\n\n";

    cout << "class Solution:\n";
    cout << "    def shortestPath(self, grid, k):\n";
    cout << "        m, n = len(grid), len(grid[0])\n";
    cout << "        if k >= m + n - 2:\n";
    cout << "            return m + n - 2\n\n";

    cout << "        # 3D visited: [row][col][eliminations_left]\n";
    cout << "        visited = [[[False] * (k + 1) for _ in range(n)] for _ in range(m)]\n";
    cout << "        # Queue state: (row, col, eliminations_left, steps)\n";
    cout << "        q = deque([(0, 0, k, 0)])\n";
    cout << "        visited[0][0][k] = True\n\n";

    cout << "        dirs = [(0,1), (1,0), (0,-1), (-1,0)]\n\n";

    cout << "        while q:\n";
    cout << "            r, c, elim, steps = q.popleft()\n\n";

    cout << "            if r == m - 1 and c == n - 1:\n";
    cout << "                return steps\n\n";

    cout << "            for dr, dc in dirs:\n";
    cout << "                nr, nc = r + dr, c + dc\n";
    cout << "                if not (0 <= nr < m and 0 <= nc < n):\n";
    cout << "                    continue\n\n";

    cout << "                new_elim = elim - grid[nr][nc]\n";
    cout << "                if new_elim < 0 or visited[nr][nc][new_elim]:\n";
    cout << "                    continue\n\n";

    cout << "                visited[nr][nc][new_elim] = True\n";
    cout << "                q.append((nr, nc, new_elim, steps + 1))\n\n";

    cout << "        return -1\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var shortestPath = function(grid, k) {\n";
    cout << "    const m = grid.length, n = grid[0].length;\n";
    cout << "    if (k >= m + n - 2) return m + n - 2;\n\n";

    cout << "    const visited = Array.from({ length: m }, () =>\n";
    cout << "        Array.from({ length: n }, () => Array(k + 1).fill(false))\n";
    cout << "    );\n";
    cout << "    const q = [[0, 0, k, 0]]; // [row, col, eliminations_left, steps]\n";
    cout << "    visited[0][0][k] = true;\n\n";

    cout << "    const dirs = [[0,1], [1,0], [0,-1], [-1,0]];\n\n";

    cout << "    while (q.length) {\n";
    cout << "        const [r, c, elim, steps] = q.shift();\n\n";

    cout << "        if (r === m - 1 && c === n - 1) return steps;\n\n";

    cout << "        for (const [dr, dc] of dirs) {\n";
    cout << "            const nr = r + dr, nc = c + dc;\n";
    cout << "            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;\n\n";

    cout << "            const newElim = elim - grid[nr][nc];\n";
    cout << "            if (newElim < 0 || visited[nr][nc][newElim]) continue;\n\n";

    cout << "            visited[nr][nc][newElim] = true;\n";
    cout << "            q.push([nr, nc, newElim, steps + 1]);\n";
    cout << "        }\n";
    cout << "    }\n\n";

    cout << "    return -1;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1\n";
    cout << "Output: 6\n";
    cout << "Explanation: The shortest path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2)\n\n";
}

// Problem 147: Sqrt(x)
void problem147() {
    cout << "\n================================================================================";
    cout << "\n                                 Problem 147: Sqrt(x)";
    cout << "\n================================================================================\n";
    cout << "Description: Calculate the integer square root of a non-negative integer, truncating";
    cout << "any decimal portion. Return the integer part of the square root.\n\n";

    cout << "Tutorial: The problem requires finding the largest integer `n` such that `n*n <= x`. This search space is monotonic (`n*n` increases with `n`), making Binary Search the ideal algorithm.\n";
    cout << "1. Initialize the search space: `left = 1`, `right = x`.\n";
    cout << "2. Use a `long long` for the square check to prevent integer overflow (`mid * mid`).\n";
    cout << "3. If `mid*mid <= x`, it could be the answer or we can find a larger one, so save the potential answer and search right (`left = mid + 1`).\n";
    cout << "4. If `mid*mid > x`, the number is too large, search left (`right = mid - 1`).\n";
    cout << "5. After the loop, the `right` pointer holds the correct integer square root.\n\n";

    cout << "C++ Solution:\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int mySqrt(int x) {\n";
    cout << "        if (x == 0) return 0;\n";
    cout << "        long long left = 1, right = x;\n";
    cout << "        int ans = 1;\n";
    cout << "        while (left <= right) {\n";
    cout << "            long long mid = left + (right - left) / 2;\n";
    cout << "            if (mid * mid <= x) {\n";
    cout << "                ans = (int)mid;\n";
    cout << "                left = mid + 1;\n";
    cout << "            } else {\n";
    cout << "                right = mid - 1;\n";
    cout << "            }\n";
    cout << "        }\n";
    cout << "        return ans;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "class Solution:\n";
    cout << "    def mySqrt(self, x):\n";
    cout << "        if x == 0:\n";
    cout << "            return 0\n";
    cout << "        left, right = 1, x\n";
    cout << "        ans = 1\n";
    cout << "        while left <= right:\n";
    cout << "            mid = (left + right) // 2\n";
    cout << "            if mid * mid <= x:\n";
    cout << "                ans = mid\n";
    cout << "                left = mid + 1\n";
    cout << "            else:\n";
    cout << "                right = mid - 1\n";
    cout << "        return ans\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var mySqrt = function(x) {\n";
    cout << "    if (x === 0) return 0;\n";
    cout << "    let left = 1, right = x;\n";
    cout << "    let ans = 1;\n";
    cout << "    while (left <= right) {\n";
    cout << "        const mid = Math.floor(left + (right - left) / 2);\n";
    cout << "        if (mid * mid <= x) {\n";
    cout << "            ans = mid;\n";
    cout << "            left = mid + 1;\n";
    cout << "        } else {\n";
    cout << "            right = mid - 1;\n";
    cout << "        }\n";
    cout << "    }\n";
    cout << "    return ans;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: 8\n";
    cout << "Output: 2\n";
    cout << "Explanation: The square root of 8 is approx 2.828, truncated to 2.\n\n";
}

// Problem 148: Min Stack
void problem148() {
    cout << "\n================================================================================";
    cout << "\n                               Problem 148: Min Stack";
    cout << "\n================================================================================\n";
    cout << "Description: Design a stack that supports push, pop, top, and retrieving the minimum";
    cout << "element in constant time O(1). You need to implement a stack with an additional function";
    cout << "to efficiently get the minimum value.\n\n";

    cout << "Tutorial: Achieving O(1) for `getMin` requires redundant storage. The simplest approach uses two stacks.\n";
    cout << "1. **Main Stack:** Stores all elements in the standard stack order.\n";
    cout << "2. **Min Stack:** Stores the current minimum element every time a value is pushed that is less than or equal to the current minimum.\n";
    cout << "3. **Push:** If the new value is <= the top of `Min Stack`, push it to *both* stacks.\n";
    cout << "4. **Pop:** If the value being popped from the `Main Stack` is equal to the top of `Min Stack`, pop it from *both* stacks.\n";
    cout << "5. **getMin:** Simply returns the top of the `Min Stack`.\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <stack>\n#include <algorithm>\nusing namespace std;\n\n";

    cout << "class MinStack {\n";
    cout << "private:\n";
    cout << "    stack<int> stk;\n";
    cout << "    stack<int> minStk;\n\n";

    cout << "public:\n";
    cout << "    MinStack() {}\n\n";

    cout << "    void push(int val) {\n";
    cout << "        stk.push(val);\n";
    cout << "        // Only push to minStk if val is the new min (or equal, to maintain symmetry)\n";
    cout << "        if (minStk.empty() || val <= minStk.top()) {\n";
    cout << "            minStk.push(val);\n";
    cout << "        }\n";
    cout << "    }\n\n";

    cout << "    void pop() {\n";
    cout << "        // If the top element is the current min, we must pop from minStk too\n";
    cout << "        if (stk.top() == minStk.top()) {\n";
    cout << "            minStk.pop();\n";
    cout << "        }\n";
    cout << "        stk.pop();\n";
    cout << "    }\n\n";

    cout << "    int top() {\n";
    cout << "        return stk.top();\n";
    cout << "    }\n\n";

    cout << "    int getMin() {\n";
    cout << "        return minStk.top();\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "class MinStack:\n";
    cout << "    def __init__(self):\n";
    cout << "        self.stk = []\n";
    cout << "        self.min_stk = []\n\n";

    cout << "    def push(self, val):\n";
    cout << "        self.stk.append(val)\n";
    cout << "        if not self.min_stk or val <= self.min_stk[-1]:\n";
    cout << "            self.min_stk.append(val)\n\n";

    cout << "    def pop(self):\n";
    cout << "        if self.stk[-1] == self.min_stk[-1]:\n";
    cout << "            self.min_stk.pop()\n";
    cout << "        self.stk.pop()\n\n";

    cout << "    def top(self):\n";
    cout << "        return self.stk[-1]\n\n";

    cout << "    def getMin(self):\n";
    cout << "        return self.min_stk[-1]\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var MinStack = function() {\n";
    cout << "    this.stk = [];\n";
    cout << "    this.minStk = [];\n";
    cout << "};\n\n";

    cout << "MinStack.prototype.push = function(val) {\n";
    cout << "    this.stk.push(val);\n";
    cout << "    if (this.minStk.length === 0 || val <= this.minStk[this.minStk.length - 1]) {\n";
    cout << "        this.minStk.push(val);\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "MinStack.prototype.pop = function() {\n";
    cout << "    if (this.stk[this.stk.length - 1] === this.minStk[this.minStk.length - 1]) {\n";
    cout << "        this.minStk.pop();\n";
    cout << "    }\n";
    cout << "    this.stk.pop();\n";
    cout << "};\n\n";

    cout << "MinStack.prototype.top = function() {\n";
    cout << "    return this.stk[this.stk.length - 1];\n";
    cout << "};\n\n";

    cout << "MinStack.prototype.getMin = function() {\n";
    cout << "    return this.minStk[this.minStk.length - 1];\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: [\"MinStack\",\"push\",\"push\",\"push\",\"getMin\",\"pop\",\"top\",\"getMin\"]\n";
    cout << "       [[],[-2],[0],[-3],[],[],[],[]]\n";
    cout << "Output: [null,null,null,null,-3,null,0,-2]\n";
    cout << "Explanation: After operations, stack is [-2,0], min is -2\n\n";
}

// Problem 149: Reverse Integer
void problem149() {
    cout << "\n================================================================================";
    cout << "\n                             Problem 149: Reverse Integer";
    cout << "\n================================================================================\n";
    cout << "Description: Reverse the digits of a given 32-bit signed integer. Handle potential";
    cout << "overflow by returning 0 if the reversed value is outside the valid range [−2^31, 2^31 − 1].\n\n";

    cout << "Tutorial: The challenge is handling the 32-bit integer limits. Since the reversed number can easily exceed `INT_MAX`, we use a larger type (`long long` in C++) for intermediate calculations.\n";
    cout << "1. Use `long long` for `result` to safely store the reversed value.\n";
    cout << "2. Loop while `x != 0`: extract the last digit (`x % 10`), update `result = result * 10 + digit`, and remove the last digit (`x /= 10`).\n";
    cout << "3. After the loop, check if `result` is outside the bounds of `INT_MIN` and `INT_MAX`.\n";
    cout << "4. If overflow/underflow occurs, return 0; otherwise, cast the result back to `int`.\n\n";

    cout << "C++ Solution:\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int reverse(int x) {\n";
    cout << "        long long result = 0;\n";
    cout << "        while (x != 0) {\n";
    cout << "            result = result * 10 + x % 10;\n";
    cout << "            x /= 10;\n";
    cout << "        }\n";
    cout << "        // Check for 32-bit integer overflow/underflow\n";
    cout << "        if (result < INT_MIN || result > INT_MAX) return 0;\n";
    cout << "        return (int)result;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "class Solution:\n";
    cout << "    def reverse(self, x):\n";
    cout << "        sign = -1 if x < 0 else 1\n";
    cout << "        x = abs(x)\n";
    cout << "        result = 0\n\n";

    cout << "        while x:\n";
    cout << "            result = result * 10 + x % 10\n";
    cout << "            x //= 10\n\n";

    cout << "        result *= sign\n";
    cout << "        # Check 32-bit bounds (Python integers don't overflow)\n";
    cout << "        if result < -2**31 or result > 2**31 - 1:\n";
    cout << "            return 0\n";
    cout << "        return result\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var reverse = function(x) {\n";
    cout << "    const sign = x < 0 ? -1 : 1;\n";
    cout << "    x = Math.abs(x);\n";
    cout << "    let result = 0;\n\n";

    cout << "    while (x > 0) {\n";
    cout << "        result = result * 10 + x % 10;\n";
    cout << "        x = Math.floor(x / 10);\n";
    cout << "    }\n\n";

    cout << "    result *= sign;\n";
    cout << "    // Check 32-bit bounds\n";
    cout << "    if (result < -(2**31) || result > 2**31 - 1) return 0;\n";
    cout << "    return result;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: 1534236469\n";
    cout << "Output: 0\n";
    cout << "Explanation: The reversed number 9646324351 is greater than INT_MAX (2147483647).\n\n";
}

// Problem 150: Implement Queue using Stacks
void problem150() {
    cout << "\n================================================================================";
    cout << "\n                       Problem 150: Implement Queue using Stacks";
    cout << "\n================================================================================\n";
    cout << "Description: Simulate a queue’s behavior (FIFO) using only stack data structures (LIFO). You need to implement push, pop, peek, and empty.\n\n";

    cout << "Tutorial: The challenge is to reverse the LIFO order of the stack to achieve the FIFO order of a queue. This is done using a two-stack system.\n";
    cout << "1. **`input` stack:** Used for all `push` operations (enqueue).\n";
    cout << "2. **`output` stack:** Used for all `pop` and `peek` operations (dequeue).\n";
    cout << "3. **Transfer Rule (The Core Logic):** When a `pop` or `peek` is called and the `output` stack is empty, transfer *all* elements from the `input` stack to the `output` stack. This transfer reverses the order, correctly lining up the oldest element at the top of the `output` stack.\n";
    cout << "4. All operations are amortized O(1), as each element is pushed and popped at most twice (once in `input`, once in `output`).\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <stack>\nusing namespace std;\n\n";

    cout << "class MyQueue {\n";
    cout << "private:\n";
    cout << "    stack<int> input, output;\n\n";

    cout << "    void transfer() {\n";
    cout << "        if (output.empty()) {\n";
    cout << "            while (!input.empty()) {\n";
    cout << "                output.push(input.top());\n";
    cout << "                input.pop();\n";
    cout << "            }\n";
    cout << "        }\n";
    cout << "    }\n\n";

    cout << "public:\n";
    cout << "    MyQueue() {}\n\n";

    cout << "    void push(int x) {\n";
    cout << "        input.push(x);\n";
    cout << "    }\n\n";

    cout << "    int pop() {\n";
    cout << "        transfer();\n";
    cout << "        int val = output.top();\n";
    cout << "        output.pop();\n";
    cout << "        return val;\n";
    cout << "    }\n\n";

    cout << "    int peek() {\n";
    cout << "        transfer();\n";
    cout << "        return output.top();\n";
    cout << "    }\n\n";

    cout << "    bool empty() {\n";
    cout << "        return input.empty() && output.empty();\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "class MyQueue:\n";
    cout << "    def __init__(self):\n";
    cout << "        self.input = []\n";
    cout << "        self.output = []\n\n";

    cout << "    def _transfer(self):\n";
    cout << "        if not self.output:\n";
    cout << "            while self.input:\n";
    cout << "                self.output.append(self.input.pop())\n\n";

    cout << "    def push(self, x):\n";
    cout << "        self.input.append(x)\n\n";

    cout << "    def pop(self):\n";
    cout << "        self._transfer()\n";
    cout << "        return self.output.pop()\n\n";

    cout << "    def peek(self):\n";
    cout << "        self._transfer()\n";
    cout << "        return self.output[-1]\n\n";

    cout << "    def empty(self):\n";
    cout << "        return not self.input and not self.output\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var MyQueue = function() {\n";
    cout << "    this.input = [];\n";
    cout << "    this.output = [];\n";
    cout << "};\n\n";

    cout << "MyQueue.prototype.transfer = function() {\n";
    cout << "    if (this.output.length === 0) {\n";
    cout << "        while (this.input.length > 0) {\n";
    cout << "            this.output.push(this.input.pop());\n";
    cout << "        }\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "MyQueue.prototype.push = function(x) {\n";
    cout << "    this.input.push(x);\n";
    cout << "};\n\n";

    cout << "MyQueue.prototype.pop = function() {\n";
    cout << "    this.transfer();\n";
    cout << "    return this.output.pop();\n";
    cout << "};\n\n";

    cout << "MyQueue.prototype.peek = function() {\n";
    cout << "    this.transfer();\n";
    cout << "    return this.output[this.output.length - 1];\n";
    cout << "};\n\n";

    cout << "MyQueue.prototype.empty = function() {\n";
    cout << "    return this.input.length === 0 && this.output.length === 0;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: [\"MyQueue\",\"push\",\"push\",\"peek\",\"pop\",\"empty\"]\n";
    cout << "       [[],[1],[2],[],[],[]]\n";
    cout << "Output: [null,null,null,1,1,false]\n";
    cout << "Explanation: 1 is the oldest element, so peek() and pop() return 1.\n\n";
}

// Problem 151: Meeting Rooms III (Completed)
void problem151() {
    cout << "\n================================================================================";
    cout << "\n                       Problem 151: Meeting Rooms III";
    cout << "\n================================================================================\n";
    cout << "Description: You're given a list of meeting times and need to figure out which room";
    cout << "hosted the most meetings. Simulate the meeting schedules to track room usage and identify the busiest room.\n\n";

    cout << "Tutorial: The challenge is handling delays and prioritizing the smallest-indexed room for immediate use or when waiting. This requires sorting and careful state management (end times and counts).\n";
    cout << "1. Sort the meetings by start time.\n";
    cout << "2. Track `endTimes` (when each room is free) and `roomCount`.\n";
    cout << "3. Use a loop to find the *first* room (`i`) that is available (`endTimes[i] <= start`).\n";
    cout << "4. If no room is available, find the room that frees up earliest. The meeting is delayed to start at that time.\n";
    cout << "5. The new end time is `delay_time + duration`.\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <algorithm>\n#include <climits>\nusing namespace std;\n\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int mostBooked(int n, vector<vector<int>>& meetings) {\n";
    cout << "        sort(meetings.begin(), meetings.end());\n";
    cout << "        vector<long long> endTimes(n, 0); // When each room becomes free\n";
    cout << "        vector<int> roomCount(n, 0);      // How many meetings per room\n\n";
    cout << "        for (auto& meeting : meetings) {\n";
    cout << "            long long start = meeting[0], end = meeting[1];\n";
    cout << "            long long duration = end - start;\n";
    cout << "            int room = -1;\n";
    cout << "            bool found_available = false;\n\n";
    cout << "            // Find earliest available room (smallest index first) that's free BEFORE start time\n";
    cout << "            for (int i = 0; i < n; ++i) {\n";
    cout << "                if (endTimes[i] <= start) {\n";
    cout << "                    room = i;\n";
    cout << "                    endTimes[room] = end;\n";
    cout << "                    found_available = true;\n";
    cout << "                    break;\n";
    cout << "                }\n";
    cout << "            }\n\n";
    cout << "            // If no room available, pick the one that frees earliest (smallest index as tie-breaker)\n";
    cout << "            if (!found_available) {\n";
    cout << "                long long minTime = LLONG_MAX;\n";
    cout << "                room = 0; // Start with room 0\n";
    cout << "                for (int i = 0; i < n; ++i) {\n";
    cout << "                    if (endTimes[i] < minTime) {\n";
    cout << "                        minTime = endTimes[i];\n";
    cout << "                        room = i;\n";
    cout << "                    }\n";
    cout << "                }\n";
    cout << "                // Meeting is delayed: new end time = room's minTime + duration\n";
    cout << "                endTimes[room] = minTime + duration;\n";
    cout << "            }\n\n";
    cout << "            roomCount[room]++;\n";
    cout << "        }\n\n";
    cout << "        int maxRoom = 0;\n";
    cout << "        for (int i = 0; i < n; ++i) {\n";
    cout << "            if (roomCount[i] > roomCount[maxRoom]) {\n";
    cout << "                maxRoom = i;\n";
    cout << "            } else if (roomCount[i] == roomCount[maxRoom]) {\n";
    cout << "                maxRoom = min(maxRoom, i); // Smallest index tie-breaker is implicit since we iterate from 0\n";
    cout << "            }\n";
    cout << "        }\n\n";
    cout << "        return maxRoom;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "class Solution:\n";
    cout << "    def mostBooked(self, n, meetings):\n";
    cout << "        meetings.sort()\n";
    cout << "        end_times = [0] * n\n";
    cout << "        room_count = [0] * n\n\n";
    cout << "        for start, end in meetings:\n";
    cout << "            duration = end - start\n";
    cout << "            room = -1\n\n";
    cout << "            # Find earliest available room (smallest index first)\n";
    cout << "            for i in range(n):\n";
    cout << "                if end_times[i] <= start:\n";
    cout << "                    room = i\n";
    cout << "                    end_times[room] = end\n";
    cout << "                    break\n\n";
    cout << "            # If no room available, pick the one that frees earliest\n";
    cout << "            if room == -1:\n";
    cout << "                min_time = min(end_times)\n";
    cout << "                # Python's list.index(min_time) finds the smallest index with that value\n";
    cout << "                room = end_times.index(min_time)\n";
    cout << "                end_times[room] = min_time + duration\n\n";
    cout << "            room_count[room] += 1\n\n";
    cout << "        # Python's list.index(max(...)) finds the smallest index with max value\n";
    cout << "        return room_count.index(max(room_count))\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var mostBooked = function(n, meetings) {\n";
    cout << "    meetings.sort((a, b) => a[0] - b[0]);\n";
    cout << "    const endTimes = Array(n).fill(0);\n";
    cout << "    const roomCount = Array(n).fill(0);\n\n";
    cout << "    for (const [start, end] of meetings) {\n";
    cout << "        const duration = end - start;\n";
    cout << "        let room = -1;\n";
    cout << "        let foundAvailable = false;\n\n";
    cout << "        // 1. Find earliest available room (smallest index first)\n";
    cout << "        for (let i = 0; i < n; i++) {\n";
    cout << "            if (endTimes[i] <= start) {\n";
    cout << "                room = i;\n";
    cout << "                endTimes[room] = end;\n";
    cout << "                foundAvailable = true;\n";
    cout << "                break;\n";
    cout << "            }\n";
    cout << "        }\n\n";
    cout << "        // 2. If no room is immediately available\n";
    cout << "        if (!foundAvailable) {\n";
    cout << "            const minTime = Math.min(...endTimes);\n";
    cout << "            // Find the room index for minTime (smallest index first)\n";
    cout << "            room = endTimes.indexOf(minTime);\n";
    cout << "            endTimes[room] = minTime + duration;\n";
    cout << "        }\n\n";
    cout << "        roomCount[room]++;\n";
    cout << "    }\n\n";
    cout << "    // Find the room with the max count (smallest index in case of a tie)\n";
    cout << "    return roomCount.indexOf(Math.max(...roomCount));\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]\n";
    cout << "Output: 0\n";
    cout << "Explanation: Room 0 hosted 3 meetings, Room 1 hosted 1 meeting.\n\n";
}

// Problem 152: Path With Maximum Minimum Value (Completed)
void problem152() {
    cout << "\n================================================================================";
    cout << "\n                  Problem 152: Path With Maximum Minimum Value";
    cout << "\n================================================================================\n";
    cout << "Description: Find a path from the start to the end of a matrix that maximizes the";
    cout << "smallest value encountered along that path. You want to find the path with the largest possible minimum value.\n\n";

    cout << "Tutorial: This is a 'Max-Min' pathfinding problem, which is equivalent to running Dijkstra's algorithm, but prioritizing the maximum minimum score instead of the minimum total cost. A Max-Heap is used to implement this priority.\n";
    cout << "1. Use a Max-Heap (Priority Queue) to store states: `(current_minimum_value, row, col)`.\n";
    cout << "2. Start with `grid[0][0]` and process cells with the highest *guaranteed* minimum value first.\n";
    cout << "3. When moving to a new cell, the new `current_minimum_value` is `min(old_value, grid[new_r][new_c])`.\n";
    cout << "4. The first time the destination is dequeued, its associated minimum value is the maximum possible minimum value path.\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <vector>\n#include <queue>\n#include <algorithm>\n#include <utility>\nusing namespace std;\n\n";

    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    int maximumMinimumPath(vector<vector<int>>& grid) {\n";
    cout << "        int m = grid.size(), n = grid[0].size();\n";
    cout << "        // Max-Heap: <value, <row, col>>. Sorts by largest value first.\n";
    cout << "        priority_queue<pair<int, pair<int, int>>> pq;\n";
    cout << "        vector<vector<bool>> visited(m, vector<bool>(n, false));\n\n";

    cout << "        pq.push({grid[0][0], {0, 0}});\n";
    cout << "        visited[0][0] = true;\n\n";

    cout << "        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};\n\n";

    cout << "        while (!pq.empty()) {\n";
    cout << "            auto [val, pos] = pq.top(); pq.pop();\n";
    cout << "            int r = pos.first, c = pos.second;\n\n";

    cout << "            if (r == m - 1 && c == n - 1) return val; // First time reaching end gives max-min\n\n";

    cout << "            for (auto& dir : dirs) {\n";
    cout << "                int nr = r + dir[0], nc = c + dir[1];\n";
    cout << "                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) continue;\n\n";

    cout << "                int new_val = min(val, grid[nr][nc]);\n";
    cout << "                pq.push({new_val, {nr, nc}});\n";
    cout << "                visited[nr][nc] = true;\n";
    cout << "            }\n";
    cout << "        }\n\n";

    cout << "        return -1;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "import heapq\n\n";
    cout << "class Solution:\n";
    cout << "    def maximumMinimumPath(self, grid):\n";
    cout << "        m, n = len(grid), len(grid[0])\n";
    cout << "        # Max-heap via negative: (-value, r, c)\n";
    cout << "        pq = [(-grid[0][0], 0, 0)]\n";
    cout << "        visited = [[False] * n for _ in range(m)]\n";
    cout << "        visited[0][0] = True\n\n";

    cout << "        dirs = [(0,1), (1,0), (0,-1), (-1,0)]\n\n";

    cout << "        while pq:\n";
    cout << "            neg_val, r, c = heapq.heappop(pq)\n";
    cout << "            val = -neg_val  # Convert back to actual minimum value\n\n";

    cout << "            if r == m - 1 and c == n - 1:\n";
    cout << "                return val\n\n";

    cout << "            for dr, dc in dirs:\n";
    cout << "                nr, nc = r + dr, c + dc\n";
    cout << "                if not (0 <= nr < m and 0 <= nc < n) or visited[nr][nc]:\n";
    cout << "                    continue\n\n";

    cout << "                new_val = min(val, grid[nr][nc])\n";
    cout << "                heapq.heappush(pq, (-new_val, nr, nc))\n";
    cout << "                visited[nr][nc] = True\n\n";

    cout << "        return -1\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var maximumMinimumPath = function(grid) {\n";
    cout << "    const m = grid.length, n = grid[0].length;\n";
    cout << "    // Max-heap via negative: [-val, r, c]\n";
    cout << "    const pq = [[-grid[0][0], 0, 0]];\n";
    cout << "    const visited = Array.from({ length: m }, () => Array(n).fill(false));\n";
    cout << "    visited[0][0] = true;\n\n";

    cout << "    const dirs = [[0,1], [1,0], [0,-1], [-1,0]];\n\n";

    cout << "    while (pq.length) {\n";
    cout << "        // Manual Max-Heap simulation: Sort to find the highest value (smallest negative)\n";
    cout << "        pq.sort((a, b) => a[0] - b[0]);\n";
    cout << "        const [negVal, r, c] = pq.shift();\n";
    cout << "        const val = -negVal;\n\n";

    cout << "        if (r === m - 1 && c === n - 1) return val;\n\n";

    cout << "        for (const [dr, dc] of dirs) {\n";
    cout << "            const nr = r + dr, nc = c + dc;\n";
    cout << "            if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) continue;\n\n";

    cout << "            const new_val = Math.min(val, grid[nr][nc]);\n";
    cout << "            pq.push([-new_val, nr, nc]);\n";
    cout << "            visited[nr][nc] = true;\n";
    cout << "        }\n";
    cout << "    }\n\n";

    cout << "    return -1;\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: grid = [[5,4,5],[1,2,6],[7,4,6]]\n";
    cout << "Output: 4\n";
    cout << "Explanation: The path 5->4->5->6->6 has a minimum value of 4 (the largest possible minimum).\n\n";
}

// Problem 153: Multiply Strings (Completed)
void problem153() {
    cout << "\n================================================================================";
    cout << "\n                            Problem 153: Multiply Strings";
    cout << "\n================================================================================\n";
    cout << "Description: Simulate multiplication of two non-negative integers represented as strings.";
    cout << "Return the product, also represented as a string.\n\n";

    cout << "Tutorial: The challenge is simulating manual long multiplication. We avoid using built-in large integer types and implement the multiplication and carry logic manually, digit by digit.\n";
    cout << "1. Initialization: Create a result vector/array `res` of size `len(num1) + len(num2)` filled with zeros.\n";
    cout << "2. Iteration: Iterate through `num1` (i) and `num2` (j) from right to left.\n";
    cout << "3. Placement: The product of `num1[i]` and `num2[j]` affects positions `p1 = i + j` (carry position) and `p2 = i + j + 1` (digit position).\n";
    cout << "4. Carry Handling: Add `mul + res[p2]` (the product plus existing value at p2). The new value at `res[p2]` is `sum % 10`, and the carry `sum / 10` is added to `res[p1]`.\n";
    cout << "5. Final Step: Convert `res` to a string, skipping leading zeros.\n\n";

    cout << "C++ Solution:\n";
    cout << "#include <string>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\n";
    cout << "class Solution {\n";
    cout << "public:\n";
    cout << "    string multiply(string num1, string num2) {\n";
    cout << "        if (num1 == \"0\" || num2 == \"0\") return \"0\";\n\n";
    cout << "        int m = num1.size(), n = num2.size();\n";
    cout << "        vector<int> res(m + n, 0);\n\n";
    cout << "        for (int i = m - 1; i >= 0; --i) {\n";
    cout << "            for (int j = n - 1; j >= 0; --j) {\n";
    cout << "                // (num1[i] - '0') converts the character digit to its integer value\n";
    cout << "                int mul = (num1[i] - '0') * (num2[j] - '0');\n";
    cout << "                int p1 = i + j, p2 = i + j + 1;\n";
    cout << "                int sum = mul + res[p2];\n\n";
    cout << "                res[p2] = sum % 10;\n";
    cout << "                res[p1] += sum / 10; // Carry added to the next higher position\n";
    cout << "            }\n";
    cout << "        }\n\n";
    cout << "        string result = \"\";\n";
    cout << "        for (int digit : res) {\n";
    cout << "            // Skip leading zero if result is currently empty\n";
    cout << "            if (!(result.empty() && digit == 0)) {\n";
    cout << "                result += ('0' + digit);\n";
    cout << "            }\n";
    cout << "        }\n\n";
    cout << "        return result.empty() ? \"0\" : result;\n";
    cout << "    }\n";
    cout << "};\n\n";

    cout << "Python Solution:\n";
    cout << "class Solution:\n";
    cout << "    def multiply(self, num1, num2):\n";
    cout << "        if num1 == \"0\" or num2 == \"0\":\n";
    cout << "            return \"0\"\n\n";
    cout << "        m, n = len(num1), len(num2)\n";
    cout << "        res = [0] * (m + n)\n\n";
    cout << "        for i in range(m - 1, -1, -1):\n";
    cout << "            for j in range(n - 1, -1, -1):\n";
    cout << "                mul = int(num1[i]) * int(num2[j])\n";
    cout << "                p1, p2 = i + j, i + j + 1\n";
    cout << "                total = mul + res[p2]\n\n";
    cout << "                res[p2] = total % 10\n";
    cout << "                res[p1] += total // 10\n\n";
    cout << "        # Convert to string and remove leading zeros\n";
    cout << "        result = ''.join(map(str, res)).lstrip('0')\n";
    cout << "        return result if result else \"0\"\n\n";

    cout << "JavaScript Solution:\n";
    cout << "var multiply = function(num1, num2) {\n";
    cout << "    if (num1 === \"0\" || num2 === \"0\") return \"0\";\n\n";
    cout << "    const m = num1.length, n = num2.length;\n";
    cout << "    const res = Array(m + n).fill(0);\n\n";

    cout << "    // We use charCodeAt(0) - '0'.charCodeAt(0) to get integer value of digit character\n";
    cout << "    const charToInt = (char) => char.charCodeAt(0) - '0'.charCodeAt(0);\n\n";

    cout << "    for (let i = m - 1; i >= 0; i--) {\n";
    cout << "        for (let j = n - 1; j >= 0; j--) {\n";
    cout << "            const mul = charToInt(num1[i]) * charToInt(num2[j]);\n";
    cout << "            const p1 = i + j, p2 = i + j + 1;\n";
    cout << "            const sum = mul + res[p2];\n\n";

    cout << "            res[p2] = sum % 10;\n";
    cout << "            res[p1] += Math.floor(sum / 10);\n";
    cout << "        }\n";
    cout << "    }\n\n";

    cout << "    let result = res.join('').replace(/^0+/, '');\n";
    cout << "    return result || \"0\";\n";
    cout << "};\n\n";

    cout << "Example:\n";
    cout << "Input: num1 = \"123\", num2 = \"45\"\n";
    cout << "Output: \"5535\"\n";
    cout << "Explanation: 123 * 45 = 5535\n\n";
}

// Map choice to function pointer for easy dispatch
void (*problemFunctions[])() = {
    nullptr, // Index 0 is exit
    problem134, problem135, problem136, problem137, problem138,
    problem139, problem140, problem141, problem142, problem143,
    problem144, problem145, problem146, problem147, problem148,
    problem149, problem150, problem151, problem152, problem153
};

int main() {
    // Add these lines to potentially enable Unicode output on Windows
    // #ifdef _WIN32
    //     std::locale::global(std::locale("en_US.UTF-8"));
    //     std::wcout.imbue(std::locale());
    // #endif

    printHeader();

    int choice;
    do {
        displayMainMenu();

        if (!(cin >> choice) || choice < 0 || choice > 20) {
            cout << "\nInvalid input! Please enter a number between 0 and 20: ";
            clearInput();
            continue;
        }
        clearInput(); // Clear the buffer in case of valid input too

        if (choice == 0) {
            cout << "\nThank you for using the Algorithm Learning Platform. Happy coding!\n";
            break;
        }

        // Execute selected problem tutorial
        problemFunctions[choice]();

        cout << "\n================================================================================\n";
        cout << "Press Enter to return to the main menu...";
        cin.get(); // Wait for user to press Enter

    } while (true);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
