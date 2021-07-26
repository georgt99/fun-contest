n = int(input())

for _ in range(n):
    t, c = input().split()

    dp = [[(0, "")] * (len(t) + 1) for _ in range(len(c) + 1)]
    for i in range(1, len(t) + 1):
        dp[0][i] = (i, "d")
    for j in range(1, len(c) + 1):
        dp[j][0] = (j, "i")
        for i in range(1, len(t) + 1):
            dp[j][i] = min([(dp[j-1][i][0] + 1, "i"), (dp[j][i-1][0] + 1, "d"), (dp[j-1][i-1][0] + 1, "r")])
            if t[i-1] == c[j-1]:
                dp[j][i] = min(dp[j][i], (dp[j-1][i-1][0], ""))

    ops = []
    i = len(t)
    j = len(c)
    while (j, i) != (0, 0):
        op = dp[j][i][1]
        ops.append(op)
        dj, di = {"r": (-1, -1), "d": (0, -1), "i": (-1, 0), "": (-1, -1)}[op]
        i += di
        j += dj
    ops = "".join(ops[::-1])
    print(len(ops), ops)
