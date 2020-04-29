void anim_twinkleHue(){
  if(switchPos){
    //---extend mode---
    //speedFader = speed of new pixels appearing up to 1 pixel per loop max speed
    //brightnessFader = brightness
    //blueFader = twinkle disappearance, higher fader = faster disappearing pixels
    //redFader = hue change speed
  
    if(counter2 >= 256){
      counter2 = 0;
    }
    
    if(counter >=  map(getSpeedFader(), 0, 1023, 10, 1)){
      counter = 1;
    }
    
    // random colored speckles that blink in and fade smoothly
    fadeToBlackBy( leds, NUM_LEDS, map(getBlueFader(), 0, 1023, 0, 255));
  
    int pos = random16(NUM_LEDS);
  
    
    if(counter <= 1){
      leds[pos] += CHSV(counter2, 255, map(getBrightnessFader(), 0, 1023, 0, 255));
    }
    counter ++;
    counter2 = counter2 + map(getRedFader(), 0, 1023, 1, 5);
  } else{
    //---duplicate mode---

    //speedFader = speed of new pixels appearing up to 1 pixel per loop max speed
    //brightnessFader = brightness
    //blueFader = twinkle disappearance, higher fader = faster disappearing pixels
    //redFader = hue change speed
  
    if(counter2 >= 256){
      counter2 = 0;
    }
    
    if(counter >=  map(getSpeedFader(), 0, 1023, 10, 1)){
      counter = 1;
    }
    
    // random colored speckles that blink in and fade smoothly
    fadeToBlackBy( leds, NUM_LEDS, map(getBlueFader(), 0, 1023, 0, 255));
  
    //int pos = random16(NUM_LEDS);
    int pos = random16(NUM_LEDS / NUM_MATRICES);
    
    if(counter <= 1){
      leds[pos] += CHSV(counter2, 255, map(getBrightnessFader(), 0, 1023, 0, 255));
      leds[pos + NUM_LEDS_PER_MATRIX] += CHSV(counter2, 255, map(getBrightnessFader(), 0, 1023, 0, 255));
      leds[pos + 2 * NUM_LEDS_PER_MATRIX] += CHSV(counter2, 255, map(getBrightnessFader(), 0, 1023, 0, 255));
      leds[pos + 3 * NUM_LEDS_PER_MATRIX] += CHSV(counter2, 255, map(getBrightnessFader(), 0, 1023, 0, 255));
    }
    counter ++;
    counter2 = counter2 + map(getRedFader(), 0, 1023, 1, 5);
  }
}
