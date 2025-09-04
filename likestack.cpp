#include <vector>          // 包含标准库顺序容器 vector
#include <iostream>        // 包含标准输入输出流
using namespace std;       // 使用标准命名空间，省写 std::

class SimpleStack {        // 声明名为 SimpleStack 的类
    vector<int> buf;       // 私有成员：用 vector 保存栈内数据，栈底在 buf[0]，栈顶在末尾
public:                    // 公有区开始：外部可访问的成员函数
    void push(int v) {     // 公有成员函数：入栈操作
        buf.push_back(v);  // 把参数 v 追加到向量末尾，即栈顶
    }                      // push 结束
    void pop() {           // 公有成员函数：出栈操作
        if (!buf.empty())  // 若栈非空
            buf.pop_back(); // 删除向量最后一个元素，即弹出栈顶
    }                      // pop 结束
    int top() const {      // 公有成员函数：读取栈顶元素值，const 表示不修改对象
        return buf.back(); // 返回向量最后一个元素的值
    }                      // top 结束
    void add(int n, int k) { // 公有成员函数：从栈底起向上 n 个元素各加 k
        int m = (n < (int)buf.size()) ? n : (int)buf.size(); // 取实际可处理的元素个数
        for (int i = 0; i < m; ++i) // 遍历区间 [0, m-1]
            buf[i] += k;            // 每个元素增加 k
    }                      // add 结束
    void print() const {   // 公有成员函数：顺序打印整个栈内容，const 保证只读
        for (int v : buf)  // 范围 for 循环遍历向量
            cout << v << ' '; // 输出当前元素后跟空格
        cout << endl;      // 输出换行符
    }                      // print 结束
};                         // 类定义结束

int main() {               // 主函数入口
    SimpleStack st;        // 创建 SimpleStack 类对象 st
    int n, m, k;           // 声明整型变量 n(压入 0..n)、m(操作元素个数)、k(增量)
    cin >> n >> m >> k;    // 从标准输入读取 n m k
    for (int i = 0; i <= n; ++i) // 循环 n+1 次
        st.push(i);        // 依次把 0 到 n 压入栈
    st.add(m, k);          // 调用 add：栈底向上 m 个元素各加 k
    st.print();            // 输出栈内全部元素
    return 0;              // 程序正常结束
}                          // main 结束
