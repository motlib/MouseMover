# MouseMover

Arduino Pro Micro sketch to move the mouse to prevent screensaver activation.

There's a tool that loses its floating license during lunch break. It seems to
detect that there is no mouse movement for an extended period of time and then
releases the license. 

To prevent this, Arduino to the rescue! The sketch implements a USB mouse
device, which moves the mouse cursor regularly. 

This sketch is intended for the Arduino Pro Micro, as it can implement a HID
device. Other Aruino boards with a separate UART-to-USB-chip will not work. 

See https://github.com/motlib/MouseMover for details.
