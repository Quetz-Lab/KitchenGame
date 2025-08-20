#pragma once
#include <vector>
#include <iostream>

class Food {
private: 
    // Private member variables
    float temperature;
    bool putrefaction;
    std::vector<int> ingredients; // Dynamic array for ingredients

public:
    // Constructor and Destructor
    Food();
    ~Food();

    // Getters and Setters
    float getTemperature() const;
    void setTemperature(float temp);
    bool isPutrefied() const;
    void setPutrefaction(bool status);

    // Functions to control food
    void addIngredient(int ingredient);
    void removeIngredient(int ingredient);
    void displayIngredients() const;
    int getIngredientCount() const;
};

