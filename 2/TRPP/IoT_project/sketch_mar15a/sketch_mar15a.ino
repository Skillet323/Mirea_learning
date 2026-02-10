#include <ESP8266WiFi.h>
#include <FastLED.h>

// Настройки LED-ленты
#define LED_PIN    4     // Пин подключения LED-ленты (D2 на NodeMCU)
#define NUM_LEDS   30    // Количество LED
#define BRIGHTNESS 50    // Изначальная яркость (0-255)

CRGB leds[NUM_LEDS];     // Массив для хранения состояния LED

// Настройки Wi-Fi
const char* ssid = "Ваш_SSID";    // Название вашей сети
const char* password = "Ваш_пароль"; // Пароль от Wi-Fi

WiFiServer server(80);            // Создаем сервер на порту 80

void setup() {
  Serial.begin(115200);
  
  // Инициализация LED-ленты
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS); // Укажите тип LED (WS2812B/NEOPIXEL)
  FastLED.setBrightness(BRIGHTNESS);

  // Подключение к Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Запуск сервера
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') {
          // Обрабатываем запрос
          handleRequest(request);
          request = "";
          break;
        } else {
          request += c;
        }
      }
    }
    client.stop();
  }
}

void handleRequest(String request) {
  // Парсинг параметров из URL
  if (request.indexOf("/led?") >= 0) {
    int red = getParam(request, "red");
    int green = getParam(request, "green");
    int blue = getParam(request, "blue");
    int brightness = getParam(request, "brightness", 0); // Необязательный параметр

    // Обновляем цвет и яркость
    if (red != -1 && green != -1 && blue != -1) {
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(red, green, blue);
      }
      if (brightness != -1) {
        FastLED.setBrightness(brightness);
      }
      FastLED.show();
      Serial.print("Color changed to: R=");
      Serial.print(red);
      Serial.print(" G=");
      Serial.print(green);
      Serial.print(" B=");
      Serial.print(blue);
      if (brightness != -1) {
        Serial.print(" Brightness=");
        Serial.print(brightness);
      }
      Serial.println();
    }
  }

  // Отправляем ответ
  sendResponse();
}

int getParam(String request, String param, int defaultValue) {
  int value = defaultValue;
  int index = request.indexOf(param + "=");
  if (index >= 0) {
    index += param.length() + 1;
    int end = request.indexOf('&', index);
    if (end == -1) end = request.length();
    value = request.substring(index, end).toInt();
  }
  return value;
}

void sendResponse() {
  WiFiClient client = server.available();
  if (client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE html>");
    client.println("<html>");
    client.println("<head><title>LED Control</title></head>");
    client.println("<body>");
    client.println("<h1>LED Control</h1>");
    client.println("Управление через URL:<br>");
    client.println("Пример: <a href=\"/led?red=255&green=0&blue=0\">/led?red=255&green=0&blue=0</a>");
    client.println("<br>");
    client.println("Добавьте параметр brightness для яркости: <a href=\"/led?red=0&green=255&blue=0&brightness=100\">brightness=100</a>");
    client.println("</body></html>");
    client.stop();
  }
}