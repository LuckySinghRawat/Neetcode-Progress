class MyCalendar {
public:
    MyCalendar() {
        
    }
    unordered_map<int, bool> booked;
    bool query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return false; // no overlap
        if (booked[node]) return true;      // already booked
        if (l == r) return false;
        int mid = (l + r) >> 1;
        return query(node*2, l, mid, ql, qr) || query(node*2+1, mid+1, r, ql, qr);
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            booked[node] = true;
            return;
        }
        int mid = (l + r) >> 1;
        update(node*2, l, mid, ql, qr);
        update(node*2+1, mid+1, r, ql, qr);
    }
 int MAX_RANGE = 1e9;
        bool book(int start, int end) {
        // check overlap
        if (query(1, 0, MAX_RANGE, start, end-1)) return false;
        // insert booking
        update(1, 0, MAX_RANGE, start, end-1);
        return true;
    }
    
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */