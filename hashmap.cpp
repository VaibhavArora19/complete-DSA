#include <bits/stdc++.h>
using namespace std;
template <typename V>
class mapnode
{
public:
    string key;
    V value;
    mapnode *next;

    mapnode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~mapnode()
    {
        delete next; //recursive destructor to delete complete linked list
    }
    //friend class mymap;
};
// this mymap class will create the array consisting of key value pair and where each index is the head of the linked list
template <typename V> //since the value we will pass is a template thats why we will also use template in this class
class mymap
{
private:
    mapnode<V> **buckets; // declaration of array having type mapnode
    int count;            // to count the no of entries in the array
    int numbuckets;       // to count the size of the array
    int getbucketindex(string key)
    {
        int hashcode = 0; //initial value of HC
        for(int i = key.size()-1; i>=0; i--)
        {
             int base = 1;
             int p = 37;
             hashcode += key[i] * base;
             base = base * p;
             // to avoid integer out of range problem
             hashcode = hashcode%numbuckets;
             base = base%numbuckets; 
        }
        return hashcode%numbuckets; // applied compression fucntion
    }
    void rehash()
    {
        mapnode<V> ** temp = buckets;
         buckets = new mapnode<V> *[2*numbuckets];
         for(int i =0; i<2*numbuckets; i++)
         {
             buckets[i] = NULL;
         }   
         int oldbucketsize = numbuckets;
         numbuckets *= 2;
         count =0;
         for(int i =0; i<oldbucketsize; i++)
         {
             mapnode<V> *head = temp[i];
             while(head != NULL)
             {
                 string key = head->key;
                 V value = head->value;
                 insert(key, value);
                 head = head->next;
             }
         }
         for(int i =0; i<oldbucketsize; i++)
         {
             delete temp[i];
         }
         delete []temp;
    }

public:
    mymap() // default constructor
    {
        count = 0;
        numbuckets = 5;                         //default size is 5
        buckets = new mapnode<V> *[numbuckets]; // array of size numbuckets
        for (int i = 0; i < numbuckets; i++)
        {
            buckets[i] = NULL; // replaced garbage values in array with NULL
        }
    }
        ~mymap() //recursive destructor
        {
            for (int i = 0; i < numbuckets; i++)
            {
                delete buckets[i]; //will delete the linked list attached with each index
            }
            delete[] buckets; // will now delete the array
        }
        int size()
        {
            return count;
        }
        //getvalue will take the key and return the value of the given key
        V getvalue(string key)
        {
            int bucketindex = getbucketindex(key);
            mapnode<V> *head = buckets[bucketindex];
            while(head != NULL)
            {
                if(head->key == key)
                {
                    return head->value;
                }
                head = head->next;
            }
            return 0;
        }
        //insert function to insert value and key into our map
        void insert(string key, V value)
        {
            int bucketindex = getbucketindex(key); // getbucketindex is our hash function
            mapnode<V> * head = buckets[bucketindex];
            while(head != NULL)
            {
                if(head->key == key)
                {
                    head->value = value;
                    return;
                }
                head = head->next;
            }
            mapnode<V> *node = new mapnode<V>(key, value);
            node->next = buckets[bucketindex];
            buckets[bucketindex] = node; 
            count++;
            double loadfactor = (1.0*count)/numbuckets;
            if(loadfactor>0.7)
            {
                rehash();
            }

        }
        // will remove the key and value and return the value corresponding to the given key
        V remove(string key)
        {
            int bucketindex = getbucketindex(key);
            mapnode<V> * head = buckets[bucketindex];
            mapnode<V> *prev = NULL;
            while(head != NULL)
            {
                if(head->key == key)
                {
                    if(prev == NULL)
                    {
                        buckets[bucketindex] = head->next;
                    }
                    else
                    {
                    prev->next = head->next;
                    }
                    V value = head->value;
                    head->next = NULL;
                    delete head;
                    count--;
                    return value;
                }
                prev = head;
                head = head->next;
            }
            return 0;
        }
        double getloadfactor()
        {
            return (1.0*count)/numbuckets;
        }
    };
int main()
{
    mymap<int> ourmap;
    for(int i =0; i<10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i+1;
        ourmap.insert(key, value);
        cout<<ourmap.getloadfactor()<<endl;
    }
    cout<<ourmap.size()<<endl;
    ourmap.remove("abc1");
    ourmap.remove("abc5");
    for(int i =0; i<10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i+1;
        cout<<key<<" "<<ourmap.getvalue(key)<<endl;
    }
    cout<<ourmap.size()<<endl;
}