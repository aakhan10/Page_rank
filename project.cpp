// PageRank Implementation in C++
// Author: Anwaar Khan
// Description: Computes PageRank scores for a directed graph
// Usage: Compile using a C++ compiler (e.g., g++ pagerank.cpp -o pagerank) and run ./pagerank
// Modify input mode in main() to use file or manual test cases

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

const double DAMPING = 0.85;
const double EPSILON = 1e-6;
const int MAX_ITER = 100;

typedef vector<vector<int>> AdjacencyMatrix;
typedef vector<vector<double>> TransitionMatrix;
typedef vector<double> RankVector;

// Converts an adjacency matrix to a column-stochastic transition matrix
TransitionMatrix buildTransitionMatrix(const AdjacencyMatrix& A) {
    int n = A.size();
    TransitionMatrix M(n, vector<double>(n, 0.0));

    for (int j = 0; j < n; ++j) {
        int outDegree = 0;
        for (int i = 0; i < n; ++i) {
            outDegree += A[i][j];
        }

        if (outDegree == 0) {
            for (int i = 0; i < n; ++i) {
                M[i][j] = 1.0 / n; // Handle dangling node
            }
        } else {
            for (int i = 0; i < n; ++i) {
                M[i][j] = static_cast<double>(A[i][j]) / outDegree;
            }
        }
    }

    return M;
}

// Performs the PageRank power iteration until convergence
RankVector computePageRank(const TransitionMatrix& M) {
    int n = M.size();
    RankVector R(n, 1.0 / n);
    RankVector R_new(n);

    for (int iter = 0; iter < MAX_ITER; ++iter) {
        for (int i = 0; i < n; ++i) {
            R_new[i] = 0.0;
            for (int j = 0; j < n; ++j) {
                R_new[i] += DAMPING * M[i][j] * R[j];
            }
            R_new[i] += (1.0 - DAMPING) / n;
        }

        double diff = 0.0;
        for (int i = 0; i < n; ++i) {
            diff += fabs(R_new[i] - R[i]);
            R[i] = R_new[i];
        }

        if (diff < EPSILON) break;
    }

    return R;
}

// Displays the PageRank vector
void printRanks(const RankVector& R) {
    cout << fixed << setprecision(6);
    for (size_t i = 0; i < R.size(); ++i) {
        cout << "Node " << i << ": " << R[i] << endl;
    }
}

int main() {
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    AdjacencyMatrix A(n, vector<int>(n));

    cout << "Enter adjacency matrix (" << n << " x " << n << ") row by row:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    TransitionMatrix M = buildTransitionMatrix(A);
    RankVector R = computePageRank(M);

    cout << "\nFinal PageRank Scores:\n";
    printRanks(R);

    return 0;
}
