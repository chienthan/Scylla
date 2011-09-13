#pragma once

#include <windows.h>
#include <Commctrl.h>
#include <map>

class ImportModuleThunk;
class ImportThunk;

class ImportThunk {
public:
	WCHAR moduleName[MAX_PATH];
	char name[MAX_PATH];
	DWORD_PTR va;
	DWORD_PTR rva;
	DWORD_PTR ordinal;
	DWORD_PTR apiAddressVA;
	WORD hint;
	bool valid;
	bool suspect;

	HTREEITEM hTreeItem;
};


class ImportModuleThunk {
public:
	WCHAR moduleName[MAX_PATH];
	std::map<DWORD_PTR, ImportThunk> thunkList;

	DWORD_PTR firstThunk;

	HTREEITEM hTreeItem;

	DWORD_PTR getFirstThunk();
	bool isValid();

	~ImportModuleThunk()
	{
		if (!thunkList.empty())
		{
			thunkList.clear();
		}
	}

};