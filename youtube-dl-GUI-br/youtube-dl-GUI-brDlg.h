
// youtube-dl-GUI-brDlg.h: arquivo de cabeçalho
//

#pragma once


// caixa de diálogo CyoutubedlGUIbrDlg
class CyoutubedlGUIbrDlg : public CDialogEx
{
// Construção
public:
	CyoutubedlGUIbrDlg(CWnd* pParent = nullptr);	// construtor padrão

// Janela de Dados
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YOUTUBEDLGUIBR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Suporte DDX/DDV


// Implementação
protected:
	HICON m_hIcon;

	// Funções geradas de mapa de mensagens
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_url;
	CButton m_audio;
	CButton m_lista;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	// Nome da subpasta que conterá o(s) arquivo(s)
	CString m_pasta;
	CButton m_legenda;
	afx_msg void OnBnClickedCheck3();
};
