#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
/*//求一元二次方程ax^2 + bx + c = 0的根，其中a不等于0
//公式x1=(-b + sqrt(b^2-4ac)/2a;x2=(-b - sqrt(b^2-4ac)/2a
int main()
{
	double a, b, c, x1, x2,s,m;
	cin >> a;
	if (a != 0)
		cin >> b >> c;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	s = -b / (2 * a);	//求实部的值
	if (-b == 0)
		s = 0;		//若被除数为0，需特判s=-0的情况，将s值改为0
	m = sqrt(4 * a * c - b * b) / (2 * a);	//求虚根的值
	if (x1 == x2)
		printf("x1 = x2 = %.5lf", x1);
	else if (x1 != x2)
		printf("x1 =  %.5lf; x2 = %.5lf", x1, x2);
	else
		printf("x1 =  %.5f+%.5i; x2 %.5f-%.5f", s, m, s, m);
	return 0;
}*/

//斐波那契数列  a1=1,a2=1,a3=a1+a2
/*int main()
{
	int a1 = 1, a2 = 1, x, s;
	cin >> x;
	for (int i = 3; i <= x; i++)
	{
		s = a1 + a2;
		a1 = a2;
		a2 = s;
	}
	cout << s << endl;
	return 0;
}
*/

//选择排序:每一趟从待排序元素中选出最小/大的一个元素放在待排序数列的最前，直到全部排完
/*int main()
{
	//方法：外层循环i控制当前序列最小值存放数组的位置，内层循环j控制从i+1到n序列中选择最小的元素所在的位置k
	int n, k, i, j; const int MAXN = 10001; int count = 0;
	float temp, a[MAXN];
	cin >> n;//从小到大排序
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i <= n; i++)//i控制当前序列最小值存放的数据位置
	{
		k = i;//最小元素所在位置
		for (j = i + 1; j <= n; j++)
			if (a[j] < a[k])
				k = j;
		if (k != i)
		{
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
			count++;
		}
	}for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << "\ntotal change step = " << count << endl;
	return 0;
}*/

//冒泡排序：比较相邻的；进行一轮的比较之后，原n个数的排序问题，转换为n-1个数的排序问题
/*int main()
{
	//1.读入数据存放在a数组中
	//2.比较相邻的前后两个数据，如果前面数据大于后面数据，就将两个数据交换
	//3.对数组的第1个数据到第n个数据进行一次遍历后，最大的一个数据就冒到数组第n个位置
	//4.n = n - 1,如果n不为1就重复前面二步，否则排序完成
	//实现方法：外层循环i控制每轮要进行多少次比较，内层循环j控制每轮比较相邻两个元素是否逆序
	const int MAXN = 10001;
	int n, i, j; int count = 0;
	float a[MAXN];
	cin >> n;
	for (i = 1; i <= n; i++)//相当于for(i = n;i > 1;i--)进行n-1轮冒泡;内层循环用for(j = 1;j < i;j++)
		cin >> a[i];
	for (i = 1; i <= n - 1; i++)
		for (int j = 1; j <= n - i; j++)
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				count++;
			}
	for (i = 1; i <= n; i++)
		cout << a[i]<<" ";
	cout << "\ntotal change step = "<<count<<endl;
	//对于有些数据不一定要n-1次才排完，因此可设置一个布尔变量，判断是否有进行交换，若没有交换则说明已经排序完成
	bool ok; int n1;int count1 = 0;
	cin >> n1;
	for (int i = 1; i <= n1; i++)
		cin >> a[i];
	for(int i = n1;i > 1;i--)
	{
		ok = true;
		for(int j = 1;j < i;j++)
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				ok = false;
				count1++;
			}
		if (ok == true)		//没有交换就退出
			break;
	}
	for (int i = 1; i <= n1; i++)
		cout << a[i] << " ";
	cout << "\ntotal change step = " << count1 << endl;
	return 0;
}*/

