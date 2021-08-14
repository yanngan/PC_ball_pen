
// Rotary Encoder Inputs
#define inputCLK 3
#define inputDT 2


int counter = 0; 
int currentStateCLK;
int previousStateCLK; 
int timeToDelay = 10;
String encdir ="";

void setup() { 
 pinMode(13,OUTPUT);
 // Set encoder pins as inputs  
 pinMode (inputCLK,INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(inputCLK), hendelIncoder, CHANGE);
 pinMode (inputDT,INPUT);
 
 
 // Setup Serial Monitor
 Serial.begin (9600);
 
 // Read the initial state of inputCLK
 // Assign to previousStateCLK variable
 previousStateCLK = digitalRead(inputCLK);

} 

 
// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);
  delay(timeToDelay);
  digitalWrite(13, LOW);
  delay(timeToDelay);
}

void hendelIncoder(){
  // Read the current state of inputCLK
   currentStateCLK = digitalRead(inputCLK);
    
   // If the previous and the current state of the inputCLK are different then a pulse has occured
   if (currentStateCLK != previousStateCLK){ 
       
     // If the inputDT state is different than the inputCLK state then 
     // the encoder is rotating counterclockwise
     if (digitalRead(inputDT) != currentStateCLK) {
      if((counter-1) > 0){
        counter --;
      }
      encdir ="CCW";
       
     } else {
       // Encoder is rotating clockwise
       counter ++;
       encdir ="CW";
       
     }
     Serial.print("Direction: ");
     Serial.print(encdir);
     Serial.print(" -- Value: ");
     Serial.println(counter);
     
     Serial.print("timeToDelay = ");
     Serial.println(timeToDelay);
     timeToDelay = 10*counter;
     previousStateCLK = currentStateCLK;
   } 
   // Update previousStateCLK with the current state
}
