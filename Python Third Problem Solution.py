def areThereZeros(buffer):

    i = 0
    while i < len(buffer):

        j = 0

        while j < len(buffer[0]):

            if buffer[i][j] == 0:
                return True

            j = j + 1
            
        i = i + 1

    return False


def floodFill(buffer, pos):

    if buffer[pos[0]][pos[1]] == 0:

        buffer[pos[0]][pos[1]] = 2

    else:

        return

    if pos[0] + 1 < len(buffer):

        if buffer[pos[0] + 1][pos[1]] == 0:

            floodFill(buffer, (pos[0] + 1, pos[1]))

    if pos[1] + 1 < len(buffer[0]):

        if buffer[pos[0]][pos[1] + 1] == 0:

            floodFill(buffer, (pos[0], pos[1] + 1))

    if pos[1] - 1 >= 0:

        if buffer[pos[0]][pos[1] - 1] == 0:

            floodFill(buffer, (pos[0], pos[1] - 1))

    if pos[0] - 1 >= 0:

        if buffer[pos[0] - 1][pos[1]] == 0:

            floodFill(buffer, (pos[0] - 1, pos[1]))


x, y = map(int, input().split())

buffer = []

i = 0

while i < y:

    limbo = input().strip()

    row = []
    j = 0

    while j < x:

        if limbo[j] == '.':

            row.append(0)

        if limbo[j] == 'X':

            row.append(1)

        j = j + 1

    buffer.append(row)
    i = i + 1

floodFill(buffer, (0, 0))

if areThereZeros(buffer) == True:

    print("Yes")

else:

    print("No")
