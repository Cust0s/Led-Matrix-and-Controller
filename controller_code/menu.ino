/*
 * Calls the printMenu function if the menu item
 * array has at least two items in it.
 */
void menuSetup(){
  //at least two menu items exist
  if(MENU_SIZE >= 2){
    printMenu();
    //reset the counter variable used by some of the animations
    counter = 0;
    counter2 = 0;
  }
}

/*
 * Moves the menu one item up.
 * Calls the printMenu function afterwards.
 */
void menuUp(){
  if(menuPosition == MENU_SIZE - 1){
    menuPosition = 0;
  } else{
    menuPosition++;
  }
  printMenu();
}

/*
 * Moves the menu one item down.
 * Calls the printMenu function afterwards.
 */
void menuDown(){
if(menuPosition <= 0){
    menuPosition = MENU_SIZE - 1;
  } else{
    menuPosition--;
  }
  
  printMenu();
}


/*
 * Prints the two current active items on the menu.
 * Checks for overflow of the Array.
 * Prints selected items in uppercase.
 */
void printMenu(){
  display3.clearDisplay();
  display3.setCursor(0,12);
  //make the selected item uppercase
  if(menuPosition == selectedItem){
    temp = "-";
    temp += menu[menuPosition].substring(1);
    displayString(temp);
  } else{
    displayString(menu[menuPosition]);
  }

  
  display3.setCursor(0,27);
  if(menuPosition+1 >= MENU_SIZE){
    if(selectedItem == 0){
      temp = "-";
      temp += menu[0].substring(1);
      displayString(temp);
    } else{
      displayString(menu[0]);
    }
  } else {
    if(menuPosition+1 == selectedItem){
      temp = "-";
      temp += menu[menuPosition+1].substring(1);
      displayString(temp);
    } else{
      displayString(menu[menuPosition+1]);
    }
  }

  
  display3.setCursor(0,42);
  if(menuPosition+2 >= MENU_SIZE){
    
    //menu position = last index
    if(menuPosition+2 >= MENU_SIZE + 1){
      if(selectedItem == 1){
        temp = "-";
        temp += menu[1].substring(1);
        displayString(temp);
      } else{
        displayString(menu[1]);
      }
    } 
    
    //menu position = last index -1
    else {
      if(selectedItem == 0){
        temp = "-";
        temp += menu[0].substring(1);
        displayString(temp);
      } else{
        displayString(menu[0]);
      }
    }
  } else {
    if(menuPosition+2 == selectedItem){
      temp = "-";
      temp += menu[menuPosition+2].substring(1);
      displayString(temp);
    } else{
      displayString(menu[menuPosition+2]);
    }
  } 
}

void displayString(String data){
  /*if(data == "Diagonal1" || data == "DIAGONAL1"){
    data = data.substring(0,8) += " ";
    lcd.print(data);
    lcd.write(byte(0));
  }else if(data == "Diagonal2" || data == "DIAGONAL2"){
    data = data.substring(0,8) += " ";
    lcd.print(data);
    lcd.write(byte(1));
  }else if(data == "Diagonal3" || data == "DIAGONAL3"){
    data = data.substring(0,8) += " ";
    lcd.print(data);
    lcd.write(byte(2));
  }else if(data == "Diagonal4" || data == "DIAGONAL4"){
    data = data.substring(0,8) += " ";
    lcd.print(data);
    lcd.write(byte(3));
  } else {
    lcd.print(data);
  }*/
  display3.setTextSize(1);
  display3.setTextColor(WHITE);
  
  display3.println(data);
  display3.drawFastHLine(0, 45, 128, WHITE);
  display3.display();
}
