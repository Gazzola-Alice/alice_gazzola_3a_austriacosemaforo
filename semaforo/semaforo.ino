int ledverde = 2;
int ledrosso =3;
int ledgiallo=7;
int ledverdedue= 8;
int ledgiallodue= 10;
int ledrossodue=4;
int cento=100;
int mille=1000;
int diecimila=10000;
void setup() {
  // put your setup code here, to run once:
pinMode(ledverde,OUTPUT);
pinMode(ledrosso,OUTPUT);
pinMode(ledgiallo,OUTPUT);
pinMode(ledverdedue,OUTPUT);
pinMode(ledrossodue,OUTPUT);
pinMode(ledgiallodue,OUTPUT);

}
void semaforo (){ digitalWrite(ledrosso,HIGH);
   digitalWrite(ledrossodue,HIGH);
  delay (diecimila);
    digitalWrite(ledrosso,HIGH); //turn the led on (high is the voltage level)
     digitalWrite(ledgiallo,HIGH);
     digitalWrite(ledrossodue,HIGH); //turn the led on (high is the voltage level)
     digitalWrite(ledgiallodue,HIGH); 
     delay (diecimila);
     digitalWrite(ledrosso,LOW); //turn the led on (high is the voltage level)
     digitalWrite(ledgiallo,LOW);
      digitalWrite(ledrossodue,LOW); //turn the led on (high is the voltage level)
     digitalWrite(ledgiallodue,LOW);
        delay(cento);
        digitalWrite(ledverde,HIGH);
         digitalWrite(ledverdedue,HIGH);//turn the led on (high is the voltage level)
 //aspetta per un secondo
 delay(diecimila);
  digitalWrite(ledverde,LOW);//turn the led off
   digitalWrite(ledverdedue,LOW);
   delay(1000);
digitalWrite(ledverde,HIGH); //turn the led on (high is the voltage level)
 digitalWrite(ledverdedue,HIGH);
  delay(mille);//aspetta per un secondo
  digitalWrite(ledverde,LOW);//turn the led off
   digitalWrite(ledverdedue,LOW);
   delay(cento);
   digitalWrite(ledverde,HIGH); //turn the led on (high is the voltage level)
    digitalWrite(ledverdedue,HIGH);
  delay(cento);//aspetta per un secondo
  digitalWrite(ledverde,LOW);//turn the led off
   digitalWrite(ledverdedue,LOW);
   delay(cento);
   digitalWrite(ledverde,HIGH); //turn the led on (high is the voltage level)
    digitalWrite(ledverdedue,HIGH);
  delay(mille);//aspetta per un secondo
  digitalWrite(ledverde,LOW);//turn the led off
   digitalWrite(ledverdedue,LOW);
   delay(cento);
   digitalWrite(ledverde,HIGH); //turn the led on (high is the voltage level)
    digitalWrite(ledverdedue,HIGH);
  delay(mille);//aspetta per un secondo
  digitalWrite(ledverde,LOW);//turn the led off
   digitalWrite(ledverdedue,LOW);
   delay(cento);

 digitalWrite(ledgiallo,HIGH); 
  digitalWrite(ledgiallodue,HIGH);
     delay (diecimila);
      digitalWrite(ledgiallo,LOW);
       digitalWrite(ledgiallodue,LOW);
      delay (cento);
}
void loop() {
 semaforo();

}
