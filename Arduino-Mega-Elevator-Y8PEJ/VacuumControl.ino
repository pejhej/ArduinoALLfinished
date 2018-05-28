/* Controlls the vacuum pump */
// Turns on vacumm pump
void turnVacuumOn() {
  digitalWrite(PUMP, HIGH);
}
// Turns off vacumm pump
void turnVacuumOff() {
  digitalWrite(PUMP, LOW);
}

/**
 * Turn the vacuum on off, with the given intervall by parameter
 */
void turnVacuumOnOff(int delayTime) {
  
  digitalWrite(PUMP, HIGH);
  delay(delayTime);
  digitalWrite(PUMP, LOW);
}
