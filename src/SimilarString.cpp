// 对于两个字符串 A 和 B，如果 A 可以通过删除一个字符，或插入一个字符，或修改一个字符变成 B，那么我们说 A 和 B 是相似的。

// 比如 apple 可以通过插入一个字符变成 applee，可以通过删除一个字符变成 appe，也可以通过修改一个字符变成 bpple。因此 apple 和 applee、appe、bpple 都是相似的。但 applee 并不能 通过任意一个操作变成 bpple，因此它们并不相似。

// 特别地，两个完全相同的字符串也是相似的。

// 给定 T 组 A,B，请你分别判断它们是否相似。

// 输入格式
// 第一行一个正整数 T。
// 接下来 T 行，每行两个用空格隔开的字符串 A 和 B。

// 输出格式
// 对组 A,B，如果他们相似，输出 similar，否则输出 not similar。

// 输入输出样例
// 输入

// 5
// apple applee
// apple appe
// apple bpple
// applee bpple
// apple apple
// 输出

// similar
// similar
// similar
// not similar
// similar
#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		string a,b;
		cin>>a>>b;
		int alen = a.length();
		int blen = b.length();
		//两个完全相同的字符串也是相似的
		if(a==b)
		{
			cout<<"similar"<<endl;
		}
		if(abs(alen-blen)>1)
		{
			cout<<"not similar"<<endl;
			//TODO
		}
		else if(alen == blen)
		{
			for (int j = 0; j < alen; j++)
			{
				if (a[j] != b[j])
				{
					a.erase(j,1);
					a.insert(j,1,b[j]);
					if(a==b)
					{
						cout<<"similar"<<endl;
						break;
					}
					else
					{
						cout<<"not similar"<<endl;
					}
				}
			}
		}
		//不相同
		else
		{
			if (alen - blen==1)
			{
				for (int j = 0; j < alen; j++)
				{
					if (a[j] != b[j])
					{
						a.erase(j,1);
						if(a==b)
						{
							cout<<"similar"<<endl;
							break;
						}
						else
						{
							cout<<"not similar"<<endl;
							break;
						}
					}
				}
			}
			else if(blen-alen==1)
			{
				for (int j = 0; j < blen; j++)
				{
					if (a[j] != b[j])
					{
						b.erase(j,1);
						if(a==b)
						{
							cout<<"similar"<<endl;
							break;
						}
						else
						{
							cout<<"not similar"<<endl;
							break;
						}
					}

					
				}
				/* code */
			}
		}
		
		/* code */
	}
	
}