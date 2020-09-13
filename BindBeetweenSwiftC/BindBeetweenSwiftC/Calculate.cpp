//
//  Calculate.cpp
//  BindBeetweenSwiftC
//
//  Created by Júlio Andherson de Oliveira Silva on 13/09/20.
//  Copyright © 2020 Júlio Andherson de Oliveira Silva. All rights reserved.
//

#include "Calculate.hpp"

// Declare callback like variable
static StructCallback sCallback;

// Implement setup callback function to reference the function's pointer
void SetupStructCallback(const StructCallback *callback) {
    sCallback = *callback;
}

void myCustomCallback() {
    sCallback.deliveryToSwift("Callback message from Cpp to Swift!");
}


int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}

int divider(int a, int b) {
    return a / b;
}
