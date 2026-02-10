import paho.mqtt.client as mqtt
import json
import xml.etree.ElementTree as ET
from xml.dom import minidom
from datetime import datetime
import socket

# === Настройки подключения ===
HOST = "192.168.1.16"  # IP-адрес вашего стенда
PORT = 1883
KEEPALIVE = 60

# === Топики и соответствующие поля ===
SUB_TOPICS = {
    '/devices/wb-msw-v3_21/controls/Current Motion': 'motion',
    '/devices/wb-msw-v3_21/controls/Sound Level': 'sound',
    '/devices/wb-ms_11/controls/Illumination': 'illumination',
    '/devices/wb-ms_11/controls/Temperature': 'temperature'
}

# === Хранилище данных ===
json_dict = {key: None for key in SUB_TOPICS.values()}
json_dict['timestamp'] = ''
json_dict['suitcase_id'] = socket.gethostbyname(socket.gethostname()).split('.')[-1][-2:]

xml_root = ET.Element("SensorData")

# === Обработчики MQTT ===
def on_connect(client, userdata, flags, rc):
    print("Подключено к MQTT-брокеру с кодом:", rc)
    for topic in SUB_TOPICS:
        client.subscribe(topic)
        print(f"Подписка на: {topic}")

def on_message(client, userdata, msg):
    payload = msg.payload.decode().strip()
    topic = msg.topic

    if topic in SUB_TOPICS:
        param = SUB_TOPICS[topic]
        json_dict[param] = payload
        print(f"{topic} → {param}: {payload}")

        # Проверка: все ли данные получены
        if all(v is not None for v in [json_dict['motion'], json_dict['sound'], json_dict['illumination'], json_dict['temperature']]):
            json_dict['timestamp'] = str(datetime.now())

            # === Запись в JSON ===
            with open('data.json', 'w', encoding='utf-8') as f:
                json.dump(json_dict, f, ensure_ascii=False, indent=2)

            # === Запись в XML ===
            for child in list(xml_root):
                xml_root.remove(child)
            for key, val in json_dict.items():
                el = ET.SubElement(xml_root, key)
                el.text = str(val) if val is not None else ""
            rough = ET.tostring(xml_root, 'unicode')
            reparsed = minidom.parseString(rough)
            with open('data.xml', 'w', encoding='utf-8') as f:
                f.write(reparsed.toprettyxml(indent="  "))

            print("Данные сохранены в JSON и XML")

# === Основная функция ===
def main():
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect(HOST, PORT, KEEPALIVE)
    client.loop_forever()

if __name__ == "__main__":
    main()