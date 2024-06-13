# ESP32 LDR Sensor Data Logger

By: Syahrul Mubarak

This project utilizes an ESP32 to read data from an LDR (Light Dependent Resistor) sensor and send it to a Flask server via HTTP POST. The Flask server receives the sensor data, records the timestamp, and responds with a confirmation message.

## Key Features
* LDR Sensor Reading:

  The ESP32 reads light intensity values from an LDR sensor connected to an analog pin.
* WiFi Connectivity:

  The ESP32 connects to a WiFi network to send sensor data to the server.
* Sensor Data Transmission:

  The light intensity data is sent to the Flask server via HTTP POST every 5 seconds.
* Timestamp Recording:

  The Flask server records the timestamp when the sensor data is received.

## Usage
* Power on the ESP32.
* Ensure the ESP32 is connected to the same WiFi network as the Flask server.
* Run the Flask server (server.py).
* The LDR sensor data will be sent every 5 seconds to the Flask server, and the timestamp will be recorded.