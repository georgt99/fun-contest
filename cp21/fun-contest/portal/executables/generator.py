from math import ceil
from pathlib import Path
import random as r

MAX_NODES = 1000000
PROBLEM_SIZES = {100, 1000, 10000, MAX_NODES}

# public inputs

Path('sample1.in').write_text(
    '3\n'+
    '0 1\n'+
    '1 2\n'+
    '2 3\n'
)
Path('sample1.desc').write_text('straight line\n')

Path('sample2.in').write_text(
    '4\n'+
    '0 1\n'+
    '3 2\n'+
    '0 2\n'+
    '2 4\n'
)
Path('sample2.desc').write_text('possible chamber with 5 rooms\n')

Path('sample3.in').write_text(
    '7\n'+
    '0 1\n'+
    '1 4\n'+
    '4 5\n'+
    '4 7\n'+
    '0 3\n'+
    '3 2\n'+
    '3 6\n'
)
Path('sample3.desc').write_text('impossible chamber with 8 rooms\n')


# secret inputs

Path('singleNodeInGraph.in').write_text(
    '0\n'
)
Path('singleNodeInGraph.desc').write_text('starting room is the only room\n')

# random possible instances
for n in PROBLEM_SIZES:
    input_text = ""
    input_text += str(n) + '\n'
    current_parent = 0
    remaining_nodes = list(range(1, n))
    r.shuffle(remaining_nodes)
    while len(remaining_nodes) > 0:
        fan_size = r.randint(1, len(remaining_nodes))
        fan_nodes = remaining_nodes[0:fan_size]
        remaining_nodes = remaining_nodes[fan_size:]

        num_subtrees = r.randint(1, ceil(fan_size / 2))
        subtrees = [fan_nodes[i::num_subtrees] for i in range(num_subtrees)]
        for sub in subtrees:
            input_text += f'{current_parent} {sub[0]}\n'
            for x in range(len(sub)-1):
                input_text += f'{sub[x]} {sub[x+1]}\n'
        current_parent = fan_nodes[r.randint(1, fan_size) - 1]
        
    Path('randomPossibleWith' + str(n) + 'nodes.in').write_text(input_text)
    Path('randomPossibleWith' + str(n) + 'nodes.desc').write_text('random possible chamber with ' + str(n) + ' nodes\n')


# random impossible instances
for n in PROBLEM_SIZES:
    was_blocking_node_used = False
    input_text = ""
    while not was_blocking_node_used: # this is a super ugly quickfix: the blocking node is sometimes not added, so we just try again
        input_text = ""
        input_text += str(n) + '\n'
        current_parent = 0
        remaining_nodes = list(range(1, n))
        blocking_node = n
        
        r.shuffle(remaining_nodes)
        while len(remaining_nodes) > 0:
            fan_size = r.randint(1, ceil(len(remaining_nodes) / 2))
            fan_nodes = remaining_nodes[0:fan_size]
            remaining_nodes = remaining_nodes[fan_size:]
            
            num_subtrees = r.randint(1, ceil(fan_size / 2))
            subtrees = [fan_nodes[i::num_subtrees] for i in range(num_subtrees)]
            for sub in subtrees:
                input_text += f'{current_parent} {sub[0]}\n'
                for x in range(len(sub)-1):
                    input_text += f'{sub[x]} {sub[x+1]}\n'
            
            extendable_subtrees = [x for x in subtrees if len(x) > 1]
            if len(extendable_subtrees) > 0:
                next_subtree = r.choice(extendable_subtrees)
                extendable_subtrees.remove(next_subtree)
                current_parent = next_subtree[r.randint(1, len(next_subtree)) - 1]

                if len(extendable_subtrees) > 0 and not was_blocking_node_used:
                    blocking_subtree = r.choice(extendable_subtrees)
                    input_text += f'{blocking_subtree[r.randint(0, len(blocking_subtree)-2)]} {blocking_node}\n'
                    was_blocking_node_used = True


    Path('randomImpossibleWith' + str(n) + 'nodes.in').write_text(input_text)
    Path('randomImpossibleWith' + str(n) + 'nodes.desc').write_text('random impossible chamber with ' + str(n) + ' nodes\n')
