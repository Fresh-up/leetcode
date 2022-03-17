//经典页面置换算法LRU 哈希表+链表结构
struct DLinkedNode{
    //key是页面序号，value代指页面内容
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0), value(0), prev(nullptr), next(nullptr){}
    DLinkedNode(int _key, int _value):key(_key), value(_value), prev(nullptr), next(nullptr){}
};

class LRUcache{
private:
    //用哈希表记录在cache中的页面情况，搜索高效O(1)
    unordered_map<int, DLinkedNode*> cache;
    //用伪头部和伪尾部
    DLinkedNode* head;
    DLinkedNode* tail;
    //size是记录在cache中的页面数
    int size;
    //capacity是cache的总容量，总共可以放多少页面在cache中
    int capacity;
public:
    LRUcache(int _capacity):size(0), capacity(_capacity){
        //初始化cache
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    //四个基本操作
    void addToHead(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

    int get(int key){
        //在cache中寻找序号为key的页面
        if (!cache.count(key)){
            //cache中没有，返回-1
            return -1;
        }
        //cache中有，移动到链表头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value){
        //修改序号是key的页面，改值为value
        if (!cache.count(key)){
            //cache中没有，要在内存中调出
            DLinkedNode* node = new DLinkedNode(key, value);
            addToHead(node);
            cache[key] = node;
            ++size;//cache中的页面数加一
            if (size > capacity){
                //如果cache中的页面数超过了cache的容量，删除链表尾部元素
                //此为最近最少使用的
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                //防止内存泄漏!又忘了
                delete removed;
                --size;
            }
        }
        else{//一定加else
            DLinkedNode* node = cache[key];
            node->value = value;
            //把新调用的页面放到链表头部
            moveToHead(node);
        }
    }
};