//Author: Bruce Allen
//Date: 23/07/09


const int pwPin = 10; 
const int channel = 3;

//variables needed to store values
long pulse, inches, cm;

void setup() {
}

void loop() {

  pinMode(pwPin, INPUT);
    //Used to read in the pulse that is being sent by the MaxSonar device.
  //Pulse Width representation with a scale factor of 147 uS per Inch.

  pulse = pulseIn(pwPin, HIGH);
  //147uS per inch
  inches = pulse/147;
  usbMIDI.sendControlChange(7, inches, channel);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.println();
  delay(50);
}
