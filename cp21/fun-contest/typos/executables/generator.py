import random
from pathlib import Path

random.seed(-7823741605153995847)

# for randomly generated input
MAX_LEN = 1000
TESTCASES = 10


Path('sample.in').write_text(
    '6\n' +
    'awful awesome\n' +
    'abcde bcxef\n' +
    'delete dlt\n' +
    'nsrt insert\n' +
    'replace letters\n' +
    'nothingtodohere nothingtodohere\n'
)
Path('sample.desc').write_text('some base cases\n')


Path('words.in').write_text(
    '10\n' +
    'disslexia dyslexia\n' +
    'sufrutiscant suffrutescent\n' +
    'antrophomorphise anthropomorphize\n' +
    'gradnilockwent grandiloquent\n' +
    'multitoutinuous multitudinous\n' +
    'descomboubulate discombobulate\n' +
    'levenstein levenshtein\n' +
    'incombrehensiblitys incomprehensibilities\n' +
    'mispelt misspelled\n' +
    'superkalyfragilisstickexpeealidecius supercalifragilisticexpialidocious\n'
)
Path('words.desc').write_text('more words to practice your spelling\n')


def add_typos(s, num_delete, num_insert, num_replace):
    assert num_delete + num_insert + num_replace <= len(s)
    ops = [0]*(len(s)-num_delete-num_insert-num_replace) + [1]*num_delete + [2]*num_insert + [3]*num_replace
    random.shuffle(ops)
    t = [c for c in s]
    for i in range(len(s)):
        if ops[i] == 1:
            t[i] = ''
        elif ops[i] == 2:
            t.insert(i, chr(97+random.randrange(26)))
        elif ops[i] == 3:
            t[i] = chr(97+random.randrange(26))
    return ''.join(t)


txt = str(TESTCASES)+'\n'
for t in range(TESTCASES):
    l = random.randrange(1, MAX_LEN)
    r = random.randrange(l)
    d = random.randrange(l-r-1) if l-r-1 > 0 else 0
    i = random.randrange(l-r-d) if l-r-d > 0 else 0
    while i+l-d > MAX_LEN:
        l = random.randrange(1, MAX_LEN)
        r = random.randrange(l)
        d = random.randrange(l - r - 1) if l - r - 1 > 0 else 0
        i = random.randrange(l - r - d) if l - r - d > 0 else 0
    s = ''.join(chr(97+random.randrange(26)) for _ in range(l))
    txt += s+' '+add_typos(s, d, i, r)+'\n'
Path('random.in').write_text(txt)
Path('random.desc').write_text('some long randomly misspelled strings\n')
