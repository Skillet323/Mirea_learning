import pack
from importlib import resources

with resources.open_text('pack', 'data.json') as f:
    data = f.read()
    print(data) 