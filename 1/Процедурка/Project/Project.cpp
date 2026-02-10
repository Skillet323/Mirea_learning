#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// Подключение модулей
#define PIN_LED_MATRIX_DATA 4
#define PIN_LED_MATRIX_CLK 2
#define PIN_LED_MATRIX_CS 15
#define PIN_3D_JOYSTICK_X 32
#define PIN_3D_JOYSTICK_Y 33
#define PIN_KEYBOARD_BTN 14

TroykaLedMatrix ledMatrix(PIN_LED_MATRIX_DATA, PIN_LED_MATRIX_CLK, PIN_LED_MATRIX_CS);
ADC adcX(PIN_3D_JOYSTICK_X);
ADC adcY(PIN_3D_JOYSTICK_Y);

// Константы для калибровки значений 3D Joystick
const int X_MIN = 0;
const int X_MAX = 4095;
const int Y_MIN = 0;
const int Y_MAX = 4095;

// Функция для калибровки значений 3D Joystick
int calibrateAdcValue(int value, int minVal, int maxVal) {
    return max(0, min(255, int(255 * (value - minVal) / (maxVal - minVal))));
}

// Функция для управления мышью
void handleMouseControl(int value) {
    int x = calibrateAdcValue(adcX.read(), X_MIN, X_MAX);
    int y = calibrateAdcValue(adcY.read(), Y_MIN, Y_MAX);
    // Здесь должен быть ваш код для управления мышью
}

// Функция для управления клавиатурой
void handleKeyboardControl(int value) {
    if (value == 1) {  // Нажата кнопка 1
        // Здесь должен быть ваш код для отправки соответствующего сигнала клавиатуре
    }
    else if (value == 2) {  // Нажата кнопка 2
        // Здесь должен быть ваш код для отправки соответствующего сигнала клавиатуре
    }
    else if (value == 3) {  // Нажата кнопка 3
        // Здесь должен быть ваш код для отправки соответствующего сигнала клавиатуре
    }
    else if (value == 4) {  // Нажата кнопка 4
        // Здесь должен быть ваш код для отправки соответствующего сигнала клавиатуре
    }
}

// Обработчик Bluetooth
class MyServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
        // Соединение установлено
    }

    void onDisconnect(BLEServer* pServer) {
        // Соединение разорвано
    }
};

void setup() {
    Serial.begin(115200);

    // Инициализация Bluetooth
    BLEDevice::init("MediaController");
    BLEServer* pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());
    BLEService* pService = pServer->createService(BLEUUID((uint16_t)0x1101));
    pService->start();
    BLECharacteristic* pCharacteristic = pService->createCharacteristic(
        BLEUUID((uint16_t)0x1102),
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE |
        BLECharacteristic::PROPERTY_NOTIFY |
        BLECharacteristic::PROPERTY_INDICATE
    );
    pCharacteristic->addDescriptor(new BLE2902());
    pCharacteristic->setValue("Hello World");
    pService->addCharacteristic(pCharacteristic);
    BLEAdvertising* pAdvertising = pServer->getAdvertising();
    pAdvertising->start();
}

void loop() {
    // Чтение данных от Bluetooth и управление соответствующими модулями
}
