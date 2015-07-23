# zlatlcv

Links:

* Git:	https://github.com/zyl910/zlatlcv
* Blog:	http://www.cnblogs.com/zyl910/tag/zlatlcv/

zlatlcv is a lightweight C++ library.

Features (特性):

* Conversion of UTF-8 string and `char`/`wchat_t`/`TCHAR` string  (支持 UTF-8字符串 与 窄字符串、宽字符串、TCHAR字符串 的相互转换).

## Usage (用法)

### Example (范例)

Add `src/``*.*` to you project (将 `src/``*.*` 加入到您的项目).

Example code:

	#include <stdio.h>
	#include <locale.h>
	#include <tchar.h>
	
	#include "zlatlcv.h"
	
	
	// "Welcome": English, Traditional Chinese, Japanese, Korean.
	const char* psa = "A_Welcome_歡迎_ようこそ_환영.";	//!< UTF-8 string( Auto. File used UTF-8 encoding).
	const wchar_t* psw = L"W_Welcome_\u6B61\u8FCE_\u3088\u3046\u3053\u305D_\uD658\uC601.";	//!< Wide char string.
	
	int _tmain(int argc, _TCHAR* argv[])
	{
		// init.
		setlocale(LC_ALL, "");	// 使用客户环境的缺省locale.
	
		// title.
		_tprintf(_T("zlatlcv v1.0 (%dbit)\n"), (int)(8*sizeof(int*)));
		_tprintf(_T("sizeof(wchar_t): %d\n"), (int)(sizeof(wchar_t)));
		_tprintf(_T("sizeof(TCHAR): %d\n"), (int)(sizeof(TCHAR)));
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
		CU82T psu8t(psa);
		fflush(stdout);
		_tprintf(_T("_tprintf A:\t%s\n"), psat);
		_tprintf(_T("_tprintf W:\t%s\n"), pswt);
		_tprintf(_T("_tprintf U8:\t%s\n"), psu8t);
	
		return 0;
	}


### Quick reference (快速参考)

Commonly used conversion Macros (常用转换宏):

* CU82A: Convert UTF-8 string to narrow string (将 UTF-8字符串 转为 窄字符串).
* CA2U8: Convert narrow string to UTF-8 string (将 窄字符串 转为 UTF-8字符串).
* CU82W: Convert UTF-8 string to wide string (将 UTF-8字符串 转为 宽字符串).
* CW2U8: Convert wide string to UTF-8 string (将 宽字符串 转为 UTF-8字符串).
* CU82T: Convert UTF-8 string to TCHAR string (将 UTF-8字符串 转为 TCHAR字符串).
* CT2U8: Convert TCHAR string to UTF-8 string (将 TCHAR字符串 转为 UTF-8字符串).

The names of the conversion macros take the form (转换宏的命名方式):

	C<SourceType>2[C]<DestinationType>[EX]

* `<SourceType>`/`<DestinationType>`: A(char), W(wchar_t), T(TCHAR), U8(UTF-8), 
* `[C]` is present when the destination type must be constant.
* `[EX]` is present when the initial size of the buffer must be specified as a template argument.

Low level conversion Classes (底层支撑类):

* CA2AEXZ: Convert source encoding string to destination encoding string (将源编码字符串转为目标编码字符串).
* CU82AEX: Convert UTF-8 string to narrow string (将 UTF-8字符串 转为 窄字符串).
* CA2U8EX: Convert narrow string to UTF-8 string (将 窄字符串 转为 UTF-8字符串).
* CU82WEX: Convert UTF-8 string to wide string (将 UTF-8字符串 转为 宽字符串).
* CW2U8EX: Convert wide string to UTF-8 string (将 宽字符串 转为 UTF-8字符串).



## Documentation (文档)

You can generate documentation with [doxygen](http://www.stack.nl/~dimitri/doxygen/index.html) (您可以用doxygen生成文档).

Use doxywizard to open *.doxygen file (使用doxywizard打开 *.doxygen).

* zlatlcv_doc.doxygen: Generates documentation from interface files (生成接口的文档) .
* zlatlcv_docfull.doxygen: Generates documentation from interface & implement and example files (生成接口、实现、示例等内容的详细文档).

You may need change INCLUDE_PATH in *.doxyfile with the actual location (您可能需要在 *.doxygen 中调整INCLUDE_PATH为实际路径).


## Tested compiler (测试过的编译器)

* Virtual C++: 7.1(2003), 8(2005), 9(2008), 10(2010), 11(2012), 12(2013).



## Change history (变更日志)

[2015-07-23] v1.0

* Release v1.0 (发布1.0版).
