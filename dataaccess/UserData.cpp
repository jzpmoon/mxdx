#include "UserData.h"

void UserData::Serialize(CArchive& archive)
{
	MxdxData::Serialize(archive);
	if(archive.IsStoring()){
		writeField(archive,name);
		writeField(archive,password);
		writeField(archive,permission);
	}else{
		readField(archive,name);
		readField(archive,password);
		readField(archive,permission);
	}
}
