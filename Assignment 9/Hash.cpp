#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int key;
    int value;
    //constructor with parameters
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};
class HashTable
{
private:
    Node **arr;
    int maxSize;
    int currentSize;
public:
    //empty constructor
    HashTable()
    {
        maxSize = 100;
        //initialize the max size of table as 100
        this->arr = new Node*[maxSize];
        //dynamically allocate the hash table array
        currentSize = 0;
        for (int i=0; i<maxSize; i++)
        {
            this->arr[i] = NULL;
            //to initialize activities in the array
        }
    }
    //to return hashcode for the element
    int hashCode(int key)
    {
        cout<<"Hash Function "<<key<<"%"<<maxSize<<" = "<<(key%maxSize)<<endl;
        return (key%maxSize);
        //h(k) = k mod maxSize
    }
    void insertNode(int key, int value)
    {
        Node *n = new Node(key,value);
        int h = hashCode(key);
        bool check = isEmpty(h);
        while(check != 1)
        {
            cout << "The previous place has taken!!" << endl;
            h++;
            h %= maxSize;
            //h'(k)= (h(k)+1) mod maxSize is selected as we are probing linearly
            //and we want to maintain insertion within the time complexity of
            //O(1) as much as possible.
            //This function is also suggested in the lecture slides.
            cout << "Checking availability at " << h << endl;
            check = isEmpty(h);
        }
        if(check==1)
        {
            //if the space is found immediately, the time complexity will be
            //O(1) [best case].
            this->currentSize++;
            this->arr[h] = n;
            cout << "Inserted " << value << " at index "<< h << endl;
        }
        //delete dynamically allocated new node
        delete n;
        if(this->currentSize==this->maxSize)
        {
            cout << "The table is already full!!" << endl;
        }
    }
//to get the index of the key
    int get(int key)
    {
        //search with same hash functions used for insertion
        int h = hashCode(key);
        int i = 0;
        if(this->arr[h]->key == key)
        {
            //if found, return the value
            return (this->arr[h]->value);
        }
        else
        {
            //to prevent infinite loop
            while(i<= this->maxSize && this->arr[h]->key != key)
            {
                i++;
                //if not, increment the counter,and find with h' hash function
                h++;
                h = hashCode(key);
            }
            return 0;
        }
    }
//check whether the index is empty or not
    bool isEmpty(int i)
    {
        if (this->arr[i] == NULL)
            return 1;
        else
            return 0;
    }
//destructor
    ~HashTable()
    {
        delete []this->arr;
    }
};
int main()
{
    //test functions
    HashTable h;
    h.insertNode(30, 50);
    h.insertNode(50, 9);
    h.insertNode(50, 100);
    int search = h.get(50);
    cout << "Result for searching: " << search << endl;
    return 0;
}
