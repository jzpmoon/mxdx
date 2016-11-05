#include "DataAccess.h"

void DataAccess::queryCln(CList<MxdxData*,MxdxData*>* list)
{
	POSITION pos=list->GetHeadPosition();
	while(pos!=NULL)
	{
		MxdxData* _data=list->GetNext(pos);
		delete _data;
	}
}