/*
//插入排序：模拟抓牌一边抓一边排，当抓完所有牌时，手中的牌是有序的
int main()
{
	//插入数据从后面开始比较，如果大于前面的就记录下标，并将数据后移，直到插入数据碰到比它小的。
	//当读入一个元素时，在已经排好的序列中搜寻他正确位置，再放入读入的元素。
	//不能忽略：插入这个元素前应把他后面的所有元素后移一位，来保证插入位置的原元素不被覆盖
	const int MAXN = 10001;
	int n, n1, i, j, k;
	float temp, a[MAXN];
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i <= n; i++)
	{
		for (j = i - 1; j >= 1; j--)//在前面有序区间中为a[i]找合适的插入位置
			if (a[j] <= a[i])
				break;			//找到比a[i]小的位置就退出，将a[i]插入其后
		if (j != i - 1)//找到比a[i]大的，j此时是那个元素的下标非a[i]前面一个元素
		{
			//用整型变量 temp 来临时存放每一次需要排序的元素， 每一次判断的条件就是在一定条件下temp 是否小于前一个元素（默认从小到大排序）
			temp = a[i];
			for (k = i - 1; k > j; k--)//从原来第二层循环开始的j出发即a[i]前一位开始整体往后移动
				a[k + 1] = a[k];
			a[k + 1] = temp;		//插入比a[i]小的值在前面某个下标
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	//////////////////////////////这个好理解
	cin >> n1;
	for (i = 1; i <= n1; i++)
		cin >> a[i];
	for (i = 1; i <= n1; i++) { // 修正外循环边界  
		temp = a[i]; // 保存当前需要排序的元素  
		j = i - 1; // 从前一个元素开始比较  

		// 找到已排序部分中第一个比temp大的元素的位置  
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j]; // 元素后移  
			j--;
		}
		a[j + 1] = temp; // 插入元素  ，就算j为0也不影响
	}
	for (int i = 1; i <= n1; i++)
		cout << a[i] << " ";
}*/

/*//桶排序：设计有限个有序桶，将待排序的值装入对应的桶（可装若干个值），桶号就是待排序的值，顺序输出各桶的值，将得到有序的数列
//基本思路如下代码
int main()
{
	const int N = 10000;
	int b[N + 1];	int  n, i, k;
	memset(b, 0, sizeof(b));//初始化
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> k;//k的值有范围0 - 100
		b[k]++;//将k值即第k桶标记成有值装入的桶：将等于k的值全部装入第k桶中
	}
	for (i = 0; i <= 100; i++)	
		while (b[i] > 0)	//b[i]的值对应着有几个相同的i
		{
			cout << i << " ";
			b[i]--;	//直至相同的i全部输出
		}
}
//例题：生成1-1000的随机整数，对于其中重复的数字只保留一个，不同的数对于不同的学生的学号，然后从小到大排序这些数
int main()
{
	const int NN = 1000;
	int a[NN + 1], n, i, k;//b[i]记录值为i的个数，那么从小到大输出b数组值不为0的b数组下标值
	int m = 0;//记录随机个数
	memset(a, 0, sizeof(a));
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> k;//桶号对应的值
		if (a[k] == 0)
			m++;//表示k为新的随机数，计算器m+1
		a[k]++;
	}
	cout <<m<< endl;//输出随机出现的值的个数
	for (i = 0; i < 1000; i++)
		while (a[i] > 0)//if(a[i]>0)直接输出i
		{
			cout << i << " ";
			break;
		}
	cout << endl;
	return 0;
}*/


