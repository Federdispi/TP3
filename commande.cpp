#include <iostream>
#include <vector>
#include <cstring>
#include "commande.h"

Commande::Commande(Client client, std::string statut)
    :_client(client), _statut(statut)
{
	_purchasedProduct = _client.getPanier(); //Lors dela création d'une commande le panier est équivalent a la commande avant que celui ci ne soit vider 
}
std::string Commande::getStatut() //Retourne le statut de la commande
{
	return _statut;
}

void Commande::setStatut(std::string statut) //Definit le statut de la commande
{
	_statut = statut;
}

std::string Commande::getId() //Retourne l'identifiant du client qui a passé la commande
{
	return _client.getId();
}

std::ostream& operator<<(std::ostream& os, const Commande& commande) //Surcharge de l'opérateur <<
	{
	os << std::endl << commande._client << std::endl << "Commande " << std::endl;

    for(int i = 0; i < commande._purchasedProduct.size(); i++)
	{
		os << commande._purchasedProduct[i].getTitre() << " " << commande._client.getQuantity(commande._purchasedProduct[i]) << std::endl;
	}

    os << commande._statut << std::endl;
	return os;
	}
