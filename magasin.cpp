#include "magasin.h"

Magasin::Magasin()
{
	_produits.clear();
}

void Magasin::addProduit(Produit* produit) //Ajout d'un produit au magasin
{
	bool c = 0;
	std::vector<Produit*>::iterator it;
	for(it = _produits.begin(); it != _produits.end(); it++)
	{
		if((*it)->getTitre() == produit->getTitre())
			c = 1;
	}

	if(!c)
		_produits.push_back(produit);
}

void Magasin::showAll() //Affiche les produits du magasin
{
	for(int i = 0; i < _produits.size(); i++)
		std::cout << i + 1 << ") " << *_produits[i];
}

void Magasin::showByName(std::string name) //Affiche un produit grâce à son nom
{
	std::vector<Produit*>::iterator it;
	for(it = _produits.begin(); it != _produits.end(); it++)
	{
		if((*it)->getTitre() == name)
			std::cout << **it;
	}
}

void Magasin::updateQuantity(std::string name) //Change la quantité d'un produit
{
	std::vector<Produit*>::iterator it;
	for(it = _produits.begin(); it != _produits.end(); it++)
	{
		if((*it)->getTitre() == name)
		{
			int quantite;
			std::cout << "Produits disponibles : " << (*it)->getQuantite() << std::endl;
			std::cout << "Nouvelle quantite : ";
			std::cin >> quantite;
			(*it)->setQuantite(quantite);
			std::cout << "Ok." << std::endl << std::endl;
		}
	}
}

Produit* Magasin::getProduct(int index) //Retourne la quantité d'un produit
{
	return _produits[index];
}

void Magasin::addClient(Client* client) //Ajoute un client au magasin
{
	bool b = 0;
	std::vector<Client*>::iterator it;
	for(it = _clients.begin(); it!=_clients.end(); it++)
	{
		if((*it)->getId() == client->getId())
			b = 1;
	}
	if(!b)
		_clients.push_back(client);
}

void Magasin::showAllClients() //Affiche tous les clients
{
	for(int i = 0; i < _clients.size(); i++)
		std::cout << i + 1 << ") " << *_clients[i];
}

void Magasin::showClientByName(std::string name) //Affiche un client grâce à son nom
{
	std::vector<Client*>::iterator it;
	for(it = _clients.begin(); it != _clients.end(); it++)
	{
		if((*it)->getNom() == name)
			std::cout << **it;
	}
}

void Magasin::showClientById(std::string id) //Affiche un client grâce à son identifiant
{
	std::vector<Client*>::iterator it;
	for(it = _clients.begin(); it != _clients.end(); it++)
	{
		if((*it)->getId() == id)
			std::cout << **it;
	}
}

void Magasin::addToCart(Client* client, Produit* produit) //Ajoute un produit au panier d'un client
{
	if (produit->getQuantite() != 0)
	{
		client->addProduct(*produit);
		produit->setQuantite(produit->getQuantite()-1);
	}else
		std::cout << "ERREUR: L'article " << produit->getTitre() << " est en rupture de stock" << std::endl;
}

void Magasin::removeFromCart(Client* client, Produit* produit) //Retire un produit du panier d'un client
{
	if(client->getQuantity(*produit) != 0)
	{
		client->eraseProduct(*produit);
		produit->setQuantite(produit->getQuantite()+1);
	}
}

void Magasin::updateQuantityInCart(Client* client, Produit produit, int quantity) //Chnage la quantité d'un produit dans le panier d'un client
{
	client->changeQuantity(produit, quantity);
}

int Magasin::validOrder(Client* client) //Valide un panier en vue d'une commande
{
	int valid = 0;
	do{
	std::cout << "Souhaitez vous valider le panier ?" << std::endl << "1. Oui" << std::endl << "0. Non" << std::endl;
	std::cin >> valid;
	std::cout << std::endl;
	}while (valid != 1 && valid != 0);
	if (valid == 0)
	{
		std::cout << "Annulation panier" << std::endl;
		return 1;
	}
	else
		return 2;
}

void Magasin::updateStatut(Commande* commande) //Met a jours le statut d'une commande
{
	int update = 0, statutNumber = 0;
	do{
	std::cout << "Souhaitez vous changer le statut de la commande ?" << std::endl;
	std::cout << "1. Oui	0. Non" << std::endl;
	std::cin >> update;
	std::cout << std::endl;
	}while (update != 1 && update != 0);

	if (update == 1)
	{
		do{
		if (update == 1)
		{
			std::cout << "Quel est le nouveau statut ?" << std::endl << "1. En Attente		2. Traitement En Cours		3. Envoie En Cours		4. Terminer" << std::endl;
			std::cin >> statutNumber; 
		}
		}while (statutNumber != 1 && statutNumber != 2 && statutNumber != 3 && statutNumber != 4);
	}

	if (statutNumber == 1)
	{
		std::string statut = "EnAttente";
		commande->setStatut(statut);
	}
	else if (statutNumber == 2)
	{
		std::string statut = "TraitementEnCours";
		commande->setStatut(statut);
	}
	else if (statutNumber == 3)
	{
		std::string statut = "EnvoieEnCours";
		commande->setStatut(statut);
	}
	else if (statutNumber == 4)
	{
		std::string statut = "Terminer";
		commande->setStatut(statut);
	}

	_commandes.push_back(*commande);
}

void Magasin::passedOrder() //Affiche les commandes passées
{
	std::vector<Commande>::iterator it;
	for(it = _commandes.begin(); it != _commandes.end(); it++)
	{
		std::cout << *it;
	}
}

void Magasin::clientOrder(Client client, std::vector<std::string> IdClient) //Affiche les commandes passées d'un client
{
	for(int i = 0; i < _commandes.size(); i++)
	{
		if (IdClient[i] == client.getId())
		{
			std::cout << _commandes[i] << std::endl;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Magasin& magasin) //Surcharge de l'operateur <<
{
	os << "Produits :" << std::endl;
	for(int i = 0; i < magasin._produits.size(); i++)
	{
		os << magasin._produits[i]->getTitre() << std::endl; //Affiche les produits en magasin
	}

	os << std::endl << "Clients :" << std::endl;
	for(int i = 0; i < magasin._clients.size(); i++) //Affiche les clients du magasin
	{
		os << magasin._clients[i]->getPrenom() << " " << magasin._clients[i]->getNom() << std::endl << "ID : " << magasin._clients[i]->getId() << std::endl << std::endl;
	}

	os << std::endl << "Commandes :" << std::endl;
	for(int i = 0; i < magasin._commandes.size(); i++)
	{
		os << magasin._commandes[i] << std::endl << std::endl; //Affiche les commandes des clients du magasin
	}
}