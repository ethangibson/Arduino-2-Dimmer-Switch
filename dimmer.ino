void setup() {
  // Set pin 9 to output because we want to send power to the breadboard from it
  // Pin 9 supports Pulse Width Modulation
  // PWM rapidly turns the digital signal on and off
  // This allows us to create a "dimmed effect with the LED"
  pinMode(9, OUTPUT);
  // Start the Serial interface so we can get data output from the board
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
    // get the value from the Analog pin 0 (this is where the dimmer switch it plugged in)
    int sensorValue = analogRead(0);
    // get the board to tell us what the value is (between 0 and 255)
    // we need to convert it to 255 because that is the number of steps available on PWM
    Serial.println(sensorValue / 4.01176470588); 
    // write the "analog" signal via PWM through digital pin 9
    analogWrite(9, (Pin/4.01176470588));
    delay(30);
}
