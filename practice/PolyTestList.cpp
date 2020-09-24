#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//�����е�һ����� 
typedef struct Node{
	float coef;
	int expn;
}ElemType;
//�Ƚ�a,b��ָ��ֵ 
int cmp(ElemType a,ElemType b){
	if(a.expn>b.expn)
	return 1;
	if(a.expn==b.expn)
	return 0;
	if(a.expn<b.expn)
	return -1; 
}
//����������ʽ�ĺͣ����������poly1�� ������ʽ��ϵ���ɵ͵��� 
void AddPolyn(list<ElemType> &poly1,list<ElemType> &poly2)
{
	list<ElemType>::iterator h1 = poly1.begin();
	list<ElemType>::iterator h2 = poly2.begin();
	while(h1!=poly1.end()&&h2!=poly2.end())
	{
		switch(cmp(*h1,*h2)){
			//h2��ָ�����󣬽�h2ָ��Ĳ��뵽h1���棬ͬʱ��h1ָ��h2 (h1��ָ����С)
			case -1:
				h1++;
				break; 
			//ָ����ͬ�ϲ�,ͬʱָ����һ�� 
			case 0:
				(*h1).coef = (*h1).coef+(*h2).coef;
				h1++;
				h2++;
				break;
			//h1��ָ�����󣬽�h2ָ��Ľ����뵽h1ָ���ǰ�� ,ͬʱh2ָ����һ����� 
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
//�˳��Ľ���ҵ�poly1��ȥ 
void MulPolyn(list<ElemType> &poly1,list<ElemType> &poly2){
	list<ElemType>::iterator h2 = poly2.begin();
	list<ElemType> polyT;
	//����һ�� polyT = poly1,ͬʱ���poly1; 
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
	//�������ʽ1,������һ����׼���� ,���գ���һ���Ƕ���ʽ�ĸ���......�׿�����ô�� ,���������е㸴���� 
	int incoef=0;
	int inexpn = 0;
	char c;//��ʱ���� 
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
	//�������ʽ2��������һ����׼����
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
	//������� 
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
	//������� 
	for(list<ElemType>::reverse_iterator i=poly.rbegin();i!=poly.rend();i++){
		cout<<(*i).coef<<" "<<(*i).expn<<" ";
	}
	
}