/*//快速排序：速度快不稳定，需要栈空间来实现递归
//一趟排序过后将待排记录分割成两个独立的部分；将关键字小于mid的放在左子序列，将关键字大于mid的放在右子序列
//其中一部分记录的关键字均比另一部分记录的关键字要小，则可分别对这两部分记录继续进行排序，以达整个序列有序
//方法：设指针i初值为l指针j初值为r，设枢纽记录取mid，
//则从j所指位置向前搜索找到第一个关键字小于mid的记录，然后从i所指位置向后搜索找到第一个关键字大于mid的记录，将他们互相交换，重复这两步直至i>j
const int N = 10000;
int a[N + 1];

void qsort(int , int );
void qsort(int l, int r)
{
	int mid = a[(l + r) / 2];//将当前序列的中间位置的数定义为分隔数
	int i = l; int j = r;	int temp;
	do
	{
		while (a[i] < mid)
			i++;	//在左半部分寻找比中间数大的数
		while (a[j] > mid)
			j--;	//在右半部分寻找比中间数小的数
		if (i <= j)
		{
			//若找到一组与排序目标不一致的数对则交换他们
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;	//继续找
		}
	} while (i <= j);	//等号不能少
	if (l < j)
		qsort(l,j);//若未找到两个数的边界，则递归搜索左右区间
	if (i < r)
		qsort(i, r);
}
int main()
{
	int n, i;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	qsort(1, n);
	for (i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}*/

/*
//归并排序：建立在归并操作上的一种有效排序算法 ，分治法的典型应用,速度快且稳定，相等的元素的排序不会改变
//思想：将已有的子序列合并，得到完全有序的序列，即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个，称为二路归并;两大步：分解、合并
//合并过程：比较a[i]和a[j]的大小，若a[i]小则赋值到r[k]中，并令i和k加上1；否则将另一个同理。直至其中一个有序表取完，再将另一个有序表中剩余的元素复制到r中下标从k到t的单元
//合并：通常使用递归先把排列区间[s,t]以中点划分，接着将左边子区间排序，再将右边子区间排序，最后把左右区间用一次归并操作合并成有序的区间[s,t]
const int N = 10000;
int r[N + 1],a[N + 1];
//int* b = new int[hight - low + 1];  //用 new 申请一个辅助函数
//int i = low, j = mid + 1, k = 0;    // k为b数组的小标
void msort(int s, int t);
void msort(int s, int t)
{
	if (s == t) return;	//如果只有一个数字则返回，无须排序
	int mid = (s + t) / 2;//中点
	msort(s, mid);	//分解左序列
	msort(mid + 1, t);//分解右序列
	int i = s, j = mid + 1, k = s;//接下来合并,k是r数组的下标

	while (i <= mid && j <= t)
	{
		if (a[i] <= a[j]){//从小到大排序
			r[k] = a[i];	k++;i++;//r[k++] = a[i++];
		}
		else{
			r[k] = a[j];	k++;j++;//r[k++] = a[j++];
		}
	}
	while (i <= mid)//j 序列结束，将剩余的 i 序列补充在 r 数组中 
	{
		r[k] = a[i];	k++; i++;
	}
	while (j <= t) {//i 序列结束，将剩余的 j 序列补充在 r 数组中 
		r[k] = a[j];	k++; j++;
	}
	for (int i = s; i <= t; i++)//排好两个子序列区间后合并起来，r数组是排好的
		a[i] = r[i];//将 r 数组的值传递给数组 a
}
int main()
{
	int n, i;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	msort(1, n);
	for (i = 1; i <= n; i++)
		cout << r[i] << " ";
	cout << endl;
	return 0;
}
/*#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
void merge(int* a, int low, int mid, int hight)  //合并函数
{
	int* b = new int[hight - low + 1];  //用 new 申请一个辅助函数
	int i = low, j = mid + 1, k = 0;    // k为 b 数组的小标
	while (i <= mid && j <= hight)  
	{
		if (a[i] <= a[j])
		{
			b[k++] = a[i++];  //按从小到大存放在 b 数组里面
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while (i <= mid)  // j 序列结束，将剩余的 i 序列补充在 b 数组中 
	{
		b[k++] = a[i++];
	}
	while (j <= hight)// i 序列结束，将剩余的 j 序列补充在 b 数组中 
	{
		b[k++] = a[j++];
	}
	k = 0;  //从小标为 0 开始传送
	for (int i = low; i <= hight; i++)  //将 b 数组的值传递给数组 a
	{
		a[i] = b[k++];
	}
	delete[]b;     // 辅助数组用完后，将其的空间进行释放（销毁）
}
void mergesort(int* a, int low, int hight) //归并排序
{
	if (low < hight)
	{
		int mid = (low + hight) / 2;
		mergesort(a, low, mid);          //对 a[low,mid]进行排序
		mergesort(a, mid + 1, hight);    //对 a[mid+1,hight]进行排序
		merge(a, low, mid, hight);       //进行合并操作
	}
}
int main()
{
	int n, a[100];
	cout << "请输入数列中的元素个数 n 为：" << endl;
	cin >> n;
	cout << "请依次输入数列中的元素：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	mergesort(a, 0, n-1);
	cout << "归并排序结果" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

//例题：逆序对问题
//思路：找右边序列元素的较小值i(相对于左边序列,与其左边剩余的数字会产生逆序关系)，能一下子计算出几对逆序对
//接下来再次在右边序列找(在取下i放到辅助数组后)较小的值j，同时取下在左边序列比j同时比i大的值放入辅助数组里。
const int N = 10000;
int r[N + 1], a[N + 1],ans;
//int* b = new int[hight - low + 1];  //用 new 申请一个辅助函数
//int i = low, j = mid + 1, k = 0;    // k为b数组的小标
void msort(int s, int t);
void msort(int s, int t)
{
	if (s == t) return;	//如果只有一个数字则返回，无须排序
	int mid = (s + t) / 2;//中点
	msort(s, mid);	//分解左序列
	msort(mid + 1, t);//分解右序列
	int i = s, j = mid + 1, k = s;//接下来合并,k是r数组的下标

	while (i <= mid && j <= t)
	{
		if (a[i] <= a[j]) {//从小到大排序
			r[k] = a[i];	k++; i++;//r[k++] = a[i++];
		}
		else {//即前面的比后面大，产生了逆序对
			r[k] = a[j];	k++; j++;//r[k++] = a[j++];
			ans += mid - i + 1;//统计产生逆序对的数量，ans要增加左边区间剩余元素的个数即比右边较小值大的值的个数
			//左半部分的i-mid都可以和j组成逆序对
		}
	}
	while (i <= mid)//j 序列结束，将剩余的 i 序列补充在 r 数组中 
	{
		r[k] = a[i];	k++; i++;
	}
	while (j <= t) {//i 序列结束，将剩余的 j 序列补充在 r 数组中 
		r[k] = a[j];	k++; j++;
	}
	for (int i = s; i <= t; i++)//排好两个子序列区间后合并起来，r数组是排好的
		a[i] = r[i];//将 r 数组的值传递给数组 a
}
int main()
{
	int n, i;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	msort(1, n);
	for (i = 1; i <= n; i++)
		cout << r[i] << " ";
	cout << "\nans = " << ans << endl;
	return 0;
}*/

