/// @addtogroup GROUP_ZYLLIBC	zyllibc
/// [zyl910](https://github.com/zyl910/)'s C/C++ librarys.
/// @{
///

/// @addtogroup GROUP_ZLATLCV	zlatlcv
/// zyl910's ATL String Conversion Utils (ATL字符串转换辅助) .
///
/// @author	[zyl910](mailto:zyl910hero@gmail.com)
/// @version	1.0
/// @date	2015-07-23
///
/// Links:
///
/// * Git:	https://github.com/zyl910/zlatlcv
/// * Blog:	http://www.cnblogs.com/zyl910/tag/zlatlcv/
/// 
/// zlatlcv is a lightweight C++ library.
///
/// Features (特性):
///
/// * Conversion of UTF-8 string and `char`/`wchat_t`/`TCHAR` string  (支持 UTF-8字符串 与 窄字符串、宽字符串、TCHAR字符串 的相互转换).
/// 
/// ## Usage (用法)
/// 
/// Add `src/``*.*` to you project (将 `src/``*.*` 加入到您的项目).
/// 
/// Example code:
/// 
/// 	#include <stdio.h>
/// 	#include <locale.h>
/// 	
/// 	#include "z_wchar.h"
/// 	#include "z_tchar.h"
/// 	#include "z_tmain.h"
/// 	
/// 	
/// 	const char* psa = "A_Welcome_歡迎_ようこそ_환영.";	//!< Narrow char string. "Welcome": English, Traditional Chinese, Japanese, Korean.
/// 	const wchar_t* psw = L"W_Welcome_歡迎_ようこそ_환영.";	//!< Wide char string.
/// 	const TCHAR* pst = _T("T_Welcome_歡迎_ようこそ_환영.");	//!< TCHAR string.
/// 	
/// 	/// tchar main .
/// 	int _tmain(int argc, TCHAR* argv[])
/// 	{
/// 		// init.
/// 		setlocale(LC_ALL, "");	// 使用客户环境的缺省locale.
/// 	
/// 		// title.
/// 		_tprintf(_T("zltchar v1.0 (%dbit)\n"), (int)(8*sizeof(int*)));
/// 		_tprintf(_T("\n"));
/// 	
/// 		// show.
/// 		_tprintf(_T("%")_T(PRIsA)_T("\n"), psa);	// Print narrow char string.
/// 		_tprintf(_T("%")_T(PRIsW)_T("\n"), psw);	// Print wide char string.
/// 		_tprintf(_T("%")_T(PRIsT)_T("\n"), pst);	// Print TCHAR string.
/// 		
/// 	
/// 		return 0;
/// 	}
/// 
/// 
/// ## Documentation (文档)
/// 
/// You can generate documentation with [doxygen](http://www.stack.nl/~dimitri/doxygen/index.html) (您可以用doxygen生成文档).
/// 
/// Use doxywizard to open *.doxygen file (使用doxywizard打开 *.doxygen).
/// 
/// * zlatlcv_doc.doxygen: Generates documentation from interface files (生成接口的文档) .
/// * zlatlcv_docfull.doxygen: Generates documentation from interface & implement and example files (生成接口、实现、示例等内容的详细文档).
/// 
/// You may need change INCLUDE_PATH in *.doxyfile with the actual location (您可能需要在 *.doxygen 中调整INCLUDE_PATH为实际路径).
/// 
/// 
/// ## Tested compiler (测试过的编译器)
/// 
/// * Virtual C++: 7.1(2003), 8(2005), 9(2008), 10(2010), 11(2012), 12(2013).
/// 
/// 
/// 
/// ## Change history (变更日志)
/// 
/// [2015-07-23] v1.0
/// 
/// * Release v1.0 (发布1.0版).
///
/// @{
///

///
/// @file zlatlcv.h
/// @file	z_tchar.h
/// @brief	zyl910's ATL String Conversion Utils (ATL字符串转换辅助) .
/// @since	@ref GROUP_ZLATLCV 1.0
///
/// Features(特性):
///
/// * Conversion of UTF-8 string and `char`/`wchat_t`/`TCHAR` string  (支持 UTF-8字符串 与 窄字符串、宽字符串、TCHAR字符串 的相互转换).
///

// Disable warning: UTF-8(No BOM).
#ifdef _MSC_VER
#pragma warning(disable : 4819)
#endif


#ifndef INCLUDED_ZLATLCV_H
#define INCLUDED_ZLATLCV_H




#endif	// #ifndef INCLUDED_ZLATLCV_H
