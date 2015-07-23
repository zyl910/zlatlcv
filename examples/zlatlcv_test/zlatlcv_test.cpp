/// @addtogroup GROUP_ZYLLIBC	zyllibc
/// @{
///

/// @addtogroup GROUP_ZLATLCV	zlatlcv
/// @{
///

/// @addtogroup GROUP_ZLATLCV_EXAMPLE	example
/// @{
///


/// @addtogroup GROUP_ZLATLCV_EXAMPLE_TEST	zlatlcv_test
/// Test @ref GROUP_ZLATLCV (测试使用 @ref GROUP_ZLATLCV).
///
/// @author	[zyl910](mailto:zyl910hero@gmail.com)
/// @since	@ref GROUP_ZLATLCV 1.0
/// @version	1.0
/// @date	2015-07-23
///
/// Links:
///
/// * Git: https://github.com/zyl910/zlatlcv
/// * Blog: http://www.cnblogs.com/zyl910/tag/zlatlcv/
///
///
///
/// ## Tested compiler (测试过的编译器)
/// 
/// * Virtual C++: 8(2005), 9(2008), 10(2010), 11(2012), 12(2013).
///
///
/// ## Change history (变更日志)
///
/// [2015-07-23] V1.0
///
/// * Release v1.0 (发布1.0版).
///
/// @{
///

///
/// @file	zlatlcv_test.cpp
/// @brief	Test @ref GROUP_ZLATLCV (测试使用 @ref GROUP_ZLATLCV).
/// @since	@ref GROUP_ZLATLCV 1.0
///


#include "stdafx.h"

#include <stdio.h>
#include <locale.h>
#include <tchar.h>

#include "zlatlcv.h"


// "Welcome": English, Traditional Chinese, Japanese, Korean.
const char* psa = "A_Welcome_歡迎_ようこそ_환영.";	//!< UTF-8 string( Auto. File is UTF-8 encoding).
const wchar_t* psw = L"W_Welcome_\u6B61\u8FCE_\u3088\u3046\u3053\u305D_\uD658\uC601.";	//!< Wide char string.

int _tmain(int argc, _TCHAR* argv[])
{
	// init.
	setlocale(LC_ALL, "");	// 使用客户环境的缺省locale.

	// title.
	_tprintf(_T("zlatlcv v1.0 (%dbit)\n"), (int)(8*sizeof(int*)));
	_tprintf(_T("\n"));

	// printf.
	fflush(stdout);
	printf("printf A:\t%s\n", psa);
	printf("printf W:\t%ls\n", psw);
	printf("\n");

	// UTF-8 to string (UTF-8 转 各种字符串).
	//CA2AZ psaa(psa, CP_UTF8, 0);
	CU82A psaa(psa);
	CU82W psaw(psa);
	printf("printf A from UTF-8:\t%s\n", psaa);
	printf("printf W from UTF-8:\t%ls\n", psaw);
	printf("\n");

	// string to UTF-8 (各种字符串 转 UTF-8).
	CA2U8 psau8(psaa);
	CW2U8 pswu8(psaw);
	fflush(stdout);
	printf("printf UTF-8 from A:\t%s\n", psau8);
	printf("printf UTF-8 from W:\t%s\n", pswu8);

	// _tprintf.
	CA2CT psat(psa);
	CW2CT pswt(psw);
	fflush(stdout);
	_tprintf(_T("_tprintf A:\t%s\n"), psat);
	_tprintf(_T("_tprintf W:\t%s\n"), pswt);

	return 0;
}


/// @}
/// @}
/// @}
/// @}
