#include <iostream>
#include <vector>
#include <cstring>
#include "commande.h"

Commande::Commande(Client client, std::string statut)
    :_client(client), _statut(statut)
{
	_purchasedProduct = _client.getPanier();
}

std::ostream& operator<<(std::ostream& os, const Commande& commande)
	{
	os << std::endl << commande._client << std::endl << "Commande " << std::endl;

    for(int i = 0; i < commande._purchasedProduct.size(); i++)
	{
		os << commande._purchasedProduct[i].getTitre() << " " << commande._client.getQuantity(commande._purchasedProduct[i]) << std::endl;
	}

    os << commande._statut << std::endl;
	return os;
	}
