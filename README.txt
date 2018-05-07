Written by Michael Bosik

Files Included:
 - PA1.c
 - README.txt

How to Compile:
 - Navigate to the file directory on your virtual machine.
 - Enter the command: "gcc -Wall -o PA1 PA1.c"
 - Enter the command: "./PA1"
 - A prompt will appear that says "Please enter year for this calendar: "
 - Enter any non-negative number as a year to see the modern calendar for that year.

Errors Compiling:
 - If the year entered by the user is a negative number, the program will output an error saying: "Error: INVALID YEAR - The year must be greater than 0."

Difficulties Programming:
 - One of the biggest challenges while creating this project was trying to figure out which day of the week to start the year on. In the end, I had found
 an equation posted to Wikipedia that I used in order to do this. The equation will determine the starting day of the year on a scale of 0 to 6. This allows
 me to create the calendar for the rest of the year continuing from this starting day.

Loop Invariants:
 - In the printCalendar() method, the for loop cycles once for every month in the year and calls the printMonth() method in order to print the month.
 - In the printMonth() method, the first for loop is strictly to create the proper indentation on the first line of every month. It does this by creating
 5 blank spaces for each day of the week before the starting day of the month held in the startingDay variable.
 - In the printMonth() method, the second for loop runs for as many days as there are in the current month as returned by a call to printMonthName(). It
 prints each day of the month with proper spacing in between and under the correct day of the week.

Sources:
 - The only part of this code that was taken from an exterior source can be found in the return statement of the findStartingDay() method. This 45 character
 long equation was found on Wikipedia "Determination of the Day of the Week" (https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week). It is used to
 calculate which day of the week a given year, month and day falls on at any point in the modern calendar.
