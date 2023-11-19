#include "list.h"
template <typename T>
Node<T>::Node()
    : next(nullptr)
{ }

template <typename T>
Node<T>::Node(T data)
    : next(nullptr), data(data)
{ }
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
list<T>::~list()
{
    while (head != nullptr) {
        Node<T>* temp = head;            
        head = head->next;
        delete temp;
    }
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
            tempNode->next = nullptr;
        }
    }
    delete tempNode;
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

template <typename T, typename V>
void list<T,V>::traverseList(void (*action)(const V&)) const
{
    Node<T>* tempNode = this->head
    while (tempNode != nullptr) 
    {
        action(tempNode->data);
        tempNode = tempNode->next;
    }
}