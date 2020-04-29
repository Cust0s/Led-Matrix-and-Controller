#include "includes.h"

void setup() {
  Serial.begin(115200);

  //LED initialisation
  FastLED.addLeds<WS2812B, MATRIX_PIN1, GRB>(leds, 0, NUM_LEDS_PER_MATRIX);
  FastLED.addLeds<WS2812B, MATRIX_PIN2, GRB>(leds, NUM_LEDS_PER_MATRIX, NUM_LEDS_PER_MATRIX);
  FastLED.addLeds<WS2812B, MATRIX_PIN3, GRB>(leds, 2 * NUM_LEDS_PER_MATRIX, NUM_LEDS_PER_MATRIX);
  FastLED.addLeds<WS2812B, MATRIX_PIN4, GRB>(leds, 3 * NUM_LEDS_PER_MATRIX, NUM_LEDS_PER_MATRIX);

  //Switches initialisation
  pinMode(TOP_SWITCH, INPUT);
  pinMode(BOTTOM_SWITCH, INPUT);

  if(digitalRead(BOTTOM_SWITCH)){
    switchPos = true;
    W_AND_H = 20;
  }

  attachInterrupt(TOP_SWITCH, TopSwitchChange, CHANGE);
  attachInterrupt(BOTTOM_SWITCH, BottomSwitchChange, CHANGE);

  //Rotary encoder initialisation
  pinMode(ENCODER_BUTTON, INPUT);
  pinMode(ENCODER_PIN_A, INPUT);
  pinMode(ENCODER_PIN_B, INPUT);
  // set an interrupt for the encoder pin a
  attachInterrupt(ENCODER_PIN_A, PinChange, CHANGE); 
  // set an interrupt for the encoder pin b
  attachInterrupt(ENCODER_PIN_B, PinChange, CHANGE);
  // set an interrupt for the encoder button
  attachInterrupt(ENCODER_BUTTON, EncoderPress, RISING);


  //OLED initialisation
  display1 = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  display2 = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire1, OLED_RESET);
  display3 = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire2, OLED_RESET);

  display1.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display2.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display3.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display3.setFont(&FreeSans9pt7b);
  menuSetup();
  printAnimationText(selectedItem);
}

void loop() {
  timeStamp1 = millis();
  // put your main code here, to run repeatedly:
  switch(selectedItem){
    //Twinkle RGB
    case 0:
      anim_twinkleRGB();
      break;
    //Twinkle Rand
    case 1:
      anim_twinkleRND();
      break;
    //Twinkle Hue
    case 2:
      anim_twinkleHue();
      break;
    //Hue Change
    case 3:
      anim_hueChange();
      break;
    //Flame
    case 4:
      anim_eachPixel();
      break;
    //Diagonal1
    case 5:
      //diagonal to top right
      anim_diagonal(0b0000);
      break;
    //Diagonal2
    case 6:
      //diagonal to bottom right
      anim_diagonal(0b0001);
      break;
    //Diagonal3
    case 7:
      //diagonal to bottom left
      anim_diagonal(0b0010);
      break;
    //Diagonal4
    case 8:
      //diagonal to top left
      anim_diagonal(0b0011);
      break;
    //Dead Channel
    case 9:
      anim_deadChannel();
      break;
    //Solid Pulse
    case 10:
      anim_solidPulse();
      break;
    //Hue Pulse
    case 11:
      anim_huePulse();
      break;
    //Test
    case 12:
      anim_test();
      break;
    //default
    default:
      break;
  }
  LEDS.show();
  sendToJava();
  timeStamp2 = millis();
  int delayTime = timeStamp2 - timeStamp1;
  while(delayTime < 15){
    timeStamp2 = millis();
    delayTime = timeStamp2 - timeStamp1;
  }

}
