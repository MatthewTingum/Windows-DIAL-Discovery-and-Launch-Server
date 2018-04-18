// IDMRSettings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Windows.h"
#include <psapi.h>
#include <tlhelp32.h>
#include "wrl\implements.h"
#include <comutil.h>
#include "wrl\client.h"
#include "atlbase.h"
#include "interfaces.h"


extern "C" {
	typedef long(*dllGetClassObjectPtr)(const CLSID& clsid, const IID& iid, IClassFactory** ppv);
}


int main()
{

	HRESULT result;

	result = Windows::Foundation::Initialize(RO_INIT_MULTITHREADED);

	result = CoInitializeSecurity(
		NULL,
		-1,
		NULL,
		NULL,
		RPC_C_AUTHN_LEVEL_DEFAULT,
		RPC_C_IMP_LEVEL_IMPERSONATE,
		NULL,
		EOAC_SECURE_REFS | EOAC_DISABLE_AAA,
		NULL
	);

	


	// Class Factory (ICast)
	// 62AAAC25-625B-4297-9842-8E4442FA98F5
	CLSID clsid;
	clsid.Data1 = 0x62AAAC25;
	clsid.Data2 = 0x625B;
	clsid.Data3 = 0x4297;
	byte cdata4[8] = { 0x98 , 0x42, 0x8E, 0x44, 0x42, 0xFA, 0x98, 0xF5 };
	memcpy(clsid.Data4, cdata4, 8);

	//af86e2e0_b12d_4c6a_9c5a_d7aa65101e90
	_GUID guid;
	guid.Data1 = 0xaf86e2e0;
	guid.Data2 = 0xb12d;
	guid.Data3 = 0x4c6a;
	byte gdata4[8] = { 0x9c, 0x5a, 0xd7, 0xaa, 0x65, 0x10, 0x1e, 0x90 };
	memcpy(guid.Data4, gdata4, 8);

	// IDMRSettings
	_GUID guid2;
	guid2.Data1 = 0x3c87d146;
	guid2.Data2 = 0xf34c;
	guid2.Data3 = 0x4778;
	byte g2data4[8] = { 0x8b, 0x7e, 0xe7, 0xa0, 0x49, 0xc0, 0x9b, 0x09 };
	memcpy(guid2.Data4, g2data4, 8);

	// ICastServerControl
	_GUID guid3_ICastServerControl;
	guid3_ICastServerControl.Data1 = 0x7733f245;
	guid3_ICastServerControl.Data2 = 0xf909;
	guid3_ICastServerControl.Data3 = 0x4be2;
	byte gdata44[8] = { 0x91, 0x8f, 0xbd, 0xde, 0xcb, 0xcd, 0x07, 0xcc };
	memcpy(guid3_ICastServerControl.Data4, gdata44, 8);


	


	



	auto hDial = LoadLibrary(L"C:\\Users\\User\\Desktop\\10041\\dialserver.dll");
	auto hDMR_DLL = LoadLibrary(L"C:\\Users\\User\\Desktop\\10041\\DMRServer.dll");
	HMODULE hModuleDMR = GetModuleHandle(L"C:\\Users\\User\\Desktop\\10041\\DMRServer.dll");
	HANDLE hProc = GetCurrentProcess();
	MODULEINFO mi;
	bool success = GetModuleInformation(hProc, hModuleDMR, &mi, sizeof(mi));

	byte signature[32] = { 0x48, 0x89 , 0x5C , 0x24 , 0x08 , 0x48 , 0x89 , 0x74 , 0x24 , 0x10 , 0x57 , 0x48 , 0x83 , 0xEC , 0x20 , 0x48 , 0x8D , 0x71 , 0x20 , 0x48 , 0x8B , 0xD9 , 0x48 , 0x8B , 0xCE , 0xE8 , 0x5A , 0x2D , 0xFD , 0xFF , 0x48 , 0x8D };

	byte buff[sizeof(signature)];
	ZeroMemory(buff, sizeof(signature));

	IGlobalInterfaceTable* git = (IGlobalInterfaceTable*)calloc(1, sizeof(IGlobalInterfaceTable*));


	
	for (DWORD i = 0; i < mi.SizeOfImage - sizeof(signature); i++) 
	{

		memcpy(buff, hModuleDMR + i, sizeof(signature));

		if (memcmp(signature, buff, sizeof(signature)) == 0) 
		{

			long(*ptr)(IGlobalInterfaceTable*) = (long(*)(IGlobalInterfaceTable*))(hModuleDMR + i);

			ptr(git);
			i = mi.SizeOfImage;
		}

	}

	
	auto dllGetClassObject = reinterpret_cast<dllGetClassObjectPtr>(GetProcAddress(hDial, "DllGetClassObject"));
	IClassFactory* factory;
	dllGetClassObject(clsid, IID_IClassFactory, &factory);


	// Dial Factory
	result = dllGetClassObject(clsid, IID_IClassFactory, &factory);




	IDialClassFactory* dialFactory = (IDialClassFactory*)factory;

	
	ICastServerControl* serverControl = (ICastServerControl*)calloc(1, sizeof(ICastServerControl*));
	
	result = dialFactory->CreateInstance(NULL, guid3_ICastServerControl, &serverControl);
	serverControl->m_LRef11 = (long long)git;

	
	result = serverControl->SetEnableControl(1);

	getchar();
	int i = 0;

    return 0;
}

