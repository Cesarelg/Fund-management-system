#include <bits/stdc++.h>
#define debug(x) (cout << "#x = " << (x) << endl)

using namespace std;
typedef long long ll;

inline char gc() {
	static char buf[100000], *p1 = buf, *p2 = buf;
	return (p1 == p2) && (p2 = (p1 = buf) +
		fread(buf, 1, 100000, stdin), p1 == p2)? EOF: *p1++;
}

#define dd ch = getchar()
inline ll read() {
	ll x = 0;
	int f = 0; char dd;
	for (; !isdigit(ch); dd) f ^= (ch == '-');
	for (; isdigit(ch); dd)  x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? -x: x;
}
#undef dd

template <class T>
inline void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 | 48);
}

template <class T>
inline void wrn(T x) {
	write(x), putchar(' ');
}

template <class T>
inline void wln(T x) {
	write(x), putchar('\n');
}

const int N = 1e6 + 5;

int cnt = 0;

map <string, int> ID_map, Name_map, abbr_map;

struct Fund {
	string ID, Name, abbr, Time, established_time;
	double unit_net, accumulated_net,
		day_growth, week_growth, month_growth, quarter_growth,
		hyear_growth, year_growth, year2_growth, year3_growth,
		thisyear_growth, found_growth;
	
	void read() {
		Fund temp;
		printf("请输入代码："), cin >> temp.ID;
		printf("请输入名称："), cin >> temp.Name;
		printf("请输入英文："), cin >> temp.abbr; 
		printf("请输入日期："), cin >> temp.Time; 
		printf("请输入单位净值："), cin >> temp.unit_net; 
		printf("请输入累计净值："), cin >> temp.accumulated_net;
		printf("请输入日增长："), cin >> temp.day_growth; 
		printf("请输入近 1 周增长："), cin >> temp.week_growth; 
		printf("请输入近 1 月增长："), cin >> temp.month_growth; 
		printf("请输入近 3 月增长："), cin >> temp.quarter_growth; 
		printf("请输入近 6 月增长："), cin >> temp.hyear_growth; 
		printf("请输入近 1 年增长："), cin >> temp.year_growth; 
		printf("请输入近 2 年增长："), cin >> temp.year2_growth; 
		printf("请输入近 3 年增长："), cin >> temp.year3_growth; 
		printf("请输入今年来增长："), cin >> temp.thisyear_growth; 
		printf("请输入成立来增长："), cin >> temp.found_growth; 
		printf("请输入成立时间："), cin >> temp.established_time; 
		*this = temp;
	}
	
	void Print() {
		Fund temp = *this;
		printf("代码："), cout << temp.ID, putchar('\n');
		printf("名称："), cout << temp.Name, putchar('\n');
		printf("英文："), cout << temp.abbr, putchar('\n'); 
		printf("日期："), cout << temp.Time, putchar('\n'); 
		printf("单位净值："), cout << temp.unit_net, putchar('\n'); 
		printf("累计净值："), cout << temp.accumulated_net, putchar('\n');
		printf("日增长："), cout << temp.day_growth, putchar('\n'); 
		printf("近 1 周增长："), cout << temp.week_growth, putchar('\n'); 
		printf("近 1 月增长："), cout << temp.month_growth, putchar('\n'); 
		printf("近 3 月增长："), cout << temp.quarter_growth, putchar('\n'); 
		printf("近 6 月增长："), cout << temp.hyear_growth, putchar('\n'); 
		printf("近 1 年增长："), cout << temp.year_growth, putchar('\n'); 
		printf("近 2 年增长："), cout << temp.year2_growth, putchar('\n'); 
		printf("近 3 年增长："), cout << temp.year3_growth, putchar('\n'); 
		printf("今年来增长："), cout << temp.thisyear_growth, putchar('\n'); 
		printf("成立来增长："), cout << temp.found_growth, putchar('\n'); 
		printf("成立时间："), cout << temp.established_time, putchar('\n'); 
	}
	
