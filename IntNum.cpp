#include "IntNum.h"



IntNum::IntNum()
{
	base_10_int = 0;
}


IntNum::~IntNum()
{
}

int changIntoBase10(string str, int base)
{
	int temp = 0;
	int sign = 1;
	/*if (str[0] == 32)
	{
		sign = -1;
		str[0] = '0';
	}*/
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == 32)
			str.erase(i);
		if (str[i] < 'A')
			temp = temp + ((int)str[i] - 48)*pow(base, str.length() - i - 1);
		else
			if (str[i] < 'a')
				temp = temp + ((int)str[i] - 55)*pow(base, str.length() - i - 1);
			else
				temp = temp + ((int)str[i] - 87)*pow(base, str.length() - i - 1);
	}
	return temp;
}

bool IntNum::input()
{
	/*cout << "Chose type base: \n1.Bin\t2.Dec\n3.Oct\t4.Hex\n0.Exit\nYour Choice ->";
	int opt;
	cin >> opt;
	switch (opt)
	{
	case 1:
	{*/
		string tmp;
		cout << "Input Binary string: ";
		cin.ignore();
		getline(cin,tmp);
		
		base_10_int = changIntoBase10(tmp, 2);
	//	break;
	/*}

	case 2: 
		cout << "Input value: ";
		cin >> base_10_int;
		break;

	case 3:
	{
		string tmp;
		cout << "Input value: ";
		cin.ignore();
		getline(cin, tmp);
		base_10_int = changIntoBase10(tmp, 8);
		break;
	}
	case 4:
	{
		string tmp;
		cout << "Input value: ";
		cin.ignore();
		getline(cin, tmp);
		base_10_int = changIntoBase10(tmp, 16);
		break;
	}
	default:
		cout << "Syntax Error\nGood Bye!";
		return false;
		break;
	}*/
	return true;
}

void IntNum::outputBase()
{
	cout << "Base 2: " << bitset <8 * sizeof(base_10_int)>(base_10_int) << '\n';
	cout << "Base 8: " << oct << base_10_int << '\n';
	cout << "Base 10: " << dec << (unsigned int) base_10_int << " (usigned int) \n";
	cout << "Base 16: " << hex << base_10_int << '\n';
	cout << dec;
}

void IntNum::output()
{
	outputBase();
	cout << "Over 19: " << 2019 - base_10_int;
	cout << "One Complement: " << oneComplement() << '\n';
	cout << "Two Complement: " << twoComplement() << '\n';
	cout << "Sign Magnitude: "; SignMagnitude();
	cout << "Float: " << singlePrecisionfloat();
}

int & IntNum::overK()
{
	IntNum K;
	cout << "\ninput K: ";
	K.input();
	int temp = base_10_int;
	temp = temp - K.base_10_int;
	return temp;

	// TODO: insert return statement here
}

int IntNum::oneComplement()
{
	int dec = base_10_int;
	unsigned int temp = ~dec;
	return temp;
}

int IntNum::twoComplement()
{
	int dec = base_10_int;
	unsigned int temp = (~dec+1);
	return temp;
}

string IntNum::SignMagnitude()
{
	char ans[64]="";
	if (!((base_10_int >> 31) & 1U))
	{
		//ans	= itoa(base_10_int, ans, 10);
		cout << base_10_int;
		return ans;
	}
	int number = base_10_int;
	number ^= (-0^ number) & (1UL << 1);
//	itoa( (unsigned int) number, ans, 10);
	for (int i = 64; i > 0; ++i);
		//ans[i] = ans[i - 1];
	ans[0] = '-';
	cout << ans << (unsigned int)number;
	return ans;
}

float IntNum::singlePrecisionfloat()
{
	ofstream fout("cache.bin", ios::out | ios::binary);
	fout.write((char*)&base_10_int, sizeof(unsigned int) );
	fout.close();
	
	float base_10_float;
	ifstream fin("cache.bin", ifstream::binary);
	fin.read((char*)&base_10_float, sizeof(float));
	fin.close();

	return base_10_float;
}

int IntNum::saveFile()
{
	cout << "Input file name:\n->";
	string file_name;
	getline(cin, file_name);
	int result = saveFile(file_name);
	return result;
}

int IntNum::saveFile(string file_name)
{
	cout << "N= ";
	int n;
	cin >> n;
	ofstream fout("cache.bin", ios::out | ios::binary | ios::ate);
	fout.write((char*)&base_10_int, n );
	fout.close();

	return 0;
}

IntNum & operator-(IntNum & a, IntNum b)
{
	IntNum temp;
	temp.base_10_int = a.base_10_int - b.base_10_int;
	return temp;
}

istream & operator>>(istream & ist, IntNum a)
{
	ist >> a.base_10_int;
	return ist;
	// TODO: insert return statement here
}
