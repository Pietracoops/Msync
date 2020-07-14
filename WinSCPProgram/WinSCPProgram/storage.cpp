//	vector <string> PathVector;
//	string path = argv[0];
//	string findexe = ".exe";

//	stringstream ss(path);

//	while (std::getline(ss, path, delimeter))
//	{
//		PathVector.push_back(path);
//	}
//
//	size = PathVector.size();
//	ApplicationInfo.push_back(PathVector[size - 1]);
//	ApplicationInfo.push_back(PathVector[0] + "\\");
//
//	size_t found = ApplicationInfo[1].find(findexe);
//	if (found != std::string::npos)
//	{
//		ApplicationInfo[1] = "";
//	}
//	else
//	{
//		for (int i = 1; i < size - 1; i++)
//		{
//			ApplicationInfo[1] = ApplicationInfo[1] + PathVector[i] + "\\";
//		}
//	}
