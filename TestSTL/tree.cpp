#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<cctype>
#include <string>
using namespace std;

typedef string ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

//����������룬��������� 
int CreatBinTree(BinTree &root,string input){
	
	//����������Ű����ļӼ�
	int size = input.size();
	int j = 0;
	//��+��-��*��/,()
	int flagN = 1;
	while(j<size)
	{
		if(!isdigit(input[j]))
		{
			flagN = 0;
			break;
		}
		j++;
	}
	if(flagN ==1 ){
		root = (BinTree)malloc(sizeof(TNode)) ;
		root->Data = input;
		root->Left = NULL;
		root->Right = NULL;
		return 1;
	}
	//�����Ϊ��������ȥ����
	if(input[0]=='('&&input[size-1]==')')
	{
		CreatBinTree(root,input.substr(1,size-2));
		return 1;
	} 
	//�ҵõ�+��- 
	j = 0;
	int flagK = 0;
	while(j<size){
		if( (input[j] == '+' || input[j]=='-')&& flagK==0){
			//�ֳ����� 
			root = (BinTree)malloc(sizeof(TNode)) ;
			root->Data = input[j];
			root->Left = NULL;
			root->Right = NULL;
			CreatBinTree(root->Left,input.substr(0,j));
			CreatBinTree(root->Right,input.substr(j+1,size-j-1));
			return 1;
		}
		if(input[j]=='(')
		{
			flagK = 1;
		}
		if(input[j]==')')
		{
			flagK = 0;
		}
		j++;
	}
	//�����Ű���*��/ 
	j = 0;
	flagK = 0;
	while(j<size){
		if( (input[j] == '*' || input[j]=='/')&& flagK==0){
			//�ֳ����� 
			root = (BinTree)malloc(sizeof(TNode)) ;
			root->Data = input[j];
			root->Left = NULL;
			root->Right = NULL;
			CreatBinTree(root->Left,input.substr(0,j));
			CreatBinTree(root->Right,input.substr(j+1,size-j-1));
			return 1;
		}
		if(input[j]=='(')
		{
			flagK = 1;
		}
		if(input[j]==')')
		{
			flagK = 0;
		}
		j++;
	}
	return 0;
};
//������� 
void Inorder(BinTree root){
	if(root!=NULL){
		Inorder(root->Left);
		cout<<root->Data<<" ";
		Inorder(root->Right);
	}
}
//����ֵ
int cal(BinTree root){
	if(root ==NULL)
	{
		return 0;
	}
	if(root->Left==NULL){
		//Ҫת��Ϊ���� 
		return stoi(root->Data);
	}
	if (root->Data == "+")
			return cal(root->Left)+cal(root->Right);
	if (root->Data == "-")
			return cal(root->Left)-cal(root->Right);
	if (root->Data == "*")
	    	return cal(root->Left)*cal(root->Right);
	if (root->Data == "/")
	    	return cal(root->Left)/cal(root->Right);
	
	return 0;
} 

typedef struct queue{
    BinTree numQ[100];
    int front;
    int rear;
} qu;
    
qu Q;
 
void initilize() { //��ʼ������
    Q.front = 0;
    Q.rear = 0;
}
 
void Push(BinTree root) { //���
    Q.numQ[++Q.rear] = root;
}
 
BinTree Pop() { //����
    return Q.numQ[++Q.front];
}
 
int empty() { //�ж϶����Ƿ�Ϊ��
    return Q.rear == Q.front;
}



void InorderTraversal( BinTree BT ){
    if(BT !=NULL){
        InorderTraversal(BT->Left);
        cout<<BT->Data;
        InorderTraversal(BT->Right);
    }
};
void PreorderTraversal( BinTree BT ){
    if(BT != NULL){
        cout<<BT->Data;
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
};
void PostorderTraversal( BinTree BT ){
     if(BT != NULL){
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        cout<<BT->Data;
    }
};
void LevelorderTraversal( BinTree BT ){
    initilize();
    BinTree temp;
    if(BT != NULL){
        Push(BT);
        while (!empty()) {
        //pop������
        temp = Pop();
        cout<<temp->Data; //������׽��
        if (temp->Left!=NULL)     //��Pop���Ľ������ӽ��������
            {
            	Push(temp->Left);
            	//cout<<temp->Left->Data;
			}
        if (temp->Right!=NULL)    //��Pop���Ľ������ӽ��������
        	{
        		Push(temp->Right);
        		//cout<<temp->Right->Data; 
			}

        };
    }
};


int main(){
	string input;
	cin>>input;
//	cout<<input[2]<<","<<input.size()<<endl;
//	cout<<input.substr(1,1)<<endl;
//	cout<<input.substr(1,2);
	BinTree root;
	cout<<CreatBinTree(root,input)<<endl; 
	cout<<cal(root)<<endl;
	//Inorder(root);
	//cout<<stoi(input)<<endl; 
	InorderTraversal(root);
	cout<<endl;
	PreorderTraversal(root);
	cout<<endl;
	PostorderTraversal(root);
	cout<<endl;
	LevelorderTraversal(root);
	cout<<endl;
}


