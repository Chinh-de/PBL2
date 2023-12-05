#include "list.h"
#pragma once
template <typename T>
Node<T>::Node()
    : next(nullptr)
{ }

template <typename T>
Node<T>::Node(T data)
    : next(nullptr), data(data)
{ }
template <typename T>
Node<T>::Node(const Node<T>& other)
    : data(other.data), next(nullptr)
{ }

template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& other) {
    if (this != &other) {
        this->data = other.data;
    }
    return *this;
}
template <typename T>
Node<T>::~Node()
{
    this->next = nullptr;
}

template <typename T>
list<T>::list()
{
    this->head = nullptr;
}

template <typename T>
list<T>::list(const list<T>& other)
    : head(nullptr) {
    Node<T>* otherNode = other.head;
    while (otherNode != nullptr) {
        this->addAtEnd(otherNode->data);
        otherNode = otherNode->next;
    }
}

template <typename T>
list<T>& list<T>::operator=(const list<T>& other) {
    if (this != &other) {
        while (this->head != nullptr) {
            Node<T>* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        Node<T>* otherNode = other.head;
        while (otherNode != nullptr) {
            addAtEnd(otherNode->data);
            otherNode = otherNode->next;
        }
    }
    return *this;
}

template <typename T>
list<T>::~list()
{
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
template <typename T>
Node<T>* list<T>::getHead() const
{
    return this->head;
}

template <typename T>
void list<T>::add(const T& addData)
{
    Node<T>* newNode = new Node<T>(addData);
    //neu danh sach trong tro head den newNode
    if(this->head == nullptr) this->head = newNode;
    ///neu khong, chen newNode vao dau danh sach
    else
    {
        newNode->next = this->head;
        this->head = newNode; 
    } 
}

template <typename T>
void list<T>::addAtEnd(const T& addData)
{
    Node<T>* newNode = new Node<T>(addData);
    // Neu rong them vao dau
    if (this->head == nullptr) {
        this->head = newNode;
    } 
    else {
        // Duyet den cuoi
        Node<T>* tempNode = this->head;
        while (tempNode->next != nullptr) {
            tempNode = tempNode->next;
        }
        // Them vao cuoi
        tempNode->next = newNode;
    }
}

template <typename T>
void list<T>::remove(const T& removeData)
{
    Node<T>* tempNode = this->head;
    Node<T>* prev = nullptr;
    //tim phan tu can xoa
    while(tempNode != nullptr && tempNode->data != removeData)
    {
        prev = tempNode;
        tempNode = tempNode->next;
    }
    //xoa phan tu tim duoc
    if(tempNode == this->head) this->head = (this->head)->next;
    else
    {
        if(tempNode != nullptr)
        {
            prev->next = tempNode->next;
            //tempNode->next = nullptr;
            delete tempNode;
        }
    }
}
template <typename T>
void list<T>::display()
{
    Node<T>* tempNode = this->head;
    //duyet qua mang
    while(tempNode != nullptr)
    {
        cout << tempNode->data << endl;
        tempNode = tempNode->next;
    }
}

template <typename T>
Node<T>* list<T>::find(const T& FindData) {
    Node<T>* tempNode = this->head;

    while (tempNode != nullptr) {
        if (tempNode->data == FindData) {
            //neu tim thay tra ve Node<T>
            return tempNode;
        }
        tempNode = tempNode->next;
    }
    // tra ve nullptr neu khong tim thay
    return nullptr;
}

template <typename T>
Node<T>* list<T>::findMiddle(Node<T>* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node<T>* slow = head;
    Node<T>* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
Node<T>* list<T>::mergeSort(Node<T>* head, bool ascending) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node<T>* middle = findMiddle(head);
    Node<T>* nextToMiddle = middle->next;
    middle->next = nullptr;

    head = mergeSort(head, ascending);
    nextToMiddle = mergeSort(nextToMiddle, ascending);

    return merge(head, nextToMiddle, ascending);
}

template <typename T>
Node<T>* list<T>::merge(Node<T>* left, Node<T>* right, bool type) {
    //type true tang, false
    Node<T>* result = nullptr;

    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    if (type ? (left->data < right->data) : (left->data > right->data)) {
        result = left;
        result->next = merge(left->next, right, type);
    } else {
        result = right;
        result->next = merge(left, right->next, type);
    }

    return result;
}