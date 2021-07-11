from pathlib import Path
import random as r

MIN_X = 0
MIN_Y = 0

MAX_X = 2048
MAX_Y = 2048

SAMPLES = [
    ['sample1', "512 1024"],
]

for name, s in SAMPLES:
    Path(name + '.in').write_text(s+'\n')
    Path(name + '.desc').write_text(name+'\n')

TESTCASES = [
    ['top-left', "0 1024"],
    ['top-right', "1024 1024"],
    ['bottom-left', "0 0"],
    ['bottom-right', "1024 0"],
    ['initial-spot', "512 512"],
]

for desc, s in TESTCASES:
    Path(desc + '.in').write_text(s+'\n')
    Path(desc + '.desc').write_text(desc+'\n')

for i in range(1,21):
    Path('random' + str(i) + '.in').write_text(str(r.randint(MIN_X, MAX_X)) + ' ' + str(r.randint(MIN_Y, MAX_Y)) + '\n')
    Path('random' + str(i) + '.desc').write_text('random testcase ' + str(i) + '\n')