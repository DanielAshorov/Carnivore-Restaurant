
// testDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"
#include "Dish.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtestDlg dialog

CtestDlg::CtestDlg(CWnd* pParent)
	: CDialogEx(IDD_TEST_DIALOG, pParent)
	, paymentSum(0)
	, FalafelCount(0)
	, KebabCount(0)
	, friesCount(0)
	, EggplantSaladCount(0)
	, WineCount(0)
	, burgerCount(0)
	, LambChopsCount(0)
	, burger_440g(FALSE)
	, burger_660g(FALSE)
	, AngusSteakCount(0)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestDlg::ClearList()
{
	for (int i = 0; i < allItems.GetSize(); i++)
	{
		delete allItems[i];
	}

	allItems.RemoveAll();
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, FalafelCount);
	DDX_Text(pDX, IDC_EDIT2, paymentSum);
	DDX_Text(pDX, IDC_EDIT3, friesCount);
	DDX_Text(pDX, IDC_EDIT5, burgerCount);
	DDX_Text(pDX, IDC_EDIT6, LambChopsCount);
	DDX_Text(pDX, IDC_EDIT7, AngusSteakCount);
	DDX_Text(pDX, IDC_EDIT8, KebabCount);
	DDX_Text(pDX, IDC_EDIT9, EggplantSaladCount);
	DDX_Text(pDX, IDC_EDIT10, WaterCount);
	DDX_Text(pDX, IDC_EDIT11, SoftDrinksCount);
	DDX_Text(pDX, IDC_EDIT12, WineCount);
	DDX_Control(pDX, IDC_STATIC4, Falafel_txt);
	DDX_Control(pDX, IDC_STATIC5, fries_txt);
	DDX_Control(pDX, IDC_STATIC7, burger_txt);
	DDX_Control(pDX, IDC_STATIC9, AngusSteak_txt);
	DDX_Control(pDX, IDC_STATIC10, burger220g_txt);
	DDX_Control(pDX, IDC_STATIC11, burger440_txt);
	DDX_Control(pDX, IDC_STATIC12, burger660_txt);
	DDX_Control(pDX, IDC_STATIC13, LambChops220_txt);
	DDX_Control(pDX, IDC_STATIC14, LambChops440_txt);
	DDX_Control(pDX, IDC_STATIC15, LambChops660_txt);
	DDX_Control(pDX, IDC_STATIC16, AngusSteak220_txt);
	DDX_Control(pDX, IDC_STATIC17, AngusSteak440_txt);
	DDX_Control(pDX, IDC_STATIC18, AngusSteak660_txt);
	DDX_Control(pDX, IDC_STATIC19, kebab_txt);
	DDX_Control(pDX, IDC_STATIC20, EggplantSalad_txt);
	DDX_Control(pDX, IDC_STATIC21, Water_txt);
	DDX_Control(pDX, IDC_STATIC22, SoftDrinks_txt);
	DDX_Control(pDX, IDC_STATIC23, Wine_txt);
}

