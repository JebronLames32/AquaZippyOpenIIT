int pirPin = 2;                    // PIR Output pin 
int pumpPin = 5;	//Pump Input pin
bool pirStat;            // PIR status (checks motion)
int t1;
int t2;
bool pirLatestStat = LOW;     //used to calculate the time duration the hand was inside
void setup() 
{    
 pinMode(pirPin, INPUT);     
 pinMode(pumpPin, OUTPUT);
}
void loop()
{
 pirStat = digitalRead(pirPin);   //reading the value of the IR sensor
 if (pirStat == HIGH)             // if motion detected
 {
  if (pirStat != pirLatestStat)
  {
  t1=millis();                   //taking the time when hand is first inserted (milliseconds)
  }
  digitalWrite(pumpPin, HIGH);
  delay(10);
  pirLatestStat=HIGH;
  t2=millis();                //Checking time constantly (milliseconds)
  if (t2-t1 > 10000)
  {
   digitalWrite(pumpPin, LOW); 
   pirLatestStat=LOW; 
   delay(5000);           //wait for five seconds before next iteration 
  }
 } 
 else {
   digitalWrite(pumpPin, LOW); 
   pirLatestStat=LOW;
 }
}
