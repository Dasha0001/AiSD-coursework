#pragma once
#ifndef  FIND_RESULT_H
#include <iostream>
#include <string>
#include "Stack.h"
#include <stdlib.h>
#include <math.h>
#include<stdexcept>




using namespace std;



bool isOperator(char c)
{

    return (!isalpha(c) && !isdigit(c) && c != ')' && c != '.');

}

int check_errors(string infix) {

    int staples = 0;
    int two_Operator = 0;
    //cout << infix.size() - 1;

    for (int index = 0; index < infix.size() - 1; index++)
    {
        if (index < infix.size() - 2) {

            if ((isOperator(infix[index])) && (isOperator(infix[index + 1])))
            {

                two_Operator++;

            }
        }

        if (infix[index] == '(')
        {
            staples++;
        }

        if (infix[index] == ')')
        {
            staples--;
        }
    }

    if (staples != 0) {
        throw runtime_error("pay attention to the brackets , they are incorrectly placed");
    }
    else { return 1; }

    if (two_Operator != 0) {
        throw runtime_error("pay attention to the operators , they are incorrectly placed");
    }
    else { return 1; }

    if (isOperator(infix[infix.size()])) {
        throw runtime_error("pay attention   to the last element, they are incorrectly placed");
    }
    else { return 1; }

    if ((infix[0]=='+')|| (infix[0] == '/') || (infix[0] == '*') || (infix[0] == '.') | (infix[0] == '^') ) {
        throw runtime_error("pay attention   to the first element, they are incorrectly placed");
    }
    else { return 1; }



}