BEGIN_MESSAGE_MAP(CtestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CtestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON10, &CtestDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &CtestDlg::OnBnClickedButton9)
	ON_EN_CHANGE(IDC_EDIT2, &CtestDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON6, &CtestDlg::OnBnClickedButton6)
	ON_EN_CHANGE(IDC_EDIT1, &CtestDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON7, &CtestDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON4, &CtestDlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT3, &CtestDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON5, &CtestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON11, &CtestDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CtestDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CtestDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON23, &CtestDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON25, &CtestDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON24, &CtestDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON15, &CtestDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON20, &CtestDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CtestDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON16, &CtestDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CtestDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CtestDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON22, &CtestDlg::OnBnClickedButton22)
	ON_EN_CHANGE(IDC_EDIT6, &CtestDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BtnBuy, &CtestDlg::OnBnClickedBtnbuy)
	ON_BN_CLICKED(IDC_BtnClear, &CtestDlg::OnBnClickedBtnclear)
	ON_LBN_SELCHANGE(IDC_ListToBuy, &CtestDlg::OnLbnSelchangeListtobuy)
	ON_STN_CLICKED(IDC_STATIC7, &CtestDlg::OnStnClickedStatic7)
	ON_EN_CHANGE(IDC_EDIT5, &CtestDlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_CHECK4, &CtestDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CtestDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK3, &CtestDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK1, &CtestDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CtestDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK6, &CtestDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &CtestDlg::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CtestDlg::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &CtestDlg::OnBnClickedCheck9)
	ON_EN_CHANGE(IDC_EDIT7, &CtestDlg::OnEnChangeEdit7)
	ON_STN_CLICKED(IDC_STATIC9, &CtestDlg::OnStnClickedStatic9)
	ON_STN_CLICKED(IDC_STATIC10, &CtestDlg::OnStnClickedStatic10)
	ON_STN_CLICKED(IDC_STATIC12, &CtestDlg::OnStnClickedStatic12)
	ON_STN_CLICKED(IDC_STATIC13, &CtestDlg::OnStnClickedStatic13)
	ON_STN_CLICKED(IDC_STATIC14, &CtestDlg::OnStnClickedStatic14)
	ON_STN_CLICKED(IDC_STATIC15, &CtestDlg::OnStnClickedStatic15)
	ON_STN_CLICKED(IDC_STATIC16, &CtestDlg::OnStnClickedStatic16)
	ON_STN_CLICKED(IDC_STATIC17, &CtestDlg::OnStnClickedStatic17)
	ON_STN_CLICKED(IDC_STATIC18, &CtestDlg::OnStnClickedStatic18)
	ON_BN_CLICKED(IDC_BUTTON28, &CtestDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON27, &CtestDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON19, &CtestDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BtnSave, &CtestDlg::OnBnClickedBtnsave)
	ON_BN_CLICKED(IDC_BtnLoad, &CtestDlg::OnBnClickedBtnload)
	ON_STN_CLICKED(IDC_STATIC19, &CtestDlg::OnStnClickedStatic19)
	ON_BN_CLICKED(IDC_BUTTON31, &CtestDlg::OnBnClickedButton31)
	ON_EN_CHANGE(IDC_EDIT8, &CtestDlg::OnEnChangeEdit8)
	ON_BN_CLICKED(IDC_BUTTON32, &CtestDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON33, &CtestDlg::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON34, &CtestDlg::OnBnClickedButton34)
	ON_STN_CLICKED(IDC_STATIC20, &CtestDlg::OnStnClickedStatic20)
	ON_BN_CLICKED(IDC_BUTTON35, &CtestDlg::OnBnClickedButton35)
	ON_EN_CHANGE(IDC_EDIT9, &CtestDlg::OnEnChangeEdit9)
	ON_BN_CLICKED(IDC_BUTTON36, &CtestDlg::OnBnClickedButton36)
	ON_BN_CLICKED(IDC_BUTTON37, &CtestDlg::OnBnClickedButton37)
	ON_BN_CLICKED(IDC_BUTTON38, &CtestDlg::OnBnClickedButton38)
	ON_BN_CLICKED(IDC_BUTTON39, &CtestDlg::OnBnClickedButton39)
	ON_STN_CLICKED(IDC_STATIC21, &CtestDlg::OnStnClickedStatic21)
	ON_BN_CLICKED(IDC_BUTTON40, &CtestDlg::OnBnClickedButton40)
	ON_EN_CHANGE(IDC_EDIT10, &CtestDlg::OnEnChangeEdit10)
	ON_BN_CLICKED(IDC_BUTTON41, &CtestDlg::OnBnClickedButton41)
	ON_BN_CLICKED(IDC_BUTTON42, &CtestDlg::OnBnClickedButton42)
	ON_BN_CLICKED(IDC_BUTTON43, &CtestDlg::OnBnClickedButton43)
	ON_STN_CLICKED(IDC_STATIC22, &CtestDlg::OnStnClickedStatic22)
	ON_BN_CLICKED(IDC_BUTTON44, &CtestDlg::OnBnClickedButton44)
	ON_EN_CHANGE(IDC_EDIT11, &CtestDlg::OnEnChangeEdit11)
	ON_BN_CLICKED(IDC_BUTTON45, &CtestDlg::OnBnClickedButton45)
	ON_BN_CLICKED(IDC_BUTTON46, &CtestDlg::OnBnClickedButton46)
	ON_BN_CLICKED(IDC_BUTTON47, &CtestDlg::OnBnClickedButton47)
	ON_STN_CLICKED(IDC_STATIC23, &CtestDlg::OnStnClickedStatic23)
	ON_BN_CLICKED(IDC_BUTTON48, &CtestDlg::OnBnClickedButton48)
	ON_EN_CHANGE(IDC_EDIT12, &CtestDlg::OnEnChangeEdit12)
	ON_BN_CLICKED(IDC_BUTTON49, &CtestDlg::OnBnClickedButton49)
	ON_BN_CLICKED(IDC_BUTTON50, &CtestDlg::OnBnClickedButton50)
END_MESSAGE_MAP()

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE unless you set the focus to a control
}

void CtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CtestDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON6)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON7)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC4)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON12)->ShowWindow(TRUE);
	UpdateData(FALSE);

}

void CtestDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_STATIC5)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON5)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON13)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
	UpdateData(FALSE);
}


//////////////////////kebab//////////////////////
void CtestDlg::OnBnClickedButton10()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_STATIC19)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON31)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON32)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON33)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT8)->ShowWindow(TRUE);
	UpdateData(FALSE);
}

void CtestDlg::OnStnClickedStatic19()
{
}

////////////////////Eggplant salad////////////////////////
void CtestDlg::OnBnClickedButton34()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_STATIC20)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON35)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON36)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON37)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT9)->ShowWindow(TRUE);
	UpdateData(FALSE);
}

void CtestDlg::OnStnClickedStatic20()
{
}

void CtestDlg::OnEnChangeEdit2()
{
}

void CtestDlg::OnBnClickedButton9()
{
	UpdateData(TRUE);
	if (isAppetizerCarnivore == false)
	{
		GetDlgItem(IDC_BUTTON1)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON10)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON34)->ShowWindow(TRUE);
		isAppetizerCarnivore = true;
	}
	else if (isAppetizerCarnivore == true)
	{
		GetDlgItem(IDC_BUTTON1)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON10)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON34)->ShowWindow(TRUE);
		isAppetizerCarnivore = false;
	}
	UpdateData(FALSE);
}

void CtestDlg::OnBnClickedButton6()             //remove Falafel button
{
	UpdateData(TRUE);
	int i;
	Falafel *falafel = new Falafel;
	for (i = 0; i < allItems.GetSize(); i++)
	{
		if (allItems[i]->getPrice() == falafel->getPrice())
			break;
	}
		
	if (FalafelCount == 0)
		FalafelCount = 0;
	else if (FalafelCount > 0)
	{
		allItems.RemoveAt(i);
		FalafelCount--;
		paymentSum -= falafel->getPrice();
	}
	UpdateData(FALSE);
}


void CtestDlg::OnEnChangeEdit1()
{
}


void CtestDlg::OnBnClickedButton7()                // add Falafel button
{
	Falafel *falafel = new Falafel;
	allItems.Add(falafel);
	UpdateData(TRUE);
	FalafelCount++;
	paymentSum += falafel->getPrice();
	UpdateData(FALSE);
}

///////////////////////////////////////////////////////////////////////////////////////////
void CtestDlg::OnBnClickedButton31()             //remove kebab button
{
	UpdateData(TRUE);
	int i;
	Kebab *kebab = new Kebab;
	for (i = 0; i < allItems.GetSize(); i++)
	{
		if (allItems[i]->getPrice() == kebab->getPrice())
			break;
	}

	if (KebabCount == 0)
		KebabCount = 0;
	else if (KebabCount > 0)
	{
		allItems.RemoveAt(i);
		KebabCount--;
		paymentSum -= kebab->getPrice();
	}
	UpdateData(FALSE);
}


void CtestDlg::OnEnChangeEdit8()
{
}


void CtestDlg::OnBnClickedButton32()                // add kebab button
{
	Kebab *kebab = new Kebab;
	allItems.Add(kebab);
	UpdateData(TRUE);
	KebabCount++;
	paymentSum += kebab->getPrice();
	UpdateData(FALSE);
}

///////////////////////////////Eggplant salad/////////////////////////////////////////////////
void CtestDlg::OnBnClickedButton35()             //remove EggplantSalad button
{
	UpdateData(TRUE);
	int i;
	EggplantSalad *eggplantSalad = new EggplantSalad;
	for (i = 0; i < allItems.GetSize(); i++)
	{
		if (allItems[i]->getPrice() == eggplantSalad->getPrice())
			break;
	}

	if (EggplantSaladCount == 0)
		EggplantSaladCount = 0;
	else if (EggplantSaladCount > 0)
	{
		allItems.RemoveAt(i);
		EggplantSaladCount--;
		paymentSum -= eggplantSalad->getPrice();
	}
	UpdateData(FALSE);
}

void CtestDlg::OnEnChangeEdit9()
{
}


void CtestDlg::OnBnClickedButton36()                // add EggplantSalad button
{
	EggplantSalad *eggplantSalad = new EggplantSalad;
	allItems.Add(eggplantSalad);
	UpdateData(TRUE);
	EggplantSaladCount++;
	paymentSum += eggplantSalad->getPrice();
	UpdateData(FALSE);
}