//递推
//数塔问题，数字三角形每个位置对应一个值。编写程序计算从顶到底的某处的一条路径，使得该路径经过的数字总和最大
//要求：1.一步可沿左斜线向下或右斜线向下走；2.三角形行数小于100；3.三角形中的数字为0-99
//思路：倒推(因为从顶层沿某条路径走到第i层向第i+1层前进时，我们的选择一定是沿其下两条路径中最大的数字方向前进)
//设a[i][j]存放i，出发到达n层最大值，则a[i][j]=max{a[i][j]+a[i+1][j],a[i][j]+a[i+1][j+1]}  a[1][1]即为所求数字总和的最大值,
int main() 
{
	int n,n2,j,i,a[101][101],b[101][101];
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = n; i >= 1; i--) {//方法一
		int max = a[i][1];
		for (int j = 1; j <= i; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		sum += max;
	}	cout << "方法一 sum = " << sum << endl;

	cin >> n2;
	for (int i = 1; i <= n2; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> b[i][j];
		}
	}
	for(i = n2 - 1;i >= 1;i--)//从n-1层逆推，a[n-1]层由a[n]层中大的逆推而来
		for (j = 1; j <= i; j++)
		{
			if (b[i+1][j] >= b[i+1][j+1])
				b[i][j] += b[i+1][j];
			else
				b[i][j] += b[i+1][j+1];
		}
	cout << "方法二 sum = "<<b[1][1]<< endl;
	return 0;
}