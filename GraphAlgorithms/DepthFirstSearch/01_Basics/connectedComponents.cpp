/**
 * @author Xin Li <helloimlixin@gmail.com>
 * @file Description
 * @desc Created on 2020-03-18 2:45:15 am
 * @copyright Mr. Xin Li
 */

#include <iostream>
#include <vector>
#include <stack>

#define MAX_VERTEX_COUNT 10

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::stack;

vector<int> adjacencyLists[MAX_VERTEX_COUNT];
bool visited[MAX_VERTEX_COUNT];

// DFS-RECURSIVE
void dfsRecursive(int src) {
    visited[src] = true;
    for (size_t w = 0; w < adjacencyLists[src].size(); w++) {
        if (visited[adjacencyLists[src][w]] == false) {
            dfsRecursive(adjacencyLists[src][w]);
        }
    }
}

// DFS-ITERATIVE
void dfsIterative(int src) {
    // Initialize a Stack data structure.
    stack<int> S;
    S.push(src);
    visited[src] = true;
    while (!S.empty()) {
        // C++ Guiding Principle: you don't pay for what you do not need.
        int v = S.top();
        S.pop();
        for (size_t w = 0; w < adjacencyLists[v].size(); w++) {
            if (visited[w] == false) {
                S.push(w);
                visited[w] = true;
            }
        }
    }
}

// Initialization step, takes O(n) runtime.
void initialize() {
    for (size_t i = 0; i < 10; i++) {
        visited[i] = false;
    }
}

/**
 * Driver code.
 * Sample Input:
 * 6
 * 4
 * 1 2
 * 2 3
 * 1 3
 * 4 5
 * where the first line denotes the number of vertices V, the second line
 * denotes the number of edges E, the following E lines denote edges.
 */
int main() {
    int V, E, x, y, connectedComponents = 0;
    cin >> V;
    cin >> E;
    for (size_t i = 0; i < E; i++) {
        cin >> x >> y;
        // For undirected graph.
        adjacencyLists[x].push_back(y);
        adjacencyLists[y].push_back(x);
    }
    initialize();  // initialize all vertices as not visited
    for (size_t i = 0; i < V; i++) {
        if (visited[i] == false) {
            dfsRecursive(i);
            connectedComponents++;
        }
    }
    cout << "Number of connected components: " << connectedComponents << endl;

    return 0;
}
