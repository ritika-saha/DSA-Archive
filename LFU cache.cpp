//LEAST FREQUENTLY USED CACHE

class Node {
public:
    int key, value, cnt;
    Node* next;
    Node* prev;
    
    Node(int _key, int _value) : key(_key), value(_value), cnt(1), next(nullptr), prev(nullptr) {}
};

class List {
public:
    int size;
    Node* head;
    Node* tail;
    
    List() : size(0) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    void addFront(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
private:
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;
    
public:
    LFUCache(int capacity) : maxSizeCache(capacity), minFreq(0), curSize(0) {}
    
    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }
        
        List* nextHigherFreqList = freqListMap[node->cnt + 1];
        if (!nextHigherFreqList) {
            nextHigherFreqList = new List();
            freqListMap[node->cnt + 1] = nextHigherFreqList;
        }
        
        node->cnt++;
        nextHigherFreqList->addFront(node);
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }
        
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {
            if (curSize == maxSizeCache) {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            
            curSize++;
            minFreq = 1;
            List* listFreq = freqListMap[minFreq];
            if (!listFreq) {
                listFreq = new List();
                freqListMap[minFreq] = listFreq;
            }
            
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
        }
    }
};

