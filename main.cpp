#include <iostream>
#include "magasin.h"
#include "produit.h"

int main()
{
	Produit ps5("PS5", "Meilleure console de jeu", 0, 499.99);Magasin magasin;
	magasin.addProduit(ps5);
	magasin.showByName("PS5");
	magasin.updateQuantity("PS5");
}