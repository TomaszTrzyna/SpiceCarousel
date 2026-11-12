#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("SPICECAROUSEL - START");
}

void loop() {
    delay(1000);
    Serial.println("System running...");
}