	void PrintFast() {
		Fund Temp = *this;
		cout.setf(ios::left);
		cout << setw(6) << Temp.ID <<
			setw(32) << Temp.Name << 
			setw(16) << Temp.abbr << 
			setw(12) << Temp.Time <<
			setw(10) << Temp.unit_net << 
			setw(10) << Temp.accumulated_net <<
			setw(8) << Temp.day_growth << 
			setw(11) << Temp.week_growth << 
			setw(11) << Temp.month_growth <<
			setw(11) << Temp.quarter_growth <<
			setw(11) << Temp.hyear_growth << 
			setw(11) << Temp.year_growth <<
			setw(11) << Temp.year2_growth <<
			setw(11) << Temp.year3_growth << 
			setw(11) << Temp.thisyear_growth <<
			setw(11) << Temp.found_growth <<
			setw(12) << Temp.established_time << '\n';
	}
} Queue[N], Copy[N];

bool cmp1(Fund a, Fund b) {
	return a.found_growth > b.found_growth;
}

bool cmp2(Fund a, Fund b) {
	return a.thisyear_growth > b.thisyear_growth;
}

bool cmp3(Fund a, Fund b) {
	return a.year3_growth > b.year3_growth;
}

inline void PrintAll(Fund *Temp) {
	for (int i = 1; i <= cnt; ++i) Temp[i].PrintFast();
}

void Input() {
	++cnt;
	printf("第%d支基金\n", cnt);
	Queue[cnt].read();
	ID_map[Queue[cnt].ID] = cnt;
	Name_map[Queue[cnt].Name] = cnt;
	abbr_map[Queue[cnt].abbr] = cnt;
	return ;
} // 1

void Modify() {
	if (!cnt) return (void) (puts("当前没有可以修改的基金！"));
	string id;
	printf("请输入要修改的基金的代码：");
	while (1) {
		cin >> id;
		if (ID_map[id]) {
			Fund temp, Fix = Queue[ID_map[id]];
			puts("请输入要更改的部分（不变输入-1）"); 
			printf("请输入名称："), cin >> temp.Name;
			if (temp.Name != "-1") Fix.Name = temp.Name;
			printf("请输入英文："), cin >> temp.abbr; 
			if (temp.abbr != "-1") Fix.abbr = temp.abbr;
			printf("请输入日期："), cin >> temp.Time; 
			if (temp.Time != "-1") Fix.Time = temp.Time;
			printf("请输入单位净值："), cin >> temp.unit_net; 
			if (temp.unit_net != -1) Fix.unit_net = temp.unit_net;
			printf("请输入累计净值："), cin >> temp.accumulated_net;
			if (temp.accumulated_net != -1) Fix.accumulated_net = temp.accumulated_net;
			printf("请输入日增长："), cin >> temp.day_growth; 
			if (temp.day_growth != -1) Fix.day_growth = temp.day_growth;
			printf("请输入近 1 周增长："), cin >> temp.week_growth; 
			if (temp.week_growth != -1) Fix.week_growth = temp.week_growth;
			printf("请输入近 1 月增长："), cin >> temp.month_growth; 
			if (temp.month_growth != -1) Fix.month_growth = temp.month_growth;
			printf("请输入近 3 月增长："), cin >> temp.quarter_growth; 
			if (temp.quarter_growth != -1) Fix.quarter_growth = temp.quarter_growth;
			printf("请输入近 6 月增长："), cin >> temp.hyear_growth; 
			if (temp.hyear_growth != -1) Fix.hyear_growth = temp.hyear_growth;
			printf("请输入近 1 年增长："), cin >> temp.year_growth; 
			if (temp.year_growth != -1) Fix.year_growth = temp.year_growth;
			printf("请输入近 2 年增长："), cin >> temp.year2_growth; 
			if (temp.year2_growth != -1) Fix.year2_growth = temp.year2_growth;
			printf("请输入近 3 年增长："), cin >> temp.year3_growth; 
			if (temp.year3_growth != -1) Fix.year3_growth = temp.year3_growth;
			printf("请输入今年来增长："), cin >> temp.thisyear_growth; 
			if (temp.thisyear_growth != -1) Fix.thisyear_growth = temp.thisyear_growth;
			printf("请输入成立来增长："), cin >> temp.found_growth; 
			if (temp.found_growth != -1) Fix.found_growth = temp.found_growth;
			printf("请输入成立时间："), cin >> temp.established_time; 
			if (temp.established_time != "-1") Fix.established_time = temp.established_time;
			Queue[ID_map[id]] = Fix;
			break;
		}
		else printf("找不到此基金，请重新输入：");
	}
	return ;
} // 2

