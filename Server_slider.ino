#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Servo.h>

#include "index.h" //Our HTML webpage contents

const char *ssid = "ServoWifi";
const char *password = "inirahasia";

//Servo objects created to control the servos
Servo myServo1;
Servo myServo2;
int servo1 = D8; //Digital PWM pin used by the servo 1
int servo2 = D6; //Digital PWM pin used by the servo 2

ESP8266WebServer server(80);

void handleRoot() {
  digitalWrite(LED_BUILTIN, !1);
  String page = MAIN_page;
  server.send(200, "text/html", page);
  digitalWrite(LED_BUILTIN, !0);
}

void handleData() {
  digitalWrite(LED_BUILTIN, !1);
  int x = server.arg("x").toInt();
  int y = server.arg("y").toInt();
  myServo1.write(x);
  myServo2.write(y);

  String note = "Servo pos x:" + String(x) + "\ty: " + String(y);
  Serial.println(note);
  server.send(200, "text/plain", "ok");
  digitalWrite(LED_BUILTIN, !0);
}

void setup(void) {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, !0);
  Serial.begin(115200);

  Serial.print("\n\nConfiguring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  
  server.on("/", handleRoot);
  server.on("/sliderdata", handleData);


  server.begin();
  Serial.println("HTTP server started");

  myServo1.attach(servo1);
  myServo2.attach(servo2);
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
