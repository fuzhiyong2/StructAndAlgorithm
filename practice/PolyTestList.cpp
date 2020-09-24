#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//链表中的一个结点 
typedef struct Node{
	float coef;
	int expn;
}ElemType;
//比较a,b的指数值 
int cmp(ElemType a,ElemType b){
	if(a.expn>b.expn)
	return 1;
	if(a.expn==b.expn)
	return 0;
	if(a.expn<b.expn)
	return -1; 
}
//求两个多项式的和，结果保存在poly1中 ，多项式的系数由低到高 
void AddPolyn(list<ElemType> &poly1,list<ElemType> &poly2)
{
	list<ElemType>::iterator h1 = poly1.begin();
	list<ElemType>::iterator h2 = poly2.begin();
	while(h1!=poly1.end()&&h2!=poly2.end())
	{
		switch(cmp(*h1,*h2)){
			//h2的指数更大，将h2指向的插入到h1后面，同时将h1指向h2 (h1的指数更小)
			case -1:
				h1++;
				break; 
			//指数相同合并,同时指向下一个 
			case 0:
				(*h1).coef = (*h1).coef+(*h2).coef;
				h1++;
				h2++;
				break;
			//h1的指数更大，将h2指向的结点插入到h1指向的前面 ,同时h2指向下一个结点 
			case 1:
				poly1.insert(h1,(*h2));
				h2++;
				break;
		}
		//cout<<"run"<<endl;
	}
	while(h2!=poly2.end()){
		poly1.insert(poly1.end(),(*h2));
		h2++;
	}
}
//乘出的结果家到poly1上去 
void MulPolyn(list<ElemType> &poly1,list<ElemType> &poly2){
	list<ElemType>::iterator h2 = poly2.begin();
	list<ElemType> polyT;
	//交换一下 polyT = poly1,同时清空poly1; 
	polyT.assign(poly1.begin(),poly1.end());
	poly1.clear();
	
	list<ElemType>::iterator h1 = polyT.begin();
	list<ElemType> polyTem;
	polyTem.assign(polyT.begin(),polyT.end()); 
	
	while(h2!=poly2.end())
	{
		while(h1!=polyT.end())
		{
			(*h1).expn = (*h1).expn+(*h2).expn;
			(*h1).coef =(*h1).coef*(*h2).coef;
			h1++;
		}
		AddPolyn(poly1,polyT);
		polyT.clear();
		polyT.assign(polyTem.begin(),polyTem.end());
		h1 = polyT.begin(); 
		h2++;
	}
} 
int main(){
	list<ElemType> poly;
	//构造多项式1,利用了一个标准输入 ,沃日，第一项是多项式的个数......白考虑那么多 ,数据输入有点复杂了 
	int incoef=0;
	int inexpn = 0;
	char c;//临时变量 
	cin>>incoef;
	c=getchar(); 
	cin>>incoef; //coef
	while((c=getchar())!='\n')
	{
		cin>>inexpn;//expn;
		ElemType point;
		point.coef = incoef;
		point.expn = inexpn;
		poly.insert(poly.begin(),point); 
		if((c=getchar())=='\n')
		{
			break;
		}
		else
		{
			cin>>incoef;
		}
		
	}
	//构造多项式2，利用了一个标准输入
	list<ElemType> poly1;
	cin>>incoef;
	c=getchar();
	cin>>incoef; //coef
	while((c=getchar())!='\n')
	{
		cin>>inexpn;//expn;
		ElemType point;
		point.coef = incoef;
		point.expn = inexpn;
		poly1.insert(poly1.begin(),point); 
		if((c=getchar())=='\n')
		{
			break;
		}
		else
		{
			cin>>incoef;
		}
		
	}
	//遍历输出 
//	for(list<ElemType>::iterator i=poly.begin();i!=poly.end();++i){
//		cout<<(*i).coef<<","<<(*i).expn<<" ";
//	}
	list<ElemType> poly3;
	poly3.assign(poly.begin(),poly.end());
	MulPolyn(poly3,poly1);
	for(list<ElemType>::reverse_iterator i=poly3.rbegin();i!=poly3.rend();i++){
		cout<<(*i).coef<<" "<<(*i).expn<<" ";
	}
	cout<<endl;
	AddPolyn(poly,poly1); 
	//遍历输出 
	for(list<ElemType>::reverse_iterator i=poly.rbegin();i!=poly.rend();i++){
		cout<<(*i).coef<<" "<<(*i).expn<<" ";
	}
	
}

