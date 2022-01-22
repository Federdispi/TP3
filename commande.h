#ifndef COMMANDE_H
#define COMMANDE_H

#include <iostream>
#include <vector>
#include "client.h"

class Commande{
public:
	Commande(Client _client, std::string _statut);
	std::string getStatut();
	void setStatut(std::string statut);
	std::string getId();
	friend std::ostream& operator<<(std::ostream& os, const Commande& commande);
private:
    Client _client;
	std::vector<Produit> _purchasedProduct;
    std::string _statut;
};

#endif