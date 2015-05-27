//
//  tree.cpp
//  DataStruct
//
//  Created by 박민석 on 2015. 5. 26..
//  Copyright (c) 2015년 박민석. All rights reserved.
//

#include <iostream>
using namespace std;

class NODE{
private:
    NODE* left;
    NODE* right;
    int   data;
    
public:
    NODE():left(NULL), right(NULL), data(0)
    { }
    
    NODE(int _i):left(NULL),right(NULL),data(_i)
    { }
    
    ~NODE()
    {
        delete left;
        delete right;
        right = left = NULL;

        cout << "DELETED!" << endl;
    }
    
    
    
    NODE* GetLeft() { return left; }
    NODE* GetRight(){ return right; }
    int GetData() { return data; }
    
    void SetLeft(NODE* _i)
    {
        left = _i;
    }
    
    void SetRight(NODE* _i)
    {
        right = _i;
    }
    
    void SetData(int _i)
    {
        data = _i;
    }
};



class TREE{
private:
    NODE* HEAD;
    NODE* CTL;
    int   index;
    
public:
    TREE():HEAD(new NODE), index(1), CTL(HEAD)
    { }
    
    TREE(int _i):HEAD(new NODE(_i)), index(1), CTL(HEAD)
    { }
    ~TREE()
    {
        delete HEAD;
        HEAD = NULL;
        cout << "DELETED" << endl;
    }
    
    NODE* GetHEAD() { return HEAD; }
    int   GetIndex(){ return index;}
    NODE* GetCTL()  { return CTL; }
    
    void SHOW(NODE *showCtl);
};
enum {LEFT = 0 , RIGHT = 1};

void Add(int _i, NODE* CTL)
{
    while(1)
    {
        if( _i > CTL->GetData())
        {
            if(CTL->GetRight() == NULL)
            {
                 CTL->SetRight(new NODE(_i));
                break;
            }
            else
            {
                CTL = CTL -> GetRight();
            }
          // right
        }
        else
        {
            if(CTL->GetLeft() == NULL)
            {
                CTL->SetLeft(new NODE(_i));
                break;
            }
            else
            {
                CTL = CTL -> GetLeft();
            }
        }
    }
    
}

enum {ADD=0, SHOW, EXIT};

int main(void)
{
    int data;
    cout << "Type First Data :";
    cin >> data;
    
    TREE *NEW = new TREE(data);
    NODE* CTL = NEW->GetCTL();
    
    int _select;
    
    while(1)
    {
        cin >> _select;
        
        
        switch (_select) {
            case ADD:
                cout << "ADD" << endl;
                int    _input;
                cin >> _input;
                
                Add(_input, CTL);
                
                break;
                
            case SHOW:
                cout << "SHOW" << endl;
                NEW->SHOW(NEW->GetHEAD());
                break;
                
            case EXIT:
                delete NEW;
                exit(1);
            default:
                break;
        }
        
    }
    
}
void TREE :: SHOW(NODE *showCtl)
{
    if( showCtl->GetLeft() != NULL) SHOW(showCtl->GetLeft());
    
    cout << showCtl->GetData() << " ";
    
    if( showCtl->GetRight() != NULL) SHOW(showCtl->GetRight());
    
}