void Count() {
	if (!cnt) return (void) (puts("当前没有可以统计的基金！"));
	double value; 
	int opt1, opt2;
	puts("      请选择要统计的信息：");
	puts("      1. 日增长"); 
	puts("      2. 近 1 周增长"); 
	puts("      3. 近 1 月增长"); 
	puts("      4. 近 3 月增长"); 
	puts("      5. 近 6 月增长"); 
	puts("      6. 近 1 年增长"); 
	puts("      7. 近 3 年增长"); 
	puts("      8. 今年来增长"); 
	puts("      9. 成立来增长"); 
	puts("      0. 返回主菜单");
	opt1 = read();
	
	puts("      请输入要统计的收益率(value)：");
	cin >> value;
	
	puts("      请选择要显示的数据：");
	puts("      0. 收益率小于等于 value"); 
	puts("      1. 收益率大于等于 value");
	opt2 = read();
	
	if (!opt2) puts("收益率小于等于 value 的基金：");
	else puts("收益率大于等于 value 的基金：");
	
	cout.setf(ios::left);
	cout << setw(6) << "代码" << setw(32) << "名称" << 
			setw(16) << "英文" << setw(12) << "日期" <<
			setw(10) << "单位净值" << setw(10) << "累计净值" <<
			setw(8) << "日增长" << setw(11) << "近1周增长" << 
			setw(11) << "近1月增长" << setw(11) << "近3月增长" <<
			setw(11) << "近6月增长" << setw(11) << "近1年增长" <<
			setw(11) << "近2年增长" << setw(11) << "近2年增长" << 
			setw(11) << "今年来增长" << setw(11) << "成立来增长" <<
			setw(12) << "成立时间" << '\n';
	switch(opt1) {
		case 1: 
			for (int i = 1; i <= cnt; ++i) 
				if (!opt2) {
					if (Queue[i].day_growth <= value) 
						Queue[i].PrintFast();
				} else {
					if (Queue[i].day_growth >= value) 
						Queue[i].PrintFast();
				}
			break;
		case 2:
			for (int i = 1; i <= cnt; ++i) 
				if (!opt2) {
					if (Queue[i].week_growth <= value) 
						Queue[i].PrintFast();
				} else {
					if (Queue[i].week_growth >= value) 
						Queue[i].PrintFast();
				}
			break;
		case 3: 
			for (int i = 1; i <= cnt; ++i) 
				if (!opt2) {
					if (Queue[i].month_growth <= value) 
						Queue[i].PrintFast();
				} else {
					if (Queue[i].month_growth >= value) 
						Queue[i].PrintFast();
				}
			break;
		case 4: 
			for (int i = 1; i <= cnt; ++i) 
				if (!opt2) {
					if (Queue[i].quarter_growth <= value) 
						Queue[i].PrintFast();
				} else {
					if (Queue[i].quarter_growth >= value) 
						Queue[i].PrintFast();
				}
			break;
		case 5: 
			for (int i = 1; i <= cnt; ++i) 
				if (!opt2) {
					if (Queue[i].hyear_growth <= value) 
						Queue[i].PrintFast();
				} else {
					if (Queue[i].hyear_growth >= value) 
						Queue[i].PrintFast();
				}
			break;
		case 6: 
			for (int i = 1; i <= cnt; ++i) 
				if (!opt2) {
					if (Queue[i].year_growth <= value) 
						Queue[i].PrintFast();
				} else {
					if (Queue[i].year_growth >= value) 
						Queue[i].PrintFast();
				}
			break;
		case 7: 
			for (int i = 1; i <= cnt; ++i) 
				if (!opt2) {
					if (Queue[i].year3_growth <= value) 
						Queue[i].PrintFast();
				} else {
					if (Queue[i].year3_growth >= value) 
						Queue[i].PrintFast();
				}
			break;
		case 8: 
			for (int i = 1; i <= cnt; ++i) 
				if (!opt2) {
					if (Queue[i].thisyear_growth <= value) 
						Queue[i].PrintFast();
				} else {
					if (Queue[i].thisyear_growth >= value) 
						Queue[i].PrintFast();
				}
			break;
		case 9: 
			for (int i = 1; i <= cnt; ++i) 
				if (!opt2) {
					if (Queue[i].found_growth <= value) 
						Queue[i].PrintFast();
				} else {
					if (Queue[i].found_growth >= value) 
						Queue[i].PrintFast();
				}
			break;
		default: break;
	}
	return ;
} // 3

