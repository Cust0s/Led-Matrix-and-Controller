void anim_twinkleRND(){
  if(switchPos){
    //-----------------
    //---extend mode---
    //-----------------
    
    // speedFader = speed of new pixels appearing up to 1 pixel per loop max speed
    // brightnessFader = brightness
    // blueFader = twinkle disappearance, higher fader = faster disappearing pixels
  
    
    if(counter >=  map(getSpeedFader(), 0, 1023, 10, 1)){
      counter = 1;
    }
    
    // random colored speckles that blink in and fade smoothly
    fadeToBlackBy( leds, NUM_LEDS, map(getBlueFader(), 0, 1023, 0, 255));
  
    int pos = random16(NUM_LEDS);
  
    if(counter <= 1){
      leds[pos] += CHSV(random8(255), 255, map(getBrightnessFader(), 0, 1023, 0, 255));
    }
    counter ++;
  } else{
    //--------------------
    //---duplicate mode---
    //--------------------
    
    // speedFader = speed of new pixels appearing up to 1 pixel per loop max speed
    // brightnessFader = brightness
    // blueFader = twinkle disappearance, higher fader = faster disappearing pixels
  
    
    if(counter >=  map(getSpeedFader(), 0, 1023, 10, 1)){
      counter = 1;
    }
    
    // random colored speckles that blink in and fade smoothly
    fadeToBlackBy( leds, NUM_LEDS, map(getBlueFader(), 0, 1023, 0, 255));
  
    int pos = random16(NUM_LEDS / NUM_MATRICES);
  
    if(counter <= 1){
      uint8_t randomHue = random8(255);
      leds[pos] += CHSV(randomHue, 255, map(getBrightnessFader(), 0, 1023, 0, 255));
      leds[pos + NUM_LEDS_PER_MATRIX] += CHSV(randomHue, 255, map(getBrightnessFader(), 0, 1023, 0, 255));
      leds[pos + 2 * NUM_LEDS_PER_MATRIX] += CHSV(randomHue, 255, map(getBrightnessFader(), 0, 1023, 0, 255));
      leds[pos + 3 * NUM_LEDS_PER_MATRIX] += CHSV(randomHue, 255, map(getBrightnessFader(), 0, 1023, 0, 255));
    }
    counter ++;
  }
}
