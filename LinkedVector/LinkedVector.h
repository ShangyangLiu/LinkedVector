#ifndef LINKEDVECTOR_H
#define LINKEDVECTOR_H

#include <string>
#include <iostream>
#include <sstream>
#include "error.h"
using namespace std;


template<typename ValueType>
class LinkedVector{
public:
    LinkedVector();
    ~LinkedVector();

    LinkedVector(const LinkedVector& vector2);
    LinkedVector<ValueType>& operator=(const LinkedVector& vector2);

    void add(const ValueType &value);
    void insert(int index,const ValueType &value);
    void remove(int index);
    LinkedVector<ValueType> subList(int start,int length) const;
    ValueType& operator[](int index);
    bool operator==(LinkedVector &queue2);
    int size() const;
    bool isEmpty() const;
    void clear();
    void show();

private:
    struct node {
        ValueType data;
        node* next;
    };
    node* head;
    node* tail;
};

template<typename ValueType>
LinkedVector<ValueType>::LinkedVector(){
    head=tail=nullptr;
}

template<typename ValueType>
LinkedVector<ValueType>::~LinkedVector(){
    while (head!=nullptr){
        node* temp=head;
        head=head->next;
        delete temp;
    }
}

template<typename ValueType>
LinkedVector<ValueType>::LinkedVector(const LinkedVector& vector2){
    node* curTail=nullptr;
    node* cur=vector2.head;
    head=nullptr;
    while (cur!=nullptr){
        node* newNode=new node{cur->data,nullptr};
        if (curTail==nullptr){
            head=curTail=newNode;
        }
        else{
            curTail->next=newNode;
            curTail=newNode;
        }
        cur=cur->next;
    }
    tail=curTail;
}

template<typename ValueType>
LinkedVector<ValueType>& LinkedVector<ValueType>::operator=(const LinkedVector& vector2){
    clear();
    node* curTail=nullptr;
    node* cur=vector2.head;
    head=nullptr;
    while (cur!=nullptr){
        node* newNode=new node{cur->data,nullptr};
        if (curTail==nullptr){
            head=curTail=newNode;
        }
        else{
            curTail->next=newNode;
            curTail=newNode;
        }
        cur=cur->next;
    }
    tail=curTail;
}

template<typename ValueType>
void LinkedVector<ValueType>::add(const ValueType &value){
    node* newNode=new node{value,nullptr};
    if (tail!=nullptr){
        tail->next=newNode;
        tail=newNode;
    }
    else{
        head=tail=newNode;
    }
}

template<typename ValueType>
void LinkedVector<ValueType>::insert(int index,const ValueType &value){
    node* newNode=new node{value,nullptr};
    node* pre=nullptr;
    node* cur=head;
    if (index==0){
        newNode->next=head;
        head=newNode;
        if (cur==nullptr){
            tail=newNode;
        }
        return;
    }
    while (index>0 && cur!=nullptr){
        index--;
        pre=cur;
        cur=cur->next;
    }
    if (index==0){
        pre->next=newNode;
        newNode->next=cur;
        if (cur==nullptr){
            tail=newNode;
        }
    }
    else{
        error("insert: index out of range");
    }
}

template<typename ValueType>
void LinkedVector<ValueType>::remove(int index){
    if (head==nullptr){
        error("remove: an empty vector");
    }
    else{
        node *pre=nullptr;
        node* cur=head;
        while (index>0 && cur!=nullptr){
            index--;
            pre=cur;
            cur=cur->next;
        }
        if (cur==nullptr){
            error("remove: index out of range");
        }
        if (cur->next==nullptr){
            tail=pre;
        }
        if (pre==nullptr){
            head=cur->next;
        }
        else{
            pre->next=cur->next;
        }
        delete cur;
    }
}

template<typename ValueType>
LinkedVector<ValueType> LinkedVector<ValueType>::subList(int start,int length) const{
    LinkedVector<ValueType> result;
    if (head==nullptr){
        if (start!=0 || length!=0){
            error("subList: an empty vector");
        }
    }
    else{
        node* cur=head;
        for (int i=0;i<start;i++){
            if (cur!=nullptr){
                cur=cur->next;
            }
        }
        if (cur==nullptr){
            error("subList: index out of range");
        }
        else if (length==-1){
            while (cur!=nullptr){
                result.add(cur->data);
                cur=cur->next;
            }
        }
        else{
            for (int i=0;i<length;i++){
                if (cur!=nullptr){
                    result.add(cur->data);
                    cur=cur->next;
                }
                else{
                    error("subList: index out of range");
                }
            }
        }
    }
    return result;
}

template<typename ValueType>
ValueType& LinkedVector<ValueType>::operator[](int index){
    if (head==nullptr){
        error("[]: an empty vector");
    }
    else{
        node* cur=head;
        while (index>0 && cur!=nullptr){
            cur=cur->next;
            index--;
        }
        if (cur==nullptr){
            error("[]: index out of range");
        }
        else{
            return cur->data;
        }
    }
}

template<typename ValueType>
bool LinkedVector<ValueType>::operator==(LinkedVector &vector2){
    node* cur=head;
    node* cur2=vector2.head;
    while (cur!=nullptr && cur2!=nullptr){
        if (cur->data != cur2->data){
            return false;
        }
        cur=cur->next;
        cur2=cur2->next;
    }
    if (cur==nullptr && cur2==nullptr){
        return true;
    }
    return false;
}

template<typename ValueType>
int LinkedVector<ValueType>::size() const{
    int result;
    node* temp=head;
    while (temp!=nullptr){
        temp=temp->next;
        result++;
    }
    return result;
}

template<typename ValueType>
bool LinkedVector<ValueType>::isEmpty() const{
    return head==nullptr;
}

template<typename ValueType>
void LinkedVector<ValueType>::clear(){
    while (head!=nullptr){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    tail=nullptr;
}

template<typename ValueType>
void LinkedVector<ValueType>::show(){
    if (!isEmpty()){
        node* temp=head;
        while (temp!=nullptr){
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

#endif // LINKEDVECTOR_H