double Conversion_to_stack_for_result(string prefix) {
    
    Stack<double> expression_stack;
    Stack<char> expression_stack_sign;
    int length = prefix.size() - 1;
    int index = 0;
    int  quantity = 0;
    string sub1;
    string sub2;
    int flag = 0;
    double result = 0;
    char sign;
    char unary_sign;
    int tmp;
    int n = length / 2;
    long double* Result = new long double[n];


    while (index < length) {
        
        if (prefix[index] == ' ') {
            index++;
        }

        if ((isdigit(prefix[index])) || (prefix[index] == '.')) {
            tmp = index;
            quantity = 0;
            while ((isdigit(prefix[tmp])) || (prefix[tmp] == '.')) {
                tmp++;
                quantity++;

            }

            sub1 = prefix.substr(index, quantity);

            double newel1 = atof(sub1.c_str());
            //cout << newel1 << "expression_stack \n";
            expression_stack.Stack_push(newel1);
            index = index + quantity;
        }



        if (isOperator(prefix[index])) {

            if ((prefix[index] == '+') || (prefix[index] == '-') || (prefix[index] == '/') || (prefix[index] == '*') || (prefix[index] == '^')) {
                //sub1 = prefix.substr(index , 1);
                expression_stack_sign.Stack_push(prefix[index]);
               // cout << prefix[index] << ";expression_stack_sign \n";
                index++;
            }


        }

        if ((isalpha(prefix[index]))) {
            if ((prefix[index] == 's') && (prefix[index + 1] == 'i') && (prefix[index + 2] == 'n')) {
                flag = 1;
                index = index + 3;
                if ((isdigit(prefix[index])) || (prefix[index] == '.')) {
                    tmp = index;
                    quantity = 0;
                    while ((isdigit(prefix[tmp])) || (prefix[tmp] == '.')) {
                        tmp++;
                        quantity++;

                    }

                    sub1 = prefix.substr(index, quantity);

                    double newel1 = atof(sub1.c_str());
                    //cout << sin(newel1) << "expression_stack \n";
                    expression_stack.Stack_push(sin(newel1));
                    if ((index + quantity - 1) <= length) { index = index + quantity; }
                }
            }

            if ((prefix[index] == 'c') && (prefix[index + 1] == 'o') && (prefix[index + 2] == 's')) {
                flag = 1;
                index = index + 3;
                if ((isdigit(prefix[index])) || (prefix[index] == '.')) {
                    tmp = index;
                    quantity = 0;
                    while ((isdigit(prefix[tmp])) || (prefix[tmp] == '.')) {
                        tmp++;
                        quantity++;

                    }

                    sub1 = prefix.substr(index, quantity);

                    double newel1 = atof(sub1.c_str());
                    //cout << cos(newel1) << "expression_stack \n";
                    expression_stack.Stack_push(cos(newel1));
                    if ((index + quantity - 1) <= length) { index = index + quantity; }
                }
            }

            if ((prefix[index] == 'l') && (prefix[index + 1] == 'o') && (prefix[index + 2] == 'g')) {
                flag = 1;
                index = index + 3;
                if ((isdigit(prefix[index])) || (prefix[index] == '.')) {
                    tmp = index;
                    quantity = 0;
                    while ((isdigit(prefix[tmp])) || (prefix[tmp] == '.')) {
                        tmp++;
                        quantity++;

                    }

                    sub1 = prefix.substr(index, quantity);

                    double newel1 = atof(sub1.c_str());
                    if (newel1 == (-1)) {
                        throw runtime_error("pay attention   to the LOG element, they are incorrectly placed");
                    }
                    else {
                        //cout << log(newel1) << "expression_stack \n";
                        expression_stack.Stack_push(log10(newel1));
                        if ((index + quantity - 1) <= length) { index = index + quantity; }
                    }
                }
            }

            if ((prefix[index] == 'c') && (prefix[index + 1] == 't') && (prefix[index + 2] == 'g')) {
                flag = 1;
                index = index + 3;
                if ((isdigit(prefix[index])) || (prefix[index] == '.')) {
                    tmp = index;
                    quantity = 0;
                    while ((isdigit(prefix[tmp])) || (prefix[tmp] == '.')) {
                        tmp++;
                        quantity++;

                    }

                    sub1 = prefix.substr(index, quantity);

                    double newel1 = atof(sub1.c_str());
                    //cout << cos(newel1) / sin(newel1) << "expression_stack \n";
                    expression_stack.Stack_push(cos(newel1) / sin(newel1));
                    if ((index + quantity - 1) <= length) { index = index + quantity; }
                }
            }

            if ((prefix[index] == 't') && (prefix[index + 1] == 'g')) {
                flag = 1;
                index = index + 2;
                if ((isdigit(prefix[index])) || (prefix[index] == '.')) {
                    tmp = index;
                    quantity = 0;
                    while ((isdigit(prefix[tmp])) || (prefix[tmp] == '.')) {
                        tmp++;
                        quantity++;

                    }

                    sub1 = prefix.substr(index, quantity);

                    double newel1 = atof(sub1.c_str());
                    //cout << sin(newel1) / cos(newel1) << "expression_stack \n";
                    expression_stack.Stack_push(sin(newel1) / cos(newel1));
                    if ((index + quantity - 1) <= length) { index = index + quantity; }
                }
            }

            if ((prefix[index] == 'l') && (prefix[index + 1] == 'n')) {
                flag = 1;
                index = index + 2;
                if ((isdigit(prefix[index])) || (prefix[index] == '.')) {
                    tmp = index;
                    quantity = 0;
                    while ((isdigit(prefix[tmp])) || (prefix[tmp] == '.')) {
                        tmp++;
                        quantity++;

                    }

                    sub1 = prefix.substr(index, quantity);

                    double newel1 = atof(sub1.c_str());
                    //cout << log10(newel1) << "expression_stack \n";
                    expression_stack.Stack_push(log(newel1));
                    if ((index + quantity - 1) <= length) { index = index + quantity; }
                }
            }
            //sqrt
            if ((prefix[index] == 's') && (prefix[index + 1] == 'q') && (prefix[index + 2] == 'r') && (prefix[index + 3] == 't')) {
                flag = 1;
                index = index + 4;
                if ((isdigit(prefix[index])) || (prefix[index] == '.')) {
                    tmp = index;
                    quantity = 0;
                    while ((isdigit(prefix[tmp])) || (prefix[tmp] == '.')) {
                        tmp++;
                        quantity++;

                    }

                    sub1 = prefix.substr(index, quantity);

                    double newel1 = atof(sub1.c_str());
                    //cout << sqrt(newel1) << "expression_stack \n";
                    expression_stack.Stack_push(sqrt(newel1));
                    if ((index + quantity - 1) <= length) { index = index + quantity; }
                }
            }

            //asin
            if ((prefix[index] == 'a') && (prefix[index + 1] == 'b') && (prefix[index + 2] == 's') ) {
                flag = 1;
                index = index + 3;
                if ((isdigit(prefix[index])) || (prefix[index] == '.')) {
                    tmp = index;
                    quantity = 0;
                    while ((isdigit(prefix[tmp])) || (prefix[tmp] == '.')) {
                        tmp++;
                        quantity++;

                    }

                    sub1 = prefix.substr(index, quantity);

                    double newel1 = atof(sub1.c_str());
                    //cout << asin(newel1) << "expression_stack \n";
                    expression_stack.Stack_push(abs(newel1));
                    if ((index + quantity - 1) <= length) { index = index + quantity; }

                }
            }


            if ((prefix[index] == 'p') && (prefix[index + 1] == 'i')) {

                index = index + 2;




                double newel1 = 3.1415926;

                expression_stack.Stack_push(newel1);
                if ((index + quantity - 1) <= length) { index = index; }

            }
            if ((prefix[index] == 'e')) {

                index = index + 1;

                double newel1 = 2.7182818;

                expression_stack.Stack_push(newel1);
                if ((index + quantity - 1) <= length) { index = index; }

            }
        }




        //cout << index << "-index\n";



    }

    if (expression_stack_sign.Stack_isEmpty())  {
        if (flag == 0) {
            index = 0;
            tmp = index;
            quantity = 0;
            while ((isdigit(prefix[tmp])) || (prefix[tmp] == '.')) {
                tmp++;
                quantity++;

            }

            sub1 = prefix.substr(index, quantity);

            double newel1 = atof(sub1.c_str());
            //cout << newel1 << "Stack_isEmpty";
            return newel1;
        }
        if (flag == 1) {

            //cout <<"answer:" <<expression_stack.peek()<<"\n";
            return expression_stack.peek();
        }

    }
    else {
        double newel2, newel1;
        n = 0;
        while (!expression_stack_sign.Stack_isEmpty()) {
            //index=i;
            if (expression_stack.Stack_isEmpty()) {
                newel1 = Result[n];
                newel2 = Result[n - 1];
            }
            else {
                newel1 = expression_stack.peek();
                //cout << newel1 << "-newel1 expression_stack \n";
                expression_stack.Stack_pop();
                if (expression_stack.Stack_isEmpty()) {
                    newel2 = Result[n];
                }
                else {
                    newel2 = expression_stack.peek();
                    expression_stack.Stack_pop();
                }

                //cout << newel2 << "-newel2 expression_stack \n";

            }


            sign = expression_stack_sign.peek();
           // cout << sign << "sign  new \n";
            expression_stack_sign.Stack_pop();
            if (sign == '+') {
                if (newel2 == 0) {
                    result = newel1 + result;
                    //cout << result << "-result 0\n";
                    n++;
                }
                else {
                    result = newel1 + newel2;
                    //cout << result << "-result\n";
                    n++;
                }

            }

            if (sign == '-') {
                if (newel2 == 0) {
                    result = newel1 - result;
                    //cout << result << "-result 0\n";
                    n++;
                }
                else {
                    result = newel2 - newel1;
                    //cout << result << "-result \n";
                    n++;
                }

            }

            if (sign == '*') {

                if (newel2 == 0) {
                    result = result * newel1;
                    //cout << result << "-result 0\n";
                    n++;
                }
                else {
                    result = newel1 * newel2;
                    //cout << result << "-result \n";
                    n++;
                }

            }

            if (sign == '/') {

                if (newel2 == 0) {
                    if (result == 0) {
                        throw runtime_error("pay attention to the / , they are incorrectly placed");
                    }
                    else{
                        result = newel1 / result;

                        //cout << result << "-result 0\n";
                        n++;
                    }
                    
                }
                else {
                    if (newel1 == 0) {
                        throw runtime_error("pay attention to the / , they are incorrectly placed");
                    }
                    result = newel2 / newel1;
                    //cout << result << "-result \n";
                    n++;
                }

            }

            if (sign == '^') {

                if (newel2 == 0) {
                    if((newel1==0)&& (result == 0))
                    {
                        throw runtime_error("pay attention to the 0^0 , they are incorrectly placed");
                    
                    }
                    else{
                        result = pow(newel1, result);
                    }
                    
                    //cout << result << "-result 0\n";
                }
                else {
                    if ((newel2 == 0) && (newel1 == 0))
                    {
                        throw runtime_error("pay attention to the 0^0 , they are incorrectly placed");

                    }
                    else {
                        result = pow(newel2, newel1);
                        //cout << result << "-result \n";
                        n++;
                    }
                }

            }


            Result[n] = result;
           // cout << result << "-result \n";
            result = 0;;

            flag = 0;
            // break;

        }

        


    }
    //cout << "answer:" << Result[n] << "\n";
    return Result[n];

}

