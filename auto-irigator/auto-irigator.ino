
long int T1 = 12 * 4 * 15 + 6 * 4* 15;
long int T2 = 5 * 4* 15 + 2* 15;
long int TT = 1000 * 60;
volatile int apa = 0;
volatile int resst = 0;


void waiterr( int x = 1) //1 min timer
{
  for ( int i = 0 ; i < x; i++)
  {
    delay(TT);
  }
}

void udator()
{
  Serial.print("incepe udatul");
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  waiterr(30);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  Serial.print("gata udatul");
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

  attachInterrupt (digitalPinToInterrupt(2), FUUU, RISING );
  attachInterrupt (digitalPinToInterrupt(3), FUUU2, RISING );

  pinMode( 2, INPUT);   //buton
  pinMode( 3, INPUT);   //buton
  pinMode( 4, OUTPUT);  //led
  pinMode( 5, OUTPUT);  //led
  pinMode( 6, OUTPUT);  //NPN

}






void loop()
{
agent:
resst=0;

  for ( int j = 0; j < T1 ; j++)
  {
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
  if ( resst > 0)
  {
goto agent;
  }
  udator();


  for ( int j = 0; j < T2 ; j++)
  {
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

