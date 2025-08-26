#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("\nWiFi Connected!");
}

void loop() {
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    http.begin("http://yourserver.com/capture"); // Simulate capture
    int httpCode = http.GET();
    if(httpCode>0){
      Serial.println("Image capture triggered!");
    }
    http.end();
  }
  delay(10000); // capture every 10 sec
}
