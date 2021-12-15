
#include "Find_result.h"
#include <iostream>
int main()
{
	string expression;
	cout << "vvedite virashenie" << "\n";
    cin >> expression;
	//cout << expression << "\n";
    string s = expression;
   
   
    cout << "expression in Prefix" << "\n";
    cout << infixToPrefix(s) << std::endl;
  

    cout << "result:" << "\n";
   cout << Conversion_to_stack_for_result((infixToPrefix_for_the_account(s))) << "\n";
    
    
	system("pause");
	return 0;

}





















































































/* int s = infix.size();

   int i = 0;
   int degree = 0;

   //string newstring;
   double* newstring = new double[s];


   cout << s ;
    for (int index = 0; index < s; index++)
    {
        degree = 0;
        i++;
        while ((isalpha(infix[index])) || (isdigit(infix[index]))) {

            newstring[i] = infix[index] * 10 ^ (degree);
            degree++;
            index++;
        }

    }

    for (int index = 0; index < s; index++)
    {
        cout << newstring[index] << "_";
    }*/