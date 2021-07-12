from pathlib import Path
import random as r

TESTCASES = [
    ('sample1',
     """2 2
++
--
""", 'Sample 2x2'),
    ('sample2',
     """3 2
+0-
-++
""", 'Sample 2x3 with 0 and crossing'),
    ('sample3',
     """13 8
--+----+-----
-------+++---
-++++----0---
-+--++--+++--
-+--++--+++--
----------0--
-------++++--
-------++----
    """, 'Bigger Sample'),
]

for name, in_data, description in TESTCASES:
    Path(name + '.in').write_text(in_data + '\n')
    Path(name + '.desc').write_text(description + '\n')

for i in range(1, 21):
    w = r.randint(1, 1000)
    h = r.randint(1, 1000)
    sample = str(w) + ' ' + str(h) + '\n'
    for _ in range(h):
        for _ in range(w):
            rnd = r.randint(1, 3)
            if (rnd == 1):
                tile = "+"
            elif (rnd == 2):
                tile = "-"
            else:
                tile = "0"
            sample += tile
        sample += "\n"

    Path('random' + str(i) + '.in').write_text(sample)

    Path('random' + str(i) + '.desc').write_text('random testcase ' + str(i) + '\n')

w = 1000
h = 1000
sample = str(w) + ' ' + str(h) + '\n'
for _ in range(h):
    for _ in range(w):
        rnd = r.randint(1, 3)
        if (rnd == 1):
            tile = "+"
        elif (rnd == 2):
            tile = "-"
        else:
            tile = "0"
        sample += tile
    sample += "\n"

Path('random1000x1000.in').write_text(sample)

Path('random1000x1000.desc').write_text('Random 1000x1000 sample \n')


w = 1000
h = 1000
for i in range(1,4):
    sample = str(w) + ' ' + str(h) + '\n'
    for _ in range(h):
        for _ in range(w):
            if (i == 1):
                tile = "+"
            elif (i == 2):
                tile = "-"
            else:
                tile = "0"
            sample += tile
        sample += "\n"

    Path(f'single_filled{i}.in').write_text(sample)

    Path(f'single_filled{i}.desc').write_text(f'Only ({tile}) tiles used\n')
