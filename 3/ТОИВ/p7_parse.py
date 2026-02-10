import json
import xml.etree.ElementTree as ET

def parse_json():
    try:
        with open('data.json', 'r', encoding='utf-8') as f:
            data = json.load(f)
        print("=== Данные из JSON ===")
        for k, v in data.items():
            print(f"{k}: {v}")
    except Exception as e:
        print("Ошибка при чтении JSON:", e)

def parse_xml():
    try:
        tree = ET.parse('data.xml')
        root = tree.getroot()
        print("\n=== Данные из XML ===")
        for child in root:
            if child.tag != 'xml':  # Пропускаем декларацию
                print(f"{child.tag}: {child.text}")
    except Exception as e:
        print("Ошибка при чтении XML:", e)

if __name__ == "__main__":
    parse_json()
    parse_xml()