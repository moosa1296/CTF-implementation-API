#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <algorithm>

// #define BUFFER_OVERFLOW true
// #define INTEGER_OVERFLOW true

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




// #ifdef BUFFER_OVERFLOW
    void BasicQA()
    {
    #if BUFFER_OVERFLOW == 1 
     std::cout << BUFFER_SIZE << std::endl;
     std::cout << "HELLO BUFFER!!!" << std::endl;   
    // std::cout << "NO BUFFER!!!" << std::endl;
  
    std::cout << "BO Chatbot: Do you love football? (yes/no)" << std::endl;

    std::string response;
    std::cout << "You: ";
    std::getline(std::cin, response);

    if (response == "yes")
    {
        std::cout << "Chatbot: Who is the current World Cup champion?" << std::endl;
        std::string answer;
        char buffer[10]; // Buffer with limited size

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
    #else
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
    
    #endif
    //Flag will come here
}

    void FlipToNegative() {
    #if INTEGER_OVERFLOW == 1
    {
         std::cout << BUFFER_SIZE << std::endl;
    std::cout << std::unitbuf; // Enable automatic flushing for output

    int acc = 0;
    int n;

    std::cout << "Hello welcome to this Integer overflow program\n";
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
    }
   
    #else
    {
        std::cout << std::unitbuf; // Enable automatic flushing for output

    int acc = 0;
    int n;

    std::cout << "Hello welcome to this non vuln program\n";
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
    }
  #endif

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
            #if BUFFER_OVERFLOW == 1
                BasicQA(); 
            #else
                std::cout << "port error";
            #endif   
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
             #if INTEGER_OVERFLOW == 1
                FlipToNegative(); 
            #else
                std::cout << "port error";
            #endif 
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

    
// #ifdef BUFFER_OVERFLOW
//     #if BUFFER_OVERFLOW == 1
//     std::cout << "HELLO BUFFER!!!" << std::endl;
//     #else
//     std::cout << BUFFER_OVERFLOW;
//     #endif
// #endif

#ifdef INTEGER_OVERFLOW
    #if INTEGER_OVERFLOW == 1
    std::cout << "HELLO INTEGER!!!" << std::endl;
    #else
    std::cout << INTEGER_OVERFLOW;
    #endif
#endif

// #ifdef DUMMY_OVERFLOW
//     #if DUMMY_OVERFLOW == 1
//     std::cout << "HELLO DUMMY!!!" << std::endl;
//     #else
//     std::cout << DUMMY_OVERFLOW;
//     #endif
// #endif

// #ifdef COMMAND_OVERFLOW
//     #if COMMAND_OVERFLOW == 1
//     std::cout << "HELLO COMMAND!!!" << std::endl;
//     #endif
// #endif

// #if defined(BUFFER_OVERFLOW)
//     #if (BUFFER_OVERFLOW == 1)
//         std::cout << BUFFER_OVERFLOW;
//     #else 
//         std::cout << "HELLO BUFFFFER!!!\n\n\n\n";
//     #endif
// #endif

// #if defined(INTEGER_OVERFLOW)
//     #if (INTEGER_OVERFLOW == 1)
//         std::cout << INTEGER_OVERFLOW;
//     #else
//         std::cout << "HELLO INTEGER!!!\n\n\n\n";
//     #endif
// #endif

    // std::cout<< BUFFER_OVERFLOW << std::endl;
    // #endif


    chatWithUser();

    return 0;
}
