import sys
from collections import deque

def isItPosibleToReachFrom(nodes, start, reachableValues):

    nodesLeftToCheck = deque()
    nodesLeftToCheck.append(start)

    reachableValues[start] = True

    while len(nodesLeftToCheck) > 0:

        tempNode = nodesLeftToCheck.popleft()

        for i in range(len(nodes[tempNode])):

            tempTransversalNode = nodes[tempNode][i]

            if reachableValues[tempTransversalNode] == False:

                reachableValues[tempTransversalNode] = True
                nodesLeftToCheck.append(tempTransversalNode)


while True:

    line = sys.stdin.readline()

    if line == "":

        break

    parts = line.strip().split()

    if len(parts) == 0:
        continue

    amountOfRestaurantes = int(parts[0])
    amountOfLinesToProccess = int(parts[1])

    nodes = []

    for i in range(amountOfRestaurantes):

        nodes.append([])

    nodesReversed = []

    for i in range(amountOfRestaurantes):

        nodesReversed.append([])

    for i in range(amountOfLinesToProccess):

        inputLine = sys.stdin.readline().split()
        nodeToAddTo = int(inputLine[0])
        nodeToAdd = int(inputLine[1])

        nodes[nodeToAddTo - 1].append(nodeToAdd - 1)
        nodesReversed[nodeToAdd - 1].append(nodeToAddTo - 1)

    casesLine = sys.stdin.readline()
    cases = int(casesLine)

    for i in range(cases):

        inputLine = sys.stdin.readline().split()
        startingNode = int(inputLine[0]) - 1
        endingNode = int(inputLine[1]) - 1

        reachableValuesFromStart = [False] * amountOfRestaurantes
        reachableValuesFromEnd = [False] * amountOfRestaurantes

        isItPosibleToReachFrom(nodes, startingNode, reachableValuesFromStart)
        isItPosibleToReachFrom(nodesReversed, endingNode, reachableValuesFromEnd)

        if reachableValuesFromStart[endingNode] == False:

            print("IMPOSIBLE")

        else:

            amountOfRestauratesWhichNeedToBeOpen = 0

            for j in range(amountOfRestaurantes):

                if reachableValuesFromStart[j] == True:

                    if reachableValuesFromEnd[j] == True:

                        amountOfRestauratesWhichNeedToBeOpen = amountOfRestauratesWhichNeedToBeOpen + 1

            print(amountOfRestauratesWhichNeedToBeOpen)

    print("---")
