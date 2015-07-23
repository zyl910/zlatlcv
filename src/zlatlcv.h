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
/// * Virtual C++: 8(2005), 9(2008), 10(2010), 11(2012), 12(2013).
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
/// @file	zlatlcv.h
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

#include <atlconv.h>

namespace ATL
{

/// Convert source encoding string to destination encoding string (将源编码字符串转为目标编码字符串).
template< int t_nBufferLength = 128 >
class CA2AEXZ {
public:
	CA2AEXZ( __in_opt LPCSTR psz ) throw(...) :
		m_psz( m_szBuffer ) {
		UINT nCodePage = _AtlGetConversionACP();
		Init( psz, nCodePage, nCodePage);
	}

	CA2AEXZ( __in_opt LPCSTR psz, UINT nCodePage ) throw(...) :
		m_psz( m_szBuffer ) {
		Init( psz, nCodePage, nCodePage);
	}

	CA2AEXZ( __in_opt LPCSTR psz, UINT cpsrc, UINT cpdst ) throw(...) :
		m_psz( m_szBuffer ) {	// 将 cpsrc编码字符串 转为 cpdst编码字符串.
		Init( psz, cpsrc, cpdst);
	}

	~CA2AEXZ() throw() {		
		AtlConvFreeMemory(m_psz,m_szBuffer,t_nBufferLength);
	}

