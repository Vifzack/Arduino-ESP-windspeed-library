#include "Windspeed.h" //include header file

anemometer::anemometer(unsigned int SignalPin, float Radius, unsigned int CounterElements) // define function of class anemometer to initialize 
{                                                                                          // function is used for initializing the object
    Pin = SignalPin;                                                                       // all the elements in brackets in the function get written to private variables
    radius = Radius;
    counterElements = CounterElements;
    pinMode(Pin, INPUT_PULLDOWN_16);
}

float anemometer::getWindspeedKmh()
{
    yield();
    counts = 0;
    startMillis = millis();
    while ((millis() - startMillis) <= intervall)
    {
        yield();

        int lastState = digitalRead(Pin);
        if (digitalRead(Pin) == HIGH && lastState != digitalRead(Pin))
        {
            counts++;
        }
    }
    speed_kmh = 2 * pi * radius * (counts / (intervall / 1000)) * 3.6;

    return speed_kmh;
}

float anemometer::getWindspeedMs()
{
    yield();
    counts = 0;
    startMillis = millis();
    while ((millis() - startMillis) <= intervall)
    {
        yield();

        int lastState = digitalRead(Pin);
        if (digitalRead(Pin) == HIGH && lastState != digitalRead(Pin))
        {
            counts++;
        }
    }
    speed_ms = 2 * pi * radius * (counts / (intervall / 1000));

    return speed_ms;
}

float anemometer::getWindspeedKmhFromMs()
{
    speed_kmh = speed_ms * 3.6;
    return speed_kmh;
}

void anemometer::writeCounts(unsigned int Counts)
{
    counts = Counts/counterElements;
    Counts = 0;
}

float anemometer::getRPM()
{
    rpm = counts * (60 / (intervall / 1000));
    return rpm;
}

float anemometer::getCounts()
{
    return counts;
}

bool anemometer::setIntervall(float Intervall)
{
    intervall = Intervall;
    return 1;
}