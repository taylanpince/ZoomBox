#include <AceButton.h>
#include "HID-Project.h"

using namespace ace_button;

const int BUTTON1_PIN = 3;
const int BUTTON2_PIN = 2;

AceButton button1(BUTTON1_PIN);
AceButton button2(BUTTON2_PIN);

void handleEvent(AceButton*, uint8_t, uint8_t);

void setup() {
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);

  ButtonConfig* buttonConfig = ButtonConfig::getSystemButtonConfig();

  buttonConfig->setEventHandler(handleEvent);
  buttonConfig->setFeature(ButtonConfig::kFeatureClick);
  //buttonConfig->setFeature(ButtonConfig::kFeatureDoubleClick);
  //buttonConfig->setFeature(ButtonConfig::kFeatureSuppressClickBeforeDoubleClick);
  buttonConfig->setFeature(ButtonConfig::kFeatureLongPress);
  buttonConfig->setFeature(ButtonConfig::kFeatureSuppressAfterLongPress);

  Keyboard.begin();
}

void loop() {
  button1.check();
  button2.check();
}

void muteUnmute() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('A');
  
  delay(100);
  
  Keyboard.releaseAll();
}

void startStopScreenShare() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('S');
  
  delay(100);
  
  Keyboard.releaseAll();
}

// The event handler for both buttons.
void handleEvent(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  switch (eventType) {
    case AceButton::kEventClicked:
      if (button->getPin() == BUTTON1_PIN) {
        muteUnmute();
      } else {
        startStopScreenShare();
      }
      break;
    case AceButton::kEventDoubleClicked:
      if (button->getPin() == BUTTON1_PIN) {
        
      } else {
        
      }
      break;
    case AceButton::kEventLongPressed:
      if (button->getPin() == BUTTON1_PIN) {
        muteUnmute();
      } else {
        
      }
      break;
    case AceButton::kEventLongReleased:
      if (button->getPin() == BUTTON1_PIN) {
        muteUnmute();
      } else {
        
      }
      break;
  }
}
