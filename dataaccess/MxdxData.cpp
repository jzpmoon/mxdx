#include "MxdxData.h"

void MxdxData::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);
	if(archive.IsStoring())
		writeField(archive,id);
	else
		readField(archive,id);
}

void MxdxData::writeField(CArchive& archive,CString& field)
{
	LPTSTR buf=field.GetBuffer(0);
	archive.Write(buf,field.GetLength());
	archive.WriteString("\n");
}

void MxdxData::readField(CArchive& archive,CString& field)
{
	char block[1024];
	int count=0;
	CFile* f=archive.GetFile();
	int seek=f->GetPosition();
	while(count=archive.Read(block,1024))
	{
		int e=0;
		while(e<count)
		{
			if(block[e]=='\n'){
				block[e]='\0';
				field+=block;
				seek+=e+1;
				f->Seek(seek,CFile::begin);
				return;
			}
			e++;
		}
		seek+=1024;
		field+=block;
	}
}