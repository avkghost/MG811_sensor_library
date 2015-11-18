/*

MG.cpp

Created by Andrey Kozeletsky <andrey.kozeletsky@gmail.com> on 19.11.15.
Source code based on http://sandboxelectronics.com/?p=147
  
Author:	Andrey Kozeletsky <andrey.kozeletsky@gmail.com>
	Tiequan Shao: tiequan.shao@sandboxelectronics.com
	Peng Wei:     peng.wei@sandboxelectronics.com
 
Lisence: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
 
Note:    This piece of source code is supposed to be used as a demostration ONLY. More
         sophisticated calibration is required for industrial field application. 
*/

#include "MG.h"

/************************Hardware Related Macros************************************/
#define         MG_PIN                       (0)     //define which analog input channel you are going to use
#define         BOOL_PIN                     (2)
#define         DC_GAIN                      (8.5)   //define the DC gain of amplifier
 
/***********************Software Related Macros************************************/
#define         READ_SAMPLE_INTERVAL         (50)    //define how many samples you are going to take in normal operation
#define         READ_SAMPLE_TIMES            (5)     //define the time interval(in milisecond) between each samples in 
                                                     //normal operation
 
/**********************Application Related Macros**********************************/
//These two values differ from sensor to sensor. user should derermine this value.
#define         ZERO_POINT_VOLTAGE           (0.220) //define the output of the sensor in volts when the concentration of CO2 is 400PPM
#define         REACTION_VOLTGAE             (0.020) //define the voltage drop of the sensor when move the sensor from air into 1000ppm CO2
 
/*****************************Globals***********************************************/
float           CO2Curve[3]  =  {2.602,ZERO_POINT_VOLTAGE,(REACTION_VOLTGAE/(2.602-3))};   
                                                     //two points are taken from the curve. 
                                                     //with these two points, a line is formed which is
                                                     //"approximately equivalent" to the original curve.
                                                     //data format:{ x, y, slope}; point1: (lg400, 0.324), point2: (lg4000, 0.280) 
                                                     //slope = ( reaction voltage ) / (log400 –log1000) 

MG::MG(uint8_t pin, uint8_t type)
{
    _pin = pin;
    _type = type;

#ifdef __AVR
    // TODO: 
#endif
}

void MG::begin(void)
{
    // TODO:
}

int MG::readCO2(void)
{
    
}

float MG::readSeries(void)
{
    float v=0;

    for (int i=0;i<READ_SAMPLE_TIMES;i++) {

        v += analogRead(_pin);
        delay(READ_SAMPLE_INTERVAL);

    }

    v = (v/READ_SAMPLE_TIMES) * 5. / 1024.;
    return v;
}

int MG::calculateValue(float value, float *values)
{
    int result;
    float currentValue = (value/DC_GAIN);
   if (currentValue >= ZERO_POINT_VOLTAGE) {
	result = -1;
   } else {
	result = pow(10, (currentValue - values[1]) / values[2] + values[0]);
   }

    return result;

}