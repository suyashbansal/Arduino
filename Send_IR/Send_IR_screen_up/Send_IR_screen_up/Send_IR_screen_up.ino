// This sketch will send out a Nikon D50 trigger signal (probably works with most Nikons)
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!
 
int IRledPin =  13;    // LED connected to digital pin 13
 
// The setup() method runs once, when the sketch starts
 
void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);      
 
  Serial.begin(9600);
}
 
void loop()                     
{
  Serial.println("Sending IR signal");
 
  SendChannelUpCode();
 
  delay(10000);  // wait twenty seconds (20 seconds * 1000 milliseconds)
}
 
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void SendChannelUpCode() {
  // This is the code for the CHANNEL + for the downstairs TV COMCAST
  delayMicroseconds(3284); //Time off (Left Column on serial monitor)
  pulseIR(380);           //Time on  (Right Column on serial monitor)
  delayMicroseconds(5880);
  pulseIR(520);
  delayMicroseconds(25124);
  pulseIR(700);
  delayMicroseconds(300);
  pulseIR(240);
  delayMicroseconds(21944);
  pulseIR(340);
  delayMicroseconds(33628);
  pulseIR(180);
  delayMicroseconds(63404);
  pulseIR(140);
  delayMicroseconds(11600);
  pulseIR(120);
  delayMicroseconds(41644);
  pulseIR(460);
  delayMicroseconds(3860);
  pulseIR(460);
  delayMicroseconds(32412);
  pulseIR(260);
  delayMicroseconds(21100);
  pulseIR(120);
  delayMicroseconds(1440);
  pulseIR(400);
  delayMicroseconds(5120);
  pulseIR(260);
  delayMicroseconds(27080);
  pulseIR(160);
  delayMicroseconds(1480);
  pulseIR(400);
  delayMicroseconds(19220);
  pulseIR(160);
  delayMicroseconds(28856);
  pulseIR(480);
  
}
