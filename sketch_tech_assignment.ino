#include <WiFi.h>
#include <HTTPClient.h>

// network
const char *ssid = "Sabrina";
const char *password = "azmisyahrulsabrina";

// server URL
const char *serverName = "http://192.168.1.5:5000/ldr_sensor_data";

// Sensor LDR pin
#define LDR_PIN 34

void setup()
{

  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  pinMode(LDR_PIN, INPUT);
}

void loop()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    // Read sensor data
    int lightValue = analogRead(LDR_PIN);
    Serial.print("LDR Value: ");
    Serial.println(lightValue);

    String sensorData = String(lightValue);

    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    String httpRequestData = "{\"sensor_data\": \"" + sensorData + "\"}";

    int httpResponseCode = http.POST(httpRequestData);

    if (httpResponseCode > 0)
    {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    }
    else
    {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
  else
  {
    Serial.println("WiFi Disconnected");
  }

  delay(5000);
}
