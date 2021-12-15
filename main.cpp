#include <iostream>
#include "magasin.h"
#include "produit.h"
#include "client.h"

int main()
{
	Magasin magasin;

	std::string prenom, nom, identifiant;
	std::cout << "Quel est votre prenom, votre nom et votre identifiant ?" << std::endl;
	std::cin >> prenom;
	std::cout << std::endl;
	std::cin >> nom;
	std::cout << std::endl;
	std::cin >> identifiant;
	Client client1(prenom, nom, identifiant);

	Produit ps5("PS5", "Meilleure console de jeu", 1, 499.99);
	Produit ps4("PS4", "Console de jeu", 1, 199.99);

	magasin.addClient(&client1);
	magasin.addProduit(&ps5);
	magasin.addProduit(&ps4);
	magasin.updateQuantity("PS5");
	magasin.showAll();

	magasin.addToCart(&client1, &ps5);
	magasin.addToCart(&client1, &ps4);
	magasin.showClientById(identifiant);

	std::cout << "Quel est votre prenom, votre nom et votre identifiant ?" << std::endl;
	std::cin >> prenom;
	std::cout << std::endl;
	std::cin >> nom;
	std::cout << std::endl;
	std::cin >> identifiant;
	Client client2(prenom, nom, identifiant);

	magasin.addClient(&client2);
	magasin.addToCart(&client2, &ps5);
	magasin.removeFromCart(&client1, &ps5);
	magasin.showAllClients();
}