//////////////////////////////////////////////////////////////////////////////////////////////
void CtestDlg::OnBnClickedButton4()              // remove fries button
{
	int i;
	Fries *fries = new Fries;
	UpdateData(TRUE);
	for (i = 0; i < allItems.GetSize(); i++) {
		if (allItems[i]->getPrice() == fries->getPrice())
			break;
	}
	if (friesCount > 0)
	{
		allItems.RemoveAt(i);
		friesCount--;
		paymentSum -= fries->getPrice();
	}
	else if (friesCount == 0)
		friesCount = 0;
	UpdateData(FALSE);
}

void CtestDlg::OnEnChangeEdit3()
{
}


void CtestDlg::OnBnClickedButton5()               //add Fries and Salad button
{
	Fries *fries = new Fries;
	UpdateData(TRUE);
	allItems.Add(fries);
	friesCount++;
	paymentSum += fries->getPrice();
	UpdateData(FALSE);
}
 
void CtestDlg::OnBnClickedButton11()
{
	if (allItems.GetSize() == 0) {
		MessageBox(_T("No Order! Please select a product."), _T("Alert!"));
	}
	else {
		MessageBox(_T("Thank you for your order! Enjoy your meal.\n "), _T(""));
		AfxGetMainWnd()->SendMessage(WM_CLOSE);
	}

}

void CtestDlg::OnBnClickedButton12()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON6)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC4)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON12)->ShowWindow(FALSE);
	UpdateData(FALSE);
}

void CtestDlg::OnBnClickedButton13()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON5)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC5)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON13)->ShowWindow(FALSE);
	UpdateData(FALSE);
}

void CtestDlg::OnBnClickedButton33()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON31)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON32)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC19)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON33)->ShowWindow(FALSE);
	UpdateData(FALSE);
}

///////////////////////////////eggplant salad/////////////////////////////
void CtestDlg::OnBnClickedButton37()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON35)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON36)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT9)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC20)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON37)->ShowWindow(FALSE);
	UpdateData(FALSE);
}
//////////////////////////////////////////////////////////////////////////

void CtestDlg::OnBnClickedButton23()             //add Lamb Chops button
{
	UpdateData(TRUE);
	LambChops *chops = new LambChops;
	if (LambChops_440g == true)
	{
		LambChopsCount++;
		LambChopsCount_440g++;
		chops->setPrice(120);
		chops->setGram(440);
	}
	else if (LambChops_660g == true)
	{
		LambChopsCount++;
		LambChopsCount_660g++;
		chops->setPrice(140);
		chops->setGram(660);
	}
	else if (LambChops_220g == true)
	{
		LambChopsCount++;
		LambChopsCount_220g++;
		chops->setPrice(100);
		chops->setGram(220);
	}

	allItems.Add(chops);
	paymentSum += chops->getPrice();
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedButton25()
{
	UpdateData(TRUE);
	AngusSteak *steak = new AngusSteak;
	if (AngusSteak_440g == true)
	{
		AngusSteakCount++;
		AngusSteakCount_440g++;
		steak->setPrice(130);
		steak->setGram(440);
	}
	else if (AngusSteak_660g == true)
	{
		AngusSteakCount++;
		AngusSteakCount_660g++;
		steak->setPrice(150);
		steak->setGram(660);
	}
	else if (AngusSteak_220g == true)
	{
		AngusSteakCount++;
		AngusSteakCount_220g++;
		steak->setPrice(110);
		steak->setGram(220);
	}

	allItems.Add(steak);
	paymentSum += steak->getPrice();
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedButton24()
{
	int i, tempCount = 0;
	AngusSteak *steak = new AngusSteak;

	if (AngusSteak_220g == true && AngusSteakCount_220g > 0)
	{
		tempCount = AngusSteakCount_220g;
		steak->setPrice(110);
		if (AngusSteakCount > 0)
			AngusSteakCount--;
		else if (AngusSteakCount == 0)
			AngusSteakCount = 0;
		if (AngusSteakCount_220g > 0)
		{
			AngusSteakCount_220g--;
			paymentSum -= steak->getPrice();
		}
		else if (AngusSteakCount_220g == 0)
			AngusSteakCount_220g = 0;

	}
	else if (AngusSteak_440g == true && AngusSteakCount_440g > 0)
	{
		tempCount = AngusSteakCount_440g;
		steak->setPrice(130);
		if (AngusSteakCount > 0)
			AngusSteakCount--;
		else if (AngusSteakCount == 0)
			AngusSteakCount = 0;
		if (AngusSteakCount_440g > 0)
		{
			AngusSteakCount_440g--;
			paymentSum -= steak->getPrice();
		}
		else if (AngusSteakCount_440g == 0)
			AngusSteakCount_440g = 0;
	}
	else if (AngusSteak_660g == true && AngusSteakCount_660g > 0)
	{
		tempCount = AngusSteakCount_660g;
		steak->setPrice(150);
		if (AngusSteakCount > 0)
			AngusSteakCount--;
		else if (AngusSteakCount == 0)
			AngusSteakCount = 0;
		if (AngusSteakCount_660g > 0)
		{
			AngusSteakCount_660g--;
			paymentSum -= steak->getPrice();
		}
		else if (AngusSteakCount_660g == 0)
			AngusSteakCount_660g = 0;
	}

	for (i = 0; i < allItems.GetSize(); i++)
	{
		if (allItems[i]->getPrice() == steak->getPrice())
			break;
	}

	RemoveAtIndex(tempCount, i);

	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedButton15()
{
	UpdateData(TRUE);
	if (isCarnivoreCelebration == false)
	{
		GetDlgItem(IDC_BUTTON16)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON17)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON18)->ShowWindow(TRUE);
		isCarnivoreCelebration = true;
	}
	else if (isCarnivoreCelebration == true)
	{
		GetDlgItem(IDC_BUTTON16)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON17)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON18)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON19)->ShowWindow(FALSE);
		isCarnivoreCelebration = false;
	}
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedButton20()
{
	UpdateData(TRUE);
	int i, tempCount = 0;
	Hamburger *burger = new Hamburger;

	if (burger_220g == true && burgerCount_220g > 0)
	{
		tempCount = burgerCount_220g;
		burger->setPrice(80);
		if (burgerCount > 0)
		burgerCount--;
		else if (burgerCount == 0)
			burgerCount = 0;
		if (burgerCount_220g > 0)
		{
			burgerCount_220g--;
			paymentSum -= burger->getPrice();
		}
		else if(burgerCount_220g == 0)
			burgerCount_220g = 0;

	}
	else if (burger_440g == true && burgerCount_440g > 0)
	{
		tempCount = burgerCount_440g;
		burger->setPrice(100);
		if (burgerCount > 0)
			burgerCount--;
		else if (burgerCount == 0)
			burgerCount = 0;
		if (burgerCount_440g > 0)
		{
			burgerCount_440g--;
			paymentSum -= burger->getPrice();
		}
		else if (burgerCount_440g == 0)
			burgerCount_440g = 0;
	}
	else if (burger_660g == true && burgerCount_660g > 0)
	{
		tempCount = burgerCount_660g;
		burger->setPrice(120);
		if (burgerCount > 0)
			burgerCount--;
		else if (burgerCount == 0)
			burgerCount = 0;
		if (burgerCount_660g > 0)
		{
			burgerCount_660g--;
			paymentSum -= burger->getPrice();
		}
		else if (burgerCount_660g == 0)
			burgerCount_660g = 0;
	}

	for (i = 0; i < allItems.GetSize(); i++)
	{
		if (allItems[i]->getPrice() == burger->getPrice())
			break;
	}
	RemoveAtIndex(tempCount, i);
	UpdateData(FALSE);
}

void CtestDlg::RemoveAtIndex(int temp, int i) {
	if (temp > 0)
		allItems.RemoveAt(i);
}

void CtestDlg::OnBnClickedButton21()
{
	UpdateData(TRUE);
	Hamburger *burger = new Hamburger;
	if (burger_440g == true)
	{
		burgerCount++;
		burgerCount_440g++;
		burger->setPrice(100);
		burger->setGram(440);
	}
	else if (burger_660g == true)
	{
		burgerCount++;
		burgerCount_660g++;
		burger->setPrice(120);
		burger->setGram(660);
	}
	else if(burger_220g == true)
	{
		burgerCount++;
		burgerCount_220g++;
		burger->setPrice(80);
		burger->setGram(220);
	}
	
	allItems.Add(burger);
	paymentSum += burger->getPrice();
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedButton16()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_STATIC7)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC10)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC11)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC12)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON19)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON20)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON21)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK3)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK4)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK5)->ShowWindow(TRUE);
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedButton17()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_STATIC8)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC13)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC14)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC15)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON22)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON23)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON28)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT6)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK1)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK2)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK6)->ShowWindow(TRUE);
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedButton18()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_STATIC9)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC16)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC17)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC18)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON24)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON25)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON27)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT7)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK7)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK8)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK9)->ShowWindow(TRUE);
	UpdateData(FALSE);
}

void CtestDlg::OnBnClickedButton22()              // remove Lamb Chops burger button
{
	UpdateData(TRUE);
	int i, tempCount = 0;
	Hamburger *chops = new Hamburger;

	if (LambChops_220g == true && LambChopsCount_220g > 0)
	{
		tempCount = LambChopsCount_220g;
		chops->setPrice(100);
		if (LambChopsCount > 0)
			LambChopsCount--;
		else if (LambChopsCount == 0)
			LambChopsCount = 0;
		if (LambChopsCount_220g > 0)
		{
			LambChopsCount_220g--;
			paymentSum -= chops->getPrice();
		}
		else if (LambChopsCount_220g == 0)
			LambChopsCount_220g = 0;

	}
	else if (LambChops_440g == true && LambChopsCount_440g > 0)
	{
		tempCount = LambChopsCount_440g;
		chops->setPrice(120);
		if (LambChopsCount > 0)
			LambChopsCount--;
		else if (LambChopsCount == 0)
			LambChopsCount = 0;
		if (LambChopsCount_440g > 0)
		{
			LambChopsCount_440g--;
			paymentSum -= chops->getPrice();
		}
		else if (LambChopsCount_440g == 0)
			LambChopsCount_440g = 0;
	}
	else if (LambChops_660g == true && LambChopsCount_660g > 0)
	{
		tempCount = LambChopsCount_660g;
		chops->setPrice(140);
		if (LambChopsCount > 0)
			LambChopsCount--;
		else if (LambChopsCount == 0)
			LambChopsCount = 0;
		if (LambChopsCount_660g > 0)
		{
			LambChopsCount_660g--;
			paymentSum -= chops->getPrice();
		}
		else if (LambChopsCount_660g == 0)
			LambChopsCount_660g = 0;
	}

	for (i = 0; i < allItems.GetSize(); i++)
	{
		if (allItems[i]->getPrice() == chops->getPrice())
			break;
	}

	if (tempCount > 0)
		allItems.RemoveAt(i);
	UpdateData(FALSE);
}


void CtestDlg::OnEnChangeEdit6()
{
}

void CtestDlg::FillData() 
{
	CListBox* list = (CListBox*)GetDlgItem(IDC_ListToBuy);
	list->ResetContent();
	for (int i = 0; i < allItems.GetSize(); i++) {
		char *strData = allItems[i]->getRecietData();
		CString str(strData);
		delete strData;
		list->AddString(str);
	}
}

void CtestDlg::OnBnClickedBtnbuy()
{
	FillData();
}


void CtestDlg::OnBnClickedBtnclear()
{
	UpdateData(TRUE);
	CListBox* list = (CListBox*)GetDlgItem(IDC_ListToBuy);
	list->ResetContent();
	paymentSum = 0;
	burgerCount = 0;
	burgerCount_220g = 0;
	burgerCount_440g = 0;
	burgerCount_660g = 0;
	friesCount = 0;
	FalafelCount = 0;
	KebabCount = 0;
	WaterCount = 0;
	SoftDrinksCount = 0;
	EggplantSaladCount = 0;
	WineCount = 0;
	LambChopsCount = 0;
	LambChopsCount_220g = 0;
	LambChopsCount_440g = 0;
	LambChopsCount_660g = 0;
	AngusSteakCount = 0;
	AngusSteakCount_220g = 0;
	AngusSteakCount_440g = 0;
	AngusSteakCount_660g = 0;

	this->ClearList();
	UpdateData(FALSE);

}

void CtestDlg::OnLbnSelchangeListtobuy()
{
}

void CtestDlg::OnStnClickedStatic7()
{
}


void CtestDlg::OnEnChangeEdit5()
{
}

void CtestDlg::OnBnClickedCheck4()
{
	UpdateData(TRUE);
	if (burger_440g == false)
	{
		burger_440g = true;
		burger_660g = false;
		burger_220g = false;
		CheckDlgButton(IDC_CHECK3, FALSE);
		CheckDlgButton(IDC_CHECK5, FALSE);
	}
	else if (burger_440g == true)
		burger_440g = false;
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedCheck5()
{
	UpdateData(TRUE);
	if (burger_660g == false)
	{
		burger_660g = true;
		burger_440g = false;
		burger_220g = false;
		CheckDlgButton(IDC_CHECK3, FALSE);
		CheckDlgButton(IDC_CHECK4, FALSE);
	}
	else if (burger_660g == true)
		burger_660g = false;
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedCheck3()
{
	UpdateData(TRUE);
	if (burger_220g == false)
	{
		burger_220g = true;
		burger_440g = false;
		burger_660g = false;
		CheckDlgButton(IDC_CHECK4, FALSE);
		CheckDlgButton(IDC_CHECK5, FALSE);
	}
	else if (burger_220g == true)
		burger_220g = false;
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedCheck1()
{
	UpdateData(TRUE);
	if (LambChops_220g == false)
	{
		LambChops_220g = true;
		LambChops_440g = false;
		LambChops_660g = false;
		CheckDlgButton(IDC_CHECK2, FALSE);
		CheckDlgButton(IDC_CHECK6, FALSE);
	}
	else if (LambChops_220g == true)
		LambChops_220g = false;
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedCheck2()
{
	UpdateData(TRUE);
	if (LambChops_440g == false)
	{
		LambChops_220g = false;
		LambChops_440g = true;
		LambChops_660g = false;
		CheckDlgButton(IDC_CHECK1, FALSE);
		CheckDlgButton(IDC_CHECK6, FALSE);
	}
	else if (LambChops_440g == true)
		LambChops_440g = false;
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedCheck6()
{
	UpdateData(TRUE);
	if (LambChops_660g == false)
	{
		LambChops_220g = false;
		LambChops_440g = false;
		LambChops_660g = true;
		CheckDlgButton(IDC_CHECK2, FALSE);
		CheckDlgButton(IDC_CHECK1, FALSE);
	}
	else if (LambChops_660g == true)
		LambChops_660g = false;
	UpdateData(FALSE);
}



void CtestDlg::OnBnClickedCheck7()
{
	UpdateData(TRUE);
	if (AngusSteak_220g == false)
	{
		AngusSteak_220g = true;
		AngusSteak_440g = false;
		AngusSteak_660g = false;
		CheckDlgButton(IDC_CHECK8, FALSE);
		CheckDlgButton(IDC_CHECK9, FALSE);
	}
	else if (AngusSteak_220g == true)
		AngusSteak_220g = false;
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedCheck8()
{
	UpdateData(TRUE);
	if (AngusSteak_440g == false)
	{
		AngusSteak_220g = false;
		AngusSteak_440g = true;
		AngusSteak_660g = false;
		CheckDlgButton(IDC_CHECK7, FALSE);
		CheckDlgButton(IDC_CHECK9, FALSE);
	}
	else if (AngusSteak_440g == true)
		AngusSteak_440g = false;
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedCheck9()
{
	UpdateData(TRUE);
	if (AngusSteak_660g == false)
	{
		AngusSteak_220g = false;
		AngusSteak_440g = false;
		AngusSteak_660g = true;
		CheckDlgButton(IDC_CHECK7, FALSE);
		CheckDlgButton(IDC_CHECK8, FALSE);
	}
	else if (AngusSteak_660g == true)
		AngusSteak_660g = false;
	UpdateData(FALSE);
}

void CtestDlg::OnEnChangeEdit7()
{
}

void CtestDlg::OnStnClickedStatic9()
{
}

void CtestDlg::OnStnClickedStatic10()
{
}

void CtestDlg::OnStnClickedStatic12()
{
}

void CtestDlg::OnStnClickedStatic13()
{
}

void CtestDlg::OnStnClickedStatic14()
{
}

void CtestDlg::OnStnClickedStatic15()
{
}

void CtestDlg::OnStnClickedStatic16()
{
}

void CtestDlg::OnStnClickedStatic17()
{
}

void CtestDlg::OnStnClickedStatic18()
{
}


void CtestDlg::OnBnClickedButton28()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON22)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON23)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON28)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK1)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK2)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK6)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC13)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC14)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC15)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedButton27()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON24)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON25)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON27)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK7)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK8)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK9)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC9)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC16)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC17)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC18)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
	UpdateData(FALSE);
}


void CtestDlg::OnBnClickedButton19()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON19)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON20)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON21)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK3)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK4)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK5)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC10)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC11)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC12)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->ShowWindow(FALSE);
	UpdateData(FALSE);
}

/////////////////////////////////Drinks////////////////////////////////////////
void CtestDlg::OnBnClickedButton38()
{
	UpdateData(TRUE);
	if (isDrinks == false)
	{
		GetDlgItem(IDC_BUTTON39)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON43)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON47)->ShowWindow(TRUE);
		isDrinks = true;
	}
	else if (isDrinks == true)
	{
		GetDlgItem(IDC_BUTTON39)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON43)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON47)->ShowWindow(FALSE);
		isDrinks = false;
	}
	UpdateData(FALSE);
}

////////////////////////////////////////Water//////////////////////////////////
void CtestDlg::OnBnClickedButton39()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_STATIC21)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON40)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON41)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON42)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT10)->ShowWindow(TRUE);
	UpdateData(FALSE);
}

void CtestDlg::OnStnClickedStatic21()
{
}

void CtestDlg::OnBnClickedButton40()             //remove water button
{
	UpdateData(TRUE);
	int i;
	Water *water = new Water;
	for (i = 0; i < allItems.GetSize(); i++)
	{
		if (allItems[i]->getPrice() == water->getPrice())
			break;
	}

	if (WaterCount == 0)
		WaterCount = 0;
	else if (WaterCount > 0)
	{
		allItems.RemoveAt(i);
		WaterCount--;
		paymentSum -= water->getPrice();
	}
	UpdateData(FALSE);
}

void CtestDlg::OnEnChangeEdit10()
{
}


void CtestDlg::OnBnClickedButton41()                // add water button
{
	Water *water = new Water;
	allItems.Add(water);
	UpdateData(TRUE);
	WaterCount++;
	paymentSum += water->getPrice();
	UpdateData(FALSE);

}

void CtestDlg::OnBnClickedButton42()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON40)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON41)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT10)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC21)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON42)->ShowWindow(FALSE);
	UpdateData(FALSE);
}
///////////////////////////////////////////////////////////////////////////////
/////////////////////////softdrinks////////////////////////////////////////////
void CtestDlg::OnBnClickedButton43()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_STATIC22)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON44)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON45)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON46)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT11)->ShowWindow(TRUE);
	UpdateData(FALSE);
}

void CtestDlg::OnStnClickedStatic22()
{
}

void CtestDlg::OnBnClickedButton44()             //remove softdrinks button
{
	UpdateData(TRUE);
	int i;
	SoftDrinks *softDrinks = new SoftDrinks;
	for (i = 0; i < allItems.GetSize(); i++)
	{
		if (allItems[i]->getPrice() == softDrinks->getPrice())
			break;
	}

	if (SoftDrinksCount == 0)
		SoftDrinksCount = 0;
	else if (SoftDrinksCount > 0)
	{
		allItems.RemoveAt(i);
		SoftDrinksCount--;
		paymentSum -= softDrinks->getPrice();
	}
	UpdateData(FALSE);
}


void CtestDlg::OnEnChangeEdit11()
{
}

void CtestDlg::OnBnClickedButton45()                // add softDrinks button
{
	SoftDrinks *softDrinks = new SoftDrinks;
	allItems.Add(softDrinks);
	UpdateData(TRUE);
	SoftDrinksCount++;
	paymentSum += softDrinks->getPrice();
	UpdateData(FALSE);

}


void CtestDlg::OnBnClickedButton46()                  // x button for soft drinks
{
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON44)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON45)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT11)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC22)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON46)->ShowWindow(FALSE);
	UpdateData(FALSE);
}

///////////////////////////////////Wine////////////////////////////////////////
void CtestDlg::OnBnClickedButton47()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_STATIC23)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON48)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON49)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON50)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT12)->ShowWindow(TRUE);
	UpdateData(FALSE);
}

void CtestDlg::OnStnClickedStatic23()
{
}

void CtestDlg::OnBnClickedButton48()             //remove Wine button
{
	UpdateData(TRUE);
	int i;
	Wine *wine = new Wine;
	for (i = 0; i < allItems.GetSize(); i++)
	{
		if (allItems[i]->getPrice() == wine->getPrice())
			break;
	}

	if (WineCount == 0)
		WineCount = 0;
	else if (WineCount > 0)
	{
		allItems.RemoveAt(i);
		WineCount--;
		paymentSum -= wine->getPrice();
	}
	UpdateData(FALSE);
}


void CtestDlg::OnEnChangeEdit12()
{
}


void CtestDlg::OnBnClickedButton49()                // add wine button
{
	Wine *wine = new Wine;
	allItems.Add(wine);
	UpdateData(TRUE);
	WineCount++;
	paymentSum += wine->getPrice();
	UpdateData(FALSE);

}


void CtestDlg::OnBnClickedButton50()                  // x button for wine
{
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON48)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON49)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT12)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC23)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON50)->ShowWindow(FALSE);
	UpdateData(FALSE);
}
//////////////////////////////////////////////////////////////////////////////
void CtestDlg::OnBnClickedBtnsave()  ///// Save button
{
	const TCHAR czFilter[] = _T("res files (*.res)|*.res|All Files (*.*)|(*.*)||");
	CFileDialog fDialog(FALSE, _T("res"), NULL, OFN_HIDEREADONLY| OFN_OVERWRITEPROMPT, czFilter, this);
	if (fDialog.DoModal() == IDOK) {
		CString filename = fDialog.GetPathName();
		CFile file (filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		allItems.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CtestDlg::OnBnClickedBtnload()   ///// Load button
{
	const TCHAR czFilter[] = _T("res files (*.res)|*.res|All Files (*.*)|(*.*)||");
	CFileDialog fDialog(TRUE, _T("res"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);
	if (fDialog.DoModal() == IDOK) {
		CString filename = fDialog.GetPathName();
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		allItems.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}