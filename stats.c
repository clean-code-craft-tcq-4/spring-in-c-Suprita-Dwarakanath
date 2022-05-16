#include "stats.h"
#include "alerters.h"
#include <stdio.h>
#include "math.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
    long int count;
    s.average = 0;
    s.min = numberset[0];
    s.max = numberset[0];

    if(setlength == 0)
    {
        s.average = NAN;
        s.max = NAN;
        s.min = NAN;
    }
        

    
    else
    {
        for(count = 0; count < setlength; count++)
        {
            s.average += numberset[count];

            if(numberset[count] < s.min)
            {
                s.min = numberset[count];
            }

            if(numberset[count] > s.max)
            {
                s.max = numberset[count];
            }
        }
    
        s.average = s.average / setlength;
    }
   
    return s;
    
}


void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    int loopCount;


     if (computedStats.max > maxThreshold)
    {
        for(loopCount = 0; loopCount < 2; loopCount++)
        {
            alerters[loopCount]();
        }        
    }

    printf("Value of emailAlertCallCount is %d \n", emailAlertCallCount);
    printf("Value of ledAlertCallCount is %d \n", emailAlertCallCount);
}

