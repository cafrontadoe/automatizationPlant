#include <pt.h>

struct pt hilo1;
struct pt hilo2;

// sistematization my plants 1
const int LED13=13; // pin of ligth
const int LED12=12; // constant of power
const int LED11=11; // pin of water

bool firstTime = true;

void setup()
{
  PT_INIT(&hilo1);
  PT_INIT(&hilo2);
}

void light(struct pt *pt){
 PT_BEGIN(pt);
 static long t = 0;
 pinMode(LED13,OUTPUT);
 do{
  t  = millis();
  digitalWrite(LED13,LOW);
 // PT_WAIT_WHILE(pt, (millis()-t < 64800000)); // 18 hours
  PT_WAIT_WHILE(pt, (millis()-t < 1000));
  digitalWrite(LED13,HIGH);
  t  = millis();
 // PT_WAIT_WHILE(pt, (millis()-t < 21600000)); // 6 hours
  PT_WAIT_WHILE(pt, (millis()-t < 1000));
  }while(true);
 PT_END(pt);
 }

void water(struct pt *pt){
  PT_BEGIN(pt);
 static long t = 0;
 pinMode(LED12,OUTPUT);
 do{
  t  = millis();
  digitalWrite(LED12,LOW);
  PT_WAIT_WHILE(pt, (millis()-t < 100)); // 18 hours
  digitalWrite(LED12,HIGH);
  t  = millis();
  PT_WAIT_WHILE(pt, (millis()-t < 100)); // 6 hours
  }while(true);
 PT_END(pt);
}

void loop()
{
light(&hilo1);
water(&hilo2);
}
