#include "magasin.h"

Magasin::Magasin() 
{
	_produits.clear();
}

void Magasin::addProduit(Produit produit)
{
	bool c = 0;
	std::vector<Produit>::iterator it;
	for(it = _produits.begin(); it != _produits.end(); it++)
	{
		if(it->getTitre() == produit.getTitre())
			c = 1;
	}

	if(!c)
		_produits.push_back(produit);
}

void Magasin::showAll()
{
	for(int i = 0; i < _produits.size(); i++)
		std::cout << i + 1 << ") " << _produits[i];
}

void Magasin::showByName(std::string name)
{
	std::vector<Produit>::iterator it;
	for(it = _produits.begin(); it != _produits.end(); it++)
	{
		if(it->getTitre() == name)
			std::cout << *it;
	}
}

void Magasin::updateQuantity(std::string name)
{
	std::vector<Produit>::iterator it;
	for(it = _produits.begin(); it != _produits.end(); it++)
	{
		if(it->getTitre() == name)
		{
			int quantite;
			std::cout << "Produits disponibles : " << it->getQuantite() << std::endl;
			std::cout << "Nouvelle quantite : ";
			std::cin >> quantite;
			it->setQuantite(quantite);
			std::cout << "Ok." << std::endl << std::endl;
		}
	}
}