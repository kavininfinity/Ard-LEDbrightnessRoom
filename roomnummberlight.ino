const int a=2,b=3,led=5;
void setup() {
pinMode(a,INPUT);
pinMode(b,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);}
int n=0;
void loop() 
{ 
  int r=n;
  if(digitalRead(a)==HIGH)
     {
      int i=0;
     while(i<500)
          { if(digitalRead(b)==HIGH)
               {n+=1;break;}
            Serial.println("A Delay");
            delay(10);
          i+=1;
          }
     while(digitalRead(b)==HIGH)
     {Serial.println("A: B Hold");}
     }
  if(n==r)
    {
      if(digitalRead(b)==HIGH)
          {int i=0;
            while(i<500)
               { if(digitalRead(a)==HIGH)
                   {n-=1;break;}
                 Serial.println("B Delay");
                 delay(10);
                 i+=1;
               }
          while(digitalRead(a)==HIGH)
            Serial.println("B: A Hold");
          }
    }
  //delay(500);
  if((n<6)&&(n>-1))
    {analogWrite(led,50*n);    
     Serial.print("Number of Person=");
     Serial.println(n);}
  //delay(500);
}
