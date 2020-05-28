// Prototype de transmission de donnée en RS485 depuis l'ESP32

int enablePin = 2; // Pin de com pour entrée (LOW) ou sortie (HIGH)
void setup() {
  
  Serial.begin(9600);                   // On met le baudrate à 9600
  pinMode(enablePin, OUTPUT);           // On met la pin en OUTPUT
  delay(10);                            // Un peu de delai
  digitalWrite(enablePin, LOW);
  
}

void loop() {

  digitalWrite(enablePin, HIGH);
  String msg = "Test envoie information";
  Serial.print(msg);
  Serial.flush();
  delay(100);
  digitalWrite(enablePin, LOW);
  
}
