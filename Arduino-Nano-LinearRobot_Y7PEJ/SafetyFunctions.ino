/*** All the safety functions ***/



//Set the 
void stopMotors() {
  mainCommand = stopRobot;
}







/**
   Checks the limit switches and sets the appropriate bools
*/
bool limitTrigged()
{
  bool limitIsTrigged = false;

  //Check the X home switch
  if (!digitalRead(X_HOME_SWITCH))
  {
    xHomeSwitch = true;
    limitIsTrigged = true;
  }
  else
  {
    xHomeSwitch = false;
  }

  //Check the X outer switch
  if (!digitalRead(X_OUTER_SWITCH))
  { 
    xAwaySwitch = true;
    limitIsTrigged = true;
  }
  else
  {
    xAwaySwitch = false;
  }

  //Check the Y Home switch
  if (!digitalRead(Y_HOME_SWITCH))
  { 
    yHomeSwitch = true;
    limitIsTrigged = true;
  }
  else
  {
    yHomeSwitch = false;
  }

  //Check the Y outer switch
  if (!digitalRead(Y_OUTER_SWITCH))
  {
    yAwaySwitch = true;
    limitIsTrigged = true;
  }
  else
  {
    yAwaySwitch = false;
  }


  return limitIsTrigged;
}





