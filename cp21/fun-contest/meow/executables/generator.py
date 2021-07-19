import random
from pathlib import Path

random.seed(-837120128602079247)

def makeMeow(count):
    for i in range(count):
        yield 'm'+'e'*random.randint(100000,200000)+'o'*random.randint(100000,200000)+'w'


SAMPLES = [
    ['sample1','3\nmeow\nmeeeeeoooow\nmeeooooooooooooow\n'],
    ['testcase1','3\nm'+'e'*20+'o'*70+'w\n'+'m'+'e'*1000+'o'*1000+'w\n'+'m'+'e'*100000+'o'*100000+'w\n'],
    [
        'testcase2',
        '10\n' + '\n'.join([m for m in makeMeow(10)])
    ],
    [
        'testcase3',
        '50\n' + '\n'.join([m for m in makeMeow(50)])
    ],
]

for name, s in SAMPLES:
    Path(name + '.in').write_text(s+'\n')
    Path(name + '.desc').write_text(name+'\n')