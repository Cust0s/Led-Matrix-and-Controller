void anim_twinkleRGB(){
  

  if(switchPos){
    //---extend matrix mode---
    //speedFader = speed of new pixels appearing up to 1 pixel per loop max speed
    //brightnessFader = twinkle disappearance, higher fader = faster disappearing pixels
    //rgb = rgb values
    
    if(counter >=  map(getSpeedFader(), 0, 1023, 10, 1)){
      counter = 1;
    }
  
    //twinkle rgb
    
    // random colored speckles that blink in and fade smoothly
    fadeToBlackBy( leds, NUM_LEDS, map(getBrightnessFader(), 0, 1023, 0, 255));
  
    int pos = random16(NUM_LEDS);
  
    byte r = map(getRedFader(),0,1023,0,255);
    byte g = map(getGreenFader(),0,1023,0,255);
    byte b = map(getBlueFader(),0,1023,0,255);
  
    if(counter <= 1){
      leds[pos].setRGB(r,g,b);
    }
    counter ++;
      
  } else {
    //---duplicate matrix mode---

    //speedFader = speed of new pixels appearing up to 1 pixel per loop max speed
    //brightnessFader = twinkle disappearance, higher fader = faster disappearing pixels
    //rgb = rgb values
    
    if(counter >=  map(getSpeedFader(), 0, 1023, 10, 1)){
      counter = 1;
    }
  
    //twinkle rgb
    
    // random colored speckles that blink in and fade smoothly
    fadeToBlackBy( leds, NUM_LEDS, map(getBrightnessFader(), 0, 1023, 0, 255));
  
    int pos = random16(NUM_LEDS / NUM_MATRICES);
  
    byte r = map(getRedFader(),0,1023,0,255);
    byte g = map(getGreenFader(),0,1023,0,255);
    byte b = map(getBlueFader(),0,1023,0,255);
  
    if(counter <= 1){
      leds[pos].setRGB(r,g,b);
      leds[pos + NUM_LEDS_PER_MATRIX].setRGB(r,g,b);
      leds[pos + 2 * NUM_LEDS_PER_MATRIX].setRGB(r,g,b);
      leds[pos + 3 * NUM_LEDS_PER_MATRIX].setRGB(r,g,b);
    }
    counter ++;
  }
  
}
