# LED Control Project

Управление RGB-лентой через веб-интерфейс.

**Архитектура:**
- Аппаратная часть на ESP8266 (Arduino C++).
- Серверная часть на Python/Flask.
- Клиентская панель на HTML/JS.

## Зависимости и установка

```bash
# Клонирование репозитория
git clone https://github.com/artyamkas/LedController.git
cd led-control

# Настройка виртуального окружения (Linux/macOS)
python3 -m venv venv
source venv/bin/activate
# (Windows)
# venv\\Scripts\\activate

# Установка Python-зависимостей и сборка пакета
pip install -r requirements.txt
python setup.py install

# Запуск приложения
flask run --host=0.0.0.0 --port=5050

#Аппаратная прошивка

Загрузите led.ino через Arduino IDE или PlatformIO.

Укажите в коде SSID и пароль вашей Wi‑Fi сети.
