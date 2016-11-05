#ifndef RESOLVER_H
#define RESOLVER_H
#include <afxtempl.h>
#include "MxdxData.h"
class Resolver
{
private:
	char sign_field;
	char sign_record;
	char sign_null;
	char* filePath;
	CArchive* srecord;
	CArchive* lrecord;
public:
	Resolver(char* filePath);
	CList<MxdxData*,MxdxData*>* query(CList<MxdxData*,MxdxData*>* list,MxdxData* d);
	int add(MxdxData* record);
	int modify();
	int del();
};

#endif