// UserAccess.cpp: implementation of the UserAccess class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UserAccess.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UserAccess::UserAccess():m_res("user.txt")
{

}

UserAccess::~UserAccess()
{

}

int UserAccess::add(MxdxData* data)
{
	m_res.add(data);
	return 0;
}

int UserAccess::del(MxdxData* data)
{
 return 0;
}

int UserAccess::modify(MxdxData* data)
{
 return 0;
}

int UserAccess::query(CList<MxdxData*,MxdxData*>* list)
{
	UserData user;
	m_res.query(list,&user);
	return 0;
}

BOOL UserAccess::isExists(MxdxData* data)
{
	BOOL exists=false;
	CList<UserData*,UserData*> list;
	this->query((CList<MxdxData*,MxdxData*>*)&list);
	POSITION pos=list.GetHeadPosition();
	while(pos!=NULL)
	{
		UserData* _data=list.GetNext(pos);
		if(exists=(*_data)==(UserData*)data)
			break;
	}
	queryCln((CList<MxdxData*,MxdxData*>*)&list);
	return exists;
}