string s;

void Change(int i, string Copy, int opt) {
	if (opt >= 1 && opt <= 4) {
		if (opt == 1) Queue[i].ID = Copy;
		if (opt == 2) Queue[i].Name = Copy;
		if (opt == 3) Queue[i].abbr = Copy;
		if (opt == 4) Queue[i].Time = Copy;
		return ;
	}
	double Now = 0, f = 1, st = 0;
	if (Copy[0] == '-') ++st, f = -1;
	for (int j = st; j < Copy.size(); ++j) 
		if (Copy[j] == '.') {
			double a = 0, b = 0;
			for (int k = st; k < j; ++k)
				a = a * 10 + (Copy[k] - '0');
			for (int k = j + 1; k < Copy.size(); ++k) 
				b = b * 10 + (Copy[k] - '0');
			Now = a + b / pow(10, Copy.size() - j - 1);
			break;
		}
	switch(opt) {
		case 5: Queue[i].unit_net = Now; break;
		case 6: Queue[i].accumulated_net = Now; break;
		case 7: Queue[i].day_growth = Now; break;
		case 8: Queue[i].week_growth = Now; break;
		case 9: Queue[i].month_growth = Now; break;
		case 10: Queue[i].quarter_growth = Now; break;
		case 11: Queue[i].hyear_growth = Now; break;
		case 12: Queue[i].year_growth = Now; break;
		case 13: Queue[i].year2_growth = Now; break;
		case 14: Queue[i].year3_growth = Now; break;
		case 15: Queue[i].thisyear_growth = Now; break;
		case 16: Queue[i].found_growth = Now; break;
	}
	return ;
}
/*
1-4 string
其余 double 
*/ 

void Impart() {
	ifstream inFile;
	inFile.open("FundData.csv");
	
	getline(inFile, s);
	while (getline(inFile, s)) {
		++cnt;
		int Count = 0;
		int len = s.size(), lst = 0;
		for (int i = 0; i < len; ++i) {
			if (s[i] == ',') {
				++Count;
				string now = "";
				for (int j = lst; j < i; ++j) now += s[j];
				Change(cnt, now, Count);
				lst = i + 1;
			}
		}
		Queue[cnt].established_time = "";
		for (int i = lst; i < len; ++i) 
			Queue[cnt].established_time += s[i];
		ID_map[Queue[cnt].ID] = cnt;
		Name_map[Queue[cnt].Name] = cnt;
		abbr_map[Queue[cnt].abbr] = cnt;
	}
	inFile.close();
	return ;
} // 4

void FindID() {
	string id;
	printf("请输入要查询的基金代码："), cin >> id; 
	if (ID_map[id]) Queue[ID_map[id]].Print();
	else puts("找不到此基金！"); 
	return ;
} // 5

void FindName() {
	string Name;
	printf("请输入要查询的基金名称："), cin >> Name; 
	if (Name_map[Name]) Queue[Name_map[Name]].Print();
	else puts("找不到此基金！"); 
	return ;
} // 6

