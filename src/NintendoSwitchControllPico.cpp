#include "NintendoSwitchControllPico.h"

NintendoSwitchControllPico_::NintendoSwitchControllPico_(void)
{
  memset(&_joystickInputData, 0, sizeof(USB_JoystickReport_Input_t));
}

bool NintendoSwitchControllPico_::sendReport(void)
{
  return usb_hid.sendReport(0, &_joystickInputData, sizeof(USB_JoystickReport_Input_t));
}

void NintendoSwitchControllPico_::pressButton(Button button_num)
{
  _joystickInputData.Button |= (uint16_t)button_num;
  sendReport();
}

void NintendoSwitchControllPico_::releaseButton(Button button_num)
{
  _joystickInputData.Button &= ((uint16_t)button_num ^ 0xffff);
  sendReport();
}

void NintendoSwitchControllPico_::pressHatButton(Hat hat)
{
  _joystickInputData.Hat = (uint8_t)hat;
  sendReport();
}

void NintendoSwitchControllPico_::releaseHatButton(void)
{
  _joystickInputData.Hat = (uint8_t)Hat::CENTER;
  sendReport();
}

void NintendoSwitchControllPico_::sendReportOnly(USB_JoystickReport_Input_t t_joystickInputData)
{
  _joystickInputData.Button = t_joystickInputData.Button;
  _joystickInputData.Hat    = t_joystickInputData.Hat;
  _joystickInputData.LX     = t_joystickInputData.LX;
  _joystickInputData.LY     = t_joystickInputData.LY;
  _joystickInputData.RX     = t_joystickInputData.RX;
  _joystickInputData.RY     = t_joystickInputData.RY;
  _joystickInputData.Dummy  = t_joystickInputData.Dummy;
  sendReport();
}

void NintendoSwitchControllPico_::setStickTiltRatio(int16_t lx_per, int16_t ly_per,
                                                     int16_t rx_per, int16_t ry_per)
{
  _joystickInputData.LX = (uint8_t)(lx_per * 0xFF / 200 + 0x80);
  _joystickInputData.LY = (uint8_t)(ly_per * 0xFF / 200 + 0x80);
  _joystickInputData.RX = (uint8_t)(rx_per * 0xFF / 200 + 0x80);
  _joystickInputData.RY = (uint8_t)(ry_per * 0xFF / 200 + 0x80);
  sendReport();
}

NintendoSwitchControllPico_ &SwitchController(void)
{
  static NintendoSwitchControllPico_ obj;
  return obj;
}
