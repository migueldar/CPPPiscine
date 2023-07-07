#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string fN, std::string lN, std::string nick, int nbr, std::string sec): firstName(fN), lastName(lN), nickname(nick), number(nbr), secret(sec){

}

Contact::~Contact() {

}

std::string Contact::truncate(std::string str){
	if (str.length() <= 10)
		return str;
	while (str.length() > 9)
		str.pop_back();
	str.push_back('.');
	return str;
}

std::string Contact::getTruncatedFirstName(){
	return Contact::truncate(this->firstName);
}
std::string Contact::getTruncatedLastName(){
	return Contact::truncate(this->lastName);
}
std::string Contact::getTruncatedNickname(){
	return Contact::truncate(this->nickname);
}