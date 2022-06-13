class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans;
        if (income <= brackets[0][0]) return (double)(brackets[0][1] * income) / 100;
        else {
            income -= brackets[0][0];
            ans += (double)(brackets[0][0] * brackets[0][1]) / 100;
        }
        for (int i = 1; i < brackets.size() && income > 0; ++i) {
            if (income <= brackets[i][0] - brackets[i - 1][0]) {
                ans += (double)(income * brackets[i][1]) / 100;
                break;
            } else {
                income -= brackets[i][0] - brackets[i - 1][0];
                ans += (double)((brackets[i][0] - brackets[i - 1][0]) * brackets[i][1]) / 100;
            }
        }
        return ans;
    }
};
// 经验是，要想除法计算返回一个double类型，除数或被除数至少有一个是double

// 优秀的代码：
class Solution {
public:
  double calculateTax(vector<vector<int>>& brackets, int income) {
    // 直接100.0让返回值为double，先除后乘避免溢出
    if (income <= brackets[0][0]) return income * (brackets[0][1] / 100.0);
    double ans = brackets[0][0] * (brackets[0][1] / 100.0);
    for (int i = 1; i < brackets.size(); ++i) {
      // 这才是阶梯的样子
      if (income > brackets[i - 1][0]) 
        ans += (min(income, brackets[i][0]) - brackets[i - 1][0]) * (brackets[i][1] / 100.0);
    }
    return ans;
  }
};