#define _CRT_SECURE_NO_WARNINGS 1
//链接：https://www.nowcoder.com/questionTerminal/f5805cc389394cf69d89b29c0430ff27
//
//给定一个长度为N(N > 1)的整型数组A，可以将A划分成左右两个部分，左部分A[0..K]，右部分A[K + 1..N - 1]，K可以取值的范围是[0, N - 2]。求这么多划分方案中，左部分中的最大值减去右部分最大值的绝对值，最大是多少？
//【题目解析】：
//要求两个最大值的差, 所以肯定可以找到整个数组的最大值, 然后就可以确定一边的最大值了;另一边的最大值就是要找左右两端最小那个数, 因为无论他们怎么往外扩都只能增大, 不能减小,所以最大差值就是第一次找出来的最大值和左右两边小的那个数的差了
//【解题思路】：
//1. 按照题意, 将i为0到n - 1的情况都罗列出来即可.
//2. 创建 mxL 记录i位左侧最大值, 创建 mxR 记录i位右侧最大值.这是在找最大值.
//3. 核心要体会到 第 i 位左侧的最大值就是 i - 1 位最大值和 i 的值的较大值.
//例如输入数据为[2, 7, 3, 1, 1] mxL 中的值为 : [2, 7, 7, 7, 7] mxR 中的值为 : [7, 7, 3, 1, 1]
//4. 然后再拿着每个位置的最大值依次去和数组的每个元素做减法, 来找到差值的最大.牢记, 最大差值就是
//最大值和左右两边最小的那个数的差
#include <iostream>
#include <vector>
using namespace std;
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		vector<int> mxL(n, 0);//记录i位左侧最大值
		vector<int> mxR(n, 0);//记录i位右侧最大值
		int max = INT_MIN;
		for (int i = 0; i < n; i++){//左侧
			if (i == 0)
				mxL[i] = A[i];
			else
				mxL[i] = max(A[i], mxL[i - 1]); // 第 i 位左侧的最大值就是 i - 1 位最大值和 i 的值的较大值
		} 
		for(int i = n - 1; i >= 0; i--){//右侧
			if (i == n - 1)
				mxR[i] = A[i];
			else
				mxR[i] = max(A[i], mxR[i + 1]);
		} // 例如输入数据为[2, 7, 3, 1, 1]
			// mxL 中的值为: [2,7,7,7,7]
			// mxR 中的值为: [7,7,3,1,1]
			int res = INT_MIN;
		// 接下来的循环就依次求差找最大值即可.
		for (int i = 0; i < n - 1; i++){//求差
			res = max(res, abs(mxL[i] - mxR[i + 1]));
		} 
		return res;
	}
};