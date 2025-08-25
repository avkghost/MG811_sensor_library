## MG811 Sensor Library (Embedded/IoT)

MG811 Carbon Dioxide sensor library for Arduino

Source code base on artlicle http://sandboxelectronics.com/?p=147

# MG811 Sensor Library ⚡

Arduino library for **MG811 CO₂ sensor**. Provides easy access to sensor readings for embedded and IoT projects.  

## ✨ Features
- 📡 Read CO₂ concentration in ppm
- 🔧 Easy integration with Arduino IDE
- ⚡ Lightweight and efficient

## 🔧 Tech Stack
- C++ (Arduino)
- Tested on ESP32/Arduino boards

## 🚀 Getting Started
```cpp
#include <MG811.h>

MG811 sensor(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int ppm = sensor.readCO2();
  Serial.println(ppm);
  delay(1000);
}

```
