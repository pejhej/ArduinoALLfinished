



void stopMotors() {
  mainCommand = stopRobot;
}

/**
    Check all the end stop sensors.
    Will set all the appropriate bools.
    Returns true if one or more sensors is trigged
*/
bool limitTrigged()
{
  bool limitIsTrigged = false;

  //Left bottom switch, set Return to true
  if (!digitalRead(LEFT_BOTTOM_SWITCH))
  {
    leftBottomSwitch = true;
    limitIsTrigged = true;
  }
  //Set return to false
  else
  {
    leftBottomSwitch = false;
  }
  
  //Left top switch, set Return to true
  if (!digitalRead(LEFT_TOP_SWITCH))
  { leftTopSwitch = true;
    limitIsTrigged = true;
  }
  //Set return to false
  else
  {
    leftTopSwitch = false;
  }
  
  //Right bottom switch, set Return to true
  if (!digitalRead(RIGHT_BOTTOM_SWITCH))
  { rightBottomSwitch = true;
    limitIsTrigged = true;
  }
  //Set return to false
  else
  {
    rightBottomSwitch = false;
  }

  //Right top switch, set Return to true
  if (!digitalRead(RIGHT_TOP_SWITCH))
  {
    rightTopSwitch = true;
    limitIsTrigged = true;
  }
  //Set return to false
  else
  {
    rightTopSwitch = false;
  }


  return limitIsTrigged;
}


/*
   Return the state of the safety barrier(trigged TRUE else false) and set the respective booleans
*/
boolean safetyBarrier()
{
  boolean barrierTrigged = false;

  //Check Top IR sensor
  if (!digitalRead(TOP_IR_RELAY))
  {
    topSafetyBarrier = true;
    barrierTrigged = true;
  }
  else
  {
      topSafetyBarrier = false;
  }

  //Check bottom IR sensor
  if (!digitalRead(BOTTOM_IR_RELAY))
  {
    bottomSafetyBarrier = true;
    barrierTrigged = true;
  }
  else
  {
      bottomSafetyBarrier = false;
  }
  
  //Return the 
  return barrierTrigged;
}

/**
   Returns state of top barrier
*/
boolean safetyBarrierTop()
{
  boolean barrierTrigged = false;

  if (!digitalRead(TOP_IR_RELAY))
  {
    topSafetyBarrier = true;
    barrierTrigged = true;
  }
  else
  {
      topSafetyBarrier = false;
  }

  return barrierTrigged;
}
/**
   Increase the active barriers
*/
void increaseActiveBarrier()
{
  updateCntTopBarrier();
  updateCntBottomBarrier();
}

/**
   Update the top barrier counter
*/
void updateCntTopBarrier()
{
  if (topSafetyBarrier)
  {
    barrierCounterTop += dirZLeft(newPos.zLeft);
  }
  else
  {
    barrierCounterTop = 0;
  }
}
/**
   Update the bottom barrier counter
*/
void updateCntBottomBarrier()
{
  if (bottomSafetyBarrier)
  {
    //Check if the robot is moving upwards, and if the bottom sensor is trigged, dont count
    if(!(LEFT_DIR_UP == dirZLeft(newPos.zLeft)))
    {
      barrierCounterBottom += dirZRight(newPos.zRight);
    }
    //else, dont count
  }
  else
  {
    barrierCounterBottom = 0;
  }
}


/**
   Returns true if the safety counters is exceeded
*/
boolean counterExceeded()
{
  boolean failure = false;

  //Check the counters
  if ((barrierCounterTop > (flagDetectionSteps + safetyFactorOffset)) || (barrierCounterBottom > (flagDetectionSteps + safetyFactorOffset)))
  {
    failure = true;
  }

  return failure;
}


/**
   Returns state of bottom barrier
*/
boolean safetyBarrierBottom()
{
  boolean barrierTrigged = false;

  if (!digitalRead(BOTTOM_IR_RELAY))
  {
    bottomSafetyBarrier = true;
    barrierTrigged = true;
  }
  else
  {
    if (bottomSafetyBarrier)
    {
      bottomSafetyBarrier = false;
    }
  }
  return barrierTrigged;
}



/**
   Function to check if the new direction is safe
*/
boolean isDirectionSafe(Pos newPos)
{

  //The return bool if direction is safe
  boolean safe = false;
  if (debug == 2) {
    Serial.println("YOU FOUND WALDO");
  }
  //Check which switch is activated
  if (leftBottomSwitch)
  {
    //Check new direction of given new pos
    if (dirZLeft(newPos.zLeft) == LEFT_DIR_UP)
    {
      safe = true;
    }
  }

  //Check which switch is activated
  if (rightBottomSwitch)
  {
    //Check new direction of given new pos
    if (dirZRight(newPos.zRight) == RIGHT_DIR_UP)
    {
      safe = true;
    }
  }

  //Check which switch is activated
  if (leftTopSwitch)
  {
    //Check new direction of given new pos
    if (dirZLeft(newPos.zLeft) == LEFT_DIR_DOWN)
    {
      safe = true;
    }
  }

  //Check which switch is activated
  if (rightTopSwitch)
  {
    //Check new direction of given new pos
    if (dirZRight(newPos.zRight) == RIGHT_DIR_DOWN)
    {
      safe = true;
    }
  }


  return safe;

}







/**
   Toggle the bool given to this function
*/
boolean toggleBool(boolean toggleThis)
{

  //Check if its high
  if (toggleThis)
  {
    toggleThis = false;
  }
  else if (!toggleThis)
  {
    toggleThis = true;
  }

  return toggleThis;
}













/*if (Y_HOME_SWITCH == triggedSwitch)
  {

  }
  else if (Y_AWAY_SWITCH == triggedSwitch)
  {

  }
  else if (X_HOME_SWITCH == triggedSwitch)
  {

  }
  else if (Y_AWAY_SWITCH == triggedSwitch)
  {

  }
*/

