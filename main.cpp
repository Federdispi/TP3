#include <iostream>
#include "magasin.h"
#include "produit.h"
#include "client.h"
#include "commande.h"

int main()
{
	Produit ps5("PS5", "Meilleure console de jeu", 0, 499.99);
	Produit ps4("PS4", "Console de jeu", 1, 199.99);
	Magasin magasin;
	magasin.addProduit(&ps5);
		std::cout << "Produit PS5 :" << std::endl;
		magasin.addProduit(&ps4);
	magasin.showByName("PS5");
		std::cout << "Nouvelle quantité de PS5 :" << std::endl;
	magasin.updateQuantity("PS5");
		std::cout << "Produit en magasin :" << std::endl;
	magasin.showAll();
		std::cout << "Vérification quantitée PS5" << std::endl;
	std::cout<<ps5; //Afin de verifier que la quantité du produit a bien été mise a jour 

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
	std::cout << "Souhaitez vous ajouté un produit ?" << std::endl << "Tapez le numero du produit (1 pour PS5, 2 pour PS4 et tapez 0 pour quitter)" << std::endl;
	client1.addProduct(ps5);
	ps5.setQuantite(ps5.getQuantite()-1);
	client1.addProduct(ps4);
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