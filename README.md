Minecraft Lantern Project with NeoPixels

Hello everyone.
In this project, we are going to build a Minecraft-style lantern using an Arduino Nano and addressable RGB LEDs. The lantern’s color is fully controllable with potentiometers, allowing smooth RGB adjustment in real time.

Components Used

Before starting, make sure you have all the required components:

1 × Arduino Nano
2 × WS2812B NeoPixel Ring (16 LEDs each)
4 × 10kΩ rotary potentiometers
1 × 1000µF electrolytic capacitor
1 × 100Ω resistor
1 × on/off switch
1 × 18650 Li-ion battery
1 × TP4056 battery charging module
1 × DC-to-DC buck converter

Circuit Assembly

After gathering all components, assemble the circuit by following the schematic shown in the image above.
Before soldering or final assembly, it is recommended to slightly tidy up the wiring layout for clarity and reliability:

Make sure all grounds (GND) are connected together
Place the 100Ω resistor in series with the NeoPixel data line
Connect the 1000µF capacitor across the NeoPixel power lines to protect the LEDs
Verify correct voltage from the buck converter before powering the LEDs
Double-check all connections to avoid damaging the NeoPixel rings or the Arduino.

Uploading the Code

Once the hardware setup is complete, upload the provided Arduino code to the Arduino Nano.
The code reads values from the potentiometers and maps them to RGB values, allowing you to control the lantern’s color dynamically. After uploading, power the circuit and enjoy your custom Minecraft lantern lighting effect.
