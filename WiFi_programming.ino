#include "WiFi.h"
#include "ArduinoOTA.h"

const char* ssid = "...";
const char* password = "...";

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Ошибка подключения к WIFI, перезагрузка...");
    delay (5000);
    ESP.restart();
  }
  ArduinoOTA.setHostname("my-esp32");
  ArduinoOTA.begin();

  Serial.println("Готово");
  Serial.print("IP адрес:");
  Serial.println(WiFi.localIP());

}

void loop() {
  ArduinoOTA.handle();
 
}
