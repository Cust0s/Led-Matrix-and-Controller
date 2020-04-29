//reads the rgb faders and pulses that colour at different speeds depending on the speed fader

//counter = hue
//counter2 = brightness
//counter3 = 1 increment or 0 decrement


//speedFader = pulse speed
//brightnessFader = brightness min/ darkest the pulse will get


void anim_solidPulse(){
  //reset counters
  if(counter >= 256){
    counter = 0;
  }
  byte brightnessFader= map(getBrightnessFader(), 0, 1023, 0, 253);
  if(counter2 >= 256){
    counter2 = 255;
    counter3 = 0;
  } else if(counter2 <= brightnessFader){
    counter2 = brightnessFader+1;
    counter3 = 1;
  }




  byte r = map(getRedFader(),0,1023,0,255);
  byte g = map(getGreenFader(),0,1023,0,255);
  byte b = map(getBlueFader(),0,1023,0,255);
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i].setRGB(r,g,b);
    leds[i].nscale8_video(counter2);
  }

  if(counter3 == 1){
    counter2 = counter2 + map(getSpeedFader(), 0, 1023, 1, 15);
  } else {
    counter2 = counter2 - map(getSpeedFader(), 0, 1023, 1, 15);
  }
}
