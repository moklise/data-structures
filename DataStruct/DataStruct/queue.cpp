//
//  queue.cpp
//  DataStruct
//
//  Created by 박민석 on 2015. 5. 25..
//  Copyright (c) 2015년 박민석. All rights reserved.
//

#include <iostream>
#include "msDev.h"
using namespace std;

class NODE
{
private:
    int   data;
    NODE* next;
    
public:
    int     GetData() { return data; }
    NODE*   GetNext() { return next; }
    void    SetData(int _i);
    void    SetNext(NODE* _next);
    
    NODE()
    {
        next = NULL;
        data = 0;
    }
    
};

class QUEUE
{
private:
    NODE* head;
    NODE* tail;
    int   index;
    
public:
    QUEUE() : index(0)
    {
        head = new NODE;
        tail = head;
    }
    
    NODE*   GetHead() { return head; }
    int     GetIndex() { return index; }
    
    void Put(int _i);
    int  Get();

};

enum { PUT = 0, GET};

int main(void)
{
    QUEUE* one = new QUEUE;
    int _select;

    while(true)
    {
        cout << "> ";
        cin >> _select;
        switch (_select) {
            case PUT:
                int _i;
                cout << "Type i : ";
                cin >> _i;
                one->Put(_i);
                break;
                
            case GET:
                cout << one->Get() << endl;
                
            default:
                break;
        }
    }

}

void QUEUE :: Put(int _i)
{
    if(index != 0)
    {
        tail->SetNext(new NODE);
        tail = tail->GetNext();
    }
    
    (tail)->SetData(_i);
    index++;
    msDone();
}
int  QUEUE :: Get()
{
    if(index == 0)
    {
        cout << "not" << endl;
        return 999;
    }
    else
    {
        NODE* temp = head;
        int data = (head)->GetData();
        
        head = head->GetNext();
        delete temp;
        index--;
        return data;
    }
}

void  NODE :: SetData(int _i)
{
    data = _i;
}

void  NODE :: SetNext(NODE* _next)
{
    next = _next;
}