	operator LPSTR() const throw() {
		return( m_psz );
	}

private:
	void Init( __in_opt LPCSTR psz, UINT cpsrc, UINT cpdst ) throw(...) {
		if (psz == NULL) {
			m_psz = NULL;
			return;
		}
		// same encoding.
		int cchsrc = lstrlenA(psz) + 1;	// 源串长度. 包含终结字符.
		if (cpsrc==cpdst || cchsrc<=1) {
			AtlConvAllocMemory(&m_psz, cchsrc, m_szBuffer, t_nBufferLength);		
			Checked::memcpy_s( m_psz, cchsrc*sizeof(char), psz, cchsrc*sizeof(char));
			return;
		}
		// Convert.
		wchar_t* pbuf = NULL;	// 缓冲区.
		int cchbuf;	// 缓冲区字符数.
		for(;;) {	// Use for break.
			// 1) to wide.
			cchbuf = ::MultiByteToWideChar( cpsrc, 0, psz, cchsrc, NULL, 0);
			if (cchbuf<=0) {
				AtlThrowLastWin32();
				break;
			}
			pbuf = (wchar_t*)malloc(cchbuf*sizeof(wchar_t));
			if (NULL==pbuf) {
				break;
			}
			cchbuf = ::MultiByteToWideChar( cpsrc, 0, psz, cchsrc, pbuf, cchbuf);
			if (cchbuf<=0) {
				AtlThrowLastWin32();
				break;
			}
			// 2) wide to.
			int cchdst = ::WideCharToMultiByte( cpdst, 0, pbuf, cchbuf, NULL, 0, NULL, NULL );
			if (cchdst<=0) {
				AtlThrowLastWin32();
				break;
			}
			AtlConvAllocMemory(&m_psz, cchdst, m_szBuffer, t_nBufferLength);
			cchdst == ::WideCharToMultiByte( cpdst, 0, pbuf, cchbuf, m_psz, cchdst, NULL, NULL );
			if (cchdst<=0) {
				AtlThrowLastWin32();
				break;
			}
			// done.
			break;
		}
		if (NULL!=pbuf) {
			free(pbuf);
		}
	}

public:
	LPSTR m_psz;
	char m_szBuffer[t_nBufferLength];

private:
	CA2AEXZ( const CA2AEXZ& ) throw();
	CA2AEXZ& operator=( const CA2AEXZ& ) throw();
};
typedef CA2AEXZ<> CA2AZ;


/// Convert UTF-8 string to narrow string (将 UTF-8字符串 转为 窄字符串).
template< int t_nBufferLength = 128 >
class CU82AEX: public CA2AEXZ<t_nBufferLength> {
public:
	CU82AEX( __in_opt LPCSTR psz ) throw(...) :
		CA2AEXZ( psz, CP_UTF8, 0 ) {	// 将 UTF-8字符串 转为 本地编码字符串.
	}
	CU82AEX( __in_opt LPCSTR psz, UINT nCodePage ) throw(...) :
		CA2AEXZ( psz, CP_UTF8, nCodePage ) {	// 将 UTF-8字符串 转为 nCodePage编码字符串.
	}
	CU82AEX( __in_opt LPCSTR psz, UINT cpsrc, UINT cpdst ) throw(...) :
		CA2AEXZ( psz, cpsrc, cpdst ) {	// 将 cpsrc编码字符串 转为 cpdst编码字符串.
	}
	~CU82AEX() throw() {
		// call base.
	}

private:
	CU82AEX( const CU82AEX& ) throw();
	CU82AEX& operator=( const CU82AEX& ) throw();
};
typedef CU82AEX<> CU82A;


/// Convert narrow string to UTF-8 string (将 窄字符串 转为 UTF-8字符串).
template< int t_nBufferLength = 128 >
class CA2U8EX: public CA2AEXZ<t_nBufferLength> {
public:
	CA2U8EX( __in_opt LPCSTR psz ) throw(...) :
		CA2AEXZ( psz, 0, CP_UTF8 ) {	// 将 本地编码字符串 转为 UTF-8字符串.
	}
	CA2U8EX( __in_opt LPCSTR psz, UINT nCodePage ) throw(...) :
		CA2AEXZ( psz, nCodePage, CP_UTF8 ) {	// 将 nCodePage编码字符串 转为 UTF-8字符串.
	}
	CA2U8EX( __in_opt LPCSTR psz, UINT cpsrc, UINT cpdst ) throw(...) :
		CA2AEXZ( psz, cpsrc, cpdst ) {	// 将 cpsrc编码字符串 转为 cpdst编码字符串.
	}
	~CA2U8EX() throw() {
		// call base.
	}

private:
	CA2U8EX( const CA2U8EX& ) throw();
	CA2U8EX& operator=( const CA2U8EX& ) throw();
};
typedef CA2U8EX<> CA2U8;


/// Convert UTF-8 string to wide string (将 UTF-8字符串 转为 宽字符串).
template< int t_nBufferLength = 128 >
class CU82WEX: public CA2WEX<t_nBufferLength> {
public:
	CU82WEX( __in_opt LPCSTR psz ) throw(...) :
		CA2WEX( psz, CP_UTF8 ) {	// 将 UTF-8字符串 转为 宽字符串.
	}
	CU82WEX( __in_opt LPCSTR psz, UINT nCodePage ) throw(...) :
		CA2WEX( psz, CP_UTF8 ) {	// 将 UTF-8字符串 转为 宽字符串.
			(void)nCodePage;
	}
	CU82WEX( __in_opt LPCSTR psz, UINT cpsrc, UINT cpdst ) throw(...) :
		CW2AEX( psz, cpsrc ) {	// 将 cpsrc编码字符串 转为 宽字符串.
			(void)cpdst;
	}
	~CU82WEX() throw() {
		// call base.
	}

private:
	CU82WEX( const CU82WEX& ) throw();
	CU82WEX& operator=( const CU82WEX& ) throw();
};
typedef CU82WEX<> CU82W;


/// Convert wide string to UTF-8 string (将 宽字符串 转为 UTF-8字符串).
template< int t_nBufferLength = 128 >
class CW2U8EX: public CW2AEX<t_nBufferLength> {
public:
	CW2U8EX( __in_opt LPCWSTR psz ) throw(...) :
		CW2AEX( psz, CP_UTF8 ) {	// 将 宽字符串 转为 UTF-8字符串.
	}
	CW2U8EX( __in_opt LPCWSTR psz, UINT nCodePage ) throw(...) :
		CW2AEX( psz, CP_UTF8 ) {	// 将 宽字符串 转为 UTF-8字符串.
			(void)nCodePage;
	}
	CW2U8EX( __in_opt LPCSTR psz, UINT cpsrc, UINT cpdst ) throw(...) :
		CW2AEX( psz, cpdst ) {	// 将 宽字符串 转为 cpdst编码字符串.
			(void)cpsrc;
	}
	~CW2U8EX() throw() {
		// call base.
	}

private:
	CW2U8EX( const CW2U8EX& ) throw();
	CW2U8EX& operator=( const CW2U8EX& ) throw();
};
typedef CW2U8EX<> CW2U8;



}


#endif	// #ifndef INCLUDED_ZLATLCV_H


/// @}
/// @}
/// @}
