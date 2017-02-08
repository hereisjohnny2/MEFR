#include <TM1637Display.h>
#include <Arduino.h>

TM1637Display display(6, 7); //Conexões com a tela (CLK, DIO)

volatile byte rpmcount;
int valor_recebido;

void rpm_fun()
{
  rpmcount++;
}

void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, rpm_fun, FALLING);
}
void tacometro()
{
  display.showNumberDec (rpmcount, true);
  Serial.println(rpmcount);
}

void loop() {
  display.setBrightness(0x0f);
  tacometro();
}



