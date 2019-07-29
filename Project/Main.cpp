//Base64 Encoder&Decoder by SQMF(Cmd Version)
//			<<<<<Using UTF-8>>>>>
#include <string>
#include <vector>
#include<iostream>
#include<bitset>
#include<sstream>
using namespace std;
int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	system("title Base64 EncoderDecoder by SQMF");
	char* arg1 = argv[1];char* arg2 = argv[2];string input, tmp, bin,temp, output;int stmp = 0, Tmp;short int i3;
	if (argc <2) {
		cout << "使用方式 : base64 [-e|-d] [ \"Code\" ]\n\n-e    Encode\n\n-d    Decode\n\n範例:   base64 -e \"base64endecode\"\n        base64 -d \"base64endecode\"\n\n";
		return 0;
	}
	switch (arg1[1]) {
		case 'e':
			input = arg2;
			system("title Base64 Encode by SQMF");
			i3 = input.size() % 3;
			for (int i = 0; i < input.size(); i++) {
				stmp = int(input[i]);
				bin = bin + bitset<8>(stmp).to_string();
			}
			switch (bin.size() % 6) {
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
			}stmp = 0;
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
					cout << "Input Error(輸入錯誤)" << "\n\n";
					return 0;
				}
				tmp = char(Tmp);
				stmp = stmp + 6;
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
			cout << "\n" << "你的Base64加密:" << "\n" << output << "\n" << "\n";
			return 0;
		case 'd':
			input = arg2;
			for (int i = 0; i < 2; i++) {
				if (input[input.size() - 2] == '=') {
					temp = temp.assign(input, 0, input.size() - 2);
					input = temp;
					temp = "";
				}
				else if (input[input.size() - 1] == '=') {
					temp = temp.assign(input, 0, input.size() - 1);
					input = temp;
					temp = "";
				}
				else {
					break;
				}
			}
			for (size_t i = 0; i < input.size(); i++) {
				tmp = tmp.assign(input, stmp, 1);
				Tmp = (int)tmp[0];
				if (Tmp <= 90 && Tmp >= 65) {
					Tmp = Tmp - 65;
				}
				else if (Tmp <= 122 && Tmp >= 97) {
					Tmp = Tmp - 71;
				}
				else if (Tmp <= 57 && Tmp >= 48) {
					Tmp = Tmp + 4;
				}
				else if (Tmp == 43) {
					Tmp = 62;
				}
				else if (Tmp == 47) {
					Tmp = 63;
				}
				else {
					cout << "Input Error(輸入錯誤)" << "\n\n";
					return 0;
				}
				bin = bin + bitset<6>(Tmp).to_string();
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
			for (size_t i = 0; i < temp.size() / 8; i++) {
				tmp = tmp.assign(temp, stmp, 8);
				Tmp = stoi(tmp, nullptr, 2);
				tmp = char(Tmp);
				stmp = stmp + 8;
				output += tmp;
			}
			cout << "\n" << "你想要的東西:" << "\n" << output << "\n" << "\n";
			return 0;
		default:
			cout << "使用方式 : base64 [-e|-d] [ \"Code\" ]\n\n-e    Encode\n\n-d    Decode\n\n範例:   base64 -e \"base64endecode\"\n        base64 -d \"base64endecode\"\n\n";			return 0;
	}
}