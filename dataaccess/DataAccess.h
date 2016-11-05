#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "MxdxData.h"
#include <afxtempl.h>
class DataAccess
{
public:
	virtual int add(MxdxData* data)=0;
	virtual int del(MxdxData* data)=0;
	virtual int modify(MxdxData* data)=0;
	virtual int query(CList<MxdxData*,MxdxData*>* list)=0;
	virtual BOOL isExists(MxdxData* data)=0;
	void queryCln(CList<MxdxData*,MxdxData*>* list);
};

#endif