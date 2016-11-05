// UserAccess.h: interface for the UserAccess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERACCESS_H__8B359530_DFB7_439E_A636_92825CCCFB00__INCLUDED_)
#define AFX_USERACCESS_H__8B359530_DFB7_439E_A636_92825CCCFB00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "DataAccess.h"
#include "UserData.h"
#include "Resolver.h"

class UserAccess : public DataAccess  
{
private:
	Resolver m_res;
public:
	UserAccess();
	virtual ~UserAccess();
	virtual int add(MxdxData* data);
	virtual int del(MxdxData* data);
	virtual int modify(MxdxData* data);
	virtual int query(CList<MxdxData*,MxdxData*>* list);
	virtual BOOL isExists(MxdxData* data);

};

#endif // !defined(AFX_USERACCESS_H__8B359530_DFB7_439E_A636_92825CCCFB00__INCLUDED_)
