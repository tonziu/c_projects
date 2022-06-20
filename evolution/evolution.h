#ifndef H_EVOLUTION_H
#define H_EVOLUTION_H
#include "linked_list.h"

struct animal 
{
    int i; // row number
    int j; // column number
    int d; // direction
    int e; // energy
    int genes[8]; // chromosome
} animal;

struct world
{
    int world_h; 
    int world_w;  
    int eden_h; 
    int eden_w;
    int plant_energy;
    int reproduction_threshold;
    int **plants; //array of plants
    cell *herd; // linked list of animals
};

#endif 
