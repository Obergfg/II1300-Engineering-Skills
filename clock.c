#include <stdio.h>

int time_update(int);       // Assigns new values to the variables hours, min and sec
                            // based on the latest value of present_time
int main()
{
    int present_time;           // The variables used in the program
    int time_for_alarm;
    int hours;
    int min;
    int sec;
    
    printf("Enter present time, HHMMSS:");
    scanf("%d", &present_time);
   
    printf("Enter time for alarm, HHMMSS:");
    scanf("%d", &time_for_alarm);

    while (!(present_time == time_for_alarm))   // A loop which loops until present_time == time_for_alarm
    {
        hours = (present_time/10000);
        min = ((present_time - (hours*10000))/100);
        sec = (present_time%100);
        
        
        printf("%d:%d:%d\n", hours, min, sec);
        
        present_time = time_update(present_time);

    }

    printf("ALARM");
   
    return 0;
    
}

int time_update(int present_time)      // The function time_update
{
    present_time++;                    // Adds 1 to present_time representing a second passed
    
    int hours = (present_time/10000);
    int sec = (present_time%100);
    
    
    if(sec >= 60)       // If the variable sec >= 60 add 40 to present_time
        {
            present_time = (present_time + 40);
        }
        
    int min = ((present_time - (hours*10000))/100);    
        
        if(min >= 60)       // If the variable min >= 60 add 4000 to present_time
        {
            present_time = (present_time + 4000);
        }
        
         if(present_time >= 240000)     // If the variable present_time >= 240000 
        {                               // (representing the clock has passed 24h) reset present_time to 0
            present_time = 0;
        }
        
        return present_time;            // Returns a new value to present_time in main function
        
}

