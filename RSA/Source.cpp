#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main()
{
	//string a = "321";
	//string b = "57";

	string a = "972";
	string b = "538";

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	//char a[3] = { 3,2,1 };

	//char a[3] = { 1,2,3 }; //  321
	//char carry[3] = { 0,0,0 };
	string carry ;


	int i_length = b.length(); //(sizeof(b) / sizeof(*b)); //2;
	int j_length = a.length(); //(sizeof(a) / sizeof(*a)); //3;

	for (int i = 0; i < j_length; i++)
	{
		carry.push_back(0);
	}

	//char b[2] = { 5,7};
	//char b[2] = { 7,5};  //57


	vector<vector<int>> mylist;


	//list<int>::iterator it;

	for (int i= 0; i < i_length;i++) //b
	{
		vector<int> mylist_inner;
		for (int k = 0; k < i; k++) //  pad with zero according to digit place
		{
			mylist_inner.push_back(0);
		}

		for (int j = 0; j < j_length; j++)//a
		{
			int temp = (b[i] - '0') * (a[j] - '0') +carry[j];
			if (temp >= 10 && j!= j_length-1)
			{
				string s = to_string(temp);
				mylist_inner.push_back(s[1] - '0');
				carry[j+1] = s[0] - '0';
			}
			else //normal add  or last one
			{
				string s = to_string(temp);

				if (temp >= 10) // to add two terms
				{
					mylist_inner.push_back(s[1] - '0');
				}
					mylist_inner.push_back(s[0] - '0');

			}
		}
		for (int j = 0; j < j_length; j++)//make carry equal zero
		{
			carry[j] = 0;
		}

		mylist.push_back(mylist_inner);
	}
	

	int max_size=0;
	int i = 0;

	//make all vectors same size 
	//first get max size
	for each (vector<int> a in mylist)
	{
		if (i == 0)
		{
			max_size = a.size();
		}
		if (a.size() > max_size)
		{
			max_size= a.size();
		}
		i++;
	}

	//pad with zeros
	for (int i = 0; i < mylist.size(); i++) 
	{
		if ( mylist[i].size() < max_size )
		{
			for (int k = mylist[i].size()  ; k < max_size ; k++)
			{
				mylist[i].push_back(0);
			}
		}
	}

	string final_carry = "";
	string final_sol = "";

	for (int i = 0; i < max_size; i++)
	{
		final_carry.push_back(0);
	}

	for (int i = 0; i < max_size; i++) 
	{
		int temp=0;
		for (int n = 0; n < mylist.size(); n++)
		{
			temp += mylist[n][i];
		}
		temp += final_carry[i];

		 //mylist[0][i] + mylist[1][i] + mylist[2][i] + final_carry[i];

		string s = to_string(temp);

		if (temp >= 10) // to add two terms
		{
			final_sol.push_back(s[1] - '0');
			final_carry[i + 1] = s[0] - '0';
		}
		else //only one term
		{
			final_sol.push_back(s[0] - '0');
		}


		//final_sol.push_back(mylist[0][i] + mylist[1][i]);
	}
	int jjj;

	//string final_sol = "";
	//int first_num = mylist[0].size();
	//int sec_num	  =	mylist[1].size();

	//int max = 0;
	//if (first_num > sec_num) max = first_num;
	//else  max = sec_num;

	//string final_carry;
	//for (int i = 0; i < max; i++)
	//{
	//	final_carry.push_back(0);
	//}
	//
	//for (int i = 0; i < first_num; i++) //get comman area
	//{
	//	int temp = mylist[0][i] + mylist[1][i] + final_carry[i];
	//	string s = to_string(temp);

	//	if (temp >= 10) // to add two terms
	//	{
	//		final_sol.push_back(s[1] - '0');
	//		final_carry[i + 1] = s[0] - '0';
	//	}
	//	else //only one term
	//	{
	//		final_sol.push_back(s[0] - '0');
	//	}


	//	//final_sol.push_back(mylist[0][i] + mylist[1][i]);
	//}

	//if (sec_num > first_num)
	//{
	//	for (int i = first_num; i < sec_num; i++) //get comman area
	//	{
	//		final_sol.push_back(mylist[1][i] + final_carry[i]);
	//	}
	//}
	return 0;
}