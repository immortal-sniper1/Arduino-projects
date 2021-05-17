
int T1 = 12 * 4 + 6 * 4;
int T2 = 5 * 4 + 2;
volatile int apa = 0;



void waiterr( int x = 1) //15 min timer
{
  for ( int i = 0 ; i < x; i++)
  {
    delay(900000);    
  }
}

void udator()
{
  Serial.print("incepe udatul");
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  waiterr(2);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  Serial.print("gata udatul");
}

void FUUU()
{
  apa++;
}

void setup()
{

  attachInterrupt (digitalPinToInterrupt(2), FUUU, RISING );

  pinMode( 2, INPUT);   //buton
  pinMode( 3, INPUT);   //buton
  pinMode( 4, OUTPUT);  //led
  pinMode( 5, OUTPUT);  //led
  pinMode( 6, OUTPUT);  //NPN

}






void loop()
{
  for ( int j = 0; j < T1 ; j++)
  {
    if ( apa > 0)
    {
      udator();
      apa--;
      j++;
    }
    waiterr();
  }

  udator();

  
  for ( int j = 0; j < T2 ; j++)
  {
    if ( apa > 0)
    {
      udator();
      apa--;
      j++;
    }
    waiterr();
  }
}

