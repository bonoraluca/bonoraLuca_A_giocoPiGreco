#include <LiquidCrystal.h>

int bottoneI
int bottone1
int bottone2
int bottone3
int bottone4
int bottone5
int tempo = 1000;
int vite = 3;
LiquidCrystal lcd();

void setup() {
  pinMode(bottoneI,INPUT);
  pinMode(bottone1,INPUT);
  pinMode(bottone2,INPUT);
  pinMode(bottone3,INPUT);
  pinMode(bottone4,INPUT);
  pinMode(bottone5,INPUT);
}

void loop() {
  while(vite>0){
  if(digitalRead(bottoneI == HIGH)
  {
    iniziaGioco();
  }
  }

}

void iniziaGioco()
{
  int pos = random(1,5);
  String bottone = "bottone"+"pos"
  lcd.setCursor(0,pos);
  lcd.print("л");
  for(int i=0,i<tempo,i++)
  {
    if(digitalRead(bottone) == HIGH)
    {
      vite++;
      iniziaGioco();
    }
  }
  vite--;
  iniziaGioco();
  
}
