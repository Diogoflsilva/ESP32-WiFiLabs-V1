#ifndef ESP32Labs_V1
#define ESP32Labs_V1

#include <DHT.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



class ESP32Labs
{
  public:
    ESP32Labs(int dht_pin, int bzr_pin, int ldr_pin, int led_r_pin, int led_g_pin, int led_b_pin, int bt1_pin, int bt2_pin, int bt3_pin, int bt4_pin, int bt5_pin, int bt6_pin);
    void begin();
    float read_temp();
    float read_hum();
    int read_ldr();
    int button(int btn_press);
    void buzzer(int buzzer_state);
    void clear_oled();
    void text_settings(float textSize, int x_cur, int y_cur);
    void oled_print(String text);
    void oled_println(String text);
    void rgb(String state);

  private:
    int _dht_pin;
    int _bzr_pin;
    int _ldr_pin;
    int _led_r_pin;
    int _led_g_pin;
    int _led_b_pin;
    int _bt1_pin;
    int _bt2_pin;
    int _bt3_pin;
    int _bt4_pin;
    int _bt5_pin;
    int _bt6_pin;
    DHT *dht;
};

#endif