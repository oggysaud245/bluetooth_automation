#define relay1 5
#define relay2 6
void setup() {
  // set relay to output mode
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
//  send low signal initially
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
//  initialize the serial communication with 9600 baud rate
  Serial.begin(9600);

}

void loop() {
  // declare boolean variable determine the current state of relay
  static bool flag1 = false;
  static bool flag2 = false;
//  variable to hold the return message 
  static String cmd;
  if (Serial.available() > 0) { // checks of serial buffer
    byte c = Serial.read();     // variable to hold the incomming bye from serial
    Serial.println(c);        
    switch (c) {                           
      case 49:                  // executes when incomming byte is 49 equivalent to numeric 1 
        digitalWrite(relay1, flag1 = !flag1);     // write low voltage to pin when falg is true and hihg when flag is false
        cmd  = String(c) + ":Success";
        Serial.println(cmd);
        cmd = "Status: " + String((flag1==1)?"on":"off");
        Serial.println(cmd);
        break;
      case 50:                  // executes when incomming byte is 50 equivalent to numeric 2 
        digitalWrite(relay2, flag2 = !flag2);     // write low voltage to pin when falg is true and hihg when flag is false
        cmd  = String(c) + ":Success";
        Serial.println(cmd);
        cmd = "Status: " + String((flag2==1)?"on":"off");
        Serial.println(cmd);
        break;

    }
  }
}
