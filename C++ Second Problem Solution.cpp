#include <iostream>
#include <queue>

using namespace std;

struct registers {

    int idNumber;
    int amountOfTimeRemaining;

    bool operator<(const registers& other) const {

        if (amountOfTimeRemaining == other.amountOfTimeRemaining) {

            return idNumber > other.idNumber;

        }

        return amountOfTimeRemaining > other.amountOfTimeRemaining;

    }

};

void getInfo (priority_queue<registers> &cajasDelSuper, queue<int> &remainingCustomers, int cantidadDeCajas, int amountOfCustomers) {

    int limbo;
    registers tempCaja;

    for (int i = 0; i < cantidadDeCajas; i++) {

        tempCaja.amountOfTimeRemaining = 0;
        tempCaja.idNumber = i;

        cajasDelSuper.push(tempCaja);

    }

    for (int i = 0; i < amountOfCustomers; i++) {

        cin >> limbo;
        remainingCustomers.push(limbo);

    }

}

int wait(priority_queue<registers> &registersInTheSuper, queue<int> &remainingCustomers) {

    registers tempRegister;

    tempRegister = registersInTheSuper.top();
    registersInTheSuper.pop();

    tempRegister.amountOfTimeRemaining += remainingCustomers.front();
    registersInTheSuper.push(tempRegister);

    remainingCustomers.pop();

    return tempRegister.idNumber;

}

vector<int> solveCases() {

    vector<int> answer;

    while (true) {

        priority_queue<registers> registersInTheSuper;
        queue<int> remainingCustomers;

        int amountOfRegisters;
        int amountOfCustomers;

        cin >> amountOfRegisters;
        cin >> amountOfCustomers;

        if (amountOfCustomers == 0 && amountOfRegisters == 0) {
            return answer;
        }

        getInfo(registersInTheSuper, remainingCustomers, amountOfRegisters, amountOfCustomers);

        int queueSize = remainingCustomers.size();

        for (int i = 0; i < queueSize; i++) {

            wait(registersInTheSuper, remainingCustomers);

        }

        answer.push_back(registersInTheSuper.top().idNumber + 1);

    }

}

int main() {

    vector<int> output;

    output = solveCases();

    for (int number : output) {
        cout << number << "\n";
    }

}
