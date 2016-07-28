# dater

Developed by : Ahmed Maklad ,

A  Unix/Linux C utitlity to manipulate dates in unix/Linux
This program is to display time and make decrement and increments for you.

There seems to be a problem if you want to manuipulate dates in Linux and unix shell scripts, there seems to be no direct command or utility to perform this.
The idea is to use the mktime system API to perform these calculations.

possible  command line options:

-y    years_to_incremnt

-m    month_to_incremnt

-d    days_to_incremnt

-i  yyyymmdd  // this option if <you want to perform calculations other than sysdate


dater : the program for calculating dates relative to sysdate. Uses the system calls time(),localtime() and mktime() to be able to subtract or add days, months and years.
                        
Usage : date -x n 
    x : could be d/day, m/month and y/year.
    n : a number with + or - 

Examples :
    ex.(1): returns the date of yesterday. 
    dater -d -1 
  
    ex.(2): returns same day next month. 
    dater -m +1 
  
    ex.(3): returns same day last year.
    dater -y -1
   
    ex.(4): makes all calculations based on the provided date, using a date other than the system's. adds one month to October 5 2006
    dater -i 20060510 +m
    
    ex.(5): returns todays date. 
    dater 
    
    Return format :
         _07_03_2005_16_23_34_Mon Mar  7 16:23:34 2005 
         _DD_MM_YYYY_HH_MI_SS_DAY MON  wDay HH:MI:SS YYYY
  
  
  hours (HH) are in 24 format
  
  room for expansion:
  - Output format options
  - Output EPOCH time
  - Input EPOCH time
  - First day of the month
  - Last day of the month
  - Week Number
  
  
