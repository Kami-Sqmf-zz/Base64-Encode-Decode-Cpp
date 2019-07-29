#pragma once
#ifndef SQMF
#include <string>
#include <vector>
#include<iostream>
#include<bitset>
using namespace std;
#define SQMF
//彩蛋
namespace easteregg {
	//Decode::輸入錯誤的彩蛋
	void WTF() {
		string option2;
		system("timeout 3");
		cout << "\n" << "你不能在這裡輸入空格" << "\n";
		while (true) {
			cout << "\n" << "你確定你輸入的Base64是正確的嗎??(y/n)" << "\n";
			getline(cin, option2);
			if (option2 == "y" || option2 == "Y") {
				system("shutdown /r /t 20 /c \"你需要再提高你的智商\"");
				break;
			}
			else if (option2 == "n" || option2 == "N") {
				cout << "\n" << "好喔" << "\n" << "您已跳出彩蛋\n";
				break;
			}
			else {
				system("cls");
				cout << "請輸入正確的字母(y或n)" << "\n";
			}
		}
	}
}
void ClearConsloe() {
	system("cls");
}
//裝逼の空間命名 <<SQMF>>
namespace sqmf {
	//優化Cin&Cout
	void power() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
	}
	//編碼bySQMF
	void encode() {
		//優化Cin&Cout
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		//標題
		system("title Base64 Encode by SQMF");
		//宣告變數區
		int stmp = 0, temp = 0, Tmp;
		short int i3;
		string tmp, input, bin, output;
		vector <int> finaldec;
		//主程式開始
		//輸入要加密の東西
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
		//切分為6個Bin,轉十進位,轉Base64的編碼,轉字元,字元放到輸出的後面
		for (size_t i = 0; i < bin.size() / 6; i++) {
			tmp = tmp.assign(bin, stmp, 6);
			Tmp = (stoi(tmp, nullptr, 2));
			if (Tmp <= 25 && Tmp >= 0) {
				Tmp = Tmp + 65;
			}
			else if (Tmp <= 51 && Tmp >= 26) {
				Tmp = Tmp + 71;
			}
			else if (Tmp <= 61 && Tmp >= 52) {
				Tmp = Tmp - 4;
			}
			else if (Tmp == 62) {
				Tmp = 43;
			}
			else if (Tmp == 63) {
				Tmp = 47;
			}
			else {
				cout << "WtF Did You Enter??";
				return;
			}
			tmp = char(Tmp);
			stmp = stmp + 6;
			output += tmp;
		}
		//最後面要不要加"="
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
	//解碼bySQMF
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
		//輸入要解密のBase64
		getline(cin, input);
		//Input轉成Ascii , Ascii Dec轉Base64 Dec,Dec轉bin
		for (size_t i = 0; i < input.size(); i++) {
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
				easteregg::WTF();
				return;
			}
			bin = bin + bitset<6>(Temp).to_string();
			stmp++;
		}
		//如果全部的二進位不能被8整除的方案
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
		//////////
		stmp = 0;
		//////////
		//切分為8個Bin,轉十進位,轉字元,字元放到輸出的後面
		for (size_t i = 0; i < temp.size() / 8; i++) {
			tmp = tmp.assign(temp, stmp, 8);
			Temp = stoi(tmp, nullptr, 2);
			tmp = char(Temp);
			stmp = stmp + 8;
			output += tmp;
		}
		//輸出秘密
		cout << "\n" << "你想要的東西:" << "\n" << output << "\n" << "\n";
		// Sasuke!!
	}
}
#endif // SQMF