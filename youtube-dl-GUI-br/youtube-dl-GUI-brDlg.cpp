
// youtube-dl-GUI-brDlg.cpp: arquivo de implementação
//

#include "pch.h"
#include "framework.h"
#include "youtube-dl-GUI-br.h"
#include "youtube-dl-GUI-brDlg.h"
#include "afxdialogex.h"
#include <afxwin.h> // AfxMessageBox

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Caixa de diálogo CAboutDlg usada para o Sobre o Aplicativo

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Janela de Dados
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Suporte DDX/DDV

// Implementação
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


// caixa de diálogo CyoutubedlGUIbrDlg



CyoutubedlGUIbrDlg::CyoutubedlGUIbrDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YOUTUBEDLGUIBR_DIALOG, pParent)
	, m_url(_T(""))
	, m_pasta(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CyoutubedlGUIbrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_url);
	DDX_Control(pDX, IDC_CHECK1, m_audio);
	DDX_Control(pDX, IDC_CHECK2, m_lista);
	DDX_Text(pDX, IDC_EDIT2, m_pasta);
	DDX_Control(pDX, IDC_CHECK3, m_legenda);
}

BEGIN_MESSAGE_MAP(CyoutubedlGUIbrDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CyoutubedlGUIbrDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CyoutubedlGUIbrDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CyoutubedlGUIbrDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK1, &CyoutubedlGUIbrDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CyoutubedlGUIbrDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CyoutubedlGUIbrDlg::OnBnClickedCheck3)
END_MESSAGE_MAP()


// Manipuladores de mensagens de CyoutubedlGUIbrDlg

BOOL CyoutubedlGUIbrDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Adicione o item de menu "Sobre..." ao menu do sistema.

	// IDM_ABOUTBOX deve estar no intervalo de comandos do sistema.
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

	// Defina o ícone para esta caixa de diálogo. A estrutura faz isso automaticamente
	//  quando a janela principal do aplicativo não é uma caixa de diálogo
	SetIcon(m_hIcon, TRUE);			// Definir ícone grande
	SetIcon(m_hIcon, FALSE);		// Definir ícone pequeno

	// TODO: adicione a inicialização extra aqui
	// Mantém foco na caixa de texto para o endereço da Internet
	HWND hWnd;
	GetDlgItem(IDC_EDIT1, &hWnd);
	::PostMessage(GetSafeHwnd(), WM_NEXTDLGCTL, (WPARAM)hWnd, TRUE);
	// Mantém foco na caixa de texto para o endereço da Internet
	// Sempre na frente
	SetWindowPos(&wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // retorna TRUE a não ser que você ajuste o foco para um controle
}

void CyoutubedlGUIbrDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Se você adicionar um botão para minimizar à sua caixa de diálogo, será necessário o código abaixo
//  para desenhar o ícone. Para aplicativos MFC usando o modelo de exibição/documento,
//  isso é feito automaticamente para você pela estrutura.

void CyoutubedlGUIbrDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexto do dispositivo para pintura

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ícone central no retângulo do cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Desenhar o ícone
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// O sistema chama esta função para obter o cursor a ser exibido enquanto o usuário arrasta
//  a janela minimizada.
HCURSOR CyoutubedlGUIbrDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CyoutubedlGUIbrDlg::OnBnClickedOk()
{
	// TODO: Adicione seu código de manipulador de notificações de controle aqui
	// Passa o que foi colado no controle (p.ex: youtube.com) para à variável mebro do controle
	UpdateData(TRUE);
	// String contendo o que eu acredito ser o mínimo para um uso suave do programa
	CString str = _T(" --restrict-filenames --mark-watched --no-warnings --ignore-errors --console-title --youtube-skip-dash-manifest -o \"\\");
	if (m_pasta == _T(""))
	{
		m_pasta = _T("Arquivos_Baixados");
	}
	str += m_pasta; // Subm_pasta
	str += _T("\\%(title)s.%(ext)s\" ");
	// Uma variável para dois controles. Checa se o usuário selecionou apenas m_audio e/ou m_lista
	bool foiChecado;
	// Audio?
	CButton* m_ctlCheck1 = (CButton*)GetDlgItem(IDC_CHECK1);
	foiChecado = (m_ctlCheck1->GetCheck());
	if (foiChecado == true) {
		str += " -x --m_audio-format mp3 ";
	}
	// Lista?
	CButton* m_ctlCheck2 = (CButton*)GetDlgItem(IDC_CHECK2);
	foiChecado = (m_ctlCheck2->GetCheck());
	if (foiChecado == true) {
		str += " --yes-playlist ";
	}
	else {
		str += " --no-playlist ";
	}
	// Legenda?
	CButton* m_ctlCheck3 = (CButton*)GetDlgItem(IDC_CHECK3);
	foiChecado = (m_ctlCheck3->GetCheck());
	if (foiChecado == true) {
		str += " --write-auto-sub --sub-format srt ";
	}
	// Atualiza a variável membro a partir da variável temporária
	str += m_url;
	// Passa os argumentos e executa via terminal o programa youtube-dl.exe
	ShellExecute(NULL, _T("open"), _T("youtube-dl.exe"), str, _T(""), SW_SHOW);
	// Avisa para não fechar a "tela preta" = janela do youtube-dl
	AfxMessageBox(L"A \"janela preta\" vai fechar sozinha. Minimize-a se desejar.\nO tempo para terminar depende da velocidade de sua Internet.");
	// Desabilita o botão Baixar para impedir que o usuário fique criando vários processos de youtube-dl
	GetDlgItem(IDOK)->EnableWindow(FALSE);
	// Mantém foco na caixa de texto para o endereço da Internet
	HWND hWnd;
	GetDlgItem(IDC_EDIT1, &hWnd);
	::PostMessage(GetSafeHwnd(), WM_NEXTDLGCTL, (WPARAM)hWnd, TRUE);
}


void CyoutubedlGUIbrDlg::OnBnClickedButton1()
{
	// TODO: Adicione seu código de manipulador de notificações de controle aqui
	AfxMessageBox(L"youtube-dl-GUI-br_ver_1.2\nMais uma interface grafica bem simples para o youtube-dl\n\nCodecs: https://www.ffmpeg.org \nAlgoritimo: https://github.com/ytdl-org/youtube-dl \n\nGUI: https://github.com/MarcoBRSP/youtube-dl-GUI-br \nContato: marcoadeoli@outlook.com \n\nCompilado com Microsoft Visual Studio Community 2019 Ver. 16.4.5");
	// Mantém foco na caixa de texto para o endereço da Internet
	HWND hWnd;
	GetDlgItem(IDC_EDIT1, &hWnd);
	::PostMessage(GetSafeHwnd(), WM_NEXTDLGCTL, (WPARAM)hWnd, TRUE);
}

void CyoutubedlGUIbrDlg::OnBnClickedButton2()
{
	// TODO: Adicione seu código de manipulador de notificações de controle aqui
	// Audio?
	CButton* m_ctlCheck1 = (CButton*)GetDlgItem(IDC_CHECK1);
	m_ctlCheck1->SetCheck(0); // (de)seleciona
	// Lista?
	CButton* m_ctlCheck2 = (CButton*)GetDlgItem(IDC_CHECK2);
	m_ctlCheck2->SetCheck(0); // (de)seleciona
	// Legenda?
	CButton* m_ctlCheck3 = (CButton*)GetDlgItem(IDC_CHECK3);
	m_ctlCheck3->SetCheck(0); // (de)seleciona
	// Limpa caixas de edição de texto
	m_url = _T("");
	m_pasta = _T("");
	UpdateData(FALSE);
	// Habilita o botão Baixar caso o usuário queira baixar outro arquivo
	GetDlgItem(IDOK)->EnableWindow(TRUE);
	// Mantém foco na caixa de texto para o endereço da Internet
	HWND hWnd;
	GetDlgItem(IDC_EDIT1, &hWnd);
	::PostMessage(GetSafeHwnd(), WM_NEXTDLGCTL, (WPARAM)hWnd, TRUE);
}


void CyoutubedlGUIbrDlg::OnBnClickedCheck1() // Audio
{
	// TODO: Adicione seu código de manipulador de notificações de controle aqui
	// Uma variável para dois controles. Checa se o usuário selecionou apenas m_audio e/ou m_lista
	bool foiChecado;
	// Audio?
	CButton* m_ctlCheck1 = (CButton*)GetDlgItem(IDC_CHECK1);
	foiChecado = (m_ctlCheck1->GetCheck());
	if (foiChecado == true) {
		CButton* m_ctlCheck3 = (CButton*)GetDlgItem(IDC_CHECK3);
		m_ctlCheck3->SetCheck(0); // (de)seleciona
	}
	// Mantém foco na caixa de texto para o endereço da Internet
	HWND hWnd;
	GetDlgItem(IDC_EDIT1, &hWnd);
	::PostMessage(GetSafeHwnd(), WM_NEXTDLGCTL, (WPARAM)hWnd, TRUE);
}


void CyoutubedlGUIbrDlg::OnBnClickedCheck2() // Lista
{
	// TODO: Adicione seu código de manipulador de notificações de controle aqui
	// Mantém foco na caixa de texto para o endereço da Internet
	HWND hWnd;
	GetDlgItem(IDC_EDIT1, &hWnd);
	::PostMessage(GetSafeHwnd(), WM_NEXTDLGCTL, (WPARAM)hWnd, TRUE);
}


void CyoutubedlGUIbrDlg::OnBnClickedCheck3() // Legenda
{
	// TODO: Adicione seu código de manipulador de notificações de controle aqui
	// Uma variável para dois controles. Checa se o usuário selecionou apenas m_audio e/ou m_lista
	bool foiChecado;
	// Legenda?
	CButton* m_ctlCheck3 = (CButton*)GetDlgItem(IDC_CHECK3);
	foiChecado = (m_ctlCheck3->GetCheck());
	if (foiChecado == true) {
		CButton* m_ctlCheck1 = (CButton*)GetDlgItem(IDC_CHECK1);
		m_ctlCheck1->SetCheck(0); // (de)seleciona
	}
	// Mantém foco na caixa de texto para o endereço da Internet
	HWND hWnd;
	GetDlgItem(IDC_EDIT1, &hWnd);
	::PostMessage(GetSafeHwnd(), WM_NEXTDLGCTL, (WPARAM)hWnd, TRUE);
}