void Find_abbr() {
	string abbr;
	printf("请输入要查询的基金英文："), cin >> abbr; 
	if (abbr_map[abbr]) Queue[abbr_map[abbr]].Print();
	else puts("找不到此基金！"); 
	return ;
} // 7

void Export(Fund *TempQueue) {
	ofstream outFile;
	outFile.open("NewFundData.csv", ios::out | ios::trunc);
	outFile << "代码,名称,英文,日期,单位净值,累积净值," << 
		"日增长,近1周,近1月,近3月,近6月,近1年,近2年,近3年," << 
		"今年来,成立来,成立时间" << '\n';
	for (int i = 1; i <= cnt; ++i) {
		Fund Temp = TempQueue[i];
		outFile << Temp.ID << "," << Temp.Name << "," << 
			Temp.abbr << "," << Temp.Time << "," << 
			Temp.unit_net << "," << Temp.accumulated_net << "," << 
			Temp.day_growth << "," << Temp.week_growth << "," << 
			Temp.month_growth << "," << Temp.quarter_growth << "," <<
			Temp.hyear_growth << "," << Temp.year_growth << "," <<
			Temp.year2_growth << "," << Temp.year3_growth << "," << 
			Temp.thisyear_growth << "," << Temp.found_growth << "," <<
			Temp.established_time << '\n';
	}
	outFile.close();
} // 12

void found_sort() {
	for (int i = 1; i <= cnt; ++i) Copy[i] = Queue[i];
	sort(Copy + 1, Copy + cnt + 1, cmp1);
	Export(Copy), PrintAll(Copy);
} // 9

void this_year_sort() {
	for (int i = 1; i <= cnt; ++i) Copy[i] = Queue[i];
	sort(Copy + 1, Copy + cnt + 1, cmp2);
	Export(Copy), PrintAll(Copy);
} // 10

void year3_sort() {
	for (int i = 1; i <= cnt; ++i) Copy[i] = Queue[i];
	sort(Copy + 1, Copy + cnt + 1, cmp3);
	Export(Copy), PrintAll(Copy);
	
} // 11

int main()
{
	puts("***** 基 金 管 理 系 统 *****");
	puts("********             ********");
	puts("      1. 输入基金信息"); 
	puts("      2. 修改基金信息"); 
	puts("      3. 统计基金信息"); 
	puts("      4. 载入文件信息"); 
	puts("      5. 按照基金代码查询"); 
	puts("      6. 按照基金名称查询"); 
	puts("      7. 按照基金英文查询"); 
	puts("      8. 显示所有基金信息"); 
	puts("      9. 按基金成立来收益率排序显示并导出"); 
	puts("      10. 按基金今年来收益率排序显示并导出"); 
	puts("      11. 按基金近三年收益率排序显示并导出"); 
	puts("      12. 导出基金信息为表格"); 
	puts("      0. 结束程序"); 
	while (1) {
		int opt = read();
		switch(opt) {
			case 0: return 0; 
			case 1: Input(); break;
			case 2: Modify(); break;
			case 3: Count(); break;
			case 4: Impart(); break;
			case 5: FindID(); break;
			case 6: FindName(); break;
			case 7: Find_abbr(); break;
			case 8: PrintAll(Queue); break;
			case 9: found_sort(); break;
			case 10: this_year_sort(); break;
			case 11: year3_sort(); break;
			case 12: Export(Queue); break;
			default: break;
		}
	}
	return 0;
}

/*
基金管理系统
1输入：输入基金信息 
2修改：修改基金信息 
3统计：按要求统计基金信息
.eg 多少时间内的收益率，成立时间，净值
（有多少基金收益率大于多少 有多少基金成立时间早于balabala） 
4打开/保存：打开文件信息或将基金信息保存到文件 
5查询显示：按照一定的要求查询基金信息 
输入输出要有信息提示
要有文件存储
信息要足够全面
 
398	华富灵活配置混合	HFLHPZHH	2022/12/15	1.224	1.669	-1.77	2.77	11.07	15.58	17.92	18.49	23.95	46.45	18.72	83.28	2013/12/18

*/

