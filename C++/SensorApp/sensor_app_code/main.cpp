
#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

// sensor data
struct SensorData {
    double temperature;
    double humidity;
    double pressure;
};

// simulate sensor data reading
SensorData readSensorData() {
    static default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());

    static uniform_real_distribution<double> temperatureDistribution(20.0, 30.0);
    static uniform_real_distribution<double> humidityDistribution(30.0, 60.0);
    static uniform_real_distribution<double> pressureDistribution(980.0, 1020.0);

    // Generate random sensor data
    SensorData data;
    data.temperature = temperatureDistribution(generator);
    data.humidity = humidityDistribution(generator);
    data.pressure = pressureDistribution(generator);
    

    return data; 
}

// calculate the average of values in a vector
double calculateAverage(const vector<double>& values) {
    return accumulate(values.begin(), values.end(), 0.0) / values.size();
}

int main() {
    const int numberOfReadings = 100;

    // sensor readings
    vector<double> temperatureReadings;
    vector<double> humidityReadings;
    vector<double> pressureReadings;

    // Simulate sensor data readings
    for (int i = 0; i < numberOfReadings; ++i) {
        SensorData data = readSensorData();

        temperatureReadings.push_back(data.temperature);
        humidityReadings.push_back(data.humidity);
        pressureReadings.push_back(data.pressure);

        // 100 milliseconds between readings
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    double avgTemperature = calculateAverage(temperatureReadings);
    double avgHumidity = calculateAverage(humidityReadings);
    double avgPressure = calculateAverage(pressureReadings);

    cout << "Average Temperature: " << avgTemperature << " C" << endl;
    cout << "Average Humidity: " << avgHumidity << " %" << endl;
    cout << "Average Pressure: " << avgPressure << " hPa" << endl;

    return 0;
}
