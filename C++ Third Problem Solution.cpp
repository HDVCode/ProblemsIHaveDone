#include <iostream>
#include <vector>

using namespace std;

bool areThereZeros (vector<vector<int>>& buffer) {
    for (int i = 0; i < buffer.size(); i++) {
        for (int j = 0; j < buffer[0].size(); j++) {
            if (buffer[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}

void floodFill (vector<vector<int>>& buffer, pair<int, int> pos) {


    if (buffer[pos.first][pos.second] == 0) {
        buffer[pos.first][pos.second] = 2;
    } else {
        return;
    }

    if (pos.first + 1 < buffer.size() && buffer[pos.first + 1][pos.second] == 0) {
        floodFill (buffer, make_pair(pos.first + 1, pos.second));
    }

    if (pos.second + 1 < buffer[0].size() && buffer[pos.first][pos.second + 1] == 0) {
        floodFill (buffer, make_pair(pos.first, pos.second + 1));
    }

    if (pos.second - 1 >= 0 && buffer[pos.first][pos.second - 1] == 0) {
        floodFill (buffer, make_pair(pos.first, pos.second - 1));
    }

    if (pos.first - 1 >= 0 && buffer[pos.first - 1][pos.second] == 0) {
        floodFill (buffer, make_pair(pos.first - 1, pos.second));
    }

}

int main() {

    int x;
    int y;

    string limbo;

    cin >> x >> y;

    vector<vector<int>> buffer(y, vector<int>(x));

    for (int i = 0; i < y; i++) {
        
        cin >> limbo;
        
        for (int j = 0; j < x; j++) {

            if (limbo[j] == '.') buffer[i][j] = 0;
            if (limbo[j] == 'X') buffer[i][j] = 1;
        }

    }

    floodFill(buffer, make_pair(0, 0));

    if (areThereZeros(buffer)) cout << "Yes" << "\n";
    else cout << "No" << "\n";

}
