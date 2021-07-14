from pathlib import Path

SAMPLES = [
    ['sample1','3\nmeow\nmeeeeeoooow\nmeeooooooooooooow\n'],
    ['testcase1','1\nm'+'e'*20+'o'*70+'w'],
    ['testcase2','1\nm'+'e'*1000+'o'*1000+'w\n'],
    ['testcase3','1\nm'+'e'*100000+'o'*100000+'w\n'],
    ['testcase4','1\nm'+'e'*1000000+'o'*1000000+'w\n'],
]


for name, s in SAMPLES:
    Path(name + '.in').write_text(s+'\n')
    Path(name + '.desc').write_text(name+'\n')