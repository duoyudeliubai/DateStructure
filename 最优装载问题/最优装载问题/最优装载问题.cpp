#include<iostream>
using namespace std;

 class bestLoading {
	static int n;//��װ������
	static int w[];//������������
	static int c;//��һ�Ҵ�������
	static int cw;//��ǰ��������
	static int bestw;//��������
	static int r;//ʣ�༯װ�������
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