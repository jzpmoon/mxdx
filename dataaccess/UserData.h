#ifndef USERDATA_H
#define USERDATA_H

#include "MxdxData.h"
#include "../StdAfx.h"

class UserData : public MxdxData
{
private:
	CString name;
	CString password;
	CString permission;
public:
	UserData(){}
	UserData(UserData& d){
		this->name=d.name;
		this->password=d.password;
		this->permission=d.permission;
	}
	virtual ~UserData(){}
	virtual MxdxData* clone()
	{
		MxdxData* d=(MxdxData*) new UserData();
		return d;
	}
	BOOL operator==(UserData* d)
	{
		if(this->name==d->name&&
			this->password==d->password&&
			this->permission==d->permission)
			return true;
		else
			return false;
	}
	void Serialize(CArchive& archive);
	CString getName()
	{
		return name;
	}
	void setName(CString name)
	{
		this->name=name;
	}
	CString getPassword()
	{
		return password;
	}
	void setPassword(CString pw)
	{
		this->password=pw;
	}
	CString getPermission()
	{
		return permission;
	}
	void setPermission(CString permission)
	{
		this->permission=permission;
	}
};

#endif