int getPriority(char C)

{

    if (C == '-' || C == '+'){ return 1; }

        
    else {
        if (C == '*' || C == '/') { return 2; }

        else {
            if (C == '^') { return 3; }
            else {



                return 0;
            }
        }
    }
}


string infixToPrefix(string infix)
{

   

    int l = infix.size();

    reverse(infix.begin(), infix.end());
    for (int i = 0; i < l; i++) {



        if (infix[i] == '(') {

            infix[i] = ')';

            i++;

        }

        else if (infix[i] == ')') {

            infix[i] = '(';

            i++;

        }

    }


    infix = '(' + infix + ')';

     l = infix.size();

    Stack<char> char_stack;

    string output;
    for (int i = 0; i < l; i++) {

        if (isalpha(infix[i]) || isdigit(infix[i]) || (infix[i] == '.')) {

            output += infix[i];

        }

        else if (infix[i] == '(') {

            char_stack.Stack_push('(');
        }

        else if (infix[i] == ')') {



            while (char_stack.peek() != '(') {

                output += char_stack.peek();

                char_stack.Stack_pop();

            }


            char_stack.Stack_pop();

        }




        else {



            if (isOperator(char_stack.peek())) {
                output += ' ';

                while (getPriority(infix[i])

                    <= getPriority(char_stack.peek())) {

                    output += char_stack.peek();

                    char_stack.Stack_pop();
                    ;
                }

                char_stack.Stack_push(infix[i]);

            }

        }

    }


    string prefix = output;

    reverse(prefix.begin(), prefix.end());


    return prefix;

}

string infixToPrefix_for_the_account(string infix)
{
    int size = infix.size();

   Stack<char> char_stack;
    string newinfix;
    string output;
    int i = 0;
    int tmp,index=0;
    bool flag=0;
    while ((i < size)) {


        if (infix[i] == '(') {
            
            i++;
           
            while (infix[i] != ')')  {

                if ((infix[i] == '(') && (flag == 0)) {
                    while (infix[i] != ')') {
                        output += infix[i];
                        //cout << infix[i];
                        i++;
                    }
                    output += infix[i];
                    break;
                }
                output += infix[i];
                //cout << infix[i];
                i++;

            }
          
                newinfix += to_string(Conversion_to_stack_for_result(infixToPrefix(output)));
                flag = 0; 
                 output.clear();
            

        }
        else{ newinfix+= infix[i];  }
       
        flag = 0;
        i++;
        
    }
    
    //cout << newinfix<<"newinfix";
    return newinfix;

}



#endif // FIND_RESULT_H