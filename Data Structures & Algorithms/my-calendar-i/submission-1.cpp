class MyCalendar {
    map<int,int> booked;
public:
    bool book(int start, int end) {
        auto it = booked.lower_bound(start);

        // check overlap with next interval
        if (it != booked.end() && it->first < end) return false;

        // check overlap with previous interval
        if (it != booked.begin()) {
            auto itPrev = std::prev(it);   // ✅ use std::prev
            if (itPrev->second > start) return false;
        }

        booked[start] = end;
        return true;
    }
};
