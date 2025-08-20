#include "Food.h"

Food::Food() : temperature(20.0f), putrefaction(false) {
    // Initialize with some default ingredients
    int defaultIngredients[] = {1, 2, 3}; // Example ingredient IDs
    for (int i = 0; i < 3; i++) {
        ingredients.push_back(defaultIngredients[i]);
    }
    std::cout << "Food object created with " << ingredients.size() << " ingredients\n";
}

Food::~Food() {
    std::cout << "Food object destroyed\n";
}

float Food::getTemperature() const {
    return temperature;
}

void Food::setTemperature(float temp) {
    temperature = temp;
    std::cout << "Temperature set to " << temp << "°C\n";
}

bool Food::isPutrefied() const {
    return putrefaction;
}

void Food::setPutrefaction(bool status) {
    putrefaction = status;
    std::cout << "Putrefaction status: " << (status ? "Yes" : "No") << "\n";
}

void Food::addIngredient(int ingredient) {
    ingredients.push_back(ingredient);
    std::cout << "Ingredient " << ingredient << " added. Total ingredients: " 
              << ingredients.size() << "\n";
}

void Food::removeIngredient(int ingredient) {
    for (auto it = ingredients.begin(); it != ingredients.end(); ++it) {
        if (*it == ingredient) {
            ingredients.erase(it);
            std::cout << "Ingredient " << ingredient << " removed\n";
            return;
        }
    }
    std::cout << "Ingredient " << ingredient << " not found\n";
}

void Food::displayIngredients() const {
    std::cout << "Ingredients: ";
    for (size_t i = 0; i < ingredients.size(); i++) {
        std::cout << ingredients[i] << " ";
    }
    std::cout << "\n";
}

int Food::getIngredientCount() const {
    return static_cast<int>(ingredients.size());
}
