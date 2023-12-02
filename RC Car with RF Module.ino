int Dfront = 10;
int Dback = 11;
int Dleft = 12;
int Dright = 13;

const int out1 = 2;
const int out2 = 3;
const int out3 = 4; 
const int out4 = 5; 

int trig = 8;
int echo = 9; 
long duration = 0;
int distance = 0;

void setup()
{
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);
    pinMode(out3, OUTPUT);
    pinMode(out4, OUTPUT);

    pinMode(Dfront, INPUT);
    pinMode(Dback, INPUT);
    pinMode(Dleft, INPUT);
    pinMode(Dright, INPUT);

    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

}

void loop()
{
    digitalWrite(trig, HIGH);
    delay(1);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = ((float)(duration*340)/10000) / 2;
    Dfront = digitalRead(10);
    Dback = digitalRead(11);
    Dleft = digitalRead(12);
    Dright = digitalRead(13);


  if (Dfront == HIGH && distance > 20) {
    digitalWrite(out2,HIGH);
    digitalWrite(out3,HIGH);
    digitalWrite(out1,LOW);
    digitalWrite(out4,LOW);
  }

  else if(Dback == HIGH){
    digitalWrite(out1,HIGH);
    digitalWrite(out4,HIGH);
    digitalWrite(out2,LOW);
    digitalWrite(out3, LOW);
  }

  else if(Dleft == HIGH){
    digitalWrite(out2,HIGH);
    digitalWrite(out4,LOW);
    digitalWrite(out1,LOW);
    digitalWrite(out3,LOW);
  }

  else if(Dright == HIGH){
    digitalWrite(out1,LOW);
    digitalWrite(out3,HIGH);
    digitalWrite(out2,LOW);
    digitalWrite(out4,LOW);
  }

  else{
    digitalWrite(out1,LOW);
    digitalWrite(out2,LOW);
    digitalWrite(out3,LOW);
    digitalWrite(out4,LOW);
  }
}

//---------------------------------------------------------------------------------------------------------



/*
void loop()
{  
    digitalWrite(ledPin,HIGH); //HIGH is set to about 5V PIN8
    delay(1000);               //Set the delay time, 1000 = 1S
    digitalWrite(ledPin,LOW);  //LOW is set to about 5V PIN8
    delay(1000);               //Set the delay time, 1000 = 1S
} */