#include <stdio.h>

/**
 * Find the starting day of the year
 * @param y Year, entered by user
 * @return Day of the Week, 0 == Sunday ... 6 == Saturday;
 */
int findStartingDay(int y){
  int d,m; //d is the day of the month; m is the month of the year in the given year (y)
  m = d = 1; //d and m are both set to one as to mean January 1st;
  return (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7; //Returns the day of the week: 0 == Sunday ... 6 == Saturday;
}

/**
 * Print out the month name
 * @param year Year, entered by user
 * @param month Month, as an int 1-12 (1 = January ... 12 == December)
 * @return days of the month, int 28-31
 */
int printMonthName(int year, int month){
  switch (month) {
    case 1:
      printf("January, %i:\n", year);
      return 31;
    case 2:
      printf("February, %i:\n", year);
      //Checks if year is a leap year. Years that are divisible by 4 are leap years,
      //except that years divisible by 100 are not leap years unless they are also divisible by 400.
      //returns 29 if it is a leap year and 28 if not;
      if(year%400 == 0)
        return 29;
      else if(year%100 == 0)
        return 28;
      else if(year%4 == 0)
        return 29;
      else
        return 28;
    case 3:
      printf("March, %i:\n", year);
      return 31;
    case 4:
      printf("April, %i:\n", year);
      return 30;
    case 5:
      printf("May, %i:\n", year);
      return 31;
    case 6:
      printf("June, %i:\n", year);
      return 30;
    case 7:
      printf("July, %i:\n", year);
      return 31;
    case 8:
      printf("August, %i:\n", year);
      return 31;
    case 9:
      printf("September, %i:\n", year);
      return 30;
    case 10:
      printf("October, %i:\n", year);
      return 31;
    case 11:
      printf("November, %i:\n", year);
      return 30;
    case 12:
      printf("December, %i:\n", year);
      return 31;
  }
  return 0;
}

/**
 * Prints the months days
 * @param year Year, entered by user
 * @param month Month, as an int 1-12 (1 = January ... 12 == December)
 * @param startingDay day of the week, as an int 0-6 (0 = Sunday ... 6 = Saturday)
 * @return startingDay day of the week, as an int 0-6 (0 = Sunday ... 6 = Saturday)
 */
int printMonth(int year, int month, int startingDay){
  printf("\n");
  int days = printMonthName(year, month); //days will be set to the value returned by a call to printMonthName
  printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); //prints the days of the week in order at the beginning of each month

  //prevents blank line at the top of each month by making sure the startingDay is not above 6 (after Saturday)
  if(startingDay>6)
    startingDay=0;

  //will indent the first line of the month by 5 spaces for each day up to the given startingDay
  for(int j=0; j<startingDay; j++)
    printf("     ");

  //iterate through each day of the month up until the amount of days in the month stored in days
  for(int i=1; i<=days; i++){

    //if startingDay, the day of the week, exceeds 6 (after Saturday), start a new line and reset startingDay to 0 (Sunday)
    if(startingDay>6){
      printf("\n");
      startingDay=0;
    }

    //if the current day of the month, i, is less than 10 or a single digit, add one extra space to its indentation
    if(i<10)
      printf(" ");

    //print the day of the month with proper indentation and spacing afterward
    printf(" %d  ", i);

    //increase startingDay, the day of the week, by one, thus changing Sunday to Monday etc.
    startingDay++;
  }

  printf("\n");
  return startingDay;
}

/**
 * Prints the calendar for the entered year
 * @param year Year, entered by user
 * @param startingDay day of the week, as an int 0-6 (0 = Sunday ... 6 = Saturday)
 */
void printCalendar(int year, int startingDay){
  int tempDay; //tempDay is used as a temporary holder for the value returned by printMonth;
  for (int i = 1; i <= 12; i++) { //cycles once for every month in the year
    tempDay = printMonth(year, i, startingDay); //tempDay is set to the value returned by a call to printMonth;
    startingDay = tempDay; //startingDay is changed to tempDay, thus making the next call to printMonth have a startingDay after the last day of the previous month
  }
}

/**
 * Main loop
 * @return 0
 */
int main(){
  int year; //year is the year that the user will enter into the program after they are prompted to.
  printf("Please enter year for this calendar: ");
  scanf("%d", &year);
  if(year<=0){ //If the user enters a year that is less than 0, returns an error.
    printf("Error: INVALID YEAR - The year must be greater than 0.\n");
    return 0;
  }
  printf("\n  ***   CALENDAR for %d   ***\n", year);
  printCalendar(year, findStartingDay(year)); //Calls the printCalendar function with the user's entered year as the first argument and a call to findStartingDay with the year as the second argument.
  return 0;
}
