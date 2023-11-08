#include "Node.h"
template <typename T>
Node<T>::Node()
    : next(nullptr))
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