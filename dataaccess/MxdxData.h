#ifndef MXDXDATA_H
#define MXDXDATA_H
#include "../StdAfx.h"
class MxdxData:public CObject
{
private:
	CString id;
protected:
	void writeField(CArchive& archive,CString& field);
	void readField(CArchive& archive,CString& field);
public:
	MxdxData(){}
	MxdxData(MxdxData& d)
	{
		this->id=d.id;
	}
	virtual ~MxdxData(){}
	virtual MxdxData* clone()
	{
		MxdxData* d=new MxdxData();
		return d;
	}
	BOOL operator==(MxdxData* d)
	{
		if(this->id==d->id)
			return true;
		else
			return false;
	}
	void Serialize(CArchive& archive);
	void setId(CString id)
	{
		this->id=id;
	}
	CString getId()
	{
		return id;
	}
};

#endif