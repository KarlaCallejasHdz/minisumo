//PROGRAMA ENTERO EQUIPO 8 KARLA CALLEJAS HERNANDEZ
/*
 * 
 * declaracion de las variables
 */
int in1=2,in2=3,in3=4,in4=5;
int enable1 = 10, enable2 = 11;
int distancia; //para la funcion de distancia
int tiempo;
int TRIGGER = 9, ECHO = 8;
int luz;
int cny_LED = 2;
const int sensorPin = 6;


void setup()
{
Serial.begin(9600);
pinMode(cny_LED, OUTPUT); 
digitalWrite(cny_LED,HIGH);//Enciende el LED IR embebido en el CNY70
pinMode(sensorPin , INPUT);  //definir pin como entrada

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
analogWrite(enable1, 120);
analogWrite(enable2, 120);

pinMode(TRIGGER, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
pinMode(ECHO, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/

}
void loop()
{

pelea();

}
void pelea(){
  int value; 
  do {
    
  value = 0;
  value = digitalRead(sensorPin );
  
 if (value == LOW) {  
    adelante();
    delay(10);    
  }else{
  buscar();
  delay(10);
  
  }
distancia = distancia_medida();
delay(80);

} while (value || distancia>=40);

}
int distancia_medida() {
digitalWrite(TRIGGER, LOW);
delayMicroseconds(2);
digitalWrite(TRIGGER, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER, LOW);
// Calcula la distancia midiendo el tiempo del estado alto del pin ECHO
tiempo = pulseIn(ECHO, HIGH);

// La velocidad del sonido es de 340m/s o 29 microsegundos por centimetro
distancia = tiempo/ 58;
//manda la distancia al monitor serie
/*
Serial.print(distancia);
Serial.println(“cm”);
delay(100);
*/
return distancia;
}

void detener() {
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
}
void izquierda() {
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}
void derecha() {
digitalWrite(in2, HIGH);
digitalWrite(in1, LOW);
digitalWrite(in4, HIGH);
digitalWrite(in3, LOW);
}
void adelante() {
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in4, HIGH);
digitalWrite(in3, LOW);

}
void atras() {
digitalWrite(in2, HIGH);
digitalWrite(in1, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}


void buscar() {
digitalWrite(in2, LOW);
digitalWrite(in1, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
//delay(10);
}
