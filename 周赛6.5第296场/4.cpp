class TextEditor {
    list<char> lst;
    list<char>::iterator cur;

    string print() {
        string ret;
        auto it = cur;
        for (int i = 0; i < 10; ++i) {
            if (it == lst.begin()) break;
            it = prev(it);
            ret.push_back(*it);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

public:
    TextEditor() {
        cur = lst.begin();
    }
    
    void addText(string text) {
        for (char c : text) lst.insert(cur, c);
    }
    
    int deleteText(int k) {
        int ret = 0;
        while (k && cur != lst.begin()) {
            cur = prev(cur);
            cur = lst.erase(cur);
            --k;
            ++ret;
        }
        return ret;
    }
    
    string cursorLeft(int k) {
        while (k && cur != lst.begin()) {
            cur = prev(cur);
            --k;
        }
        return print();
    }
    
    string cursorRight(int k) {
        while (k && cur != lst.end()) {
            cur = next(cur);
            --k;
        }
        return print();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */