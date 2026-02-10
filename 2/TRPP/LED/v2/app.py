import socket
from flask import Flask, render_template, request, redirect, jsonify, session
import requests
import os

app = Flask(__name__)
app.secret_key = os.urandom(24)


def get_local_ip():
    """
    Определяет локальный IP-адрес машины в сети посредством открытия
    временного UDP-сокета к публичному DNS Google.
    Возвращает строку вида '192.168.x.x' или '127.0.0.1' при ошибке.
    """
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(("8.8.8.8", 80))
        local_ip = s.getsockname()[0]
        s.close()
        return local_ip
    except Exception:
        return "127.0.0.1"

DEFAULT_ESP_IP = 'http://192.168.1.100'


def get_esp_ip():
    """
    Возвращает текущий IP ESP-контроллера из сессии Flask.
    Если в сессии нет значения, возвращает DEFAULT_ESP_IP.
    """
    return session.get('esp_ip', DEFAULT_ESP_IP)


@app.route('/')
def index():
    """
    Главная страница: отображает шаблон control_panel с текущим IP контроллера.
    """
    return render_template('index.html', current_ip=get_esp_ip())


@app.route('/update_ip', methods=['POST'])
def update_ip():
    """
    Обрабатывает POST-запрос для обновления IP контроллера.
    Проверяет, что строка начинается с http:// или https://
    и сохраняет её в сессии.
    """
    new_ip = request.form.get('ip')
    if new_ip and new_ip.startswith(('http://', 'https://')):
        session['esp_ip'] = new_ip
        return jsonify({'status': 'success', 'ip': new_ip})
    return jsonify({'status': 'error'}), 400


@app.route('/power/<state>')
def power_control(state):
    """
    Включает или выключает LED-ленту.
    При state=='on' отправляет запрос на /on, иначе /off.
    После запроса перенаправляет на '/' методом HTTP 302.
    """
    esp_ip = get_esp_ip()
    if state == 'on':
        requests.get(f'{esp_ip}/on')
    else:
        requests.get(f'{esp_ip}/off')
    return redirect('/')


@app.route('/color')
def color():
    """
    Устанавливает цвет: принимает параметры r, g, b в query-string.
    Перенаправляет обратно на главную.
    """
    esp_ip = get_esp_ip()
    r = request.args.get('r')
    g = request.args.get('g')
    b = request.args.get('b')
    if all([r, g, b]):
        requests.get(f'{esp_ip}/color?r={r}&g={g}&b={b}')
    return redirect('/')


@app.route('/mode', methods=['POST'])
def set_mode():
    """
    Изменяет режим работы ленты: статичный, дыхание, радуга или музыка.
    Получает параметр 'mode' из формы и отправляет запрос к ESP.
    """
    esp_ip = get_esp_ip()
    mode = request.form.get('mode', '0')
    requests.get(f'{esp_ip}/mode?m={mode}')
    return ('', 200)


if __name__ == '__main__':
    """
    Запускает Flask-сервер на локальном IP и порту 5050.
    """
    app.run(host=get_local_ip(), port=5050)