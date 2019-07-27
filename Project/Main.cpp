//﻿// Base64.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
//
//Base64 by SQMF PreAlpha 1.0
//已知問題:
//					encode無法輸入空格;
//					decode很多問題;
//進度:
//			cmd選單 90%
//			Encode  70%
//			Decode 40%
//			標題 50%
//			圖示 0%
//			GUI 0%
//
//
#include <bits/stdc++.h>
using namespace std;
void encode() {
	string base, bit6, bits6tmp, tmp, bits6;
	int len, aslen, bit8len, bit6len, conlen, conlen2, b = 0, c = 0, d, antmp;
	vector <int> ascii; vector <string> bit8; vector <string> convertbit; vector <int> final; vector <string> ans;
	cin >> base;
	antmp = base.size() % 3;
	len = base.length(); aslen = ascii.size(); bit8len = bit8.size();
	for (int i = 0; i < len; i++) { ascii.push_back(int(base[i])); aslen = ascii.size(); }
	for (int i = 0; i < aslen; i++) { bit8.push_back(bitset<8>(ascii[i]).to_string()); bit8len = bit8.size(); }
	for (int i = 0; i < bit8len; i++) {
		bit6len = bit6.size();
		bit6.insert(bit6len, bit8[i]);
	}
	conlen = bit6.size() / 6;
	conlen2 = bit6.size() % 6;
	if (bit6.size() % 6 != 0) { conlen++; }
	for (int i = 0; i < conlen; i++) {
		bits6tmp = bits6.assign(bit6, b, 6);
		convertbit.push_back(bits6tmp);
		b = b + 6;
	}
	tmp = convertbit.back();
	convertbit.pop_back();
	if (bit6.size() % 6 == 1) { tmp.insert(1, "00000"); }
	else if (bit6.size() % 6 == 2) { tmp.insert(2, "0000"); }
	else if (bit6.size() % 6 == 3) { tmp.insert(3, "000"); }
	else if (bit6.size() % 6 == 4) { tmp.insert(4, "00"); }
	else if (bit6.size() % 6 == 5) { tmp.insert(5, "0"); }
	convertbit.push_back(tmp);
	c = convertbit.size();
	for (int i = 0; i < c; i++) { final.push_back(stoi(convertbit[i], nullptr, 2)); }
	for (int i = 0; i < c; i++) {
		if (final[i] == 0) { ans.push_back("A"); }
		else if (final[i] == 1) { ans.push_back("B"); }
		else if (final[i] == 2) { ans.push_back("C"); }
		else if (final[i] == 3) { ans.push_back("D"); }
		else if (final[i] == 4) { ans.push_back("E"); }
		else if (final[i] == 5) { ans.push_back("F"); }
		else if (final[i] == 6) { ans.push_back("G"); }
		else if (final[i] == 7) { ans.push_back("H"); }
		else if (final[i] == 8) { ans.push_back("I"); }
		else if (final[i] == 9) { ans.push_back("J"); }
		else if (final[i] == 10) { ans.push_back("K"); }
		else if (final[i] == 11) { ans.push_back("L"); }
		else if (final[i] == 12) { ans.push_back("M"); }
		else if (final[i] == 13) { ans.push_back("N"); }
		else if (final[i] == 14) { ans.push_back("O"); }
		else if (final[i] == 15) { ans.push_back("P"); }
		else if (final[i] == 16) { ans.push_back("Q"); }
		else if (final[i] == 17) { ans.push_back("R"); }
		else if (final[i] == 18) { ans.push_back("S"); }
		else if (final[i] == 19) { ans.push_back("T"); }
		else if (final[i] == 20) { ans.push_back("U"); }
		else if (final[i] == 21) { ans.push_back("V"); }
		else if (final[i] == 22) { ans.push_back("W"); }
		else if (final[i] == 23) { ans.push_back("X"); }
		else if (final[i] == 24) { ans.push_back("Y"); }
		else if (final[i] == 25) { ans.push_back("Z"); }
		else if (final[i] == 26) { ans.push_back("a"); }
		else if (final[i] == 27) { ans.push_back("b"); }
		else if (final[i] == 28) { ans.push_back("c"); }
		else if (final[i] == 29) { ans.push_back("d"); }
		else if (final[i] == 30) { ans.push_back("e"); }
		else if (final[i] == 31) { ans.push_back("f"); }
		else if (final[i] == 32) { ans.push_back("g"); }
		else if (final[i] == 33) { ans.push_back("h"); }
		else if (final[i] == 34) { ans.push_back("i"); }
		else if (final[i] == 35) { ans.push_back("j"); }
		else if (final[i] == 36) { ans.push_back("k"); }
		else if (final[i] == 37) { ans.push_back("l"); }
		else if (final[i] == 38) { ans.push_back("m"); }
		else if (final[i] == 39) { ans.push_back("n"); }
		else if (final[i] == 40) { ans.push_back("o"); }
		else if (final[i] == 41) { ans.push_back("p"); }
		else if (final[i] == 42) { ans.push_back("q"); }
		else if (final[i] == 43) { ans.push_back("r"); }
		else if (final[i] == 44) { ans.push_back("s"); }
		else if (final[i] == 45) { ans.push_back("t"); }
		else if (final[i] == 46) { ans.push_back("u"); }
		else if (final[i] == 47) { ans.push_back("v"); }
		else if (final[i] == 48) { ans.push_back("w"); }
		else if (final[i] == 49) { ans.push_back("x"); }
		else if (final[i] == 50) { ans.push_back("y"); }
		else if (final[i] == 51) { ans.push_back("z"); }
		else if (final[i] == 52) { ans.push_back("0"); }
		else if (final[i] == 53) { ans.push_back("1"); }
		else if (final[i] == 54) { ans.push_back("2"); }
		else if (final[i] == 55) { ans.push_back("3"); }
		else if (final[i] == 56) { ans.push_back("4"); }
		else if (final[i] == 57) { ans.push_back("5"); }
		else if (final[i] == 58) { ans.push_back("6"); }
		else if (final[i] == 59) { ans.push_back("7"); }
		else if (final[i] == 60) { ans.push_back("8"); }
		else if (final[i] == 61) { ans.push_back("9"); }
		else if (final[i] == 62) { ans.push_back("+"); }
		else if (final[i] == 63) { ans.push_back("/"); }
	}
	d = ans.size();
	for (int i = 0; i < d; i++) { cout << ans[i]; }
	switch (antmp) {
	case(1):
		cout << "==" << "\n";
		break;
	case(2):
		cout << "=" << "\n";
		break;
	}

}
void decode() {
	int itmp = 0, lentmp;
	string input, stmp, allbintmp, allbin, final;
	vector <string> vecinput;
	vector <int> dec;
	vector <string> bin6;
	cin >> input;
	lentmp = input.length();
	for (int i = 0; i < lentmp; i++) {
		stmp = stmp.assign(input, itmp, 1);
		vecinput.push_back(stmp);
		itmp++;
	}
	for (int i = 0; i < vecinput.size(); i++) {
		if (vecinput[i] == "A") { dec.push_back(0); }
		else if (vecinput[i] == "B") { dec.push_back(1); }
		else if (vecinput[i] == "C") { dec.push_back(2); }
		else if (vecinput[i] == "D") { dec.push_back(3); }
		else if (vecinput[i] == "E") { dec.push_back(4); }
		else if (vecinput[i] == "F") { dec.push_back(5); }
		else if (vecinput[i] == "G") { dec.push_back(6); }
		else if (vecinput[i] == "H") { dec.push_back(7); }
		else if (vecinput[i] == "I") { dec.push_back(8); }
		else if (vecinput[i] == "J") { dec.push_back(9); }
		else if (vecinput[i] == "K") { dec.push_back(10); }
		else if (vecinput[i] == "L") { dec.push_back(11); }
		else if (vecinput[i] == "M") { dec.push_back(12); }
		else if (vecinput[i] == "N") { dec.push_back(13); }
		else if (vecinput[i] == "O") { dec.push_back(14); }
		else if (vecinput[i] == "P") { dec.push_back(15); }
		else if (vecinput[i] == "Q") { dec.push_back(16); }
		else if (vecinput[i] == "R") { dec.push_back(17); }
		else if (vecinput[i] == "S") { dec.push_back(18); }
		else if (vecinput[i] == "T") { dec.push_back(19); }
		else if (vecinput[i] == "U") { dec.push_back(20); }
		else if (vecinput[i] == "V") { dec.push_back(21); }
		else if (vecinput[i] == "W") { dec.push_back(22); }
		else if (vecinput[i] == "X") { dec.push_back(23); }
		else if (vecinput[i] == "Y") { dec.push_back(24); }
		else if (vecinput[i] == "Z") { dec.push_back(25); }
		else if (vecinput[i] == "a") { dec.push_back(26); }
		else if (vecinput[i] == "b") { dec.push_back(27); }
		else if (vecinput[i] == "c") { dec.push_back(28); }
		else if (vecinput[i] == "d") { dec.push_back(29); }
		else if (vecinput[i] == "e") { dec.push_back(30); }
		else if (vecinput[i] == "f") { dec.push_back(31); }
		else if (vecinput[i] == "g") { dec.push_back(32); }
		else if (vecinput[i] == "h") { dec.push_back(33); }
		else if (vecinput[i] == "i") { dec.push_back(34); }
		else if (vecinput[i] == "j") { dec.push_back(35); }
		else if (vecinput[i] == "k") { dec.push_back(36); }
		else if (vecinput[i] == "l") { dec.push_back(37); }
		else if (vecinput[i] == "m") { dec.push_back(38); }
		else if (vecinput[i] == "n") { dec.push_back(39); }
		else if (vecinput[i] == "o") { dec.push_back(40); }
		else if (vecinput[i] == "p") { dec.push_back(41); }
		else if (vecinput[i] == "q") { dec.push_back(42); }
		else if (vecinput[i] == "r") { dec.push_back(43); }
		else if (vecinput[i] == "s") { dec.push_back(44); }
		else if (vecinput[i] == "t") { dec.push_back(45); }
		else if (vecinput[i] == "u") { dec.push_back(46); }
		else if (vecinput[i] == "v") { dec.push_back(47); }
		else if (vecinput[i] == "w") { dec.push_back(48); }
		else if (vecinput[i] == "x") { dec.push_back(49); }
		else if (vecinput[i] == "y") { dec.push_back(50); }
		else if (vecinput[i] == "z") { dec.push_back(51); }
		else if (vecinput[i] == "0") { dec.push_back(52); }
		else if (vecinput[i] == "1") { dec.push_back(53); }
		else if (vecinput[i] == "2") { dec.push_back(54); }
		else if (vecinput[i] == "3") { dec.push_back(55); }
		else if (vecinput[i] == "4") { dec.push_back(56); }
		else if (vecinput[i] == "5") { dec.push_back(57); }
		else if (vecinput[i] == "6") { dec.push_back(58); }
		else if (vecinput[i] == "7") { dec.push_back(59); }
		else if (vecinput[i] == "8") { dec.push_back(60); }
		else if (vecinput[i] == "9") { dec.push_back(61); }
		else if (vecinput[i] == "+") { dec.push_back(62); }
		else if (vecinput[i] == "/") { dec.push_back(63); }
	}
	for (int i = 0; i < dec.size(); i++) {
		bin6.push_back(bitset<6>(dec[i]).to_string());
	}
	itmp = 0;
	for (int i = 0; i < bin6.size(); i++) {
		itmp = allbintmp.size();
		allbintmp.insert(itmp, bin6[i]);
	}
	itmp = 0;
	lentmp = allbintmp.size();
	switch (lentmp % 8) {
	case(1):
		itmp = lentmp - 1;
		allbin = allbin.append(allbintmp, 0, itmp);
		break;
	case(2):
		itmp = lentmp - 2;
		allbin = allbin.append(allbintmp, 0, itmp);
		break;
	case(3):
		itmp = lentmp - 3;
		allbin = allbin.append(allbintmp, 0, itmp);
		break;
	case(4):
		itmp = lentmp - 4;
		allbin = allbin.append(allbintmp, 0, itmp);
		break;
	case(5):
		itmp = lentmp - 5;
		allbin = allbin.append(allbintmp, 0, itmp);
		break;
	}
	itmp = 0;
	stringstream ans(allbin);
	while (ans.good())
	{
		bitset<8> bits;
		ans >> bits;
		char c = char(bits.to_ulong());
		final += c;
	}
	cout << final << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	system("title Base64 EncoderDecoder by SQMF");
	cout << "請選擇加密或解碼" << "\n";
	string Go, a;
	int b;
	for (int i = 0; i == 0; i = 0) {
		cout << "\n" << "----------" << "\n" << "| 1.加密 |" << "\n" << "| 2.解碼 |" << "\n" << "----------" << "\n";
		cin >> Go;
		if (Go != "1" && Go != "2") { b = 1; system("cls"); cout << "請輸入正確的數字(1或2)" << "\n"; }
		else if (Go == "2") { b = 0; system("cls");  cout << "請輸入你要解密的資料" << "\n"; decode(); }
		else if (Go == "1") { b = 0; system("cls"); cout << "請輸入你要加密的資料" << "\n"; encode(); }
		if (b == 0) {
			cout << "在一次??(y/n)" << "\n";
			for (int i = 0; i == 0; i = 0) {
				cin >> a;
				if (a == "y" || a == "Y") { system("cls"); break; }
				else if (a == "n" || a == "N") { break; }
				else { system("cls"); cout << "請輸入正確的字母(y或n)" << "\n"; }
			}
			if (a == "n" || a == "N") { break; }
		}
	}
	return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
