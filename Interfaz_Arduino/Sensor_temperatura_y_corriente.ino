#include <LiquidCrystal.h>
#include <math.h>

// C++ code
//
float R_Termistor = 0;
float R_known = 10000;
float buffer = 0;
float entrada = 0; //lectura de tension en Rknow
float Vin = 5;
float B = 3862; // parametro para la ecuacion de beta
float Vout = 0;
float R0 = 10000; // parametro para la ecuacion de beta
float T0 = 298.15; // parametro para la ecuacion de beta 25°C
float T = 0;
float Vref = 0;
float Iout = 0;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup()
{
  pinMode(A5, INPUT);
  pinMode (A0, INPUT);
  lcd.begin(16,2);
  //lcd.print("hola mundo");
}

void loop()
{
  // Lectura de tension Vref
  Vref = analogRead(A0);
  buffer =  Vref*Vin;
  // El divisor de tension divide en 1/6
  Vref = buffer*6/1024.0;
  // lectura del valor resistivo del termistor
  entrada = analogRead(A5);
  if(entrada){
    // Calculo de la tension del potenciometro
   	buffer = entrada*Vin;
    Vout = buffer/1024.0;
    R_Termistor = R_known*(Vin/Vout-1);
    
    //calculo de temperatura coeficiente beta
    T = 1/((1/T0)+(1/B)*log(R_Termistor/R0));
    T = T-273.15;
    
    //calculo de la corriente del diodo laser
    Iout = 0.0536*(Vref)-0.181;

    lcd.setCursor(0, 0);
    lcd.print("Temp [C]: ");
    lcd.print(T);

    lcd.setCursor(0, 1);
    lcd.print("Iout [A]: ");
    lcd.print(Iout);
    delay(1000);
  }
  

}