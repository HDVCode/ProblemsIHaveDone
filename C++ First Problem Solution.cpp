#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void isItPosibleToReachFrom(vector<vector<int>>& nodes, int start, vector<bool>& reachableValues) {

    queue<int> nodesLeftToCheck;
    nodesLeftToCheck.push(start);
    reachableValues[start] = true;

    while (!nodesLeftToCheck.empty()) {

        int tempNode = nodesLeftToCheck.front();
        nodesLeftToCheck.pop();

        for (int nxt : nodes[tempNode]) {
            if (!reachableValues[nxt]) {
                reachableValues[nxt] = true;
                nodesLeftToCheck.push(nxt);
            }
        }
    }
}

int main() {

    int amountOfRestaurantes = 0;
    int amountOfLinesToProccess = 0;

    cin >> amountOfRestaurantes >> amountOfLinesToProccess;
    if (!cin) return 0; 

    vector<vector<int>> nodes(amountOfRestaurantes);
    vector<vector<int>> nodesReversed(amountOfRestaurantes);

    for (int i = 0; i < amountOfLinesToProccess; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a-1].push_back(b-1);
        nodesReversed[b-1].push_back(a-1);
    }

    int cases = 0;
    cin >> cases;

    for (int i = 0; i < cases; i++) {

        int startingNode, endingNode;
        cin >> startingNode >> endingNode;

        startingNode--;
        endingNode--;

        vector<bool> reachableFromStart(amountOfRestaurantes, false);
        vector<bool> reachableFromEnd(amountOfRestaurantes, false);

        isItPosibleToReachFrom(nodes, startingNode, reachableFromStart);
        isItPosibleToReachFrom(nodesReversed, endingNode, reachableFromEnd);

        if (!reachableFromStart[endingNode]) {
            cout << "IMPOSIBLE\n";
            continue;
        }

        int result = 0;

        for (int j = 0; j < amountOfRestaurantes; j++) {
            if (reachableFromStart[j] && reachableFromEnd[j])
                    result++;
        }

        cout << result << "\n";
    }

    cout << "---\n";

    return 0;
}
