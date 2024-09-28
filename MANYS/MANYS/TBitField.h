#include <iostream>
#include <string>

//using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class TBitField
{
private:
	unsigned _int32* mem;
	int size;
	/*int GetNumberMem(int k);
	int GetBit(int k);*/

public:
	TBitField(int szU = 0) {
		size = szU / (sizeof(unsigned _int32) * 8) + 1;
		mem = new unsigned _int32[size];
		for (int i = 0; i < size; i++)
			mem[i] = 0;
	}

	~TBitField() {
		delete[] mem;
	}

	TBitField(const TBitField& tmp) {
		size = tmp.size;
		mem = new unsigned _int32[size];
		for (int i = 0; i < size; i++)
			mem[i] = tmp.mem[i];
	}

	TBitField& operator=(TBitField tmp) {
		if (size != tmp.size) {
			if (size != 0)
				delete[] mem;
			size = tmp.size;
			mem = new unsigned _int32[size];
		}
		for (int i = 0; i < size; i++)
			mem[i] = tmp.mem[i];

		return *this;
	}

	int GetNumberMem(int k) {
		return (k - 1) / (sizeof(unsigned _int32) * 8);
	}

	int GetBit(int k) {
		return (k - 1) % (sizeof(unsigned _int32) * 8);
	}

	void Add(int k, int sizeU) {
		if (k >= 0 && k <= sizeU) {
			int l = GetNumberMem(k);
			int  m = GetBit(k);
			mem[l] = mem[l] | (1 << m);
			//std::cout << l << " " << m << " " << mem[l] << std::endl;
		}
	}

	std::string Bittostring(int sizeU)
	{

		std::string str = "";
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < sizeof(unsigned _int32) * 8; j++)
			{
				if (i * sizeof(unsigned _int32) * 8 + j + 1 <= sizeU)
				{

					if (mem[i] & (1 << j))
					{
						str = str + "  " + std::to_string(i * sizeof(unsigned _int32) * 8 + j + 1);
						//cout << i << endl;
					}
				}
			}
		}

		return str;
	}
	TBitField operator|(TBitField tmp)
	{
		TBitField res(*this);
		//cout << res.Bittostring(161) << endl;
		for (int i = 0; i < size; i++)
		{
			res.mem[i] = mem[i] | tmp.mem[i];
		}
		//cout << res.Bittostring(161) << endl;
		return res;
	}

	TBitField operator&(TBitField tmp)
	{
		TBitField res(*this);
		//cout << res.Bittostring(161) << endl;
		for (int i = 0; i < size; i++)
		{
			res.mem[i] = mem[i] & tmp.mem[i];
		}
		//cout << res.Bittostring(161) << endl;
		return res;
	}

	TBitField operator~()
	{
		TBitField res(*this);
		for (int i = 0; i < size; i++)
		{
			res.mem[i] = ~mem[i];
		}
		return res;
	}
};
