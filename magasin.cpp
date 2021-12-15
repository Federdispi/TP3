#include "magasin.h"

Magasin::Magasin() 
{
	_produits.clear();
}

void Magasin::addProduit(Produit* produit)
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

void Magasin::showAll()
{
	for(int i = 0; i < _produits.size(); i++)
		std::cout << i + 1 << ") " << *_produits[i];
}

void Magasin::showByName(std::string name)
{
	std::vector<Produit*>::iterator it;
	for(it = _produits.begin(); it != _produits.end(); it++)
	{
		if((*it)->getTitre() == name)
			std::cout << **it;
	}
}

void Magasin::updateQuantity(std::string name)
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

Produit* Magasin::getProduct(int index)
{
	return _produits[index];
}

void Magasin::addClient(Client* client)
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

void Magasin::showAllClients()
{
	for(int i = 0; i < _clients.size(); i++)
		std::cout << i + 1 << ") " << *_clients[i];
}

void Magasin::showClientByName(std::string name)
{
	std::vector<Client*>::iterator it;
	for(it = _clients.begin(); it != _clients.end(); it++)
	{
		if((*it)->getNom() == name)
			std::cout << **it;
	}
}

void Magasin::showClientById(std::string id)
{
	std::vector<Client*>::iterator it;
	for(it = _clients.begin(); it != _clients.end(); it++)
	{
		if((*it)->getId() == id)
			std::cout << **it;
	}
}

void Magasin::addToCart(Client* client, Produit* produit)
{
	if (produit->getQuantite() != 0)
	{
		client->addProduct(*produit);
		produit->setQuantite(produit->getQuantite()-1);
	}else
		std::cout << "ERREUR: L'article " << produit->getTitre() << " est en ropture de stock" << std::endl;
}

void Magasin::removeFromCart(Client* client, Produit* produit)
{
	if(client->getQuantity(*produit) != 0)
	{
		client->eraseProduct(*produit);
		produit->setQuantite(produit->getQuantite()+1);
	}
}

void Magasin::updateQuantityInCart(Client* client, Produit produit, int quantity)
{
	client->changeQuantity(produit, quantity);
}