/*
 * needs to be preceeded by LEDS.show();
 */
void sendToJava(){
  //send the pot values first
  //Serial.print(getRedFader());
  Serial.print(getFader1());
  Serial.print(",");
  //Serial.print(getGreenFader());
  Serial.print(getFader2());
  Serial.print(",");
  //Serial.print(getBlueFader());
  Serial.print(getFader3());
  Serial.print(",");
  //Serial.print(getSpeedFader());
  Serial.print(getFader4());
  Serial.print(",");
  //Serial.print(getBrightnessFader());
  Serial.print(getFader5());
  Serial.print(",");
  //unused and can be replaced with fader 6
  //Serial.print(digitalRead(TOP_SWITCH));
  Serial.print(getFader6());
  Serial.print(",");
  Serial.print(digitalRead(BOTTOM_SWITCH));
  Serial.print(",");

  //send the rgb matrix
  for(int i = 0; i < NUM_LEDS; i++){
    Serial.print(leds[i].r);
    Serial.print(",");
    Serial.print(leds[i].g);
    Serial.print(",");
    Serial.print(leds[i].b);
    if(i !=(NUM_LEDS - 1)){
      Serial.print(",");
    }
  }
  Serial.println("");
}
