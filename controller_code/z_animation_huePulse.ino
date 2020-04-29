//pulses the hue change animation
//counter = hue
//counter2 = brightness
//counter3 = 1 increment or 0 decrement

//speedFader = speed of hue change 
//brightnessFader = pulse speed
//blueFader = brightness min/ darkest the pulse will get


void anim_huePulse(){
  //reset counters
  if(counter >= 256){
    counter = 0;
  }
  byte bluefader= map(getBlueFader(), 0, 1023, 0, 253);
  if(counter2 >= 256){
    counter2 = 255;
    counter3 = 0;
  } else if(counter2 <= bluefader){
    counter2 = bluefader+1;
    counter3 = 1;
  }

  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CHSV( counter, 255, counter2);
  }
  if(counter3 == 1){
    counter2 = counter2 + map(getBrightnessFader(), 0, 1023, 1, 15);
  } else {
    counter2 = counter2 - map(getBrightnessFader(), 0, 1023, 1, 15);
  }
  counter = counter + map(getSpeedFader(), 0, 1023, 1, 5);
  
}
