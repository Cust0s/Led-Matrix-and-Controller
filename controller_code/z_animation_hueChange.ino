void anim_hueChange(){
  //---extend and duplicate mode---
  //speedFader = animation speed
  //brightnessFader = brightness
  
  if(counter >= 2560){
    counter = 0;
  }
  for(int i = 0; i < NUM_LEDS; i++){
    //leds[i].setHue(counter);
    leds[i] = CHSV( counter/10, 255, map(getBrightnessFader(), 0, 1023, 0, 255));
  }
  
  counter = counter + map(getSpeedFader(), 0, 1023, 1, 20);
}
