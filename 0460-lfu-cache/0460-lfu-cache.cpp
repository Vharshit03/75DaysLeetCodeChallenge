class Node{
    public:
    int key, val;
    int cnt;
    Node* next;
    Node* prev;


    Node(int key_,int value){
        key = key_;
        val = value;
        cnt = 1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;

    List(){
        size = 0;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
     }

    void addFront(Node* node){
      Node* nextNode = head->next;
      node->next = nextNode;
      node->prev = head;
      nextNode->prev = node;
      head->next = node;
      size++;
    }

   void deleteNode(Node* node){
      Node* prevNode = node->prev;
      Node* nextNode = node->next;

      prevNode->next = nextNode;
      nextNode->prev = prevNode;
      size--;
    }

};
class LFUCache {
private:
   unordered_map<int,List*> FreqListMp;
   unordered_map<int,Node*> keymp;
   int currSize;
   int maxSize;
   int minFreq;

public:
    LFUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
        minFreq = 0;

    }

    void updateFreqList(Node* node){



        FreqListMp[node->cnt]->deleteNode(node);

        if(node->cnt == minFreq && FreqListMp[node->cnt]->size==0)
        minFreq++;

        List* nextFreqList = new List();
        if(FreqListMp.find(node->cnt + 1) != FreqListMp.end()){
            nextFreqList = FreqListMp[node->cnt +1];
        }

        nextFreqList->addFront(node);
        node->cnt += 1;
        FreqListMp[node->cnt] = nextFreqList;

    }
    
    int get(int key) {

        if(keymp.find(key)!= keymp.end()){
           Node* node = keymp[key];
           updateFreqList(node);

           return node->val;
        }

        return -1;
        
    }
    
    void put(int key, int value) {
        
        if(keymp.find(key)!= keymp.end()){
            Node* node = keymp[key];
            node->val = value;
            updateFreqList(node);
        }
        else{

            if(currSize == maxSize){
                List* list = FreqListMp[minFreq];

                keymp.erase(list->tail->prev->key);

                list->deleteNode(
                    list->tail->prev
                );
                
                currSize--;
            }

            currSize++;

            minFreq = 1;
            List* newList = new List();

            if(FreqListMp.find(minFreq) != FreqListMp.end()){
                newList = FreqListMp[minFreq];
            }

            Node* newNode = new Node(key,value);
            newList->addFront(newNode);
            FreqListMp[minFreq] = newList;

            keymp[key] = newNode;

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */