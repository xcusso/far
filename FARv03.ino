/*
  FAR MAR
  Il.lumina 4 leds sequancialment fent un efecte de iluminació de far.
 
 */
 

#define L1 PB0 //Digital Pin1 (pin 5xip)
#define L2 PB1 //Digital Pin0 (pin 6xip)
#define L3 PB2 //Digital Pin2 (pin 7xip)
#define L4 PB4 //(pin 3xip)
 
// Pins de sortida
int const ledpin[] = {L1,L2,L3,L4};
// Pin entrada
int const sensor = 3;
// Valor sensor
int vsensor = 255;
int ledvalor[] = {0,0,0,0,0};
int const umbralllum = 10; //Umbral de disparo del far
int const Umbral = 15; //Umbral d'il.luminació minima leds
int const repeticions = 50; //Repeticions abans d'apagarse
int A = 0;
int B = 0;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
for (int L = 0; L < 4; L++) {
  pinMode(ledpin[L], OUTPUT); 
  digitalWrite(ledpin[L], LOW);  
}
//Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  vsensor = analogRead(sensor);
  while (vsensor > umbralllum) {
  vsensor = analogRead(sensor);
  delay(100);
  //Serial.println(vsensor);
  }
   for (int t = 0; t < repeticions; t ++) { 
   for (int s = 0; s < 6; s++) {
    switch (s) {
     case 0:
    // A es rampa de pujada
    // B es rampa baixada
    // Valor 4 no existeix es per fer la part fosca
       A = 4;
       B = 4;
       break;

     case 1:
       A = 0;
       B = 4;
       break;
       
     case 2:
       A = 1;
       B = 0;
       break;
       
     case 3:
       A = 2;
       B = 1;
       break;
   
     case 4:
       A = 3;
       B = 2;
       break;
   
     case 5:
       A = 4;
       B = 3;
       break;    
    }
     
   //Constructor de rampes
    for (int v = Umbral; v < 255; v++){
      ledvalor[A] = v;
      ledvalor[B] = (255 - (v - Umbral));
      /*Serial.print("LED 1: ");
      Serial.print(ledvalor[0]);
      Serial.print("LED 2: ");
      Serial.print(ledvalor[1]);
      Serial.print("LED 3: ");
      Serial.print(ledvalor[2]);
      Serial.print("LED 4: ");
      Serial.print(ledvalor[3]);
      Serial.println(" * ");
      */
      //Bucle per escriure valors als leds
      for (int i = 0; i < 255; i=i+2) {
        for (int n = 0; n < 4; n++) {
          if  (ledvalor[n] > i) {
           digitalWrite(ledpin[n], HIGH);
          } else {
           digitalWrite(ledpin[n],LOW);
          }
        }
      } 
      // Fins aqui bucle escriure valors
    }
   }
 }
 vsensor = analogRead(sensor);
 while (vsensor < umbralllum) {
  vsensor = analogRead(sensor);
  // Aquest bucle espera que la llum sigui superior al umbral
  delay(100);
  }
}
