#ifndef MAGASIN_H
#define MAGASIN_H

#include <vector>
#include <iostream>
#include "produit.h"
#include "client.h"

class Magasin {
public:
	Magasin();
	void addProduit(Produit* produit);
	void showAll();
	void showByName(std::string name);
	void updateQuantity(std::string name);
	Produit* getProduct(int index);
	void addClient(Client* client);
	void showAllClients();
	void showClientByName(std::string name);
	void showClientById(std::string id);
	void addToCart(Client* client, Produit* produit);
	void removeFromCart(Client* client, Produit* produit);
	void updateQuantityInCart(Client* client, Produit produit, int quantity);
private: 
	std::vector<Produit*> _produits;
	std::vector<Client*> _clients;
	//std::vector<Commande> _commandes;
};

#endif