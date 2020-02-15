//#include <Arduino.h>

#define IN1 9
#define IN2 10
#define IN3 11
#define IN4 12
char serial_data;

void setup()
{     
  Serial.begin(9600);
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    



}

void loop()
{

    if(Serial.available()>0)
    serial_data = Serial.read();

    if(serial_data=='F')
    {
        move_forward();
        Serial.println("Forward");

    }
    else if(serial_data=='B')
    {
        move_backward();
        Serial.println("Back");
    }
    else if(serial_data=='L')
    {
        move_left();
        
        Serial.println("left");

    }

    else if(serial_data=='R')
    {
        move_right();
        
        Serial.println("right");
    }
    else
    {
        bot_stop();
        
        Serial.println("Stop");
    }
    

    



}


void move_forward()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}

void move_left()
{
     digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);

}

void move_right()
{   
     digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);

}

void move_backward()
{
     digitalWrite(IN2,HIGH);
    digitalWrite(IN1,LOW);
    digitalWrite(IN4,HIGH);
    digitalWrite(IN3,LOW);

}

void bot_stop()
    {
        
     digitalWrite(IN2,LOW);
    digitalWrite(IN1,LOW);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,LOW);

    }
