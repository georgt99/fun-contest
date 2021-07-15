from sys import stdin, stdout


def solve(t, c):
    m = [[max(i, j) if min(i, j) == 0 else 0 for j in range(0, len(t) + 1)] for i in range(0, len(c) + 1)]
    for i in range(1, len(c) + 1):
        for j in range(1, len(t) + 1):
            m[i][j] = min(m[i - 1][j] + 1,
                          m[i][j - 1] + 1,
                          m[i - 1][j - 1] + (t[j - 1] != c[i - 1]))

    path = []
    while (i, j) != (0, 0):
        op = min(o for o in ((m[i][j - 1], 1, 0, 1, 'd'), (m[i - 1][j], 1, 1, 0, 'i'), (m[i - 1][j - 1], 0, 1, 1, 'r')) if i-o[2]>=0 and j-o[3]>=0)
        if op[0] < m[i][j]:
            path.append(op[-1])
        i, j = i - op[2], j - op[3]
    return str(m[-1][-1]) + ' ' + 'i' * (i-1) + 'd' * (j-1) + ''.join(reversed(path))


for i in range(int(stdin.readline())):
    t, c = stdin.readline().split()
    stdout.write(str(solve(t, c))+'\n')
