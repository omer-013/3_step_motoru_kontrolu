#include "Step_Motor.h"

int sayi_y = 0, sayi_d = 0, sayi_y_eksi = 0, sayi_d_eksi = 0, yon_d = 2, yon_y = 2, hiz;

Step_Motor donus(10, 11, 12, 13);
Step_Motor yatay(6, 7, 8, 9);
Step_Motor dikey(2, 3, 4, 5);

void setup()
{
  Serial.begin(9600);  
}

void loop()
{
  char deger, secim;
  int sayi, aci, mod_g, mod_c, step_y;
  
  Serial.println("Yapacaginiz hareketi secin:");
  Serial.println("DIKEY HAREKET(D | d)"); 
  Serial.println("YATAY HAREKET(Y | Y)");
  Serial.println("DONME ACISI(A | a)");

  while(!Serial.available());
  deger = Serial.read();
  switch(deger){
    case 'd':
    case 'D':
      step_y = deger_alma();
      sayi = abs(step_y);
      hiz = hiz_ayari();
      dikey.step_hiz(hiz);
      if(yon_d == 1){
        sayi_d_eksi = 8 - sayi_d;
      }
      if(step_y < 0){
        dikey.step_yon(-1);

        dikey_hareket(sayi_d_eksi,sayi_d_eksi + sayi);
        sayi_d_eksi = sayi_d_eksi + sayi;
        yon_d = 0;
      }
      else{
        if(yon_d == 0){
          sayi_d = 8 - sayi_d_eksi;
        }
        dikey.step_yon(1);
        dikey_hareket(sayi_d,sayi_d + sayi);
        sayi_d=sayi_d + sayi;
        yon_d = 1;
      }       
      if(sayi_d > 8)
        sayi_d = sayi_d%8;
      if(sayi_d_eksi > 8)
        sayi_d_eksi = sayi_d_eksi%8;
      Serial.println(String(sayi) + " santimetre dikey yonde hareket ettiriliyor");
      break;

    case 'y':
    case 'Y': 
      step_y = deger_alma();
      sayi = abs(step_y);
      hiz = hiz_ayari();
      yatay.step_hiz(hiz);
      if(yon_y == 1){
          sayi_y_eksi = 8 - sayi_y ;
        }
      if(step_y < 0){
        yatay.step_yon(-1);
        yatay_hareket(sayi_y_eksi,sayi_y_eksi + sayi);
        sayi_y_eksi =sayi_y_eksi + sayi;
        yon_y = 0;
      }
      else{
        if(yon_y == 0){
          sayi_y = 8 - sayi_y_eksi ;
        }
        yatay.step_yon(1);
        yatay_hareket(sayi_y,sayi_y + sayi);
        sayi_y=sayi_y + sayi;
        yon_y = 1;
      }
      if(sayi_y > 8)
        sayi_y = sayi_y%8;
      if(sayi_y_eksi > 8)
        sayi_y_eksi = sayi_y_eksi%8;
      Serial.println(String(sayi) + " santimetre yatay yonde hareket ettiriliyor");
      break;

    case 'a':
    case 'A':
      devam:
      Serial.println("45 Derecede bir mi yoksa 90 derecede bir mi dondurulucegini giriniz(45 | 90):");
      while(!Serial.available());
      aci = Serial.parseInt();
      hiz = hiz_ayari();
      yatay.step_hiz(hiz);
      if(aci == 45){
        mod_g = 1;
        mod_c = 0;        
        dondurme(0,8,mod_g,mod_c);
      }
      else if(aci == 90){
        mod_g = 2;
        mod_c = 1;
        dondurme(1,8,mod_g,mod_c);
      }
      else{
        Serial.println("Gecerli bir deger giriniz!!");
        goto devam;
        break;
        
       default: 
        Serial.println("Gecerli bir deger giriniz"); 
        break;
      }
  }
}

void dikey_hareket(int f_step, int l_step) // her 45 derece 1 CM olacak şekilde yukarı aşağı hareket hareket edebilir
{
  for(int i = f_step%8; i < l_step; i++){
    dikey.calistir(i%8);
  }
}

void yatay_hareket(int f_step, int l_step) // her 45 derece 1 CM olacak şekilde ileri geri hareket edebilir
{ 
  for(int i = f_step%8; i < l_step; i++){
    yatay.calistir(i%8);
  }
}

void dondurme(int f_step, int l_step,int a, int b) // 45 derece ve 90 derecede bir dönme ayarı var
{
  for(int i = f_step; i < l_step; i++){
    if(i%a==b)
    donus.calistir(i%8);
  }
}

int deger_alma()
{
  int deger;
  char yon;
  Serial.println("Kac santim hareket edeceginizi giriniz:");
  while(!Serial.available());
  deger = Serial.parseInt();
  Serial.println("Hangi yonde gideceginizi seciniz:(+ | -)");
  while(!Serial.available());
  yon = Serial.read();
  if(yon == '-'){
    deger = -deger;
    }
  else if(yon == '+'){
    deger = abs(deger);

  }
  
  return deger;
}

int hiz_ayari()
{
  int deger;
  Serial.println("Hiz degerini milisaniye cinsinden giriniz:");
  while(!Serial.available());
  deger = Serial.parseInt();
  
  return deger;
}
