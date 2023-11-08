template <typename T>
class Node
{
    public:
        T data;
        Node* next;
    public:
        Node();
        Node(T);
        ~Node();    
};