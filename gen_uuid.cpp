#include <stdio.h>
#include <string>
#include <iostream>

#ifdef WIN32
#include <objbase.h>
#else
#include <uuid/uuid.h>
#endif

using namespace std;

#define MAX_LEN 128

/*
**@brief: get windows guid or linux uuid
**@return: string type windows guid or linux uuid
*/
string GetGuid()
{
	char szuuid[MAX_LEN] = {0};
#ifdef WIN32
	GUID guid;
	CoCreateGuid(&guid);
	_snprintf_s(
		szuuid,
		sizeof(szuuid),
		"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
		guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1],
		guid.Data4[2], guid.Data4[3],
		guid.Data4[4], guid.Data4[5],
		guid.Data4[6], guid.Data4[7]);
#else
	uuid_t uuid;
	uuid_generate(uuid);
	uuid_unparse(uuid, szuuid);

#endif

	return std::string(szuuid);
}

int main()
{

	string strGuid  = GetGuid();
	cout << strGuid.c_str() << endl;

	return 0;
}

