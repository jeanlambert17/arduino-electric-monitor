void serialEvent(){
  while (node.available()) {
    delay(3); // Delay necesario para leer el proximo caracter;
    char c = node.read(); // Leer el caracter;
    readString += c; // Se anade el caracter al string;
  }
  if (readString.length() > 0) {
    Serial.println("Received: " + readString);
    readString = ""; // Se limpia el String que contiene el valor obtenido;

    // Manejador de eventos del relay;
    relayHandler();
  }
}