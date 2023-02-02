#include "Arduino.h"
#include "SwitchControllerPico.h"

const uint8_t desc_hid_report[] =
{
  CUSTOM_DESCRIPTOR
};

Adafruit_USBD_HID usb_hid(desc_hid_report, sizeof(desc_hid_report), HID_ITF_PROTOCOL_NONE, 2, false);

void setup() {
  switchcontrollerpico_init();
  // wait until device mounted
  while( !TinyUSBDevice.mounted() ) delay(1);
  switchcontrollerpico_reset();
}

void loop() {
  pushButton(Button::A, 100, 1);
}
