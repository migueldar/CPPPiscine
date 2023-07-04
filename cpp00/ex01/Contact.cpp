#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string fN, std::string lN, std::string nick, long long int nbr, std::string sec): firstName(fN), lastName(lN), nickname(nick), number(nbr), secret(sec){

}

Contact::~Contact() {

}