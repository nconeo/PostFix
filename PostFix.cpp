#include <iostream>
#include <stack>
#include <string>

int stackGetAndPop(std::stack<int> *toPop);

// TO-DO take a polish notation expression like 3 4 + 11 * and return the result
// Is it possible to improve the space complexity using only one variable instead of a stack?
int main (int argc, char* argv[]) {

    std::string input;

    std::cout << "Please enter an PostFix expression to evaluate" << std::endl;

    // Used getline to get spaces
    std::getline(std::cin, input);

    std::stack<int> myStack;

    //TO-DO: Check that input contains only digits and symbols such as +,-,*,/
    // Previous is used to find the previous char.
    // TO-DO: Check if input.length > 0;
    char previous = input[0];

    // Used to temporarily store each number, needed for numbers with multiple digits.
    std::string currentNumber;
    int result = 0;

    for (char i : input) {

        switch (i)
        {
            // Pop the stack then add two numbers together.
            case '+':
                // Popping until there are no more values in the stack.
                while (!myStack.empty()) {

                    result += stackGetAndPop(&myStack);
                }

                myStack.push(result);
    
                // Reset result so that we can continue to store the values of operations.
                result = 0;

                break;

            case '-':

                // For subtraction, we first need to set the top as negative.
                result -= stackGetAndPop(&myStack);
                // Popping until 
                while (!myStack.empty()) {
                    // Add to the bottom of the stack, since the top is (-).
                    result += stackGetAndPop(&myStack);
                }
                myStack.push(result);
                
                // Reset result so that we can continue to store the values of operations.
                result = 0;
                break;

            case '*':
                break;

            case '/':
                break;

            // We reached the space between characters.
            case ' ':
                if (!currentNumber.empty()) {
                    // Current Number should only contain numbers. Convert string to int.
                    myStack.push(stoi(currentNumber));
                
                    // Reset currentNumber.
                    currentNumber.clear();
                }
                
                break;
            
            // for numbers. Should check if they are numbers. Also concat for two values.
            default:
                // If previous value was a number, then we should consider that we have a multidigit number
                // EX: 77
                if (isdigit(i)) {
                    currentNumber += i;
                }
            
                break;
        }
        // After performing all operations. Then make the current char i, the previous.
        previous = i;
    }

    std::cout << "The result for " << input << " is: " << myStack.top() << std::endl;
}

int stackGetAndPop(std::stack<int> *toPop) {

    int value = toPop->top();
    toPop->pop();

    return value;
}

