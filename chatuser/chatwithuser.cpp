#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <algorithm>
void sayHello() {  std::cout << "Hello, World!" << std::endl; }
void getCurrentDate(){    std::time_t now = std::time(nullptr);    std::tm* localTime = std::localtime(&now);    int year = localTime->tm_year + 1900;    int month = localTime->tm_mon + 1;    int day = localTime->tm_mday;    std::cout << "Today's date is " << day << "/" << month << "/" << year << "." << std::endl;}


int main()
{
    sayHello();
    getCurrentDate();    
    return 0;
}
