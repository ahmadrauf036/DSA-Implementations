#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool corresponding_paranthesis(char open,char closed)
{
	return ((open == '(' && closed == ')') || (open == '{' && closed == '}') || (open == '[' && closed == ']'));
}
bool balanced_paranthesis(string c)
{
	stack<char> st;
	for (int i = 0; i < c.length(); i++)
	{
		if (c[i] == '(' || c[i] == '[' || c[i] == '{') {
			st.push(c[i]);
			
		}
		else if(c[i]==')'|| c[i] == ']'|| c[i] == '}')
		{
			if (st.empty())
				return false;
			if (corresponding_paranthesis(st.top(),c[i]))
				st.pop();
			else if (c[i] == '}' || c[i] == ')' || c[i] == ']')
			{
				return false;
			}
		}
	}
	if (st.empty())
		return true;
	else
		return false;
}
int main()
{
	string input;
	getline(cin, input);
	cout << balanced_paranthesis(input) << endl;
	return 0;
}