#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void isItPosibleToReachFrom(vector<vector<int>>& nodes, int start, vector<bool>& reachableValues) {

    queue<int> nodesLeftToCheck;
    nodesLeftToCheck.push(start);

    reachableValues[start] = true;

    int tempNode = 0;
    int tempTransversalNode = 0;

    while (!nodesLeftToCheck.empty()) {

        tempNode = nodesLeftToCheck.front();
        nodesLeftToCheck.pop();

        for (int i = 0; i < nodes[tempNode].size(); i++) {

            tempTransversalNode = nodes[tempNode][i];

            if (!reachableValues[tempTransversalNode]) {

                reachableValues[tempTransversalNode] = true;
                nodesLeftToCheck.push(tempTransversalNode);

            }

        }

    }

}

int main() {

    int amountOfRestaurantes = 0;
    int amountOfLinesToProccess = 0;

    vector<vector<int>> nodes(amountOfRestaurantes, vector<int>(0));
    vector<vector<int>> nodesReversed(amountOfRestaurantes, vector<int>(0));

    int nodeToAdd = 0;
    int nodeToAddTo = 0;

    cin >> amountOfRestaurantes >> amountOfLinesToProccess

    for (int i = 0; i < amountOfLinesToProccess; i++) {

        cin >> nodeToAddTo >> nodeToAdd;

        nodes[nodeToAddTo - 1].push_back(nodeToAdd - 1);
        nodesReversed[nodeToAdd - 1].push_back(nodeToAddTo - 1);

    }

    int cases = 0;
    cin >> cases;

    for (int i = 0; i < cases; i++) {

        int startingNode = 0;
        int endingNode = 0;

        vector<bool> reachableValuesFromStart(amountOfRestaurantes, false);
        vector<bool> reachableValuesFromEnd(amountOfRestaurantes, false);

        int amountOfRestauratesWhichNeedToBeOpen = 0;

        cin >> startingNode >> endingNode;
        startingNode--;
        endingNode--;

        isItPosibleToReachFrom(nodes, startingNode, reachableValuesFromStart);
        isItPosibleToReachFrom(nodesReversed, endingNode, reachableValuesFromEnd);

        if (!reachableValuesFromStart[endingNode]) {

            cout << "IMPOSIBLE\n";
            continue;

        }

        for (int j = 0; j < amountOfRestaurantes; j++) {

            if (reachableValuesFromStart[j] && reachableValuesFromEnd[j]) {

                amountOfRestauratesWhichNeedToBeOpen++;

            }

        }

        cout << amountOfRestauratesWhichNeedToBeOpen << "\n";

    }

    cout << "---\n";

}

return 0;

}
