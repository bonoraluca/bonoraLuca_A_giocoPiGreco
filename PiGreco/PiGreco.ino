#include <LiquidCrystal_I2C.h>

int bottoneI = 6;
int tempo = 1000;
int record = 0;
int vite = 3;
int punti = 0;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  randomSeed(analogRead(0));
  pinMode(bottoneI,INPUT);
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
}

void loop() {
  if(digitalRead(bottoneI) == HIGH)
  {
    
    iniziaGioco(vite, tempo, record, punti);
    
  }
  

}

void iniziaGioco(int vite, int tempo, int record, int punti)
{
  
  if (record<punti){
    record = punti;
  }
  punti = 0;
  if(vite == 0){
    lcd.setCursor(0,0);
    lcd.print("GAME OVER");
    lcd.setCursor(0,1);
    lcd.print("Record = "+String(record));
  }
  if(vite != 0){
  lcd.setCursor(0,1);
  lcd.print("Vite: "+ String(vite));
  while (vite>0){
  int pos = random(5);
  lcd.setCursor(pos,0);
  lcd.print("P");
  for(int i=0;i<tempo;i++)
  {
    if(digitalRead(pos+1) == HIGH)
    {
      punti++;
      lcd.setCursor(pos,0);
      lcd.print(" ");
      iniziaGioco(vite, tempo, record, punti);
    }
    delay(1);
    
  }
  vite--;
  lcd.setCursor(pos,0);
  lcd.print(" ");
  iniziaGioco(vite, tempo, record , punti);
  }
  }
}
