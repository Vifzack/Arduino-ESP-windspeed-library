
#ifndef Windspeed
#define Windspeed

#include "Arduino.h"


class anemometer                                                                               //define a class named NTC
{
private:                                                                                //private section of the class
    unsigned int Pin;                                                                          //variables for calculation are declared here
    float radius;
    unsigned int counterElements;

    float speed_kmh;
    float speed_ms;
    float rpm;
    int counts;
    unsigned int startMillis=0;
    

    float intervall = 1.00;
    const float pi = 3.14159265359;



public:                                                                                 //public section oft the class
    anemometer(unsigned int SignalPin, float Radius, unsigned int CounterElements);                        //here are all the functions from this library defined
                                                                                        
    float getWindspeedKmh(); 
    float getWindspeedKmhFromMs(); 
    float getWindspeedMs();
    float getRPM();
    float getCounts();
    bool setIntervall(float Intervall);
    void writeCounts(unsigned int Counts);

    
};

#endif 