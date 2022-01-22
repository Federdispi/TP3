#include <iostream>
#include "magasin.h"
#include "produit.h"
#include "client.h"
#include "commande.h"
#include <fstream>

int main()
{
	Magasin magasin;
	Produit ps5("PS5", "Meilleure console de jeu", 1, 499.99);
	Produit ps4("PS4", "Console de jeu", 1, 199.99); //Création des produits
	std::string prenom, nom, identifiant;
	int menu = 0;

	std::cout << "Quel est votre prenom, votre nom et votre identifiant ?" << std::endl; //Identification client
	std::cin >> prenom;
	std::cout << std::endl;
	std::cin >> nom;
	std::cout << std::endl;
	std::cin >> identifiant;
	Client client1(prenom, nom, identifiant);
	magasin.addClient(&client1); //Ajout du client au magasin
	Client client2(prenom  = "test", nom  = "test", identifiant  = "test");
	magasin.addClient(&client2);//Ajout d'un deuxième client au magasin
	magasin.addProduit(&ps5); //Ajouts des produits au magasin
	magasin.addProduit(&ps4);

	do{
		do{
			std::cout << "Bienvenue sur EasyStore" << std::endl << "Que voulez vous faire ?" << std::endl << "1. Gestion du magasin" << std::endl << "2. Gestion des utilisateurs" << std::endl << "3. Gestion des commandes" << std::endl << "4. Commande" <<std::endl << "0. Quitter" << std::endl << std::endl; //Menu
			std::cin >> menu;
			std::cout << std::endl;
		}while (menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 0); //Boucle afin de ne pas rentrer de numeros incorrect

		if(menu == 1) //Magasin
		{
				std::cout << "Produit PS5 :" << std::endl;
			magasin.showByName("PS5"); //Affiche le produit ps5
				std::cout << "Nouvelle quantité de PS5 :" << std::endl;
			magasin.updateQuantity("PS5"); //Modifie la quantité de ps5
				std::cout << "Produit en magasin :" << std::endl;
			magasin.showAll(); //Affiche tous les produits du magasin
				std::cout << "Vérification quantitée PS5" << std::endl;
			std::cout<<ps5; //Afin de verifier que la quantité du produit a bien été mise a jour 

		}

		if(menu ==2) //Utilisateurs
		{
				std::cout << "Liste de client" << std::endl;
			magasin.showClientById(identifiant); //Affiche un client avec son identifiant
				std::cout << std::endl;

				std::cout << "Liste de client" << std::endl;
			magasin.showAllClients(); //Affiche tous les clients du magasin
				std::cout << std::endl;
		}

		if(menu == 3) //Commandes
		{
				std::cout << "Ajout d'une ps5 dans une commande de client1" << std::endl; //Ajout et retrait de produits dans les paniers des clients
			magasin.addToCart(&client1, &ps5);
				std::cout << "Ajout d'une ps4 dans une commande de client1" << std::endl;
			magasin.addToCart(&client1, &ps4);
				std::cout << "Ajout d'une ps5 dans une commande de client2" << std::endl;
			magasin.addToCart(&client2, &ps5);
				std::cout << "Retrait d'une ps5 dans une commande de client1" << std::endl;
			magasin.removeFromCart(&client1, &ps5);

			std::cout << "Historique des commandes :" << std::endl;
			magasin.passedOrder(); //N'affiche pas les commandes en attentes car elles ne sont pas valider et donc ne font pas partie de l'historique
			std::cout << std::endl << std::endl;
		}

		if(menu == 4) //Commander
		{
			std::vector<std::string> IdClient;
			std::string Identifiant_client;
			client1.addProduct(ps5); //Ajout d'un produit au panier
			ps5.setQuantite(ps5.getQuantite()-1);
			std::cout << client1 << std::endl;

			std::cout << "Validation commande :" << std::endl;
			int order = magasin.validOrder(&client1); //Validation du panier pour commande
			if (order == 1)
			{ 
				ps5.setQuantite(ps5.getQuantite() + client1.getQuantity(ps5));
				ps4.setQuantite(ps4.getQuantite() + client1.getQuantity(ps4));
				client1.clearPanier();
			}

			std::string statut0 = "EnAttente"; //Statuts de commande
			std::string statut1 = "TraitementEnCours";
			std::string statut2 = "EnvoieEnCours";
			std::string statut3 = "Terminer";

			Commande commande(client1, statut0); //Création d'une commande
			Identifiant_client = commande.getId();
			IdClient.push_back(Identifiant_client);
			std::cout << commande << std::endl;
			client1.clearPanier(); //Panier vider après que la commande soit effectué
			std::cout << "Commande effectué : panier vide" << std::endl << client1 << std::endl;

			if (order != 1)
			{ 
				magasin.updateStatut(&commande);
				std::cout << commande << std::endl;
			}

			magasin.addToCart(&client1, &ps5); //Ajout d'un produit au panier d'un client

			Commande commande2(client1, statut0); //Création d'une deuxième commande
			Identifiant_client = commande2.getId();
			IdClient.push_back(Identifiant_client);
			std::cout << client1 << std::endl;
			magasin.updateStatut(&commande2); //Modification du statut de la commande
			std::cout << commande2 << std::endl; 
			client1.clearPanier();

			Commande commande3(client2, statut0); //Création d'une troisième commande
			Identifiant_client = commande3.getId();
			IdClient.push_back(Identifiant_client);
			std::cout << client2 << std::endl;
			magasin.updateStatut(&commande3); //Modification du statut de la commande
			std::cout << commande3 << std::endl << std::endl;
			client2.clearPanier();
				std::cout << "Historique des commandes de client1 " << std::endl;
			magasin.clientOrder(client1, IdClient);
			std::cout << std::endl << std::endl;
		}

		if(menu == 0) //Quitter
		{
			std::ofstream file_EasyStore("EasyStore.txt"); //Enregistrement dans un fichier
			if (file_EasyStore)
			{
				file_EasyStore << magasin;
				file_EasyStore.close();
			}
			else 
				std::cout << "Erreur d'ouverture du fichier" << std::endl;

			std::ifstream file_EasyStoreLec("EasyStore.txt"); //Lecture d'un fichier
			if(file_EasyStoreLec)
			{
				std::string ligne;
				while (getline(file_EasyStoreLec, ligne))
				{
					std::cout << ligne << std::endl;
				}
			}
			else 
				std::cout << "Erreur de lecture du fichier" << std::endl;
		}
	}while (menu != 0);

} 