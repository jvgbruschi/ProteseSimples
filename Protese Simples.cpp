#include <Servo.h> 

Servo dedinho, anelar, meio, indicador, dedao;


const int dedinhoFlex = A0; 
const int anelarFlex = A1; 
const int meioFlex = A2; 
const int indicadorFlex = A3; 
const int dedaoFlex = A4; 

void setup(){

  dedinho.attach(13);
  anelar.attach(12);
  meio.attach(11);
  indicador.attach(9);
  dedao.attach(10);

  dedinho.write(180);
  anelar.write(180);
  meio.write(180);
  indicador.write(180);
  dedao.write(180);
 

  Serial.begin(9600);
}

void loop(){
  fingerControl(dedinho, dedinhoFlex, 30, 180, 710, 900);
  fingerControl(anelar, anelarFlex, 0, 180, 935, 965);
  fingerControl(meio, meioFlex, 0, 180, 976, 985);
  fingerControl(indicador, indicadorFlex, 30, 180, 850, 920);
  fingerControl(dedao, dedaoFlex, 0, 180, 487, 500);
}

void fingerControl(Servo servo, int flex, int s_bent, int s_flat, int f_bent, int f_flat) {
  int servo_pos;
  int flex_pos;
  flex_pos = analogRead(flex); 
  Serial.println(flex_pos); 
  servo_pos = map(flex_pos, f_bent, f_flat, s_bent, s_flat); 
  servo.write(servo_pos); 
  delay(100); 
}

void testFlex(){
 
  int val0 = analogRead(A0);
  Serial.println("");
  Serial.print(" A0: ");
  Serial.print(val0);
  
  int val1 = analogRead(A1);
  Serial.print(" A1: ");
  Serial.print(val1);
  
  int val2 = analogRead(A2);
  Serial.print(" A2: ");
  Serial.print(val2);
  
  int val3 = analogRead(A3);
  Serial.print(" A3: ");
  Serial.print(val3);
  
  int val4 = analogRead(A4);
  Serial.print(" A4: ");
  Serial.print(val4);

  delay(500); 
}