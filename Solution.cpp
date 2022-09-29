#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) 
{
    // odd number of brackets, return false
    if (s.length() % 2 != 0) {
        return false;
    }
    // stack for open parentheses
    stack<char> parentheses_stack;

    // find length of s
    const int length_of_s = s.length();

    // iterate through s
    for (int i = 0; i < length_of_s; i++)
    {
        // add all opening brackets to the stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            parentheses_stack.push(s[i]);
        }

        // for all closing brackets: make sure stack is not empty & check stack for appropriate opening bracket
        else if (s[i] == ')' && !parentheses_stack.empty() && parentheses_stack.top() == '(') {
            parentheses_stack.pop();
        }
        else if (s[i] == '}' && !parentheses_stack.empty() && parentheses_stack.top() == '{') {
            parentheses_stack.pop();
        }
        else if (s[i] == ']' && !parentheses_stack.empty() && parentheses_stack.top() == '[') {
            parentheses_stack.pop();
        }
        // this else statement is needed for examples such as
        // ([}}])
        else {
            parentheses_stack.push(s[i]);
        }
    }

    return parentheses_stack.empty();

}
int main()
{
    string example_one = "()";
    string example_two = "()[]{}";
    string example_three = "(]";
    string example_four = "([}}])";
    cout << example_one << " : " << isValid(example_one) << endl;
    cout << example_two << " : " << isValid(example_two) << endl;
    cout << example_three << " : " << isValid(example_three) << endl;
    cout << example_four << " : " << isValid(example_four) << endl;

	return 0;
}