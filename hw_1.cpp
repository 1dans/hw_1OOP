#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
	int amount=0;
public:
	string type="", name = "";
	int amountOfProductsSold=0;
	float price = 0, sale = 0;

	int getAmountOfProduct() {
		return amount;
	}
	
	void calculateFinalPrice(float bonuses) {
		price -= (price * (sale / 100) + bonuses); //������ �������� ���������� � ��������
	}

	void addProduct(int addAmnt) {
		amount += addAmnt;
	}

	void soldProduct(int substrAmnt) {
		if(amount>=0) amount -= substrAmnt;
	}

	

};

class Assistant: public Product {
private:
	float salary=0, hourCost=0, benefit = 0;
	int amountOfClients = 0;
public:
	string name="";
	int workHrs=0;
	
	void setHourCost(float hrCost) {
		hourCost = hrCost;
	}

	void sellProduct(vector<Product> productsSold, float bonuses) {
		calculateFinalPrice(bonuses);
		for (Product product : productsSold) { 
			benefit += product.price * product.amountOfProductsSold;
			soldProduct(product.amountOfProductsSold);
		}
		amountOfClients++;
	}

	void calculateSalary() {
		salary = workHrs * hourCost + benefit * 0.1 + amountOfClients * 20; //� ������� � ��� �� ���� ���� ��
	}

	float getAssistantBenefit() {
		return benefit;
	}

	int getAmountOfClients() {
		return amountOfClients;
	}
};

class Shop: public Assistant {
private:
	string location="";
	int amountOfClientsInShop=0, amountOfProducts=0;
	float shopBenefit=0;
public:
	vector<Assistant> assistants;
	vector<Product> products, allProducts;
	void calculateShopBenefitAndAmountOfClients() {
		for (Assistant assistant : assistants) {
			amountOfClientsInShop += assistant.getAmountOfClients();
			shopBenefit += assistant.getAssistantBenefit();
		}
	}


	void findAmountOfProducts() {
		for (Product product : products) {
			amountOfProducts += product.getAmountOfProduct();
		}
	}

	int getAmountOfProducts() {
		return amountOfProducts;
	}

	string getLocation() {
		return location;
	}
};

class Client : public Shop
{
private:
	string phoneNumber; //����� �������� ��� ������
	float bonuses = 0;
public:
	vector<Product> chosenProducts;
	vector<Shop> shops;

	void onlineShopping() {
		Product product;
		string buyName = "-", location;
		int amount, index = 0, maxamount;
		cout << "������� ������ ��������: ";
		getline(cin, location);
		for (int i = 0; i < shops.size(); ++i) {
			if (shops[i].getLocation() == location) {
				index = i;
			}
		}
		if (index == 0) {
			cout << "�������� �� ����� ������� ����";
			return;
		}
		while (buyName != "") {
			cout << "������ �������: ";
			getline(cin, buyName);
			for (Product searchProduct : allProducts) if (searchProduct.name == buyName) product = searchProduct;
			maxamount = product.getAmountOfProduct();
			cout << "������ ������� (��������: "<<maxamount<<")\n";
			cin >> amount;
			if (amount > maxamount) cout << "���������� ������� ������";
			
			else {
				product.amountOfProductsSold = amount;
				chosenProducts.push_back(product);
			}
		}
	}

};

int main()
{

}
