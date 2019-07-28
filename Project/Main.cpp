//Base64 Encoder&Decoder by SQMF
//			<<<<<Using UTF-8>>>>>

//進度:
//			選單&標題&圖示&Encode&Decode 100%
//			GUI,雙語言支持 0%
//v0.1 更新:
//								沒有Vector!!
//								獨立Encode&Decode
//								看起來更裝逼
#include "Res/Icon.h" 
#include "Res/SQMF.h" 

int main()
{
	//優化Cin&Cout
	sqmf::power();
	//標題
	SetConsoleTitle("Base64 EncoderDecoder by SQMF");
	//宣告變數區
	bool tmp = 1, main=1;
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
			ClearConsloe();
			cout << "請輸入你要加密的資料" << "\n";
			sqmf::encode();
		}
		//輸入選項2進入Decode
		else if (option1 == "2") {
			tmp = 1;
			ClearConsloe();
			cout << "請輸入你要解密的資料" << "\n";
			sqmf::decode();
		}
		//輸入錯誤告知使用者
		else {
			tmp = 0;
			ClearConsloe();
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
