#include <iostream>
#include <list>
using namespace std;

class Exchange {
private:
	string Bitcoin;
	int price_Bitcoin;
	string Ethereum;
	int price_Ethereum;
	string XRP;
	int price_XRP;
	string Bitcoin_Cash;
	int price_Bitcoin_Cash;
	string Litecoin;
	int price_Litecoin;

	list<Buyer*> buyers;

public:
	Exchange(string name, double price,
		string name2, double price2,
		string name3, double price3,
		string name4, double price4,
		string name5, double price5 ) {
		Bitcoin = name;
		price_Bitcoin = price;

		Ethereum = name2;
		price_Ethereum = price2;

		XRP = name3;
		price_XRP = price3;

		Bitcoin_Cash = name4;
		price_Bitcoin_Cash = price4;

		Litecoin = name5;
		price_Litecoin = price5;
	}
	void Attach(Buyer* pBuyer) {
		buyers.push_back(pBuyer);
	}
	void Detach(Buyer* pBuyer) {
		for (auto it = buyers.begin(); it != buyers.end(); it++){
			if (*it == pBuyer)
				buyers.erase(it); return;
		}
	}
	void Notify() {
		for (auto it = buyers.begin(); it != buyers.end(); it++){
			(*it)->Update(this);
		} cout << endl;
	}

public:

	string GetNameBitcoin() const {
		return Bitcoin;
	}
	string GetNameEthereum() const {
		return Ethereum;
	}
	string GetNameXRP() const {
		return XRP;
	}
	string GetNameBitcoin_Cash() const {
		return Bitcoin_Cash;
	}
	string GetNameLitecoin() const {
		return Litecoin;
	}
	int GetPriceBitcoin() const {
		return price_Bitcoin;
	}
	int GetPriceEthereum() const {
		return price_Ethereum;
	}
	int GetPriceXRP() const {
		return price_XRP;
	}
	int GetPriceBitcoin_Cash() const {
		return price_Bitcoin_Cash;
	}
	int GetPriceLitecoin() const {
		return price_Litecoin;
	}
};

class Buyer {
public:
	virtual void Update(Exchange*) = 0;
};

class UkrainianBuyer : public Buyer {
private:
	Exchange* ptr;
	string name;
	int money = 100000;
public:
	UkrainianBuyer(string pName, int pMoney) {
		name = pName;
		money = pMoney;
	}
	Exchange* GetProduct() const {
		return ptr;
	}
	void SetProduct(Exchange* pProduct) {
		ptr = pProduct;
	}
	void Update(Exchange* pProduct) {

	}
};

int name() {

	return 0;
}