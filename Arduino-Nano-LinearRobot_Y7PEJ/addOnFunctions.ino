



  /**
   Check failure and return the given failure state
*/
state checkFailure()
{
  state returnState = fail;

  if (xHomeSwitch || xAwaySwitch || yHomeSwitch || yAwaySwitch )
  {
    inState = linearBotLimitTrigged;
  }

  return returnState;
}
/**
   Returns true if the robot is in same position as new-position. Ergo no moving required
*/
boolean robotInPosition()
{
  boolean inPos = false;
  if ((currentPos.x == newPos.x) && (currentPos.y == newPos.y))
  {
    inPos = true;
  }

  return inPos;
}

/**
 * Update the status to given status and notify over serial com
 */
void updateStatusAndNotify(byte state) {

  if (inState != state) 
  {
    inState = state;
    sendInt(inState);
  }
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













