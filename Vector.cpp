#include<bits/stdc++.h>
using namespace std;

void show(vector<int> test){
	for (vector<int>::iterator it=test.begin();it !=test.end();++it)
	{
		cout<<*it<<" ,";
	}
	cout <<endl;
}
void testVector(){
	vector<int> test;
	
	vector<int> test1; 
	test.insert(test.begin(),1);
	test.insert(test.begin(),2);
	test.insert(test.begin(),3);
	test.insert(test.begin(),4); 
	
	show(test);
	//test.erase(test.end());
	//���� �õ�ǰ������Ԫ��
	cout<<"front "<<test.front()<<endl;
	cout<<"back "<<test.back()<<endl; 
	cout<<"at "<<test.at(2)<<endl;
	
	//����empty��size 
	cout<<"size "<<test.size()<<endl;
	cout<<"empty "<<test.empty()<<endl;
	
	//����end,begin���� 
	cout<<"begin "<<*test.begin()++<<endl;
	cout<<"end "<<*test.end()<<endl;
	//����capacity ���� 
	cout<<"capacity "<<test.capacity()<<endl; 
	cout<<"max_size "<<test.max_size()<<endl; 
	
	//����reverse ����
	cout<< "reserve"<<endl;
	test.reserve(9);
	cout<<"capacity "<<test.capacity()<<endl; 
	cout<<"max_size "<<test.max_size()<<endl; 
	
	//����clear ����
	test.clear();
	show(test); 
	cout<<"capacity "<<test.capacity()<<endl; 
	//����swap���� 
	test.swap(test1);
	show(test);
	cout<<"capacity "<<test.capacity()<<endl; 
	
	//����resize����
	test.resize(4,1);
	show(test);
	
	//assign
	test.assign(5,2);
	show(test);
	
}
int main(){
	testVector();
	return 0;
} 
