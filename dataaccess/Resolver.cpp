#include "Resolver.h"
#include "../StdAfx.h"

Resolver::Resolver(char* filePath)
{
	this->filePath=filePath;
}

int Resolver::add(MxdxData* record)
{
	CFile f(_T(this->filePath),CFile::modeCreate|CFile::modeReadWrite);
	CArchive ar(&f,CArchive::store);
	try{
		record->Serialize(ar);
	} catch(CFileException e){}
	ar.Flush();
	ar.Close();
	f.Close();
	return 0;
}

CList<MxdxData*,MxdxData*>* Resolver::query(CList<MxdxData*,MxdxData*>* list,MxdxData* d)
{
	CFile f(_T(this->filePath),CFile::modeRead);
	CArchive ar(&f,CArchive::load);
	while(f.GetPosition()!=f.GetLength())
	{
		MxdxData* _d=d->clone();
		_d->Serialize(ar);
		list->AddTail(_d);
	}
	ar.Close();
	f.Close();
	return list;
}