void printAnimationText(int animation){
  //general table with headers
  //-display 1-
  display1.clearDisplay();
  display1.setTextSize(1);
  display1.setTextColor(WHITE);

  display1.drawFastHLine(0, 37, 128, WHITE);
  display1.drawFastHLine(0, 36, 128, WHITE);
  display1.drawFastVLine(42, 38, 64, WHITE);
  display1.drawFastVLine(85, 38, 64, WHITE);
  display1.drawFastHLine(0, 47, 128, WHITE);

  //first column
  display1.setCursor(4,39);
  display1.print(" LEFT");

  //second column
  display1.setCursor(47,39);
  display1.print("MIDDLE");

  //third column
  display1.setCursor(88,39);
  display1.print(" RIGHT");

  //-additional information-
  //matrix mode
  display1.setCursor(0,0);
  if(switchPos){
    display1.print("Extended Matrix Mode");
  }else{
    display1.print("Duplicate Matrix Mode");
  }

  //-display 2-
  display2.clearDisplay();
  display2.setTextSize(1);
  display2.setTextColor(WHITE);

  display2.drawFastHLine(0, 37, 128, WHITE);
  display2.drawFastHLine(0, 36, 128, WHITE);
  display2.drawFastVLine(42, 38, 64, WHITE);
  display2.drawFastVLine(85, 38, 64, WHITE);
  display2.drawFastHLine(0, 47, 128, WHITE);

  //first column
  display2.setCursor(4,39);
  display2.print(" LEFT");

  //second column
  display2.setCursor(47,39);
  display2.print("MIDDLE");

  //third column
  display2.setCursor(88,39);
  display2.print(" RIGHT");
  
  
  switch(animation){
    //Twinkle RGB
    case 0:
      //-display 1-
      //first column
      display1.setCursor(0,49);
      display1.print("  Red");
      
      display1.setCursor(0,57);
      display1.print(" value");

      //second column
      display1.setCursor(44,49);
      display1.print(" Green");
      
      display1.setCursor(44,57);
      display1.print(" value");

      //third column
      display1.setCursor(90,49);
      display1.print(" Blue");
      
      display1.setCursor(87,57);
      display1.print(" value");

      //-display 2-
      //first column
      display2.setCursor(1,49);
      display2.print("New p");
      display2.setCursor(30,49);
      display2.print("i");
      display2.setCursor(35,49);
      display2.print("x");
      
      display2.setCursor(0,57);
      display2.print(" speed");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(88,49);
      display2.print("Twink");
      display2.setCursor(116,49);
      display2.print("l");
      display2.setCursor(121,49);
      display2.print("e");
      
      display2.setCursor(90,57);
      display2.print(" fade");
      break;
    //Twinkle Rand
    case 1:
      //-display 1-
      //first column
      display1.setCursor(0,49);
      display1.print("  not");
      
      display1.setCursor(2,57);
      display1.print(" used");

      //second column
      display1.setCursor(44,49);
      display1.print("  not");
      
      display1.setCursor(46,57);
      display1.print(" used");

      //third column
      display1.setCursor(88,49);
      display1.print("Twink");
      display1.setCursor(116,49);
      display1.print("l");
      display1.setCursor(121,49);
      display1.print("e");
      
      display1.setCursor(90,57);
      display1.print(" fade");

      //-display 2-
      //first column
      display2.setCursor(0,49);
      display2.print("New pix");
      
      display2.setCursor(0,57);
      display2.print(" speed");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(86,49);
      display2.print(" Brigh");
      display2.drawFastHLine(123, 52, 3, WHITE);
      
      display2.setCursor(87,57);
      display2.print(" tness");
      break;
    //Twinkle Hue
    case 2:
      //-display 1-
      //first column
      display1.setCursor(0,49);
      display1.print("  Hue");
      
      display1.setCursor(0,57);
      display1.print(" speed");

      //second column
      display1.setCursor(44,49);
      display1.print("  not");
      
      display1.setCursor(46,57);
      display1.print(" used");

      //third column
      display1.setCursor(88,49);
      display1.print("Twink");
      display1.setCursor(116,49);
      display1.print("l");
      display1.setCursor(121,49);
      display1.print("e");
      
      display1.setCursor(90,57);
      display1.print(" fade");

      //-display 2-
      //first column
      display2.setCursor(0,49);
      display2.print("New pix");
      
      display2.setCursor(0,57);
      display2.print(" speed");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(86,49);
      display2.print(" Brigh");
      display2.drawFastHLine(123, 52, 3, WHITE);
      
      display2.setCursor(87,57);
      display2.print(" tness");
      break;
    //Hue Change
    case 3:
      //-display 1-
      //first column      
      display1.setCursor(0,49);
      display1.print("  not");
      
      display1.setCursor(2,57);
      display1.print(" used");

      //second column
      display1.setCursor(44,49);
      display1.print("  not");
      
      display1.setCursor(46,57);
      display1.print(" used");

      //third column
      display1.setCursor(87,49);
      display1.print("  not");
      
      display1.setCursor(90,57);
      display1.print(" used");

      //-display 2-
      //first column
      display2.setCursor(0,49);
      display2.print("  Hue");
      
      display2.setCursor(0,57);
      display2.print(" speed");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(86,49);
      display2.print(" Brigh");
      display2.drawFastHLine(123, 52, 3, WHITE);
      
      display2.setCursor(87,57);
      display2.print(" tness");
      break;
    //Flame
    case 4:
      //-display 1-
      //first column
      display1.setCursor(0,49);
      display1.print("  Red");
      
      display1.setCursor(0,57);
      display1.print(" value");

      //second column
      display1.setCursor(44,49);
      display1.print(" Green");
      
      display1.setCursor(44,57);
      display1.print(" value");

      //third column
      display1.setCursor(90,49);
      display1.print(" Blue");
      
      display1.setCursor(87,57);
      display1.print(" value");

      //-display 2-
      //first column
      display2.setCursor(1,49);
      display2.print("New p");
      display2.setCursor(30,49);
      display2.print("i");
      display2.setCursor(35,49);
      display2.print("x");
      
      display2.setCursor(0,57);
      display2.print(" speed");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(88,49);
      display2.print("Twink");
      display2.setCursor(116,49);
      display2.print("l");
      display2.setCursor(121,49);
      display2.print("e");
      
      display2.setCursor(90,57);
      display2.print(" fade");
      break;
    //Diagonal1
    case 5:
      //-display 1-
      //first column      
      display1.setCursor(0,49);
      display1.print("  not");
      
      display1.setCursor(2,57);
      display1.print(" used");

      //second column
      display1.setCursor(44,49);
      display1.print("  not");
      
      display1.setCursor(46,57);
      display1.print(" used");

      //third column
      display1.setCursor(87,49);
      display1.print("  not");
      
      display1.setCursor(90,57);
      display1.print(" used");

      //-display 2-
      //first column
      display2.setCursor(0,49);
      display2.print("  Hue");
      
      display2.setCursor(0,57);
      display2.print(" speed");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(86,49);
      display2.print(" Brigh");
      display2.drawFastHLine(123, 52, 3, WHITE);
      
      display2.setCursor(87,57);
      display2.print(" tness");
      break;
    //Diagonal2
    case 6:
      //-display 1-
      //first column      
      display1.setCursor(0,49);
      display1.print("  not");
      
      display1.setCursor(2,57);
      display1.print(" used");

      //second column
      display1.setCursor(44,49);
      display1.print("  not");
      
      display1.setCursor(46,57);
      display1.print(" used");

      //third column
      display1.setCursor(87,49);
      display1.print("  not");
      
      display1.setCursor(90,57);
      display1.print(" used");

      //-display 2-
      //first column
      display2.setCursor(0,49);
      display2.print("  Hue");
      
      display2.setCursor(0,57);
      display2.print(" speed");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(86,49);
      display2.print(" Brigh");
      display2.drawFastHLine(123, 52, 3, WHITE);
      
      display2.setCursor(87,57);
      display2.print(" tness");
      break;
    //Diagonal3
    case 7:
      //-display 1-
      //first column      
      display1.setCursor(0,49);
      display1.print("  not");
      
      display1.setCursor(2,57);
      display1.print(" used");

      //second column
      display1.setCursor(44,49);
      display1.print("  not");
      
      display1.setCursor(46,57);
      display1.print(" used");

      //third column
      display1.setCursor(87,49);
      display1.print("  not");
      
      display1.setCursor(90,57);
      display1.print(" used");

      //-display 2-
      //first column
      display2.setCursor(0,49);
      display2.print("  Hue");
      
      display2.setCursor(0,57);
      display2.print(" speed");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(86,49);
      display2.print(" Brigh");
      display2.drawFastHLine(123, 52, 3, WHITE);
      
      display2.setCursor(87,57);
      display2.print(" tness");
      break;
    //Diagonal4
    case 8:
      //-display 1-
      //first column      
      display1.setCursor(0,49);
      display1.print("  not");
      
      display1.setCursor(2,57);
      display1.print(" used");

      //second column
      display1.setCursor(44,49);
      display1.print("  not");
      
      display1.setCursor(46,57);
      display1.print(" used");

      //third column
      display1.setCursor(87,49);
      display1.print("  not");
      
      display1.setCursor(90,57);
      display1.print(" used");

      //-display 2-
      //first column
      display2.setCursor(0,49);
      display2.print("  Hue");
      
      display2.setCursor(0,57);
      display2.print(" speed");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(86,49);
      display2.print(" Brigh");
      display2.drawFastHLine(123, 52, 3, WHITE);
      
      display2.setCursor(87,57);
      display2.print(" tness");
      break;
    //Dead Channel
    case 9:
      //-display 1-
      //first column      
      display1.setCursor(0,49);
      display1.print("  not");
      
      display1.setCursor(2,57);
      display1.print(" used");

      //second column
      display1.setCursor(44,49);
      display1.print("  not");
      
      display1.setCursor(46,57);
      display1.print(" used");

      //third column
      display1.setCursor(87,49);
      display1.print("  not");
      
      display1.setCursor(90,57);
      display1.print(" used");

      //-display 2-
      //first column
      display2.setCursor(0,49);
      display2.print("  not");
      
      display2.setCursor(2,57);
      display2.print(" used");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(87,49);
      display2.print("  not");
      
      display2.setCursor(90,57);
      display2.print(" used");
      break;
    //Solid Pulse
    case 10:
      //-display 1-
      //first column      
      display1.setCursor(0,49);
      display1.print("  not");
      
      display1.setCursor(2,57);
      display1.print(" used");

      //second column
      display1.setCursor(44,49);
      display1.print("  not");
      
      display1.setCursor(46,57);
      display1.print(" used");

      //third column
      display1.setCursor(87,49);
      display1.print("  not");
      
      display1.setCursor(90,57);
      display1.print(" used");

      //-display 2-
      //first column
      display2.setCursor(0,49);
      display2.print(" Pulse");
      
      display2.setCursor(0,57);
      display2.print(" speed");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(86,49);
      display2.print(" Brigh");
      display2.drawFastHLine(123, 52, 3, WHITE);
      
      display2.setCursor(87,57);
      display2.print(" tness");
      break;
    //Hue Pulse
    case 11:
      //-display 1-
      //first column      
      display1.setCursor(0,49);
      display1.print("  not");
      
      display1.setCursor(2,57);
      display1.print(" used");

      //second column
      display1.setCursor(44,49);
      display1.print("  not");
      
      display1.setCursor(46,57);
      display1.print(" used");

      //third column
      display1.setCursor(86,49);
      display1.print(" Brigh");
      display1.drawFastHLine(123, 52, 3, WHITE);
      
      display1.setCursor(87,57);
      display1.print(" tness");

      //-display 2-
      //first column
      display2.setCursor(0,49);
      display2.print("  Hue");
      
      display2.setCursor(0,57);
      display2.print(" speed");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(87,49);
      display2.print(" Pulse");
      
      display2.setCursor(87,57);
      display2.print(" speed");
      break;
    //Test
    case 12:
      break;
    //default
    default:
      //-display 1-
      //first column      
      display1.setCursor(0,49);
      display1.print("  not");
      
      display1.setCursor(2,57);
      display1.print(" used");

      //second column
      display1.setCursor(44,49);
      display1.print("  not");
      
      display1.setCursor(46,57);
      display1.print(" used");

      //third column
      display1.setCursor(87,49);
      display1.print("  not");
      
      display1.setCursor(90,57);
      display1.print(" used");

      //-display 2-
      //first column
      display2.setCursor(0,49);
      display2.print("  not");
      
      display2.setCursor(2,57);
      display2.print(" used");

      //second column
      display2.setCursor(44,49);
      display2.print("  not");
      
      display2.setCursor(46,57);
      display2.print(" used");

      //third column
      display2.setCursor(87,49);
      display2.print("  not");
      
      display2.setCursor(90,57);
      display2.print(" used");
      break;
  }
  display1.display();
  display2.display();
}
