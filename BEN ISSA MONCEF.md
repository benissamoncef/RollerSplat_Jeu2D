**LE JEUX ROLLER SPLAT EN C++**

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.003.jpeg)

**REALISE PAR** : BEN ISSA MONCEF  

**ENCADRE PAR** : Mme BEN ABDEL OUAHAB IKRAM & Mr EL AACHAK LOTFI **LIEN DE GITHUB** :  

**REMERCIEMENT:** 

Nous voudrions exprimer nos vifs remerciements et notre gratitude ainsi  

notre considération distinguée à **Mme Ben Abdel Ouahab Ikram** et **Mr El Aachak Lotfi**,  de nous donner tout d’abord l’opportunité de travailler  

sur ce projet, durant lequel j’ai pu acquérir et développer plusieurs connaissances 

et compétences, qui vont nous servir sans doute tout au long de nôtre carrière  

en tant que futurs informaticiens, et aussi pour ses directives et conseils, ainsi 

pour leurs aide et son soutien tout au long de la période de la réalisation  

de ce projet. 

En effet, au cours de ce projet nous avons pu développer certaines compétences professionnelles tel que la prise d’initiative, le respect des délais et le travail  

en équipe qui seront des aspects essentiels de notre futur métier. 

De plus, ce projet nous a permis d’appliquer nos connaissances qu’on a acquis  à travers le module de la programmation orienté objet en C++ et Python. 

**INTRODUCTION:**  

**1- L’IDEE DU JEUX:**  

L’idée du jeu c’est un ballon qui vous pouvez le balayer vers le haut, le bas  à travers le labyrinthe pendant que vous éclaboussez la couleur partout  dans le labyrinthe. Vous pouvez gagner dans les niveaux de chaque puzzle  en couvrant chaque couloir et coin avec une peinture. 

**2- COCOS2D-x V4 :** 

Cocos2d-x est l’une des bibliothèques logicielles de référence. En plus de permettre de créer des jeux en 2D pour les appareils mobiles Android, iOS et Windows Phone, elle compile sur Windows, Mac et Linux. La bibliothèque peut être utilisée pour le développement en C++, Javascript et Lua. 

**3- ADOBE PHOTOSHOP:** 

Photoshop est un[ logiciel ](https://fr.wikipedia.org/wiki/Logiciel)de[ retouche,](https://fr.wikipedia.org/wiki/Retouche_d%27image) de[ traitement ](https://fr.wikipedia.org/wiki/Traitement_d%27images)et de[ dessin assisté par ordinateur,](https://fr.wikipedia.org/wiki/Dessin_assist%C3%A9_par_ordinateur) édité par[ Adobe,](https://fr.wikipedia.org/wiki/Adobe_Systems) il est principalement utilisé pour le traitement des[ photographies numériques,](https://fr.wikipedia.org/wiki/Photographie_num%C3%A9rique) Il travaille essentiellement sur[ images matricielles ](https://fr.wikipedia.org/wiki/Image_matricielle)car les images sont constituées d’une grille de points appelés[ pixels.](https://fr.wikipedia.org/wiki/Pixel) L’intérêt de ces images est de reproduire des gradations subtiles de couleurs. 

**4- MICROSOFT VISUAL STUDIO:** 

Visual Studio est un ensemble complet d'outils de développement permettant de générer des applications web ASP.NET, des services web XML, des applications bureautiques et des applications mobiles. 

**CONCEPTION DES PLANS:** 

L’idée generale c’est que j’ai éssayé de traiter les plans comme une matrice de N lignes et M colonnes pour la facilité de conception graphique et la facilité des déplacements après.Tous les plans ont une dimension de 1024px/768px, et chaque plan a une arrire plan differente. pour la conception graphique j’ai utilisé le logiciel Adobe photoshop et les sites web Unsplash et Pexels pour les arrières plans. 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.004.jpeg)

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.005.jpeg)

**CREATION DE SPRITE:** 

**Prenant l’exemple du ballon de premier niveau:**  

1- Déclaration de Sprite dans la classe principale (Dans le fichier 

Niveau1.h) :  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.006.png)

2- Après la déclaration, dans le fichier Niveau1.cpp on fait la création en 

utilisant la fonction **Sprite::create(),** On place notre élément dans une position initiale en utilisant la fonction **setPosition()** et finalement on ajoute l’élément avec un z-index (Dans ce cas le z-index = 1). 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.007.png)

J’ai fait la même chose pour les autres objets de classe Sprite sauf par exemple dans le cas d'arrière-plan je fait la définition de position au centre de l'écran en utilisant la taille visible, qui est la zone de l'écran qui est disponible sur un appareil particulier, car il existe différentes tailles d'écran. 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.008.png)

**CREATION DU MENU:** 

**Prenant l’exemple du premier menu (MainMenuScene):** 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.009.png)

1- On commence par la création des éléments de menu dans ce cas 

(playerItem) quand on clique sur ce boutton on passe au premier niveau autrement dit on fait l’appel de fonction GoToGameScene(). 

2- Après on créé le menu en indiquant leur position dans la scène. (Dans 

ce cas le menu est centré). 

3- On ajoute le menu en utilisant la fonction addChild(). 

**La fonction GoToGameScene() :** 

