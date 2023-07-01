#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <algorithm>

// #define BUFFER_OVERFLOW
// #define INTEGER_OVERFLOW_2

void greetUser(const std::string& username)
{
    std::cout << "Hello, " << username << "!" << std::endl;
}

void getCurrentDay()
{
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    std::string day = "";

    switch (localTime->tm_wday)
    {
        case 0:
            day = "Sunday";
            break;
        case 1:
            day = "Monday";
            break;
        case 2:
            day = "Tuesday";
            break;
        case 3:
            day = "Wednesday";
            break;
        case 4:
            day = "Thursday";
            break;
        case 5:
            day = "Friday";
            break;
        case 6:
            day = "Saturday";
            break;
    }

    std::cout << "Today is " << day << "." << std::endl;

    //Flag will come here
}

// #define BUFFER_SIZE 8
// #define BUFFER_OVERFLOW

#ifdef BUFFER_OVERFLOW
void BasicQA()
{
    std::cout << "Chatbot: Do you love football? (yes/no)" << std::endl;

    std::string response;
    std::cout << "You: ";
    std::getline(std::cin, response);

    if (response == "yes")
    {
        std::cout << "Chatbot: Who is the current World Cup champion?" << std::endl;
        std::string answer;
        char buffer[BUFFER_SIZE]; // Buffer with limited size

        std::cout << "You: ";
        std::cin.getline(buffer, sizeof(buffer)); // Buffer overflow vulnerability here
        
        answer = buffer; // Assign buffer contents to answer
        
        std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer == "argentina")
        {
            std::cout << "Chatbot: That's great! Argentina is the current World Cup champion. Well done!" << std::endl;
        }
        else
        {
            std::cout << "Chatbot: Ahh, maybe you missed watching the World Cup final in 2022. The correct answer is Argentina." << std::endl;
        }

        std::cout << "Chatbot: How many players are there in a football playing team?" << std::endl;
        std::string numPlayers;
        std::cout << "You: ";
        std::getline(std::cin, numPlayers);

        if (numPlayers == "11")
        {
            std::cout << "Chatbot: Congratulations! You are correct. There are 11 players in a football playing team." << std::endl;
        }
        else
        {
            std::cout << "Chatbot: Oops! The correct answer is 11. Better luck next time!" << std::endl;
        }
    }
    else if (response == "no")
    {
        std::cout << "Chatbot: Alright, let me know if you have any other questions!" << std::endl;
    }
    else
    {
        std::cout << "Chatbot: I'm sorry, I didn't understand your response." << std::endl;
    }

    //Flag will come here
}
#endif

void BasicQA()
{
    std::cout << "Chatbot: Do you love football? (yes/no)" << std::endl;

    std::string response;
    std::cout << "You: ";
    std::getline(std::cin, response);

    if (response == "yes")
    {
        std::cout << "Chatbot: Who is the current World Cup champion?" << std::endl;
        std::string answer;
        std::cout << "You: ";
        std::getline(std::cin, answer);
        std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer == "argentina")
        {
            std::cout << "Chatbot: That's great! Argentina is the current World Cup champion. Well done!" << std::endl;
        }
        else
        {
            std::cout << "Chatbot: Ahh, masybe you missed watching the World Cup final in 2022. The correct answer is Argentina." << std::endl;
        }

        std::cout << "Chatbot: How many players are there in a football playing team?" << std::endl;
        std::string numPlayers;
        std::cout << "You: ";
        std::getline(std::cin, numPlayers);

        if (numPlayers == "11")
        {
            std::cout << "Chatbot: Congratulations! You are correct. There are 11 players in a football playing team." << std::endl;
        }
        else
        {
            std::cout << "Chatbot: Oops! The correct answer is 11. Better luck next time!" << std::endl;
        }
    }
    else if (response == "no")
    {
        std::cout << "Chatbot: Alright, let me know if you have any other questions!" << std::endl;
    }
    else
    {
        std::cout << "Chatbot: I'm sorry, I didn't understand your response." << std::endl;
    }

    //Flag will come here
}

#ifdef INTEGER_OVERFLOW_2

void FlipToNegative() {
    std::cout << std::unitbuf; // Enable automatic flushing for output

    int acc = 0;
    std::string input;

    std::cout << "Hello, welcome to this program\n";
    while (acc >= 0) {
        std::cout << "acc = " << acc << '\n';
        std::cout << "Enter a number: ";

        std::getline(std::cin, input);

        // Convert the input string to an integer
        std::istringstream iss(input);
        int n;
        if (!(iss >> n)) {
            std::cout << "Error reading integer\n";
            continue;
        }

        if (n < 0) {
            std::cout << "You can't enter a negative number!\n";
        } else {
            acc += n;
        }

        // Check if any remaining characters are present in the input
        if (iss.peek() != EOF) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Warning: Input too long\n";
        }
    }

    std::cout << "You win! acc = " << acc << '\n';
}
#endif

void FlipToNegative() {
    std::cout << std::unitbuf; // Enable automatic flushing for output

    int acc = 0;
    int n;

    std::cout << "Hello welcome to this program\n";
    while (acc >= 0) {
        std::cout << "acc = " << acc << '\n';
        std::cout << "Enter a number: ";

        if (!(std::cin >> n)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error reading integer\n";
        } else {
            if (n < 0) {
                std::cout << "You can't enter a negative number!\n";
            } else {
                acc += n;
            }
        }
    }

    std::cout << "You win! acc = " << acc << '\n';
  
  
    //Flag will come here
    
}

void getCurrentDate()
{
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;

    std::cout << "Today's date is " << day << "/" << month << "/" << year << "." << std::endl;

    //Flag will come here
}



void calculator()
{
    double num1, num2;
    char op;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    double result;

    switch (op)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
            {
                result = num1 / num2;
            }
            else
            {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return;
            }
            break;
        default:
            std::cout << "Invalid operator." << std::endl;
            return;
    }

    std::cout << "The result is: " << result << std::endl;

    //Flag will come here
}

void chatWithUser()
{
    std::string username;
    std::cout << "Enter your name: ";
    std::getline(std::cin, username);

    greetUser(username);

    std::string userResponse;

    while (true)
    {
        std::cout << "What do you want to know? (date, Q&A, day, calculator, FTN or bye to exit): ";
        std::getline(std::cin, userResponse);

        if (userResponse == "bye")
        {
            break;
        }
        else if (userResponse == "date")
        {
            getCurrentDate();
        }
        else if (userResponse == "Q&A")
        {
            BasicQA();
        }
        else if (userResponse == "day")
        {
            getCurrentDay();
        }
        else if (userResponse == "calculator")
        {
            calculator();
        }
        else if (userResponse == "FTN")
        {
            FlipToNegative();
        }
        else
        {
            std::cout << "I'm sorry, I don't understand." << std::endl;
        }

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main()
{
    chatWithUser();

    return 0;
}
