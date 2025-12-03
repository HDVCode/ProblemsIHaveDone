import heapq
import sys

class registers:

    def __init__(self):
        self.idNumber = 0
        self.amountOfTimeRemaining = 0

    def __lt__(self, other):

        if self.amountOfTimeRemaining == other.amountOfTimeRemaining:

            if self.idNumber < other.idNumber:

                return True

            else:

                return False

        if self.amountOfTimeRemaining < other.amountOfTimeRemaining:

            return True

        else:

            return False


def getInfo(cajasDelSuper, remainingCustomers, cantidadDeCajas, amountOfCustomers):

    limbo = 0
    tempCaja = registers()

    i = 0
    while i < cantidadDeCajas:

        tempCaja = registers()
        tempCaja.amountOfTimeRemaining = 0
        tempCaja.idNumber = i

        heapq.heappush(cajasDelSuper, tempCaja)

        i = i + 1

    customerLine = sys.stdin.readline().split()

    i = 0

    while i < amountOfCustomers:

        limbo = int(customerLine[i])
        remainingCustomers.append(limbo)

        i = i + 1


def wait(registersInTheSuper, remainingCustomers):

    tempRegister = heapq.heappop(registersInTheSuper)

    tempRegister.amountOfTimeRemaining = tempRegister.amountOfTimeRemaining + remainingCustomers[0]
    heapq.heappush(registersInTheSuper, tempRegister)

    remainingCustomers.pop(0)

    return tempRegister.idNumber


def solveCases():

    answer = []

    while True:

        registersInTheSuper = []
        remainingCustomers = []

        line = sys.stdin.readline().split()
        amountOfRegisters = int(line[0])
        amountOfCustomers = int(line[1])

        if amountOfCustomers == 0 and amountOfRegisters == 0:
            return answer

        getInfo(registersInTheSuper, remainingCustomers, amountOfRegisters, amountOfCustomers)

        queueSize = len(remainingCustomers)

        i = 0
        while i < queueSize:

            wait(registersInTheSuper, remainingCustomers)

            i = i + 1

        topRegister = heapq.heappop(registersInTheSuper)
        answer.append(topRegister.idNumber + 1)


def main():

    output = solveCases()

    for number in output:
        print(number)


main()



