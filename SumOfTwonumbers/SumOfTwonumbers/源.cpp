#include<map>
#include <iostream>
#include<iterator>

using namespace std;
pair<int, int> Findtarget(map<int, int> zielMap, const int target);
void Show(const pair<int, int> result);
int main()
{
	int target=0;
	map<int, int> Mymap;
	Mymap.insert(map<int, int>::value_type{ 0,8 });
	Mymap.insert(pair<int, int>(1, 4));
	Mymap[2] = 5;
	Mymap[3] = 2;
	Mymap[4] = 7;
	//for (int i = 0; i < 3; i++)
	//	cout << Mymap.at(i) << endl;
	cout << "请输入target：" << endl;
	cin >> target;
	pair<int, int> get = Findtarget(Mymap, target);
	Show(get);
}

pair<int, int> Findtarget(map<int, int> zielMap, const int target)
{
	map<int, int>::iterator iter, Beg;
	for (int i = 0; i < zielMap.size(); i++)
	{
		Beg = zielMap.begin();
		iter = zielMap.find(target-Beg->first);
		Beg++;
		if (iter != zielMap.end())
			return pair<int, int>(zielMap.at(i), iter->second);
	}
	return pair<int, int>(-1, -1);
}

void Show(pair<int, int> result)
{
	if (result.first != -1 && result.second != -1)
		cout << "两个数分别为:" << result.first << "," << result.second << endl;
	else
		cout << "无满足要求选项！" << endl;
}
