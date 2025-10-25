class RecentCounter {
private:
    static constexpr uint32_t DELAY_MS = 3000;
    std::queue<int> calls;

public:
    RecentCounter() = default;

    int ping(int t) {
        calls.push(t);;
        remove_old_calls(t);
        return calls.size();
    }
private:
    void remove_old_calls(int current_time) noexcept {
        const int threshold = current_time - DELAY_MS;
        while (!calls.empty() && calls.front() < threshold) {
            calls.pop();
        }
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */