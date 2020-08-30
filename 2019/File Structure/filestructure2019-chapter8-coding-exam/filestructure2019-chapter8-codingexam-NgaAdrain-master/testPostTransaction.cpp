//학번: 201524582
//이름:	정희석
//github id: NgaAdrain
//19.5.21 coding  시험
//Modify method LedgerProcess::ProcessEndMaster 


#include <iostream>
#include <string.h>
#include "recfile.h"
#include "ledger.h"
#include "stdlib.h"
#include "length.h"
#include "ledgpost.h"

#define MAX_BUFFER 256

const int Month = 3; // processing for feb, march, april, jan(month = 0)
int main(void)
{
	//Initialization of Ledger//
	//계좌 번호 : 101 // 계좌 이름 // 2월 잔고 // 3월 잔고 // 4월 잔고 //
	Ledger L1(101, "Checking Account #1", 1032.57, 1032.57, 1032.57);
	Ledger L2(102, "Checking Account #2", 543.78, 543.78, 543.78);
	Ledger L3(505, "Advertising expense", 25.00, 25.00, 25.00);
	Ledger L4(510, "Auto expenses", 195.40, 195.40, 195.40);
	Ledger L5(515, "Bank charges", 0.00, 0.00, 0.00);
	Ledger L6(520, "Books and publications", 27.95, 27.95, 27.95);
	Ledger L7(525, "Interest expense", 103.50, 103.50, 103.50);
	Ledger L8(535, "Miscellaneous expense", 12.45, 12.45, 12.45);
	Ledger L9(540, "Office expense", 57.50, 57.50, 57.50);
	Ledger L10(545, "Postage and shipping", 21.00, 21.00, 21.00);
	Ledger L11(550, "Rent", 500.00, 500.00, 500.00);
	Ledger L12(555, "Supplies", 112.00, 112.00, 112.00);
	
	//Initialization of Journal//
	//계좌 번호 // check Number// 날짜 // 사용내역 // 사용금액//
	Journal J1(101, 1271, "02/02/86", "Auto expense", -78.70);
	Journal J2(101, 1271, "03/02/86", "Auto expense", -18.70);
	Journal J3(101, 1272, "03/02/97", "Rent", -50.00);
	Journal J4(101, 1272, "04/02/97", "Rent", -54.00);
	Journal J5(101, 1273, "04/04/97", "Advertising", -80.50);
	Journal J6(101, 1273, "02/04/97", "Advertising", -187.50);
	Journal J7(101, 1274, "02/02/97", "Auto expense", -30.83);
	Journal J8(101, 1274, "04/02/97", "Auto expense", -231.83);
	Journal J9(102, 670, "02/02/97", "Office expense", -382.78);
	Journal J10(102, 670, "03/02/97", "Office expense", -232.78);
	Journal J11(505, 1273, "02/04/97", "Newspaper ad re: new product", 827.50);
	Journal J12(505, 1273, "03/04/97", "Newspaper ad re: new product", 287.50);
	Journal J13(510, 1271, "02/02/97", "Tune up and minor repair", 178.70);
	Journal J14(510, 1274, "04/09/97", "Oil change", 131.83);
	Journal J15(510, 1271, "03/02/97", "Tune up and minor repair", 278.70);
	Journal J16(510, 1274, "04/09/97", "Oil change", 331.83);
	Journal J17(540, 670, "03/02/97", "Printer cartridge", 132.78);
	Journal J18(540, 670, "04/02/97", "Printer cartridge", 332.78);
	Journal J19(550, 1272, "02/02/97", "Rent for April", 50.00);
	Journal J20(550, 1272, "03/02/97", "Rent for April", 52.00);

	//==================//
	LengthFieldBuffer Lbuffer;
	RecordFile<Ledger> ledgerFile(Lbuffer);
	int result = ledgerFile.Create("ledger.dat", ios::out);
	cout << "Create file " << result << endl;
	if (!result)
	{
		cout << "Unable to Create file " << "ledger.dat" << endl;
		return 0;
	}
	ledgerFile.Write(L1);
	ledgerFile.Write(L2);
	ledgerFile.Write(L3);
	ledgerFile.Write(L4);
	ledgerFile.Write(L5);
	ledgerFile.Write(L6);
	ledgerFile.Write(L7);
	ledgerFile.Write(L8);
	ledgerFile.Write(L9);
	ledgerFile.Write(L10);
	ledgerFile.Write(L11);
	ledgerFile.Write(L12);
	ledgerFile.Close();
	//Ledger -> ledger.dat 작성
	LengthFieldBuffer Jbuffer;
	RecordFile<Journal> journalFile(Jbuffer);
	int flag = journalFile.Create("journal.dat", ios::out);
	cout << "Create file " << flag << endl;
	if (!flag)
	{
		cout << "Unable to Create file " << "journal.dat" << endl;
		return 0;
	}
	journalFile.Write(J1);
	journalFile.Write(J2);
	journalFile.Write(J3);
	journalFile.Write(J4);
	journalFile.Write(J5);
	journalFile.Write(J6);
	journalFile.Write(J7);
	journalFile.Write(J8);
	journalFile.Write(J9);
	journalFile.Write(J10);
	journalFile.Write(J11);
	journalFile.Write(J12);
	journalFile.Write(J13);
	journalFile.Write(J14);
	journalFile.Write(J15);
	journalFile.Write(J16);
	journalFile.Write(J17);
	journalFile.Write(J18);
	journalFile.Write(J19);
	journalFile.Write(J20);
	journalFile.Close();
	//journal -> journal.dat 작성
	int res;
	//============================//
	//계좌를 파일로 부터 읽어 들임
	RecordFile<Ledger> lFile(Lbuffer);
	lFile.Open("ledger.dat", ios::in);
	Ledger ledger;
	cout << "\nLEDGER INFO" << endl;
	cout << "Number " << "\t\tTitle\t " << "\t\tFeb"<< "\t\tMar" << "\t\tApr" <<endl;
	while (1)
	{
		res = lFile.Read(ledger);
		if (res <= 0) break;
		cout << "ledger" << endl;
		ledger.Print(cout);
	}
	lFile.Close();
	//============================//
	//사용내역을 파일로 부터 읽어 들임
	RecordFile<Journal> jFile(Jbuffer);
	jFile.Open("journal.dat", ios::in);
	Journal journal;
	cout << "\nJOURNAL INFO" << endl;
	cout << "Number\t \tCheck " << "\tDD/MM/YY\t " << "\t\tUSAGE\t" << "\tPrice" << endl;
	while (1)
	{
		res = jFile.Read(journal);
		if (res <= 0) break;
		journal.PrintLine(cout);
	}
	jFile.Close();
	cout << "Posting " << endl;
	LedgerProcess Posting(Month);
	//============================//
	/*
	Modify method LedgerProcess::ProcessEndMaster so it updates the ledger file 
	with the new account balances for month
	*/
	Posting.PostTransactions("ledger.dat", "journal.dat", "ledger.txt");
	// ====
	//여기에서 balance를 수정하는 process가 일어나야함!

	// ====
	//Modify to show the file ledger.txt

	//2. 이게 정상 작동하도록 고쳐야함!
	//ledger.txt로부터 읽어들여서 내용을 출력
	char ch;
	char inpBuf[MAX_BUFFER];
	cout << "\nREAD LEDGER&JOURNAL(ledger.txt) " << endl;
	fstream ledgerJournal;
	ledgerJournal.open("ledger.txt", ios::in);
	while (1) {
		//ledgerJournal >> ch; //한글자씩 읽어서 출력
		ledgerJournal.getline(inpBuf, MAX_BUFFER, '\n');
		if (ledgerJournal.fail()) break;
		//cout << ch;
		for (int i = 0; i < strlen(inpBuf); i++)
			cout << inpBuf[i];
		cout << endl;
	}
	cout << endl; //끝 체크
	//Modify to show ledger.Print();
	//3. 이게 정상 작동하도록 고쳐야함!
	//ledger.dat로부터 읽어들여서 내용을 출력
	cout << "\nREAD LEDGER(ledger.dat) " << endl;
	cout << "Showing the new account balances for the month"<< "\n" << endl;
	//RecordFile<Ledger> lFile(Lbuffer);
	//lFile.Open("ledger.dat", ios::in);
	//Ledger ledger;
	lFile.Open("ledger.dat", ios::in);
	while (1)//작동안하는듯 => lFile가 안닫혀서 open했을 때 마지막 부분에 포인터
	{	res = lFile.Read(ledger);//읽기 실패! -> 해결
		if (res <= 0) break;
		cout << "ledger" << endl;
		ledger.Print(cout);
	}
	lFile.Close();
	/*
	//============================//
	//계좌를 파일로 부터 읽어 들임
	RecordFile<Ledger> lFile(Lbuffer);
	lFile.Open("ledger.dat", ios::in);
	Ledger ledger;
	cout << "\nLEDGER INFO" << endl;
	cout << "Number " << "\t\tTitle\t " << "\t\tFeb"<< "\t\tMar" << "\t\tApr" <<endl;
	while (1)
	{
		res = lFile.Read(ledger);
		if (res <= 0) break;
		cout << "ledger" << endl;
		ledger.Print(cout);
	}
	*/
	system("pause");
	return 1;
}