
// youtube-dl-GUI-br.cpp: define os comportamentos de classe para o aplicativo.
//

#include "pch.h"
#include "framework.h"
#include "youtube-dl-GUI-br.h"
#include "youtube-dl-GUI-brDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CyoutubedlGUIbrApp

BEGIN_MESSAGE_MAP(CyoutubedlGUIbrApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// construção de CyoutubedlGUIbrApp

CyoutubedlGUIbrApp::CyoutubedlGUIbrApp()
{
	// TODO: adicione código de construção aqui,
	// Coloque todas as inicializações significativas em InitInstance
}


// O único objeto de CyoutubedlGUIbrApp

CyoutubedlGUIbrApp theApp;


// inicialização de CyoutubedlGUIbrApp

BOOL CyoutubedlGUIbrApp::InitInstance()
{
	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Criar o gerenciador de shell se a caixa de diálogo contiver
	// qualquer modo de exibição de árvore de shell ou controles de exibição de lista de shell.
	CShellManager *pShellManager = new CShellManager;

	// Ativar o gerenciador visual "Nativo do Windows" para habilitar temas nos controles do MFC
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Inicialização padrão
	// Se você não estiver usando esses recursos e desejar reduzir o tamanho
	// do seu arquivo executável final, que você deve remover de
	// as rotinas de inicialização específicas que não são necessárias
	// Alterar a chave do Registro sob a qual as configurações são armazenadas
	// TODO: você deve modificar esta cadeia de caracteres para algo apropriado
	// como o nome da sua empresa ou organização
	SetRegistryKey(_T("Aplicativos Locais Gerados pelo AppWizard"));

	CyoutubedlGUIbrDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: coloque código aqui para manipular quando a caixa de diálogo estiver
		//  descartado com Ok
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: coloque código aqui para manipular quando a caixa de diálogo estiver
		//  descartado com Cancelar
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Aviso: a criação de caixa de diálogo falhou, portanto, o aplicativo está sendo encerrado inesperadamente.\n");
		TRACE(traceAppMsg, 0, "Aviso: se você estiver usando controles do MFC na caixa de diálogo, não será possível #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Exclua o gerenciador de shell criado acima.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Como a caixa de diálogo foi fechada, retornar FALSE para que encerremos o
	//  aplicativo, em vez de iniciar o aumento de mensagens do aplicativo.
	return FALSE;
}

