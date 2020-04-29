void anim_diagonal(byte flow){
  //---extend and duplicate mode---
  //brightnessFader = brightness
  //speedFader = animation speed
  if(counter >= 2560){
    counter = 0;
  }
  //calculate the no of slices
  int maxSlice = 2 * W_AND_H - 1;

  //loop through slices
  for(int slice = 0; slice < maxSlice; slice++){
    //select the brightness for the slice
    int z;
    if(slice < W_AND_H){
      z = 0;
    } else{
      z = slice - W_AND_H + 1;
    }
    for(int j = z; j <= slice - z; j++){
      //x coordinate is simple, but because it is actually an array, not a 2D array,
      //every next row is dependent upon the total width/height. So each next row is
      //the resulting matrix index multiplied with the width/height.
      //(slice-j) is taken from the website
      int xCoord = j;
      int yCoord = (slice-j)*W_AND_H;
        //hue is gonna be different depending on the slice,
        //the counter therefore needs to be dynamically adjusted to the slice

        //defines which way the color flows
        int hue;
        if(flow == 0b0000){
          //towards top right
          hue = counter/10 + (slice-j) - xCoord;
        } else if(flow == 0b0001){
          //towards bottom right
          hue = counter/10 - (slice-j) - xCoord;
        } else if(flow == 0b0010){
          //towards bottom left
          hue = counter/10 - (slice-j) + xCoord;
        } else if(flow == 0b0011){
          //towards top left
          hue = counter/10 + (slice-j) + xCoord;
        }
        
        if(hue < 0){
          hue = 255+hue;
        }
        if(hue > 255){
          hue = 0 + hue;
        }
        //the resulting index is xCoord+yCoord
        //leds[xCoord+yCoord].setHue(hue);
        leds[xCoord+yCoord] = CHSV( hue, 255, map(getBrightnessFader(), 0, 1023, 0, 255));
      }
  }
  
  counter = counter + map(getSpeedFader(), 0, 1023, 1, 50);
}
