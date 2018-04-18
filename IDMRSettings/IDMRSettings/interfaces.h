#pragma once
#include "wrl\implements.h"

interface ICastAppLaunchCallback : IUnknown
{

};

class IDMRSettings
{
protected:
	long long m_LRef;

public:


	IDMRSettings(void);
	~IDMRSettings(void);

	//IUnknown
	virtual HRESULT QueryInterface(_GUID const &, void * *) = 0;
	virtual ULONG AddRef(void) = 0;
	virtual ULONG Release(void) = 0;

	//Implementation


};


class IDMRSettingsEventNotify
{
protected:
	long long m_LRef;

public:


	IDMRSettingsEventNotify(void);
	~IDMRSettingsEventNotify(void);

	//IUnknown
	virtual HRESULT QueryInterface(_GUID const &, void * *) = 0;
	virtual ULONG AddRef(void) = 0;
	virtual ULONG Release(void) = 0;

	//Implementation


};



class ICastServerControl
{
protected:
	long long m_LRef;

public:


	long long m_LRef0;
	long long m_LRef1;
	long long m_LRef2;
	long long m_LRef3;
	long long m_LRef4;
	long long m_LRef5;
	long long m_LRef6;
	long long m_LRef7;
	long long m_LRef8;
	long long m_LRef9;
	long long m_LRef10;
	long long m_LRef11;
	long long m_LRef12;
	long long m_LRef13;
	long long m_LRef14;
	long long m_LRef15;
	long long m_LRef16;
	long long m_LRef17;
	long long m_LRef18;
	long long m_LRef19;
	long long m_LRef20;
	long long m_LRef21;
	long long m_LRef22;
	long long m_LRef23;
	long long m_LRef24;
	long long m_LRef25;
	long long m_LRef26;
	long long m_LRef27;
	long long m_LRef28;
	long long m_LRef29;
	long long m_LRef30;
	long long m_LRef31;
	long long m_LRef32;
	long long m_LRef33;
	long long m_LRef34;
	long long m_LRef35;


	ICastServerControl(void);
	~ICastServerControl(void);

	//IUnknown
	virtual HRESULT QueryInterface(_GUID const &, void * *) = 0;
	virtual ULONG AddRef(void) = 0;
	virtual ULONG Release(void) = 0;

	//Implementation
	virtual HRESULT StartCastServer(void) = 0;
	virtual HRESULT StopCastServer(void) = 0;
	virtual HRESULT Advise(ICastAppLaunchCallback *) = 0;
	virtual HRESULT Unadvise(ICastAppLaunchCallback *) = 0;
	virtual HRESULT GetEnableControl(int *) = 0;
	virtual HRESULT SetEnableControl(int) = 0;
	virtual HRESULT PutSettings(IUnknown *) = 0;

};


class IDialClassFactory
{
protected:
	long m_LRef;
public:

	IDialClassFactory(void);
	~IDialClassFactory(void);

	//IUnknown
	virtual HRESULT QueryInterface(_GUID const &, void * *) = 0;
	virtual ULONG AddRef(void) = 0;
	virtual ULONG Release(void) = 0;

	//Implementation
	virtual HRESULT CreateInstance(IUnknown*, const IID&, ICastServerControl **) = 0;
	virtual HRESULT LockServer(BOOL) = 0;

};
