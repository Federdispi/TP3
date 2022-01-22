#include <vector>
#include <iostream>
#include <cstring>
#include "produit.h"
#include "client.h"

	Client::Client(std::string prenom, std::string nom, std::string identifiant)
		:_prenom(prenom), _nom(nom), _identifiant(identifiant)
	{
		_panier.clear();
	}

	std::string Client::getPrenom()
	{
		return _prenom;
	}

	std::string Client::getNom()
	{
		return _nom;
	}

	std::string Client::getId()
	{
		return _identifiant;
	}

	void Client::addProduct(Produit produit)
	{
		if (produit.getQuantite() != 0) //Si la quantité est non nulle
	{
		_panier.push_back(produit); //Ajout d'un produit au panier
	}else
		std::cout << "ERREUR: L'article " << produit.getTitre() << " est en rupture de stock" << std::endl << std::endl;
	}

	void Client::clearPanier() //Vider le panier
	{
		_panier.clear();
	}

	void Client::eraseProduct(Produit produit) //Effacer un produit du panier
	{
	for (int i = 0; i < _panier.size(); i++)
		{
			if (produit.getTitre() == _panier[i].getTitre())
				_panier.erase(_panier.begin() + i);
		}
	}


	void Client::changeQuantity(Produit produit, int quantity) //Changer la quantité d'un produit
	{
		int count = getQuantity(produit);
		if (count < quantity)
		{
			for (int i = 0; i < quantity - count; i++)
				addProduct(produit);
		}
		if (count > quantity)
		{
			for (int i = 0; i < count - quantity ; i++)
				eraseProduct(produit);
		}
	}

	int Client::getQuantity(Produit produit) const //Obtenir la quantité
	{
		int count = 0;
		for (int i = 0; i < _panier.size(); i++)
		{
			if(produit.getTitre() == _panier[i].getTitre())
				count++;
		}
		return count;
	}

	std::vector<Produit> Client::getPanier() //Obtenir le panier
	{
		return _panier;
	}


	std::ostream& operator<<(std::ostream& os, const Client& client) //Surcharge de l'opérateur <<
	{
	os << client._prenom << " " << client._nom << std::endl << "Id : " << client._identifiant << std::endl << std::endl << "Panier :" << std::endl;
	for(int i = 0; i < client._panier.size(); i++)
	{
		os << client._panier[i].getTitre() << " " << client.getQuantity(client._panier[i]) << std::endl;
	}
	return os;
	}
