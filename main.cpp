#include <iostream>
#include "magasin.h"
#include "produit.h"
#include "client.h"

int main()
{
	Produit ps5("PS5", "Meilleure console de jeu", 0, 499.99);
	Produit ps4("PS4", "Console de jeu", 1, 199.99);
	Magasin magasin;
	magasin.addProduit(&ps5);
	magasin.showByName("PS5");
	magasin.updateQuantity("PS5");
	magasin.showAll();
	std::cout<<ps5;

	std::string _prenom;
	std::string _nom;
	std::string _identifiant;
	std::cout << "Quel est votre prenom, votre nom et votre identifiant ?" << std::endl;
	std::cin >> _prenom;
	std::cout << std::endl;
	std::cin >> _nom;
	std::cout << std::endl;
	std::cin >> _identifiant;
	

	Client client1(_prenom, _nom, _identifiant);
	client1.addProduct(ps5);
	client1.addProduct(ps4);
	ps5.setQuantite(ps5.getQuantite()-1);
	std::cout << client1 << std::endl;
}