// KitchenGame.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "KitchenGame.h"
#include "Food.h"

// KitchenGame class implementation
KitchenGame::KitchenGame() : score(0), level(1) {
    // Initialize kitchen tools array
    kitchenTools[0] = "Knife";
    kitchenTools[1] = "Pan";
    kitchenTools[2] = "Pot";
    kitchenTools[3] = "Spatula";
    kitchenTools[4] = "Cutting Board";
    kitchenTools[5] = "Whisk";
    kitchenTools[6] = "Ladle";
    kitchenTools[7] = "Tongs";
    kitchenTools[8] = "Measuring Cup";
    kitchenTools[9] = "Timer";
    
    // Initialize temperature zones
    for (int i = 0; i < 5; i++) {
        temperatures[i] = 20.0f; // Room temperature
    }
    
    // Initialize stove burners (all off)
    for (int i = 0; i < 4; i++) {
        stoveStatus[i] = false;
    }
    
    std::cout << "Kitchen Game initialized!\n";
}

KitchenGame::~KitchenGame() {
    std::cout << "Kitchen Game ended. Final score: " << score << "\n";
}

void KitchenGame::startGame() {
    std::cout << "=== Welcome to Kitchen Game ===\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Score: " << score << "\n";
    displayKitchenStatus();
}

void KitchenGame::addFood(const Food& food) {
    foodItems.push_back(food);
    std::cout << "Food item added! Total items: " << foodItems.size() << "\n";
}

void KitchenGame::removeFood(int index) {
    if (index >= 0 && index < static_cast<int>(foodItems.size())) {
        foodItems.erase(foodItems.begin() + index);
        std::cout << "Food item removed!\n";
    } else {
        std::cout << "Invalid food index!\n";
    }
}

void KitchenGame::setStoveStatus(int burner, bool status) {
    if (burner >= 0 && burner < 4) {
        stoveStatus[burner] = status;
        std::cout << "Burner " << burner + 1 << " is now " 
                  << (status ? "ON" : "OFF") << "\n";
    }
}

bool KitchenGame::getStoveStatus(int burner) const {
    if (burner >= 0 && burner < 4) {
        return stoveStatus[burner];
    }
    return false;
}

void KitchenGame::setZoneTemperature(int zone, float temp) {
    if (zone >= 0 && zone < 5) {
        temperatures[zone] = temp;
        std::cout << "Zone " << zone + 1 << " temperature set to " 
                  << temp << "°C\n";
    }
}

float KitchenGame::getZoneTemperature(int zone) const {
    if (zone >= 0 && zone < 5) {
        return temperatures[zone];
    }
    return 0.0f;
}

void KitchenGame::displayKitchenStatus() {
    std::cout << "\n=== Kitchen Status ===\n";
    
    // Display stove status
    std::cout << "Stove Burners: ";
    for (int i = 0; i < 4; i++) {
        std::cout << "B" << i + 1 << ":" << (stoveStatus[i] ? "ON" : "OFF") << " ";
    }
    std::cout << "\n";
    
    // Display temperature zones
    std::cout << "Temperature Zones: ";
    for (int i = 0; i < 5; i++) {
        std::cout << "Z" << i + 1 << ":" << temperatures[i] << "°C ";
    }
    std::cout << "\n";
    
    // Display available tools
    std::cout << "Available Tools: ";
    for (int i = 0; i < 10; i++) {
        std::cout << kitchenTools[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Food Items: " << foodItems.size() << "\n";
}

void KitchenGame::displayFoodItems() {
    std::cout << "\n=== Food Items ===\n";
    for (size_t i = 0; i < foodItems.size(); i++) {
        std::cout << "Item " << i + 1 << ": Food object\n";
    }
}

int KitchenGame::getFoodCount() const {
    return static_cast<int>(foodItems.size());
}

int main()
{
    // Create a KitchenGame instance
    KitchenGame game;
    
    // Start the game
    game.startGame();
    
    // Example usage of arrays in the game
    std::cout << "\n=== Testing Kitchen Features ===\n";
    
    // Turn on some stove burners
    game.setStoveStatus(0, true);  // Turn on burner 1
    game.setStoveStatus(2, true);  // Turn on burner 3
    
    // Set some zone temperatures
    game.setZoneTemperature(0, 180.0f);  // Oven zone
    game.setZoneTemperature(1, 100.0f);  // Boiling zone
    
    // Add some food items
    Food pizza;
    Food pasta;
    game.addFood(pizza);
    game.addFood(pasta);
    
    // Display current status
    game.displayKitchenStatus();
    game.displayFoodItems();
    
    std::cout << "\nTotal food items: " << game.getFoodCount() << "\n";
    
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
