
int T1 = 102;
int T2 = 30;
long int TT = 600000L;   // timer 10 min
volatile int apa = 0;
volatile int resst = 0;


void waiterr( int x = 1) //10 min timer
{
  for ( int i = 0 ; i < x; i++)
  {
    delay(TT);
  }
}
void printare_var()
{
  Serial.print("apa= ");
  Serial.println(apa);
  Serial.print("resst= ");
  Serial.println(resst);
}


void udator()
{
  Serial.println("incepe udatul");
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  waiterr(3);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  Serial.println("gata udatul");
}




void FUUU()
{
  apa++;
}




void FUUU2()
{
  resst++;
}





void setup()
{
  pinMode( 2, INPUT);   //buton
  pinMode( 3, INPUT);   //buton
  pinMode( 4, OUTPUT);  //led
  pinMode( 5, OUTPUT);  //led
  pinMode( 6, OUTPUT);  //NPN
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  attachInterrupt (digitalPinToInterrupt(2), FUUU, RISING );
  attachInterrupt (digitalPinToInterrupt(3), FUUU2, RISING );
  Serial.begin(9600); // open the serial port at 9600 bps:
  printare_var();
  Serial.print("timp de dormire inainte udare in intervale");
  Serial.println(T1);
  Serial.print("timp de dormire dupa udare in intervale");
  Serial.println(T2);
  Serial.print("interval de calculare in ms");
  Serial.println(TT);

}






void loop()
{
  Serial.println("inceput loop:");
  delay(2000);
  printare_var();
agent:
  resst = 0;

  for ( int j = 0; j < T1 ; j++)
  {
    Serial.println(j);
    if ( resst > 0)
    {
      goto agent;
    }
    if ( apa > 0)
    {
      udator();
      apa--;
      j = j + 3;
    }
    waiterr();
  }
  if ( resst > 0)
  {
    goto agent;
  }
  udator();





  for ( int j = 0; j < T2 ; j++)
  {
    Serial.println(j);
    if ( resst > 0)
    {
      goto agent;
    }
    if ( apa > 0)
    {
      udator();
      apa--;
      j++;
    }
    waiterr();
  }
}

