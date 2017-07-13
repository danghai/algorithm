#include "stack.h"

using namespace std;

int main()
{

    stack stack1, stack2, result;
    cout << "! TESTING reverse method" << endl;
    stack1.push(2); stack1.push(5); stack1.push(10); stack1.push(15);
    cout << "STACK1 : " ;stack1.display_all();
    stack2.reverse(stack1);
    cout << "STACK2 : " ;stack2.display_all();
    cout << "------------------------------------------------------"<< endl;
    cout << "! TESTING stutter method" << endl;
    cout << "STACK1 : " ;stack2.display_all();
    stack1.stutter(stack2);
    cout << "Check Stack 1 is backup: ";stack2.display_all();
    cout << "STACK1 : " ;stack1.display_all();
    cout << "------------------------------------------------------"<< endl;
    stack1.reset();
    cout << "! TESTING collapse method" << endl;
    cout << "Situation 1: Even number of elements " << endl;
    cout << "STACK1 : " ;stack2.display_all();
    result.collapse(stack2);
    cout<< "Stack after collapse: "; result.display_all(); result.reset(); // reset result
    cout << "Situation 2: Odd number of elements " << endl;
    stack1.push(2); stack1.push(5); stack1.push(10); stack1.push(15); stack1.push(3);
    cout << "STACK1 : " ;stack1.display_all();
    result.collapse(stack1);
    cout<< "Stack after collapse: "; result.display_all(); result.reset(); // reset result
    cout << "------------------------------------------------------"<< endl;
    cout << "! TESTING equal method" << endl;
    stack1.reset(); stack2.reset(); stack check;
    cout << "CASE1: 2 stack empty" << endl;
    if(check.equal(stack1,stack2))
      cout << "--> PASS: 2 stack are empty" << endl;
    cout << "CASE2: Stack1 is not empty, but Stack2 is empty" << endl;
    stack1.push(2); stack1.push(5); stack1.push(10); stack1.push(15); stack1.push(3);
    if(!check.equal(stack1,stack2))
      cout << "--> PASS TEST" << endl;
    cout << "CASE3: Test 2 stack equal" << endl;
    stack1.reset();stack1.push(2); stack1.push(5); stack1.push(10); stack1.push(15); stack1.push(3);
    stack2.push(2); stack2.push(5); stack2.push(10); stack2.push(15); stack2.push(3);
    if(check.equal(stack1,stack2))
      cout << "--> PASS: 2 stack are equal" << endl;
    cout << "--> SUCCESS 2 stack are always back up " << endl;
    cout << "STACK1 : " ;stack1.display_all();
    cout << "STACK2 : " ;stack2.display_all();
    cout << "CASE4: Stack2 is longer stack1" << endl;
    stack2.push(20);
    if(!check.equal(stack1,stack2))
      cout << "--> PASS: 2 stack are not equal" << endl;
    cout << "--> SUCCESS 2 stack are always back up " << endl;
    cout << "STACK1 : " ;stack1.display_all();
    cout << "STACK2 : " ;stack2.display_all();
    cout << "CASE5: Stack1 is longer stack2" << endl;
    stack1.push(12); stack1.push(13);
    if(!check.equal(stack1,stack2))
      cout << "--> PASS: 2 stack are not equal" << endl;
    cout << "--> SUCCESS 2 stack are always back up " << endl;
    cout << "STACK1 : " ;stack1.display_all();
    cout << "STACK2 : " ;stack2.display_all();
    cout << "------------------------------------------------------------------------------";
    cout <<"TESTING findMin method" << endl;
    stack1.reset();stack1.push(2); stack1.push(5); stack1.push(10); stack1.push(15); stack1.push(3);
    stack1.display_all();
    cout << "MIN value of stack: " << stack1.findMin(); cout <<endl;
    stack1.display_all();
    stack1.reset();stack1.push(2); stack1.push(5); stack1.push(10); stack1.push(-1);stack1.push(15); stack1.push(3);
    stack1.display_all();
    cout << "MIN value of stack: " << stack1.findMin(); cout <<endl;
    stack1.display_all();
    stack1.reset();stack1.push(-1); stack1.push(5); stack1.push(10); stack1.push(-1);stack1.push(15); stack1.push(3); stack1.push(-1);
    stack1.display_all();
    cout << "MIN value of stack: " << stack1.findMin(); cout <<endl;
    stack1.display_all();
    cout << "---------------------------------------------------------------------------------";
    cout <<"TESTING mirror method" << endl;
    stack1.reset();stack1.push(2); stack1.push(5); stack1.push(10); stack1.push(15); stack1.push(3);
    stack1.display_all();
    stack1.mirror();
    cout << "Test stack 1 after mirror: ";stack1.display_all();
    return 0;
}
