#include <WiFi.h>

const char* ssid = "SSID";      
const char* password = "PASSWORD";  
void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Connecting...");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  WiFi.begin(ssid, password);

  WiFi.setTxPower(WIFI_POWER_8_5dBm);

  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println("Connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
}
