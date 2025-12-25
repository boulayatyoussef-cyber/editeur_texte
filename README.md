# 📝 Mini editeur de texte

[![Python Version](https://img.shields.io/badge/python-3.8%2B-blue)](https://www.python.org/)
[![C Language](https://img.shields.io/badge/language-C-orange)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/license-MIT-green)](https://opensource.org/licenses/MIT)

mon editeur est un traiteur de texte ultra-léger et performant. Son architecture unique repose sur la puissance brute du **C** pour la gestion des données et la flexibilité de **Python** pour l'interface graphique moderne.



---

## 🚀 Fonctionnalités Clés

- **🧠 Moteur Core (C) :** Gestion optimisée du buffer de texte, algorithme de recherche de motifs et dictionnaire orthographique intégré.
- **🖼️ Gestion d'Images :** Insertion d'images avec métadonnées (positions, dimensions) stockées en C et redimensionnement dynamique.
- **🎨 Mise en Forme Riche :** Support du **Gras**, *Italique*, __Souligné__ et changement de couleur du texte.
- **🔡 Styles de Polices :** Sélecteur de polices système (Calibri, Arial, Courier, Times, etc.).
- **🔍 Recherche Intelligente :** Système de recherche de mots-clés ultra-rapide basé sur le moteur C.

---

## 💡 Comment ça marche ?

Le projet utilise **Ctypes** pour créer un pont entre les deux langages :
1. **Saisie :** Lorsqu'une touche est pressée, Python envoie l'instruction au moteur C.
2. **Traitement :** Le C met à jour le buffer mémoire, vérifie l'orthographe et scanne les motifs de recherche.
3. **Rendu :** Le moteur C renvoie les coordonnées (index) des objets et des erreurs à Python.
4. **Affichage :** Python utilise ces données pour appliquer des "tags" visuels et rendre les images.



---

## 🛠️ Installation & Compilation (Ubuntu)

### 1. Prérequis
Installez les outils de compilation GCC et les dépendances Python pour l'imagerie :

```bash
sudo apt update
sudo apt install build-essential python3-tk python3-pip
sudo apt install python3-pil python3-pil.imagetk
pip install Pillow
