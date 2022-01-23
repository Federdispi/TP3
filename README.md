# TP3 C++ : EasyStore

_Federico Di Spirito et Lucas Blanchard_

Nous avons choisi ce sujet puisque cela avait l'air intéressant de manipuler plusieurs classes à la fois et de simuler un magasin qui pourrait être une sorte d'Amazon, bien qu'en beaucoup moins complexe.
Au début, nous nous sommes partagé le travail :
* Federico a fait le squelette des classes Produit et Magasin (variables et méthodes de base)
* Lucas a fait les classes Client et Commande

Le niveau entre nous deux étant différent, Lucas a continué de faire ce TP afin de s'entraîner vu qu'il était de son niveau tandis que Federico est passé à un TP de niveau supérieur.

Le programme implique des classes avec des méthodes avec passage de références. Les classes Produit, Client et Commande servent d'appui à la classe Magasin, classe qui est au centre du programme.

Même si j'ai rencontré des difficultés avec les passages de références j'ai réussi à résoudre tous les problèmes et le programme fonctionne bien, le travail d'équipe a été utile afin de surmonter certains problèmes.

## Introduction

Le but de ce TP est de créer un magasin que l'on pourra par la suite gérer, c'est à dire que nous pourrons ajouter des produits au magasin, produits possédant un nom, une description, un prix ainsi qu'une quantité présente dans le magasin, nous pourrons gérer ces produits, c'est à dire, par exemple, modifier la quantité d'un produit. Une autre fonctionnalité sera la gestion des clients, nous pourrons ajouter des clients au magasin pour ensuite gérer les commandes, nous pourrons donc ajouter et retirer des produits aux paniers des clients et enfin, les clients pourront commander les produits qu'ils auront mis dans leur panier et nous pourrons ensuite modifier le statut de cette commande. Les produits, clients et commandes seront enfin enregistré dans un fichier texte qui sera lu à la fin du programme afin de nous faire un récapitulatif du magasin, de ses produits, de ses clients et de ses commandes.

## Fonctionnement du programme

À chaque lancement du programme, il faudra donner son prénom, son nom ainsi qu'un identifiant, on arrive ensuite dans le menu du magasin, nous pourrons dès lors gérer les produits du magasin, les clients, les commandes ou tout simplement effectuer et valider des commandes ainsi que modifier leurs statut, après chacune de ces actions nous reviendrons au menu afin de continuer de naviguer sur le magasin, lorsque nous déciderons de quitter le magasin, les produits, clients et commandes seront enregistré dans un fichier texte et affiché à l'ecran afin que nous puissions voir ce que nous avons fait.

Le menu du programme possède 5 parties:
* La **gestion des produits** du magasin
* La **gestion des clients** du magasin
* La **gestion des commandes**
* La **commande** en elle même 
* L'option **quitter**
