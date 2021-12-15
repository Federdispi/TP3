#ifndef MAGASIN_H
#define MAGASIN_H

#include <vector>
#include <iostream>
#include "produit.h"

class Magasin {
public:
	Magasin();
	void addProduit(Produit* produit);
	void showAll();
	void showByName(std::string name);
	void updateQuantity(std::string name);
	Produit* getProduct(int index);
private: 
	std::vector<Produit*> _produits;
	//std::vector<Client> _clients;
	//std::vector<Commande> _commandes;
};

#endif