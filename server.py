from flask import Flask, request, jsonify
from datetime import datetime

app = Flask(__name__)

@app.route('/ldr_sensor_data', methods=['POST'])
def save_sensor_data():
    data = request.json
    sensor_data = data.get('sensor_data')
    
    timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    
    print(f"Received value LDR sensor data: {sensor_data} at {timestamp}")
    
    return jsonify({"ldr_sensor_data": sensor_data, "status": "success", "timestamp": timestamp})

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)
