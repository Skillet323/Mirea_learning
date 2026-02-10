import paho.mqtt.client as mqtt
import csv
from datetime import datetime
import time

HOST = "192.168.1.16"
PORT = 1883
KEEPALIVE = 60

# Топики для ПР №8 (вариант 4)
TOPICS = {
    '/devices/wb-msw-v3_21/controls/Current Motion': 'motion',
    '/devices/wb-ms_11/controls/Temperature': 'temperature',
    '/devices/wb-map12h_220/controls/Voltage': 'voltage'
}

current_data = {key: None for key in TOPICS.values()}
csv_file = "sensor_data.csv"

# Инициализация CSV
with open(csv_file, 'w', newline='', encoding='utf-8') as f:
    writer = csv.writer(f)
    writer.writerow(['timestamp', 'motion', 'temperature', 'voltage'])

def on_connect(client, userdata, flags, rc):
    print("Подключено к MQTT для сбора данных")
    for topic in TOPICS:
        client.subscribe(topic)

def on_message(client, userdata, msg):
    payload = msg.payload.decode().strip()
    topic = msg.topic
    if topic in TOPICS:
        param = TOPICS[topic]
        current_data[param] = payload

def main():
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect(HOST, PORT, KEEPALIVE)
    client.loop_start()

    print("Сбор данных в течение 10 минут...")
    start = time.time()
    try:
        while time.time() - start < 600:  # 10 минут = 600 сек
            time.sleep(5)
            if all(v is not None for v in current_data.values()):
                row = [
                    str(datetime.now()),
                    current_data['motion'],
                    current_data['temperature'],
                    current_data['voltage']
                ]
                with open(csv_file, 'a', newline='', encoding='utf-8') as f:
                    writer = csv.writer(f)
                    writer.writerow(row)
                print("Записано:", row)
            else:
                print("Ожидание всех данных...")
    finally:
        client.loop_stop()
        print("Сбор завершён. Данные в sensor_data.csv")

if __name__ == "__main__":
    main()