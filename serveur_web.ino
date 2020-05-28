// Test de creation de serveur web depuis l'ESP32

#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

AsyncWebServer server(80);

const char* PARAM_INPUT_1 = "input1";
const char* PARAM_INPUT_2 = "input2";

const char index_html[] PROGMEM = R"rawliteral(
      <!DOCTYPE HTML>
      <html>
      <head>
        <title>BORNE DE RECHARGE 1</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta charset=\"utf-8\" />
      </head>
      <body>
        <form action="/get">
          Identifiant  :<input type="text" name="identifiant"><br>
          Mot de passe :<input type="password" name="motdepasse"<br>
          <input type="submit" value="Se connecter">
        </form>
      </body>
      </html>)rawliteral";

void setup(void) {
  Serial.println("Parametrage du point d'accès...");
  
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAP("Borne-1","projetbts");
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });
  
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    String inputParam;
    // GET input1 value on <ESP_IP>/get?input1=<inputMessage>
    if (request->hasParam(PARAM_INPUT_1)) {
      inputMessage = request->getParam(PARAM_INPUT_1)->value();
      inputParam = PARAM_INPUT_1;
    }else {
      inputMessage = "No message sent";
      inputParam = "none";
    }
    Serial.println(inputMessage);
    request->send(200, "text/html", "Requête HHTP GET reçu sur votre ESP32 on input field (" 
                                     + inputParam + ") with value: " + inputMessage +
                                     "<br><a href=\"/\">Retourner à l'accueil</a>");
  });
  server.begin();
}

void loop(void) {
}

/*
void Accueil() {
  String msg;
  if (server.hasHeader("Cookie")) {
    Serial.print("Found cookie: ");
    String cookie = server.header("Cookie");
    Serial.println(cookie);
  }
  if (server.hasArg("DISCONNECT")) {
    Serial.println("Disconnection");
    server.sendHeader("Location", "/");
    server.sendHeader("Cache-Control", "no-cache");
    server.sendHeader("Set-Cookie", "ESPSESSIONID=0");
    server.send(301);
    return;
  }
  if (server.hasArg("identifiant") && server.hasArg("motdepasse")) {
      server.sendHeader("Location", "/");
      String id = server.hasArg("identifiant");
      String pswd = server.hasArg("motdepasse");
      msg = "Votre identifiant est :" + id + " et votre mot de passe est : " + pswd + ".";
      server.send(301);
      Serial.println("Log in Successful");
      return;
    }
    msg = "Remplissez tous les champs, ou logs incorrect";
    Serial.println("Log in Failed");
  }
  String content = "<!DOCTYPE html>";
    content += "<head>";
    content += "<title>BORNE DE RECHARGE 1</title>";
    content += "<meta charset=\"utf-8\" />";
    content += "</head>";
    content += "<body>";
    content += "<h2>Borne 1 : Connexion</h2>";
    content += "Identifiant  :<input type='text' name='identifiant' placeholder='user name'><br>";
    content += "Mot de passe :<input type='password' name='motdepasse'<br>";
    content += "<input type='submit' name='SUBMIT' value='Submit'></form> <br>";
    content += "</body>";
    content += "</html>";
  server.send(200, "text/html", content);
}
*/
