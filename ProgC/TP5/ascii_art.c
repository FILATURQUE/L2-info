#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define prl { printf("\n"); }

typedef struct 
{
    double x;
    double y;

} coord_t; 

coord_t coordinate(double x, double y){

    coord_t c = {x,y};
    return c;

}

coord_t inv_translate_point(coord_t p, coord_t v){

    return coordinate(p.x - v.x,p.y - v.y);
}

coord_t inv_rotate_point(coord_t p, double t){

    return coordinate(p.x * cos(-t) - p.y * sin(-t),p.x * sin(-t) + p.y * cos(-t));
}


void print_coord(coord_t c){
    printf("(%f,%f)",c.x,c.y); prl;
}


// Definition de l'enumeration shape_t
typedef enum{

    Circle, 
    Rectangle, 
    Line

} shape_t;

//Definition de la structure rayon_t + Double 8 octets 
typedef struct {
    double rayon;
} cercle_t;

//Definition de la structure rectangle_t + 16 octets car 2 x 8
typedef struct {
    double miLargeur;
    double miHauteur;
} rectangle_t;

//Definition de la structure line_t + 8 octets car double
typedef struct {
    double longeur;
} line_t;

typedef char color_t;

typedef union {

    struct {double rayonCarre;} circle; // caracteristique du cercle
    struct {double miLargeur, miHauteur ;} rectangle; // caracteristique du rectangle
    struct {double miLongeur;} line; // caracteristique de la ligne 
    
} caracteristic_t;

// Figure 48 octets car coord 16 + double 8 + color_t 1 + caracteristic 16 + shape 4 
typedef struct {
    coord_t gravityCenter;
    caracteristic_t carac;
    double rotationAngle;
    color_t color;
    shape_t shape;

} figure_t;

figure_t createFigure(shape_t s){
    figure_t f;
    f.gravityCenter = coordinate(0.0,0.0);
    f.rotationAngle = 0.0;
    f.color = '+';
    f.shape = s;

    return f;
}

figure_t circle(double radius){
    figure_t c = createFigure(Circle);
    c.carac.circle.rayonCarre = radius * radius;

    return c;
}

figure_t rectangle(double width, double height){
    figure_t r = createFigure(Rectangle);
    r.carac.rectangle.miLargeur = width/2;
    r.carac.rectangle.miHauteur= height/2;

    return r;
}

figure_t line(double length){
    figure_t l = createFigure(Line);
    l.carac.line.miLongeur = length / 2;

    return l;
}

figure_t color(figure_t f, color_t c){
    f.color = c;
    return f;
}

figure_t translate(figure_t f, double dx, double dy){
    
    f.gravityCenter.x = dx;
    f.gravityCenter.y = dy;

    return f;
}

figure_t rotate(figure_t f, double dt){
    f.rotationAngle = dt;

    return f;
}

color_t intersect(coord_t p, figure_t f, double grain){

    coord_t translated_p = inv_translate_point(p,f.gravityCenter);
    coord_t rotated_p = inv_rotate_point(translated_p,f.rotationAngle);
    
    switch (f.shape){
        case Circle:
            if (rotated_p.x * rotated_p.x + rotated_p.y * rotated_p.y  <= f.carac.circle.rayonCarre ) 
                return f.color;
            return 0;
        
        case Rectangle:
            if (fabs(rotated_p.x) <= f.carac.rectangle.miLargeur && fabs(rotated_p.y) <= f.carac.rectangle.miHauteur / 2) 
                return f.color;
            return 0;

        case Line: 
            if (fabs(rotated_p.x) <= f.carac.line.miLongeur && fabs(rotated_p.y) <= grain)
                return f.color;
            return 0;
        
        default:
            return 0;
    }
}

// image_t = 504 : Figure = 48 x 10 + unsigned int et int = 8 x 3 + double = 8 
typedef struct {

    figure_t maxShape[10];
    double grain;
    unsigned int width;
    unsigned int height;
    int registedShape;

} image_t;

// creation du constructeur image
image_t image(unsigned int width, unsigned int height, double grain){
    image_t i;
    i.width = width;
    i.height = height;
    i.grain = grain;

    return i;
}

image_t append(image_t img, figure_t f){

    // Fait une boucle qui parcour tout le tableau
    for (int i = 0; i < 10 ; i++)
    {   
        // Verifie si a l'index i le tableau est vide ou pas 
        if (img.maxShape[i].shape == 0){
            img.maxShape[i] = f; // rajout de la figure si le tableau est vide
            return img; // quitte la fonction des que la figure est ajoute pour eviter tout autre ajout inutile
        }
        // dans le cas ou le tableau est remplie print l'erreur et exit le programme 
        else {
            fprintf(stderr, "Error: Maximum number of shapes reached.\n");
            exit(EXIT_FAILURE);
        }
    }
    return img;
    
}

image_t prepend(image_t img, figure_t f){
    if (img.registedShape >= 10) {
        fprintf(stderr, "Error: Maximum number of shapes reached.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = img.registedShape; i > 0; i--) {
        img.maxShape[i] = img.maxShape[i - 1];
    }

    img.maxShape[0] = f;
    img.registedShape++;

    return img;
}

int main(){

    /* figure_t f;
    color_t c;
    
    f = rectangle(10,7);
    f = translate(f, 10, 8);
    f = rotate(f, 45 * M_PI / 180);
    
    c = intersect(coordinate(5,5),f,1);
    if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
    c = intersect(coordinate(10,10),f,1);
    if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
    c = intersect(coordinate(18,18),f,1);
    if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
    
    f = circle(12);
    f = translate(f, 20, 13);
    f = color(f, 'O');
    
    c = intersect(coordinate(5,5),f,1);
    if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
    c = intersect(coordinate(10,10),f,1);
    if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
    c = intersect(coordinate(18,18),f,1);
    if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
    
    f = line(20);
    f = translate(f, 18, 18);
    f = rotate(f, -60 * M_PI / 180);
    f = color(f, '*');
    
    c = intersect(coordinate(5,5),f,1);
    if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
    c = intersect(coordinate(10,10),f,1);
    if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
    c = intersect(coordinate(18,18),f,1);
    if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
     */

    /* printf("Hello\n");
    printf("Figure :%zu\n",sizeof(figure_t));
    printf("Coord :%zu\n",sizeof(coord_t));
    printf("Double :%zu\n",sizeof(double));
    printf("Caracteristique :%zu\n",sizeof(caracteristic_t));
    printf("Shape :%zu\n",sizeof(shape_t));
    printf("Color :%zu\n",sizeof(color_t)); */


    printf("Hello\n");
    printf("Image_t :%zu\n",sizeof(image_t));
    printf("Double :%zu\n",sizeof(double));
    printf("figure :%zu\n",sizeof(figure_t));
    printf("int :%zu\n",sizeof(int));
    printf("unsigned int :%zu\n",sizeof(unsigned int));
    return EXIT_SUCCESS;
}