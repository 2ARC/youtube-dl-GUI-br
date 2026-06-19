#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Remova itens raramente utilizados dos cabeçalhos Windows
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // alguns construtores CString serão explícitos

// desativa a ocultação de MFC de algumas mensagens de aviso comuns e frequentemente ignoradas
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // componentes MFC principais e padrões
#include <afxext.h>         // Extensões MFC


#include <afxdisp.h>        // Classes de Automação MFC



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Suporte MFC para Controles Comuns do Internet Explorer 4
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Suporte MFC para Controles Comuns Windows
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // Suporte do MFC para faixas de opções e barras de controle











