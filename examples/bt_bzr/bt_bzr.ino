 /* Example: 
 * Using the buttons to control the buzzer
 * Author: EduEletronics
 */

#include <ESP32Labs_V1.h>

const int dht_pin = 13;
const int bzr_pin = 18;
const int ldr_pin = 14;

const int rgb_pins[] = { 4, 16, 17 };           // R G B
const int bt_pins[] = { 12, 14, 27, 26, 25, 0 };  // BT1 BT2 BT3 BT4 BT5 BT6

ESP32Labs ESP32Labs(dht_pin, bzr_pin, ldr_pin,
                    rgb_pins[0], rgb_pins[1], rgb_pins[2],
                    bt_pins[0], bt_pins[1], bt_pins[2], bt_pins[3], bt_pins[4], bt_pins[5]);

void setup() {
  ESP32Labs.begin();
}

void loop() {
  if (ESP32Labs.button(1) == 1) {
    ESP32Labs.buzzer(1);
    delay(100);
    ESP32Labs.buzzer(0);
    delay(300);
  } else if (ESP32Labs.button(2) == 1) {
    ESP32Labs.buzzer(1);
    delay(100);
    ESP32Labs.buzzer(0);
    delay(100);
    ESP32Labs.buzzer(1);
    delay(100);
    ESP32Labs.buzzer(0);
    delay(300);
  } else if (ESP32Labs.button(3) == 1) {
    ESP32Labs.buzzer(1);
    delay(100);
    ESP32Labs.buzzer(0);
    delay(100);
    ESP32Labs.buzzer(1);
    delay(100);
    ESP32Labs.buzzer(0);
    delay(100);
    ESP32Labs.buzzer(1);
    delay(100);
    ESP32Labs.buzzer(0);
    delay(300);
  } 
}