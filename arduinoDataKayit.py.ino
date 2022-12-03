#include "max6675.h" 
#define soPin  12// SO=Serial Out
#define csPin  3// CS = chip select CS pin
#define sckPin 13// SCK = Serial Clock pin
#include "DHT.h"
#define DHTPIN 6    
#define DHTTYPE DHT11 
MAX6675 Module(sckPin, csPin, soPin);// create instance object of MAX6675
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  dht.begin();    
  Serial.begin(9600);// initialize serial monitor with 9600 baud


}
int a=0;
void loop() {
  // basic readout test, just print the current temp
   float h = dht.readHumidity();
   char hum[12];
   hum[11]='\0';
   hum[5]=' ';
   float tem=Module.readCelsius();
   a=tem/10;
   hum[0]=a+48; tem=tem-a*10;a=tem;
   hum[1]=a+48; tem=(tem-a)*10.0;a=tem;
   hum[2]='.';
   hum[3]=a+48; tem=(tem-a)*10.0;a=tem;
   hum[4]=a+48;
   
   a=h/10;
   hum[6]=a+48; h=h-a*10;a=h;
   hum[7]=a+48; h=(h-a)*10.0;a=h;
   hum[8]='.';
   hum[9]=a+48; h=(h-a)*10.0;a=h;
   hum[10]=a+48;
   Serial.println(hum);


   delay(1100);
}
