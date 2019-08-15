#ifndef DEF_PARTIE
#define DEF_PARTIE

class Partie {
public:
 Partie();
 ~Partie();
 virtual void lancerPartie() = 0;
 virtual void verifCasesExistantes() = 0;
};

#endif
