#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream> 
#include <windows.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <Psapi.h>

using namespace std;


string ConsoleCommand(string Command, bool printOutput, vector <string> &ApplicationInfo)
{
	ofstream fout;
	FILE* pipe;
	char psBuffer[2048];
	psBuffer[0] = 0;													
	string Output;
	pipe = _popen(Command.c_str(), "r");								

	if (pipe)
	{
		while (!feof(pipe))
		{
			if (fgets(psBuffer, 2048, pipe) != NULL)
			{
				Output.append(psBuffer);
				if (printOutput == true) cout << psBuffer;
			}
		}
	}

	if (printOutput == true)
	{
		fout.open(ApplicationInfo[1] + "msync.log");
		fout << Output << endl;
		fout.close();
	}

	Output = Output.substr(0, Output.length() - 1);					
	psBuffer[0] = 0;													


	return Output;
}

int CallMenu(int argc, TCHAR* argv[], string &Option, string &host, string &remoteUser, string &remotePassword, string &localPath, string &remotePath)
{

	string FunctionInput;


		if (argv[1] != ('\0'))
		{
			FunctionInput = argv[1];
		}
		else
		{
			FunctionInput = "";
		}


		if (FunctionInput.compare("-h") == 0 || FunctionInput.compare("-help") == 0 || FunctionInput.compare("--h") == 0)
		{
		help:
			cout << "-----------------------USAGE------------------------" << endl;
			cout << "msync [OPTION]...[HOST]...[USER]...[PASSWORD]...[SRC]...[DEST]" << endl;
			cout << "OPTIONS:" << endl;
			cout << "synchronize    .....................Update Destination with Source" << endl;

			return 1;
		}
		else if (FunctionInput.compare("synchronize") == 0)
		{
			Option = argv[1];
			host = argv[2];
			remoteUser = argv[3];
			remotePassword = argv[4];
			localPath = argv[5];
			remotePath = argv[6];
			return 0;
		}
		else if (FunctionInput.compare("") == 0)
		{
			cout << "Invalid Option" << endl;
			goto help;
		}
		else
		{
			cout << "Invalid Option" << endl;
			goto help;
		}

	return 1;
}



void GetPathAndApplicationName(vector <string> &ApplicationInfo)
{
	//ApplicationInfo [0] = Application Name
	//ApplicationInfo [1] = Application Path

	HANDLE hProcess = GetCurrentProcess();
	char psBuffer[2048];

	GetModuleBaseName(hProcess, NULL, psBuffer, 2048);
	ApplicationInfo.push_back(psBuffer);
	psBuffer[0] = 0;

	GetModuleFileName(NULL, psBuffer, 2048);
	ApplicationInfo.push_back(psBuffer);
	size_t found = ApplicationInfo[1].find(ApplicationInfo[0]);
	ApplicationInfo[1] = ApplicationInfo[1].substr(0, found - 1) + "\\";
	psBuffer[0] = 0;

}

void Delete(string Filename)
{
	if (remove(Filename.c_str()) != 0)
	{
		//cout << "Error deleting file: " << Filename << endl;
	}
	else
	{
		//cout << "File successfully deleted: " << Filename << endl;
	}

}


int main(int argc, TCHAR* argv[])
{

//--------------INITIALIZATION-------------------------------------------------------------------------------------------------------------------------
	string command;																																	//|
	ofstream fout;																																	//|
	string remoteUser = "User";																														//|
	string remotePassword = "Password";																												//|
	string key;																																		//|
	string hash;																																	//|
	string host;																																	//|
	string hostkey;																																	//|
	string localPath;																																//|
	string remotePath;																																//|
	string keyFile = "key.txt";																														//|
	string scriptFile = "script.txt";																												//|
	string consoleOutput;																															//|
	string Option;																																	//|
	vector <string> ApplicationInfo;																												//|
	bool logging = false;																															//|
//-----------------------------------------------------------------------------------------------------------------------------------------------------



//--------------GET EXECUTABLE INFO--------------------------------------------------------------------------------------------------------------------
	GetPathAndApplicationName(ApplicationInfo);																										//|
//-----------------------------------------------------------------------------------------------------------------------------------------------------


//--------------CALL CONSOLE MENU----------------------------------------------------------------------------------------------------------------------
	if (CallMenu(argc, argv, Option, host, remoteUser, remotePassword, localPath, remotePath) == 1) return 1;										//|
																																					//|
//-----------------------------------------------------------------------------------------------------------------------------------------------------


//--------------GET KEY--------------------------------------------------------------------------------------------------------------------------------
	//ssh-keyscan -t ed25519																														//|
	//ssh-keyscan -t rsa -b 4096																													//|
	//ssh-keyscan -t dsa																															//|
	//ssh-keyscan -t ecdsa -b 521																													//|
																																					//|
	//https://www.ssh.com/ssh/keygen/																												//|
//	cout << "Fetching session key..." << endl;																										//|
	key = ConsoleCommand("ssh-keyscan -t ed25519 " + host, false, ApplicationInfo);																	//|
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//--------------STORE KEY IN FILE----------------------------------------------------------------------------------------------------------------------
//	cout << "Storing Key" << endl;																													//|
	fout.open(ApplicationInfo[1] + keyFile);																										//|
	fout << key;																																	//|
	fout.close();																																	//|
//-----------------------------------------------------------------------------------------------------------------------------------------------------


//--------------GET HASH FROM KEY FILE-----------------------------------------------------------------------------------------------------------------
//	cout << "Hashing Key" << endl;																													//|
	hash = ConsoleCommand("ssh-keygen -l -f " + ApplicationInfo[1] + keyFile + " -E md5", false, ApplicationInfo);									//|																																					//|
	//String manipulation																															//|
	hash = hash.substr(0, hash.length() - host.length() - 11);																						//|
	hash = hash.substr(8, hash.length());																											//|
	//cout << hash << endl;	//for debugging																											//|
//-----------------------------------------------------------------------------------------------------------------------------------------------------



//--------------WRITe SCRIPT TO FILE-------------------------------------------------------------------------------------------------------------------
//	cout << "Creating Script file" << endl;																											//|
	hostkey = "ssh-ed25519 256 " + hash;																											//|
																																					//|
	fout.open(ApplicationInfo[1] + scriptFile);																										//|
	fout << "open sftp://" + remoteUser + ":" + remotePassword + "@" + host + " -hostkey=\"" + hostkey + "\"" << endl;	//connect					//|
	fout << "synchronize remote -mirror " + localPath + " " + remotePath << endl;										//syncrhonize directory		//|
	fout << "close" << endl;																							//Disconnect				//|
	fout << "exit" << endl;																								//Exit Winscp				//|
	fout.close();																																	//|
																																					//|
//-----------------------------------------------------------------------------------------------------------------------------------------------------



//--------------CALL WinSCP SCRIPT---------------------------------------------------------------------------------------------------------------------
																																					//|
//	cout << "Executing WinSCP" << endl;																												//|
	consoleOutput = ConsoleCommand(ApplicationInfo[1] + "WinSCP.com /ini=nul /script=" + ApplicationInfo[1] + "script.txt", true, ApplicationInfo);	//|
																																					//|
//-----------------------------------------------------------------------------------------------------------------------------------------------------



//--------------CLEANING UP----------------------------------------------------------------------------------------------------------------------------
	Delete(ApplicationInfo[1] + keyFile);																											//|
	Delete(ApplicationInfo[1] + scriptFile);																										//|
//-----------------------------------------------------------------------------------------------------------------------------------------------------



	//system("pause");
	return 0;
}