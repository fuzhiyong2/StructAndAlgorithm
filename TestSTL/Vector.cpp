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
	//测试 得到前后两个元素
	cout<<"front "<<test.front()<<endl;
	cout<<"back "<<test.back()<<endl; 
	cout<<"at "<<test.at(2)<<endl;
	
	//测试empty和size 
	cout<<"size "<<test.size()<<endl;
	cout<<"empty "<<test.empty()<<endl;
	
	//测试end,begin方法 
	cout<<"begin "<<*test.begin()++<<endl;
	cout<<"end "<<*test.end()<<endl;
	//测试capacity 方法 
	cout<<"capacity "<<test.capacity()<<endl; 
	cout<<"max_size "<<test.max_size()<<endl; 
	
	//测试reverse 方法
	cout<< "reserve"<<endl;
	test.reserve(9);
	cout<<"capacity "<<test.capacity()<<endl; 
	cout<<"max_size "<<test.max_size()<<endl; 
	
	//测试clear 方法
	test.clear();
	show(test); 
	cout<<"capacity "<<test.capacity()<<endl; 
	//测试swap方法 
	test.swap(test1);
	show(test);
	cout<<"capacity "<<test.capacity()<<endl; 
	
	//测试resize函数
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
