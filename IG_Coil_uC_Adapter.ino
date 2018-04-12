/*
Code done by Gerald Just Projects
gerald@geraldjustprojects.com

MIT License

Copyright (c) 2018 geraldjust

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
*/


unsigned long start;
unsigned long elapsed;
unsigned long RPM;
int numOfCyl = 4 ; //4 banger
int pin = 3; //attach interupt for atmega328p / atmega32u4 (arduino Mapped.



void setup()
{
  Serial.begin(115200);
  pinMode(pin, INPUT);
  digitalWrite(pin, HIGH);
  attachInterrupt(digitalPinToInterrupt(pin), speedCalc, FALLING);
  start = micros();

}

void speedCalc() {
  elapsed = micros() - start;
  start = micros();

  //RPM = ((120 * (1000000 / elapsed)) / numOfCyl); //MS to RPM +-30RPM Res
  RPM = ((12*(10,000,000/elapsed)) /numOfCyl); //uS  +- 3RPM resolution

}

void loop()
{

  Serial.print(int(RPM));
  Serial.print(" rpm ");

  Serial.println(elapsed);
  Serial.println(" ms/rev      ");
  delay(50);

  if ((micros()-start) >= 500000){
      RPM=0;//if RPM times out then RPM = 0
  }

  
}
