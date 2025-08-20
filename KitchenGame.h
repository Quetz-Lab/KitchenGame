#pragma once
#include "Food.h"
#include <vector>
#include <string>

class KitchenGame {
private:
    // Arrays for managing the kitchen
    std::vector<Food> foodItems;           // Dynamic array of Food objects
    std::string kitchenTools[10];          // Static array of kitchen tools
    float temperatures[5];                 // Array for different cooking zones
    bool stoveStatus[4];                   // Array for 4 stove burners (on/off)
    
    // Game state variables
    int score;
    int level;
    
public:
    // Constructor and Destructor
    KitchenGame();
    ~KitchenGame();
    
    // Game management methods
    void startGame();
    void updateGame();
    void endGame();
    
    // Food management methods
    void addFood(const Food& food);
    void removeFood(int index);
    Food& getFood(int index);
    int getFoodCount() const;
    
    // Kitchen equipment methods
    void setStoveStatus(int burner, bool status);
    bool getStoveStatus(int burner) const;
    void setZoneTemperature(int zone, float temp);
    float getZoneTemperature(int zone) const;
    
    // Utility methods
    void displayKitchenStatus();
    void displayFoodItems();
};