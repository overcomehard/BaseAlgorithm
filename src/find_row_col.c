#include <iostream>

void find_row_col(int n, int m, int &row, int &col)
{
	// 边界条件
	if (n <= 0 || (m <= 0 || m > n*n))
	{
		row = -1;
		col = -1;
		return;
	}
	int layer_start = 0;  //对应层的开始数值
	int layer_end = 0;  //对应层的结速数值
	for (int i = 1; i <= n / 2; i++) {
		layer_start = layer_end+1;
		layer_end += 4 * (n - (i-1)*2 - 1);
		if (m <= layer_end) {
			//确定边
			int side = ((m-1) - layer_start + 1) / (n - (i - 1) * 2 - 1);
			//确定所在边的具体位置
			int seat = ((m-1) - layer_start + 1) % (n - (i - 1) * 2 - 1) + 1;
			if (side == 0) {
				row = i;  // 第i行
				col = seat + i - 1;
			}
			else if (side == 2) {
				row = n - i + 1;  //倒数第i列
				col = n - (seat + i - 1) + 1;
			}
			else if (side == 1) {
				row = seat + i - 1;
				col = n - i + 1;  // 倒数第i行
			}
			else if (side == 3) {
				row = n - (seat + i - 1) + 1;
				col = i;  //第i列
			}
			return;
		}
	}
	if (m > layer_end) {  //当n为奇数的情况
		row = n / 2 + 1;
		col = n / 2 + 1;
	}
}

void main()
{
	int n = 5;
	int m;
	int row, col;
	while(1)
	{
		std::cin >> m;
		find_row_col(n, m, row, col);
		std::cout << row << "," << col << std::endl;
	}

	getchar();
}
