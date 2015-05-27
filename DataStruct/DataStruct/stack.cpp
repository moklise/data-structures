//
//  main.cpp
//  DataStruct
//
//  Created by 박민석 on 2015. 5. 24..
//  Copyright (c) 2015년 박민석. All rights reserved.
//
// 스택은 한쪽끝에서 데이터를 넣거나 뺄 수 있는 선형 구조이다.
//S.top() 스택의 가장 윗 데이터를 넘겨준다.만약에 비었다면 이 연산은 정의불가 상태다.
//S.pop() 스택의 가장 윗 데이터의 값을 넘겨주고 해당 데이터를 삭제한다. 스택이 비었다면 연산 정의불가 상태.
//S.push(): 스택의 가장 윗 데이터로 top이 가리키는 자리 위에(top = top + 1) 메모리를 생성, x데이터를 넣는다.
//S.empty(): 스택이 비었다면 참을 주고,그렇지 않다면 거짓이 된다.


#include <iostream>
using namespace std;

class ELEMENT
{
private:
    int data;
    
public:
    int GetData()         { return data; };
    void SetData(int _i)  { data = _i; };
};

class STACK
{
private:
    ELEMENT* body;
    int size;
    int index;
    
public:
    STACK() : size(10), index(0)
    {
        body = new ELEMENT[size+1];
        for( int i = 0 ; i < size ; i++ )
            body[i].SetData(0);
    }
    
    STACK(int _size) : size(_size), index(0)
    {
        body = new ELEMENT[size];
        for( int i = 0 ; i < size ; i++ )
            body[i].SetData(0);
    }
    ~STACK()
    {
        
    }

    int    GetSize() { return size; };
    ELEMENT* GetBody() { return body; };
    int    GetIndex(){ return index; };
    
    int  Top();
    int  Pop();
    void Push(int _i);
    bool Empty();
    
};

enum { TOP=0, POP, PUSH, EMPTY, EXIT, STAT = 9, NOW };

int main(void)
{
    int input;

    cout << "Init" << endl;

    STACK* NewOne= new STACK;

    cout << "done." << endl;
    
    while(true)
    {

        cout << "> ";
        cin >> input;
        
        cout << "> ";
        
        switch (input) {
            case TOP:
                cout << NewOne->Top() << endl;
                break;
                
            case POP:
                cout << NewOne->Pop() << endl;
                break;
                
            case PUSH:
                
                cout << "Type new data" << endl;;
                int _i;
                
                cout << "> ";
                cin  >> _i;
                
                NewOne->Push(_i);
                break;
                
            case EMPTY:
                cout << NewOne->Empty() << endl;
                break;
                
            case EXIT:
                delete [] NewOne;
                exit(1);
                
                break;
                
        }
    }
    
}

int    STACK :: Top()
{
    if(!Empty())
    {
        cout << "not" << endl;
        return 999;
    }
    
    return ((this->body)+index)->GetData();
}

int    STACK :: Pop()
{
    if(!Empty())
    {
        cout << "Illegal Data!" << endl;
        return 999;
    }
    
    int pop = (body+(index))->GetData();
    
    (body+index)->SetData(0);
    
    index--;
    
    return pop;
}

void   STACK :: Push(int _i)
{
    if( index == size )
    {
        cout << "더 넣을 공간이 없습니다. " << endl;
    }
    else
    {
        index++;
        (GetBody()+index)->SetData(_i);
        cout << "done." << endl;
    }
    
    
}
bool   STACK :: Empty()
{
//    if(GetBody()->GetData() == 0 ) return 1;
    if(index == 0 )      return true;
    else                 return false;
}

//index가 0부터 시작하는게 있고 1부터 시작하는게 있음 정형화 해줄 컨버전스가 필요
//시작이 0 이 아닌 1부터 시작했음. 최대치에 근접했을때 포인터 오류가 날 가능성 존재.
//하지만 Index의 의미는 얼마나 들어가있나를 보는 것이므로 -1로 초기화후 0부터 시작할수도있고
// 0으로 초기화후 1로부터 시작할수 있다.

//STACK 이란 한 쪽에서 데이터의 입 출력이 이루어지는 선형 구조이다.