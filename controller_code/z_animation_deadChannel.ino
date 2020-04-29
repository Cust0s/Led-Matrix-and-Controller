void anim_deadChannel() {
  if(switchPos){
    //---extend mode---
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(0, 0, random8(255));
    }
  } else{
    //---duplicate mode---
    for (int i = 0; i < NUM_LEDS / NUM_MATRICES; i++) {
      uint8_t randomBrightness = random8(255);
      leds[i] = CHSV(0, 0, randomBrightness);
      leds[i + NUM_LEDS_PER_MATRIX] = CHSV(0, 0, randomBrightness);
      leds[i + 2 * NUM_LEDS_PER_MATRIX] = CHSV(0, 0, randomBrightness);
      leds[i + 3 * NUM_LEDS_PER_MATRIX] = CHSV(0, 0, randomBrightness);
    }
  }
}
