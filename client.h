#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include <iostream>
#include "produit.h"

class Client{
public:
	Client(std::string _prenom, std::string _nom, std::string _identifiant);
	std::string getPrenom();
	std::string getNom();
	std::string getId();
	void addProduct(Produit produit);
	void clearPanier();
	void changeQuantity(Produit produit, int quantity);
	void eraseProduct(Produit produit);
	friend std::ostream& operator<<(std::ostream& os, const Client& client);
	int getQuantity(Produit produit) const;
	std::vector<Produit> getPanier();
private: 
	std::string _prenom;
	std::string _nom;
	std::string _identifiant;
	std::vector<Produit> _panier;
};

#endif