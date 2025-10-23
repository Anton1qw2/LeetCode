class Solution {
public:
    pair<uint16_t, uint16_t> get_pairs(uint16_t total, uint16_t most_common){
        if ((2 * most_common) > total){
            return pair<uint16_t, uint16_t>(total - most_common, 2 * most_common - total);
        }
        return pair<uint16_t, uint16_t>(total / 2, total % 2);
    }
    int score(vector<string>& cards, char x) {
        uint16_t total_xx = 0;
        vector<uint16_t> count_ax(10,0);
        vector<uint16_t> count_xa(10,0);
        for (auto& card : cards){
            if (card[0] == x && card[1] == x)
                total_xx++;
            else if (card[0] == x)
                count_ax[card[1] - 'a']++;
            else if (card[1] == x)
                count_xa[card[0] - 'a']++;
        }
        pair<uint16_t, uint16_t> pair_ax = get_pairs(std::reduce(count_ax.begin(), count_ax.end()), *std::max_element(count_ax.begin(), count_ax.end()));
        pair<uint16_t, uint16_t> pair_xa = get_pairs(std::reduce(count_xa.begin(), count_xa.end()), *std::max_element(count_xa.begin(), count_xa.end()));
        uint16_t total_tail = pair_xa.second + pair_ax.second;
        uint16_t total_dif_pair = pair_xa.first + pair_ax.first;
        uint16_t total_score = total_dif_pair;
        if (total_tail == 0)
            total_score += min(total_score, uint16_t(total_xx / 2));
        else if (total_tail > 0){
            total_score += std::min(total_xx, total_tail);
            total_xx -= std::min(total_xx, total_tail);
            if (total_xx > 0)
                total_score += min(total_dif_pair, uint16_t(total_xx / 2));
            }
        return total_score;
    }
};