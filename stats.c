#include "stats.h"
#include <stdio.h>
#include "math.h"

struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
    long int count;
    s.average = 0;
    s.min = numberset[0];
    s.max = numberset[0];

    printf("numberset %f and *numberset %f\n", &numberset, *numberset);


    for(count = 0; count < setlength; count++)
    {;
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


    return s;
}



int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
