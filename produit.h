#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>

class Produit {
public:
	Produit(std::string titre, std::string descritpion, int quantite, float prix);
	std::string getTitre();
	std::string getDescription();
	int getQuantite();
	float getPrix();
	void setQuantite(int quantite);
	friend std::ostream& operator<<(std::ostream& os, const Produit& produit);
private:
	std::string _titre;
	std::string _description;
	int _quantite;
	float _prix;
};

#endif