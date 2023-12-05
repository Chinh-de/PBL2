#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
        T data;
        Node* next;
    public:
        Node();
        Node(T);
        Node(const Node&);
        Node& operator=(const Node&);
        ~Node();    
};
template <typename T>
class list
{
    private:
        Node<T> *head;
    public:
        list();
        list(const list&);
        list& operator=(const list&);
        ~list();
        Node<T>* getHead() const;
        void add(const T&);
        void addAtEnd(const T&);
        void remove(const T&);
        void display();
        Node<T>* find(const T& findData);
        Node<T>* findMiddle(Node<T>*);
        Node<T>* mergeSort(Node<T>*, bool = true);
        Node<T>* merge(Node<T>*, Node<T>*, bool);
};