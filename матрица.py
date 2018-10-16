n = int (input ())
matrix = [[0]*n for i in range(n)]
for line in range (0, n):
    for i in range (0, n):
        if line < i:
            matrix[line][i] = i-line
        else:
            matrix[line][i] = 0

for row in matrix:
    print(' '.join([str(elem).rjust(len(str(n))) for elem in row]))

