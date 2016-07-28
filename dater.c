/*

NAME : dater

Version : 2 (2005 04 01)

Developed by : Ahmed Maklad ,

*/

 

/*

This program is to display time

and make decrement and increments for you.

possible options:

-y    years_to_incremnt

-m    month_to_incremnt

-d    days_to_incremnt

-i  yyyymmdd  // this option if <you want to perform calculations other than sysdate

*/

 

#include <time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int   main (int argc ,char *argv[],char *envp[])
{
            // variables related to time calculation
        int i;
            int fd=0,fm=0,fy=0;
        time_t t;
        struct tm *tp;
        char *ts;

            // variables of input time
            char stryy[5];
            char strmm[3];
            char strdd[3];

            // variables related to GetOpt for parsing command line
            int c;
            char *filename;
            extern char *optarg;
            extern int optind, optopt, opterr;

        /*
              // loop through command arguments
              // used only for debugging
        for (i=0;i<argc;i++)
        {
                printf (" %s \n",argv[i]);
        };
        */

       

        time (&t);
        tp = localtime(&t);
        //printf("Time Before :%ld \n",t);
             // parsing the command line options
        while ((c = getopt(argc, argv, ":i:y:m:d:h")) != -1) {
         switch(c) {
             case 'i':
                   if (strlen(optarg)==8) {          
                              strncpy(stryy,optarg,4);
                              strncpy(strmm,optarg+4,2);
                              strncpy(strdd,optarg+6,2);
                              // debug only
                              // printf ( "input date : YYYY/MM/DD: %s %s %s \n",stryy,strmm,strdd );                       
                              tp->tm_mday = atoi (strdd);
                              tp->tm_mon  = atoi (strmm)-1;
                              tp->tm_year = atoi (stryy)-1900;         
                        }
                    else
                        printf("invalid input date in option -i, should be in format YYYYMMDD \n");
                    break;

         case 'y':
              fy = atoi( optarg );
              break;

         case 'm':
              fm = atoi( optarg );             
              break;

         case 'd':
              fd = atoi( optarg );                           
              break;

         case 'h':
                        printf (" dater : the program for calculating dates relative to sysdate. Uses the system calls time(),localtime() and mktime() to be able to subtract or add days, months and years. \n");
                        printf (" Developed by :\n");
                        printf (" \t Ahmed Maklad, April 2005.  \n");
                        printf (" Usage : date -x n \n");
                        printf ("\t x : could be d/day, m/month and y/year.\n");
                        printf ("\t n : a number with + or - . \n");
                        printf (" Examples :\n");
                        printf ("\t ex.(1): dater -d -1 \t: returns the date of yesterday. \n");
                        printf ("\t ex.(2): dater -m +1 \t: returns same day next month. \n");
                        printf ("\t ex.(3): dater -y -1 \t: returns same day last year. \n");
                        printf ("\t ex.(4): dater -i 20060510 \t: makes all calculations based on the provided date, using a date other than the system's. \n");
                        printf ("\t ex.(5): dater \t\t: returns todays date. \n");
                        printf (" Return format :\n");
                        printf ("\t _07_03_2005_16_23_34_Mon Mar  7 16:23:34 2005 \n");
                        printf ("\t _DD_MM_YYYY_HH_MI_SS_DAY MON  wDay HH:MI:SS YYYY \n");
                        printf ("\t hours (HH) are in 24 format \n");
                        printf ("Today is : \n");
                        break;

             case ':':
              printf("-%c without argument\n", optopt);
              break;

         case '?':
              printf("unknown arg %c\n", optopt);
              break;

         }

     }

      if (argc > 1)
      {          
            // applying factors to tp structure      
            tp->tm_mday = tp->tm_mday + fd;
            tp->tm_mon = tp->tm_mon + fm;
            tp->tm_year = tp->tm_year + fy;
            // converting updated tp structure to millesconds and back again to tp structure           
            t = mktime(tp);
            tp = localtime(&t);                           
      };   

        /*
        printf("Time After : %ld \n",t);
        printf("Time %d:%d:%d \n", tp->tm_hour,tp->tm_min,tp->tm_sec);
        printf("Day of Week : %d\n" ,tp->tm_wday+1);
        printf("Day of Year : %d\n" ,tp->tm_yday+1);
        */

        ts = asctime(tp);
        printf ("%002d_%002d_%0004d_%002d_%002d_%002d=%s",
                tp->tm_mday ,
                tp->tm_mon  +1 ,
                tp->tm_year +1900 ,
                tp->tm_hour ,
                tp->tm_min  ,
                tp->tm_sec  ,
                ts
                );

        return 0;
}
