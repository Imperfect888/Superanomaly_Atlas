#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10); // можно использовать любые
const uint32_t pipe = 123456789; // адрес

float Damage = 4010;

int led = 7;

int time_ = 0;


void setup()
{
  pinMode(led, OUTPUT);
  
  radio.begin();
  delay(2);
  radio.setChannel(9);
  radio.setDataRate(RF24_1MBPS); // скорость обмена данными RF24_1MBPS или RF24_2MBPS
  radio.setPALevel(RF24_PA_MIN);
  radio.openWritingPipe(pipe); // открыть канал на отправку
}

void loop()   
{
  time_ = random(100,1000);
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)

  radio.write(&Damage,4);
  
  delay(time_);             // wait for a second

  time_ = random(100,1000);
  
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(time_);  

}
