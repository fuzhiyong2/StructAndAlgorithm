#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//�����е�һ����� 
typedef struct Node{
	float coef;
	int expn;
}ElemType;

int main(){
	list<ElemType> poly;
//	char input=' ';
//	cin.get(input);
	int b;
	int a;
	char c;
	cin >>a;
	while((c=getchar())!='\n')
	{
		if(c == '+')
		{
			cin>>b;
			cout<<a+b<<endl;
		}
		
	}
	cout<<"OK"<<endl;
}

