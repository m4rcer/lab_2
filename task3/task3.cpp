#include <stdio.h>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <windows.h>
#include <filesystem>
#include <experimental/filesystem>

using namespace std;

class Car {
public:
	Car() {}
	Car(string firm, string model, int number,
		int price, int year, int mileage)
		: Firm(firm), Model(model), Number(number),
		Price(price), Year(year), Mileage(mileage)
	{}

	string GetFirm() const { return Firm; };
	string GetModel() const { return Model; };
	int GetNumber() const { return Number; };
	int GetPrice() const { return Price; };
	int GetYear() const { return Year; };
	int GetMileage() const { return Mileage; };


	void SetFirm(string firm) { Firm = firm; };
	void SetModel(string model) { Model = model; };
	void SetNumber(int number) {
		if (number < 0)
			throw exception("number can't be negative");
		Number = number;
	};
	void SetPrice(int price) {
		if (price < 0)
			throw exception("price can't be negative");
		Price = price;
	};
	void SetYear(int year) {
		if (year < 1886)
			throw exception("year can't be less than 1886");
		Year = year;
	};
	void AddMileage(int mileage) {
		if (mileage < 0)
			throw exception("mileage can't be negative");
		Mileage += mileage;
	};

	void Serialize(string path = "car.txt") {
		nlohmann::json j{};
		j["Firm"] = this->Firm;
		j["Model"] = this->Model;
		j["Number"] = this->Number;
		j["Price"] = this->Price;
		j["Year"] = this->Year;
		j["Mileage"] = this->Mileage;

		string serializedString = j.dump();

		ofstream out;
		out.open(path);
		if (out.is_open())
		{
			out << serializedString << std::endl;
		}
		out.close();
	}

	void Deserialize(string path = "car.txt") {

		string serializedLine;

		ifstream in(path);
		if (in.is_open())
		{
			while (getline(in, serializedLine))
			{
				std::cout << serializedLine << std::endl;
			}
		}
		in.close();

		nlohmann::json j = nlohmann::json::parse(serializedLine);

		this->Firm = j["Firm"].get<string>();
		this->Model = j["Model"].get<string>();
		this->Number = j["Number"].get<int>();
		this->Price = j["Price"].get<int>();
		this->Year = j["Year"].get<int>();
		this->Mileage = j["Mileage"].get<int>();
	}

	void Print() {
		cout << Firm << " " << Model << " " << Number << " " << Year << " Mileage: " << Mileage << endl;
	}

private:
	string Firm{ "" };
	string Model{ "" };
	int Number{ 0 };
	int Price{ 0 };
	int Year{ 0 };
	int Mileage{ 0 };
};

void immitateTrips(Car* carArr, size_t N) {
	srand(unsigned(time(0)));
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			carArr[j].AddMileage(rand() % 3000 + 300);
		}
	}
}

void SortByMillage(Car* carArr, size_t N) {
	Car temp;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (carArr[j].GetMileage() < carArr[j + 1].GetMileage()) {
				temp = carArr[j];
				carArr[j] = carArr[j + 1];
				carArr[j + 1] = temp;
			}
		}
	}
}

void SortByYear(Car* carArr, size_t N) {
	Car temp;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (carArr[j].GetYear() < 2011) {
				temp = carArr[j];
				carArr[j] = carArr[j + 1];
				carArr[j + 1] = temp;
			}
		}
	}
}

void SortCars(Car* carArr, size_t N) {
	SortByMillage(carArr, N);
	SortByYear(carArr, N);
}

void PrintCars(Car* carArr, size_t N) {
	for (size_t i = 0; i < N; i++)
	{
		carArr[i].Print();
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	Car* car1 = new Car();

	Car* carArr = new Car[3];
	carArr[0].SetFirm("Subaru");
	carArr[0].SetModel("Forester");
	carArr[0].SetNumber(1);
	carArr[0].SetYear(2022);
	carArr[0].SetPrice(10000);

	carArr[1].SetFirm("Renault");
	carArr[1].SetModel("Duster");
	carArr[1].SetNumber(1);
	carArr[1].SetYear(2001);
	carArr[1].SetPrice(10000);

	carArr[2].SetFirm("Volkswagen");
	carArr[2].SetModel("Polo");
	carArr[2].SetNumber(1);
	carArr[2].SetYear(2012);
	carArr[2].SetPrice(10000);

	Car* car = new Car("Volkswagen", "Polo", 1, 2022, 10000, 0);

	immitateTrips(carArr, 3);
	SortCars(carArr, 3);
	PrintCars(carArr, 3);
}
