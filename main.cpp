#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdbool.h>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node* prev;
};



class max_heap
{
private:
    int first=1;
    node* rroot;
    node* act;
    node* last;
         queue<node *> q1;
        stack<node *> stack1;
    void traverse11(node *ptr , int x=0)
{
    if(ptr!=NULL)
    {

        cout<<ptr->data<<"\t"<<x<<endl;
        traverse11(ptr->left  , 1);
        traverse11(ptr->right , 2);
    }
}


void check(node *root)
{
    cout<<"in check"<<endl;
    cout<<"\t"<<root->data<<endl;
    if(root->prev==NULL)
    {
        cout<<"NULL trigger"<<endl;
        return;
    }else
    if(root->prev->data<root->data)
    {
//        int x=root->prev->prev->data;
        int y=root->prev->data;
        int z=root->data;
        cout<<"y:  "<<y<<"z:  "<<z<<endl;
        node *temp1=root->prev->prev;
        node *temp2=root->prev;
        node *temp3=root;
        node *temp2_left=temp2->left;
        node *temp2_right=temp2->right;
        temp2->data=z;
        temp3->data=y;
        check(temp2);
    }
}


 void top_check(node *root)
    {
        cout<<"in top_check"<<endl;
        if(root==NULL )
        {
            cout<<"in top_ckeck_NULL trigger"<<endl;
            return;
        }
        node *highest;
        if(root->right!=NULL){
        int x=max(root->left->data , root->right->data);
         if(x==root->left->data)
        {
            highest=root->left;
        }else
        {
            highest=root->right;
        }
        }else
        {
            if(root->left!=NULL)
            {
                highest=root->left;
            }else
            {
                return;
            }
        }
        cout<<"highest:"<<highest->data<<endl;
        if(root->data>=highest->data)
        {
            return ;

        }else
        {
            int temp1=root->data;
            root->data=highest->data;
            highest->data=temp1;
             top_check(highest);
        }

    }


    public:
    node * root()
    {
        return rroot;
    }

    max_heap( )
    {
        queue<node *> q2;
        q1=q2;
        stack<node *> s1;
        stack1=s1;
    }

    void push(int x)
    {
        node *new1=new node;
        new1->data=x;
        new1->left=NULL;
        new1->right=NULL;
        new1->prev=NULL;
        if(first==1)
        {
            rroot=new1;
            q1.push(new1);
            q1.push(new1);
            act=rroot;
            last=rroot;
             stack1.push(new1);
            first++;
        }else
        {
            node *temp1=q1.front();
            act=temp1;
            stack1.push(new1);
            q1.pop();
            if(temp1->left==NULL)
            {
                temp1->left=new1;
                new1->prev=temp1;
                q1.push(new1);
                q1.push(new1);
                check(new1);


            }else if(temp1->right==NULL)
            {
                temp1->right=new1;
                new1->prev=temp1;
                q1.push(new1);
                q1.push(new1);
                check(new1);
            }
        }
    }

    int peek()
    {
        return rroot->data;
    }

    void pop()
    {

        node *last=stack1.top();
        act=last->prev;
         if(stack1.size()==1)
        {
            cout<<"rooooooooooooooooot"<<last->data<<endl;
            rroot->data=0;
            rroot->left=NULL;
            rroot->right=NULL;
            rroot->prev=NULL;
            stack1.pop();
            return;
        }
        cout<<"last_node added"<<last->data<<endl;
        cout<<"act"<<act->data<<endl;
        stack1.pop();
        rroot->data=last->data;
        if(act->left->data==last->data)
        {
            act->left=NULL;
        }else
        {
            cout<<"pop else"<<endl;
            act->right=NULL;
        }
        top_check(rroot);
        delete last;
    }

    vector<int> heap_sort()
    {
        vector<int> v1;
        while(stack1.size()!=0)
        {
            v1.push_back(peek());
            pop();
        }
        return v1;
    }

void traverse()
{
    traverse11(rroot);
}




};


int main()
{
        max_heap mh1;
       int t;
       int t1=0;
       cin>>t;
       int data;
       while(t--)
       {
           cout<<"data";
           cin>>data;
           mh1.push(data);
       }
        mh1.traverse();
        cout<<"pop================"<<endl;
        while(t1--){
                cout<<"pop================"<<endl;
                        cout<<"peek============================================"<<mh1.peek()<<endl;

        mh1.pop();
        mh1.traverse();
        cout<<"pop================end"<<endl;
        }
                mh1.traverse();

        cout<<"root:"<<mh1.peek()<<endl;
        cout<<"heapsort--------------------------------"<<endl;
        vector<int> ans=mh1.heap_sort();
        for(auto& it1:ans)
        {
            cout<<it1<<"\t";
        }
        cout<<endl;
}
