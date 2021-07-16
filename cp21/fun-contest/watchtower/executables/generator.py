import random
from pathlib import Path

random.seed(-1723868745248908682)

MAX_NODES = 20

Path('sample1.in').write_text(
    '5 3\n'+
    '1 2\n'+
    '1 3\n'+
    '1 4\n'
)
Path('sample1.desc').write_text('Sample with Solution 1\n')

Path('sample2.in').write_text(
    '4 3\n'+
    '3 2\n'+
    '1 2\n'+
    '3 4\n'
)
Path('sample2.desc').write_text('Sample with Solution 2\n')

Path('sample3.in').write_text(
    '6 6\n'+
    '6 5\n'+
    '1 2\n'+
    '2 3\n'+
    '2 4\n'+
    '3 4\n'+
    '4 5\n'
)
Path('sample3.desc').write_text('Sample with Solution 3\n')



Path('case0.in').write_text('10 0')
Path('case0.desc').write_text('case with zero edges')

for i in range(1,10):
    
    nodes = random.randint(2,MAX_NODES)
    edges = 0
    description = ""
    
    for node in range(1, nodes):
        other_nodes = list(range(node+1,nodes))
        random.shuffle(other_nodes)
        for other_node in other_nodes:
            if bool(random.getrandbits(1)):
                if bool(random.getrandbits(1)):
                    description +=f'{node} {other_node}\n'
                else:
                    description +=f'{other_node} {node}\n'
                edges += 1
                
    description = f'{nodes} {edges}\n{description}'
    Path(f'case{i}.in').write_text(description)
    Path(f'case{i}.desc').write_text(f'case with random number of nodes and edges {i}.\n')
            
        
