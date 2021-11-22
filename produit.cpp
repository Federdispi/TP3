#include "produit.h"
Produit::Produit(std::string titre, std::string description, int quantite, float prix)
	:_titre(titre), _description(description), _quantite(quantite), _prix(prix) 
{}

std::string Produit::getTitre()
{
	return _titre;
}

std::string Produit::getDescription()
{
	return _description;
}

int Produit::getQuantite()
{
	return _quantite;
}

float Produit::getPrix()
{
	return _prix;
}

void Produit::setQuantite(int quantite)
{
	_quantite = quantite;
}

std::ostream& operator<<(std::ostream& os, const Produit& produit)
{
	os << produit._titre << std::endl << produit._description << std::endl << "Quantite : " << produit._quantite << std::endl << produit._prix << "€" << std::endl << std::endl;
	return os;
}