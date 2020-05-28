// Protoype de recpetion de donnée en RS485 depuis l'ESP32

int enablePin = 2; // Pin de com pour entrée (LOW) ou sortie (HIGH)

void setup() {
  
  Serial.begin(9600);                   // On met le baudrate à 9600
  pinMode(enablePin, OUTPUT);           // On met la pin en OUTPUT
  delay(10);                            // Un peu de delai

}

void loop() {                                       
  while (Serial.available())                          // Capter en permanance une donnée
     {
        String msg = Serial.readString();             // On attend un STRING de la part de la RPi
        Serial.println(msg);                          // On l'affiche dans le moniteur
    }
}
