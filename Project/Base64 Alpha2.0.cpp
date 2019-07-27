//Base64 by SQMF Alpha 2.0
//已知問題:
//						我不知道(好像沒有)
//進度:
//			選單&標題&圖示 100%
//			Encode  90%
//			Decode 90%
//			GUI 0%
//			雙語言支持 0%
//Alpha 2.0 更新:
//								減少記憶體使用嗎??
//								減少vector的使用
//								新的運算方式(大大減少編譯時間;)
//								加入部份註解
#include "Icon.h" 
#include <bits/stdc++.h>
using namespace std;
void encode() {
	//優化Cin&Cout
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//標題
	system("title Base64 Encode by SQMF");
	//宣告變數區
	int stmp = 0, temp = 0;
	short int i3;
	string tmp, input, bin, output;
	vector <int> finaldec;
	//主程式開始
	//輸入Base64
	getline(cin, input);
	////////////////////
	temp = input.size();
	i3 = temp % 3;
	////////////////////
	//Input轉成Ascii , Ascii Dec轉Ascii Bin
	for (int i = 0; i < temp; i++) {
		stmp = int(input[i]);
		bin = bin + bitset<8>(stmp).to_string();
	}
	///////////////////
	temp = bin.size();
	stmp = temp % 6;
	///////////////////
	//如果全部的二進位不能被6整除的方案
	switch (stmp) {
	default:
		break;
	case 1:
		bin = bin + "00000";
		break;
	case 2:
		bin = bin + "0000";
		break;
	case 3:
		bin = bin + "000";
		break;
	case 4:
		bin = bin + "00";
		break;
	case 5:
		bin = bin + "0";
		break;
	}
	//////////
	stmp = 0;
	//////////

	for (int i = 0; i < bin.size() / 6; i++) {
		tmp = tmp.assign(bin, stmp, 6);
		finaldec.push_back(stoi(tmp, nullptr, 2));
		stmp = stmp + 6;
	}
	for (int i = 0; i < finaldec.size(); i++) {
		if (finaldec[i] <= 25 && finaldec[i] >= 0) {
			finaldec[i] = finaldec[i] + 65;
		}
		else if (finaldec[i] <= 51 && finaldec[i] >= 26) {
			finaldec[i] = finaldec[i] + 71;
		}
		else if (finaldec[i] <= 61 && finaldec[i] >= 52) {
			finaldec[i] = finaldec[i] - 4;
		}
		else if (finaldec[i] == 62) {
			finaldec[i] = 43;
		}
		else if (finaldec[i] == 63) {
			finaldec[i] = 47;
		}
		else {
			cout << "WtF Did You Enter??";
			return;
		}
	}
	for (int i = 0; i < finaldec.size(); i++) {
		tmp = char(finaldec[i]);
		output += tmp;
	}
	switch (i3) {
	case(1):
		output += "==";
		break;
	case(2):
		output += "=";
		break;
	default:
		break;
	}
	//輸出Base64
	cout << "\n" << "你的Base64加密:" << "\n" << output << "\n" << "\n";
	// XD
}
void decode() {
	//優化Cin&Cout
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//標題
	system("title Base64 Encode by SQMF");
	//宣告變數區(吃飽你的記憶體區)
	int Temp = 0;
	short int stmp = 0;
	string tmp, input, bin, output, temp;
	//主程式開始
	//輸入Base64
	getline(cin, input);
	for (int i = 0; i < input.size(); i++) {
		tmp = tmp.assign(input, stmp, 1);
		Temp = (int)tmp[0];
		if (Temp <= 90 && Temp >= 65) {
			Temp = Temp - 65;
		}
		else if (Temp <= 122 && Temp >= 97) {
			Temp = Temp - 71;
		}
		else if (Temp <= 57 && Temp >= 48) {
			Temp = Temp + 4;
		}
		else if (Temp == 43) {
			Temp = 62;
		}
		else if (Temp == 47) {
			Temp = 63;
		}
		else {
			cout << "WtF Did You Enter??" << "\n" << "Are you Serious??" << "\n";
			system("timeout 3");
			cout << "It's not a Base64 Code!!" << "\n";
			return;
		}
		bin = bin + bitset<6>(Temp).to_string();
		stmp++;
	}
	switch (bin.size() % 8) {
	case(1):
		temp = temp.append(bin, 0, bin.size() - 1);
		break;
	case(2):
		temp = temp.append(bin, 0, bin.size() - 2);
		break;
	case(3):
		temp = temp.append(bin, 0, bin.size() - 3);
		break;
	case(4):
		temp = temp.append(bin, 0, bin.size() - 4);
		break;
	case(5):
		temp = temp.append(bin, 0, bin.size() - 5);
		break;
	default:
		temp = temp.append(bin, 0, bin.size());
		break;
	}
	stmp = 0;
	for (int i = 0; i < temp.size() / 8; i++) {
		tmp = tmp.assign(temp, stmp, 8);
		Temp = stoi(tmp, nullptr, 2);
		tmp = char(Temp);
		stmp = stmp + 8;
		output += tmp;
	}
	cout << "\n" << "你想要的東西:" << "\n" << output << "\n" << "\n";
}
int main()
{
	//優化Cin&Cout
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//標題
	system("title Base64 EncoderDecoder by SQMF");
	//宣告變數區
	bool tmp = 1,main = 1;
	string option1, option2;
	//主程式開始
	cout << "請選擇加密或解碼" << "\n";
	while (main == true) {
		//選單
		cout << "\n" << "----------" << "\n" << "| 1.加密 |" << "\n" << "| 2.解碼 |" << "\n" << "----------" << "\n";
		//輸入選項
		getline(cin, option1);
		//輸入選項1進入Encode
		if (option1 == "1") {
			tmp = 1;
			system("cls");
			cout << "請輸入你要加密的資料" << "\n";
			encode();
		}  
		//輸入選項2進入Decode
		else if (option1 == "2") {
			tmp = 1;
			system("cls");
			cout << "請輸入你要解密的資料" << "\n";
			decode();
		}
		//輸入錯誤告知使用者
		else {
			tmp = 0;
			system("cls");
			cout << "請輸入正確的數字(1或2)" << "\n";
		}
		//結束後要不要再一次
		if (tmp == true) {
			cout << "再一次??(y/n)" << "\n";
			while (true) {
				getline(cin, option2);
				if (option2 == "y" || option2 == "Y") {
					system("cls");
					break;
				}
				else if (option2 == "n" || option2 == "N") {
					main = 0;
					break;
				}
				else {
					system("cls");
					cout << "請輸入正確的字母(y或n)" << "\n";
				}
			}
		}

	}
	//結束
	return 0;
}
