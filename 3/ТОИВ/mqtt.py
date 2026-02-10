#!/usr/bin/env python3
# Требует: pip install paho-mqtt
import paho.mqtt.client as mqtt

LOCAL_BROKER = ('localhost', 1883)
REMOTE_BROKER = ('dev.rightech.io', 1883)   # или 8883 + TLS
REMOTE_USER = 'aaabbbaaa_2000@bk.ru'
REMOTE_PASS = 'kydvan-1taxme-barzEt'
SUBSCRIBE_TOPIC = '/devices/Temperature/controls/#'  # фильтр — обязательно сузьте!

# Клиент, который публикует в облако
pub = mqtt.Client(client_id="wb-bridge-pub")
pub.username_pw_set(REMOTE_USER, REMOTE_PASS)
# при необходимости: pub.tls_set(...) для TLS/8883
pub.connect(*REMOTE_BROKER)
pub.loop_start()

def on_local_message(client, userdata, msg):
    # защита от петли: можно перекрывать/менять префикс, добавлять метку source
    # не публикуем сообщения, которые уже помечены как пересланные
    payload = msg.payload
    topic = msg.topic
    # пример: пересылаем на тот же топик (или измените маппинг)
    pub.publish(topic, payload, qos=0, retain=False)

local = mqtt.Client(client_id="wb-bridge-sub")
local.on_message = on_local_message
local.connect(*LOCAL_BROKER)
local.subscribe(SUBSCRIBE_TOPIC)
local.loop_forever()
