#include <MIDI.h>
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 16 servos, one after the other

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  500 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
  
  MIDI.begin(); 
  MIDI.setHandleNoteOn(HandleNoteOn);
  MIDI.setHandleNoteOff(HandleNoteOff);
  pwm.begin();
  pinMode(7, OUTPUT);
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}



void loop() {
  // Drive each servo one at a time
  MIDI.read();
  // Serial.println(servonum);
  
  
  // delay(500);

//  servonum ++;
  if (servonum > 15) servonum = 0;
}
void HandleNoteOn(byte channel, byte pitch, byte velocity) { 
  //openservo(LED);
  // openservo(0);

  // Do whatever you want when you receive a Note On.
  if(pitch==35){
    openservo(1);
  }
  
  if(pitch==36){
    openservo(1);
  }
    if(pitch==37){
    openservo(1);
  }
  
  if(pitch==38){
    openservo(1);
  }
    if(pitch==39){
    openservo(1);
  }
  
  if(pitch==40){
    openservo(1);
  }
    if(pitch==41){
    openservo(1);
  }
  
  if(pitch==42){
    openservo(1);
  }
  if(pitch==43){
    openservo(1);
  }
  
  if(pitch==44){
    openservo(1);
  }
    if(pitch==45){
    openservo(1);
  }
  
  if(pitch==46){
    openservo(1);
  }
  
}

void HandleNoteOff(byte channel, byte pitch, byte velocity) { 
  // turnOneOff(0);
// Serial.print("on");
  // Do whatever you want when you receive a Note On.
  if(pitch==35){
    turnOneOff(1);
  }
  
  if(pitch==36){
    turnOneOff(1);
  }
    if(pitch==37){
    turnOneOff(1);
  }
  
  if(pitch==38){
    turnOneOff(1);
  }
    if(pitch==39){
    turnOneOff(1);
  }
  
  if(pitch==40){
    turnOneOff(1);
  }
    if(pitch==41){
    turnOneOff(1);
  }
  
  if(pitch==42){
    turnOneOff(1);
  }
  if(pitch==43){
    turnOneOff(1);
  }
  
  if(pitch==44){
    turnOneOff(1);
  }
    if(pitch==45){
    turnOneOff(1);
  }
  
  if(pitch==46){
    turnOneOff(1);
  }
  
}
// void setServoPulse(uint8_t n, double pulse) {
//   double pulselength;
  
//   pulselength = 1000000;   // 1,000,000 us per second
//   pulselength /= 60;   // 60 Hz
//   Serial.print(pulselength); Serial.println(" us per period"); 
//   pulselength /= 4096;  // 12 bits of resolution
//   Serial.print(pulselength); Serial.println(" us per bit"); 
//   pulse *= 1000;
//   pulse /= pulselength;
//   Serial.println(pulse);
//   pwm.setPWM(n, 0, pulse);
// }

void openservo(int nServo){
  // pulselength = map(100, 0, 180, SERVOMIN, SERVOMAX);
  // servonum=nServo-1;
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen+=100) {
    pwm.setPWM(servonum, 0, pulselen);
  }
  // pwm.setPWM(0, SERVOMIN, SERVOMAX);
  
  // for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
 //    pwm.setPWM(servonum, 0, pulselen);
 //  }
 //  delay(500);
 //  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
 //    pwm.setPWM(servonum, 0, pulselen);
  
}
void turnOneOff(int nServo){
  // pulselength = map(0, 0, 180, SERVOMIN, SERVOMAX);
  digitalWrite(7, LOW);

  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }
  // for (uint16_t pulselen = SERVOMAX; pulselen < SERVOMIN ; pulselen++) {
  //     pwm.setPWM(nServo, 0, pulselen);
  //   }
}
