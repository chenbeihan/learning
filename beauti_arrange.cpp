#include <iostream>
#include <vector>

using namespace std;

int n;                   // 全局变量：数列长度
vector<int> path;        // path[i] 表示当前排列的第 i 个位置放的数字
vector<bool> used;       // used[num]=true 表示数字 num 已经被使用过了

// 回溯函数：正在给第 pos 个位置选数字
void dfs(int pos) {
    // 如果 pos 超过 n，说明 1~n 全部填完，找到一个合法排列
    if (pos > n) {
        // 输出当前合法排列，格式：a[1] a[2] ... a[n]
        for (int i = 1; i <= n; ++i)
            cout << path[i] << (i == n ? '\n' : ' ');
        return;          // 回溯到上一层，继续搜索下一个可能
    }

    // 枚举把数字 1~n 放到第 pos 个位置
    for (int num = 1; num <= n; ++num) {
        if (used[num]) continue;               // 如果 num 已经被用过，跳过
        // 剪枝：必须满足 num 与 pos 互相可整除
        if (num % pos != 0 && pos % num != 0) continue;

        used[num] = true;   // 标记 num 已使用
        path[pos] = num;    // 把 num 放到当前位置
        dfs(pos + 1);       // 递归去填下一个位置
        used[num] = false;  // 回溯：撤销选择，尝试别的数字
    }
}

int main() {
    cin >> n;               // 读入数列长度 n
    path.resize(n + 1);     // 下标从 1 用到 n
    used.resize(n + 1, false); // 初始化为 false，表示所有数字都未使用

    dfs(1);                 // 从第 1 个位置开始搜索
    return 0;
}