1- La déclaration :  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.010.png)

2- Le code :  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.011.png)

Dans ce cas quand on fait l’appel de la fonction elle créée une scène de Niveau1 et change la scène actuelle (MainMenuScene) par la nouvelle scène (Le premier niveau). 

**SCENES DE JEUX:** 

MENU  NIVEAU 1  NIVEAU 2  NIVEAU 3 PRINCIPAL ![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.012.png)![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.013.png)![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.014.png)![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.015.png)![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.016.png)![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.017.png)![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.015.png)![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.018.png)![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.019.png)![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.020.png)

PAUSE ![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.021.png)

**1-  La creation du scene:** 

**Prenant l’exemple de la deuxième scène: a- Les déclarations:**   

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.022.png)

**b- La création du scene (Dans le fichier Niveau2.cpp) :** 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.023.png)

**Commentaires :** 

On fait déclarer et initialiser la méthode du monde physique qui attribue le monde de la physique et définit la gravité à 0 car notre jeu Roller Splat ne nécessite pas de gravité. Ainsi, le moteur physique dans ce cas sera simplement utilisé pour la détection de collision, et après on déclare le monde physique local.  

**JOUER AVEC LES TOUCHES DE CLAVIER:** 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.024.png)

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.025.png)

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.026.png)

On declare premièrement un événement qui détecte le keycode chaque fois que vous cliquez sur les touches de clavier, pour cela on utilise la fonction prédéfinie **EventListenerKeyboard : : create()**.Après, comme une solution proposée j’ai choisi de travailler avec un switch qui a comme argument le keycode de la touche de clavier avec 4 possibilités (Up, Down, Left and Right) dans chaque cas elle exécute une partie de code. 

**METHODE DE DEPLACEMENT ET DE COLORATION:** 

Dans chaque plan il y’a des points dans lesquels la balles peut se déplacer dans N directions (entre 1 et 3 directions).  

Ces points sont situés en X ligne et Y colonne, prenant l’exemple du 3éme niveau :  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.027.jpeg)

Par exemple dans cette figure si la balle est située dans le point entouré, la balle à 3 possibilités soit se déplacer vers le haut soit vers le bas soit vers la gauche, si l’utilisateur a cliqué sur la flèche « en haut », la balle va se  déplacer 2 cases vers le haut et va colorer 3 cases (incluse la position de la balle) et de même pour les autres directions, la coloration et faite par une boucle qui insère N carrées (Cette carrée a la même dimension que la case de la matrice). Si on fait une traduction de cette idée par code on obtient :  

Si on clique sur UP :  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.028.png)

Avec :  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.029.png)

Si on clique sur Down :  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.030.png)

Avec :  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.031.png)

Si on clique sur Left : 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.032.png)

Avec :  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.033.png)

**DETECTION DES COLLISIONS:**  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.034.png)

Le code précédent ajoute un écouteur pour écouter activement les collisions. en cas de détection de collision, la méthode **onContactBegin** sera appelée. 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.035.jpeg)

Cette fonction dans notre cas va pour chaque collision savoir quel obstacle a fait la collision et par suite va exécuter un algorithme dans le but de savoir  si la balle a parcouru tout le plan.

**CREATION DES OBSTACLES:** 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.036.png)

On crée un sprite non dynamique avec une position fixe. apès, on fait la création d’un corps physique qui a la même taille que l’élement avec un identificateur diffirent que le sprite principale (Dans notre cas la balle a un CollisionBitMask = 0 et d’obstacle égale a 1). Les obstacles sont placés avec une manière qu’ils couvrent tout le plan ou bien les couloires principales de plan.

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.037.jpeg)**COMMENT SAVOIR QUE LA BALLE A COLOREE TOUT LE PLAN?** 

Par exemple dans un plan qui contient N obstacles, comme une première étape j’ai déclaré une variable par exemple x égale a 0 et chaque fois qu’on détecte une collision entre la balle et cet obstacle on incrémente la variable et on efface cet obstacle. Si la variable x = N ca veut dire que la balle est passé par tous les obstacles et par suite le niveau est terminé, la dernière étape j’appelle la fonction bravo() ; 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.038.jpeg)

Concernant la fonction **onContactBegin()** s’exécute chaque fois qu’on  détecte une collision. 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.039.png)

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.040.jpeg)

**LA FONCTION BRAVO:** 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.041.png)

Cette fonction est appelée quand le niveau est terminé ou bien la balle a fait une collision avec tous les obstacles de plan. 

La fonction fait une action (une saute), après elle créée un bouton pour passer au niveau suivant. 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.042.jpeg)

**CREATION DE RACCOURCI:**  

On fait  un raccourci d’un fichier éxecutable de chemin Fichier\_de\_jeux / proj.Win32 / bin / Nom\_de\_jeux (Game) / Debug. 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.043.png)

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.044.png)

**RESULTAS:**  

**1-  Le menu principal:** 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.045.jpeg)

**2-  Le 1er niveau:**  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.046.jpeg)

**3-  Le 2em niveau:** 

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.047.jpeg)

**4-  Le 3em niveau:**  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.048.jpeg)

**5-  La scene de pause:**  

![](Aspose.Words.b72c6c77-8b13-4699-b55f-652f25e726dc.049.jpeg)
