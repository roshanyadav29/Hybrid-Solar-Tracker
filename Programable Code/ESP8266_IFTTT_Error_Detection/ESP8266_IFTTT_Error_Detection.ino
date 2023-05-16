/*
Project Code: ESP8266 Wi-Fi Module
*/

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "abcd";  // Insert SSID for the Wi-fi here
const char* password = "1234";  // Insert Password for Wi-fi here

const char* host = "maker.ifttt.com";
const int httpsPort = 443;

const int API_TIMEOUT = 10000;
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  client.setInsecure();
  client.setTimeout(API_TIMEOUT);
  Serial.print("Connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection failed");
    return;
  }

  String url = "/trigger/.../with/key/...";  // Project/Applet Name and Generated Key Here
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "User-Agent: BuildFailureDetectorESP8266\r\n" + "Connection: close\r\n\r\n");

  Serial.println("Request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("Headers Received");
      break;
    }
  }
  String line = client.readStringUntil('\n');

  Serial.println("Reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("Closing connection");
}
void loop() {
}