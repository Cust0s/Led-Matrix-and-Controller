void anim_eachPixel(){
  //---extend and duplicate mode---
  //speedFader = animation speed
  //brightnessFader = brightness

  if(counter >=  map(getSpeedFader(), 0, 1023, 10, 1)){
    counter = 1;
  }

  
  if(counter2 >= 100){
    counter2 = 0;
  }

  fadeToBlackBy( leds, NUM_LEDS, map(getBrightnessFader(), 0, 1023, 0, 255));
  

  
  //counter = counter + map(getSpeedFader(), 0, 1023, 1, 20);


  byte r = map(getRedFader(),0,1023,0,255);
  byte g = map(getGreenFader(),0,1023,0,255);
  byte b = map(getBlueFader(),0,1023,0,255);

  if(counter <= 1){
    leds[counter2].setRGB(r,g,b);
    leds[counter2 + NUM_LEDS_PER_MATRIX].setRGB(r,g,b);
    leds[counter2 + 2 * NUM_LEDS_PER_MATRIX].setRGB(r,g,b);
    leds[counter2 + 3 * NUM_LEDS_PER_MATRIX].setRGB(r,g,b);
    counter2++;
  }

  counter++;
}
