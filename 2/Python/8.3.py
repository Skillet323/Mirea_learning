import re
import sys
import argparse

def replace_quotes(text):
    count = 0
    def repl(match):
        nonlocal count
        if count % 2 == 0:
            res = '«'
        else:
            res = '»'
        count += 1
        return res
    return re.sub(r'"', repl, text)

def process_code_blocks(text):
    # Нахождение всех блоков кода
    code_blocks = []
    pattern = r'```(.*?)```'
    matches = list(re.finditer(pattern, text, re.DOTALL))
    
    # Разделение текста на части (между блоками кода)
    fragments = []
    last_end = 0
    for m in matches:
        start, end = m.start(), m.end()
        fragments.append(text[last_end:start])  # Текст перед блоком кода
        code_block = m.group(0)  # Сам блок кода
        code_blocks.append(code_block)
        fragments.append(f'__CODE_{len(code_blocks)-1}__')  # Заглушка для блока кода
        last_end = end
    fragments.append(text[last_end:])  # Оставшийся текст
    
    # Обработка текста вне блоков кода
    processed = []
    for part in fragments:
        if part.startswith('__CODE_'):
            processed.append(part)  # Блок кода оставляем без изменений
        else:
            processed.append(replace_quotes(part))  # Заменяем кавычки
    
    # Восстановление блоков кода
    result = []
    code_idx = 0
    for part in processed:
        if part.startswith('__CODE_'):
            idx = int(part.split('_')[-1])
            result.append(code_blocks[idx])  # Возвращаем оригинальный блок кода
        else:
            result.append(part)
    return ''.join(result)

def main():
    parser = argparse.ArgumentParser(description='Convert quotes in markdown')
    parser.add_argument('file', nargs='?', type=argparse.FileType('r', encoding='utf-8'), default=sys.stdin,
                        help='Input file (or stdin if not specified)')
    args = parser.parse_args()
    
    # Чтение данных из файла или stdin с явной кодировкой UTF-8
    text = args.file.read()
    processed = process_code_blocks(text)
    
    # Вывод результата в UTF-8
    sys.stdout.reconfigure(encoding='utf-8') 
    print(processed, end='')

if __name__ == '__main__':
    main()