/***** Functions responseble for sending data over an serial communication. ****/

// Sends one byte over and serial communication using string.
// Uses devise name in front and devide the byte witn an , as delimiter
// It writes to the serial bus.


//Send one int to the serial port
void sendInt(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     int intToSend) {
  //Make the string, with device ID, int and ending
  String stringToSend = DEVICE_NAME;
  stringToSend = stringToSend + ",";
  stringToSend = stringToSend + intToSend;
  stringToSend = stringToSend + "\n";

  // Make char pointer and dynamically allocate the memory for all the chars the pointer have access to
  char* cString = (char*) malloc(sizeof(char) * (stringToSend.length() + 1));
  stringToSend.toCharArray(cString, stringToSend.length() + 1);
  
  //Send the chars to the serial port
  Serial.write(cString);
  // Free the allocated memory.
  free(cString);

  if (debug) {
    Serial.println();
  }
}



// Sends multiple integers to the serial port.
void sendIntegers(int integers[], int arrayLength) {
  
  String stringToSend = DEVICE_NAME;
  //Iterate the integer array and add them to a String.
  for (int i = 0; i <  arrayLength; i++) {
    stringToSend = stringToSend + ",";
    stringToSend = stringToSend + integers[i];
  }
  //Set END to string
  stringToSend = stringToSend + "\n";


  //Make char string from arduino string by memory allocating the array.
  //Give the char pointer the memory for all the chars it should have control over
  char* cString = (char*) malloc(sizeof(char) * (stringToSend.length() + 1));
  //Use toChar function to split all the char's in the string. They will be allocated to the memory the pointer has control of.
  stringToSend.toCharArray(cString, stringToSend.length() + 1);
  
  //Send all the chars to the serial port
  Serial.write(cString);
  
  // Free the allocated memory.
  free(cString);
  
  if (debug) {
    Serial.println();
  }
}



