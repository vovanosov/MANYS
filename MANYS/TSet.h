#include "TBitField.h"

class TSet {
private:
	int size_U_;
	TBitField tb;
public:
	TSet(int size_U = 0) {
		size_U_ = size_U;
		tb = TBitField(size_U);
	}

	~TSet() {}

	TSet operator=(TSet tmp) {
		tb = tmp.tb;
		size_U_ = tmp.size_U_;
		return *this;
	}

	TSet(const TSet& tmp) {
		tb = tmp.tb;
		size_U_ = tmp.size_U_;
	}

	void Add(int num) {
		if (num >= 0 && num <= size_U_) {
			tb.Add(num, size_U_);
		}
	}

	std::string TSetToString() {
		return tb.Bittostring(size_U_);
	}

	TSet operator | (TSet tmp) {
		if (size_U_ == tmp.size_U_) {
			TSet res(size_U_);
			res.tb = tb | tmp.tb;
			return res;
		}
		else {
			return TSet(0);
		}
	}

	TSet operator & (TSet tmp) {
		if (size_U_ == tmp.size_U_) {
			TSet res(size_U_);
			res.tb = tb & tmp.tb;
			return res;
		}
		else {
			return TSet(0);
		}
	}

	TSet operator ~ () {
		TSet res(size_U_);
		res.tb = ~tb;
		return res;
	}
};
