#include <iostream>
#include "magasin.h"
#include "produit.h"
#include "client.h"
#include "commande.h"

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
		std::cout << "Produit PS5 :" << std::endl;
	magasin.showByName("PS5");
		std::cout << "Nouvelle quantité de PS5 :" << std::endl;
	magasin.updateQuantity("PS5");
		std::cout << "Produit en magasin :" << std::endl;
	magasin.showAll();
		std::cout << "Vérification quantitée PS5" << std::endl;
	std::cout<<ps5; //Afin de verifier que la quantité du produit a bien été mise a jour 

	magasin.addToCart(&client1, &ps5);
	magasin.addToCart(&client1, &ps4);
		std::cout << "Liste de client" << std::endl;
	magasin.showClientById(identifiant);

	Client client2(prenom, nom, identifiant);

	magasin.addClient(&client2);
	magasin.addToCart(&client2, &ps5);
	magasin.removeFromCart(&client1, &ps5);
		std::cout << "Liste de client" << std::endl;
	magasin.showAllClients();
	client1.addProduct(ps5);
	ps5.setQuantite(ps5.getQuantite()-1);
	ps4.setQuantite(ps4.getQuantite()-1);
	std::cout << client1 << std::endl;


	std::string statut0 = "EnAttente";
	std::string statut1 = "TraitementEnCours";
	std::string statut2 = "EnvoieEnCours";
	std::string statut3 = "Terminer";

	Commande commande(client1, statut0);
	std::cout << commande << std::endl;
	client1.clearPanier();
	std::cout << "Commande effectué : panier vide" << std::endl << client1 << std::endl;
	
	std::cout << "Produit en magasin :" << std::endl;
	magasin.showAll();
}