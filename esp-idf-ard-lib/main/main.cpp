
#include <stdio.h>
#include <Arduino.h>
#include <Ticker.h>

extern "C" {
void app_main(void);
}

// attach a LED to pPIO 21
#define LED_PIN 2

Ticker blinker;
Ticker toggler;
Ticker changer;
float blinkerPace = 0.1;  //seconds
const float togglePeriod = 5; //seconds

void change() {
  blinkerPace = 0.5;
}

void blink() {
  Serial.println("Blinking...." );
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}

void toggle() {
  Serial.println("toggle triggered...." );
  static bool isBlinking = false;
  if (isBlinking) {
    blinker.detach();
    isBlinking = false;
  }
  else {
    blinker.attach(blinkerPace, blink);
    isBlinking = true;
  }
  digitalWrite(LED_PIN, LOW);  //make sure LED on on after toggling (pin LOW = led ON)
}

void app_main()
{   
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  toggler.attach(togglePeriod, toggle);
  changer.once(5, change);
}