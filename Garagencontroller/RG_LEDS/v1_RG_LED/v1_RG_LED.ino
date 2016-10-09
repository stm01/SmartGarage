//Defines

#define Out1A 5
#define Out1B 4
#define Out2A 3 
#define Out2B 2
#define Out3A 
#define LED 13
#define C1auf 9
#define C1zu 10
#define C2auf 11
#define C2zu 12 


char color1, color2;
char contact[5];
char ContactInput[10];

char C1state, C2state, Cstate, C1, C2; 
char C1laststate, C2laststate;
int C1a,C1z,C1mu,C1md,C1e;  // mögliche Zustände : auf, zu, moving up, moving down, error,
int C2a,C2z,C2mu,C2md,C2e;  // mögliche Zustände : auf, zu, moving up, moving down, error,
int addr;
int i = 0,l=0;




void setup() {
  // put your setup code here, to run once:
delay(300);
Serial.begin(115200);

//PinModes
pinMode(Out1A, OUTPUT); //Rot
pinMode(Out1B, OUTPUT); // Grün
pinMode(Out2A, OUTPUT); //Rot
pinMode(Out2B, OUTPUT); //Grün
pinMode(LED, OUTPUT); //gelbe LED
pinMode(C1auf, INPUT_PULLUP);//
pinMode(C1zu, INPUT_PULLUP);//
pinMode(C2auf, INPUT_PULLUP);//
pinMode(C2zu, INPUT_PULLUP);//


//pinMode();//

//Startup Pattern
//delay(5000);
/*
Out('g',1);
delay(100);
Out('r',1);
delay(100);
Out('g',2);
delay(100);
Out('r',2);
delay(100);
delay(500);
*/
}

void loop() {
  //blinkError();
  //check inputs
  getState(C1); //Zustand von Kanal 1 Erfassen
  getState(C2); //Zustand von Kanal 2 Erfassen
  visualizeState();
  //debugInfo();
  

  
 
}

void debugInfo(){
  delay(500);
  Serial.print ("DEBUGMODE ON ");
   Serial.print (" ----- ");
  Serial.print("C1state = ");
  Serial.print (C1state);
  Serial.print (" ----- ");
  //Serial.print("C2state = ");
  //Serial.print(C2state);
  Serial.print (" ----- ");
  
  Serial.print ("DigitalReadC1auf--");
  Serial.print(digitalRead(C1auf));
  
  Serial.print ("--");
    Serial.print ("DigitalReadC1zu--");
    Serial.print(digitalRead(C1zu));
  
  Serial.println ("--EOD--");
  
  
  
  
  
  
  }

void blinkError(){
    Out('r',1);
    Out('r',2);
    delay(1000);
    Out('b',1);
    Out('b',2);
    delay(1000);
}


