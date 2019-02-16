int ledverde = 2;
int ledrosso =3;
int ledgiallo=7;
int ledverdedue= 8;
int ledgiallodue= 10;
int ledrossodue=4;
int i;
int lampeggio;
int numero;
int tempo;
int t;
int nl;
int pausa=100;

void setup() {
pinMode(ledverde,OUTPUT);
pinMode(ledrosso,OUTPUT);
pinMode(ledgiallo,OUTPUT);
pinMode(ledverdedue,OUTPUT);
pinMode(ledrossodue,OUTPUT);
pinMode(ledgiallodue,OUTPUT);
Serial.begin(9600);
Serial.println("seriale attiva");
interrompi();
chiedogiallo();
chiedolamp();
chiedonlampeggi();
chiedoloop();
}
void chiedogiallo() {
  Serial.println("Scrivi quanto deve valere l'intervallo di tempo del giallo");
  while(Serial.available()==0);
    if ( Serial.available ()> 0){
  numero= Serial.readString().toInt();
  Serial.println(numero);
  }
}
void chiedolamp() {
  Serial.println("Scrivi quanto deve valere il tempo di lampeggio del verde ");
  while(Serial.available()==0);
    if ( Serial.available ()> 0){
  lampeggio= Serial.readString().toInt();
  Serial.println(lampeggio);
  }
}
void chiedonlampeggi(){
  //devo chiedere quanti lampeggi voglio
   Serial.println("Scrivi quante volte il led verde deve lampeggiare ");
  while(Serial.available()==0);
    if ( Serial.available ()> 0){
 nl= Serial.readString().toInt();
  Serial.println(nl);
  }
  
  }
  void chiedoloop (){
    //devo chiedere quanto dura una fase o tutto il ciclo e poi divido il valore per le fasi tranne quella del giallo
     Serial.println("Scrivi quanto deve durare il semaforo( quanto deve durare il rosso,il verde e il rosso e giallo) ");
  while(Serial.available()==0);
    if ( Serial.available ()> 0){
tempo= Serial.readString().toInt();
  Serial.println(tempo);
  t= ((tempo-numero)/4);
  errore();
    }}
void interrompi(){
   digitalWrite(ledgiallo,LOW);
  digitalWrite(ledverde,LOW);
  digitalWrite(ledrosso,LOW);
   digitalWrite(ledgiallodue,LOW);
  digitalWrite(ledverdedue,LOW);
  digitalWrite(ledrossodue,LOW);
  }
void errore(){
  if (tempo<numero+(lampeggio*nl))
  {
 Serial.println ("IL TEMPO DI DURATA DEL SEMAFORO DEVE ESSERE MAGGIORE DELLA SOMMA DEI VALORI INSERITI PRECEDENTEMENTE!!");
 Serial.println("Ricominciamo");
 delay(pausa);  
   setup();
 
   }
   else{ Serial.println("Il semaforo parte!");
    }
}
void psRosso() {
  digitalWrite(ledgiallo,LOW);
  digitalWrite(ledverde,LOW);
  digitalWrite(ledrosso,HIGH);
}

void psGialloRosso() {
  digitalWrite(ledverde,LOW);
  
  digitalWrite(ledrosso,HIGH);
  digitalWrite(ledgiallo,HIGH);
}

void psVerde() {
  digitalWrite(ledrosso,LOW);
  digitalWrite(ledgiallo,LOW);
  
  digitalWrite(ledverde,HIGH);
}

void psLampeggiaVerde() {digitalWrite(ledverde,LOW);
    digitalWrite(ledrosso,LOW);
    digitalWrite(ledgiallo,LOW);
    i=0;
      while (i<nl){
    digitalWrite(ledverdedue,HIGH);
    delay(lampeggio);

   digitalWrite(ledverdedue,LOW);
    delay(lampeggio);
    i++;}
  
   
}

void psGiallo() {
  digitalWrite(ledverde,LOW);
  digitalWrite(ledrosso,LOW);
  
  digitalWrite(ledgiallo,HIGH);
}
  

void ssRosso() {
  digitalWrite(ledgiallodue,LOW);
  digitalWrite(ledverdedue,LOW);
  
  digitalWrite(ledrossodue,HIGH);
}

void ssGialloRosso() {
  digitalWrite(ledverdedue,LOW);
  
  digitalWrite(ledrossodue,HIGH);
  digitalWrite(ledgiallodue,HIGH);
}

void ssVerde() {
  digitalWrite(ledrossodue,LOW);
  digitalWrite(ledgiallodue,LOW);
  
  digitalWrite(ledverdedue,HIGH);
}

void ssLampeggiaVerde() {
    digitalWrite(ledrossodue,LOW);
    digitalWrite(ledgiallodue,LOW);
    digitalWrite(ledverdedue,LOW);
   // delay(lampeggio);
   i=0;
   while (i<nl){
    digitalWrite(ledverdedue,HIGH);
    delay(lampeggio);

   digitalWrite(ledverdedue,LOW);
    delay(lampeggio);
    i++;
  
}}

void ssGiallo() {
  digitalWrite(ledverdedue,LOW);
  digitalWrite(ledrossodue,LOW);
  
  digitalWrite(ledgiallodue,HIGH);
}


void faseuno(){
   ssRosso();
  psVerde();
  delay(t);
  
  }
  void fasedue(){
     ssGialloRosso();
  psLampeggiaVerde();
  delay(t);
    }
    void fasetre()
    { ssVerde();
  psRosso();
  delay(t);
      }
      void fasequattro(){
         ssLampeggiaVerde();
  psGialloRosso();
  delay(t);
        
        }
        void fasecinque()
        {
           ssGiallo();
  delay(numero);
          }
void mysemaforo() { 
  
  faseuno();
  
 fasedue();
  
 fasetre();
  
fasequattro();
 fasecinque(); 
 setup();
 
}
void loop() {
 
 mysemaforo();
 

 
}
