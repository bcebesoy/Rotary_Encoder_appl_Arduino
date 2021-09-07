volatile unsigned int temp = 0, counter = 500; //This variable will increase or decrease depending on the rotation of encoder
uint8_t st_wheel;
 
void setup() {
  Serial.begin (9600);

  pinMode(2, INPUT_PULLUP); // internal pullup input pin 2 
  
  pinMode(3, INPUT_PULLUP); // internalเป็น pullup input pin 3
//Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(0, ai0, RISING);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(1, ai1, RISING);
  }
   
  void loop() 
  {
    
    // Send the value of counter
    if( counter != temp )
    {
      st_wheel = map(counter, 1, 1000, 0, 1023);
      Serial.println (st_wheel);
      temp = counter;
    }
  }
   
  void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(3)==LOW) {
  counter++;
  }else{
  counter--;
  }
  if(counter > 1000)
    {
      counter = 1000;
    }else if(counter < 1)
    {
      counter = 1;
    }
  }
   
  void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(2)==LOW) {
  counter--;
  }else{
  counter++;
  }
  if(counter > 1000)
    {
      counter = 1000;
    }else if(counter < 1)
    {
      counter = 1;
    }
  }
