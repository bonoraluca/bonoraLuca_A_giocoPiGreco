#include <LiquidCrystal.h>

int bottoneI = 6;
int bottone1 = 1;
int bottone2 = 2;
int bottone3 = 3;
int bottone4 = 4;
int bottone5 = 5;
int tempo = 1000;
int vite = 3;
int punti = 0;
LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  lcd.begin(16,2);
  pinMode(bottoneI,INPUT);
  pinMode(bottone1,INPUT);
  pinMode(bottone2,INPUT);
  pinMode(bottone3,INPUT);
  pinMode(bottone4,INPUT);
  pinMode(bottone5,INPUT);
}

void loop() {
  if(digitalRead(bottoneI == HIGH))
  {
    
    iniziaGioco();
    
  }
  

}

void iniziaGioco()
{
  lcd.setCursor(1,0);
  lcd.print("vite: "+ vite);
  while (vite>0){
  int pos = random(1,5);
  lcd.setCursor(0,pos);
  lcd.print("л");
  for(int i=0;i<tempo;i++)
  {
    if(digitalRead(pos) == HIGH)
    {
      punti++;
      iniziaGioco();
    }
  }
  vite--;
  iniziaGioco();
  }
  
}
