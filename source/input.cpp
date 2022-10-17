/*
 *	DESCRIPTION:	Read input data for a simulation from the file 'settings_file.txt'
 *
 */


#include "input.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include <iostream>

using namespace std;


void settingsfile :: read_settings_file ()
{
	ifstream fin("settings_file.txt");
	string line;
	while (getline(fin, line))
	{
		istringstream iss(line);
		string inputname;

		iss >> inputname;

		if (inputname == "length") iss >> length;

		if (inputname == "numGC") iss >> numGC;

		if (inputname == "lsnumGC") iss >> lsnumGC;

		if (inputname == "lslength") iss >> lslength;

		if (inputname == "fluid1_gamma") iss >> fluid1_gamma;

		if (inputname == "fluid1_B") iss >> fluid1_B;

		if (inputname == "fluid2_gamma") iss >> fluid2_gamma;

		if (inputname == "fluid2_B") iss >> fluid2_B;

		if (inputname == "CFL") iss >> CFL;

		if (inputname == "output") iss >> output;
		
		if (inputname == "RS_pure") iss >> RS_pure; 

		if (inputname == "RS_mixed") iss >> RS_mixed;
	
		if (inputname == "FS") iss >> FS;

		if (inputname == "GFM") iss >> GFM;
		
		if (inputname == "IC") iss >> IC;

		if (inputname == "eos1") iss >> eos1;

		if (inputname == "eos2") iss >> eos2;

		if (inputname == "BC_L") iss >> BC_L;
		
		if (inputname == "BC_R") iss >> BC_R;

		if (inputname == "sim") iss >> sim;

		if (inputname == "outputpath") iss >> outputpath;


	}

	basename = outputpath + GFM + "_" + FS + "_" + RS_pure + "_" + RS_mixed + "_" + IC + "_" 
		+ eos1 + "-" + eos2 + "_" + std::to_string(length) + "_";

	if (sim == "onefluid") basename = outputpath + "onefluid_" + FS + "_" + RS_pure + "_" + IC + "_" + eos1 + "_" + std::to_string(length) + "_";
	
	fin.close();
}
