// ���������ַ��� A �� B����� A ����ͨ��ɾ��һ���ַ��������һ���ַ������޸�һ���ַ���� B����ô����˵ A �� B �����Ƶġ�

// ���� apple ����ͨ������һ���ַ���� applee������ͨ��ɾ��һ���ַ���� appe��Ҳ����ͨ���޸�һ���ַ���� bpple����� apple �� applee��appe��bpple �������Ƶġ��� applee ������ ͨ������һ��������� bpple��������ǲ������ơ�

// �ر�أ�������ȫ��ͬ���ַ���Ҳ�����Ƶġ�

// ���� T �� A,B������ֱ��ж������Ƿ����ơ�

// �����ʽ
// ��һ��һ�������� T��
// ������ T �У�ÿ�������ÿո�������ַ��� A �� B��

// �����ʽ
// ���� A,B������������ƣ���� similar��������� not similar��

// �����������
// ����

// 5
// apple applee
// apple appe
// apple bpple
// applee bpple
// apple apple
// ���

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
		//������ȫ��ͬ���ַ���Ҳ�����Ƶ�
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
		//����ͬ
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