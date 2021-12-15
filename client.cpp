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
		if(produit.getQuantite() != 0)
			_panier.push_back(produit);
	}

	void Client::clearPanier()
	{
		_panier.clear();
	}

	void Client::eraseProduct(Produit produit)
	{
	for (int i = 0; i < _panier.size(); i++)
		{
			if (produit.getTitre() == _panier[i].getTitre() == 0)
				_panier.erase(_panier.begin() + i);
		}
	}


	void Client::changeQuantity(Produit produit, int quantity)
	{
		int count = getQuantity(produit);
		// for (int i = 0; i < _panier.size(); i++)
		// {
		// 	if (produit.getTitre() == _panier[i].getTitre() == 0)
		// 		count++;
		// }
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

	int Client::getQuantity(Produit produit) const
	{
		int count = 0;
		for (int i = 0; i < _panier.size(); i++)
		{
			if(produit.getTitre() == _panier[i].getTitre())
				count++;
		}
		return count;
	}


	std::ostream& operator<<(std::ostream& os, const Client& client)
	{
	os << client._prenom << " " << client._nom << std::endl << "Id : " << client._identifiant << std::endl << std::endl;
	for(int i = 0; i < client._panier.size(); i++)
	{
		os << client._panier[i].getTitre() << " " << client.getQuantity(client._panier[i]) << std::endl;
	}
	return os;
	}

