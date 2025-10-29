class Solution {
public:
    int inline count_lasers(string& floor) {
        return std::count(floor.begin(), floor.end(), '1');
    }

    int numberOfBeams(vector<string>& bank) {
        uint32_t current, next, total_lines = 0;
        for (auto& line : bank) {
            next = count_lasers(line);
            total_lines += (next != 0) ? exchange(current, next) * next : 0;
        }
        return total_lines;
    }
};