#pragma once
#include <iostream>
template<class DataType>
class Node{
public:
	Node() {}
    Node(DataType & val):val_(val),next_(nullptr),prev_(nullptr){}
    Node(DataType & val,Node * next,Node * prev):val_(val),next_(next),prev_(prev){}

public:
    DataType val_;
    Node<DataType> *next_;
    Node<DataType> *prev_;
};

template<class DataType>
class DoubleLinkList{
public:
    DoubleLinkList();
    ~DoubleLinkList();
    int GetLength() const;
    DataType GetValue(int index);
    Node<DataType>* Front();
    Node<DataType>* Back();
	Node<DataType>* GetHead();
    void HeadInsert(DataType val);
    void LastInsert(DataType val);
    bool Delete(int index);
    void PopBack();
    void PopFront();
    bool IsEmpty();
    void ForwardPrint();
    void ReversePrint();
    void ForwardChangeHead();
    void ReverseChangeHead();

private:
    Node<DataType>* GetNode(int index);
    bool IndexIsValid(int index);
    void Swap(DataType& val1,DataType& val2);
private:
    int len_;
    Node<DataType> *head_;
};

template<class DataType>
DoubleLinkList<DataType>::DoubleLinkList() :len_(0) {
	//������ͷ�ڵ�
	head_ = new Node<DataType>();
	head_->next_ = head_;
	head_->prev_ = head_;
}

template<class DataType>
DoubleLinkList<DataType>::~DoubleLinkList() {
    Node<DataType>* tmp;
    Node<DataType>* it = head_->next_;
    while (it != head_){
        tmp = it;
        it = it->next_;
        delete tmp;
    }
    delete head_;
    head_ = nullptr;
}

template<class DataType>
Node<DataType>* DoubleLinkList<DataType>::GetNode(int index){
    if(!IndexIsValid(index)) return nullptr;

    if(index<=len_/2){
        auto it = head_->next_;
        while(index){
            it = it->next_;
            index--;
        }
        return it;
    }
    else {
        auto it = head_->prev_;
        index = len_ - index -1;
        while(index){
            it = it->prev_;
            index--;
        }
        return it;
    }
}

template<class DataType>
int DoubleLinkList<DataType>::GetLength() const {
	return len_;
}

template<class DataType>
bool DoubleLinkList<DataType>::IsEmpty() {
	return len_ == 0;
}

template<class DataType>
void DoubleLinkList<DataType>::HeadInsert(DataType val) {
    auto node = new Node<DataType>(val,head_->next_,head_);
    head_->next_->prev_ = node;
    head_->next_ = node;
    len_++;
}

template<class DataType>
void DoubleLinkList<DataType>::LastInsert(DataType val) {
	auto node = new Node<DataType>(val,head_,head_->prev_);
    head_->prev_->next_ = node;
    head_->prev_ = node;
    len_++;
}

template<class DataType>
bool DoubleLinkList<DataType>::Delete(int index) {
    auto node = GetNode(index);
    if(node == nullptr) return false;
    node->next_->prev_ = node->prev_;
    node->prev_->next_ = node->next_;
    len_--;
    return true;
}

template<class DataType>
void DoubleLinkList<DataType>::ForwardPrint(){
    Node<DataType>* it = head_->next_;
    int len = len_;
    while(len){
        std::cout<<it->val_<<" ";
        it = it->next_;
        len--;
    }
    std::cout<<std::endl;
}

template<class DataType>
void DoubleLinkList<DataType>::ReversePrint(){
    Node<DataType>* it = head_->prev_;
    int len = len_;
    while(len){
        std::cout<<it->val_<<" ";
        it = it->prev_;
        len--;
    }
    std::cout<<std::endl;
}

template<class DataType>
void DoubleLinkList<DataType>::PopBack() {
    Delete(len_-1);
}

template<class DataType>
void DoubleLinkList<DataType>::PopFront() {
    Delete(0);
}

template<class DataType>
Node<DataType>* DoubleLinkList<DataType>::Front() {
    GetNode(0);
}

template<class DataType>
Node<DataType>* DoubleLinkList<DataType>::GetHead() {
	return head_;
}

template<class DataType>
Node<DataType>* DoubleLinkList<DataType>::Back() {
    GetNode(len_-1);
}

template<class DataType>
bool DoubleLinkList<DataType>::IndexIsValid(int index) {
    return index>=0&&index<len_;
}



template<class DataType>
DataType DoubleLinkList<DataType>::GetValue(int index){
    if(IndexIsValid(index)){
        return GetNode(index)->val_;
    }
	return {};
}

template<class DataType>
void DoubleLinkList<DataType>::Swap(DataType& val1,DataType& val2){
    auto tmp = val1;
    val1 = val2;
    val2 = val1;
}

template<class DataType>
void DoubleLinkList<DataType>::ForwardChangeHead(){
    Swap(head_->val_,head_->next_->val_);
    head_ = head_->next_;
}

template<class DataType>
void DoubleLinkList<DataType>::ReverseChangeHead(){
    Swap(head_->val_,head_->prev_->val_);
    head_ = head_->prev_;
}