/* Example: 
 * OLED Displaying Temperature and Humidity from DHT11 sensor
 * Author: Diogo Silva
 */

#include <ESP32Labs_V1.h>

const int dht_pin = 13;
const int bzr_pin = 12;
const int ldr_pin = 14;

const int rgb_pins[] = {27, 26, 25}; // R G B
const int  bt_pins[] = {33, 32, 19, 18, 5, 4}; // BT1 BT2 BT3 BT4 BT5 BT6


ESP32Labs ESP32Labs(dht_pin, bzr_pin, ldr_pin, 
                    rgb_pins[0], rgb_pins[1], rgb_pins[2],
                    bt_pins[0], bt_pins[1], bt_pins[2], bt_pins[3], bt_pins[4], bt_pins[5]);

void setup() {
  ESP32Labs.begin();

}

void loop() {
  ESP32Labs.clear_oled();

  //Getting data from DHT11
  float t = ESP32Labs.read_temp();
  float h = ESP32Labs.read_hum();

  // text_settings(Text Size, Cursor POS X, Cursor POS Y);
  ESP32Labs.text_settings(2, 0, 17);

   // Displaying on the OLED
  ESP32Labs.oled_print("Temp:");
  ESP32Labs.oled_println(String(t));

  ESP32Labs.oled_print("Hum:");
  ESP32Labs.oled_println(String(h));
  
  delay(1000);
}
