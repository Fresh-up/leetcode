class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int p = 0, plast = 0;
        string res;
        double d = 1 - (discount / 100);
        while (p < sentence.size()) {
            if (sentence[p] == '$') {
                int pp = p + 1;
                res += sentence.substr(plast, pp);
                while (pp < sentence.size() && isdigit(sentence[pp])) {
                    ++pp;
                }
                if (pp != p + 1 && (pp == sentence.size() || sentence[pp] == ' ')) {
                    int k = stoi(sentence.substr(p + 1, pp - p - 1));
                    double kk = k * d;
                    std::stringstream ss;
                    ss << std::setiosflags(std::ios::fixed) << std::setprecision(2) << kk;
                    string newsub = ss.str();
                    res += newsub;
                    plast = pp;
                    p = pp;
                }
            }
            ++p;
        }
        res += sentence.substr(plast, p - plast);
        return res;
    }
};