//
//  MG.h
//  
//  
//  Created by Andrey Kozeletsky on 19.11.15.
//  Source code based on http://sandboxelectronics.com/?p=147
//

#ifndef MG_hpp
#define MG_hpp

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// Define types of sensors.
#define MG811 11

class MG {
public:
    MG(uint8_t pin, uint8_t type);
    void begin(void);
    int readCO2(void);

private:
    uint8_t _pin, _type;

    float readSeries();
    int calculateValue(float value, float *values);
};

#endif /* MG_hpp */
