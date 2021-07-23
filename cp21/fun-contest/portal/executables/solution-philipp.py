n = int(input()) + 1

adj = [[] for _ in range(n)]

for _ in range(n - 1):
    u, v = map(int, input().split())

    adj[u].append(v)
    adj[v].append(u)


def possible():
    par = [-1] * n
    depth = [0] * n
    q = [0]

    while q:
        v = q.pop()
        for nei in adj[v]:
            if nei == par[v]:
                continue
            par[nei] = v
            depth[nei] = depth[v] + 1
            q.append(nei)

    splits = [v for v in range(n) if len(adj[v]) >= 3]
    if not splits:
        return True
    cur = max(splits, key=lambda v: depth[v])
    seen = {cur}
    while cur != 0:
        cur = par[cur]
        seen.add(cur)

    return seen.issuperset(set(splits))


if possible():
    print("THERE WILL BE CAKE")
else:
    print("THE CAKE IS A LIE")
