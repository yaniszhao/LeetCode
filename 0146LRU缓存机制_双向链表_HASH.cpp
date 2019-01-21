class LRUCache {
public:
    //hash+list减少查找时间，但是还是没有我用3个vector的快
    class Node {
    public:
        int key;
        int val;
    };
    list<Node> li;
    map<int, list<Node>::iterator> m;
    int maxsize;
    
    LRUCache(int capacity) {//初始化
        maxsize=capacity;
    }
    
    int get(int key) {
        if (maxsize==0) return -1;//空间为0
        auto it=m.find(key);
        if (it==m.end()) return -1;//没找到
        else {
            auto itlist=m[key];
            Node tmp={key, itlist->val};
            li.erase(itlist);
            //li.insert(li.begin(), tmp);
            li.push_front(tmp);
            m[key]=li.begin();
            return tmp.val;
        }
    }
    
    void put(int key, int value) {
        if (maxsize==0||key==-1)
            return;//空间为0或者key不符合
        Node tmp={key, value};
        auto it=m.find(key);
        //相同的key
        if (it!=m.end()) {//相同的key
            auto itlist=m[key];
            li.erase(itlist); 
        }//不同的key，且要替换
        else if (li.size()>=maxsize) {
            m.erase(m.find(li.back().key));
            li.pop_back();
        } 
        //更新list和map
        //li.insert(li.begin(), tmp);
        li.push_front(tmp);
        m[key]=li.begin();
    }
};

class LRUCache3 {
public:
    //用链表就可以少用一个time变量，单向链表删除一个点挺麻烦，用双向好点
    //这里时间还是多，自己写个双向链表应该要快一点
    class Node {
    public:
        int key;
        int val;
        bool operator==(const Node &x) {return (key == x.key);}
    };
    list<Node> li;
    int maxsize;
    
    LRUCache3(int capacity) {//初始化
        maxsize=capacity;
    }
    
    int get(int key) {
        if (maxsize==0) return -1;//空间为0
        Node tmp={key,0};
        auto it=find(li.begin(), li.end(), tmp);
        if (it==li.end()) return -1;//没找到
        else {
            tmp={it->key, it->val};
            li.erase(it);
            li.insert(li.begin(), tmp);
            return tmp.val;
        }
    }
    
    void put(int key, int value) {
        if (maxsize==0||key==-1)
            return;//空间为0或者key不符合
        Node tmp={key,0};
        //相同的key
        auto it=find(li.begin(), li.end(), tmp);
        if (it!=li.end())//相同的key
            li.erase(it);
        else if (li.size()>=maxsize) //不同的key，找到下标
            li.pop_back();
        //找到下标后就可以赋值了
        tmp={key, value};
        li.insert(li.begin(), tmp);
    }
};

class LRUCache2 {
public://这个时间比之前的还要高
    typedef struct node {
        int val;
        int time;
    } Node;
    map<int, Node> m;
    int time;//时间戳
    int maxsize;
    int curcnt;
    
    LRUCache2(int capacity) {//初始化
        maxsize=capacity;
        curcnt=0;
        time=0;
    }
    
    int get(int key) {
        if (maxsize==0) return -1;//空间为0
        auto it=m.find(key);
        if (it==m.end()) return -1;//没找到
        else {
            it->second.time=++time;//要更新时间戳
            return it->second.val;
        }
    }
    
    void put(int key, int value) {
        if (maxsize==0||key==-1)
            return;//空间为0或者key不符合
        //相同的key
        auto it=m.find(key);
        if (it!=m.end()) {
            it->second.val=value;
            it->second.time=++time;
            return;
        }
        //不同的key，找到下标
        auto iPair=m.end();//假设有空的
        if (curcnt>=maxsize) {//没空的，要自己找
            iPair=m.begin();
            for (auto it=m.begin(); it!=m.end(); it++)
                if (it->second.time < iPair->second.time)
                    iPair=it;
        }
        //找到下标后就可以赋值了
        if (iPair==m.end()) curcnt++;//有空白的
        else m.erase(iPair);
        m[key]={value, ++time};
    }
};

class LRUCache1 {
public://时间好像有点多，考虑换下数据结构
    vector<int> vKey;
    vector<int> vVal;
    vector<int> vTime;
    int time;//时间戳
    
    LRUCache1(int capacity) {//初始化
        vKey.resize(capacity);
        vTime.resize(capacity);
        vVal.resize(capacity);
        fill(vKey.begin(), vKey.end(), -1);
        time=0;
    }
    
    int get(int key) {
        if (vKey.size()==0) return -1;//空间为0
        auto it=find(vKey.begin(), vKey.end(), key);
        if (it==vKey.end()) return -1;//没找到
        else {
            int idx=it-vKey.begin();
            vTime[idx]=++time;//要更新时间戳
            return vVal[idx];
        }
    }
    
    void put(int key, int value) {
        if (vKey.size()==0||key==-1)
            return;//空间为0或者key不符合
        int idx;//用于替换的下标
        //相同的key
        auto it=find(vKey.begin(), vKey.end(), key);
        if (it!=vKey.end()) {
            idx=it-vKey.begin();
            vVal[idx]=value;
            vTime[idx]=++time;
            return;
        }
        //不同的key，找到下标
        it=find(vKey.begin(), vKey.end(), -1);
        if (it!=vKey.end()) {//有空的
            idx=it-vKey.begin();
        } else {//没空的，要自己找
            int minTime=vTime[0];
            idx=0;
            for (int i=1; i<vTime.size(); i++) {
                if (vTime[i]<minTime) {
                    minTime=vTime[i];
                    idx=i;
                }
            }
        }
        //找到下标后就可以赋值了
        vKey[idx]=key;
        vVal[idx]=value;
        vTime[idx]=++time;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
