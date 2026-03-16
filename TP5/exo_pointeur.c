#include <stdio.h>
typedef struct {
    const char *option;
} Menu;

typedef struct {
    const char *nom;
    Menu *menus;
    int nb_menus;
} Application;
void displayMenu(const Application* app) {
    if (app == NULL || app->menus == NULL) {
        return;
    }

    printf("--- %s ---\n", app->nom);

    for (int i = 0; i < app->nb_menus; i++) {
        printf("%d. %s\n", i + 1, app->menus[i].option);
    }

    printf("Choisissez une option (0 pour quitter) : ");
}
void runApplication(const Application* app) {
    int choix = -1;

    if (app == NULL || app->menus == NULL) {
        return;
    }

    while (choix != 0) {
        displayMenu(app);

        scanf("%d", &choix);

        if (choix == 0) {
            printf("Au revoir !\n");
        }
        else if (choix > 0 && choix <= app->nb_menus) {
            printf("Vous avez selectionne : %s\n",
                   app->menus[choix - 1].option);
        }
        else {
            printf("Choix invalide\n");
        }

        printf("\n");
    }
}

int main() {
    Menu photoMenus[] = {
        { "Regarder une photo" },
        { "Prendre une photo" }
    };
    Application photoApp = {
        "Photos",
        photoMenus,
        2
    };
    runApplication(&photoApp);

    return 0;
}
