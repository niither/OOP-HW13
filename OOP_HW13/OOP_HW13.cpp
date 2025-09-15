#include <iostream>
#include <string>
using namespace std;

// Visa
class Visa {
private:
    string country;
    string validUntil;

public:
	// Constructors
    Visa() {
        country = "";
        validUntil = "";
    }
	Visa(const string& country, const string& validUntil) {
		this->country = country;
		this->validUntil = validUntil;
	}

	// Getters
    string getCountry() const {
        return country; 
    }
    string getValidUntil() const { 
        return validUntil; 
    }

	// Setters
    void setCountry(const string& country) {
        this->country = country; 
    }
    void setValidUntil(const string& validUntil) {
        this->validUntil = validUntil; 
    }

    void printInfo() const {
        cout << "Visa: " << country << ", valid until: " << validUntil << "\n";
    }
};

// Passport
class Passport {
private:
    string fullName;
    string birthDate;
    string passportNumber;

public:
	// Constructors
	Passport() {
		fullName = "";
		birthDate = "";
		passportNumber = "";
	}
	Passport(const string& fullName, const string& birthDate, const string& passportNumber) {
		this->fullName = fullName;
		this->birthDate = birthDate;
		this->passportNumber = passportNumber;
	}

    // Getters
    string getFullName() const {
        return fullName; 
    }
    string getBirthDate() const {
        return birthDate; 
    }
    string getPassportNumber() const { 
        return passportNumber; 
    }

	// Setters
    void setFullName(const string& fullName) { 
        this->fullName = fullName; 
    }
    void setBirthDate(const string& birthDate) {
        this->birthDate = birthDate; 
    }
    void setPassportNumber(const string& passportNumber) {
        this->passportNumber = passportNumber; 
    }

    void printInfo() const {
        cout << "Passport owner: " << fullName << ", birth date: " << birthDate
            << ", number: " << passportNumber << "\n";
    }
};

// Foreign Passport
class ForeignPassport : public Passport {
private:
    Visa visa;

public:
	// Constructors
    ForeignPassport() {
		Passport();
		visa = Visa();
    }
	ForeignPassport(const string& fullName, const string& birthDate, const string& passportNumber, const Visa& visa)
		: Passport(fullName, birthDate, passportNumber) {
		this->visa = visa;
	}

	// Getters and Setters for Visa
    Visa getVisa() const {
        return visa;
    }
    void setVisa(const Visa& visa) {
        this->visa = visa; 
    }

    void printInfo() const {
        Passport::printInfo();
        visa.printInfo();
    }
};

int main() {
    Passport p("Bob Bobbinson", "01.01.2000", "UA123456");
    p.printInfo();

    cout << "------------------------" << "\n";

    Visa v("Germany", "15.09.2026");
    ForeignPassport fp("Bob Bobbinson", "01.01.2000", "FP123456", v);
    fp.printInfo();

    return 0;
}
