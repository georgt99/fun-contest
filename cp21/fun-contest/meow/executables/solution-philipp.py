MAX_N = 2 * 10**6

counts = [0] * (MAX_N + 1)

for i in range(1, MAX_N + 1):
    s = i + i + 1
    j = i + 2
    while s <= MAX_N:
        counts[s] += 1
        s += j
        j += 1

t = int(input())

for _ in range(t):
    s = input()
    n = s.count("e") + s.count("o")

    print(counts[n])
