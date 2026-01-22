#include <Adafruit_NeoPixel.h> 
// Include the Adafruit NeoPixel library to control addressable LEDs

#define PIXEL_PIN 3    
// Digital pin where the NeoPixel data line is connected

#define NUMPIXELS 16   
// Total number of NeoPixels in the LED strip or ring

#define POT_PIN_R  A0  
// Analog pin connected to the potentiometer for Red color

#define POT_PIN_G  A1  
// Analog pin connected to the potentiometer for Green color

#define POT_PIN_B  A2  
// Analog pin connected to the potentiometer for Blue color

#define POT_PIN_Br A3  
// Analog pin for brightness control (currently not used)

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  NUMPIXELS, 
  PIXEL_PIN, 
  NEO_GRB + NEO_KHZ800
);
// Create a NeoPixel object with pixel count, pin number, and color order

int redColor; 
// Stores mapped red color value (0–255)

int greenColor;
// Stores mapped green color value (0–255)

int blueColor;
// Stores mapped blue color value (0–255)

int potValue;
// Temporary variable to store analog potentiometer readings

void setup() {
  Serial.begin(9600);        
  // Start serial communication for debugging

  pixels.begin();            
  // Initialize the NeoPixel library

  pixels.show();             
  // Turn off all pixels at startup

  pixels.setBrightness(50);  
  // Set overall LED brightness (0–255)

  rainbow(3);                
  // Play a rainbow animation on startup
};

void loop() {
  potValue   = analogRead(POT_PIN_R);          
  // Read potentiometer value for Red channel

  redColor   = map(potValue, 0, 1023, 0, 255); 
  // Map analog value to valid RGB range

  potValue   = analogRead(POT_PIN_G);          
  // Read potentiometer value for Green channel

  greenColor = map(potValue, 0, 1023, 0, 255); 
  // Map analog value to valid RGB range

  potValue   = analogRead(POT_PIN_B);          
  // Read potentiometer value for Blue channel

  blueColor  = map(potValue, 0, 1023, 0, 255); 
  // Map analog value to valid RGB range

  Serial.print("r: "); Serial.println(redColor);
  // Print red value to Serial Monitor

  Serial.print("g: "); Serial.println(greenColor);
  // Print green value to Serial Monitor

  Serial.print("b: "); Serial.println(blueColor);
  // Print blue value to Serial Monitor

  Serial.println("");
  // Print empty line for readability

  for (int i = 0; i < NUMPIXELS; i++) {
    // Loop through all pixels

    pixels.setPixelColor(
      i, 
      pixels.Color(redColor, greenColor, blueColor)
    );
    // Set each pixel to the selected RGB color
  };
  
  pixels.show();   
  // Update the LEDs with new color values

  delay(10);       
  // Small delay to stabilize readings
};

void rainbow(int wait) {
  // Function that displays a rainbow animation

  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    // Cycle through multiple hue values

    pixels.rainbow(firstPixelHue);
    // Apply rainbow colors starting from a given hue

    pixels.show(); 
    // Update LEDs

    delay(wait);   
    // Control animation speed
  };
};
