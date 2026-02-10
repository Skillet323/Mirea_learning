import os
import sys
import argparse

def generate_dot(root_path, output_file):
    with open(output_file, 'w', encoding='utf-8') as f:  # Явно указываем кодировку UTF-8
        f.write("digraph {\n")
        f.write('\tnode [shape=folder];\n')
        nodes = {}  # Словарь: путь -> уникальное имя узла
        stack = [(root_path, None)]  # (current_path, parent_path)

        while stack:
            current_path, parent_path = stack.pop()
            node_name = os.path.basename(current_path).replace(os.sep, '_')  # Используем имя файла/папки
            nodes[current_path] = node_name

            # Определяем тип и добавляем узел
            if os.path.isdir(current_path):
                f.write(f'\t"{node_name}" [shape=folder];\n')
                # Добавляем дочерние элементы
                try:
                    for entry in os.listdir(current_path):
                        full_child_path = os.path.join(current_path, entry)
                        stack.append((full_child_path, current_path))
                except PermissionError:
                    pass  # Пропускаем недоступные директории
            else:
                f.write(f'\t"{node_name}" [shape=file];\n')

            # Добавляем ребро к родителю
            if parent_path in nodes:
                parent_node = nodes[parent_path]
                f.write(f'\t"{parent_node}" -> "{node_name}";\n')

        f.write("}\n")

def main():
    parser = argparse.ArgumentParser(description='Generate directory tree in Graphviz format')
    parser.add_argument('path', help='Root directory path')
    parser.add_argument('-o', '--output', default='tree.dot', help='Output file (default: tree.dot)')
    args = parser.parse_args()

    path = args.path
    if not os.path.exists(path):
        print(f"Error: {path} does not exist")
        sys.exit(1)

    generate_dot(path, args.output)  # Генерируем dot-файл
    print(f"Saved to {args.output}")

if __name__ == '__main__':
    main()