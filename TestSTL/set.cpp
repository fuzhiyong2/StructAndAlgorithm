#include<bits/stdc++.h>
using namespace std;
void testSet(){
	set<int> test;
	//test insert
	test.insert(5);
	test.insert(5);
	test.insert(3);
	test.insert(6);
	//test count count ţƤ;
	cout<<"count "<<test.count(2)<<endl;
	cout<<"size "<<test.size()<<endl;
	//test max_size
	cout<<"max_size"<<test.max_size()<<endl;
	
	//test find
	cout<<" find " << (test.find(3)==test.end())<<endl;
	cout<<"end "<<*test.end()<<endl;
	//test equal_range
	int i = 3;
	cout<<"equal_range "<<*(test.equal_range(i).first)<<endl;
	cout<<"equal_range " << *(test.equal_range(i).second)<<endl;	
	//test begin and end
	for(set<int>::iterator i = test.begin();i!=test.end();i++)
	{
		cout<<*i<<endl;
	}
	//int * a = int[100]
}
int main(){
	testSet();
	int a[100];
	a[0]=1;
	cout<<a[0];
}
