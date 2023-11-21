#include "ESP32Labs_V1.h"

#include <DHT.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

ESP32Labs::ESP32Labs(int dht_pin, int bzr_pin, int ldr_pin, int led_r_pin, int led_g_pin, int led_b_pin, int bt1_pin, int bt2_pin, int bt3_pin, int bt4_pin, int bt5_pin, int bt6_pin)
{
  _dht_pin = dht_pin;
  _bzr_pin = bzr_pin;
  _ldr_pin = ldr_pin;
  _led_r_pin = led_r_pin;
  _led_g_pin = led_g_pin;
  _led_b_pin = led_b_pin;
  _bt1_pin = bt1_pin;
  _bt2_pin = bt2_pin;
  _bt3_pin = bt3_pin;
  _bt4_pin = bt4_pin;
  _bt5_pin = bt5_pin;
  _bt6_pin = bt6_pin;
  dht = new DHT(_dht_pin, DHT11);
}

//Misc. Setup
  Adafruit_SSD1306 display(128, 64);

void ESP32Labs::begin()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  dht->begin();

  pinMode(_ldr_pin, INPUT);
  pinMode(_bzr_pin, OUTPUT);
  pinMode(_led_r_pin, OUTPUT);
  pinMode(_led_g_pin, OUTPUT);
  pinMode(_led_b_pin, OUTPUT);
  pinMode(_bt1_pin, INPUT_PULLUP);
  pinMode(_bt2_pin, INPUT_PULLUP);
  pinMode(_bt3_pin, INPUT_PULLUP);
  pinMode(_bt4_pin, INPUT_PULLUP);
  pinMode(_bt5_pin, INPUT_PULLUP);
  pinMode(_bt6_pin, INPUT_PULLUP);

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Welcome!");

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 17);
  display.println("EduEletronics");
  display.println("ESP32Labs V1");
  display.println("Firmware: V0.0.2");
  display.display();

  delay(2000);
  display.clearDisplay();
  delay(100);
}

float ESP32Labs::read_temp()
{
  float t = dht->readTemperature();
  return t;
}

float ESP32Labs::read_hum()
{
  float h = dht->readHumidity();
  return h;
}

int ESP32Labs::read_ldr()
{
  int l = analogRead(_ldr_pin);
  return l;
}

int ESP32Labs::button(int btn_press)
{
  switch (btn_press) {
  case 1:
    if (digitalRead(_bt1_pin) == 0) {
      return 1; 
      break;
    } else if (digitalRead(_bt1_pin) == 1) {
      return 0;
      break;
    } 
    break;
    
  case 2:
    if (digitalRead(_bt2_pin) == 0) {
      return 1; 
      break;
    } else if (digitalRead(_bt2_pin) == 1) {
      return 0;
      break;
    } 
    break;

  case 3:
    if (digitalRead(_bt3_pin) == 0) {
      return 1; 
      break;
    } else if (digitalRead(_bt3_pin) == 1) {
      return 0;
      break;
    } 
    break;

  case 4:
    if (digitalRead(_bt4_pin) == 0) {
      return 1; 
      break;
    } else if (digitalRead(_bt4_pin) == 1) {
      return 0;
      break;
    } 
    break;

  case 5:
    if (digitalRead(_bt5_pin) == 0) {
      return 1; 
      break;
    } else if (digitalRead(_bt5_pin) == 1) {
      return 0;
      break;
    } 
    break;

  case 6:
    if (digitalRead(_bt6_pin) == 0) {
      return 1; 
      break;
    } else if (digitalRead(_bt6_pin) == 1) {
      return 0;
      break;
    } 
    break;
  }
}

void ESP32Labs::buzzer(int buzzer_state) {
  if (buzzer_state == 1) {
    digitalWrite(_bzr_pin, HIGH);
  } else if (buzzer_state == 0) {
    digitalWrite(_bzr_pin, LOW);
  }
}

void ESP32Labs::clear_oled(){
  display.clearDisplay();
}

void ESP32Labs::text_settings(float textSize, int x_cur, int y_cur){
  display.setTextSize(textSize);
  display.setTextColor(WHITE);
  display.setCursor(x_cur, y_cur);
}

void ESP32Labs::oled_print(String text)
{
  display.print(text);
  display.display();
}

void ESP32Labs::oled_println(String text)
{
  display.println(text);
  display.display();
}

void ESP32Labs::oled_scroll(String scroll)
{
  if (scroll == "left") {
    display.startscrollleft(0x00, 0x0F);
  } else if (scroll == "right") {
    display.startscrollright(0x00, 0x0F);
  } else if (scroll == "stop") {
    display.stopscroll();
  }
}


void ESP32Labs:: rgb(String state)
{
  if (state == "red") {
    digitalWrite(_led_r_pin, HIGH);
    digitalWrite(_led_g_pin, LOW);
    digitalWrite(_led_b_pin, LOW);
  } else if (state == "green") {
    digitalWrite(_led_r_pin, LOW);
    digitalWrite(_led_g_pin, HIGH);
    digitalWrite(_led_b_pin, LOW);
  } else if (state == "blue") {
    digitalWrite(_led_r_pin, LOW);
    digitalWrite(_led_g_pin, LOW);
    digitalWrite(_led_b_pin, HIGH);
  } else if (state == "yellow") {
    digitalWrite(_led_r_pin, HIGH);
    digitalWrite(_led_g_pin, HIGH);
    digitalWrite(_led_b_pin, LOW);
  } else if (state == "magenta") {
    digitalWrite(_led_r_pin, HIGH);
    digitalWrite(_led_g_pin, LOW);
    digitalWrite(_led_b_pin, HIGH);
  } else if (state == "cyan") {
    digitalWrite(_led_r_pin, LOW);
    digitalWrite(_led_g_pin, HIGH);
    digitalWrite(_led_b_pin, HIGH);
  } else if (state == "white") {
    digitalWrite(_led_r_pin, HIGH);
    digitalWrite(_led_g_pin, HIGH);
    digitalWrite(_led_b_pin, HIGH);
  } else if (state == "off") {
    digitalWrite(_led_r_pin, LOW);
    digitalWrite(_led_g_pin, LOW);
    digitalWrite(_led_b_pin, LOW);
  }
}