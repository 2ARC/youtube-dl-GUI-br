
// youtube-dl-GUI-br.h: arquivo de cabeçalho principal para o aplicativo PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "inclua 'pch.h' antes de incluir este arquivo para PCH"
#endif

#include "resource.h"		// símbolos principais


// CyoutubedlGUIbrApp:
// Consulte youtube-dl-GUI-br.cpp para a implementação desta classe
//

class CyoutubedlGUIbrApp : public CWinApp
{
public:
	CyoutubedlGUIbrApp();

// Substitui
public:
	virtual BOOL InitInstance();

// Implementação

	DECLARE_MESSAGE_MAP()
};

extern CyoutubedlGUIbrApp theApp;
