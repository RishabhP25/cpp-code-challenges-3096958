// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cmath>

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    // Write your code here
    if (birth_d > 31) {
        std::cout << "Please enter a real birth day!" << std::endl << std::endl << std::flush;
    } 

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    // Extract day, month, and year components
    int day = now->tm_mday;
    int month = now->tm_mon + 1; // Month is zero-based
    int year = now->tm_year + 1900; // Years since 1900

    // Store components in separate strings
    std::ostringstream dayStr, monthStr, yearStr;
    dayStr << day;
    monthStr << month;
    yearStr << year;

    // Retrieve strings
    std::string dayString = dayStr.str();
    std::string monthString = monthStr.str();
    std::string yearString = yearStr.str();

    int diff_in_year = year - birth_y;
    int diff_in_month = month - birth_m;
    int diff_in_day = std::abs(day - birth_d);

    age = (diff_in_year * 365) + (diff_in_month * 31) - (diff_in_day);

    if (diff_in_year >= 120) {
        std::cout << "Come on. You can't be " << diff_in_year << " years old!. Its a bluff please enter a proper birth year" << "\n\n" << std::flush;
    }

    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
