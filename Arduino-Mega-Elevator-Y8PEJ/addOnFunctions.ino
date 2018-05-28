
/*
   Add the Tray given in parameter to the Tray Register
*/
void addToTrayReg(Tray addTray)
{
  //Check if it is the first tray, If not, then continue as usual
  if (trayReg.nrOfTrays == 0)
  {
    addTray.trayNumber = 1;
    trayReg.nrOfTrays = 1;
    trayReg.trayList[0] = addTray;
  }
  else
  {
    int newTotal = (trayReg.nrOfTrays + 1);
    trayReg.nrOfTrays = (trayReg.nrOfTrays + 1);
    addTray.trayNumber = newTotal;
    trayReg.trayList[newTotal - 1] = addTray;
  }
  
    if(debug){
    Serial.println("Tray added to reg"); 
  }
}

/**
   Create a tray and add it to the register
*/
void createTrayOnPos()
{
  
  Tray newTray;
  //Save the current position
  newTray.zPos.zLeft = currentPos.zLeft;
  newTray.zPos.zRight = currentPos.zRight;

  //Add a new tray to the register
  if(debug){
    Serial.println("Tray made"); 
  }
  addToTrayReg(newTray);
}


/**
   Check failure and return the given failure state'
   By checking all the bool values, the last one will have the "highest" priority.
*/
state checkFailure()
{
  state returnState = fail;
  //Safety barrier
  if (topSafetyBarrier)
  {
    inState = safetySwitchUpper;
  }
  
  if (bottomSafetyBarrier)
  {
    inState = safetySwitchLower;
  }
  
  if (leftBottomSwitch)
  {
    inState = elevatorLimitTrigg;
  }
  
  if (leftTopSwitch)
  {
    inState = elevatorLimitTrigg;
  }
  
  if (rightBottomSwitch)
  {
    inState = elevatorLimitTrigg;
  }
  
  if (rightTopSwitch)
  {
    inState = elevatorLimitTrigg;
  }


  return returnState;
}




/**
 * Update the status to given status and notify over serial com
 */
void updateStatusAndNotify(byte state) {
  //Check if state is changed
  if (inState != state) {
    inState = state;
    sendInt(inState);
  }
}

