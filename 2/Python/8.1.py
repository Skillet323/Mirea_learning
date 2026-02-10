#8.1
import os
import sys
import argparse
from datetime import datetime

def human_size(size_bytes):
    #Человекочитаемый формат
    units = ['B', 'KB', 'MB', 'GB', 'TB']
    if size_bytes == 0:
        return "0 B"
    num = float(size_bytes)
    magnitude = 0
    while num >= 1024 and magnitude < len(units)-1:
        magnitude += 1
        num /= 1024.0
    return f"{num:.1f} {units[magnitude]}"

def get_file_info(file_path):
    try:
        stat = os.stat(file_path)
        #-l параметры
        return {
            'name': os.path.basename(file_path),
            'size': stat.st_size,
            'mtime': stat.st_mtime,
            'is_dir': os.path.isdir(file_path),
            'perms': stat.st_mode
        }
    except OSError as e:
        return None

#Правильное чтение файла
def format_file(file_info, human=False):
    name = file_info['name']
    if file_info['is_dir']:
        name += '/'
    perms = oct(file_info['perms'])[-4:]
    size = human_size(file_info['size']) if human else str(file_info['size'])
    mtime = datetime.fromtimestamp(file_info['mtime']).strftime('%Y-%m-%d %H:%M')
    return f"{perms} {size: <8} {mtime} {name}"

#Составление списка из фпйлов
def list_files(path, all_files=False):
    try:
        files = os.listdir(path)
        if not all_files:
            files = [f for f in files if not f.startswith('.')]
        return [os.path.join(path, f) for f in files]
    except OSError as e:
        return []

def main():
    parser = argparse.ArgumentParser(description='List directory contents')
    parser.add_argument('path', nargs='?', default='.', help='Directory to list')
    parser.add_argument('-a', '--all', action='store_true', help='Show all files')
    parser.add_argument('-l', '--long', action='store_true', help='Use long format')
    parser.add_argument('-R', '--recursive', action='store_true', help='Recurse into subdirectories')
    parser.add_argument('-H', '--human-readable', action='store_true', help='Human-readable sizes')
    parser.add_argument('-S', '--sort-size', action='store_true', help='Sort by size')
    parser.add_argument('-t', '--sort-time', action='store_true', help='Sort by modification time')
    args = parser.parse_args()

    path = args.path
    if not os.path.exists(path):
        print(f"Error: {path} does not exist")
        sys.exit(1)
        
    #Сортировка
    def get_sort_key(file_info):
        if args.sort_size:
            return file_info['size']
        elif args.sort_time:
            return -file_info['mtime']
        else:
            return file_info['name']

    def process_directory(current_path, indent=''):
        files = list_files(current_path, args.all)
        file_infos = [get_file_info(f) for f in files]
        file_infos = [fi for fi in file_infos if fi is not None]
        file_infos.sort(key=lambda x: get_sort_key(x))
        for fi in file_infos:
            if args.long:
                print(indent + format_file(fi, args.human_readable))
            else:
                print(indent + fi['name'])
        if args.recursive:
            for fi in file_infos:
                if fi['is_dir']:
                    new_path = os.path.join(current_path, fi['name'])
                    if new_path != current_path:
                        print(indent + f"{fi['name']}/:")
                        process_directory(new_path, indent + '  ')

    process_directory(path)

if __name__ == '__main__':
    main()