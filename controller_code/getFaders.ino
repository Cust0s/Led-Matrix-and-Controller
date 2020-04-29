int getRedFader(){
  return 1023 - analogRead(RED);
}

int getGreenFader(){
  return 1023 - analogRead(GREEN);
}

int getBlueFader(){
  return 1023 - analogRead(BLUE);
}

int getSpeedFader(){
  return 1023 - analogRead(SPEED);
}

int getBrightnessFader(){
  return 1023 - analogRead(BRIGHTNESS);
}

int getFader1(){
  return 1023 - analogRead(FADER1);
}

int getFader2(){
  return 1023 - analogRead(FADER2);
}

int getFader3(){
  return 1023 - analogRead(FADER3);
}

int getFader4(){
  return 1023 - analogRead(FADER4);
}

int getFader5(){
  return 1023 - analogRead(FADER5);
}

int getFader6(){
  return 1023 - analogRead(FADER6);
}
