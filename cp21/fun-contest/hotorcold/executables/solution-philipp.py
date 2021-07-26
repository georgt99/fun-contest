def query(diff, x_dir):
    if x_dir:
        if diff > 0:
            print("e", diff)
        else:
            print("w", -diff)
    else:
        if diff > 0:
            print("n", diff)
        else:
            print("s", -diff)
    ans = input()
    if ans == "found":
        exit()
    return ans == "hot"


# Search in x, then y
for x_dir in [True, False]:
    lo = -512
    hi = 512
    cur = 0

    # Find correct position by binary search
    while lo < hi:
        target_split = (lo+hi) // 2
        new_pos = cur + (target_split - cur) * 2 + 1

        is_closer = query(new_pos - cur, x_dir=x_dir)
        if is_closer == (new_pos > cur):
            lo = target_split + 1
        else:
            hi = target_split

        cur = new_pos
    # Move to correct position if necessary
    if cur != lo:
        query(lo - cur, x_dir=x_dir)
