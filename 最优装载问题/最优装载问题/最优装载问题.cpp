#include<iostream>
using namespace std;

 class bestLoading {
	static int n;//集装箱数量
	static int w[];//箱子重量数组
	static int c;//第一艘船的载重
	static int cw;//当前的载重量
	static int bestw;//最优载重
	static int r;//剩余集装箱的重量
	public static int maxLoading(int[]ww, int cc){
		n = ww.length - 1;
		w = ww;
		c = cc;
		cw = 0;
		bestw = 0;
		r = 0;
		for (int i = 1; i <= n; i++){
			r += w[i];
		}
		backtrack(0);
		return bestw;
	}

	private static void backtrack(int i){
		if (i>n){
			if (cw>bestw) bestw = cw;
			return;
		}
		r -= w[i];
		if (cw + w[i] <= c){
			cw += w[i];
			backtrack(i + 1);
			cw -= w[i];
		}
		if (cw + r>bestw)
			backtrack(i + 1);
		r += w[i];

	}
	public static void main(String[]args){
		int[]ww = { 1, 7, 4, 20, 9, 11 };
		int c = 26;
		System.out.println(maxLoading(ww, c));
	}

}