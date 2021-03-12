// Compteur pour les exercices du livre
// exoCount v2

#define workPin 3
#define yellowPin 4
#define greenPin 5
#define pushButton 2

int myBluePins[] = {7, 8, 9, 10, 11, 12};

int arraySerie[] = {6, 6, 6, 6, 6, 6, 4, 6, 6, 4};
int arrayCommonRest[] = {25, 25, 25, 25, 25, 25, 25, 25, 25, 60};
int arrayLongRest[] = {25, 25, 180, 180, 120, 180, 180, 180, 90, 60};

//char arrayExoName[] = {"bras1", "bras2", "bras3", "Bras4", "JambeDroite", "JambeGauche", "Saut", "AbdosHaut", "AbdosBas", "Bras5"};
int exoBras1[] = {6, 25, 25};

int serie = 0;
int exercice = 0;
int secondes;
int count;
int modulo;

//void verifExercice(){
//  for (int x = 0; x < 10; x = x + 1) {
//    int myRest =  arrayCommonRest[x];
//    int myLongRest = arrayLongRest[x];
//    int mySerie = arraySerie[x];
//
//    Serial.println ("");
//
//    Serial.println ("Top");
//    Serial.println (x + 1);
//    Serial.println(myRest);
//    Serial.println(myLongRest);
//    Serial.println(mySerie);
//  }
//}



void setup()
{
  Serial.begin(9600);
  for (int x = 3; x <= 13; x = x + 1) {
    pinMode(x, OUTPUT);
  }
  pinMode(pushButton, INPUT);
  digitalWrite(workPin, HIGH);
}

void loop()
{
  int buttonState = digitalRead(pushButton);

  if (buttonState == 1) {
    
    if (serie < arraySerie[exercice]){
      serie = (serie + 1);
      digitalWrite(serie + 6, HIGH);
      String strOne = "Serie finished : ";
      Serial.println(strOne + serie);
      commonRest(arrayCommonRest[exercice]);
    }
  
    if (serie == arraySerie[exercice]){
      exercice = (exercice + 1);
      String strOne = "Exercice finished : ";
      Serial.println(strOne + exercice);
      longRest(arrayLongRest[exercice]);
    }

 }
}

void offPin(){
  
    for (int x = 3; x < 13; x = x + 1) {
      digitalWrite(x, LOW);
    }
    
}

void commonRest(int x){
  
    Serial.println("let's take few rest...");
    digitalWrite(workPin, LOW);
    
    for (secondes = 0; secondes < x; ++secondes) {
      
      if (secondes <= 20){
        blinkLed(greenPin);
      }
      
      if (secondes > 20){
        blinkLed(yellowPin);
      }
      
    }
    
    Serial.println("Rest over !!");
    digitalWrite(workPin, HIGH);
    
} 

void blinkLed(int x){
  
  digitalWrite(x, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(x, LOW);
  delay(500); // Wait for 500 millisecond(s)
  
}

void longRest(int x){
  
  Serial.println("let's take some long rest...");
  digitalWrite(workPin, LOW);

  int tours = x / 6;
  int tiers = tours / 3;
  int deuxTiers = tiers * 2;
  
  //Serial.println (tiers);
  //Serial.println (deuxTiers);
  //Serial.println (tours);
  
  for (count = 0; count < tours; ++count) {
    //Serial.println (count);
    
    modulo= count % 2;

    if (count >= tiers) {
      digitalWrite(greenPin, HIGH);
    }

    if (count >= deuxTiers) {
      digitalWrite(yellowPin, HIGH);
    }

    for (int i = 7; i <= 12; i = i + 1) {
      delay(1000); // Wait for 500 millisecond(s)
      if (modulo == 1){
        digitalWrite(i, LOW);
      }
      
      if (modulo == 0){
        digitalWrite(i, HIGH);
      }
      
    }
  }
  resetSerie();
}

void resetSerie(){
  
  serie = 0;
  offPin();
  digitalWrite(workPin, HIGH);
  
}
