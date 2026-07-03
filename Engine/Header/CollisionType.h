#pragma once

// Valeur par défaut, après je sais pas si on peut le modifier pour les besoins du dev ?
// Ok alors update : c'est normal, et faut passer par un GUI. (Unity le fait aussi.)
// Et je suis pas fan de l'idée de faire un en-tête spécial.. Mais bon, pas le choix.
enum class CollisionType {
    None = 0,
    Player = 1,
    Enemy = 2,
    Wall = 3,
    WindowBorder = 4,
    Bullet = 5,
};