#include "pch.h"
#include "CppUnitTest.h"
#include "../Курсовая работа/Stack.h"
#include "../Курсовая работа/Find_result.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


using namespace std;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(STACK)
		{
			Stack<int> stack;
			stack.Stack_push(22);
			stack.Stack_pop();

			bool check = 1;
			try
			{
				stack.Stack_pop();
			}
			catch (std::runtime_error)
			{
				check = 0;
			}
			Assert::IsFalse(check);


			//we'll fill up the stack
			for (int i = 1; i < 11; i++) {
				stack.Stack_push(i);
			}
			Assert::IsFalse(stack.Stack_isEmpty());

			//let's clear the stack and check for emptiness
			for (int i = 10; i >= 1; i--) {
				Assert::AreEqual(i, stack.peek());
				stack.Stack_pop();
			}
			Assert::IsTrue(stack.Stack_isEmpty());

		}
		

		TEST_METHOD(expression_to_prefix)
		{
				string expression;
				string prefix;
				expression = "(5+2)*8-(45-89)*sin(45)";
				prefix=infixToPrefix(expression);
				//-*+5 2 8* -45 89 sin45
				Assert::AreEqual(prefix[0],'-');
				Assert::AreEqual(prefix[1], '*');
				Assert::AreEqual(prefix[2], '+');
				Assert::AreEqual(prefix[3], '5');
				Assert::AreEqual(prefix[4], ' ');
				Assert::AreEqual(prefix[5], '2');
				Assert::AreEqual(prefix[6], ' ');
				Assert::AreEqual(prefix[7], '8');//
				Assert::AreEqual(prefix[8], '*');
				Assert::AreEqual(prefix[9], ' ');
				Assert::AreEqual(prefix[10], '-');
				Assert::AreEqual(prefix[11], '4');
				Assert::AreEqual(prefix[12], '5');
				Assert::AreEqual(prefix[13], ' ');
				Assert::AreEqual(prefix[14], '8');
				Assert::AreEqual(prefix[15], '9');
				Assert::AreEqual(prefix[16], ' ');
				Assert::AreEqual(prefix[17], 's');
				Assert::AreEqual(prefix[18], 'i');
				Assert::AreEqual(prefix[19], 'n');
				Assert::AreEqual(prefix[20], '4');
				Assert::AreEqual(prefix[21], '5');
				

				string expression1;
				string prefix1;
				expression1 = "log(5)+cos(7)-ctg(45)*e";
				prefix1 = infixToPrefix(expression1);
				//+log5- cos7* ctg45 e 
				Assert::AreEqual(prefix1[0], '+');
				Assert::AreEqual(prefix1[1], 'l');
				Assert::AreEqual(prefix1[2], 'o');
				Assert::AreEqual(prefix1[3], 'g');
				Assert::AreEqual(prefix1[4], '5');
				Assert::AreEqual(prefix1[5], '-');
				Assert::AreEqual(prefix1[6], ' ');
				Assert::AreEqual(prefix1[7], 'c');//
				Assert::AreEqual(prefix1[8], 'o');
				Assert::AreEqual(prefix1[9], 's');
				Assert::AreEqual(prefix1[10], '7');
				Assert::AreEqual(prefix1[11], '*');
				Assert::AreEqual(prefix1[12], ' ');
				Assert::AreEqual(prefix1[13], 'c');
				Assert::AreEqual(prefix1[14], 't');
				Assert::AreEqual(prefix1[15], 'g');
				Assert::AreEqual(prefix1[16], '4');
				Assert::AreEqual(prefix1[17], '5');
				Assert::AreEqual(prefix1[18], ' ');
				Assert::AreEqual(prefix1[19], 'e');
				




		
		}



		
		TEST_METHOD(Mistake)
		{
			
			
			string expression;
		
			expression = "//(5+2)-(45-89)-sin(45)";
			double n;
			//n=Conversion_to_stack_for_result((infixToPrefix_for_the_account(prefix)));

			bool check = 1;
			try
			{
				
				check_errors(expression);
			}
			catch (std::runtime_error)
			{
				check = 0;
			}
			Assert::IsFalse(check);

			string expression1;
			expression1 = "(5+2";
			double n1;
			//n=Conversion_to_stack_for_result((infixToPrefix_for_the_account(prefix)));

			bool check1 = 1;
			try
			{

				check_errors(expression1);
			}
			catch (std::runtime_error)
			{
				check1 = 0;
			}
			Assert::IsFalse(check1);



			string expression2;
			expression2 = "(5+2*/-+";
			
			bool check2 = 1;
			try
			{

				check_errors(expression1);
			}
			catch (std::runtime_error)
			{
				check2 = 0;
			}
			Assert::IsFalse(check1);


			string expression3;
			expression3 = "5555";

			bool check3 = 1;
			try
			{

				check_errors(expression1);
			}
			catch (std::runtime_error)
			{
				check3 = 0;
			}
			Assert::IsFalse(check3);

			
			
		}


		TEST_METHOD(Result)
		{
			string expression;
			expression = "55+45";
			double n;
			string m;
			m = infixToPrefix_for_the_account(expression);
			n = Conversion_to_stack_for_result(m);
			double p = 100;
			Assert::AreEqual(n, p);



			string expression1;
			expression1 = "(55+45)*(58-50)";
			double n1;
			string m1;
			m1 = infixToPrefix_for_the_account(expression1);
			n1 = Conversion_to_stack_for_result(m1);
			double p1 = 800;
			Assert::AreEqual(n1, p1);


			string expression2;
			expression2 = "(78-45)+(78+45-5)+(35-5)";
			double n2;
			string m2;
			m2 = infixToPrefix_for_the_account(expression2);
			n2 = Conversion_to_stack_for_result(m2);
			double p2 = 181;
			Assert::AreEqual(n2, p2);









		}


	};




	


	
}
