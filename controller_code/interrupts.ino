void PinChange(){
  cli();
  //PTC11 Pin 38 pinB
  //PTC10 Pin 37 pinA
  reading = (GPIOE_PDIR >> 24);
  reading = reading & 0b0011;
  sum = sum | reading;
  

  if(sum == 0b0100 || sum == 0b1011){
    menuUp();
  }
  if(sum == 0b0111 || sum == 0b1000){
    menuDown();
  }
  sum <<= 2;  //move the reading to become the old reading
  sum = sum & 0b1100;   //delete everything but the old reading
  sei();
}

void EncoderPress(){
  cli();
  selectedItem = menuPosition;
  menuSetup();
  printAnimationText(selectedItem);
  /*
  display1.clearDisplay();
  display1.setCursor(0,12);
  display1.setTextSize(1);
  display1.setTextColor(WHITE);
  
  display1.println(selectedItem);
  display1.display();*/
  sei();
}

void TopSwitchChange(){
}

void BottomSwitchChange(){
  switchPos = !switchPos;
  printAnimationText(selectedItem);
  if(switchPos){
    W_AND_H = 20;
  }else{
    W_AND_H = 10;
  }
}

