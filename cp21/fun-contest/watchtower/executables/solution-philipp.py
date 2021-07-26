n, m = map(int, input().split())

edges = []
for _ in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    edges.append((x, y))

best = n
for bs in range(1 << n):
    for x, y in edges:
        if not (bs & (1 << x) or (bs & (1 << y))):
            break
    else:
        best = min(best, bin(bs).count("1"))
print(best)
