---
title: Configuration
slug: /client/config
---

# Client Configuration

Cette section décrit la configuration du client utilisée pour le **Ball Game**. La configuration définit les paramètres du jeu, de la fenêtre, du réseau et de l'interface utilisateur.

---

## Game

| Paramètre | Valeur | Description |
|-----------|--------|-------------|
| **FRAME_RATE** | `144` | Nombre maximal d'images par seconde. |
| **CAMERA_INTERPOLATE_FACTOR** | `0.1` | Facteur d'interpolation pour la caméra. |

---

## Window

| Paramètre | Valeur | Description |
|-----------|--------|-------------|
| **WIDTH** | `1920` | Largeur de la fenêtre du jeu. |
| **HEIGHT** | `1080` | Hauteur de la fenêtre du jeu. |
| **NAME** | `"Ball game"` | Nom de la fenêtre affichée. |

---

## Network

| Paramètre | Valeur | Description |
|-----------|--------|-------------|
| **HOST** | `127.0.0.1` | Adresse IP du serveur par défaut. |
| **PORT** | `12345` | Port du serveur de jeu. |
| **MAX_SIZE** | `1024` | Taille maximale des paquets réseau. |
| **ENTITY_LINKING_BIAS** | `0.01` | Décalage d'ID utilisé pour lier les entités (ex: pseudo et entité associée). |

---

## World

| Paramètre | Valeur | Description |
|-----------|--------|-------------|
| **ID** | `1` | ID unique de l'entité représentant le monde. |
| **BACKGROUND_COLOR** | `{20, 20, 20, 255}` | Couleur de fond du monde. |

---

## Zoom

| Paramètre | Valeur | Description |
|-----------|--------|-------------|
| **SPEED** | `50.0` | Vitesse de zoom appliquée lors du défilement de la souris. |

---

## Player

### Nickname

| Paramètre | Valeur | Description |
|-----------|--------|-------------|
| **TEXT_SIZE** | `10.0` | Taille de la police du pseudo affiché en jeu. |
| **FONT_FAMILY** | `Montserrat` | Famille de police utilisée pour le pseudo. |
| **FONT_WEIGHT** | `800` | Épaisseur de la police du pseudo. |

### Mass

| Paramètre | Valeur | Description |
|-----------|--------|-------------|
| **TEXT_SIZE** | `4.0` | Taille de la police affichant la masse de la cellule. |
| **FONT** | `Montserrat` | Police utilisée pour la masse. |
| **FONT_WEIGHT** | `500` | Épaisseur de la police de la masse. |

---

## HUD (Interface Utilisateur)

| Paramètre | Valeur | Description |
|-----------|--------|-------------|
| **BACKGROUND_COLOR** | `{255, 255, 255, 25}` | Couleur de fond du HUD. |
| **PADDING** | `10.0` | Espacement interne du HUD. |
| **TEXT_PADDING** | `25.0` | Espacement entre les textes. |
| **FONT_FAMILY** | `Montserrat` | Police d'affichage principale du HUD. |
| **TEXT_COLOR** | `{255, 255, 255, 255}` | Couleur des textes affichés dans le HUD. |

### Stats

| Paramètre | Valeur | Description |
|-----------|--------|-------------|
| **WIDTH** | `180.0` | Largeur du panneau des statistiques. |
| **HEIGHT** | `220.0` | Hauteur du panneau des statistiques. |
| **LABEL_SIZE** | `18.0` | Taille de la police des libellés. |
| **VALUE_SIZE** | `19.0` | Taille de la police des valeurs. |
| **FONT_WEIGHT_LABEL** | `500` | Épaisseur de la police des libellés. |
| **FONT_WEIGHT_VALUE** | `900` | Épaisseur de la police des valeurs. |
| **VALUE_COLOR** | `{120, 107, 242, 255}` | Couleur des valeurs affichées. |
| **MARGIN_TOP** | `20` | Marge supérieure du panneau des statistiques. |
| **MARGIN_BETWEEN_LINES** | `40` | Marge entre les lignes des statistiques. |

### Leaderboard

| Paramètre | Valeur | Description |
|-----------|--------|-------------|
| **WIDTH** | `250.0` | Largeur du panneau du classement. |
| **HEIGHT** | `400.0` | Hauteur du panneau du classement. |
| **TITLE** | `Leaderboard` | Titre affiché en haut du classement. |
| **TITLE_SIZE** | `23.0` | Taille de la police du titre. |
| **FONT_WEIGHT_LABEL** | `900` | Épaisseur de la police du titre. |
| **FONT_WEIGHT_VALUE** | `700` | Épaisseur de la police des noms des joueurs. |
| **CONTENT_SIZE** | `18.0` | Taille de la police des entrées du classement. |
| **MARGIN_TOP** | `40` | Marge supérieure du panneau du classement. |
| **MARGIN_BETWEEN_TITLE_AND_CONTENT** | `75` | Marge entre le titre et le contenu du classement. |
| **MARGIN_BETWEEN_LINES** | `30` | Marge entre les lignes du classement. |
| **MAX_ENTRIES** | `10` | Nombre maximal de joueurs affichés dans le classement. |

### ChatBox

| Paramètre | Valeur | Description |
|-----------|--------|-------------|
| **WIDTH** | `350.0` | Largeur de la boîte de chat. |
| **HEIGHT** | `300.0` | Hauteur de la boîte de chat. |
| **TITLE_SIZE** | `30.0` | Taille de la police du titre de la boîte de chat. |
| **CONTENT_SIZE** | `30.0` | Taille de la police du contenu du chat. |

---

## Conclusion

La configuration du client définit tous les paramètres de fonctionnement essentiels au bon affichage et à l'expérience utilisateur du jeu. Ces paramètres permettent de personnaliser l'affichage, les performances et l'expérience de jeu.