void visualizeState(){
 // beide Tore im selben Zustand für schöneres blinken
    if((C2state == 'Z') && (C1state == 'Z')) {
      Out('g',1);
      Out('g',2);
      delay(1000);
      Out('b',1);
      Out('b',2);
      delay(1000);
      }
    if((C2state == 'A') && (C1state == 'A')) {
      Out('r',1);
      Out('r',2);
      delay(500);
      Out('b',1);
      Out('b',2);
      delay(500);
      }

     if((C2state == 'u') && (C1state == 'u')) {
      Out('g',1);
      Out('g',2);
      delay(100);
      Out ('r',1);
      Out ('r',2);
      delay(100);
      }
// einzelne zustände  
 if ((C1state == 'Z') && (C2state != 'Z')){
    Out('g',1);
    delay(1000);
    Out('b',1);
    delay(1000);
    } 
    
    if((C1state == 'A') && (C2state != 'A')){
    Out ('r',1);
    delay(500);
    Out('b',1);
    delay(500);
    }

   if ((C1state == 'u') && (C2state != 'u')){
   Out('g',1);
   delay(100);
   Out ('r',1);
   delay(100);
   }

// jetzt für C2
 if ((C2state == 'Z') && (C1state != 'Z')){
    Out('g',2);
    delay(1000);
    Out('b',2);
    delay(1000);
    } 
    
    if ((C2state =='A')&& (C1state != 'A')){
    Out ('r',2);
    delay(500);
    Out('b',2);
    delay(500);
    }

   if ((C2state == 'u') && (C1state != 'u')){
   Out('g',2);
   delay(100);
   Out ('r',2);
   delay(100);
   }

}
/*
void blink(int addr, char color, int  , int blinkduration)
void handleError(){
    if (C1e >=1)
    blink('r',1,50);
    if (C2e >=1);
    if (C3e >=1);
    if (C4e >=1);
    if (C5e >=1);
    if (C6e >=1);
    if (C7e >=1);
    if (C8e >=1);
    if (C9e >=1);
    if (C10e >=1);
    if (C11e >=1);
    
   
    
    
    
}

void measureTime(){}

*/
char getState(char ContactInput){ 
                  
             if(ContactInput = 'C1'){
              //Serial.println(ContactInput);
               if(digitalRead(C1auf) == LOW){          //C1 ist offen
                  C1a = 1;                              //Setze Zustand C1auf auf 1
                  C1state = 'A';
               } else {
                  C1a = 0;                              //Setze Zustand C1zu auf 0  
                  C1state = 'u';

                    if(digitalRead(C1zu) == LOW){      //C1 ist zu
                      C1z = 1;                          //Setze Zustand C1zu auf 1
                      C1state = 'Z'; 
                    } else {
                      C1z = 0;                          //Setze Zustand C1zu auf 0
                      C1state = 'u';
                    } 
               }
             }


             if(ContactInput = 'C2'){
              //Serial.println(ContactInput);
               if(digitalRead(C2auf) == LOW){          //C2 ist offen
                  C2a = 1;                              //Setze Zustand C2auf auf 1
                  C2state = 'A';
               } else {
                  C2a = 0;                              //Setze Zustand C2auf auf 0  
                  C2state = 'u';

                    if(digitalRead(C2zu) == LOW){         //C2 ist zu
                      C2z = 1;                          //Setze Zustand C2zu auf 1
                      C2state = 'Z'; 
                    } else {
                      C2z = 0;                          //Setze Zustand C2zu auf 0
                      C2state = 'u';
                    } 
               }
             }

              
               
             /* 
              *  
              *  
              *  Serial.println("------------------------");
               Serial.print("local debug"); 
               Serial.print(" C1A- ");
               Serial.print(C1a);
               Serial.print("----");
               Serial.print(" C1Z - ");
               Serial.print(C1z);
               Serial.print("----");
               
               
               Serial.println("------------------------");
               Serial.print("local debug"); 
               Serial.print(C1state);
               Serial.print("--");
               Serial.print(ContactInput);
               Serial.print("--");
               Serial.print(digitalRead(C1auf));
               Serial.print(digitalRead(C1zu));


              Serial.println("###");
               } else {
                C1state = 'f';
                
                 if(ContactInput = 0){
               //C1 ist offen
               //C1state = 'A';
               Serial.println(C1state);
               
                
               }
               
             
               } else {
                C1state = 'f';
               }                                  
             }*/
 
}


int Out(char color1, int addr){
 if (addr == 1){ 
  if(color1 == 'r'){
    digitalWrite(Out1A, HIGH);
    digitalWrite(Out1B, LOW);
    digitalWrite(LED, HIGH);
    //Serial.println("r1");
    }
  if(color1 == 'g'){
    digitalWrite(Out1A, LOW);
    digitalWrite(Out1B, HIGH);
    digitalWrite(LED, HIGH);
    //Serial.println("g1");
  }
  if(color1 == 'b'){
    digitalWrite(Out1A, LOW);
    digitalWrite(Out1B, LOW);
    digitalWrite(LED, LOW);
    //Serial.println("b1");
  }
 }

  if (addr == 2){ 
    if(color1 == 'r'){
      digitalWrite(Out2A, HIGH);
      digitalWrite(Out2B, LOW);
      digitalWrite(LED, HIGH);
      //Serial.println("r2");
      }
    if(color1 == 'g'){
      digitalWrite(Out2A, LOW);
      digitalWrite(Out2B, HIGH);
      digitalWrite(LED, HIGH);
      //Serial.println("g2");
    }
    if(color1 == 'b'){
      digitalWrite(Out2A, LOW);
      digitalWrite(Out2B, LOW);
      digitalWrite(LED, LOW);
      //Serial.println("b2");
    }
   
 }

 

}


    

