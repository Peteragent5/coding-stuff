#include <iostream>
#define _WIN32_WINNT 0x0501 //Windows XP & above
#include <windows.h>
#include <tlhelp32.h>
#include <string>
#include <conio.h>
#include <cstdio>
#include <unistd.h>
using namespace std;
//Compile with: g++ -O2 -optl-static SetPriority.cpp -o SetPriority.exe
//https://msdn.microsoft.com/en-us/library/system.diagnostics.process.priorityclass(v=vs.110).aspx
//http://stackoverflow.com/questions/9009333/how-to-check-if-the-program-is-run-from-a-console
const char* LoLClient = "LoLClient.exe";

void SwitchPriority(const char* Name) {
	PROCESSENTRY32 entry;
	HANDLE hProcess = INVALID_HANDLE_VALUE;

    entry.dwSize = sizeof(PROCESSENTRY32);
	HANDLE snapshot = INVALID_HANDLE_VALUE;
    snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (snapshot != INVALID_HANDLE_VALUE && Process32First(snapshot, &entry)) {
		while ( Process32Next(snapshot, &entry) ) {
			if (stricmp(entry.szExeFile, Name) == 0) { //Search for image name
				 hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
				 
				if ( entry.pcPriClassBase == 8 ) { //At Normal Priority
					if( SetPriorityClass(hProcess, IDLE_PRIORITY_CLASS) ) cout <<  Name << " -> Low";
						else cout << "\nError changing priority!";
				}
				else { //At Low Priority
					if( SetPriorityClass(hProcess, NORMAL_PRIORITY_CLASS) ) cout <<  Name << " -> Normal";
						else cout << "\nError changing priority!";
				}
				
				if (snapshot != INVALID_HANDLE_VALUE) CloseHandle(hProcess);
				break; //Stops searching for the target image name
			}
		}
	}
    DWORD dwProcessId;
    GetWindowThreadProcessId(GetConsoleWindow(), &dwProcessId);
    if ( GetCurrentProcessId() == dwProcessId ) getch(); //If run from explorer and has own window 
	
	if (snapshot != INVALID_HANDLE_VALUE) CloseHandle(snapshot);
}

int main(int argc, char* argv[]) {
	SetConsoleTitle("SetPriority");
	SwitchPriority(LoLClient);
	return 0;
}

