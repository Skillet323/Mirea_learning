__all__ = ['func1', 'ClassA']  # Указываем, что импортируется через *

def func1():
    return "Hello"

class ClassA:
    pass

def private_func():
    pass  # Не попадет в импорт *