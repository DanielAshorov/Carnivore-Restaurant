
// testDlg.h : header file
//

#pragma once

#include"Dish.h"

using namespace std;

// CtestDlg dialog
class CtestDlg : public CDialogEx
{
	// Construction
public:
	CtestDlg(CWnd* pParent = nullptr);	// standard constructor

	CTypedPtrArray <CObArray, Dish*> allItems;

	void RemoveAtIndex(int, int);
	void FillData();

	void ClearList();

	~CtestDlg()
	{
		ClearList();
	}

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

// Implementation
protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedBtnbuy();
	afx_msg void OnBnClickedBtnclear();
	afx_msg void OnLbnSelchangeListtobuy();
	afx_msg void OnStnClickedStatic7();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnStnClickedStatic13();
	afx_msg void OnStnClickedStatic14();
	afx_msg void OnStnClickedStatic15();
	afx_msg void OnStnClickedStatic16();
	afx_msg void OnStnClickedStatic17();
	afx_msg void OnStnClickedStatic12();
	afx_msg void OnStnClickedStatic18();
	afx_msg void OnStnClickedStatic10();
	afx_msg void OnStnClickedStatic9();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedBtnsave();
	afx_msg void OnBnClickedBtnload();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnStnClickedStatic19();
	afx_msg void OnBnClickedButton31();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnBnClickedButton32();
	afx_msg void OnBnClickedButton33();
	afx_msg void OnBnClickedButton34();
	afx_msg void OnStnClickedStatic20();
	afx_msg void OnBnClickedButton35();
	afx_msg void OnEnChangeEdit9();
	afx_msg void OnBnClickedButton36();
	afx_msg void OnBnClickedButton37();
	afx_msg void OnBnClickedButton38();
	afx_msg void OnBnClickedButton39();
	afx_msg void OnStnClickedStatic21();
	afx_msg void OnBnClickedButton40();
	afx_msg void OnEnChangeEdit10();
	afx_msg void OnBnClickedButton41();
	afx_msg void OnBnClickedButton42();
	afx_msg void OnBnClickedButton43();
	afx_msg void OnStnClickedStatic22();
	afx_msg void OnBnClickedButton44();
	afx_msg void OnEnChangeEdit11();
	afx_msg void OnBnClickedButton45();
	afx_msg void OnBnClickedButton46();
	afx_msg void OnBnClickedButton47();
	afx_msg void OnStnClickedStatic23();
	afx_msg void OnBnClickedButton48();
	afx_msg void OnEnChangeEdit12();
	afx_msg void OnBnClickedButton49();
	afx_msg void OnBnClickedButton50();

	double paymentSum;

	bool isAppetizerCarnivore = false;
	bool isCarnivoreCelebration = false;
	bool isDrinks = false;
	bool burger_220g = false;
	bool burger_440g = false;
	bool burger_660g = false;
	bool LambChops_220g = false;
	bool LambChops_440g = false;
	bool LambChops_660g = false;
	bool AngusSteak_220g = false;
	bool AngusSteak_440g = false;
	bool AngusSteak_660g = false;

	int FalafelCount;
	int KebabCount;
	int EggplantSaladCount;
	int WaterCount;
	int SoftDrinksCount;
	int	WineCount;
	int friesCount;
	int burgerCount;
	int burgerCount_220g = 0;
	int burgerCount_440g = 0;
	int burgerCount_660g = 0;
	int LambChopsCount_220g = 0;
	int LambChopsCount_440g = 0;
	int LambChopsCount_660g = 0;
	int LambChopsCount;
	int AngusSteakCount;
	int AngusSteakCount_220g = 0;
	int AngusSteakCount_440g = 0;
	int AngusSteakCount_660g = 0;

	CStatic Falafel_txt;
	CStatic kebab_txt;
	CStatic EggplantSalad_txt;
	CStatic Water_txt;
	CStatic SoftDrinks_txt;
	CStatic Wine_txt;
	CStatic fries_txt;
	CStatic burger_txt;
	CStatic AngusSteak_txt;
	CStatic burger220g_txt;
	CStatic burger440_txt;
	CStatic burger660_txt;
	CStatic LambChops220_txt;
	CStatic LambChops440_txt;
	CStatic LambChops660_txt;
	CStatic AngusSteak220_txt;
	CStatic AngusSteak440_txt;
	CStatic AngusSteak660_txt;
};